# -*- coding: utf-8 -*-
"""
Created on November 21, 2019

@author: Hung Phan
"""

# -*- coding: utf-8 -*-
"""
Created on November 21, 2019

@author: Hung Phan
"""

from predefined_header_functions import NODE_LIST, NODE_MAP, NODE_MAP_str, stdio_funcs, stdlib_funcs, string_funcs, \
    time_funcs, ctype_funcs, math_funcs, locale_funcs, setjmp_funcs, signal_funcs
from initializeVariablesCode.Step2_HandleVocabToVector  import file1_paths, diction_list_copy, diction_list
from numpy import array
from pickle import dump
from keras.utils import to_categorical
from keras.models import Sequential
from keras.layers import Dense, TimeDistributed, RepeatVector
from keras.layers import LSTM, Dropout, Embedding
from keras.optimizers import RMSprop
from pickle import load
from keras.models import load_model
from keras.utils import to_categorical
from keras.preprocessing.sequence import pad_sequences
from sklearn.model_selection import train_test_split
import glob
import json
import os
import ast
import re
import matplotlib.pyplot as plt


# load doc into memory
def load_doc(filename):
    # open the file as read only
    file = open(filename, 'r')
    # read all text
    text = file.read()
    # close the file
    file.close()
    return text


def save_doc(lines, filename):
    data = '\n'.join(lines)
    file = open(filename, 'w')
    file.write(data)
    file.close()


# load text
raw_text = load_doc('inputss.txt')
# print(raw_text)

# clean
raw_text = raw_text.split()

# organize into sequences of characters
length = 1
sequences = list()
for i in range(length, len(raw_text)):
    # select sequence of tokens
    seq = raw_text[i - length:i + 1]
    # store
    sequences.append(seq)
# print(sequences)
# integer encode sequences of characters
mapping = dict()
count = 0
for i in range(len(raw_text)):
    if raw_text[i] not in mapping.values():
        mapping[count] = raw_text[i]
        count = count + 1
# print(mapping)
inverse_mapping = {}
for key, val in mapping.items():
    # print(str(key)+'---'+str(val))
    inverse_mapping[val] = key

# print('Total Sequences: %d %s' % (len(sequences), sequences))
sequences_encode = list()
for i in range(len(sequences)):
    encoded_seq = [inverse_mapping[sequences[i][j]] for j in range(len(sequences[i]))]
    sequences_encode.append(encoded_seq)

# print(sequences_encode)
# vocabulary size
vocab_size = len(mapping)
# print('Vocabulary Size: ' + str(vocab_size))

# separate into input and output
sequences_encode = array(sequences_encode)
# print("encode "+str(sequences_encode))
X, y = sequences_encode[:, :-1], sequences_encode[:, -1]
# print(X)
# print(y)
sequences_encode = [to_categorical(x, num_classes=vocab_size) for x in X]
X = array(sequences_encode)
y = to_categorical(y, num_classes=vocab_size)
# print(X)


# print("sequence: "+str(sequences))
# print("x: "+str(len(X))+" "+str(X[0]))
# print("x: "+str(len(X))+" "+str(X[4]))
# print("y: "+str(len(y))+" "+str(y[0]))
# print("y: "+str(len(y))+" "+str(y[4]))
# print("y: "+str(len(y))+" "+str(y[1]))
# print("y: "+str(len(y))+" "+str(y[2]))
# print(X.shape[1],X.shape[2])
# define model
model = Sequential()
# model.add(Embedding(input_dim=vocab_size,output_dim=512))
model.add(LSTM(512, return_sequences=True))
# model.add(RepeatVector(1))
model.add(LSTM(512))
model.add(Dropout(0.5))
model.add(Dense(vocab_size, activation='softmax'))
# print(model.summary())
# compile model
model.compile(loss='categorical_crossentropy', optimizer=RMSprop(lr=0.01), metrics=['accuracy'])
# fit model
X_train, X_valid, Y_train, Y_valid = train_test_split(X, y, test_size=0.20, random_state=36)
# print(X_train)
# print(len(X_train))
# print(len(X_train[0]))
# print(len(X_train[1]))
# input("Enter your name : ")


history = model.fit(X_train, Y_train, epochs=5, batch_size=3, verbose=2)
test_history = model.fit(X_valid, Y_valid, epochs=2, batch_size=3, verbose=2)
# save the model to file
model.save('model.h5')
# save the mapping
dump(mapping, open('mapping.pkl', 'wb'))
# print(len(inverse_mapping))
dump(inverse_mapping, open('inverse_mapping.pkl', 'wb'))


# # summarize history for accuracy
# plt.plot(history.history['accuracy'])
# #plt.plot(history.history['val_acc'])
# plt.title('model accuracy')
# plt.ylabel('accuracy')
# plt.xlabel('epoch')
# plt.legend(['train'], loc='upper left')
# plt.show()
# # summarize history for loss
# plt.plot(history.history['loss'])
# #plt.plot(history.history['val_loss'])
# plt.title('model loss')
# plt.ylabel('loss')
# plt.xlabel('epoch')
# plt.legend(['train'], loc='upper left')
# plt.show()
#
# plt.plot(test_history.history['accuracy'])
# #plt.plot(history.history['val_acc'])
# plt.title('model accuracy')
# plt.ylabel('accuracy')
# plt.xlabel('epoch')
# plt.legend(['test'], loc='upper left')
# plt.show()
# # summarize history for loss
# plt.plot(test_history.history['loss'])
# #plt.plot(history.history['val_loss'])
# plt.title('model loss')
# plt.ylabel('loss')
# plt.xlabel('epoch')
# plt.legend(['test'], loc='upper left')
# plt.show()

# generate a sequence of characters with a language model
def generate_seq(model, mapping, inverse_mapping, seq_length, seed_text, n_words):
    in_text = seed_text.split()
    # print(in_text)
    # generate a fixed number of characters
    for _ in range(n_words):
        # encode the characters as integers
        encoded = [inverse_mapping[in_text[word]] for word in range(len(in_text))]
        # print(encoded)
        encoded = pad_sequences([encoded], maxlen=seq_length, truncating='pre')
        # print(encoded)
        encoded = to_categorical([encoded], num_classes=len(mapping))
        # print(encoded)
        yhat = model.predict_classes(encoded, verbose=0)
        out_word = ''
        for index, word in mapping.items():
            if index == yhat:
                out_word = word
                # print(out_word)
                break
        in_text.append(out_word)
        # print("out class " + str(yhat) + " input " + str(encoded)+" out_word "+str(out_word)+ " seed text " + str(in_text))
    return in_text


# load the model
model = load_model('model.h5')
# load the mapping
mapping = load(open('mapping.pkl', 'rb'))
inverse_mapping = load(open('inverse_mapping.pkl', 'rb'))

# print(raw_text)
# loop over all id, predict a declaration
predictions = []
for i in range(len(raw_text)):

    if i % 4 == 0:
        print(str(raw_text[i]))
        pred = generate_seq(model, mapping, inverse_mapping, 1, raw_text[i], 3)
        # print("Here is prediction "+str(raw_text[i])+" "+str(pred))
        predictions.append(pred)
# print(predictions)
# print(generate_seq(model, mapping, inverse_mapping,1, 'scanf', 2))
# print(generate_seq(model, mapping, inverse_mapping, 1, 'strlen', 2))
# print(generate_seq(model, mapping, 16, 'Decl:literal_alpha', 23))
# print(generate_seq(model, mapping, 16, 'TypeDecl:literal_alpha', 20))
with open('predictions.pkl', 'wb') as pick:
    dump(predictions, pick)

with open('predictions.pkl', 'rb') as pi:
    predictions = load(pi)

count = 0
flag1 = 0
f1 = 0
f2 = 0
f3 = 0
f4 = 0
f5 = 0
f6 = 0
f7 = 0
f8 = 0
f9 = 0
f10 = 0
f11 = 0
c = 0
type_var = ''
type_stmts = []
type2_stmts = []
type3_stmts = []
type4_stmts = []
type5_stmts = []
type6_stmts = []
other_type_stmts = []
final_type = []
pcount = 1
bcount = 2
ptmap = {}
nf = set()

file2_path = '/Users/hungphan/git/MLFixCErrors/testUninitVars/data_files/'
for file in range(len(file1_paths)):
    lines = open(file2_path + file1_paths[file], 'r').readlines()
    for i in range(len(lines)):
        lines[i] = lines[i].split(':')
        if 'ID' == lines[i][0] and lines[i][1] not in stdio_funcs and lines[i][1] not in string_funcs and lines[i][
            1] not in stdlib_funcs and lines[i][1] not in ctype_funcs and lines[i][1] not in math_funcs and lines[i][
            1] not in setjmp_funcs and lines[i][1] not in signal_funcs and lines[i][1] not in locale_funcs:
            for j in range(len(predictions)):
                try:
                    pp = diction_list_copy[count]['100222222'] | diction_list_copy[count]['100']
                except KeyError as e:
                    pp = diction_list_copy[count]['100222222']
                # print("prediction output: "+str(j)+" " + str(predictions[j][0].split(':')[1]))
                # print("prediction details: " + str(j) + " " + str(predictions[j][0]))
                if predictions[j][0] == lines[i][0] + ":" + lines[i][1].strip() and 'Decl: ' + \
                        predictions[j][0].split(':')[1] not in pp:
                    # print(pp)
                    # print("pp: " + str(pp))
                    if predictions[j][0] not in nf:
                        nf.add(predictions[j][0])
                        print("augmented variables ",file1_paths[file]," ",predictions[j][0])
                        bcount = pcount
                        # print(file1_paths[file])
                        # print("possible not found: " + str(len(predictions)))
                        # print("nf: " + str(nf))
                        next_line = lines[i + 1].split(':')
                        if next_line[0] == 'Constant':
                            if "." in next_line[1]:
                                type_var = "['float']"
                                type_stmts.append(type_var)
                                print(predictions[j][0].split(':')[1])
                                print(next_line[1])
                                ptmap[bcount] = type_var
                                # print(count)

                            else:
                                type_var = "['int']"
                                type_stmts.append(type_var)
                                print(predictions[j][0].split(':')[1])
                                print(next_line[1])
                                ptmap[bcount] = type_var
                                # print(count)
                        elif next_line[0] == 'ID' and next_line[1].strip() not in stdio_funcs and next_line[
                            1].strip() not in string_funcs and next_line[1].strip() not in stdlib_funcs:
                            y = list(diction_list[count]['200111111'])
                            z = list(diction_list[count]['100222222'])
                            # print(next_line[1])
                            for ir in range(len(z)):
                                # print(('Decl:' + next_line[1]).strip())
                                # print(z[i])
                                # print(y[i].split(':')[1])
                                if ('Decl:' + next_line[1]).strip() == z[ir] and f1 == 0:
                                    type2_stmts.append(y[ir].split(':')[1])
                                    print(predictions[j][0].split(':')[1])
                                    print(z[ir])
                                    print(y[ir].split(':')[1])
                                    ptmap[bcount] = y[ir].split(':')[1]
                                    # print(count)
                                    f1 = 1
                        elif next_line[0] == 'FuncCall':
                            y1 = list(diction_list[count]['200111111'])
                            z1 = list(diction_list[count]['100222222'])
                            second_next_line = lines[i + 2].split(':')
                            if second_next_line[1].strip() not in stdio_funcs and second_next_line[
                                1].strip() not in string_funcs and second_next_line[1].strip() not in stdlib_funcs and \
                                    second_next_line[1].strip() not in ctype_funcs and second_next_line[
                                1].strip() not in math_funcs:
                                # print(second_next_line[1])
                                if 'ID' in lines[i + 4]:
                                    third = lines[i + 4].split(':')
                                    if third[0].strip() == 'ID' and third[1].strip() not in stdio_funcs and third[
                                        1].strip() not in stdlib_funcs and third[1].strip() not in string_funcs and \
                                            third[1].strip() not in math_funcs and third[1].strip() not in ctype_funcs:
                                        for ir in range(len(z1)):
                                            if ('Decl:' + third[1]).strip() == z1[ir] and f2 == 0:
                                                type3_stmts.append(y1[ir].split(':')[1])
                                                print(predictions[j][0].split(':')[1])
                                                print(z1[ir])
                                                print(y1[ir].split(':')[1])
                                                ptmap[bcount] = y1[ir].split(':')[1]
                                                # print(count)
                                                f2 = 1
                                elif 'BinaryOp' in lines[i + 4]:
                                    fourth = lines[i + 5].split(':')
                                    if fourth[0].strip() == 'ID':
                                        for ir in range(len(z1)):
                                            if ('Decl:' + fourth[1]).strip() == z1[ir] and f3 == 0:
                                                type3_stmts.append(y1[ir].split(':')[1])
                                                print(predictions[j][0].split(':')[1])
                                                print(z1[ir])
                                                print(y1[ir].split(':')[1])
                                                ptmap[bcount] = y1[ir].split(':')[1]
                                                # print(count)
                                                f3 = 1
                                else:
                                    type3_stmts.append("['int']")
                                    print(predictions[j][0].split(':')[1])
                                    ptmap[bcount] = "['int']"
                                    # print(count)
                            else:
                                type3_stmts.append("['int']")
                                print(predictions[j][0].split(':')[1])
                                ptmap[bcount] = "['int']"
                                # print(count)
                        elif next_line[0] == 'Assignment':
                            y2 = list(diction_list[count]['200111111'])
                            z2 = list(diction_list[count]['100222222'])
                            third_next_line = lines[i + 2].split(':')
                            if third_next_line[0].strip() == 'ID' and third_next_line[1].strip() not in stdio_funcs and \
                                    third_next_line[1].strip() not in stdlib_funcs and third_next_line[
                                1].strip() not in math_funcs and third_next_line[1].strip() not in ctype_funcs and \
                                    third_next_line[1].strip() not in string_funcs:
                                for ir in range(len(z2)):
                                    # print(z2[i])
                                    # print("\n")
                                    if ('Decl:' + third_next_line[1]).strip() == z2[ir] and f4 == 0:
                                        # print(z2[i])
                                        # print("\n")
                                        type4_stmts.append(y2[ir].split(':')[1])
                                        print(predictions[j][0].split(':')[1])
                                        print(z2[ir])
                                        print(y2[ir].split(':')[1])
                                        ptmap[bcount] = y2[ir].split(':')[1]
                                        # print(count)
                                        f4 = 1
                            else:
                                type4_stmts.append("['int']")
                                print(predictions[j][0].split(':')[1])
                                ptmap[bcount] = y2[ir].split(':')[1]
                                # print(count)
                        elif next_line[0] == 'BinaryOp':
                            # x5=x5+1
                            y3 = list(diction_list[count]['200111111'])
                            z3 = list(diction_list[count]['100222222'])
                            fourth_next_line = lines[i + 2].split(':')
                            if fourth_next_line[0].strip() == 'ID':
                                for ir in range(len(z3)):
                                    if ('Decl:' + fourth_next_line[1]).strip() == z3[ir]:
                                        # print(('Decl:'+fourth_next_line[1]).strip())
                                        # print(z3[i])
                                        # print("\n")
                                        type5_stmts.append(y3[ir].split(':')[1])
                                        print(predictions[j][0].split(':')[1])
                                        print(z3[ir])
                                        print(y3[ir].split(':')[1])
                                        ptmap[bcount] = y3[ir].split(':')[1]
                                        # print(count)
                                        f5 = 1
                            elif fourth_next_line[0].strip() == 'BinaryOp':
                                fifth_next_line = lines[i + 3].split(':')
                                if fifth_next_line[0].strip() == 'ID':
                                    for ir in range(len(z3)):
                                        if ('Decl:' + fifth_next_line[1]).strip() == z3[ir] and f6 == 0:
                                            type5_stmts.append(y3[ir].split(':')[1])
                                            print(predictions[j][0].split(':')[1])
                                            print(z3[ir])
                                            print(y3[ir].split(':')[1])
                                            ptmap[bcount] = y3[ir].split(':')[1]
                                            # print(count)
                                            f6 = 1
                                elif fifth_next_line[0].strip() == 'BinaryOp':
                                    sixth_next_line = lines[i + 4].split(':')
                                    if sixth_next_line[0].strip() == 'ID':
                                        for ir in range(len(z3)):
                                            if ('Decl:' + sixth_next_line[1]).strip() == z3[ir] and f7 == 0:
                                                type5_stmts.append(y3[ir].split(':')[1])
                                                print(predictions[j][0].split(':')[1])
                                                print(z3[ir])
                                                print(y3[ir].split(':')[1])
                                                ptmap[bcount] = y3[ir].split(':')[1]
                                                # print(count)
                                                f7 = 1
                                    else:
                                        type5_stmts.append("['int']")
                                        print(predictions[j][0].split(':')[1])
                                        ptmap[bcount] = "['int']"
                                        # print(count)
                                else:
                                    type5_stmts.append("['int']")
                                    print(predictions[j][0].split(':')[1])
                                    ptmap[bcount] = "['int']"
                                    # print(count)
                            elif fourth_next_line[0].strip() == 'FuncCall':
                                seventh_next_line = lines[i + 3].split(':')
                                if seventh_next_line[0].strip() == 'ID' and seventh_next_line[
                                    1].strip() not in stdio_funcs and seventh_next_line[
                                    1].strip() not in stdlib_funcs and seventh_next_line[
                                    1].strip() not in math_funcs and seventh_next_line[1].strip() not in ctype_funcs and \
                                        seventh_next_line[1].strip() not in string_funcs:
                                    for ir in range(len(z3)):
                                        if ('Decl:' + seventh_next_line[1]).strip() == z3[ir] and f8 == 0:
                                            type5_stmts.append(y3[ir].split(':')[1])
                                            print(predictions[j][0].split(':')[1])
                                            print(z3[ir])
                                            print(y3[ir].split(':')[1])
                                            ptmap[bcount] = y3[ir].split(':')[1]
                                            # print(count)
                                            f8 = 1
                                else:
                                    type5_stmts.append("['int']")
                                    ptmap[bcount] = "['int']"
                                    # print(count)
                            elif fourth_next_line[0].strip() == 'ArrayRef':
                                eighth_next_line = lines[i + 3].split(':')
                                if eighth_next_line[0].strip() == 'ID' and eighth_next_line[
                                    1].strip() not in stdio_funcs and eighth_next_line[
                                    1].strip() not in stdlib_funcs and eighth_next_line[1].strip() not in math_funcs and \
                                        eighth_next_line[1].strip() not in ctype_funcs and eighth_next_line[
                                    1].strip() not in string_funcs:
                                    for ir in range(len(z3)):
                                        if ('Decl:' + eighth_next_line[1]).strip() == z3[ir] and f9 == 0:
                                            type5_stmts.append(y3[ir].split(':')[1])
                                            print(predictions[j][0].split(':')[1])
                                            print(z3[ir])
                                            print(y3[ir].split(':')[1])
                                            ptmap[bcount] = y3[ir].split(':')[1]
                                            # print(count)
                                            f9 = 1
                                else:
                                    type5_stmts.append("['int']")
                                    print(predictions[j][0].split(':')[1])
                                    ptmap[bcount] = "['int']"
                                    # print(count)
                            else:
                                type5_stmts.append("['int']")
                                print(predictions[j][0].split(':')[1])
                                ptmap[bcount] = "['int']"
                                # print(count)
                        elif next_line[0] == 'ArrayRef':

                            y4 = list(diction_list[count]['200111111'])
                            z4 = list(diction_list[count]['100222222'])
                            ninth_next_line = lines[i + 2].split(':')
                            if ninth_next_line[0].strip() == 'ID':
                                for ir in range(len(z4)):
                                    if ('Decl:' + ninth_next_line[1]).strip() == z4[ir] and f10 == 0:
                                        type6_stmts.append(y4[ir].split(':')[1])
                                        print(predictions[j][0].split(':')[1])
                                        print(z4[ir])
                                        print(y4[ir].split(':')[1])
                                        ptmap[bcount] = y4[ir].split(':')[1]
                                        # print(count)
                                        f10 = 1
                            else:
                                type6_stmts.append("['int']")
                                print(predictions[j][0].split(':')[1])
                                ptmap[bcount] = "['int']"
                                # print(count)
                        else:
                            other_type_stmts.append("['int']")
                            ptmap[bcount] = "['int']"
                            # print(count)
                        final_type = type_stmts + type2_stmts + type3_stmts + type4_stmts + type5_stmts + type6_stmts + other_type_stmts
                        # print(final_type)
                        # flag1=1
    pcount = pcount + 1
    # flag1=0
    nf.clear()
    f1 = 0
    f2 = 0
    f3 = 0
    f4 = 0
    f5 = 0
    f6 = 0
    f7 = 0
    f8 = 0
    f9 = 0
    f10 = 0
    f11 = 0
    count = count + 1
    type_var = ''
# print(x4)
# print(ptmap)
# print(len(type_stmts),len(type2_stmts),len(type3_stmts),len(type4_stmts),len(type5_stmts),len(type6_stmts),len(other_type_stmts))
# print(len(final_type))
# print(diction_list_copy[0]['100222222'])
for key, val in ptmap.items():
    ptmap[key] = re.sub('\[', '', ptmap[key])
    ptmap[key] = re.sub('\]', '', ptmap[key])
    ptmap[key] = re.sub(' ', '', ptmap[key])
# print(ptmap)

new_flag = 0
count = 0
bcount = 2
js = 0
bf = set()
temp_file_path = "/Users/hungphan/git/MLFixCErrors/testUninitVars/data_files/"
for file in range(len(file1_paths)):
    f = open(temp_file_path + file1_paths[file], 'r+')
    lines = f.readlines()
    for i in range(len(lines)):
        lines[i] = lines[i].split(':')
        if 'ID' == lines[i][0] and lines[i][1].strip() not in stdio_funcs and lines[i][
            1].strip() not in string_funcs and lines[i][1].strip() not in stdlib_funcs and lines[i][
            1].strip() not in ctype_funcs and lines[i][1].strip() not in math_funcs and lines[i][
            1].strip() not in setjmp_funcs and lines[i][1].strip() not in signal_funcs and lines[i][
            1].strip() not in locale_funcs:
            # print(lines[i][1]+' '+str(predictions))
            for j in range(len(predictions)):
                # print("prediction aaa "+predictions[j][1])
                try:
                    pp = diction_list_copy[count]['100222222'] | diction_list_copy[count]['100']
                except KeyError as e:
                    pp = diction_list_copy[count]['100222222']
                if predictions[j][0] == lines[i][0] + ":" + lines[i][1].strip() and 'Decl: ' + \
                        predictions[j][0].split(':')[1] not in pp:
                    if predictions[j][0] not in bf:
                        df = "'" + predictions[j][0].split(':')[1].strip() + "'"
                        bf.add(predictions[j][0])
                        # print(count)
                        # print(final_type)
                        if 'ArrayRef' in lines[i - 1]:
                            js = bcount
                            print('arrayref to json ' + str(js))
                            with open('array_json_file.json', 'r') as fl:
                                with open(
                                        '/Users/hungphan/git/MLFixCErrors/testUninitVars/jsonfiles/file_{}.json'.format(
                                                js), 'w') as bl:
                                    for line in fl:
                                        line = line.strip()
                                        line = line.replace('"', "'")
                                        if 'var' in line:
                                            m = line.split(':')[1].strip(', ')
                                            bl.write(line.replace(m, df))
                                        elif 'types' in line:
                                            h = line.strip()
                                            if js in ptmap:
                                                bl.write(line.replace(h, ptmap[js]))
                                            else:
                                                bl.write(line.replace(h, "'int'"))

                                        else:
                                            bl.write(line)
                                bl.close()
                            fl.close()
                        else:
                            js = bcount
                            print('go to json ' + str(js))
                            with open('json_file.json', 'r') as fl:
                                with open(
                                        '/Users/hungphan/git/MLFixCErrors/testUninitVars/jsonfiles/file_{}.json'.format(
                                                js), 'w') as bl:
                                    for line in fl:
                                        line = line.strip()
                                        line = line.replace('"', "'")
                                        if 'var' in line:
                                            m = line.split(':')[1].strip(', ')
                                            bl.write(line.replace(m, df))
                                        elif 'types' in line:
                                            h = line.strip()
                                            if js in ptmap:
                                                bl.write(line.replace(h, ptmap[js]))
                                            else:
                                                bl.write(line.replace(h, "'int'"))
                                        else:
                                            bl.write(line)
                                bl.close()
                            fl.close()
                            # new_flag=1
    # new_flag=0
    bf.clear()
    fl = 0
    f2 = 0
    f3 = 0
    f4 = 0
    f5 = 0
    f6 = 0
    f7 = 0
    f8 = 0
    f9 = 0
    f10 = 0
    f11 = 0
    type_var = ''
    count = count + 1
    bcount = bcount + 1

# print(len(jj))
json_path = '/Users/hungphan/git/MLFixCErrors/testUninitVars/jsonfiles/'
json_paths = os.listdir(json_path)
json_paths.sort(key=lambda f: int(''.join(filter(str.isdigit, f))))
output_data_path = '/Users/hungphan/git/MLFixCErrors/testUninitVars/output_data_files/'
fop_output_json_files = '/Users/hungphan/git/MLFixCErrors/testUninitVars/output_json_files/file_{}.json'
output_data_paths = os.listdir(output_data_path)
output_data_paths.sort(key=lambda f: int(''.join(filter(str.isdigit, f))))

ccount = 1
file_count = 1

for odf in range(len(output_data_paths)):
    for jsf in range(len(json_paths)):
        if json_paths[jsf] == output_data_paths[odf]:
            dl = open(json_path + json_paths[jsf], 'r')
            gl = open(output_data_path + output_data_paths[odf], 'r')
            ccount = file_count
            with open(fop_output_json_files.format(ccount), 'w') as ojf:
                lines = json.load(gl)
                values = lines['ext']
                for value in values:
                    if value['_nodetype'] == 'FuncDef' and value['body']['block_items'] != None:
                        # print(value['decl']['name'])
                        kvalues = value['body']['block_items']
                        kvalues.insert(0, dl.read())
                        dl.seek(0)
                        # print(kvalues)
                        # print("\n")
                lines = str(lines).replace('null', 'None')
                lines = str(lines).replace('"', '')
                ojf.write(lines)
            ojf.close()
            dl.close()
            gl.close()
    file_count = file_count + 1

