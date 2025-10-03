#include <iostream>
#include <string>
using namespace std;

float hitungRataRata(int nilaiTugas, int nilaiUTS) {
    return (nilaiTugas + nilaiUTS) / 2.0f;
}

void cetakProfil(string nama, float nilai) {
    cout << "Nama : " << nama << endl;
    cout << "Nilai : " << nilai << endl;
}

void beriNilaiBonus(float &nilai) {
    nilai += 5.0f;
}

int main() {
    string namaSiswa = "Budi";
    int tugas = 80, uts = 90;

    float nilaiAkhir = hitungRataRata(tugas, uts);

    cout << "Profil Awal" << endl;
    cetakProfil(namaSiswa, nilaiAkhir);

    cout << "\nMemberikan nilai bonus..." << endl;
    beriNilaiBonus(nilaiAkhir);

    cout << "\nProfil Setelah Bonus" << endl;
    cetakProfil(namaSiswa, nilaiAkhir);

    return 0;
}
