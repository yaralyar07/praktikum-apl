#include <iostream>
#include <string>

using namespace std;

int main() {
    string nama_valid = "yaralyar"; 
    string password_valid = "043"; 

    string input_nama, input_password;
    bool login_sukses = false;

    for (int i = 1; i <= 3; i++) {
        cout << "Percobaan login ke-" << i << endl;
        cout << "Masukkan nama : ";
        getline(cin >> ws, input_nama); 
        cout << "Masukkan password (NIM) : ";
        cin >> input_password;

        if (input_nama == nama_valid && input_password == password_valid) {
            login_sukses = true;
            cout << "Login berhasil!" << endl;
            break; 
        } else {
            cout << "Nama atau password salah.\n\n";
        }
    }

    if (!login_sukses) {
        cout << "Anda gagal login 3 kali. Program berhenti." << endl;
        return 0; 
    }

    int pilihan;
    double nilai_awal, hasil_1, hasil_2;

    do {
        cout << "\nMenu Utama Konversi:" << endl;
        cout << "1. Konversi Meter -> Kilometer dan Centimeter" << endl;
        cout << "2. Konversi Kilometer -> Meter dan Centimeter" << endl;
        cout << "3. Konversi Centimeter -> Meter dan Kilometer" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        // m ke km dan cm
        if (pilihan == 1) {
            cout << "Masukkan nilai panjang (m): ";
            cin >> nilai_awal;
            hasil_1 = nilai_awal / 1000.0; 
            hasil_2 = nilai_awal * 100.0;  
            cout << "Hasil: " << hasil_1 << " km dan " << hasil_2 << " cm\n";
        
        // km ke m dan cm
        } else if (pilihan == 2) {
            cout << "Masukkan nilai panjang (km): ";
            cin >> nilai_awal;
            hasil_1 = nilai_awal * 1000.0;   
            hasil_2 = nilai_awal * 100000.0; 
            cout << "Hasil: " << hasil_1 << " m dan " << hasil_2 << " cm\n";
            
        // cm ke m dan km
        } else if (pilihan == 3) {
            cout << "Masukkan nilai panjang (cm): ";
            cin >> nilai_awal;
            hasil_1 = nilai_awal / 100.0;   
            hasil_2 = nilai_awal / 100000.0; 
            cout << "Hasil: " << hasil_1 << " m dan " << hasil_2 << " km\n";
            
        } else if (pilihan == 4) {
            cout << "Program selesai." << endl;
            
        } else {
            cout << "Pilihan tidak ada di menu." << endl;
        }

    } while (pilihan != 4); 

    return 0;
}