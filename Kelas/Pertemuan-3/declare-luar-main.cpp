#include <iostream>
using namespace std;

int kuadrat(int x) {
    return x * x;
}

void sapa(string nama) {
    cout << "Halo, " << nama << "!" << endl;
}

int main() {
    sapa("Budi");
    cout << "Hasil 5 kuadrat: " << kuadrat(5) << endl;
    return 0;
}