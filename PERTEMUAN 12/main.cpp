#include <iostream>
#include "circularlist.h"
using namespace std;

address createData(string nama, string nim, char jenis_kelamin, float ipk)
{
    infotype x;
    address P;

    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;

    P = alokasi(x);
    return P;
}

int main(){
    List L;
    address P1, P2;
    infotype x;

    createList(L);

    cout << "coba insert first, last, dan after" << endl << endl;

    // dasar: tambah beberapa elemen dengan insertFirst / insertLast
    P1 = createData("Danu", "04", 'l', 4.0);
    insertFirst(L, P1);

    P1 = createData("Fahmi", "06", 'l', 3.45);
    insertLast(L, P1);

    P1 = createData("Bobi", "02", 'l', 3.71);
    insertFirst(L, P1);

    P1 = createData("Ali", "01", 'l', 3.3);
    insertFirst(L, P1);

    P1 = createData("Gita", "07", 'p', 3.75);
    insertLast(L, P1);

    // 1) masukkan Cindi (03) setelah NIM "02" (Bobi)
    x.nim = "02";
    P1 = findElm(L, x);            // cari Bobi
    P2 = createData("Cindi", "03", 'p', 3.5);
    insertAfter(L, P1, P2);

    // 2) masukkan Hilmi (08) setelah NIM "07" (Gita)  -> jadi berada di akhir sesuai gambar
    x.nim = "07";
    P1 = findElm(L, x);            // cari Gita
    P2 = createData("Hilmi", "08", 'p', 3.3);
    insertAfter(L, P1, P2);

    // 3) masukkan Eli (05) setelah NIM "04" (Danu)
    x.nim = "04";
    P1 = findElm(L, x);            // cari Danu
    P2 = createData("Eli", "05", 'p', 3.4);
    insertAfter(L, P1, P2);

    printInfo(L);
    return 0;
}
