#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

typedef struct Node {
    int coef;
    int exp;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} Polynomial;

Polynomial* createPolynomial();
void insertTerm(Polynomial* poly, int coef, int exp);
Polynomial* addPolynomials(Polynomial* poly1, Polynomial* poly2);
void printPolynomial(const Polynomial* poly);
void Polynomial_destroy(Polynomial* poly);

#endif

