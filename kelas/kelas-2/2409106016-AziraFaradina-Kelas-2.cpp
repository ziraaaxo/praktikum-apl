#include <iostream>
using namespace std;

int main() {
    struct mahasiswa{
        string nama;
        int umur;
        string jurusan;
    };
    
    mahasiswa mhs;
    mhs.nama = "Azira";
    mhs.umur = 18;
    mhs.jurusan = "Informatika";

    cout << "Nama: " << mhs.nama << endl;
    cout << "Umur: " << mhs.umur << endl;
    cout << "Jurusan: " << mhs.jurusan << endl;
}

int main() {
    struct tanggal {
        int month;
        int day;
        int year;
    };
    struct mahasiswa{
        string name;
        struct tanggal lahir;
    };

    // deklarasi global dari variabel mahasiswa
    struct mahasiswa mhs[10];

    mhs[0].name = "Nuno";
    mhs[0].lahir.day = 28;
    mhs[0].lahir.month = 3;
    mhs[0].lahir.year = 2006;  
}

// studi kasus 1
int main() {
    struct mahasiswa{
        int nim;
        string nama;
        float nilai;
    };

    mahasiswa mhs;
    mhs.nim = 2409106016;
    mhs.nama = "Azira Faradina";
    mhs.nilai = 99,9;

    cout << "NIM: " << mhs.nim << endl;
    cout << "Nama: " << mhs.nama << endl;
    cout << "Nilai Akhir: " << mhs.nilai << endl;
}

int main() {
    int pilihan, index;
    do {
        system("clear");
        cout << "Menu Program" << endl;
        cout << "1. Tampilkan Buku" << endl;
        cout << "2. Tambah Buku" << endl;
        cout << "3. Ubah Buku" << endl;
        cout << "4. Hapus Buku" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        int panjang = 0;
        switch (pilihan) {
        case 1:
        // Tampilkan Buku
        if (panjang == 0) {
            cout << "Belum ada buku yang tersimpan" << endl;
        } else {
            cout << "=== Daftar Buku ===" << endl;
            cout << "===================" << endl;
            for (int i = 0; i < panjang; i++) {
                cout << "Buku ke-" << i + 1 << endl;
                cout << "Judul Buku: " << buku[i].judul << endl;
                cout << "Status Buku: " << buku[i].status << endl;
                cout << "Tahun Terbit: " << buku[i].tahun << endl;
            }
        }
        break;
        case 2:
        // Tambah Data Mahasiswa
        break;
        case 3:
        // Ubah Data Mahasiswa
        break;
        case 4:
        // Hapus Data Mahasiswa
        break;
        case 5:
            cout << "Program selesai" << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    } while (pilihan != 5);

return 0;

}