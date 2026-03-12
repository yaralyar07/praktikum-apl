#include <iostream>
using namespace std;

int kuadrat(int x);
void sapa(string nama);

int main() {
    sapa("Andi");
    cout << "Hasil 3 kuadrat: " << kuadrat(3) << endl;
    return 0;
}

int kuadrat(int x) {
    return x * x;
}

void sapa(string nama) {
    cout << "Halo, " << nama << "!" << endl;
}