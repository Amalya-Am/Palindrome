#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initializeQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

bool emptyQueue(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (emptyQueue(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct Queue* q) {
    if (emptyQueue(q)) {
        printf("Queue is empty.\n");
        exit(1);
    }
    struct Node* frontNode = q->front;
    char data = frontNode->data;
    q->front = frontNode->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(frontNode);
    return data;
}

bool palindromeString(const char* string) {
    struct Queue queue;
    initializeQueue(&queue);

    int length = strlen(string);

    for (int i = 0; i < length; i++) {
        enqueue(&queue, string[i]);
    }

    int i = length - 1;
    while (!emptyQueue(&queue)) {
        char c = dequeue(&queue);
        if (c != string[i]) {
            return false; 
        }
        i--;
    }

    return true; 
}

int main() {
    char inputStr[100];

    printf("Enter a string: ");
    scanf("%s", inputStr);
    if (palindromeString(inputStr)) {
        printf("%s is a palindrome.\n", inputStr);
    } else {
        printf("%s is not a palindrome.\n", inputStr);
    }

    return 0;
}
