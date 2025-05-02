#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "strtab.h"
#include "tree.h"

int yyparse(void);
void print_sym_tab(void);
void printAst(struct treenode* node, int indent);

extern FILE* yyin;
extern struct treenode *ast;

void printhelp(){
    printf("Usage: mcc [--ast] [--sym] [-h|--help] FILE\n");
    printf("\t--ast:\t\tPrint a textual representation of the constructed abstract syntax tree.\n");
    printf("\t--sym:\t\tPrint a textual representation of the constructed symbol table.\n");
    printf("\t-h,--help:\tPrint this help information and exit.\n\n");
}


// Codegen headers
void gen_stmt(tree *node);
void gen_expr(tree *node);
void gen_function_body(tree *stmtList);

int main(int argc, char **argv) {
    if (yyparse() == 0) {
        printf("# Parsing successful.\n");

        // ast is expected to be a 'program' node or 'funDecl'
        if (ast == NULL) {
            fprintf(stderr, "No AST generated.\n");
            return 1;
        }

        // If ast is a program with a declList child:
        for (int i = 0; i < ast->numChildren; i++) {
            tree *decl = getChild(ast, i);
            if (decl->nodeKind == FUNDECL) {
                tree *funBody = getChild(decl, 3); // funBody
                tree *stmtList = getChild(funBody, 1); // statementList
                gen_function_body(stmtList); // Generate code
            }
        }

    } else {
        fprintf(stderr, "Parse failed.\n");
    }

    return 0;
}