#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define Node structure for Stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define Stack structure managing the top pointer
typedef struct {
    Node* top;
} Stack;

// Initialize stack
void initStack(Stack* s) {
    s->top = NULL;
}

// Check if stack is empty
bool isEmpty(Stack* s) {
    return s->top == NULL;
}

// Push operation: Insert element at the top
void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("    [ERROR] Heap overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    printf("    [PUSH] Pushed %d onto stack\n", value);
}

// Pop operation: Remove element from the top
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("    [ERROR] Stack underflow! Cannot pop from empty stack.\n");
        return -1;
    }
    Node* temp = s->top;
    int poppedVal = temp->data;
    s->top = temp->next;
    free(temp);
    printf("    [POP] Popped %d from stack\n", poppedVal);
    return poppedVal;
}

// Peek operation: View top element without removing
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("    [INFO] Stack is empty.\n");
        return -1;
    }
    return s->top->data;
}

// Display stack contents from top to bottom
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("    [INFO] Stack is currently empty.\n");
        return;
    }
    Node* temp = s->top;
    printf("    STACK (Top -> Bottom): ");
    while (temp != NULL) {
        printf("[%d] ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    printf("==================================================\n");
    printf("      DATA STRUCTURES: STACK (LIFO) ENGINE        \n");
    printf("==================================================\n\n");

    Stack s;
    initStack(&s);

    // 1. Push Operations
    printf("[1] PUSHING ELEMENTS ONTO STACK:\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);
    printf("\n");

    // 2. Peek Operation
    printf("[2] PEEK OPERATION:\n");
    printf("    Current top element is: %d\n\n", peek(&s));

    // 3. Pop Operations
    printf("[3] POPPING ELEMENTS FROM STACK:\n");
    pop(&s);
    display(&s);

    printf("\n==================================================\n");

    return 0;
}
