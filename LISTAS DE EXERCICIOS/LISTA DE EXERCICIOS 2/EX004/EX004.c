/*
Usando pilha, crie uma função para verificar se uma expressão composta apenas por chaves,
colchetes e parênteses, representada por uma cadeia de caracteres, está ou não balanceada. Por
exemplo, as expressões "[{()()}{}]" e "{[([{}])]}" estão balanceadas, mas as
expressões "{[(}])" e "{[)()(]}" não estão.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

bool isBalancedExpression(const char *expression) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(&stack) || !isMatchingPair(stack.data[stack.top], expression[i])) {
                return false;
            }
            pop(&stack);
        }
    }

    return isEmpty(&stack);
}

int main() {
    const char *expression1 = "[{()()}{}]";
    const char *expression2 = "{[([{}])]}";
    const char *expression3 = "{[(}])";
    const char *expression4 = "{[)()(]}";

    printf("%s is %sbalanced.\n", expression1, isBalancedExpression(expression1) ? "" : "not ");
    printf("%s is %sbalanced.\n", expression2, isBalancedExpression(expression2) ? "" : "not ");
    printf("%s is %sbalanced.\n", expression3, isBalancedExpression(expression3) ? "" : "not ");
    printf("%s is %sbalanced.\n", expression4, isBalancedExpression(expression4) ? "" : "not ");

    return 0;
}