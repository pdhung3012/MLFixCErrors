fopPrutorCodes='/Users/hungphan/git/MLFixCErrors_data/TestCCodeInit/'
fopPreprocessCodes='/Users/hungphan/git/MLFixCErrors_data/PreprocessCodes_Test/'
fopASTInfos='/Users/hungphan/git/MLFixCErrors_data/ASTInfo_Test/'

import os
from pycparser import c_parser, c_ast
from pypreprocessor import pypreprocessor
from analyze.utils import createDir
createDir(fopPreprocessCodes)
createDir(fopASTInfos)

def preprocessCode(fpInput,fpOutput):
    fFileItem = open(fpInput, 'r')
    strInput = fFileItem.read().strip()
    fFileItem.close()
    arrInput=strInput.split('\n')
    arrOutput=[]
    for item in arrInput:
        if(not(item.strip().startswith("#") or item.strip().startswith("//"))):
            arrOutput.append(item)

    strOutput='\n'.join(arrOutput)
    fFileItem = open(fpOutput, 'w')
    fFileItem.write(strOutput)
index=0
for filename in os.listdir(fopPrutorCodes):
    if filename.endswith(".c") or filename.endswith(".cpp"):
        fpCodeItem=os.path.join(fopPrutorCodes, filename)
        fpPreprocessItem=fopPreprocessCodes+filename
        fpASTInfos = fopASTInfos + filename
        # print(strFileItem)
        parser = c_parser.CParser()

        try:
            # pypreprocessor.input = fpCodeItem
            # pypreprocessor.output = fpPreprocessItem
            # pypreprocessor.removeMeta = True
            # pypreprocessor.parse()
            index=index+1
            preprocessCode(fpCodeItem, fpPreprocessItem)
            fFileItem = open(fpPreprocessItem, 'r')
            strFileItem = fFileItem.read().strip()
            fFileItem.close()

            ast = parser.parse(strFileItem, filename='<none>')
            # import io

            fFileItem = open(fpASTInfos, 'w')
            # sio = io.StringIO(open(fpASTInfos).write())
            ast.show(buf=fFileItem,showcoord=True)
            fFileItem.close()
            # sio.close()
            # fFileItem = open(fpASTInfos, 'w')
            # fFileItem.write(strAST)
            # fFileItem.close()
            print('{0} ast info'.format(index))
            # print(ast)
        except Exception as e: # work on python 3.x

            print('{0} cannot open {1}'.format(index,str(e)))


    else:
        continue