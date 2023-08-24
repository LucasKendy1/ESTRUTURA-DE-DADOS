#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

// Definição da estrutura de pilha
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Função para inicializar a pilha
void initialize(struct Stack *s) {
    s->top = -1;
}

// Função para verificar se a pilha está vazia
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Função para empilhar um caractere
void push(struct Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("A pilha está cheia.\n");
    } else {
        s->top++;
        s->items[s->top] = c;
    }
}

// Função para desempilhar um caractere
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("A pilha está vazia.\n");
        return '\0';
    } else {
        char c = s->items[s->top];
        s->top--;
        return c;
    }
}

// Função para inverter uma palavra
void reverseWord(char *word) {
    struct Stack stack;
    initialize(&stack);

    // Empilhar os caracteres da palavra
    for (int i = 0; i < strlen(word); i++) {
        push(&stack, word[i]);
    }

    // Desempilhar os caracteres para formar a palavra invertida
    for (int i = 0; i < strlen(word); i++) {
        word[i] = pop(&stack);
    }
}

// Função principal
int main() {
    char input[MAX_SIZE];
    printf("Digite uma frase: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    while (token != NULL) {
        reverseWord(token);
        printf("%s ", token);
        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}
