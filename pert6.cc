#include <iostream>
#include <cstring>

using namespace std;

typedef struct {
    int tgl;
    int bln;
    int th;
} Tanggal;

typedef struct {
    char noID[5];
    char nama[30];
    char jenis_kelamin;
    Tanggal t;
} KTP;

typedef struct {
    KTP ktp;
    int jml;
} Data_KTP;

Data_KTP data_ktp;
Data_KTP *p = &data_ktp;

void tambahData() {
    if (p->jml < 100) {
        cout << "Masukkan nomor ID: ";
        cin >> p->ktp.noID;
        cout << "Masukkan nama: ";
        cin.ignore();
        cin.getline(p->ktp.nama, 30);
        cout << "Masukkan jenis kelamin (L/P): ";
        cin >> p->ktp.jenis_kelamin;
        cout << "Masukkan tanggal lahir (dd mm yyyy): ";
        cin >> p->ktp.t.tgl >> p->ktp.t.bln >> p->ktp.t.th;
        p->jml++;
        cout << "Data berhasil ditambahkan!" << endl;
    } else {
        cout << "KTP sudah mencapai batas maksimum!" << endl;
    }
}

void cariDataTahun() {
    int tahun;
    cout << "Masukkan tahun kelahiran yang ingin dicari: ";
    cin >> tahun;
    
    for (int i = 0; i < p->jml; i++) {
        if (p->ktp.t.th == tahun) {
            cout << "No. ID: " << p->ktp.noID << endl;
            cout << "Nama: " << p->ktp.nama << endl;
            cout << "Jenis Kelamin: " << p->ktp.jenis_kelamin << endl;
            cout << "Tanggal Lahir: " << p->ktp.t.tgl << "/" << p->ktp.t.bln << "/" << p->ktp.t.th << endl;
        }
        p++;
    }
}

void tampilDataJK() {
    char jenis_kelamin;
    cout << "Masukkan jenis kelamin (L/P) yang ingin ditampilkan: ";
    cin >> jenis_kelamin;
    
    for (int i = 0; i < p->jml; i++) {
        if (p->ktp.jenis_kelamin == jenis_kelamin) {
            cout << "No. ID: " << p->ktp.noID << endl;
            cout << "Nama: " << p->ktp.nama << endl;
            cout << "Jenis Kelamin: " << p->ktp.jenis_kelamin << endl;
            cout << "Tanggal Lahir: " << p->ktp.t.tgl << "/" << p->ktp.t.bln << "/" << p->ktp.t.th << endl;
        }
        p++;
    }
}

void editData() {
    char noID[5];
    cout << "Masukkan nomor ID data yang ingin diedit: ";
    cin >> noID;
    
    for (int i = 0; i < p->jml; i++) {
        if (strcmp(p->ktp.noID, noID) == 0) {
            cout << "Masukkan nomor ID baru: ";
            cin >> p->ktp.noID;
            cout << "Masukkan nama baru: ";
            cin.ignore();
            cin
.getline(p->ktp.nama, 30);
cout << "Masukkan jenis kelamin baru (L/P): ";
cin >> p->ktp.jenis_kelamin;
cout << "Masukkan tanggal lahir baru (dd mm yyyy): ";
cin >> p->ktp.t.tgl >> p->ktp.t.bln >> p->ktp.t.th;
cout << "Data berhasil diubah!" << endl;
return;
}
p++;
}

c
Copy code
cout << "Data dengan nomor ID tersebut tidak ditemukan!" << endl;
}

int main() {
p->jml = 0;
int menu;

c
Copy code
do {
    cout << "Menu:" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Cari Data berdasarkan Tahun Kelahiran" << endl;
    cout << "3. Tampilkan Data berdasarkan Jenis Kelamin" << endl;
    cout << "4. Edit Data" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> menu;
    
    switch (menu) {
        case 1:
            tambahData();
            break;
        case 2:
            cariDataTahun();
            break;
        case 3:
            tampilDataJK();
            break;
        case 4:
            editData();
            break;
        case 5:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Menu yang dipilih tidak valid!" << endl;
    }
    
    cout << endl;
} while (menu != 5);

return 0;
}
