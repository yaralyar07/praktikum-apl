#include <iostream>
using namespace std;

void pesankopi(string menu, string kadargula = "Normal") {
    cout << "Pesanan: " << menu << " | Gula: " << kadargula << endl;
}

int main() {
    pesankopi("Kopi Susu");
    pesankopi("Americano", "Less Sugar");

    return 0;
}