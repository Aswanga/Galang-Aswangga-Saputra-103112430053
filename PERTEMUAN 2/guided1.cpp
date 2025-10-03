#include <iostream>
using namespace std;

int main() {
    int bukuperhari[7] = {2, 1, 3, 2, 4, 5, 1};
    int totalbuku = 0;

    cout << "Laporan baca buku mingguan" << endl;

    // mengakses setiap elemen array menggunakan loop
    for (int i = 0; i < 7; i++) {
        // mencetak nilai dari elemen pada indeks
        cout << "Hari ke-" << i + 1 << " : " << bukuperhari[i]
             << " buku" << endl;
        totalbuku += bukuperhari[i];
    }

    cout << "Total buku yang dibaca minggu ini: " << totalbuku << endl;

    // tambahan: menghitung rata-rata
    double rata = (double)totalbuku / 7;
    cout << "Rata-rata buku per hari: " << rata << endl;

    return 0;
}
