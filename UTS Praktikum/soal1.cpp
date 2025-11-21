#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = nullptr;

// fungsi insert nama untuk di akhir list
void insertNama(string nama) {
    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// fungsi delete nama pertama yang ditemukan 
void deleteNama(string nama) {
    if (head == nullptr) return;

    if (head->nama == nama) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->nama != nama) {
        current = current->next;
    }

    if (current->next != nullptr && current->next->nama == nama) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// fungsi view seluruh list
void viewList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->nama << " ";
        temp = temp->next;
    }
    cout << endl;
}

// fungsi hitung dan tampilkan nama dengan jumlah huruf genap
int hitungGenap() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->nama.length() % 2 == 0) {
            cout << temp->nama << " ";
            count++;
        }
        temp = temp->next;
    }
    cout << endl;
    return count;
}

int main() {
    int menu;
    string nama;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
        cout << "Masukkan menu: ";
        cin >> menu;
        cin.ignore(); // membersihkan buffer

        switch(menu) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, nama);
                insertNama(nama);
                break;
            case 2:
                cout << "Masukkan nama untuk delete: ";
                getline(cin, nama);
                deleteNama(nama);
                break;
            case 3:
                viewList();
                break;
            case 4: {
                int genapCount = hitungGenap();
                cout << "Jumlah nama dengan huruf genap: " << genapCount << endl;
                break;
            }
            case 0:
                cout << "Keluar program." << endl;
                break;
            default:
                cout << "Menu salah, coba lagi." << endl;
        }
    } while (menu != 0);

    // bersihkan memori linked list
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
