Travail 2
---------

Une expression arithmétique est composée d'opérandes et d'opérateurs exprimés de façon infixe. Mais pour évaluer une expression arithmétique, la priorité des opérateurs doit être respectée.

#### Priorités

0\. ( et )
1\. + et -
2\. \*, / et %

#### Infixe à Postfixe

Les programmes informatiques, dont les compilateurs, sont confrontés à l'évaluation d'expressions arithmétiques. Afin de simplifier la tâche, les expressions sont d'abord exprimées de façon postfixe.

*   Les opérandes sont directement ajoutés à la file postfixe.
*   Les parenthèses ouvrantes sont empilées sur la pile d'opérateurs.
*   Les parenthèses fermantes dépilent les opérateurs de la pile dans la file postfix jusqu'à une parenthèse ouvrante, aussi dépilée.
*   Les opérateurs sont empilés sur la pile après en avoir dépilé, dans la file postfixe, ceux ayant une priorité supérieure ou égale.
*   Lorsque la file infixe est vide, dépiler dans la file postfixe jusqu'à ce que la pile soit vide.

#### Postfixe à Résultat

Les expressions postfixe permettent d'évaluer le résultat en respectant les priorités des opérateurs.

*   Les opérandes sont directement empilés dans la pile d'opérandes.
*   Les opérateurs sont appliqués aux deux opérandes dépilés et le résultat empilé.
*   Suite à l'évaluation, le dessus de la pile consistera au résultat.

##### Conversion

Des fonctions spéciales permettent de passer d'un entier à un tableau de caractères et vice-versa :

int entier;
char tabCaracteres\[10\];

entier = atoi(tabCaracteres);  _// Conversion d'un entier vers un tableau de caractères._
sprintf(tabCaracteres, "%i", entier);  _// Conversion d'un tableau de caractères vers un entier._


_\* Sous Windows, « \_s » doit être ajouté à « sprintf »._

#### Résultat

Le programme doit afficher les résultats sous la forme suivante :

Infix : 1+2\*(5+10)+11
Postfix : 12510+\*+11+
Evaluation : 42

_\* Les expressions utilisées seront toujours valides.
\*\* Les opérandes utilisées seront toujours positives.
_
