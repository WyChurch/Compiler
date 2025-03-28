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

tree *maketreeWithVal(int kind, int val) 
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

// --------- PRINT AST FUNCTIONS START HERE ---------

// Helper function to print indentation based on nesting level
void printIndent(int level) 
{
    for (int i = 0; i < level * 2; i++) 
    {
        printf(" ");
    }
}

// Helper function to get a readable string for the node kind
const char *getNodeKindName(int kind) 
{
    switch (kind) {
        case 257: return "Identifier";
        case 258: return "TypeSpecifier";
        case 259: return "IntLiteral";
        case 260: return "AddExpr";
        case 261: return "RelOpExpr";
        case 262: return "FuncDecl";
        // Add more nodeKind values based on your grammar
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
        printf(", %s", strTable[node->val]);
    } 
    else if (node->nodeKind == 259) 
    { // Int literal
        printf(", %d", node->val);
    } 
    else if (node->nodeKind == 258) 
    { // Type specifier
        const char *types[] = {"int", "float", "void"};
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