#include <iostream>
#include <iomanip> // untuk format output 
#include <string> // untuk manipulasi string
#include <ctime> // untuk mendapatkan waktu dan tanggal saat ini
using namespace std;

// program utama
int main() {
    string username, password;
    string stored_user = "Azira"; // username valid
    string stored_pass = "2409106016"; // password valid

    // array multidimesi
    string passwords[100][4]; // data [website, username, password, waktu]

    // array satu dimensi
    string categories[100]; // kategori akun seperti sosial media, email, dll
    string emails[100]; // alamat email yang terhubung
    string password_strength[100]; // mengecek tingkat kekuatan password

    int password_count = 0;
    int login_attempts = 0;
    char repeat;

    do {
        // menu login
        while (login_attempts < 3) {
            cout << "\n=== Sistem Login ===\n";
            cout << "Masukkan Username anda: ";
            cin >> username;
            cout << "Masukkan Password anda: ";
            cin >> password;

            // menu utama
            if (username == stored_user && password == stored_pass) {
                cout << "Login berhasil! Selamat datang " << username << endl;
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
                    int pilihan;
                    cin >> pilihan;
                    cin.ignore();

                    // tambah password
                    if (pilihan == 1) { 
                        if (password_count < 100) {
                            cout << "\n=== Tambah Password ===" << endl;
                            cout << "Masukkan nama website/platform: ";
                            getline(cin, passwords[password_count][0]);
                            cout << "Masukkan username: ";
                            getline(cin, passwords[password_count][1]);
                            cout << "Masukkan password: ";
                            getline(cin, passwords[password_count][2]);

                            cout << "Masukkan kategori (misal: sosmed, perbankan, ecommerce, dll): ";
                            getline(cin, categories[password_count]);

                            cout << "Masukkan alamat email yang terhubung: ";
                            getline(cin, emails[password_count]);

                            // menentukan kekuatan password
                            int length = passwords[password_count][2].length();
                            if (length < 6) {
                                password_strength[password_count] = "Lemah";
                            } else if (length < 10) {
                                password_strength[password_count] = "Sedang";
                            } else {
                                password_strength[password_count] = "Kuat";
                            }

                            // mendapatkan waktu dan tanggal saat menyimpan input
                            time_t now = time(0);
                            passwords[password_count][3] = ctime(&now);
                            password_count++;
                            cout << "Password berhasil ditambahkan!" << endl;
                        } else {
                            cout << "Penyimpanan penuh!" << endl;
                        }

                    // lihat passowrd
                    } else if (pilihan == 2) {
                        if (password_count == 0) {
                            cout << "Belum ada password yang tersimpan :(.)" << endl;
                        } else {
                            cout << "\n=== Daftar Password ===" << endl;
                            cout << left << setw(5) << "No" << setw(20) << "Website" << setw(20) << "Username" << setw(20) << "Password" << setw(15) << "Kategori" << setw(30) << "Email" << setw(12) << "Kekuatan" << "Waktu Dibuat" << endl;
                            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                            for (int i = 0; i < password_count; i++) {
                                cout << left << setw(5) << i + 1 << setw(20) << passwords[i][0] << setw(20) << passwords[i][1] << setw(20) << passwords[i][2] << setw(15) << categories[i] << setw(30) << emails[i] << setw(12) << password_strength[i] << passwords[i][3];
                            }
                        }

                    // update password
                    } else if (pilihan == 3) {
                        if (password_count == 0) {
                            cout << "Belum ada password yang tersimpan :(.)" << endl;
                        } else {
                            cout << "\n=== Daftar Password ===" << endl;
                            cout << left << setw(5) << "No" << setw(20) << "Website" << setw(20) << "Username" << setw(20) << "Password" << setw(15) << "Kategori" << setw(30) << "Email" << setw(12) << "Kekuatan" << "Waktu Dibuat" << endl;
                            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                            for (int i = 0; i < password_count; i++) {
                                cout << left << setw(5) << i + 1 << setw(20) << passwords[i][0] << setw(20) << passwords[i][1] << setw(20) << passwords[i][2] << setw(15) << categories[i] << setw(30) << emails[i] << setw(12) << password_strength[i] << passwords[i][3];
                            }
                            int index;
                            cout << "\n=== Update Password ===" << endl;
                            cout << "Masukkan nomor password yang ingin diupdate: ";
                            cin >> index;
                            cin.ignore();
                            if (index > 0 && index <= password_count) {
                                cout << "Masukkan website baru: ";
                                getline(cin, passwords[index - 1][0]);
                                cout << "Masukkan username baru: ";
                                getline(cin, passwords[index - 1][1]);
                                cout << "Masukkan password baru: ";
                                getline(cin, passwords[index - 1][2]);

                                cout << "Masukkan kategori baru: ";
                                getline(cin, categories[index - 1]);

                                cout << "Masukkan email baru: ";
                                getline(cin, emails[index - 1]);

                                int length = passwords[index - 1][2].length();
                                if (length < 6) {
                                    password_strength[index - 1] = "Lemah";
                                } else if (length < 10) {
                                    password_strength[index - 1] = "Sedang";
                                } else {
                                    password_strength[index - 1] = "Kuat";
                                }

                                time_t now = time(0);
                                passwords[index - 1][3] = ctime(&now);
                                cout << "Password berhasil diperbarui!" << endl;
                            } else {
                                cout << "Nomor yang diinput tidak valid, coba lagi." << endl;
                            }
                        }

                    // hapus password
                    } else if (pilihan == 4) {
                        if (password_count == 0) {
                            cout << "Belum ada password yang tersimpan :(.)." << endl;
                        } else {
                            cout << "\n=== Daftar Password ===" << endl;
                            cout << left << setw(5) << "No" << setw(20) << "Website" << setw(20) << "Username" << setw(20) << "Password" << setw(15) << "Kategori" << setw(30) << "Email" << setw(12) << "Kekuatan" << "Waktu Dibuat" << endl;
                            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                            for (int i = 0; i < password_count; i++) {
                                cout << left << setw(5) << i + 1 << setw(20) << passwords[i][0] << setw(20) << passwords[i][1] << setw(20) << passwords[i][2] << setw(15) << categories[i] << setw(30) << emails[i] << setw(12) << password_strength[i] << passwords[i][3];
                            }
                            int index;
                            cout << "\n=== Hapus Password ===" << endl;
                            cout << "Masukkan nomor password yang ingin dihapus: ";
                            cin >> index;
                            cin.ignore();
                            if (index > 0 && index <= password_count) {
                                for (int i = index - 1; i < password_count - 1; i++) {
                                    for (int j = 0; j < 4; j++) {
                                        passwords[i][j] = passwords[i + 1][j];
                                    }
                                }
                                password_count--;
                                cout << "Password berhasil dihapus!" << endl;
                            } else {
                                cout << "Nomor yang diinput tidak valid, coba lagi." << endl;
                            }
                        }

                    // keluar dari menu
                    } else if (pilihan == 5) {
                        cout << "Logout berhasil!" << endl;
                        break;
                    } else {
                        cout << "Pilihan anda tidak valid, coba lagi." << endl;
                    }
                }
                break;
            } else {
                cout << "Username atau password anda salah. Coba lagi!" << endl;
                login_attempts++;
            }
        }
        if (login_attempts == 3) {
            cout << "Kesempatan login habis. Program berhenti." << endl;
            break;
        }
    
        cout << "Apakah anda masih ingin menggunakan program? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');
    cout << "Terima kasih telah menggunakan program ini!" << endl;

    return 0;
}