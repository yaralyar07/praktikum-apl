#include <iostream>

using namespace std;

int main() {
    int tahun;

    cout << "Masukkan Tahun: ";
    cin >> tahun;

    if (tahun % 400 == 0) {
        cout << tahun << " Tahun Kabisat.\n";
    } 
    else if (tahun % 100 == 0) {
        cout << tahun << " Bukan Tahun Kabisat.\n";
    } 
    else if (tahun % 4 == 0) {
        cout << tahun << " Tahun Kabisat.\n";
    } 
    else {
        cout << tahun << " Bukan Tahun Kabisat.\n";
    }

    return 0;
}