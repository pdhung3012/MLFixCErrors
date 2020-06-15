# -*- coding: utf-8 -*-
"""
Created on November 21, 2019

@author: Hung Phan
"""

from __future__ import print_function

import json
import sys
import re
import pycparser_fake_libc
import os
from subprocess import Popen, PIPE

fake_libc_arg = "-I" + pycparser_fake_libc.directory
# This is not required if you've installed pycparser into
# your site-packages/ with setup.py
#
sys.path.extend(['.', '..'])

from pycparser import parse_file, c_ast, c_generator
from pycparser.plyparser import Coord

RE_CHILD_ARRAY = re.compile(r'(.*)\[(.*)\]')
RE_INTERNAL_ATTR = re.compile('__.*__')


class CJsonError(Exception):
    pass


def memodict(fn):
    """ Fast memoization decorator for a function taking a single argument """

    class memodict(dict):
        def __missing__(self, key):
            ret = self[key] = fn(key)
            return ret

    return memodict().__getitem__


@memodict
def child_attrs_of(klass):
    """
    Given a Node class, get a set of child attrs.
    Memoized to avoid highly repetitive string manipulation
    """
    non_child_attrs = set(klass.attr_names)
    all_attrs = set([i for i in klass.__slots__ if not RE_INTERNAL_ATTR.match(i)])
    return all_attrs - non_child_attrs


def to_dict(node):
    """ Recursively convert an ast into dict representation. """
    klass = node.__class__

    result = {}

    # Metadata
    result['_nodetype'] = klass.__name__

    # Local node attributes
    for attr in klass.attr_names:
        result[attr] = getattr(node, attr)

    # Coord object
    if node.coord:
        result['coord'] = str(node.coord)
    else:
        result['coord'] = None

    # Child attributes
    for child_name, child in node.children():
        # Child strings are either simple (e.g. 'value') or arrays (e.g. 'block_items[1]')
        match = RE_CHILD_ARRAY.match(child_name)
        if match:
            array_name, array_index = match.groups()
            array_index = int(array_index)
            # arrays come in order, so we verify and append.
            result[array_name] = result.get(array_name, [])
            if array_index != len(result[array_name]):
                raise CJsonError('Internal ast error. Array {} out of order. '
                                 'Expected index {}, got {}'.format(
                    array_name, len(result[array_name]), array_index))
            result[array_name].append(to_dict(child))
        else:
            result[child_name] = to_dict(child)

    # Any child attributes that were missing need "None" values in the json.
    for child_attr in child_attrs_of(klass):
        if child_attr not in result:
            result[child_attr] = None

    return result


def to_json(node, **kwargs):
    """ Convert ast node to json string """
    return json.dumps(to_dict(node), **kwargs)


def file_to_dict(filename):
    """ Load C file into dict representation of ast """
    ast = parse_file(filename, use_cpp=True, cpp_args=fake_libc_arg)
    return to_dict(ast)


def file_to_json(filename, **kwargs):
    """ Load C file into json string representation of ast """
    ast = parse_file(filename, use_cpp=True, cpp_args=fake_libc_arg)
    return to_json(ast, **kwargs)


def _parse_coord(coord_str):
    """ Parse coord string (file:line[:column]) into Coord object. """
    if coord_str is None:
        return None

    vals = coord_str.split(':')
    vals.extend([None] * 3)
    filename, line, column = vals[:3]
    return Coord(filename, line, column)


def _convert_to_obj(value):
    """
    Convert an object in the dict representation into an object.
    Note: Mutually recursive with from_dict.
    """
    value_type = type(value)
    if value_type == dict:
        return from_dict(value)
    elif value_type == list:
        return [_convert_to_obj(item) for item in value]
    else:
        # String
        return value


def from_dict(node_dict):
    """ Recursively build an ast from dict representation """
    class_name = node_dict.pop('_nodetype')

    klass = getattr(c_ast, class_name)

    # Create a new dict containing the key-value pairs which we can pass
    # to node constructors.
    objs = {}
    for key, value in node_dict.items():
        if key == 'coord':
            objs[key] = _parse_coord(value)
        else:
            objs[key] = _convert_to_obj(value)

    # Use keyword parameters, which works thanks to beautifully consistent
    # ast Node initializers.
    return klass(**objs)


def from_json(ast_json):
    """ Build an ast from json string representation """
    return from_dict(json.loads(ast_json))


# ------------------------------------------------------------------------------
if __name__ == "__main__":
    count = 0
    # new_folder_path='/Users/hungphan/git/MLFixCErrors/testUninitVars/output_uninit/'
    # folder_exec="/Users/hungphan/git/MLFixCErrors/testUninitVars/output_exec_2/file_{}.c"
    new_folder_path = '/Users/hungphan/git/MLFixCErrors/testUninitVars/output_json_files/'
    folder_exec = "/Users/hungphan/git/MLFixCErrors/testUninitVars/output_exec/file_{}.c"
    new_files = os.listdir(new_folder_path)
    # new_files = [i for i in new_files if i.endswith('.c')]
    new_files.sort(key=lambda f: int(''.join(filter(str.isdigit, f))))
    i = 0
    for new_file in range(len(new_files)):
        # print(new_file)
        i = i + 1
        generator = c_generator.CGenerator()
        cl = open(new_folder_path + new_files[new_file], 'r')
        # print(eval(cl.read()))
        temp_json = json.dumps(eval(cl.read()))
        ast_json = from_json(temp_json)
        # print(ast_json)
        original_stdout = sys.stdout
        sys.stdout = open(folder_exec.format(i), "w")
        out = generator.visit(ast_json)
        out = re.sub(r'(%d)', r'\1"', out)
        out = re.sub(r'(%d)', r'"\1', out)
        out = re.sub(r'(%f)', r'\1"', out)
        out = re.sub(r'(%f)', r'"\1', out)
        out = re.sub(r'(%ld)', r'\1"', out)
        out = re.sub(r'(%ld)', r'"\1', out)
        out = re.sub(r'(%lf)', r'\1"', out)
        out = re.sub(r'(%lf)', r'"\1', out)
        out = re.sub(r'(%c)', r'\1"', out)
        out = re.sub(r'(%c)', r'"\1', out)
        out = re.sub(r'("\\n)', r'"\1', out)
        out = re.sub(r'("\\n)', r'\1"', out)
        print(out)
        sys.stdout.close()
        sys.stdout = original_stdout

        # print(i)
    '''    
    check_path='output_exec/'
    check_files=os.listdir(check_path)
    check_files.sort(key=lambda f: int(''.join(filter(str.isdigit, f))))
    j=1
    for file in range(len(check_files)):
        file_new=open('output_execution/file_{}.c'.format(j),'w')
        for line in file.read():
            if not 'typedef' in line:
                file_new.write(line)
        j=j+1        
    '''


    def execution(filename):
        process = Popen(['clang', filename, '-c'], stdout=PIPE, stderr=PIPE)
        stdout, stderr = process.communicate()
        return stderr

