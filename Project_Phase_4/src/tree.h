#ifndef TREE_H
#define TREE_H

#define MAXCHILDREN 100

enum nodeTypes {
      PROGRAM, DECLLIST, DECL, VARDECL, TYPESPEC, FUNDECL, FORMALDECLLIST,
      FORMALDECL, FUNBODY, LOCALDECLLIST, STATEMENTLIST, STATEMENT,
      COMPOUNDSTMT, ASSIGNSTMT, CONDSTMT, LOOPSTMT, RETURNSTMT,
      EXPRESSION, RELOP, ADDEXPR, ADDOP, TERM, MULOP, FACTOR,
      FUNCCALLEXPR, ARGLIST, INTEGER, IDENTIFIER, VAR, ARRAYDECL,
      CHAR, FUNCTYPENAME, IFSTMT, IFELSESTMT, WHILESTMT, FORSTMT, STRING
};

enum opType {
      ADD, SUB, MUL, DIV,
      LT, LTE, EQ, GTE, GT, NEQ
};

/* string values for ast node types, makes tree output more readable */
extern const char *typeNames[];
extern const char *ops[];
extern const char *nodeNames[];

typedef struct treenode tree;



/* tree node - you may want to add more fields */
struct treenode {
      int nodeKind;
      int numChildren;
      int val;
      char *charVal;
      int scope; // Used for var/id. Index of the scope. This works b/c only global and local.
      int type;
      int sym_type; // Only used by var to distinguish SCALAR vs ARRAY
      tree *parent;
      tree *children[MAXCHILDREN];
};

tree *ast; /* pointer to AST root */

/* builds sub tree with zeor children  */
tree *maketree(int kind);

/* builds sub tree with leaf node */
tree *maketreeWithVal(int kind, char *val);

tree *maketreeWithIntVal(int kind, int val);

void addChild(tree *parent, tree *child);

void printAst(tree *root, int nestLevel);

/* Adds all children of sublist to list */
void flattenList(tree *list, tree *subList);

/* tree manipulation macros */
/* if you are writing your compiler in C, you would want to have a large collection of these */

#define nextAvailChild(node) node->children[node->numChildren]
#define getChild(node, index) node->children[index]

#endif
