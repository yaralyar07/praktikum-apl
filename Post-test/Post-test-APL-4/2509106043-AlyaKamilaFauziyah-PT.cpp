#include <iostream>
#include <string>
#include <limits> 

using namespace std;

struct User {
    string username;
    string password;
    int movie_nextid;
    int series_nextid;
};

struct Tontonan {
    int id; 
    string judul;
    string tipe;      
    int total_eps;     
    int eps_ditonton;
    string status;
    User* owner_ptr; // poin plus ya mba/bang hehe
};

void cetak_garis() {
    cout << "\n===================================";
}

void cetak_garis(string teks) {
    cout << "\n=== " << teks << " ===";
}

int cari_id(Tontonan* daftar, int jumlah, int target, string owner, string tipe, int iter = 0) {
    if (iter >= jumlah) {
        return -1;
    }
    if (daftar[iter].id == target && daftar[iter].owner_ptr->username == owner && daftar[iter].tipe == tipe) {
        return iter;
    }
    return cari_id(daftar, jumlah, target, owner, tipe, iter + 1);
}

// regis 
void registrasi_akun(User* daftar_user, int* jumlah_user) {
    if (*jumlah_user < 10) {
        cout << "Buat Username: "; cin >> daftar_user[*jumlah_user].username;
        cout << "Buat Password: "; cin >> daftar_user[*jumlah_user].password;
        daftar_user[*jumlah_user].movie_nextid = 1;
        daftar_user[*jumlah_user].series_nextid = 1;
        (*jumlah_user)++; 
        cout << "Registrasi Berhasil!\n";
    } else { 
        cout << "[Error] Kapasitas user penuh!\n"; 
    }
}

// login 
void proses_login(User* daftar_user, int jumlah_user, string user_in, string pass_in, bool* login_berhasil, int* index_userlogin, int* jumlah_percobaan, bool* program_berjalan) {
    for (int i = 0; i < jumlah_user; i++) {
        if (user_in == daftar_user[i].username && pass_in == daftar_user[i].password) {
            *login_berhasil = true; 
            *index_userlogin = i;   
            break; 
        }
    }

    if (*login_berhasil) {
        *jumlah_percobaan = 0; 
    } else {
        (*jumlah_percobaan)++;
        cout << "[Error] Username atau Password salah! Sisa percobaan: " << 3 - *jumlah_percobaan << "\n";
        
        if (*jumlah_percobaan >= 3) {
            cout << "\n[Fatal] Terlalu banyak percobaan gagal. Program otomatis keluar.\n";
            *program_berjalan = false; 
        }
    }
}

// menu 1
void tambah_tontonan(Tontonan* daftar, int* jumlah_data, User* user_aktif) {
    if (*jumlah_data >= 100) {
        cout << "\n[Pemberitahuan] Maaf, kapasitas daftar tontonan sudah penuh (100/100)!\n";
        cout << "Silakan hapus beberapa data terlebih dahulu untuk menambah judul baru.\n";
        return;
    }

    cout << "\nTipe (1. Movie, 2. Series, 0. Batal): ";
    int pt; cin >> pt;
    
    if (cin.fail() || pt < 0 || pt > 2) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[Error] Pilihan tipe tidak valid. Dibatalkan.\n";
        return;
    }
    if (pt == 0) return;

    cout << "Judul: "; cin.ignore(); getline(cin, daftar[*jumlah_data].judul);
    
    if (pt == 1) {
        daftar[*jumlah_data].tipe = "Movie";
        daftar[*jumlah_data].id = user_aktif->movie_nextid++; 
        daftar[*jumlah_data].total_eps = 1;
    } else {
        daftar[*jumlah_data].tipe = "Series";
        daftar[*jumlah_data].id = user_aktif->series_nextid++;
        cout << "Total Episode: "; cin >> daftar[*jumlah_data].total_eps;
        
        if (cin.fail() || daftar[*jumlah_data].total_eps <= 0) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[Error] Jumlah episode tidak valid. Dibatalkan.\n";
            user_aktif->series_nextid--; 
            return;
        }
    }
    daftar[*jumlah_data].eps_ditonton = 0;
    daftar[*jumlah_data].status = "Rencana Menonton";
    
    daftar[*jumlah_data].owner_ptr = user_aktif; 
    
    (*jumlah_data)++;
    cout << "Data berhasil disimpan!\n";
}

// menu 2
void lihat_daftar(Tontonan* daftar, int jumlah_data, string current_user) {
    cout << "\n>> DAFTAR MOVIE <<";
    cout << "\nID\tJudul\t\t\tStatus\n";
    bool ada_movie = false;
    for (int i = 0; i < jumlah_data; i++) {
        if (daftar[i].owner_ptr->username == current_user && daftar[i].tipe == "Movie") {
            cout << daftar[i].id << "\t" << daftar[i].judul << "\t\t\t" << daftar[i].status << endl;
            ada_movie = true;
        }
    }
    if(!ada_movie) cout << "(Kosong)\n";

    cout << "\n>> DAFTAR SERIES <<";
    cout << "\nID\tJudul\t\t\tProgress\tStatus\n";
    bool ada_series = false;
    for (int i = 0; i < jumlah_data; i++) {
        if (daftar[i].owner_ptr->username == current_user && daftar[i].tipe == "Series") {
            cout << daftar[i].id << "\t" << daftar[i].judul << "\t\t\t" 
                 << daftar[i].eps_ditonton << "/" << daftar[i].total_eps << "\t\t" << daftar[i].status << endl;
            ada_series = true;
        }
    }
    if(!ada_series) cout << "(Kosong)\n";
}

// menu 3
void update_progress(Tontonan* daftar, int jumlah_data, string current_user) {
    cout << "\nUpdate Apa? (1. Movie, 2. Series, 0. Batal): ";
    int up; cin >> up;
    
    if (cin.fail() || up < 0 || up > 2) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[Error] Pilihan tidak valid. Dibatalkan.\n";
        return;
    }
    if (up == 0) return;
    
    string tipe_cari = (up == 1) ? "Movie" : "Series";
    
    cout << "\n--- Daftar " << tipe_cari << " Anda ---";
    cout << "\nID\tJudul\n";
    for (int i = 0; i < jumlah_data; i++) {
        if (daftar[i].owner_ptr->username == current_user && daftar[i].tipe == tipe_cari) {
            cout << daftar[i].id << "\t" << daftar[i].judul << endl;
        }
    }

    cout << "\nMasukkan ID (0 Batal): "; int idC; cin >> idC;
    if (cin.fail()) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "[Error] ID harus angka!\n"; 
        return; 
    }
    if (idC == 0) return;

    int indeks = cari_id(daftar, jumlah_data, idC, current_user, tipe_cari);
    
    if (indeks != -1) {
        if (tipe_cari == "Movie") {
            daftar[indeks].eps_ditonton = 1; daftar[indeks].status = "Selesai";
            cout << "Berhasil diupdate menjadi Selesai!\n";
        } else {
            cout << "Episode terakhir ditonton: "; int eb; cin >> eb;
            if (cin.fail() || eb < 0 || eb > daftar[indeks].total_eps) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[Error] Input episode tidak valid. Dibatalkan.\n";
            } else {
                daftar[indeks].eps_ditonton = eb;
                
                if (eb == daftar[indeks].total_eps) {
                    daftar[indeks].status = "Selesai";
                } else {
                    daftar[indeks].status = "Sedang Ditonton";
                }
                
                cout << "Berhasil diupdate!\n";
            }
        }
    } else {
        cout << "[Error] ID tidak ditemukan.\n";
    }
}

// menu 4
void hapus_tontonan(Tontonan* daftar, int* jumlah_data, string current_user) {
    cout << "\nTipe yang dihapus (1. Movie, 2. Series, 0. Batal): "; int th; cin >> th;
    if (cin.fail() || th < 0 || th > 2) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "[Error] Pilihan tidak valid.\n"; 
        return;
    }
    if (th == 0) return;
    
    string tipe_hapus = (th == 1) ? "Movie" : "Series";
    
    cout << "\n--- Daftar " << tipe_hapus << " Anda ---";
    cout << "\nID\tJudul\n";
    bool ada_data = false;
    for (int i = 0; i < *jumlah_data; i++) {
        if (daftar[i].owner_ptr->username == current_user && daftar[i].tipe == tipe_hapus) {
            cout << daftar[i].id << "\t" << daftar[i].judul << endl;
            ada_data = true;
        }
    }

    if (!ada_data) {
        cout << "(Tidak ada data untuk dihapus)\n";
        return;
    }

    cout << "\nMasukkan ID yang ingin dihapus (0 Batal): "; int idH; cin >> idH;
    if (cin.fail()) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "[Error] ID harus angka!\n"; 
        return; 
    }
    if (idH == 0) return;

    int indeks_hapus = cari_id(daftar, *jumlah_data, idH, current_user, tipe_hapus);

    if (indeks_hapus != -1) {
        char yakin;
        cout << "Yakin ingin menghapus '" << daftar[indeks_hapus].judul << "'? (y/n): "; 
        cin >> yakin;
        
        if (yakin == 'y' || yakin == 'Y') {
            for (int j = indeks_hapus; j < *jumlah_data - 1; j++) {
                daftar[j] = daftar[j + 1];
            }
            (*jumlah_data)--; 
            cout << "Data berhasil dihapus!\n";
        } else {
            cout << "Penghapusan dibatalkan.\n";
        }
    } else {
        cout << "[Error] ID tidak ditemukan.\n";
    }
}


int main() {
    Tontonan daftar[100];
    int jumlah_data = 0;
    User daftar_user[10]; 
    int jumlah_user = 0;
    int jumlah_percobaan = 0;
    bool program_berjalan = true;

    while (program_berjalan) {
        string user_in, pass_in;
        bool login_berhasil = false;
        int index_userlogin = -1;

        cetak_garis();
        cout << "\n   SELAMAT DATANG DI MOVIE-TRACK   ";
        cetak_garis();
        cout << "\n(Ketik 'register' untuk buat akun)";
        cout << "\nUsername: "; cin >> user_in;

        if (user_in == "register") {
            registrasi_akun(daftar_user, &jumlah_user);
            continue; 
        } else {
            cout << "Password: "; cin >> pass_in;
            
            proses_login(daftar_user, jumlah_user, user_in, pass_in, &login_berhasil, &index_userlogin, &jumlah_percobaan, &program_berjalan);
            
            if (!login_berhasil) {
                continue; 
            }
        }

        if (login_berhasil) {
            int pilihan;
            string current_user = daftar_user[index_userlogin].username;
            string judul_menu = "MENU UTAMA (User: " + current_user + ")";
            
            do {
                cetak_garis(judul_menu);
                cout << "\n1. Tambah Tontonan";
                cout << "\n2. Lihat Daftar (Terpisah)";
                cout << "\n3. Update Progress";
                cout << "\n4. Hapus Data";
                cout << "\n5. LOGOUT";
                cout << "\n6. KELUAR PROGRAM";
                cout << "\nPilih menu: "; cin >> pilihan;

                if (cin.fail()) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "\n[Error] Input harus berupa angka!\n";
                    continue; 
                }

                if (pilihan == 1) {
                    tambah_tontonan(daftar, &jumlah_data, &daftar_user[index_userlogin]);
                }
                else if (pilihan == 2) {
                    lihat_daftar(daftar, jumlah_data, current_user);
                }
                else if (pilihan == 3) {
                    update_progress(daftar, jumlah_data, current_user);
                }
                else if (pilihan == 4) {
                    hapus_tontonan(daftar, &jumlah_data, current_user);
                }
                else if (pilihan == 5) {
                    char yakin; cout << "Yakin Logout? (y/n): "; cin >> yakin;
                    if (yakin != 'y' && yakin != 'Y') pilihan = 0;
                }
                else if (pilihan == 6) {
                    char yakin; cout << "Yakin Keluar Program? (y/n): "; cin >> yakin;
                    if (yakin == 'y' || yakin == 'Y') program_berjalan = false;
                    else pilihan = 0;
                }
                else {
                    cout << "[Error] Pilihan menu tidak tersedia!\n";
                }
            } while (pilihan != 5 && pilihan != 6);
        }
    }
    return 0;
}