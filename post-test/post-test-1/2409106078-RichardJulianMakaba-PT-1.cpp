#include <iostream>
using namespace std;

int main() {
    string username, password;
    int percobaan_login = 0;

    cout << "=====================================================================================" << endl;
    cout << "   Selamat datang di sistem konversi perhitungan mata uang, jarak, waktu, dan suhu" << endl;
    cout << "=====================================================================================" << endl;
    cout << "Anda memiliki kesempatan login 3x\n" << endl;

    // Login dengan maksimal 3 percobaan
    while (percobaan_login < 3) {
        cout << "Masukkan Username: ";
        getline(cin, username);
        cout << "Masukkan Password: ";
        getline(cin, password);

        if (username == "Richard Julian Makaba" && password == "2409106078") {
            cout << "\nSelamat Anda berhasil login!" << endl;
            break;
        } else {
            cout << "\nLOGIN GAGAL!!!\n" << endl;
            percobaan_login++;
        }
    }

    if (percobaan_login == 3) {
        cout << "Kesempatan login 3x telah habis. Program berhenti.\n";
        return 0;
    }

    int pilihan;
    do {
        // Menu utama
        cout << "\n============= MENU UTAMA =============\n";
        cout << "[1] Konversi Mata Uang\n";
        cout << "[2] Konversi Jarak\n";
        cout << "[3] Konversi Waktu\n";
        cout << "[4] Konversi Suhu\n";
        cout << "[5] Logout\n";
        cout << "======================================\n";
        cout << "Silahkan pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int subPilihan;
            double jumlah;
            do {
                // Submenu Mata Uang
                cout << "\n====== Konversi Mata Uang ======\n";
                cout << "[1] Rupiah ke Dolar AS\n";
                cout << "[2] Rupiah ke Euro\n";
                cout << "[3] Dolar AS ke Rupiah\n";
                cout << "[4] Dolar AS ke Euro\n";
                cout << "[5] Euro ke Rupiah\n";
                cout << "[6] Euro ke Dolar AS\n";
                cout << "[7] Kembali\n";
                cout << "================================\n";
                cout << "Silahkan pilih menu: ";
                cin >> subPilihan;

                if (subPilihan >= 1 && subPilihan <= 6) {
                    cout << "Masukkan jumlah: ";
                    cin >> jumlah;
                    if (subPilihan == 1) cout << "Hasil konversi dari Rupiah ke Dolar AS: " << jumlah / 15000 << " USD\n";
                    if (subPilihan == 2) cout << "Hasil konversi dari Rupiah ke Euro: " << jumlah / 17000 << " EUR\n";
                    if (subPilihan == 3) cout << "Hasil konversi dari Dolar AS ke Rupiah: " << jumlah * 15000 << " IDR\n";
                    if (subPilihan == 4) cout << "Hasil konversi dari Dolar AS ke Euro: " << jumlah * 0.88 << " EUR\n";
                    if (subPilihan == 5) cout << "Hasil konversi dari Euro ke Rupiah: " << jumlah * 17000 << " IDR\n";
                    if (subPilihan == 6) cout << "Hasil konversi dari Euro ke Dolar AS: " << jumlah / 0.88 << " USD\n";
                }
            } while (subPilihan != 7);
        }

        else if (pilihan == 2) {
            int subPilihan;
            double jumlah;
            do {
                // Submenu Jarak
                cout << "\n====== Konversi Jarak ======\n";
                cout << "[1] Kilometer ke Meter\n";
                cout << "[2] Kilometer ke Centimeter\n";
                cout << "[3] Meter ke Kilometer\n";
                cout << "[4] Meter ke Centimeter\n";
                cout << "[5] Centimeter ke Kilometer\n";
                cout << "[6] Centimeter ke Meter\n";
                cout << "[7] Kembali\n";
                cout << "============================\n";
                cout << "Silahkan pilih menu: ";
                cin >> subPilihan;

                if (subPilihan >= 1 && subPilihan <= 6) {
                    cout << "Masukkan jumlah: ";
                    cin >> jumlah;
                    if (subPilihan == 1) cout << "Hasil konversi dari Kilometer ke Meter: " << jumlah * 1000 << " meter\n";
                    if (subPilihan == 2) cout << "Hasil konversi dari Kilometer ke Centimeter: " << jumlah * 100000 << " cm\n";
                    if (subPilihan == 3) cout << "Hasil konversi dari Meter ke Kilometer: " << jumlah / 1000 << " km\n";
                    if (subPilihan == 4) cout << "Hasil konversi dari Meter ke Centimeter: " << jumlah * 100 << " cm\n";
                    if (subPilihan == 5) cout << "Hasil konversi dari Centimeter ke Kilometer: " << jumlah / 100000 << " km\n";
                    if (subPilihan == 6) cout << "Hasil konversi dari Centimeter ke Meter: " << jumlah / 100 << " meter\n";
                }
            } while (subPilihan != 7);
        }

        else if (pilihan == 3) {
            int subPilihan;
            double jumlah;
            do {
                // Submenu Waktu
                cout << "\n====== Konversi Waktu ======\n";
                cout << "[1] Jam ke Menit\n";
                cout << "[2] Jam ke Detik\n";
                cout << "[3] Menit ke Jam\n";
                cout << "[4] Menit ke Detik\n";
                cout << "[5] Detik ke Jam\n";
                cout << "[6] Detik ke Menit\n";
                cout << "[7] Kembali\n";
                cout << "============================\n";
                cout << "Silahkan pilih menu: ";
                cin >> subPilihan;

                if (subPilihan >= 1 && subPilihan <= 6) {
                    cout << "Masukkan jumlah: ";
                    cin >> jumlah;
                    if (subPilihan == 1) cout << "Hasil konversi dari Jam ke Menit: " << jumlah * 60 << " menit\n";
                    if (subPilihan == 2) cout << "Hasil konversi dari Jam ke Detik: " << jumlah * 3600 << " detik\n";
                    if (subPilihan == 3) cout << "Hasil konversi dari Menit ke Jam: " << jumlah / 60 << " jam\n";
                    if (subPilihan == 4) cout << "Hasil konversi dari Menit ke Detik: " << jumlah * 60 << " detik\n";
                    if (subPilihan == 5) cout << "Hasil konversi dari Detik ke Jam: " << jumlah / 3600 << " jam\n";
                    if (subPilihan == 6) cout << "Hasil konversi dari Detik ke Menit: " << jumlah / 60 << " menit\n";
                }
            } while (subPilihan != 7);
        }

        if (pilihan == 4) {  
            int subPilihan;
            double suhu;
            do {
                // Submenu Suhu
                cout << "\n====== Konversi Suhu ======\n";
                cout << "[1] Celcius ke Fahrenheit\n";
                cout << "[2] Celcius ke Kelvin\n";
                cout << "[3] Fahrenheit ke Celcius\n";
                cout << "[4] Fahrenheit ke Kelvin\n"; 
                cout << "[5] Kelvin ke Celcius\n";
                cout << "[6] Kelvin ke Fahrenheit\n"; 
                cout << "[7] Kembali\n";
                cout << "===========================\n";
                cout << "Silahkan pilih menu: ";
                cin >> subPilihan;

                if (subPilihan >= 1 && subPilihan <= 6) {
                    cout << "Masukkan suhu: ";
                    cin >> suhu;
                    if (subPilihan == 1) cout << "Hasil konversi dari Celcius ke Fahrenheit: " << (suhu * 9 / 5) + 32 << " Fahrenheit\n";
                    if (subPilihan == 2) cout << "Hasil konversi dari Celcius ke Kelvin: " << suhu + 273.15 << " Kelvin\n";
                    if (subPilihan == 3) cout << "Hasil konversi dari Fahrenheit ke Celcius: " << (suhu - 32) * 5 / 9 << " Celcius\n";
                    if (subPilihan == 4) cout << "Hasil konversi dari Fahrenheit ke Kelvin: " << ((suhu - 32) * 5 / 9) + 273.15 << " Kelvin\n";  
                    if (subPilihan == 5) cout << "Hasil konversi dari Kelvin ke Celcius: " << suhu - 273.15 << " Celcius\n";
                    if (subPilihan == 6) cout << "Hasil konversi dari Kelvin ke Fahrenheit: " << ((suhu - 273.15) * 9 / 5) + 32 << " Fahrenheit\n";  
                }
            } while (subPilihan != 7);
        }

    } while (pilihan != 5);

    cout << "\nTerima kasih telah menggunakan program ini!\n";
    return 0;
}
