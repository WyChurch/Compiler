#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strtab.h"
#include "tree.h"

int yyparse(void);
void print_sym_tab(void);
void printAst(struct treenode *node, int indent);

// MIPS codegen headers
void gen_stmt(tree *node);
void gen_expr(tree *node);
void gen_function_body(tree *stmtList);
void generateCode(tree *node);  // <-- Add this if you use generateCode()

extern FILE *yyin;
extern tree *ast;

void printhelp() {
    printf("Usage: mcc [--ast] [--sym] [-h|--help] FILE\n");
    printf("\t--ast:\t\tPrint a textual representation of the constructed abstract syntax tree.\n");
    printf("\t--sym:\t\tPrint a textual representation of the constructed symbol table.\n");
    printf("\t-h,--help:\tPrint this help information and exit.\n\n");
}

int main(int argc, char **argv) {
    int show_ast = 0, show_sym = 0;
    char *filename = NULL;

    // Parse command-line arguments
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--ast") == 0) show_ast = 1;
        else if (strcmp(argv[i], "--sym") == 0) show_sym = 1;
        else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            printhelp();
            return 0;
        } else {
            filename = argv[i];  // Assume the first unknown argument is the file
        }
    }

    if (!filename) {
        fprintf(stderr, "No input file provided.\n");
        printhelp();
        return 1;
    }

    // Open input file
    yyin = fopen(filename, "r");
    if (!yyin) {
        perror("fopen");
        return 1;
    }

    // Parse input
    if (yyparse() == 0) {
        fprintf(stderr, "# Parsing successful.\n");

        if (!ast) {
            fprintf(stderr, "No AST generated.\n");
            return 1;
        }

        if (show_ast) {
            printAst(ast, 0);
        }

        if (show_sym) {
            print_sym_tab();
        }

        // MIPS code generation
        generateCode(ast);  // or use your manual loop + gen_function_body
    } else {
        fprintf(stderr, "Parse failed.\n");
    }

    fclose(yyin);
    return 0;
}