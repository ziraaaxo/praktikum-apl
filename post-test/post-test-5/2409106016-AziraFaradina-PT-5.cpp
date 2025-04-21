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

// deklarasi fungsi dan prosedur
void menu_login();
int login(user users[], int jumlah_user);
void regis();
void main_menu(user* u);
void tambah_pass(user &);
void show_pass_header();
void show_pass_data(const user &, int);
void lihat_pass(const user &);
void update_pass(user &);
void hapus_pass(user &);
string cek_strength(string *pass); // fungsi overloading

// fitur login menggunakan fungsi dengan parameter dereference
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

// fitur registrasi
void regis() {
    cout << "\n=== Registrasi ===" << endl;
    cout << "Masukkan Nama: ";
    getline(cin, users[jumlah_user].nama);
    cout << "Masukkan NIM: ";
    getline(cin, users[jumlah_user].nim);

    user* pUser = &users[jumlah_user]; // menyimpan pointer ke user yang baru
    pUser->jumlah_pass = 0; //inisialisasi jumlah password menjadi 0

    jumlah_user++;
    cout << "Registrasi berhasil! Silakan login kembali." << endl;
}

// menu login & regis
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
                cout << "Terima kasih telah menggunakan program ini!";
                break;
            }
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }
}

// menu utama
void main_menu(user* u) { // dereference pointer
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
            case 1: tambah_pass(*u); 
                break;
            case 2: lihat_pass(*u); 
                break;
            case 3: update_pass(*u); 
                break;
            case 4: hapus_pass(*u); 
                break;
            case 5: cout << "Logout berhasil!" << endl; 
                return;
            default: cout << "Pilihan tidak valid." << endl;
        }
    }
}

// fungsi mengecek kekuatan password dengan parameter dereference
string cek_strength(string *pass) {
    int len = pass->length();
    if (len < 6) return "Lemah";
    else if (len < 10) return "Sedang";
    return "Kuat";
}

// fungsi tambah data menggunakan prinsip pointer dan menggunakan parameter address-of
void tambah_pass(user &u) {
    if (u.jumlah_pass >= 100) {
        cout << "Penyimpanan penuh!" << endl;
        return;
    }
    data_password* p = &u.daftar_pass[u.jumlah_pass]; // akses data dengan dereference

    cout << "\n=== Tambah Password ===" << endl;
    cout << "Website/Platform: "; getline(cin, p->website);
    cout << "Username: "; getline(cin, p->username);
    cout << "Password: "; getline(cin, p->password);
    cout << "Kategori (sosmed, bank, dll): "; getline(cin, p->kategori);
    cout << "Email yang terhubung: "; getline(cin, p->email);

    // mengecek kekuatan password
    p->strength = cek_strength(&p->password);
    time_t now = time(0);
    p->waktu = ctime(&now);

    u.jumlah_pass++;
    cout << "Password berhasil ditambahkan!" << endl;
}

// fungsi untuk menampilkan header data
void show_pass_header() {
    cout << left << setw(5) << "No"
         << setw(20) << "Website"
         << setw(15) << "Username"
         << setw(20) << "Password"
         << setw(15) << "Kategori"
         << setw(30) << "Email"
         << setw(10) << "Strength"
         << setw(25) << "Waktu" << endl;
    cout << string(140, '-') << endl;
}

// fungsi untuk menampilkan data password menggunakan prinsip pointer dan dengan parameter dereference
void show_pass_data(int indeks, const data_password* p) {
    cout << left << setw(5) << indeks
         << setw(20) << p->website
         << setw(15) << p->username
         << setw(20) << p->password
         << setw(15) << p->kategori
         << setw(30) << p->email
         << setw(10) << p->strength
         << setw(25) << p->waktu;
}

// fungsi tampilkan data menggunakan prinsip pointer dan menggunakan parameter address-of
void lihat_pass(const user &u) {
    if (u.jumlah_pass == 0) {
        cout << "Belum ada password tersimpan :(." << endl;
        return;
    }
    show_pass_header();
    for (int i = 0; i < u.jumlah_pass; ++i) {
        show_pass_data(i + 1, &u.daftar_pass[i]);
    }
}

// fungsi update data menggunakan prinsip pointer dan menggunakan parameter address-of
void update_pass(user &u) {
    lihat_pass(u);
    if (u.jumlah_pass == 0) 
        return;
    int idx;
    cout << "Pilih nomor password untuk diupdate: ";
    cin >> idx; cin.ignore();

    if (idx < 1 || idx > u.jumlah_pass) {
        cout << "Nomor tidak valid." << endl;
        return;
    }

    data_password* p = &u.daftar_pass[idx - 1]; // akses data dengan dereference
    cout << "Website/Platform baru: "; getline(cin, p->website);
    cout << "Username baru: "; getline(cin, p->username);
    cout << "Password baru: "; getline(cin, p->password);
    cout << "Kategori baru: "; getline(cin, p->kategori);
    cout << "Email baru: "; getline(cin, p->email);

    p->strength = cek_strength(&p->password);
    time_t now = time(0);
    p->waktu = ctime(&now);
    cout << "Password berhasil diperbarui!" << endl;
}

// fungsi hapus data menggunakan prinsip pointer dan menggunakan parameter address-of
void hapus_pass(user &u) {
    lihat_pass(u);
    if (u.jumlah_pass == 0) return;
    int idx;
    cout << "Pilih nomor password untuk dihapus: ";
    cin >> idx; cin.ignore();

    if (idx < 1 || idx > u.jumlah_pass) {
        cout << "Nomor tidak valid." << endl;
        return;
    }
    // penerapan pointer untuk memindahkan data
    for (int i = idx - 1; i < u.jumlah_pass - 1; ++i) {
        // akses data dengan dereference
        data_password* p1 = &u.daftar_pass[i]; // elemen yang akan dipindah
        data_password* p2 = &u.daftar_pass[i + 1]; //elemen yang akan menggantikan
        *p1 = *p2; // copy data dari p2 ke p1
    }
    u.jumlah_pass--;
    
    cout << "Password berhasil dihapus!" << endl;
}

// program utama
int main() {
    // user default
    users[0].nama = "Azira";
    users[0].nim = "2409106016";
    users[0].jumlah_pass = 0;

    menu_login();

    return 0;
}