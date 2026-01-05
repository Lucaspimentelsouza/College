#include <stdio.h>
#include "polynomial.h"

int main() {
    Polynomial* poly1 = createPolynomial();
    Polynomial* poly2 = createPolynomial();

    insertTerm(poly1, 5, 4);
    insertTerm(poly1, 6, 3);
    insertTerm(poly1, 7, 0);

    insertTerm(poly2, 2, 3);
    insertTerm(poly2, -7, 2);
    insertTerm(poly2, 3, 1);

    printf("Polinômio 1: ");
    printPolynomial(poly1);
    printf("Polinômio 2: ");
    printPolynomial(poly2);

    Polynomial* result = addPolynomials(poly1, poly2);

    printf("Resultado: ");
    printPolynomial(result);

    Polynomial_destroy(poly1);
    Polynomial_destroy(poly2);
    Polynomial_destroy(result);

    return 0;
}

