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

void insertLast(List &L, address P) {
    P->prev = L.last;
    P->next = Nil;
    if (L.last != Nil)
        L.last->next = P;
    else
        L.first = P;
    L.last = P;
}

void insertAfter(List &L, address P, address R) {
    P->next = R->next;
    P->prev = R;
    if (R->next != Nil)
        R->next->prev = P;
    else
        L.last = P;
    R->next = P;
}

void printForward(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void printBackward(List L) {
    address P = L.last;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->prev;
    }
    cout << endl;
}

// SMART INSERT
void smartInsert(List &L, infotype x) {
    address P = alokasi(x);
    cout << "Smart Insert: ";

    // 1) List kosong
    if (L.first == Nil) {
        insertFirst(L, P);
        cout << "List kosong, insert " << x << " di first" << endl;
        return;
    }

    // 2) Nilai lebih kecil dari elemen pertama
    if (x < L.first->info) {
        insertFirst(L, P);
        cout << x << " < first, insert di first" << endl;
        return;
    }

    // 3) Nilai genap
    if (x % 2 == 0) {
        insertLast(L, P);
        cout << x << " genap, insert di last" << endl;
        return;
    }

    // 4) Nilai ganjil (di antara dua nilai)
    address Q = L.first;
    bool inserted = false;
    while (Q->next != Nil) {
        if (Q->info < x && x < Q->next->info) {
            insertAfter(L, P, Q);
            cout << x << " di antara " << Q->info << " dan " << Q->next->info << endl;
            inserted = true;
            break;
        }
        Q = Q->next;
    }

    // Jika tidak menemukan posisi di tengah
    if (!inserted) {
        insertLast(L, P);
        cout << x << " insert di last (tidak menemukan posisi tengah)" << endl;
    }
}

// CONDITIONAL DELETE (hapus semua bilangan ganjil)
void conditionalDelete(List &L) {
    cout << "Sebelum Conditional Delete: ";
    printForward(L);

    address P = L.first;
    int count = 0;

    while (P != Nil) {
        address next = P->next;
        if (P->info % 2 != 0) { // hapus ganjil
            if (P == L.first) {
                L.first = P->next;
                if (L.first != Nil) L.first->prev = Nil;
                else L.last = Nil;
            } else if (P == L.last) {
                L.last = P->prev;
                if (L.last != Nil) L.last->next = Nil;
                else L.first = Nil;
            } else {
                P->prev->next = P->next;
                P->next->prev = P->prev;
            }
            dealokasi(P);
            count++;
        }
        P = next;
    }

    cout << "Conditional Delete: " << count << " elemen ganjil dihapus" << endl;
    cout << "Setelah Conditional Delete: ";
    printForward(L);
}

// MAIN PROGRAM
int main() {
    List L;
    L.first = Nil;
    L.last = Nil;

    cout << "ADVANCED OPERATIONS" << endl;
    cout << "SMART INSERT DEMO" << endl;

    smartInsert(L, 5);
    smartInsert(L, 3);
    smartInsert(L, 8);
    smartInsert(L, 6);
    smartInsert(L, 4);
    smartInsert(L, 7);

    cout << "\nHasil Smart Insert:" << endl;
    cout << "Forward: ";
    printForward(L);
    cout << "Backward: ";
    printBackward(L);
    cout << endl;

    cout << "CONDITIONAL DELETE" << endl;
    conditionalDelete(L);
    cout << endl;

    cout << "DELETE BY VALUE DEMO" << endl;
    // hapus nilai 6
    int x = 6;
    address P = L.first;
    while (P != Nil && P->info != x) P = P->next;
    if (P != Nil) {
        if (P == L.first) {
            L.first = P->next;
            if (L.first != Nil) L.first->prev = Nil;
        } else if (P == L.last) {
            L.last = P->prev;
            if (L.last != Nil) L.last->next = Nil;
        } else {
            P->prev->next = P->next;
            P->next->prev = P->prev;
        }
        cout << "Nilai " << x << " berhasil dihapus" << endl;
        dealokasi(P);
    } else {
        cout << "Nilai " << x << " tidak ditemukan" << endl;
    }

    // hapus nilai 10
    x = 10;
    P = L.first;
    while (P != Nil && P->info != x) P = P->next;
    if (P != Nil) {
        if (P == L.first) {
            L.first = P->next;
            if (L.first != Nil) L.first->prev = Nil;
        } else if (P == L.last) {
            L.last = P->prev;
            if (L.last != Nil) L.last->next = Nil;
        } else {
            P->prev->next = P->next;
            P->next->prev = P->prev;
        }
        cout << "Nilai " << x << " berhasil dihapus" << endl;
        dealokasi(P);
    } else {
        cout << "Nilai " << x << " tidak ditemukan" << endl;
    }

    cout << "List akhir: ";
    printForward(L);
    cout << endl;

    cout << "DELETE ALL DEMO" << endl;
    int count = 0;
    while (L.first != Nil) {
        address temp = L.first;
        L.first = L.first->next;
        dealokasi(temp);
        count++;
    }
    L.last = Nil;
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;

    return 0;
}