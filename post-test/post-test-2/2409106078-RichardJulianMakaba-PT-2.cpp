#include <iostream>
#include <iomanip>  //  untuk merapikan tabel

using namespace std;

#define MAX_PEMAIN 20  // Maksimal jumlah pemain

int main() {
    string username, nim;
    int percobaan_login = 0;
    bool login_berhasil = false;

    cout << "=================================================================" << endl;
    cout << "       Selamat datang di Manajemen Skuad Barcelona 2025" << endl;
    cout << "=================================================================" << endl;
    cout << "Anda memiliki kesempatan login 3x\n" << endl;

    // Login dengan maksimal 3 kali percobaan
    while (percobaan_login < 3) {
        cout << "Masukkan Nama: ";
        cin >> username;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (username == "Richard" && nim == "2409106078") {
            login_berhasil = true;
            break;
        } else {
            cout << "Login gagal! Coba lagi.\n";
            percobaan_login++;
        }
    }

    if (!login_berhasil) {
        cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    // Data awal skuad Barcelona
    string pemain[MAX_PEMAIN][6] = {
        {"Marc-Andre ter Stegen", "Kiper", "1", "Jerman", "32", "Aktif"},
        {"Ronald Araujo", "Bek", "4", "Uruguay", "25", "Cedera"},
        {"Pedri", "Gelandang", "8", "Spanyol", "22", "Aktif"},
        {"Robert Lewandowski", "Penyerang", "9", "Polandia", "35", "Aktif"}
    };

    int jumlah_pemain = 4;  // Jumlah pemain yang sudah ada

    while (true) {
        // Menu utama
        cout << "\n=== Menu Utama ===\n";
        cout << "1. Tambah Pemain\n";
        cout << "2. Lihat Daftar Pemain\n";
        cout << "3. Perbarui Data Pemain\n";
        cout << "4. Hapus Pemain\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {  
            // Menambah pemain baru
            if (jumlah_pemain < MAX_PEMAIN) {
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, pemain[jumlah_pemain][0]);
                cout << "Masukkan Posisi (Kiper/Bek/Gelandang/Penyerang): ";
                getline(cin, pemain[jumlah_pemain][1]);
                cout << "Masukkan Nomor Punggung: ";
                cin >> pemain[jumlah_pemain][2];
                cout << "Masukkan Negara Asal: ";
                cin.ignore();
                getline(cin, pemain[jumlah_pemain][3]);
                cout << "Masukkan Usia: ";
                cin >> pemain[jumlah_pemain][4];
                cout << "Masukkan Status (Aktif/Cedera/Cadangan): ";
                cin.ignore();
                getline(cin, pemain[jumlah_pemain][5]);

                jumlah_pemain++;
                cout << "Pemain berhasil ditambahkan!\n";
            } else {
                cout << "Skuad penuh! Tidak bisa menambah pemain lagi.\n";
            }
        } 
        else if (pilihan == 2) {  
            // Menampilkan daftar pemain
            cout << "\n======================================================================================================\n";
            cout << left << setw(5) << "No."
                 << setw(25) << "Nama"
                 << setw(20) << "Posisi"
                 << setw(16) << "No. Punggung"
                 << setw(15) << "Negara"
                 << setw(8) << "Usia"
                 << setw(10) << "Status" << endl;
            cout << "------------------------------------------------------------------------------------------------------\n";
            
            for (int i = 0; i < jumlah_pemain; i++) {
                cout << left << setw(5) << i + 1
                << setw(25) << pemain[i][0]
                << setw(20) << pemain[i][1]
                << setw(16) << pemain[i][2]
                << setw(15) << pemain[i][3]
                << setw(8) << pemain[i][4]
                << setw(10) << pemain[i][5] << endl;
            }
            cout << "------------------------------------------------------------------------------------------------------\n";
        } 
        else if (pilihan == 3) {  
            // Menampilkan daftar pemain
            cout << "\n======================================================================================================\n";
            cout << left << setw(5) << "No."
                 << setw(25) << "Nama"
                 << setw(20) << "Posisi"
                 << setw(16) << "No. Punggung"
                 << setw(15) << "Negara"
                 << setw(8) << "Usia"
                 << setw(10) << "Status" << endl;
            cout << "------------------------------------------------------------------------------------------------------\n";
            
            for (int i = 0; i < jumlah_pemain; i++) {
                cout << left << setw(5) << i + 1
                << setw(25) << pemain[i][0]
                << setw(20) << pemain[i][1]
                << setw(16) << pemain[i][2]
                << setw(15) << pemain[i][3]
                << setw(8) << pemain[i][4]
                << setw(10) << pemain[i][5] << endl;
            }
            cout << "------------------------------------------------------------------------------------------------------\n";
            
            // Perbarui data pemain
            cout << "Masukkan nomor pemain yang ingin diperbarui: ";
            int index;
            cin >> index;
            index--;

            if (index >= 0 && index < jumlah_pemain) {
                cout << "Data yang ingin diperbarui:\n";
                cout << "1. Nama\n2. Posisi\n3. Nomor punggung\n4. Negara\n5. Usia\n6. Status\n";
                cout << "Pilih : ";
                int pilihan_update;
                cin >> pilihan_update;
                cin.ignore();

                if (pilihan_update == 1) {
                    cout << "Masukkan Nama baru : ";
                    getline(cin, pemain[index][0]);
                } 
                else if (pilihan_update == 2) {
                    cout << "Masukkan Posisi baru (Kiper/Bek/Gelandang/Penyerang): ";
                    cin >> pemain[index][1];
                } 
                else if (pilihan_update == 3) {
                    cout << "Masukkan Nomor Punggung baru: ";
                    cin >> pemain[index][2];
                } 
                else if (pilihan_update == 4) {
                    cout << "Masukkan Negara baru : ";
                    getline(cin, pemain[index][3]);
                } 
                else if (pilihan_update == 5) {
                    cout << "Masukkan Usia baru: ";
                    cin >> pemain[index][4];
                } 
                else if (pilihan_update == 6) {
                    cout << "Masukkan Status baru (Aktif/Cedera/Cadangan): ";
                    getline(cin, pemain[index][5]);
                } 
                else {
                    cout << "Pilihan tidak valid.\n";
                }
                if (pilihan_update >= 1 && pilihan_update <= 6) {
                    cout << "Data pemain diperbarui!\n";
                }
            } else {
                cout << "Nomor pemain tidak ditemukan.\n";
            }
        } 
        else if (pilihan == 4) {  
            // Menampilkan daftar pemain
            cout << "\n======================================================================================================\n";
            cout << left << setw(5) << "No."
                 << setw(25) << "Nama"
                 << setw(20) << "Posisi"
                 << setw(16) << "No. Punggung"
                 << setw(15) << "Negara"
                 << setw(8) << "Usia"
                 << setw(10) << "Status" << endl;
            cout << "------------------------------------------------------------------------------------------------------\n";
            
            for (int i = 0; i < jumlah_pemain; i++) {
                cout << left << setw(5) << i + 1
                << setw(25) << pemain[i][0]
                << setw(20) << pemain[i][1]
                << setw(16) << pemain[i][2]
                << setw(15) << pemain[i][3]
                << setw(8) << pemain[i][4]
                << setw(10) << pemain[i][5] << endl;
            }
            cout << "------------------------------------------------------------------------------------------------------\n";
            
            // Menghapus pemain dari skuad
            cout << "Masukkan nomor pemain yang ingin dihapus: ";
            int index;
            cin >> index;
            index--;

            if (index >= 0 && index < jumlah_pemain) {
                for (int i = index; i < jumlah_pemain - 1; i++) {
                    for (int j = 0; j < 6; j++) {
                        pemain[i][j] = pemain[i + 1][j];
                    }
                }
                jumlah_pemain--;
                cout << "Pemain berhasil dihapus!\n";
            } else {
                cout << "Nomor pemain tidak ditemukan.\n";
            }
        } 
        else if (pilihan == 5) {  
            // Keluar dari program
            cout << "Terima kasih telah menggunakan program ini.\n";
            break;
        } 
        else {
            cout << "Pilihan tidak valid! Coba lagi.\n";
        }
    }

    return 0;
}
