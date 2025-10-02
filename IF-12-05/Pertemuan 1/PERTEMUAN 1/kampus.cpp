#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string kampus[]={"Universitas Telkom","Universitas Indonesia","Institut Teknologi Bandung","Universitas Gadjah mada","Universitas Airlangga"};

    cout << "Daftar Nama Kampus:" << endl;

    for (const std::string& namaKampus : kampus){
        cout<<"-"<<namaKampus << endl;
    }
    return 0;
}