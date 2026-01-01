#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "sparepart_tree.h"
using namespace std;

// ================== TANGGAL ===================
string tanggalHariIni() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int d = ltm->tm_mday;
    int m = 1 + ltm->tm_mon;
    int y = 1900 + ltm->tm_year;

    return to_string(d) + "-" + to_string(m) + "-" + to_string(y);
}

// ================== LOAD DATA ===================
void loadMatic(Node*& root) {
    root = nullptr;
    root = insertNode(root, "Oli Mesin", 2000, 3000);
    root = insertNode(root, "Busi (Nikel)", 4000, 8000);
    root = insertNode(root, "Oli Gardan", 4000, 6000);
    root = insertNode(root, "Kampas Rem", 4000, 8000);
    root = insertNode(root, "Filter Udara", 5000, 10000);
    root = insertNode(root, "Roller", 12000, 20000);
    root = insertNode(root, "V-Belt", 15000, 25000);
    root = insertNode(root, "Aki / Battery", 20000, 40000);
}

void loadManual(Node*& root) {
    root = nullptr;
    root = insertNode(root, "Oli Mesin", 2000, 3000);
    root = insertNode(root, "Busi (Nikel)", 4000, 8000);
    root = insertNode(root, "Kampas Rem", 4000, 8000);
    root = insertNode(root, "Gear Set", 10000, 15000);
    root = insertNode(root, "Kampas Kopling", 15000, 30000);
    root = insertNode(root, "Aki / Battery", 20000, 40000);
}

// ================== MAIN ===================
int main() {
    int menu;

    do {
        cout << "\n===== SISTEM REKOMENDASI SPAREPART =====\n";
        cout << "1. Input servis\n";
        cout << "2. Cek riwayat servis\n";
        cout << "3. Hapus semua riwayat\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        // ================== MENU 1 ===================
        if (menu == 1) {
            cin.ignore();
            string namaKendaraan;
            cout << "Masukkan nama kendaraan: ";
            getline(cin, namaKendaraan);

            int jenis;
            cout << "1. Matic\n2. Manual\nPilih jenis motor: ";
            cin >> jenis;

            Node* root = nullptr;
            string jenisMotor;

            if (jenis == 1) {
                loadMatic(root);
                jenisMotor = "Matic";
            } else {
                loadManual(root);
                jenisMotor = "Manual";
            }

            int km;
            cout << "Masukkan kilometer saat ini: ";
            cin >> km;

            ofstream file("riwayat_servis.csv", ios::app);

            file << "Tanggal : " << tanggalHariIni() << "\n";
            file << "Nama Kendaraan : " << namaKendaraan << "\n";
            file << "Jenis Motor : " << jenisMotor << "\n";
            file << "Kilometer : " << km << "\n";
            file << "Sparepart Diganti :\n";

            bool ada = false;

            if (km < 2000) {
                cout << "\nTidak ada sparepart yang perlu diganti\n";
                file << "- Tidak ada sparepart yang diganti\n";
            } 
            else {
                cout << "\nSparepart yang direkomendasikan:\n";

                if (jenis == 1)
                    ada = displayNeededPartsMatic(root, km, file);
                else
                    ada = displayNeededPartsManual(root, km, file);

                if (!ada) {
                    cout << "- Tidak ada sparepart yang perlu diganti\n";
                    file << "- Tidak ada sparepart yang diganti\n";
                }
            }

            file << "========================\n";
            file.close();
            freeTree(root);

            cout << "\nData tersimpan!\n";
        }

        // ================== MENU 2 ===================
        else if (menu == 2) {
            cout << "\n===== RIWAYAT SERVIS =====\n";
            ifstream file("riwayat_servis.csv");

            if (!file) {
                cout << "Belum ada riwayat.\n";
            } else {
                string line;
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            }
        }

        // ================== MENU 3 ===================
        else if (menu == 3) {
            remove("riwayat_servis.csv");
            cout << "Semua riwayat berhasil dihapus.\n";
        }

    } while (menu != 4);

    cout << "Program selesai.\n";
    return 0;
}
