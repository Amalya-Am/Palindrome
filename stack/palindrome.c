#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 100

struct Stack{

	char arr[MAX_SIZE];
	int top;
};

void initializeStack(struct Stack* s){
	s->top = -1;
}

bool emptyStack(struct Stack* s){
        return s->top == -1;
}

bool fullStack(struct Stack* s){
        return s->top == MAX_SIZE - 1;
}

char popElement(struct Stack *s) {
    if (emptyStack(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0'; // Return null character for an empty stack
    } else {
        return s->arr[s->top--];
    }
}

void pushElement(struct Stack* a, char el){
	if(fullStack(a)){
		printf("Stack overflow: Can't push.\n");
	}
		

	a->arr[++a->top] = el;
}
bool palindromeString(const char* string){
    struct Stack stack;
    initializeStack(&stack);

    int i = 0;
    while (string[i] != '\0') {
        pushElement(&stack, string[i]);
        i++;
    }

    i = 0;
    while (string[i] != '\0') {
        char a = popElement(&stack);
        if (a != string[i]) {
            return false;
        }
        i++;
    }

    return true;
}
int main()
{
	char inputChar[MAX_SIZE];
	scanf("%s", inputChar);
	if(palindromeString(inputChar)){
		printf("String is palindrome.\n");
	} else {
		printf("String is not palindrome.\n");
	}

	return 0;

}


