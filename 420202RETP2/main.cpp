#include <iostream>
#include <cstring>
#include <cctype>

#include "Stack.h"
#include "Queue.h"

#define PARENTHESIS 0
#define OPERATOR 1
#define OPERAND 2

using namespace std;

unsigned int getType(char grain) {
	switch (grain) {
		case '(':
		case ')':
			return PARENTHESIS;

		case '*':
		case '/':
		case '%':
		case '+':
		case '-':
			return OPERATOR;

		default:
			return OPERAND;
	}
}



int main() {

    Queue<const char*>* infixExpressionQueue = new Queue<const char*>();
		Stack<const char*>* stack = new Stack<const char*>();
    infixExpressionQueue->push("1");
    infixExpressionQueue->push("+");
    infixExpressionQueue->push("2");
    infixExpressionQueue->push("*");
    infixExpressionQueue->push("(");
    infixExpressionQueue->push("5");
    infixExpressionQueue->push("+");
    infixExpressionQueue->push("10");
    infixExpressionQueue->push(")");
    infixExpressionQueue->push("+");
    infixExpressionQueue->push("11");

		SLIterator<const char*>* infixIterator = infixExpressionQueue->begin();

		cout << "Infix : ";
		for (unsigned int i = 0; i < infixExpressionQueue->size(); i++) {
		  cout << infixIterator->getData();
		  infixIterator->goNext();
		}

	  cout << endl;

	  // TODO : Infixe à postfixe...
		while (infixExpressionQueue->size() > 0) {
			if (infixExpressionQueue->front()) {
				stack->push(infixExpressionQueue->front());
				infixExpressionQueue->pop();
			}
			else if (getType(infixExpressionQueue->front()[0]) == PARENTHESIS) {

			}
		}

	  cout << "Postfix : ";
		// TODO : Afficher l'expression postfixe...
		cout << endl;

		// TODO : Postfixe � r�sultat...

		cout << "Evaluation : ";
		// TODO : Afficher le r�sultat...
		cout << endl;

		getchar();
	  return 0;
}
