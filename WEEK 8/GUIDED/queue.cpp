#include "queue.h"
#include <iostream>

using namespace std;


void createQueue(Queue &Q){
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0;
}


bool isEmpty(Queue Q) {
    return Q.count == 0;
}


bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE;
}


void enqueue(Queue &Q, int x) {
    if(!isFull(Q)) {
        Q.info[Q.tail] = x;

        Q.tail = (Q.tail + 1) % MAX_QUEUE;
        Q.count++;
    } else {
        cout << "Antrean Penuh!" << endl;
    }
}


int dequeue(Queue &Q) {
    if(!isEmpty(Q)) {
        int x = Q.info[Q.head];
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--;
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}


void printInfo(Queue Q) {
    cout << "Isi Queue : [";
    if(!isEmpty(Q)) {
        int i = Q.head;
        int n = 0;
        while (n < Q.count) {
            cout << Q.info[i] << " ";
            i = (i + 1) % MAX_QUEUE;
            n++;
        }
    }
    cout << "]" << endl;
}