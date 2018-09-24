#include <iostream>
#include <cstring>

//#include "Stack.h"
//#include "Queue.h"

#define PARENTHESIS 0
#define OPERATOR 1
#define OPERAND 2

using namespace std;

int main() {
		/*
    Queue<const char*>* infixExpressionQueue = new Queue<const char*>();
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
		*/

		std::cout << "Infix : ";
    // TODO : Afficher l'expression infixe...
    cout << endl;

    // TODO : Infixe à postfixe...

    cout << "Postfix : ";
		// TODO : Afficher l'expression postfixe...
		cout << endl;

		// TODO : Postfixe à résultat...

		cout << "Evaluation : ";
		// TODO : Afficher le résultat...
		cout << endl;

		getchar();
    return 0;
}
