
from pickle import load
with open('dictions.pkl','rb') as pi:
    diction_list_copy,file1_paths,diction_list=load(pi)
    print(diction_list[0])
    print(diction_list_copy[0])
    print(len(diction_list))
    print(len(diction_list_copy))
    print(str(file1_paths))

