#ifndef STACK_H
#define STACK_H

#include <iostream>

#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(const Stack &S);
bool isFull(const Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif // STACK_H
