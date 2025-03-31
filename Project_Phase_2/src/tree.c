#include <tree.h>
#include <strtab.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


tree *maketree(int kind) 
{
    tree *node = malloc(sizeof(tree));
    if (!node) 
    {
        fprintf(stderr, "Memory allocation failed in maketree\n");
        exit(1);
    }
    node->nodeKind = kind;
    node->val = 0;
    node->numChildren = 0;
    node->parent = NULL;

    for (int i = 0; i < MAXCHILDREN; i++) 
    {
        node->children[i] = NULL;
    }
    return node;
}

tree *maketreeWithVal(int kind, char *val2) 
{
    tree *newTree = maketree(kind);
    newTree->val2 = val2;
    return newTree;
}

tree *maketreeWithIntVal(int kind, int val) 
{
    tree *node = maketree(kind);
    node->val = val;
    return node;
}

void addChild(tree *parent, tree *child) 
{
    if (parent->numChildren >= MAXCHILDREN) 
    {
        fprintf(stderr, "Exceeded max children in addChild\n");
        return;
    }
    parent->children[parent->numChildren++] = child;
    child->parent = parent;
}
void addCharChild(tree *parent, tree *child) 
{
    if (parent->numChildren >= MAXCHILDREN) 
    {
        fprintf(stderr, "Exceeded max children in addChild\n");
        return;
    }
    parent->children[parent->numChildren++] = child;
    child->parent = parent;
}

// --------- PRINT AST FUNCTIONS START HERE ---------

// Helper function to print indentation based on nesting level
void printIndent(int level) 
{
    for (int i = 0; i < level * 2; i++) 
    {
        printf(" ");
    }
}

//Get a readable string for the node kind
const char *getNodeKindName(int kind) {
    switch (kind) {
        case ADDEXPR: return "AddExpr";
        case ADDOP: return "AddOp";
        case PROGRAM: return "Program";
        case DECLLIST: return "DeclList";
        case DECL: return "Decl";
        case VARDECL: return "VarDecl";
        case TYPESPEC: return "TypeSpecifier";
        case FUNDECL: return "FuncDecl";
        case FORMALDECLLIST: return "FormalDeclList";
        case FORMALDECL: return "FormalDecl";
        case FUNBODY: return "FunBody";
        case LOCALDECLLIST: return "LocalDeclList";
        case STATEMENTLIST: return "StatementList";
        case STATEMENT: return "Statement";
        case COMPOUNDSTMT: return "CompoundStmt";
        case ASSIGNSTMT: return "AssignStmt";
        case CONDSTMT: return "CondStmt";
        case LOOPSTMT: return "LoopStmt";
        case RETURNSTMT: return "ReturnStmt";
        case EXPRESSION: return "Expression";
        case RELOP: return "RelOp";
        case TERM: return "Term";
        case MULOP: return "MulOp";
        case FACTOR: return "Factor";
        case FUNCCALLEXPR: return "FuncCallExpr";
        case ARGLIST: return "ArgList";
        case INTEGER: return "IntLiteral";
        case IDENTIFIER: return "Identifier";
        case VAR: return "Var";
        case ARRAYDECL: return "ArrayDecl";
        case CHAR: return "CharLiteral";
        case FUNCTYPENAME: return "FuncTypeName";
        default: return "Unknown";
    }
}

// Helper function to print details about a node
void printNode(tree *node) 
{
    const char *name = getNodeKindName(node->nodeKind);

    printf("%s", name);

    // Print extra info for specific node kinds
    if (node->nodeKind == 257) 
    { // Identifier
        printf(", %s", strTable[node->val].name);
    } 
    else if (node->nodeKind == 259) 
    { // Int literal
        printf(", %d", node->val);
    } 
    else if (node->nodeKind == 258) 
    { // Type specifier
        const char *types[] = {"int", "char", "void"};
        if (node->val >= 0 && node->val < 3) 
        {
            printf(", %s", types[node->val]);
        }
    } 
    else if (node->nodeKind == 260 || node->nodeKind == 261) 
    { // Operators
        const char *ops[] = {"+", "-", "*", "/", "==", "!=", "<", "<=", ">", ">="};
        if (node->val >= 0 && node->val < 10) 
        {
            printf(", %s", ops[node->val]);
        }
    }

    printf("\n");
}

// Recursive function to print the AST
void printAst(tree *root, int nestLevel) 
{
    if (!root) return;

    printIndent(nestLevel);
    printNode(root);

    for (int i = 0; i < root->numChildren; i++)
    {
        printAst(root->children[i], nestLevel + 1);
    }
}