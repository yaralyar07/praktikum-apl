#include <iostream>
using namespace std;

void cobaUbahGaji(int gajiSaya) {
    gajiSaya = 1000000000;
    cout << "Gaji pas di dalam fungsi: " << gajiSaya << endl;
}

int main() {
    int gajiSaya = 5000000;

    cout << "Gaji awal: " << gajiSaya << endl;
    
    cobaUbahGaji(gajiSaya);
    cout << "Gaji setelah fungsi dipanggil: " << gajiSaya << endl;

    return 0;
}