#include <iostream>
using namespace std;

void tukarsenjata(string &senjata) {
    senjata = "Sarung Wadimor";
}

int main() {
    string senjatahero = "Kayu Busuk";

    cout << "Senjata awal: " << senjatahero << endl;

    tukarsenjata(senjatahero);
    cout << "Senjata sekarang: " << senjatahero << endl;

    return 0;
}