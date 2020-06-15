# -*- coding: utf-8 -*-
"""
Created on Mon Mar 30 16:50:34 2020

@author: Augusto Menezes Savaris
"""
import pycparser
import sys

#create class to visit and print all the nodes in an ast
class Vocabulary(pycparser.c_ast.NodeVisitor):
    def __init__(self):
        pass
    def generic_visit(self, node):
        print(type(node).__name__)
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)
    def visit_Decl(self,node):
        print("Decl:",node.name)
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)
    def visit_Cast(self,node):
        print("Cast:",node.to_type.name)
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)
    def visit_TypeDecl(self,node):    
        print("TypeDecl:",node.declname)
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)
    def visit_Typedef(self,node):    
        print("Typedef:")
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)    
    def visit_IdentifierType(self,node): 
        print("IdentifierType:",node.names)
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)   
    def visit_FuncDef(self,node):   
        print("FuncDef:")
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)  
    def visit_FuncDecl(self,node):
        print("FuncDecl:")
        pycparser.c_ast.NodeVisitor.generic_visit(self, node) 
    def visit_ParamList(self,node): 
        print("ParamList:")
        pycparser.c_ast.NodeVisitor.generic_visit(self, node) 
    def visit_PtrDecl(self,node):
        print("PtrDecl:")
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)      
    def visit_Typename(self,node):   
        print("Typename:",node.name)
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)  
    def visit_Compound(self,node):   
        print("Compound:")
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)      
    def visit_Assignment(self,node):  
        print("Assignment:",node.op)
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)              
    def visit_ID(self,node):
        print("ID:",node.name)
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)   
    def visit_UnaryOp(self,node): 
        print("UnaryOp:",node.op)
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)    
    def visit_BinaryOp(self,node): 
        print("BinaryOp:",node.op)
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)      
    def visit_Constant(self,node):    
        print("Constant:",node.value)
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)   
    def visit_For(self,node):
        print("For:")
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)   
    def visit_DoWhile(self,node):
        print("DoWhile:")
        pycparser.c_ast.NodeVisitor.generic_visit(self, node) 
    def visit_While(self,node):
        print("While:")
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)          
    def visit_If(self,node):   
        print("If:")
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)  
    def visit_Switch(self,node):   
        print("Switch:")
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)     
    def visit_Return(self,node):   
        print("Return:")
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)      
    def visit_Pragma(self,node):
        print("Pragma:")
        print("Typename:",node.string)
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)  
    def visit_FuncCall(self,node):   
        print("FuncCall:")
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)    
    def visit_ExprList(self,node):
        print("ExprList:")
        pycparser.c_ast.NodeVisitor.generic_visit(self, node)    
    def visit_ArrayRef(self,node):
        print("ArrayRef:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_DeclList(self,node):
        print("DeclList:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_Struct(self,node):
        print("Struct:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_ArrayDecl(self,node):
        print("ArrayDecl:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_InitList(self,node):
        print("InitList:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_Break(self,node):
        print("Break:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_Case(self,node):
        print("Case:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_CompoundLiteral(self,node):    
        print("CompoundLiteral:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node) 
    def visit_Continue(self,node):    
        print("Continue:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node) 
    def visit_Default(self,node):    
        print("Default:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node) 
    def visit_EmptyStatement(self,node):    
        print("EmptyStatement:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)   
    def visit_Enum(self,node):    
        print("Enum:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)  
    def visit_Enumerator(self,node):    
        print("Enumerator:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)  
    def visit_EnumeratorList(self,node):    
        print("EnumeratorList:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)   
    def visit_Goto(self,node):    
        print("Goto:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)  
    def visit_Label(self,node):    
        print("Label:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)  
    def visit_NamedInitializer(self,node):    
        print("NamedInitializer:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)  
    def visit_StructRef(self,node):
        print("StructRef:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)    
    def visit_TernaryOp(self,node):
        print("TernaryOp:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)
    def visit_Union(self,node):
        print("Union:")
        pycparser.c_ast.NodeVisitor.generic_visit(self,node)      
        
a=Vocabulary() #create object of the visitor Vocabulary class

#function that parses c code to ast format
def to_ast(filename, text):
  parser = pycparser.c_parser.CParser() #construct parser object
  ast = parser.parse(text, filename = filename) #parse the c code into ast and store it in a variable
  ast.show(showcoord=True) #show the ast representation with coordinates in console, can comment it out if wanted
  return ast #return the parsed ast representation of the original c code

for i in range(1,501):
    if(i!=139):
        filename = "preprocessed-unitialized" + str(i) +".txt" #set name of input file to open it, read its content, and parse it
        output_filename = "ast" + str(i) + ".txt" #set name of the ast output file
        f = open(filename, "r") #open input file
        text = f.read() #read all the content of input file into text (text should have the preprocessed c code)
        ast = to_ast(filename, text) #get the parsed ast representation of code
        original_stdout= sys.stdout #save the console output in a variable so later we set it back to normal
        sys.stdout = open(output_filename,"w") #open output file and sets the standard output as the output file astn.txt where n corresponds to number of unitialized variable file
        a.visit(ast) #visit the whole tree and print its contents
        sys.stdout.close() #close output file
        sys.stdout= original_stdout #resets the standard output as the console