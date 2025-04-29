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
    int password_length;
    string waktu;
};

// struct untuk menyimpan data pengguna
struct user {
    string nama;
    string nim;
    data_password daftar_pass[100];
    int jumlah_pass;
};

user users[100];
int jumlah_user = 1;

// deklarasi fungsi
void menu_login();
int login(user users[], int jumlah_user);
void regis();
void main_menu(user* u);
void tambah_pass(user &);
void show_pass_header();
void show_pass_data(int, const data_password*);
int lihat_pass(const user &, int[]);
void update_pass(user &);
void hapus_pass(user &);

// Bubble Sort untuk sort website (Descending Z-A)
void bubble_sort(data_password arr[], int mapping[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j].website < arr[j+1].website) {
                swap(arr[j], arr[j+1]);
                swap(mapping[j], mapping[j+1]);
            }
        }
    }
}

// Selection Sort untuk sort panjang password (Ascending 1-9)
void selection_sort(data_password arr[], int mapping[], int n) {
    for (int i = 0; i < n-1; ++i) {
        int min_idx = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j].password_length < arr[min_idx].password_length) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
        swap(mapping[i], mapping[min_idx]);
    }
}

// Insertion Sort untuk sort username (Ascending A-Z)
void insertion_sort(data_password arr[], int mapping[], int n) {
    for (int i = 1; i < n; i++) {
        data_password key = arr[i];
        int key_idx = mapping[i];
        int j = i - 1;
        while (j >= 0 && arr[j].username > key.username) {
            arr[j + 1] = arr[j];
            mapping[j + 1] = mapping[j];
            j--;
        }
        arr[j + 1] = key;
        mapping[j + 1] = key_idx;
    }
}

// fungsi login
int login(user* users, int jumlah_user) {
    string nama, nim;
    int attempts = 0;
    while (attempts < 3) {
        cout << "\n=== Login ===" << endl;
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        for (int i = 0; i < jumlah_user; ++i) {
            if (users[i].nama == nama && users[i].nim == nim) {
                cout << "Login berhasil! Selamat datang, " << nama << "!" << endl;
                return i;
            }
        }
        cout << "Nama atau NIM salah. Coba lagi." << endl;
        attempts++;
    }
    cout << "Terlalu banyak percobaan. Program berhenti." << endl;
    exit(0);
}

// fungsi registrasi
void regis() {
    cout << "\n=== Registrasi ===" << endl;
    cout << "Masukkan Nama: ";
    getline(cin, users[jumlah_user].nama);
    cout << "Masukkan NIM: ";
    getline(cin, users[jumlah_user].nim);

    user* pUser = &users[jumlah_user];
    pUser->jumlah_pass = 0;

    jumlah_user++;
    cout << "Registrasi berhasil! Silakan login kembali." << endl;
}

// menu login
void menu_login() {
    while (true) {
        cout << "\n======================" << endl;
        cout << "|     Menu Login     |" << endl;
        cout << "======================" << endl;
        cout << "|    1. Login        |" << endl;
        cout << "|    2. Registrasi   |" << endl;
        cout << "|    3. Keluar       |" << endl;
        cout << "======================" << endl;
        cout << "Pilih opsi (1-3): ";
        int menu;
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            int idx = login(users, jumlah_user);
            main_menu(&users[idx]);
        } else if (menu == 2) {
            regis();
        } else if (menu == 3) {
            char keluar;
            cout << "Apakah Anda ingin keluar? (y/n): ";
            cin >> keluar;
            if (keluar == 'y' || keluar == 'Y') {
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                break;
            }
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }
}

// menu utama
void main_menu(user* u) {
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
        int pilih;
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case 1: tambah_pass(*u); break;
            case 2: { int dummy[100]; lihat_pass(*u, dummy); } break;
            case 3: update_pass(*u); break;
            case 4: hapus_pass(*u); break;
            case 5: cout << "Logout berhasil!" << endl; return;
            default: cout << "Pilihan tidak valid." << endl;
        }
    }
}

// fungsi tambah password
void tambah_pass(user &u) {
    if (u.jumlah_pass >= 100) {
        cout << "Penyimpanan penuh!" << endl;
        return;
    }
    data_password* p = &u.daftar_pass[u.jumlah_pass];

    cout << "\n=== Tambah Password ===" << endl;
    cout << "Website/Platform: "; getline(cin, p->website);
    cout << "Username: "; getline(cin, p->username);
    cout << "Password: "; getline(cin, p->password);
    cout << "Kategori (sosmed, bank, dll): "; getline(cin, p->kategori);
    cout << "Email yang terhubung: "; getline(cin, p->email);

    p->password_length = p->password.length();
    time_t now = time(0);
    p->waktu = ctime(&now);

    u.jumlah_pass++;
    cout << "Password berhasil ditambahkan!" << endl;
}

// fungsi tampilkan header data
void show_pass_header() {
    cout << left << setw(5) << "No"
         << setw(20) << "Website"
         << setw(15) << "Username"
         << setw(20) << "Password"
         << setw(15) << "Kategori"
         << setw(30) << "Email"
         << setw(10) << "Panjang"
         << setw(25) << "Waktu" << endl;
    cout << string(150, '-') << endl;
}

// fungsi tampilkan data
void show_pass_data(int indeks, const data_password* p) {
    cout << left << setw(5) << indeks
         << setw(20) << p->website
         << setw(15) << p->username
         << setw(20) << p->password
         << setw(15) << p->kategori
         << setw(30) << p->email
         << setw(10) << p->password_length
         << setw(25) << p->waktu;
}

// fungsi lihat password
int lihat_pass(const user &u, int mapping[]) {
    if (u.jumlah_pass == 0) {
        cout << "Belum ada password tersimpan :(." << endl;
        return 0;
    }

    int pilihan_sort;
    cout << "\n===============================" << endl;
    cout << "|         Menu Sorting        |" << endl;
    cout << "===============================" << endl;
    cout << "|   1. Sort Website (Z - A)   |" << endl;
    cout << "|   2. Sort Panjang Password  |" << endl;
    cout << "|   3. Sort Username (A - Z)  |" << endl;
    cout << "===============================" << endl;
    cout << "Pilih opsi (1-3): ";
    cin >> pilihan_sort;
    cin.ignore();

    data_password temp[100];
    for (int i = 0; i < u.jumlah_pass; i++) {
        temp[i] = u.daftar_pass[i];
        mapping[i] = i; // mapping awal
    }

    if (pilihan_sort == 1) {
        bubble_sort(temp, mapping, u.jumlah_pass);
    } else if (pilihan_sort == 2) {
        selection_sort(temp, mapping, u.jumlah_pass);
    } else if (pilihan_sort == 3) {
        insertion_sort(temp, mapping, u.jumlah_pass);
    } else {
        cout << "Pilihan tidak valid." << endl;
        return 0;
    }

    show_pass_header();
    for (int i = 0; i < u.jumlah_pass; ++i) {
        show_pass_data(i + 1, &temp[i]);
    }
    return u.jumlah_pass;
}

// fungsi update password
void update_pass(user &u) {
    int mapping[100];
    int n = lihat_pass(u, mapping);
    if (n == 0) return;

    int idx;
    cout << "\nPilih nomor password untuk diupdate: ";
    cin >> idx;
    cin.ignore();

    if (idx < 1 || idx > n) {
        cout << "Nomor tidak valid." << endl;
        return;
    }

    data_password* p = &u.daftar_pass[mapping[idx - 1]];
    cout << "Website/Platform baru: "; getline(cin, p->website);
    cout << "Username baru: "; getline(cin, p->username);
    cout << "Password baru: "; getline(cin, p->password);
    cout << "Kategori baru: "; getline(cin, p->kategori);
    cout << "Email baru: "; getline(cin, p->email);

    p->password_length = p->password.length();
    time_t now = time(0);
    p->waktu = ctime(&now);

    cout << "Password berhasil diperbarui!" << endl;
}

// fungsi hapus password
void hapus_pass(user &u) {
    int mapping[100];
    int n = lihat_pass(u, mapping);
    if (n == 0) return;

    int idx;
    cout << "\nPilih nomor password untuk dihapus: ";
    cin >> idx;
    cin.ignore();

    if (idx < 1 || idx > n) {
        cout << "Nomor tidak valid." << endl;
        return;
    }

    int asli = mapping[idx - 1];
    for (int i = asli; i < u.jumlah_pass - 1; ++i) {
        u.daftar_pass[i] = u.daftar_pass[i + 1];
    }
    u.jumlah_pass--;

    cout << "Password berhasil dihapus!" << endl;
}

// program utama
int main() {
    users[0].nama = "Azira";
    users[0].nim = "2409106016";
    users[0].jumlah_pass = 0;

    menu_login();
    return 0;
}