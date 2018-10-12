#include <iostream>
#include <cstring>
#include <cctype>

#include "Stack.h"
#include "Queue.h"

#define PARENTHESIS 0
#define OPERATOR1 1
#define OPERATOR2 2

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

unsigned int getType(const char* operateur) {
	//TODO changer a opérateurs uniquement
	if (operateur == "+") {
		return ADDITION;
	}
	else if (operateur == "-") {
		return SUBSTRACTION;
	}
	else if (operateur == "*") {
		return MULTIPLICATION;
	}
	else if (operateur == "/") {
		return DIVISION;
	}
	else if (operateur == "%") {
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

	SLIterator<const char*>* iterateur = infixExpressionQueue->begin();

	std::cout << "Infix : ";
	for (unsigned int i = 0; i < infixExpressionQueue->size(); i++) {
		std::cout << iterateur->getData();
		iterateur->goNext();
	}
	//On le supprime maintenant pour ne pas l'oublier
	delete iterateur;

	std::cout << endl;

	// TODO : Infixe à postfixe...
	while (infixExpressionQueue->size() > 0) {
		if (infixExpressionQueue->front() != "(" && infixExpressionQueue->front() != ")" && infixExpressionQueue->front() != "+" && infixExpressionQueue->front() != "-" && infixExpressionQueue->front() != "*" && infixExpressionQueue->front() != "/" && infixExpressionQueue->front() != "%") {
			postfixExpressionQueue->push(infixExpressionQueue->front());
			infixExpressionQueue->pop();
		}
		else if (infixExpressionQueue->front() == "(") {
			operandStack->push(infixExpressionQueue->front());
			infixExpressionQueue->pop();
		}
		else if (infixExpressionQueue->front() == ")") {
			infixExpressionQueue->pop();
			while (operandStack->top() != "(" && operandStack->size() > 0) {
				postfixExpressionQueue->push(operandStack->top());
				operandStack->pop();
			}
			operandStack->pop();
		}
		else {
			priority = getPriority(infixExpressionQueue->front());


			switch (priority) {
				//"+" || "+"
			case 1:

				//Boucler until empty stack ou que la valeur au top soit "("
				while (operandStack->size() && getPriority(operandStack->top()) >= OPERATOR1) {
					postfixExpressionQueue->push(operandStack->top());
					operandStack->pop();
				}
				operandStack->push(infixExpressionQueue->front());
				break;
				//"*" || "/" || "%"
			case 2:

				//Boucle jusqu'� ce que la pile soit vide ou que la valeur sur le dessus de la pile soit une paranth�se ouvrante, un plus ou un moins
				while (operandStack->size() && getPriority(operandStack->top()) >= OPERATOR2) {
					postfixExpressionQueue->push(operandStack->top());
					operandStack->pop();
				}
			
					operandStack->push(infixExpressionQueue->front());
				break;
			}
			infixExpressionQueue->pop();
		}
	}

	//Vider la pile
	for (unsigned int i = 0; i <= operandStack->size(); i++) {
		postfixExpressionQueue->push(operandStack->top());
		operandStack->pop();
	}
	delete infixExpressionQueue;

	std::cout << "Postfix : ";
	//Afficher l'expression postfixe
	iterateur = postfixExpressionQueue->begin();
	for (unsigned int i = 0; i < postfixExpressionQueue->size(); i++) {
		cout << iterateur->getData();
		iterateur->goNext();
	}
	delete iterateur;

	std::cout << endl;

	// TODO : Postfixe à résultat...
	while (postfixExpressionQueue->size()) {
		// V�rifie si le caract�re est un op�rande
		if (postfixExpressionQueue->front() != "+" && postfixExpressionQueue->front() != "-" && postfixExpressionQueue->front() != "*" && postfixExpressionQueue->front() != "/" && postfixExpressionQueue->front() != "%") {
			operandStack->push(postfixExpressionQueue->front());
		}
		// Caract�re est un op�rateur
		else {
			type = getType(postfixExpressionQueue->front());
			entier2 = atoi(operandStack->top());
			operandStack->pop();
			entier1 = atoi(operandStack->top());
			operandStack->pop();

			// 
			switch (type) {
				// Addition
			case ADDITION:
				resultat = entier1 + entier2;
				break;
				// Soustraction
			case SUBSTRACTION:
				resultat = entier1 - entier2;
				break;
				// Multiplication
			case MULTIPLICATION:
				resultat = entier1 * entier2;
				break;
				// Division
			case DIVISION:
				resultat = entier1 / entier2;
				break;
				// Modulo
			case MODULO:
				resultat = entier1 % entier2;
				break;
			}
			sprintf_s(tabCaracteres, "%i", resultat);
			operandStack->push(tabCaracteres);
		}
		postfixExpressionQueue->pop();
	}
	delete postfixExpressionQueue;

	std::cout << "Evaluation : ";
	// TODO : Afficher le résultat...
	
	std::cout << operandStack->top();
	std::cout << endl;
	delete operandStack;

	getchar();
	return 0;
}
