#include "stack.h"
#include <iostream>

using namespace std;

void CreateStack(Stack &S) {
    S.top = Nil;
}

bool isEmpty(const Stack &S) {
    return S.top == Nil;
}

bool isFull(const Stack &S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack Penuh" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = -999; 
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack Kosong" << endl;
    }
    return x;
}

void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; --i) {
            cout << S.info[i] << (i==0 ? "" : " ");
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1);
        CreateStack(temp2);
        while (!isEmpty(S)) push(temp1, pop(S));
        while (!isEmpty(temp1)) push(temp2, pop(temp1));
        while (!isEmpty(temp2)) push(S, pop(temp2));
    }
}
