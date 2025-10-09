# Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Galang Aswangga Saputra
- **NIM**: 103112430053
- **Kelas**: 12-IF-05

## 2. Motivasi Belajar Struktur Data
tentunya selain karena agar lulus matkul ini agar bisa mengambil matkul selanjutnya, belajar struktur data itu penting karena di dalamnya mempelajari bahasa pemrograman c++ yang dimana bahsa ini mau ga mau anak if harus paham, karena banyak liat di dunia sosmed, orang orang tuh bisa menggunkan bahasa ini, jadi ya iri aja gitu, mana semester sebelumnya cuman bahas go
## 3. Dasar Teori
Struktur data adalah cara untuk menyimpan dan mengorganisir data dalam komputer agar dapat digunakan secara efisien. Berikut adalah teori dasar mengenai Array, Pointer, dan Fungsi:

-Array adalah salah satu struktur data paling dasar dan esensial dalam pemrograman. Secara sederhana, array adalah sekumpulan elemen yang disusun secara berurutan dan memiliki tipe data yang sama. Setiap elemen dalam array dapat diakses menggunakan indeks, yang biasanya dimulai dari nol. Penggunaan array memungkinkan penyimpanan dan manipulasi sejumlah besar data dengan cara yang efisien dan terstruktur. (Rumahcoding.co.id)
-Setiap variabel yang kita deklarasikan di program memiliki alamat memori di RAM. Alamat ini digunakan oleh komputer untuk menyimpan dan mengakses data. Nah, pointer adalah variabel khusus yang berisi alamat memori variabel lain.(codepolitan.com)
**Fungsi dan Parameter Referensi** Fungsi dalam C++ digunakan untuk memecah program menjadi bagian-bagian kecil yang dapat digunakan kembali. Salah satu konsep pentingnya adalah _pass by reference_, yaitu ketika variabel dikirim ke fungsi bukan sebagai salinan, tetapi sebagai referensi ke variabel asli. Dengan begitu, perubahan di dalam fungsi langsung mempengaruhi data aslinya. _“Penggunaan parameter referensi dalam fungsi memungkinkan efisiensi pemrosesan data dan mendukung prinsip modularitas dalam pemrograman”_
## 4. Guided
### 4.1 Guided 1

```cpp
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
```

output

![](output/1.png)

Penjelasan :
Program ini menampilkan jumlah buku yang dibaca tiap hari selama seminggu, menghitung total semua buku, lalu menampilkan rata-rata buku yang dibaca per hari.
### 4.2 Guided 2

```cpp
#include <iostream>

using namespace std;

int main(){
    float hargaproduk = 50000.0f;

    float* ptrharga;
    ptrharga = &hargaproduk;

    cout << "harga awal produk: RP"<<hargaproduk<< endl;
    cout <<"alamat memori harga:."<<ptrharga<<endl;

    cout<<"\n...memberikan diskon 10% melalui pointer..."<< endl;
    *ptrharga= *ptrharga*0.9;
    cout<<"harga setelah diskon: Rp"<<hargaproduk<<endl;

    return 0;
}
```

output

![](output/2.png)


penjelasan: 
Program ini menunjukkan bahwa pointer dapat digunakan untuk akses dan merubah nilai variabel secara tidak langsung melalui alamat memorinya.

### 4.3 Guided 3

```cpp
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
```

output
![](output/3.png)

penjelasan:
Program ini menghitung **nilai rata-rata siswa**, menampilkan profilnya, lalu menambahkan **bonus nilai** sebesar 5 menggunakan **referensi variabel**, sehingga nilai akhir siswa berubah tanpa perlu membuat variabel baru.
### G 

## 5. Unguided
### 5.1 Unguided 1
``` cpp
#include <iostream>
using namespace std;

void cetakStok(int arr[], int size) {
    cout <<"[";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << (i < size - 1 ? " " : ",");
}
    cout << "]" << endl;
}

int hitungTotalStok(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int* cariStokPalingSedikit(int arr[], int size) {
    int* ptrPalingSedikit = &arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *ptrPalingSedikit) {
            ptrPalingSedikit = &arr[i];
        }
    }
    return ptrPalingSedikit;
}

void tambahStokBonus(int* ptrStok){
    *ptrStok += 10;
}
int main() {
    int stokBuku[] = {12,8,25,5,18};
    int jumlahJenisBuku = 5;
    
    cout <<"Stok Buku Awal: " <<endl;
    cetakStok(stokBuku, jumlahJenisBuku);

    int total = hitungTotalStok(stokBuku, jumlahJenisBuku);
    cout <<"Total semua Stok Buku: " << total << endl;

    int* ptrStokRendah = cariStokPalingSedikit(stokBuku, jumlahJenisBuku);
    tambahStokBonus(ptrStokRendah);

    cout << "\nStok Buku Setelah Penambahan Bonus:" << endl;
    cetakStok(stokBuku, jumlahJenisBuku);

    return 0;
}
```

output
![](output/4.png)
penjelasan:
Program ini mengelola data stok buku menggunakan **array dan pointer**. Program menghitung total stok, mencari stok paling sedikit, lalu menambah 10 pada stok terendah melalui pointer, sehingga nilai dalam array langsung berubah tanpa perlu variabel baru.


## 6. Kesimpulan
jadi setelah saya mempelajari sedikir dari bahasa c++, bahasa ini ternyata tidak seseram yang di bayangkan
## 7. Referensi
1. [https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/](https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/)
2. https://www.codepolitan.com/blog/belajar-pointer-c-dasardasar-fungsi-dan-contoh-kode/
3. https://rumahcoding.co.id/array-konsep-implementasi-dan-penggunaan/