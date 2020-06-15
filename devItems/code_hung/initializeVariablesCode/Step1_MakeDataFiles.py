# -*- coding: utf-8 -*-
"""
Created on Wednesday 20 November, 2019

@author: Hung Phan
"""
import sys 
import pycparser_fake_libc 
import glob
import os

from pycparser.c_ast import ID, ArrayRef

fake_libc_arg = "-I" + pycparser_fake_libc.directory
import pycparser as pp


class Vocabulary(pp.c_ast.NodeVisitor):

    def __init__(self):
        pass
        self.levelVisitIndex = 0
    def levelVisitIndex(self):
        return self.__levelVisitIndex
    def generic_visit(self, node):
        print(type(node).__name__)
        pp.c_ast.NodeVisitor.generic_visit(self, node)
    def visit_Decl(self,node):
        if(node.init is not None):
        #     # print("Decl:", node.name, ";", "notInitialized")
        #
        # else:
            print("Decl:",node.name,";initialized")
        pp.c_ast.NodeVisitor.generic_visit(self, node)
    def visit_Cast(self,node):
        print("Cast:",node.to_type.name)
        pp.c_ast.NodeVisitor.generic_visit(self, node)
    def visit_TypeDecl(self,node):    
        print("TypeDecl:",node.declname)
        # print("Quals:", node.quals)

        pp.c_ast.NodeVisitor.generic_visit(self, node)
    def visit_Typedef(self,node):    
        print("Typedef:")
        pp.c_ast.NodeVisitor.generic_visit(self, node)    
    def visit_IdentifierType(self,node): 
        print("IdentifierType:",node.names)
        pp.c_ast.NodeVisitor.generic_visit(self, node)   
    def visit_FuncDef(self,node):   
        print("FuncDef:")
        pp.c_ast.NodeVisitor.generic_visit(self, node)  
    def visit_FuncDecl(self,node):
        print("FuncDecl:")
        pp.c_ast.NodeVisitor.generic_visit(self, node) 
    def visit_ParamList(self,node): 
        print("ParamList:")
        pp.c_ast.NodeVisitor.generic_visit(self, node) 
    def visit_PtrDecl(self,node):
        print("PtrDecl:")
        pp.c_ast.NodeVisitor.generic_visit(self, node)      
    def visit_Typename(self,node):   
        print("Typename:",node.name)
        pp.c_ast.NodeVisitor.generic_visit(self, node)  
    def visit_Compound(self,node):   
        print("Compound:")
        pp.c_ast.NodeVisitor.generic_visit(self, node)      
    def visit_Assignment(self,node):
        pp.c_ast.NodeVisitor.generic_visit(self, node)
        print("Assignment:", node.op)
        nodeVariable = node.lvalue.name
        if (isinstance(nodeVariable, ID)):
            instance = nodeVariable
            print("ID:", str(instance.name), ";initialized")
        elif (isinstance(nodeVariable, ArrayRef)):
            instance = nodeVariable
            print("ID:", str(instance.name.name), ";initialized")
        # print("RightValue:", node.rvalue)
        # sys.exc_info()
    def visit_ID(self,node):
        print("ID:",node.name)
        # print("children:", node.children)
        pp.c_ast.NodeVisitor.generic_visit(self, node)   
    def visit_UnaryOp(self,node):
        # self.levelVisitIndex = self.levelVisitIndex + 1
        print("UnaryOp:",node.op)
        if(node.op == "&"):
            if(isinstance(node.expr,ID)):
                instance=node.expr
                print("ID:",str(instance.name),";initialized")
            elif(isinstance(node.expr,ArrayRef)):
                instance = node.expr
                print("ID:", str(instance.name.name), ";initialized")
        pp.c_ast.NodeVisitor.generic_visit(self, node)
        # self.levelVisitIndex = self.levelVisitIndex - 1
    def visit_BinaryOp(self,node):
        # self.levelVisitIndex=self.levelVisitIndex+1
        print("BinaryOp:",node.op)
        pp.c_ast.NodeVisitor.generic_visit(self, node)
        # self.levelVisitIndex = self.levelVisitIndex - 1
    def visit_Constant(self,node):
        # self.levelVisitIndex = self.levelVisitIndex + 1
        print("Constant:",self.levelVisitIndex,":",node.value)
        pp.c_ast.NodeVisitor.generic_visit(self, node)
        # self.levelVisitIndex = self.levelVisitIndex - 1
    def visit_For(self,node):
        print("For:")
        pp.c_ast.NodeVisitor.generic_visit(self, node)   
    def visit_DoWhile(self,node):
        print("DoWhile:")
        pp.c_ast.NodeVisitor.generic_visit(self, node) 
    def visit_While(self,node):
        print("While:")
        pp.c_ast.NodeVisitor.generic_visit(self, node)          
    def visit_If(self,node):   
        print("If:")
        pp.c_ast.NodeVisitor.generic_visit(self, node)  
    def visit_Switch(self,node):   
        print("Switch:")
        pp.c_ast.NodeVisitor.generic_visit(self, node)     
    def visit_Return(self,node):   
        print("Return:")
        pp.c_ast.NodeVisitor.generic_visit(self, node)      
    def visit_Pragma(self,node):
        print("Pragma:")
        print("Typename:",node.string)
        pp.c_ast.NodeVisitor.generic_visit(self, node)  
    def visit_FuncCall(self,node):   
        print("FuncCall:")
        pp.c_ast.NodeVisitor.generic_visit(self, node)    
    def visit_ExprList(self,node):
        print("ExprList:")
        pp.c_ast.NodeVisitor.generic_visit(self, node)    
    def visit_ArrayRef(self,node):
        print("ArrayRef:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_DeclList(self,node):
        print("DeclList:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_Struct(self,node):
        print("Struct:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_ArrayDecl(self,node):
        print("ArrayDecl:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_InitList(self,node):
        print("InitList:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_Break(self,node):
        print("Break:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_Case(self,node):
        print("Case:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_CompoundLiteral(self,node):    
        print("CompoundLiteral:")
        pp.c_ast.NodeVisitor.generic_visit(self,node) 
    def visit_Continue(self,node):    
        print("Continue:")
        pp.c_ast.NodeVisitor.generic_visit(self,node) 
    def visit_Default(self,node):    
        print("Default:")
        pp.c_ast.NodeVisitor.generic_visit(self,node) 
    def visit_EmptyStatement(self,node):    
        print("EmptyStatement:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)   
    def visit_Enum(self,node):    
        print("Enum:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)  
    def visit_Enumerator(self,node):    
        print("Enumerator:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)  
    def visit_EnumeratorList(self,node):    
        print("EnumeratorList:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)   
    def visit_Goto(self,node):    
        print("Goto:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)  
    def visit_Label(self,node):    
        print("Label:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)  
    def visit_NamedInitializer(self,node):    
        print("NamedInitializer:"+node.expr)
        pp.c_ast.NodeVisitor.generic_visit(self,node)  
    def visit_StructRef(self,node):
        print("StructRef:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)    
    def visit_TernaryOp(self,node):
        print("TernaryOp:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_Union(self,node):
        print("Union:")
        pp.c_ast.NodeVisitor.generic_visit(self,node)      
a=Vocabulary()

'''
ast=pp.parse_file("undecl_data.c",use_cpp=True,
        cpp_path='C:/Program Files/LLVM/bin/clang',
        cpp_args=r'-Iutils/fake_libc_include')

ast=pp.parse_file("train_program_set/undeclared887.c",use_cpp=True,cpp_args=fake_libc_arg)
a.visit(ast)
'''
folder_path="/Users/hungphan/git/MLFixCErrors/testUninitVars/train_program_set/"
files=os.listdir(folder_path)
print(len(files))
# int(os.path.splitext(os.path.basename(i))[0])
# files.sort(key=lambda f: int(''.join(filter(str.isdigit, f))))
files.sort(key=lambda i: int(os.path.splitext(os.path.basename(i))[0]))
i=1
for file in range(len(files)):
    ast=pp.parse_file(folder_path+ files[file],use_cpp=True,cpp_args=fake_libc_arg)
    original_stdout= sys.stdout
    sys.stdout = open("/Users/hungphan/git/MLFixCErrors/testUninitVars/data_files/file_{}.txt".format(i),"w",errors='ignore')
    a.visit(ast)
    sys.stdout.close()
    sys.stdout= original_stdout
    i=i+1
    
file_path= "/Users/hungphan/git/MLFixCErrors/testUninitVars/data_files/"
file_paths= os.listdir(file_path)

file_paths.sort(key=lambda f: int(''.join(filter(str.isdigit, f))))
# int(os.path.splitext(os.path.basename(i))[0]
# file_paths.sort(key=lambda i: int(os.path.splitext(os.path.basename(i))[0]))
search = 'FuncDef:'
for file in range(len(file_paths)):
     lines= open(file_path+ file_paths[file],'r',errors='ignore').readlines()
     for i,line in enumerate(lines):
         if search in line:
             break
     if i < len(lines) - 1:
       with open(file_path + file_paths[file], 'w') as f:
          f.write(''.join(lines[i:]))
        
#print(NODE_MAP)

