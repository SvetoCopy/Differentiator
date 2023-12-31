#ifndef TREE_READ_HPP
#define TREE_READ_HPP

#include "RuzalLib/include/Tree.h"

#define NODE_IMM_VALUE(node) node->data.value.imm_value
#define NODE_CMD_CODE(node)  node->data.value.command_type
#define NODE_VAR_VALUE(node) node->data.value.var.imm_value
#define NODE_VAR_NAME(node)  node->data.value.var.name

const int   MAX_BD_SIZE = 1000;
const int   DEFAULT_TRACK_SIZE = 10;
const int   MAX_NODEINFO_SIZE = 100;

constexpr const char* DEFAULT_NIL = ".";

enum ParseStatus {
	FOUND = 1,
	UNFOUND = 2
};

enum Order {
	POST = 1,
	IN = 2,
	PRE = 3
};

enum NodeElem {
	LEFT_ELEM = 0,
	ROOT_ELEM = 1,
	RIGHT_ELEM = 2
};

int  ReadNodeIN(char* str, Node** res);
void PrintTreeExpr(Tree* tree, FILE* stream);

bool isEqualVar(ExprVar var1, ExprVar var2);


bool —heckVarInNode(Node* node, ExprVar var);

Node* CreateCommandNode(int command_code, Node* left, Node* right);
Node* CreateImmNode(double imm_value, Node* left, Node* right);
Node* CreateVarNode(ExprVar var, Node* left, Node* right);

#endif // !TREE_READ_HPP
