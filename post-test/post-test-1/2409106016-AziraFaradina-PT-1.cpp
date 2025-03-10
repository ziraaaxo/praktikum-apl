#include <iostream>
#include <string>
using namespace std;

// menu login
bool login() {
    string name, nim;
    int attempts = 0;

    while (attempts < 3) {
        cout << "=== Menu Login ===" << endl;
        cout << "Masukkan Nama: ";
        getline(cin, name);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        // data login valid
        if (name == "Azira Faradina" && nim == "2409106016") {
            cout << "Login berhasil!" << endl;
            return true;
        } else {
            attempts++;
            cout << "Login gagal! Silahkan coba lagi." << endl;
        }
    }

    cout << "Anda terlalu banyak melakukan percobaan. Program berhenti." << endl;
    return false;
}

// menampilkan menu utama
void show_menu() {
    cout << "==========================================" << endl;
    cout << "|         Menu Konversi Sederhana        |" << endl;
    cout << "==========================================" << endl;
    cout << "|  1. Meter ke (Centimeter, Mile, Foot)  |" << endl;
    cout << "|  2. Centimeter ke (Meter, Mile, Foot)  |" << endl;
    cout << "|  3. Mile ke (Meter, Centimeter, Foot)  |" << endl;
    cout << "|  4. Foot ke (Meter, Centimeter, Mile)  |" << endl;
    cout << "|  5. Keluar                             |" << endl;
    cout << "==========================================" << endl;
}

// konversi satuan Meter
void convert_meter(double meter) {
    cout << meter << " meter = " << meter * 100 << " centimeter" << endl;
    cout << meter << " meter = " << meter * 0.000621371 << " mile" << endl;
    cout << meter << " meter = " << meter * 3.28084 << " foot" << endl;
}

// konversi satuan Centimeter
void convert_centimeter(double centimeter) {
    cout << centimeter << " centimeter = " << centimeter / 100 << " meter" << endl;
    cout << centimeter << " centimeter = " << centimeter * 0.00000621371 << " mile" << endl;
    cout << centimeter << " centimeter = " << centimeter * 0.0328084 << " foot" << endl;
}

// konversi satuan Mile
void convert_mile(double mile) {
    cout << mile << " mile = " << mile * 1609.34 << " meter" << endl;
    cout << mile << " mile = " << mile * 160934 << " centimeter" << endl;
    cout << mile << " mile = " << mile * 5280 << " foot" << endl;
}

// konversi satuan Foot
void convert_foot(double foot) {
    cout << foot << " foot = " << foot * 0.3048 << " meter" << endl;
    cout << foot << " foot = " << foot * 30.48 << " centimeter" << endl;
    cout << foot << " foot = " << foot * 0.000189394 << " mile" << endl;
}

int main() {
    // memeriksa fungsi login
    if (!login()) {
        return 0; // keluar dari program jika login gagal
    }

    // program utama
    char choice;
    char repeat_program;
    do {
        do {
            show_menu();
            cout << "Masukkan pilihan (1-5): ";
            cin >> choice;

            double value;
            switch (choice) {
                case '1':
                    cout << "Masukkan nilai dalam meter: ";
                    cin >> value;
                    convert_meter(value);
                    break;
                case '2':
                    cout << "Masukkan nilai dalam centimeter: ";
                    cin >> value;
                    convert_centimeter(value);
                    break;
                case '3':
                    cout << "Masukkan nilai dalam mile: ";
                    cin >> value;
                    convert_mile(value);
                    break;
                case '4':
                    cout << "Masukkan nilai dalam foot: ";
                    cin >> value;
                    convert_foot(value);
                    break;
                case '5':
                    cout << "Terima kasih telah menggunakan program!" << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        } while (choice != '5');

        // jika pengguna masih ingin menggunakan program
        cout << "Apakah Anda ingin menggunakan program lagi? (y/n): ";
        cin >> repeat_program;

    } while (repeat_program == 'y' || repeat_program == 'Y');

    cout << "Program sampai sini saja. Terima kasih!" << endl;
    return 0;
}