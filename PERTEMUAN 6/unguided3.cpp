#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);

    // gunakan fungsi getInputStream untuk membaca input angka dari user
    getInputStream(S);

    // tampilkan isi stack hasil input
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    // tampilkan hasil setelah dibalik
    printInfo(S);

    return 0;
}