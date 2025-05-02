#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "tree.h"
#include "strtab.h"

// Utility: emit MIPS code
static void emit(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    printf("\n");
    va_end(args);
}

// Forward declaration
void gen_expr(tree *node);

// Expression generator (handles integer, identifier, +, -, *, /)
void gen_expr(tree *node) {
    if (node == NULL) return;

    switch (node->nodeKind) {
        case INTEGER:
            emit("  li $t0, %d", node->val);
            break;

        case IDENTIFIER: {
            const char *name = get_symbol_id(node->val);
            if (strcmp(name, "a") == 0)
                emit("  move $t0, $a0");
            else if (strcmp(name, "b") == 0)
                emit("  move $t0, $a1");
            else
                emit("  # unknown identifier: %s", name); // placeholder
            break;
        }

        case ADDEXPR: {
            gen_expr(getChild(node, 0));      // left
            emit("  move $t1, $t0");
            gen_expr(getChild(node, 1));      // right
            emit("  move $t2, $t0");

            const char *op = ops[node->val];
            if (strcmp(op, "+") == 0)
                emit("  add $t0, $t1, $t2");
            else if (strcmp(op, "-") == 0)
                emit("  sub $t0, $t1, $t2");
            break;
        }

        case TERM: {
            gen_expr(getChild(node, 0));      // left
            emit("  move $t1, $t0");
            gen_expr(getChild(node, 1));      // right
            emit("  move $t2, $t0");

            const char *op = ops[node->val];
            if (strcmp(op, "*") == 0)
                emit("  mul $t0, $t1, $t2");
            else if (strcmp(op, "/") == 0)
                emit("  div $t1, $t2\n  mflo $t0");
            break;
        }

        default:
            emit("  # Unsupported expr nodeKind: %d", node->nodeKind);
    }
}

// Assignment generator
void gen_stmt(tree *node) {
    if (node == NULL) return;

    switch (node->nodeKind) {
        case ASSIGNSTMT: {
            tree *lhs = getChild(node, 0);
            tree *rhs = getChild(node, 1);
            gen_expr(rhs); // result in $t0

            const char *name = get_symbol_id(lhs->val);
            if (strcmp(name, "a") == 0)
                emit("  move $a0, $t0");
            else if (strcmp(name, "b") == 0)
                emit("  move $a1, $t0");
            else
                emit("  # unknown assignment target: %s", name);
            break;
        }

        case IFSTMT: {
            static int labelCounter = 0;
            int elseLabel = labelCounter++;
            tree *cond = getChild(node, 0);
            tree *thenStmt = getChild(node, 1);

            gen_expr(cond); // result in $t0
            emit("  beq $t0, $zero, L%d", elseLabel);  // if false, jump to Lelse
            gen_stmt(thenStmt);
            emit("L%d:", elseLabel);
            break;
        }

        case IFELSESTMT: {
            static int labelCounter = 1000;
            int elseLabel = labelCounter++;
            int endLabel = labelCounter++;
            tree *cond = getChild(node, 0);
            tree *thenStmt = getChild(node, 1);
            tree *elseStmt = getChild(node, 2);

            gen_expr(cond); // result in $t0
            emit("  beq $t0, $zero, L%d", elseLabel); // if false, go to else
            gen_stmt(thenStmt);
            emit("  j L%d", endLabel);                // skip else
            emit("L%d:", elseLabel);
            gen_stmt(elseStmt);
            emit("L%d:", endLabel);
            break;
        }


        case WHILESTMT: {
            static int labelCounter = 2000;
            int startLabel = labelCounter++;
            int endLabel = labelCounter++;

            emit("L%d:", startLabel);
            gen_expr(getChild(node, 0)); // condition
            emit("  beq $t0, $zero, L%d", endLabel);
            gen_stmt(getChild(node, 1)); // body
            emit("  j L%d", startLabel);
            emit("L%d:", endLabel);
            break;
        }

        case FORSTMT: {
            static int labelCounter = 3000;
            int startLabel = labelCounter++;
            int endLabel = labelCounter++;

            gen_stmt(getChild(node, 0)); // init
            emit("L%d:", startLabel);
            gen_expr(getChild(node, 1)); // condition
            emit("  beq $t0, $zero, L%d", endLabel);
            gen_stmt(getChild(node, 3)); // body
            gen_stmt(getChild(node, 2)); // update
            emit("  j L%d", startLabel);
            emit("L%d:", endLabel);
            break;
        }

        default:
            emit("  # Unsupported stmt nodeKind: %d", node->nodeKind);
    }
}

// Handles statements in a function body
void gen_function_body(tree *stmtList) {
    for (int i = 0; i < stmtList->numChildren; i++) {
        gen_stmt(getChild(stmtList, i));
    }
}