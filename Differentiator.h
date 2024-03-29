#ifndef DIFFERCIATOR_DED
#define DIFFERCIATOR_DED
#include "TreeRead.h"
#include <math.h>
#include <cstdlib>
#include "LatexDump.h"

#define _ADD(left, ...)	CreateCommandNode(ADD, left, __VA_ARGS__)
#define _SUB(left, ...) CreateCommandNode(SUB, left, __VA_ARGS__) 
#define _MUL(left, ...) CreateCommandNode(MUL, left, __VA_ARGS__)
#define _DIV(left, ...) CreateCommandNode(DIV, left, __VA_ARGS__)
#define _POW(left, ...) CreateCommandNode(POW, left, __VA_ARGS__)
#define _LOG(left, ...) CreateCommandNode(LOG, left, __VA_ARGS__)
#define _COS(left)      CreateCommandNode(COS, left, nullptr)
#define _SIN(left)      CreateCommandNode(SIN, left, nullptr)
#define _IMM(num)		CreateImmNode(num, nullptr, nullptr)

#define DIFF_EXPR(node, var) DiffExprNode(node, var, latex_logfile)

#define DIFF_COMPOSITION_FUNC(expr) _MUL(expr, DIFF_EXPR(LEFT, diff_var))

#define LEFT  node->left
#define RIGHT node->right

#define PRINT_LATEX_LEFT  PrintLatexNode(child->left, child, file);
#define PRINT_LATEX_RIGHT PrintLatexNode(child->right, child, file);

const int	 MAX_TAYLOR_LEN = 5;
const double EXP			= 2.72;
const double EPSILON		= 0.01;

enum ExprCommands {
	#define DEF_EXPR_CMD(cmd_name, command, code, priority, handle, ...) cmd_name = code,

	#include "def_expr_cmd.h"

	#undef DEF_EXPR_CMD
};

void SetVarInNode(Node* node, ExprVar var, double point);

double LogBase(double num, double base);
double Eval(const Node* node);

int Factorial(int num);
void TaylorExpr(Tree* expr, ExprVar var, double point);
void GetTangentInPoint(Tree* tree, ExprVar diff_var, double point);

void  DiffExprNTimes(int N, Tree* tree, ExprVar diff_var);
Node* DiffExprNode(Node* node, ExprVar diff_var, FILE* latex_logfile);
void  DiffExprTree(Tree* tree, ExprVar diff_var);
#endif // !DIFFERCIATOR_DED
