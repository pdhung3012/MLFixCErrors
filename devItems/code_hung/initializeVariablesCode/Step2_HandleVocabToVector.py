# -*- coding: utf-8 -*-
"""
Created on November 21, 2019

@author: Hung Phan
"""


from __future__ import print_function
from tensorflow.compat.v1.keras.initializers import Constant
from keras.layers import Embedding, LSTM, Dense, Dropout
from keras.preprocessing.text import Tokenizer
from keras.callbacks import EarlyStopping
from pickle import dump
from keras.utils import to_categorical
from keras.models import Sequential
from collections import defaultdict
import keras.utils as ku 
import tensorflow as tf
from tensorflow.contrib import rnn
import glob
import os
import numpy as np
from predefined_header_functions import NODE_LIST,NODE_MAP,NODE_MAP_str, stdio_funcs,stdlib_funcs,string_funcs,time_funcs,ctype_funcs,math_funcs,locale_funcs,setjmp_funcs,signal_funcs
header_stmts={'<stdio.h>','<stdlib.h>','<string.h>','<math.h>','<ctype.h>','<signal.h>'}
type_stmts={"['int']","['char']","['float']","['double']","['long']","['unsigned']","['void']",
            "['size_t']","['ptrdiff_t']","['FILE']","['long', 'int']","['long', 'double']","['long', 'long']", 
            "['long', 'float']","['short', 'int']","['short']","['signed', 'int']","['unsigned', 'int']","['Signed', 'char']",
            "['Unsigned', 'char']","['div_t']","['ldiv_t']","['jmp_buf']",
            "['time_t']","['clock_t']", "['wchar_t']","['ptrdiff_t']"}
terminal_map={}
terminal_map[50]='None'
terminal_map[51]='#include'
header_count=52
for i in header_stmts:
    terminal_map[header_count]=i
    header_count=header_count+1
type_count=60
stdio_count=100
stdlib_count=160
string_count=190
time_count=220
ctype_count=240
math_count=260
locale_count=280
setjmp_count=290
signal_count=300
alpha_count=310
numeric_int_count=1000
numeric_float_count=3000
int_val=0
float_val=0.0
file1_path="/Users/hungphan/git/MLFixCErrors/testUninitVars/data_files/"
file1_paths= os.listdir(file1_path)
#print(file1_paths)
file1_paths.sort(key=lambda f: int(''.join(filter(str.isdigit, f))))
#print(file1_paths)

# comment this part
headers_file=open("header.txt",'w')
input_file=open("input.txt",'w')
for file in range(len(file1_paths)):
       lines= open(file1_path+file1_paths[file] ,'r').readlines()
       for i in range(len(lines)):
           copy_lines=list(lines)
           lines[i] = lines[i].split(':')
           if len(lines[i])==2:
             lines[i][1] = lines[i][1].strip('\n').strip()
             if lines[i][1]!= ' ' and lines[i][1]!='':
                if lines[i][1] in type_stmts:
                  if lines[i][1] not in terminal_map.values():
                     terminal_map[type_count]=lines[i][1]
                     type_count=type_count+1
                elif lines[i][1] in stdio_funcs:
                   if lines[i][1] not in terminal_map.values():
                     terminal_map[stdio_count]=lines[i][1]
                     stdio_count=stdio_count+1
                elif lines[i][1] in stdlib_funcs:
                   if lines[i][1] not in terminal_map.values():
                     terminal_map[stdlib_count]=lines[i][1]
                     stdlib_count=stdlib_count+1
                elif lines[i][1] in string_funcs:
                   if lines[i][1] not in terminal_map.values():
                     terminal_map[string_count]=lines[i][1]
                     string_count=string_count+1
                elif lines[i][1] in ctype_funcs:
                   if lines[i][1] not in terminal_map.values():
                     terminal_map[ctype_count]=lines[i][1]
                     ctype_count=ctype_count+1
                elif lines[i][1] in math_funcs:
                   if lines[i][1] not in terminal_map.values():
                     terminal_map[math_count]=lines[i][1]
                     math_count=math_count+1
                elif lines[i][1] in locale_funcs:
                   if lines[i][1] not in terminal_map.values():
                     terminal_map[locale_count]=lines[i][1]
                     locale_count=locale_count+1
                elif lines[i][1] in setjmp_funcs:
                   if lines[i][1] not in terminal_map.values():
                     terminal_map[setjmp_count]=lines[i][1]
                     setjmp_count=setjmp_count+1
                elif lines[i][1] in signal_funcs:
                   if lines[i][1] not in terminal_map.values():
                     terminal_map[signal_count]=lines[i][1]
                     signal_count=signal_count+1
                else:
                    try:
                        if "." in lines[i][1] :
                            float_val = float(lines[i][1])
                            if float_val not in terminal_map.values():
                                terminal_map[numeric_float_count]=float_val
                                numeric_float_count=numeric_float_count+1
                        else:
                            int_val = int(lines[i][1])
                            if int_val not in terminal_map.values():
                                terminal_map[numeric_int_count]=int_val
                                numeric_int_count=numeric_int_count+1
                    except ValueError:
                            if lines[i][1] not in terminal_map.values():
                                terminal_map[alpha_count]=lines[i][1]
                                alpha_count=alpha_count+1
                            pass

           if lines[i][0]=='FuncCall':
               funcs=lines[i+1].split(':')[1].strip('\n')
               funcs=funcs.strip()
               if funcs in stdio_funcs:
                   headers_file.write("%s \n" %funcs)
           if lines[i][0]=='ID' and lines[i][1] not in stdio_funcs and lines[i][1] not in string_funcs and lines[i][1] not in stdlib_funcs and lines[i][1] not in ctype_funcs and lines[i][1] not in math_funcs and lines[i][1] not in setjmp_funcs and lines[i][1] not in signal_funcs and lines[i][1] not in locale_funcs:
               input_file.write("%s" %copy_lines[i])
# print(terminal_map)
input_file.close()

s=' Decl:literal_alpha TypeDecl:literal_alpha IdentifierType:type'
# s=''
with open('inputs.txt','w') as f:
   with open('input.txt','r') as out:
     for line in out:
        # print(line.rstrip('\n').replace(" ","") + " " + s + '\n')
        f.write(line.rstrip('\n').replace(" ","") + " " + s + '\n')
f.close()

lines_seen=set()
outfile=open("inputss.txt",'w')
for line in open("inputs.txt",'r'):
    if line not in lines_seen:
        outfile.write(line)
        lines_seen.add(line)
outfile.close()  
               
symbol_map={}
symbol_map=dict(terminal_map)
#print(symbol_map)
for key,value in symbol_map.items():
    if key>=60 and key<100:
         symbol_map[key]='type'
    if key>=310 and key<1000:
         symbol_map[key]='literal_alpha'
    elif key>=1000 and key<3000: 
         symbol_map[key]='literal_integer'
    elif key>=3000:
         symbol_map[key]='literal_float'

number_to_symbol={}
number_to_symbol.update({'222222':'literal_alpha'})
number_to_symbol.update({'333333':'literal_integer'})
number_to_symbol.update({'444444':'literal_float'})
number_to_symbol.update({'555555':'initialization'})
number_to_symbol.update({'111111':'type'})
#print(number_to_symbol) 

terminal_map_str={str(key):value for key,value in terminal_map.items()}
symbol_map_str={str(key):value for key,value in symbol_map.items()}  
terminal_map_str['00']=': ' 
symbol_map_str['00']=': '     

diction=dict()
diction_var=dict()
vocab_seq=[]
sequence=[]
diction_list=[]
non_term=''
term=''
col=''
for file in range(len(file1_paths)):
        lines= open(file1_path+file1_paths[file] ,'r').readlines()
        lines_copy=list(lines)
        for i in range(len(lines)):
            lines[i]=lines[i].strip('\n')            
            lines_copy[i] = lines[i].split(":")
            if lines_copy[i][1] == '':
                 lines_copy[i].remove(lines_copy[i][1])
            for key,val in NODE_MAP_str.items():
                if val==lines_copy[i][0]:
                    non_term=key
            for key1,val1 in symbol_map_str.items():        
                if val1==': ':
                    col=key1            
            if len(lines_copy[i])==2: 
               lines_copy[i][1]= lines_copy[i][1].strip()
               for key2,val2 in terminal_map_str.items():
                    try:
                        if "." in lines_copy[i][1]:
                            float_val2=float(lines_copy[i][1])
                            if float(val2)== float_val2: 
                               if int(key2)>=3000:
                                   for key3,val3 in symbol_map_str.items():
                                      if key2==key3:
                                        for key4,val4 in number_to_symbol.items():
                                          if val3==val4: 
                                              term=key4
                        else:
                            int_val2=int(lines_copy[i][1])
                            if int(val2)== int_val2:
                                if int(key2)>=1000 and int(key2)<3000:
                                    for key3,val3 in symbol_map_str.items():
                                       if key2==key3:
                                          for key4,val4 in number_to_symbol.items():
                                              if val3==val4: 
                                                   term=key4
                    except ValueError:
                             if val2==lines_copy[i][1]:
                                if int(key2)>=310 and int(key2)<1000:    
                                   for key3,val3 in symbol_map_str.items():
                                      if key2==key3:
                                        for key4,val4 in number_to_symbol.items():
                                          if val3==val4: 
                                               term=key4
                                if int(key2)>=60 and int(key2)<100:
                                   for key3,val3 in symbol_map_str.items():
                                      if key2==key3:
                                        for key4,val4 in number_to_symbol.items():
                                          if val3==val4: 
                                               term=key4
                                elif int(key2)<310 and int(key2)>=100: 
                                     term= key2                
                             pass                
            lines_copy[i]=non_term+col+term
            if lines_copy[i] in diction:
               diction[lines_copy[i]].append(lines[i])
            else:
               diction[lines_copy[i]]= [lines[i]] 
               
            if lines_copy[i] in diction_var:
               diction_var[lines_copy[i]].append(lines[i])
            else:
               diction_var[lines_copy[i]]= [lines[i]]   
            non_term=col=term=''
            vocab_seq.append(lines[i])
        diction_copy=dict(diction) 
        diction_list.append(diction_copy)
        sequence.append(lines_copy) 
        diction.clear()
#print(diction_list)                  

diction_var_copy=dict(diction_var)
for key,val in diction_var.items(): 
          diction_var_copy[key]=set(val)  
diction_map_int={int(key):val for key,val in diction_var_copy.items()}

#print(diction_map_int)
import copy
diction_list_copy=copy.deepcopy(diction_list)
for i in range(len(diction_list_copy)):
   for key,val in diction_list_copy[i].items():
           diction_list_copy[i][key]=set(val)

#print(diction_list_copy)    
          
with open('dictions.pkl','wb') as pick:
     dump([diction_list_copy,file1_paths,diction_list],pick)

from pickle import load
with open('dictions.pkl','rb') as pi:
    diction_list_copy,file1_paths,diction_list=load(pi)
    # print(str(diction_list))



'''
embedding_dim=512
            
from gensim.models import FastText
model_src = FastText(sentences=vocab_seq, size=embedding_dim, window=5, min_count=5, workers=4,sg=1)
src_words = list(model_src.wv.vocab)
#print(len(src_words))

src_filename= 'embedding_word2vec.txt'
model_src.wv.save_word2vec_format(src_filename,binary=False)



src_embeddings_index = {}
src_file_embed = open(os.path.join('','embedding_word2vec.txt'), encoding='utf-8')
for line in src_file_embed:
    values=line.split()
    word=values[0]
    coefs = np.asarray(values[1:])
    src_embeddings_index[word]= coefs
src_file_embed.close()

src_embedding_matrix= np.zeros((len(vocab_seq),embedding_dim))

for i,word in diction_map_int.items():
    if i > len(diction_map_int):
        continue
    src_embedding_vector = src_embeddings_index.get(word)
    if src_embedding_vector is not None:
        src_embedding_matrix[i] = src_embedding_vector
'''

