#include <iostream>
#include <iomanip> // untuk format output
#include <string> // untuk manipulasi string
#include <ctime> // untuk mendapatkan waktu dan tanggal saat ini
using namespace std;

// struct untuk menyimpan data password
struct data_password {
    string website;
    string username;
    string password;
    string kategori;
    string email;
    string strength;
    string waktu;
};

// struct untuk menyimpan data pengguna
struct user {
    string nama;
    string nim;
    data_password daftar_pass[100]; // maksimal 100 password per user
    int jumlah_pass;
};

// array untuk menyimpan semua pengguna
user users[100]; // maksimal 100 pengguna
int jumlah_user = 1; // user default

// program utama
int main() {
    // user default
    users[0].nama = "Azira"; // username valid
    users[0].nim = "2409106016"; // password valid
    users[0].jumlah_pass = 0;

    int login_attempts = 0;
    char repeat;
    string input_nama, input_nim;
    int current_user = -1;

    do {
        // menu login & regis
        cout << "\n======================" << endl;
        cout << "|     Menu Login     |" << endl;
        cout << "======================" << endl;
        cout << "|    1. Login        |" << endl;
        cout << "|    2. Registrasi   |" << endl;
        cout << "|    3. Keluar       |" << endl;
        cout << "======================" << endl;
        cout << "Pilih opsi (1-3): ";
        int pilih;
        cin >> pilih;
        cin.ignore();

        // login
        if (pilih == 1) {
            while (login_attempts < 3) {
                cout << "\n=== Login ===\n";
                cout << "Masukkan Nama anda: ";
                getline(cin, input_nama);
                cout << "Masukkan NIM anda: ";
                getline(cin, input_nim);

                // mengecek apakah user sudah terdaftar
                bool found = false;
                for (int i = 0; i < jumlah_user; i++) {
                    if (users[i].nama == input_nama && users[i].nim == input_nim) {
                        current_user = i;
                        found = true;
                        break;
                    }
                }

                if (found) {
                    cout << "Login berhasil! Selamat datang, " << users[current_user].nama << "!\n";
                    login_attempts = 0; // reset percobaan login
                    break;
                } else {
                    cout << "Nama atau NIM anda salah. Silahkan coba lagi!" << endl;
                    login_attempts++;
                }
            }

            if (login_attempts == 3) {
                cout << "Terlalu banyak percobaan login. Program berhenti." << endl;
                break;
            }

            // menu utama
            while (true) {
                cout << "\n=================================" << endl;
                cout << "|   Sistem Manajemen Password   |" << endl;
                cout << "=================================" << endl;
                cout << "|      1. Tambah Password       |" << endl;
                cout << "|      2. Lihat Password        |" << endl;
                cout << "|      3. Update Password       |" << endl;
                cout << "|      4. Hapus Password        |" << endl;
                cout << "|      5. Logout                |" << endl;
                cout << "=================================" << endl;
                cout << "Pilih opsi: ";
                int choice;
                cin >> choice;
                cin.ignore();

                // tambah password
                if (choice == 1) {
                    if (users[current_user].jumlah_pass < 100) {
                        data_password &pass = users[current_user].daftar_pass[users[current_user].jumlah_pass];

                        cout << "\n=== Tambah Password ===\n";
                        cout << "Masukkan nama website/platform: ";
                        getline(cin, pass.website);
                        cout << "Masukkan username: ";
                        getline(cin, pass.username);
                        cout << "Masukkan password: ";
                        getline(cin, pass.password);
                        cout << "Masukkan kategori (sosmed, bank, dll): ";
                        getline(cin, pass.kategori);
                        cout << "Masukkan email yang terhubung: ";
                        getline(cin, pass.email);

                        // mengecek kekuatan password
                        int length = pass.password.length();
                        if (length < 6)
                            pass.strength = "Lemah";
                        else if (length < 10)
                            pass.strength = "Sedang";
                        else
                            pass.strength = "Kuat";

                        // mendapatkan waktu real time
                        time_t now = time(0);
                        pass.waktu = ctime(&now);

                        users[current_user].jumlah_pass++;
                        cout << "Password berhasil ditambahkan!\n";
                    } else {
                        cout << "Penyimpanan penuh!\n";
                    }

                // lihat password
                } else if (choice == 2) {
                    if (users[current_user].jumlah_pass == 0) {
                        cout << "Belum ada password yang tersimpan :(." << endl;
                    } else {
                        cout << "\n=== Daftar Password ===\n";
                        cout << left << setw(5) << "No" << setw(20) << "Website" << setw(20) << "Username"
                             << setw(20) << "Password" << setw(15) << "Kategori" << setw(30) << "Email"
                             << setw(12) << "Kekuatan" << "Waktu Dibuat\n";
                        cout << "------------------------------------------------------------------------------------------------------------------------------------------------\n";
                        for (int i = 0; i < users[current_user].jumlah_pass; i++) {
                            data_password &pass = users[current_user].daftar_pass[i];
                            cout << left << setw(5) << i + 1 << setw(20) << pass.website << setw(20) << pass.username
                                 << setw(20) << pass.password << setw(15) << pass.kategori << setw(30) << pass.email
                                 << setw(12) << pass.strength << pass.waktu;
                        }
                    }

                // update password
                } else if (choice == 3) {
                    if (users[current_user].jumlah_pass == 0) {
                        cout << "Belum ada password yang tersimpan :(." << endl;
                    } else {
                        cout << "\n=== Daftar Password ===\n";
                        cout << left << setw(5) << "No" << setw(20) << "Website" << setw(20) << "Username"
                             << setw(20) << "Password" << setw(15) << "Kategori" << setw(30) << "Email"
                             << setw(12) << "Kekuatan" << "Waktu Dibuat\n";
                        cout << "------------------------------------------------------------------------------------------------------------------------------------------------\n";
                        for (int i = 0; i < users[current_user].jumlah_pass; i++) {
                            data_password &pass = users[current_user].daftar_pass[i];
                            cout << left << setw(5) << i + 1 << setw(20) << pass.website << setw(20) << pass.username
                                 << setw(20) << pass.password << setw(15) << pass.kategori << setw(30) << pass.email
                                 << setw(12) << pass.strength << pass.waktu;
                        }
                        int index;
                        cout << "Masukkan nomor password yang ingin diupdate: ";
                        cin >> index;
                        cin.ignore();
                        if (index > 0 && index <= users[current_user].jumlah_pass) {
                            data_password &pass = users[current_user].daftar_pass[index - 1];

                            cout << "Masukkan website baru: ";
                            getline(cin, pass.website);
                            cout << "Masukkan username baru: ";
                            getline(cin, pass.username);
                            cout << "Masukkan password baru: ";
                            getline(cin, pass.password);

                            cout << "Masukkan kategori baru: ";
                            getline(cin, pass.kategori);

                            cout << "Masukkan email baru: ";
                            getline(cin, pass.email);

                            // update kekuatan password
                            int length = pass.password.length();
                            pass.strength = (length < 6) ? "Lemah" : (length < 10) ? "Sedang" : "Kuat";

                            time_t now = time(0);
                            pass.waktu = ctime(&now);
                            cout << "Password berhasil diperbarui!" << endl;
                        } else {
                            cout << "Nomor tidak valid, coba lagi." << endl;
                        }
                    }

                // hapus password
                } else if (choice == 4) {
                    if (users[current_user].jumlah_pass == 0) {
                        cout << "Belum ada password yang tersimpan :(." << endl;
                    } else {
                        cout << "\n=== Daftar Password ===\n";
                        cout << left << setw(5) << "No" << setw(20) << "Website" << setw(20) << "Username"
                             << setw(20) << "Password" << setw(15) << "Kategori" << setw(30) << "Email"
                             << setw(12) << "Kekuatan" << "Waktu Dibuat\n";
                        cout << "------------------------------------------------------------------------------------------------------------------------------------------------\n";
                        for (int i = 0; i < users[current_user].jumlah_pass; i++) {
                            data_password &pass = users[current_user].daftar_pass[i];
                            cout << left << setw(5) << i + 1 << setw(20) << pass.website << setw(20) << pass.username
                                 << setw(20) << pass.password << setw(15) << pass.kategori << setw(30) << pass.email
                                 << setw(12) << pass.strength << pass.waktu;
                        }
                        int index;
                        cout << "Masukkan nomor password yang ingin dihapus: ";
                        cin >> index;
                        cin.ignore();
                        if (index > 0 && index <= users[current_user].jumlah_pass) {
                            for (int i = index - 1; i < users[current_user].jumlah_pass - 1; i++) {
                                users[current_user].daftar_pass[i] = users[current_user].daftar_pass[i + 1];
                            }
                            users[current_user].jumlah_pass--;
                            cout << "Password berhasil dihapus!" << endl;
                        } else {
                            cout << "Nomor tidak valid, coba lagi." << endl;
                        }
                    }

                // logout
                } else if (choice == 5) {
                    cout << "Logout berhasil!" << endl;
                    current_user = -1;
                    break;
                } else {
                    cout << "Pilihan anda tidak valid, coba lagi!" << endl;
                }
            }

        // registrasi user baru
        } else if (pilih == 2) {
            cout << "\n=== Register ===\n";
            cout << "Masukkan Nama: ";
            getline(cin, users[jumlah_user].nama);
            cout << "Masukkan NIM: ";
            getline(cin, users[jumlah_user].nim);
            users[jumlah_user].jumlah_pass = 0;
            jumlah_user++;
            cout << "Registrasi berhasil! Silahkan Login." << endl;
        
        // keluar dari program
        } else if (pilih == 3) {
            cout << "Apakah anda masih ingin menggunakan program? (y/n): ";
            cin >> repeat;
            if (repeat == 'n' || repeat == 'N') {
                cout << "Terima kasih!" << endl;
                break;
            }

        } else {
            cout << "Pilihan anda tidak valid! Silahkan coba lagi." << endl;
        }

    }
    while (true);
    return 0;
}