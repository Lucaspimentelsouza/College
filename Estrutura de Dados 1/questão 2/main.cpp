#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

void removeAccents(char *str) {
    char c;
    for (int i = 0; str[i] != '\0'; i++) {
        c = str[i];
        switch (c) {
            case 'á': case 'à': case 'ã': case 'â': case 'ä': str[i] = 'a'; break;
            case 'Á': case 'À': case 'Ã': case 'Â': case 'Ä': str[i] = 'A'; break;
            case 'é': case 'è': case 'ê': case 'ë': str[i] = 'e'; break;
            case 'É': case 'È': case 'Ê': case 'Ë': str[i] = 'E'; break;
            case 'í': case 'ì': case 'î': case 'ï': str[i] = 'i'; break;
            case 'Í': case 'Ì': case 'Î': case 'Ï': str[i] = 'I'; break;
            case 'ó': case 'ò': case 'õ': case 'ô': case 'ö': str[i] = 'o'; break;
            case 'Ó': case 'Ò': case 'Õ': case 'Ô': case 'Ö': str[i] = 'O'; break;
            case 'ú': case 'ù': case 'û': case 'ü': str[i] = 'u'; break;
            case 'Ú': case 'Ù': case 'Û': case 'Ü': str[i] = 'U'; break;
            case 'ç': str[i] = 'c'; break;
            case 'Ç': str[i] = 'C'; break;
        }
    }
}

void removeSpecialCaractere(char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '-' && str[i] != ',') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}

void toUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

int isPalindrome(const char *str) {
    Stack *stack = Stack_create();

    char Str[strlen(str) + 1];
    strcpy(Str, str);
	
    for (int i = 0; Str[i] != '\0'; i++) {
            Stack_push(stack, Str[i]);
    }
	
	//Stack_print(stack);
	
    for (int i = 0; Str[i] != '\0'; i++) {
            if (Str[i] != Stack_pop(stack)) {
                Stack_destroy(&stack);
                return 0; // Não é um palíndromo
            }
    }

    Stack_destroy(&stack);
    return 1; // É um palíndromo
}

int main() {
    char str[] = "A diva em Argel alegra-me a vida";
    
    printf("A string \"%s\" ", str);
    
    removeAccents(str);
    toUpperCase(str);
	removeSpecialCaractere(str);
	
    if (isPalindrome(str)) {
        printf("e um palindromo\n", str);
    } else {
        printf("nao e um palindromo\n", str);
    }
    return 0;
}
