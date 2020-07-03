fopASTInfos='/Users/hungphan/git/MLFixCErrors_data/ASTInfo/'
fopLogAssignment='/Users/hungphan/git/MLFixCErrors_data/ASTLogAssignment/'

import os
from pycparser import c_parser, c_ast
from pypreprocessor import pypreprocessor
from analyze.utils import createDir

createDir(fopASTInfos)
createDir(fopLogAssignment)

def getLevelOfTreeAndASTInfo(arrASTs,index):
    countIndent=0
    for j in range(len(arrASTs[index])):
        # print('{}aaa\t{}'.format(len(arrASTs[index]),arrASTs[index][j]))
        if str(arrASTs[index][j]).isspace():
            countIndent = countIndent+1
        else:
            break;

    strContent=arrASTs[index].strip()
    nodeName=strContent.split(':')[0].strip()
    return countIndent,nodeName

def sortDictionaryAndSaveToFile(dict,fp):
    file=open(fp,'w')
    file.write('')
    file.close()

    sorted_list = sorted(dict.items(), key=lambda x: x[1], reverse=True)

    for key in sorted_list:
        file = open(fp, 'a')
        file.write('{}\t{}\n'.format(key[0],key[1]))
        file.close()



# lstASTs=[]
dictASTs={}
dictDecls={}
fpOutputInitializationTypes = fopLogAssignment + 'initializationTypes.txt'
fpOutputDeclarationTypes = fopLogAssignment + 'declarationTypes.txt'
# fpOutputLSize = fopLogAssignment + 'assignmentLeftSize.txt'

ii=0
for filename in os.listdir(fopASTInfos):
    if filename.endswith(".c") or filename.endswith(".cpp"):
        fpCodeItem=os.path.join(fopASTInfos, filename)
        fpASTInfos = fopASTInfos + filename
        fileAST=open(fpASTInfos,'r')
        strAST=fileAST.read()
        fileAST.close()
        ii=ii+1
        print('{}\t{}'.format(ii,fpASTInfos))
        arrASTs=strAST.split('\n')
        for i in range(0,len(arrASTs)):
            levelOfTree,nodeName=getLevelOfTreeAndASTInfo(arrASTs,i)
            # print('{} and {}'.format(levelOfTree,nodeName))
            if str(nodeName) == 'Assignment' or str(nodeName) == 'FuncCall' or str(nodeName) == 'Decl':
                # print('handle here')

                index=i+1
                lstItemCode=[]
                lstItemLevel = []
                while index<len(arrASTs):
                    lstStrAppends = arrASTs[i]
                    indexLevel, indexNode = getLevelOfTreeAndASTInfo(arrASTs, index)
                    if(indexLevel<=levelOfTree):
                        break
                    lstItemCode.append(arrASTs[index])
                    lstItemLevel.append(indexLevel)
                    index=index+1

                if str(nodeName) == 'Assignment' and len(lstItemCode)>=2:
                    lstTemp=[]
                    for j in range(1,len(lstItemCode)):
                        strTemp=lstItemCode[j].strip().split('(')[0].strip()
                        lstTemp.append(strTemp)

                    strTemp=','.join(lstTemp)
                    strTemp=nodeName+','+strTemp
                    if not strTemp in dictASTs.keys():
                        dictASTs[strTemp] = 1
                    else:
                        dictASTs[strTemp] = dictASTs[strTemp] + 1
                elif  str(nodeName) == 'FuncCall' and len(lstItemCode)>=2:
                    strFuncName=lstItemCode[0].split(':')[1].strip()
                    if strFuncName == 'scanf':
                        lstTemp = []
                        for j in range(1, len(lstItemCode)):
                            strTemp = lstItemCode[j].strip().split('(')[0].strip()
                            lstTemp.append(strTemp)
                        strTemp = ','.join(lstTemp)
                        strTemp = nodeName + ',' + strTemp
                        if not strTemp in dictASTs.keys():
                            dictASTs[strTemp]=1
                        else:
                            dictASTs[strTemp] = dictASTs[strTemp]+1
                elif  str(nodeName) == 'Decl' and len(lstItemCode)>=2:
                    strFuncName=lstItemCode[0].split(':')[1].strip()
                    if strFuncName != 'main, []':
                        lstTemp = []
                        for j in range(1, len(lstItemCode)):
                            strTemp = lstItemCode[j].strip().split('(')[0].strip()
                            lstTemp.append(strTemp)
                        strTemp = ','.join(lstTemp)
                        strTemp = nodeName + ',' + strTemp
                        if not strTemp in dictDecls.keys():
                            dictDecls[strTemp]=1
                        else:
                            dictDecls[strTemp] = dictDecls[strTemp]+1

sortDictionaryAndSaveToFile(dictASTs,fpOutputInitializationTypes)
sortDictionaryAndSaveToFile(dictDecls,fpOutputDeclarationTypes)

        


