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