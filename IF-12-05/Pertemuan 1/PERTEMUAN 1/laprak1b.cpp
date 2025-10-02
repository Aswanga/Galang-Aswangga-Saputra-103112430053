#include <iostream>
using namespace std;

string satuan[] = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan",
                   "sepuluh","sebelas","dua belas","tiga belas","empat belas","lima belas",
                   "enam belas","tujuh belas","delapan belas","sembilan belas"};

string puluhan[] = {"","", "dua puluh","tiga puluh","empat puluh","lima puluh","enam puluh",
                    "tujuh puluh","delapan puluh","sembilan puluh"};

string terjemah(int n) {
    if (n < 20) return satuan[n];
    else if (n < 100) {
        int p = n / 10;
        int s = n % 10;
        if (s == 0) return puluhan[p];
        else return puluhan[p] + " " + satuan[s];
    } else if (n == 100) return "seratus";
    else return "di luar jangkauan";
}

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;
    cout << n << " : " << terjemah(n) << endl;
    return 0;
}
