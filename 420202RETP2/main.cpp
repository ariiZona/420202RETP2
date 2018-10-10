#include <iostream>
#include <cstring>
#include <cctype>

#include "Stack.h"
#include "Queue.h"

#define PARENTHESIS 0
#define OPERATOR 1
#define OPERAND 2

#define ADDITION 1
#define SUBSTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4
#define MODULO 5

using namespace std;

unsigned int getPriority(const char* operateur) {
	if (operateur == "(") {
		return PARENTHESIS;
	}
	else if (operateur == "+" || operateur == "-") {
		return OPERATOR1;
	}
	else if (operateur == "*" || operateur == "/" || operateur == "%") {
		return OPERATOR2;
	}
}

unsigned int getType(const char* operator) {
	//TODO changer a opérateurs uniquement
	if (operator == "+") {
		return ADDITION;
	}
	else if (operator == "-") {
		return SUBSTRACTION;
	}
	else if (operator == "*") {
		return MULTIPLICATION;
	}
	else if (operator == "/") {
		return DIVISION;
	}
	else if (operator == "%") {
		return MODULO;
	}
}


int main() {

	//Variables
	unsigned int priority;	// Priorit� d'un op�rateur
	unsigned int type;	// Type d'un op�rateur
	unsigned int entier1;	// Premier entier d'une op�ration
	unsigned int entier2;	// Deuxi�me entier d'une op�ration
	char tabCaracteres[10];	// R�sultat d'une op�ration en char
	unsigned int resultat;	// R�sultat d'une op�ration en unsigned int

	Queue<const char*>* infixExpressionQueue = new Queue<const char*>();
	Queue<const char*>* postfixExpressionQueue = new Queue<const char*>();
	Stack<const char*>* operandStack = new Stack<const char*>();

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
		if (infixExpressionQueue->front() != ("-" && "+" && "(" && ")" && "/" && "%")) {
			postfixExpressionQueue->push(infixExpressionQueue->front());
			infixExpressionQueue->pop();
		}
		else if (infixExpressionQueue->front() == "(") {
			operandStack->push(infixExpressionQueue->front());
			infixExpressionQueue->pop();
		}
		else if (infixExpressionQueue->front() == ")" {
			infixExpressionQueue->pop(); //TODO: vérifier this shit
			while (operandStack->top() != "(" && operandStack->size() > 0) {
				postfixExpressionQueue->push(operandStack->top());
				operandStack->pop();
			}
			operandStack->pop()
		}
		else {

		}
	}

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
