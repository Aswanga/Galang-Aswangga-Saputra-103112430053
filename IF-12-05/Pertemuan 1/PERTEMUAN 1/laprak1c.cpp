#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;
    cout << "output:" << endl;

    for (int i = n; i >= 1; i--) {
        // kiri
        for (int j = i; j >= 1; j--)
            cout << j;
        cout << " * ";
        // kanan
        for (int j = 1; j <= i; j++)
            cout << j;
        cout << endl;
    }
    cout << "*" << endl;
    return 0;
}
