#include <iostream>
#include <iomanip>

using namespace std;

#define MAX_USER 5
#define MAX_PEMAIN 20

// Struktur untuk menyimpan data pemain
struct Pemain {
    string nama;
    string posisi;
    int nomor;
    string negara;
    int usia;
    string status;
};

// Struktur untuk menyimpan data pengguna (multiuser)
struct User {
    string username;
    string nim;
};

void registrasi(User users[], int &jumlah_user) {
    if (jumlah_user >= MAX_USER) {
        cout << "Maaf, jumlah user sudah maksimal!\n";
    } else {
        cout << "\n=== Registrasi User Baru ===\n";
        cout << "Masukkan Nama: ";
        cin >> users[jumlah_user].username;
        cout << "Masukkan NIM: ";
        cin >> users[jumlah_user].nim;
        jumlah_user++;
        cout << "User berhasil didaftarkan! Silakan login.\n";
    }
}

bool login(User users[], int jumlah_user) {
    int percobaan_login = 0;
    bool login_berhasil = false;
    cout << "\nAnda memiliki kesempatan login 3x\n";
    while (percobaan_login < 3) {
        string username, nim;
        cout << "Masukkan Nama: ";
        cin >> username;
        cout << "Masukkan NIM: ";
        cin >> nim;

        for (int i = 0; i < jumlah_user; i++) {
            if (users[i].username == username && users[i].nim == nim) {
                login_berhasil = true;
                cout << "Login berhasil! Selamat datang, " << username << "!\n";
                return true;
            }
        }
        
        cout << "Login gagal! Coba lagi.\n";
        percobaan_login++;
    }
    
    cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
    return false;
}

void TambahPemain(Pemain skuad[], int &jumlah_pemain) {
    if (jumlah_pemain < MAX_PEMAIN) {
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, skuad[jumlah_pemain].nama);
        cout << "Masukkan Posisi (Kiper/Bek/Gelandang/Penyerang): ";
        getline(cin, skuad[jumlah_pemain].posisi);
        cout << "Masukkan Nomor Punggung: ";
        cin >> skuad[jumlah_pemain].nomor;
        cout << "Masukkan Negara Asal: ";
        cin.ignore();
        getline(cin, skuad[jumlah_pemain].negara);
        cout << "Masukkan Usia: ";
        cin >> skuad[jumlah_pemain].usia;
        cout << "Masukkan Status (Aktif/Cedera/Cadangan): ";
        cin.ignore();
        getline(cin, skuad[jumlah_pemain].status);

        jumlah_pemain++;
        cout << "Pemain berhasil ditambahkan!\n";
    } else {
        cout << "Skuad penuh! Tidak bisa menambah pemain lagi.\n";
    }
}

void TampilkanSkuad(const Pemain skuad[], int jumlah_pemain) {
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
                << setw(25) << skuad[i].nama
                << setw(20) << skuad[i].posisi
                << setw(16) << skuad[i].nomor
                << setw(15) << skuad[i].negara
                << setw(8) << skuad[i].usia
                << setw(10) << skuad[i].status << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------\n";
}

void UpdatePemain(Pemain skuad[], int jumlah_pemain) {
    cout << "Masukkan nomor pemain yang ingin diperbarui: ";
    int index;
    cin >> index;
    index--;

    if (index >= 0 && index < jumlah_pemain) {
        cout << "Data yang ingin diperbarui:\n";
        cout << "1. Nama\n2. Posisi\n3. Nomor punggung\n4. Negara\n5. Usia\n6. Status\n";
        cout << "Pilih: ";
        int pilihan_update;
        cin >> pilihan_update;
        cin.ignore();

        if (pilihan_update == 1) {
            cout << "Masukkan Nama baru: ";
            getline(cin, skuad[index].nama);
        } else if (pilihan_update == 2) {
            cout << "Masukkan Posisi baru: ";
            getline(cin, skuad[index].posisi);
        } else if (pilihan_update == 3) {
            cout << "Masukkan Nomor Punggung baru: ";
            cin >> skuad[index].nomor;
        } else if (pilihan_update == 4) {
            cout << "Masukkan Negara baru: ";
            cin.ignore();
            getline(cin, skuad[index].negara);
        } else if (pilihan_update == 5) {
            cout << "Masukkan Usia baru: ";
            cin >> skuad[index].usia;
        } else if (pilihan_update == 6) {
            cout << "Masukkan Status baru: ";
            cin.ignore();
            getline(cin, skuad[index].status);
        } else {
            cout << "Pilihan tidak valid.\n";
        }
        cout << "Data pemain diperbarui!\n";
    } else {
        cout << "Nomor pemain tidak ditemukan.\n";
    }
}

void HapusPemain(Pemain skuad[], int &jumlah_pemain) {
    cout << "Masukkan nomor pemain yang ingin dihapus: ";
    int index;
    cin >> index;
    index--;

    if (index >= 0 && index < jumlah_pemain) {
        for (int i = index; i < jumlah_pemain - 1; i++) {
            skuad[i] = skuad[i + 1];
        }
        jumlah_pemain--;
        cout << "Pemain berhasil dihapus!\n";
    } else {
        cout << "Nomor pemain tidak ditemukan.\n";
    }
}

// Fungsi dengan parameter address-of: mengubah status pemain
void GantiStatusPemain(string* status) {
    cout << "Masukkan Status baru (Aktif/Cedera/Cadangan): ";
    getline(cin, *status);  // Dereference untuk mengubah nilai
    cout << "Status berhasil diubah menjadi " << *status << endl;
}

// Fungsi dengan parameter dereference: menampilkan usia pemain
void TampilkanUsiaPemain(const int* usia) {
    cout << "Usia pemain ini adalah " << *usia << " tahun.\n";
}

void SelectionSortNama(Pemain skuad[], int jumlah_pemain) {
    for (int i = 0; i < jumlah_pemain - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < jumlah_pemain; j++) {
            if (skuad[j].nama < skuad[min_idx].nama) { // Ascending
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(skuad[i], skuad[min_idx]);
        }
    }
    cout << "Daftar pemain berhasil diurutkan berdasarkan Nama (A-Z).\n";
}

void QuickSortNomorPunggung(Pemain skuad[], int low, int high) {
    if (low >= high) return;

    // menentukan data tengah sebagai pivot
    int mid = low + (high - low) / 2;
    int pivot = skuad[mid].nomor;
    int i = low, j = high;
    
    while (i <= j) {
        // Untuk ascending: gunakan '<'
        while (skuad[i].nomor < pivot) {
            i++;
        }
        // Untuk ascending: gunakan '>'
        while (skuad[j].nomor > pivot) {
            j--;
        }
        if (i <= j) { // Tukar elemen jika berada di posisi yang salah
            swap(skuad[i], skuad[j]);
            i++;
            j--;
        }
    }
    // Rekursi untuk bagian kiri dan kanan array
    if (low < j) {
        QuickSortNomorPunggung(skuad, low, j);
    }
    if (i < high) {
        QuickSortNomorPunggung(skuad, i, high);
    }
}

void mergePosisi(Pemain skuad[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Pemain L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = skuad[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = skuad[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].posisi >= R[j].posisi) { // Descending
            skuad[k] = L[i];
            i++;
        } else {
            skuad[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        skuad[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        skuad[k] = R[j];
        j++;
        k++;
    }
}

void MergeSortPosisi(Pemain skuad[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSortPosisi(skuad, left, mid);
        MergeSortPosisi(skuad, mid + 1, right);
        mergePosisi(skuad, left, mid, right);
    }
}

int main() {
    User users[MAX_USER];
    int jumlah_user = 0;
    
    // Data awal skuad Barcelona
    Pemain skuad[MAX_PEMAIN] = {
        {"Marc-Andre ter Stegen", "Kiper", 1, "Jerman", 32, "Aktif"},
        {"Ronald Araujo", "Bek", 4, "Uruguay", 25, "Cedera"},
        {"Pedri", "Gelandang", 8, "Spanyol", 22, "Aktif"},
        {"Robert Lewandowski", "Penyerang", 9, "Polandia", 35, "Aktif"}
    };
    int jumlah_pemain = 4;

    cout << "=================================================================" << endl;
    cout << "       Selamat datang di Manajemen Skuad Barcelona 2025       " << endl;
    cout << "=================================================================" << endl;
    
    while (true) {
        cout << "\n=== Menu Awal ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            registrasi(users,jumlah_user);
        } else if (pilihan == 2) {
            if (login(users, jumlah_user)) {
                while (true) {
                    cout << "\n=== Menu Utama ===\n";
                    cout << "1. Tambah Pemain\n";
                    cout << "2. Lihat Daftar Pemain\n";
                    cout << "3. Perbarui Data Pemain\n";
                    cout << "4. Hapus Pemain\n";
                    cout << "5. Ganti Status Pemain \n";
                    cout << "6. Lihat Usia Pemain \n";
                    cout << "7. Urutkan Skuad \n";
                    cout << "8. Keluar\n";
                    cout << "Pilih menu: ";
                    int pilihan;
                    cin >> pilihan;
            
                    if (pilihan == 1) {
                        TambahPemain(skuad, jumlah_pemain); // Menambah pemain baru
                    } else if (pilihan == 2) {
                        TampilkanSkuad(skuad, jumlah_pemain); // Menampilkan skuad
                    } else if (pilihan == 3) {
                        TampilkanSkuad(skuad, jumlah_pemain); // Menampilkan skuad
                        UpdatePemain(skuad, jumlah_pemain); // Memperbarui data pemain
                    } else if (pilihan == 4) {
                        TampilkanSkuad(skuad, jumlah_pemain); // Menampilkan skuad
                        HapusPemain(skuad, jumlah_pemain); // Menghapus pemain
                    } else if (pilihan == 5) {
                        TampilkanSkuad(skuad, jumlah_pemain);
                        cout << "Pilih nomor pemain: ";
                        int idx;
                        cin >> idx;
                        cin.ignore(); // untuk menghindari bug newline
                        if (idx >= 1 && idx <= jumlah_pemain) {
                            GantiStatusPemain(&skuad[idx - 1].status);  // kirim address
                        } else {
                            cout << "Nomor tidak valid.\n";
                        }
                    } else if (pilihan == 6) {
                        TampilkanSkuad(skuad, jumlah_pemain);
                        cout << "Pilih nomor pemain: ";
                        int idx;
                        cin >> idx;
                        if (idx >= 1 && idx <= jumlah_pemain) {
                            TampilkanUsiaPemain(&skuad[idx - 1].usia);  // kirim address
                        } else {
                            cout << "Nomor tidak valid.\n";
                        }
                    } else if (pilihan == 7) {
                        cout << "\n=== Pilih Metode Pengurutan ===\n";
                        cout << "1. Sort Posisi Pemain\n";
                        cout << "2. Sort Nomor Punggung Pemain\n";
                        cout << "3. Sort Nama Pemain\n";
                        cout << "Pilihan: ";
                        int pilihan_sort;
                        cin >> pilihan_sort;
                    
                        if (pilihan_sort == 1) {
                            MergeSortPosisi(skuad, 0, jumlah_pemain - 1);
                            TampilkanSkuad(skuad, jumlah_pemain);
                        } else if (pilihan_sort == 2) {
                            QuickSortNomorPunggung(skuad, 0, jumlah_pemain - 1);
                            TampilkanSkuad(skuad, jumlah_pemain);
                        } else if (pilihan_sort == 3) {
                            SelectionSortNama(skuad, jumlah_pemain);
                            TampilkanSkuad(skuad, jumlah_pemain);
                        } else {
                            cout << "Pilihan tidak valid!\n";
                        }
                    } else if (pilihan == 8) {
                        break; // Keluar dari menu utama
                    } else {
                        cout << "Pilihan tidak valid! Coba lagi.\n";
                    }
                }
            } else {
                return 0; // gagal login 3x
            }
        } else if (pilihan == 3) {
            cout << "Terima kasih telah menggunakan program ini.\n";
            return 0;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
}
