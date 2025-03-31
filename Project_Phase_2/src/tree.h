#ifndef TREE_H
#define TREE_H


enum nodeType {
      PROGRAM = 1,
      DECLLIST,
      DECL,
      VARDECL,
      TYPESPEC,
      FUNDECL,
      FORMALDECLLIST,
      FORMALDECL,
      FUNBODY,
      LOCALDECLLIST,
      STATEMENTLIST,
      STATEMENT,
      COMPOUNDSTMT,
      ASSIGNSTMT,
      CONDSTMT,
      LOOPSTMT,
      RETURNSTMT,
      EXPRESSION,
      RELOP,
      ADDOP,
      MULOP,
      INTEGER,
      IDENTIFIER,
      CHAR,
      FUNCTION,
      VOID_TYPE,
      INT_TYPE,
      CHAR_TYPE,
      ADDEXPR,
      TERM,
      FACTOR,
      FUNCCALLEXPR,
      ARGLIST,
      VAR,
      ARRAYDECL,
      FUNCTYPENAME
};  

enum symbolType {SCALAR, ARRAY};


/* ERRORS ARISE FROM THIS BUT I WANT TO KEEP JUST IN CASE
// AST node kinds
#define PROGRAM          1
#define DECLLIST         2
#define DECL             3
#define VARDECL          4
#define TYPESPEC         5
#define FUNDECL          6
#define FORMALDECLLIST   7
#define FORMALDECL       8
#define FUNBODY          9
#define LOCALDECLLIST    10
#define STATEMENTLIST    11
#define STATEMENT        12
#define COMPOUNDSTMT     13
#define ASSIGNSTMT       14
#define CONDSTMT         15
#define LOOPSTMT         16
#define ADDEXPR          17
#define ADDOP            18
#define MULOP            19
#define RELOP            20
#define INTEGER          21
#define IDENTIFIER       22
#define CHAR             23
#define FUNCTION         24
#define VOID_TYPE        25
#define INT_TYPE         26
#define CHAR_TYPE        27
#define RETURNSTMT       28
#define EXPRESSION       29
#define TERM             30
#define FACTOR           31
#define FUNCCALLEXPR     32
#define ARGLIST          33
#define VAR              34
#define ARRAYDECL        35
#define FUNCTYPENAME     36
*/

#define MAXCHILDREN      12

typedef struct treenode tree;

/* tree node - you may need to add more fields or change this file however you see fit. */
struct treenode {
      int nodeKind;
      int numChildren;
      int val;
      char *val2;
      tree *parent;
      tree *children[MAXCHILDREN];
};

tree *ast; /* pointer to AST root */

/* builds sub tree with zeor children  */
tree *maketree(int kind);

/* builds sub tree with leaf node. Leaf nodes typically hold a value. */
tree *maketreeWithVal(int kind, char *val2);
tree *maketreeWithIntVal(int kind, int val);

/* assigns the subtree rooted at 'child' as a child of the subtree rooted at 'parent'. Also assigns the 'parent' node as the 'child->parent'. */
void addChild(tree *parent, tree *child);
void addCharChild(tree *parent, tree *child);

/* prints the ast recursively starting from the root of the ast. This function prints the warning "undeclared variable" or <nodeKind, value> for identifiers and integers, or <nodeKind, type name> for typeSpecifiers, and <nodeName, the operator symbol> for relational and arithmetic operators. For more information, take a look at the example in the "Sample Output" section of the assignment instructions.*/
void printAst(tree *root, int nestLevel);


#endif
