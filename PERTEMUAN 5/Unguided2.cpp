#include <iostream>
using namespace std;
#define Nil NULL

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    P->prev = Nil;
    if (L.first != Nil)
        L.first->prev = P;
    else
        L.last = P;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    P = L.first; L.first = L.first->next;
    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil;
    P->next = Nil; P->prev = Nil;
}

void deleteLast (List &L, address &P) {
    P = L.last; L.last = L.last->prev;
    if (L.last != Nil) L.last->next = Nil; else L.first = Nil;
    P->prev = Nil; P->next = Nil;
}

void deleteAfter (List &L, address &P, address R) {
    P = R->next; R->next = P->next;
    if (P->next != Nil) P->next->prev = R; else L.last = R;
    P->prev = Nil; P->next = Nil;
}

bool deleteByValue(List &L, infotype x) {
    address P = L.first;

    while (P != Nil && P->info != x) {
        P = P->next;
    }

    if (P == Nil) {
        cout << "Nilai " << x << " tidak ditemukan" << endl;
        return false;
    }

    if (P == L.first) {
        L.first = P->next;
        if (L.first != Nil)
            L.first->prev = Nil;
        else
            L.last = Nil;
    } else if (P == L.last) {
        L.last = P->prev;
        if (L.last != Nil)
            L.last->next = Nil;
        else
            L.first = Nil;
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }

    cout << "Nilai " << x << " berhasil dihapus" << endl;
    dealokasi(P);
    return true;
}

void deleteAll(List &L) {
    address P = L.first;
    int count = 0;
    while (P != Nil) {
        address temp = P;
        P = P->next;
        dealokasi(temp);
        count++;
    }
    L.first = Nil;
    L.last = Nil;
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
}

int main() {
    List L;
    L.first = Nil;
    L.last = Nil;

    cout << "TASK 1: DELETE OPERATIONS" << endl;

    // List awal: 2 3 2 1
    insertFirst(L, alokasi(1));
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(3));
    insertFirst(L, alokasi(2));

    cout << "List awal: ";
    printInfo(L);

    // Delete by value 2
    deleteByValue(L, 2);
    cout << "Setelah deleteByValue(2): ";
    printInfo(L);

    // Delete value yang tidak ada
    deleteByValue(L, 5);
    cout << "List tetap: ";
    printInfo(L);

    // Tambah data baru
    insertFirst(L, alokasi(5));
    cout << "List setelah tambah data: ";
    printInfo(L);

    // Delete semua elemen
    deleteAll(L);

    return 0;
}