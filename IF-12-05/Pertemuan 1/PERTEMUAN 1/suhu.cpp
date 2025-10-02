#include <iostream>

using namespace std;

int main(){
    float celcius,fahrenheit;
    cout << "Tulis sedingin apa gebetan lu : ";
    cin >> celcius;
    fahrenheit = (9.0/5.0)* celcius + 32;
    cout << "Kalau di fahreheit itu " << fahrenheit << "derajat" <<endl;
    cout << "itu dingin banget sih, saran gua jauhin aja";
    return 0;
}