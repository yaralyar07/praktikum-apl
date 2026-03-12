#include <iostream>
using namespace std;

void tampilkanStatus(string namaHero, int level, double hp) {
    cout << " = STATUS HERO =" << endl;
    cout << "Nama : " << namaHero << endl;
    cout << "Level : " << level << endl;
    cout << "Darah : " << hp << "%" << endl;
    cout << "===================" << endl;
    cout << endl;
}

int main() {
    tampilkanStatus("Alucard", 15, 90.5);

    string hero2 = "Miya";
    int lvl2 = 12;
    double hp2 = 45.0;

    tampilkanStatus(hero2, lvl2, hp2);
    return 0;
}