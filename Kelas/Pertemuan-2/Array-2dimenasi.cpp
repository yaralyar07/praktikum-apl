#include <iostream>
using namespace std;

// Inisialisasi matriks (boleh di luar/global atau di dalam main)
int matriks[3][3] = {
    {1, 2, 3}, // Baris ke - 0 
    {4, 5, 6}, // Baris ke - 1 
    {7, 8, 9}  // Baris ke - 2
};

int main() {
    // 1. Mengakses elemen spesifik
    cout << "Elemen [0][1]: " << matriks[0][1] << endl;
    cout << "Elemen [2][0]: " << matriks[2][0] << endl;
    cout << "----------------" << endl;

    // 2. Menampilkan seluruh matriks dengan nested loop (i dan j)
    cout << "Menggunakan for loop biasa:" << endl;
    for (int i = 0; i < 3; i++) {        
        for (int j = 0; j < 3; j++) {    
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------" << endl;

    // 3. Menampilkan dengan Range-based for loop (C++11 ke atas)
    cout << "Menggunakan range-based loop:" << endl;
    for (auto &baris : matriks) { 
        for (auto &elemen : baris) { 
            cout << elemen << " ";
        }
        cout << endl;
    }

    return 0;
}