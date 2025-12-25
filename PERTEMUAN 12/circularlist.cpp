#include "circularlist.h"

void createList(List &L){
    L.first = Nil;
}

address alokasi(infotype x){
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address P){
    delete P;
}

void insertFirst(List &L, address P){
    if(L.first == Nil){
        L.first = P;
        P->next = P;
    } else {
        address Q = L.first;
        while(Q->next != L.first){
            Q = Q->next;
        }
        Q->next = P;
        P->next = L.first;
        L.first = P;
    }
}

void insertAfter(List &L, address Prec, address P){
    if(Prec != Nil){
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P){
    if(L.first == Nil){
        insertFirst(L, P);
    } else {
        address Q = L.first;
        while(Q->next != L.first){
            Q = Q->next;
        }
        Q->next = P;
        P->next = L.first;
    }
}

void deleteFirst(List &L, address &P){
    P = L.first;

    if(P->next == P){     // 1 elemen
        L.first = Nil;
    } else {
        address Q = L.first;
        while(Q->next != L.first){
            Q = Q->next;
        }
        L.first = P->next;
        Q->next = L.first;
    }
    P->next = Nil;
}

void deleteAfter(List &L, address Prec, address &P){
    P = Prec->next;

    if(P != Nil){
        Prec->next = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P){
    if(L.first->next == L.first){   // satu elemen
        deleteFirst(L, P);
    } else {
        address Q = L.first;
        while(Q->next->next != L.first){
            Q = Q->next;
        }
        P = Q->next;
        Q->next = L.first;
        P->next = Nil;
    }
}

address findElm(List L, infotype x){
    if(L.first == Nil) return Nil;

    address P = L.first;
    do{
        if(P->info.nim == x.nim){
            return P;
        }
        P = P->next;
    } while(P != L.first);

    return Nil;
}

void printInfo(List L){
    if(L.first == Nil){
        cout << "List kosong" << endl;
        return;
    }

    address P = L.first;

    do {
        cout << "Nama : " << P->info.nama << endl;
        cout << "NIM  : " << P->info.nim << endl;
        cout << "L/P  : " << P->info.jenis_kelamin << endl;
        cout << "IPK  : " << P->info.ipk << endl;
        cout << endl;
        P = P->next;
    } while(P != L.first);
}
