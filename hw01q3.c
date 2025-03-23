/* This C program demonstrates the switch statement
*
* Completion time: 0.5 hours
*
* author: Ben Higginbotham
* version: 03-22-2025
*/

#include <stdio.h>
int  main() {
    char ch = '+';
    int a = 10, b = 20;
    double f;

    printf("ch = %c\n", ch);
    switch (ch) {
        case '+': f = a + b; printf("f = %.2f\n", f); break;
        case '-': f = a - b; printf("f = %.2f\n", f); break;
        case '*': f = a * b; printf("f = %.2f\n", f); break;
        case '/': f = (float)a / b; printf("f = %.2f\n", f); break;
        default: printf("invalid operator\n");
    }

    ch = '-';
    printf("ch = %c\n", ch);
    switch (ch) {
        case '+': f = a + b; printf("f = %.2f\n", f); break;
        case '-': f = a - b; printf("f = %.2f\n", f); break;
        case '*': f = a * b; printf("f = %.2f\n", f); break;
        case '/': f = (float)a / b; printf("f = %.2f\n", f); break;
        default: printf("invalid operator\n");
    }

    ch = '*';
    printf("ch = %c\n", ch);
    switch (ch) {
        case '+': f = a + b; printf("f = %.2f\n", f); break;
        case '-': f = a - b; printf("f = %.2f\n", f); break;
        case '*': f = a * b; printf("f = %.2f\n", f); break;
        case '/': f = (float)a / b; printf("f = %.2f\n", f); break;
        default: printf("invalid operator\n");
    }

    ch = '/';
    printf("ch = %c\n", ch);
    switch (ch) {
        case '+': f = a + b; printf("f = %.2f\n", f); break;
        case '-': f = a - b; printf("f = %.2f\n", f); break;
        case '*': f = a * b; printf("f = %.2f\n", f); break;
	case '/': f = (float)a / b; printf("f = %.2f\n", f); break;
        default: printf("invalid operator\n");
    }

    ch = '%';
    printf("ch = %c\n", ch); 
    switch (ch) {
        case '+': f = a + b; printf("f = %.2f\n", f); break;
        case '-': f = a - b; printf("f = %.2f\n", f); break;
        case '*': f = a * b; printf("f = %.2f\n", f); break;
        case '/': f = (float)a / b; printf("f = %.2f\n", f); break;
        default: printf("invalid operator\n");
    }
}
