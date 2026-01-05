#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

Node* createNode(int coef, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

Polynomial* createPolynomial() {
    Polynomial* poly = (Polynomial*)malloc(sizeof(Polynomial));
    poly->head = NULL;
    return poly;
}

void insertTerm(Polynomial* poly, int coef, int exp) {
    Node* newNode = createNode(coef, exp);
    if (poly->head == NULL || poly->head->exp < exp) {
        newNode->next = poly->head;
        poly->head = newNode;
    } else {
        Node* current = poly->head;
        while (current->next != NULL && current->next->exp > exp) {
            current = current->next;
        }
        if (current->next != NULL && current->next->exp == exp) {
            current->next->coef += coef;
            free(newNode);
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

Polynomial* addPolynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial* result = createPolynomial();
    Node* p1 = poly1->head;
    Node* p2 = poly2->head;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertTerm(result, p1->coef, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insertTerm(result, p2->coef, p2->exp);
            p2 = p2->next;
        } else {
            insertTerm(result, p1->coef + p2->coef, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insertTerm(result, p1->coef, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertTerm(result, p2->coef, p2->exp);
        p2 = p2->next;
    }
    return result;
}

void printPolynomial(const Polynomial* poly) {
    if (poly->head == NULL) {
        printf("0\n");
        return;
    }
    Node* current = poly->head;
    while (current != NULL) {
        printf("%dx^%d", current->coef, current->exp);
        current = current->next;
        if (current != NULL)
            printf(" + ");
    }
    printf("\n");
}

void Polynomial_destroy(Polynomial* poly) {
    Node* current = poly->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(poly);
}

