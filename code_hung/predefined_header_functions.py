# -*- coding: utf-8 -*-
"""
Created on Wed Apr  3 17:31:19 2019

@author: Venkatesh T Mohan
"""

NODE_LIST=['Decl','IdentifierType','Constant','FuncDef','FuncDecl','FuncCall',
           'ParamList','Typename','TypeDecl','Compound','Assignment','ID','UnaryOp',
           'BinaryOp','Cast','ExprList','Pragma','For','While','DoWhile','If','Switch',
           'Return','Print','DeclList','ArrayRef','Cast','TypeDef','PtrDecl','Struct',
           'ArrayDecl','InitList','Break','Case','CompoundLiteral','Continue','Default',
           'EmptyStatement','Enum','Enumerator','EnumeratorList','Goto','Label',
           'NamedInitializer','StructRef','TernaryOp','Union']
NODE_MAP = {i+1: n for (i, n) in enumerate(NODE_LIST)}
#print(NODE_MAP)
NODE_MAP_str= {str(key):val for key,val in NODE_MAP.items()}

print(NODE_MAP)

stdio_funcs=['fclose','clearerr','feof','ferror','fflush','fgetpos','fopen','fread','freopen',\
 'fseek','fsetpos','ftell','fwrite','remove','rename','rewind','setbuf','setvbuf',\
 'tmpfile','tmpnam','fprintf','printf','sprintf','vfprintf','vprintf','vsprintf',\
 'fscan','scanf','sscanf','fgetc','fgets','fputc','fputs','getc','getchar','gets',\
 'putc','putchar','puts','ungetc','perror']

stdlib_funcs=['atof','atoi','atol','strtod','strtol','strtoul','calloc','free',\
              'malloc','realloc','abort','atexit','exit','getenv','system',\
              'bsearch','qsort','abs','div','labs','ldiv','rand','srand','mblen',\
              'mbstowcs','mbtowc','wcstombs','wctomb']
string_funcs=['memchr','memcmp','memcpy','memmove','memset','strcat','strncat','strchr',\
              'strcmp','strncmp','strcoll','strcpy','strncpy','strcspn','strerror',\
              'strlen','strpbrk','strrchr','strspn','strstr','strtok','strxfrm']

time_funcs=['asctime','clock','ctime','difftime','gmtime','localtime','mktime','strftime','time']

ctype_funcs=['isalnum','isalpha','iscntrl','isdigit','isgraph','islower','isprint','ispunct',\
             'isspace','isupper','isxdigit','tolower','toupper']

math_funcs=['acos','asin','atan','atan2','cos','cosh','sin','sinh','tanh','exp','frexp',\
            'ldexp','log','log10','modf','pow','sqrt','ceil','fabs','floor','fmod']

locale_funcs=['setlocale','localeconv']
setjmp_funcs=['longjmp']
signal_funcs=['signal','raise']


