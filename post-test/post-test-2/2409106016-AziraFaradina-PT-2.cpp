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
    string passwords[100][4]; // data [website, username, password, waktu]
    int password_count = 0;
    int login_attempts = 0;
    char repeat;

    do {
        while (login_attempts < 3) {
            cout << "\n=== Sistem Login ===\n";
            cout << "Masukkan Username anda: ";
            cin >> username;
            cout << "Masukkan Password anda: ";
            cin >> password;

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
                            cout << left << setw(5) << "No" << setw(20) << "Website" << setw(20) << "Username" << setw(20) << "Password" << "Waktu Dibuat" << endl;
                            cout << "---------------------------------------------------------------------------------------------" << endl;
                            for (int i = 0; i < password_count; i++) {
                                cout << left << setw(5) << i + 1 << setw(20) << passwords[i][0] << setw(20) << passwords[i][1] << setw(20) << passwords[i][2] << passwords[i][3];
                            }
                        }

                    // update password
                    } else if (pilihan == 3) {
                        if (password_count == 0) {
                            cout << "Belum ada password yang tersimpan :(.)" << endl;
                        } else {
                            cout << "\n=== Daftar Password ===" << endl;
                            cout << left << setw(5) << "No" << setw(20) << "Website" << setw(20) << "Username" << setw(20) << "Password" << "Waktu Dibuat" << endl;
                            cout << "---------------------------------------------------------------------------------------------" << endl;
                            for (int i = 0; i < password_count; i++) {
                                cout << left << setw(5) << i + 1 << setw(20) << passwords[i][0] << setw(20) << passwords[i][1] << setw(20) << passwords[i][2] << passwords[i][3];
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
                            cout << left << setw(5) << "No" << setw(20) << "Website" << setw(20) << "Username" << setw(20) << "Password" << "Waktu Dibuat" << endl;
                            cout << "---------------------------------------------------------------------------------------------" << endl;
                            for (int i = 0; i < password_count; i++) {
                                cout << left << setw(5) << i + 1 << setw(20) << passwords[i][0] << setw(20) << passwords[i][1] << setw(20) << passwords[i][2] << passwords[i][3];
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
                cout << "Username atau password salah!" << endl;
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
