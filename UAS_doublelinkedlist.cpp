#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    Mahasiswa* prev;
    Mahasiswa* next;

    Mahasiswa(string nama, int nim) {
        this->nama = nama;
        this->nim = nim;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Mahasiswa* head;
    Mahasiswa* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menambahkan mahasiswa di depan
    void tambahDepan(string nama, int nim) {
        Mahasiswa* newMahasiswa = new Mahasiswa(nama, nim);
        if (head == nullptr) {
            head = newMahasiswa;
            tail = newMahasiswa;
        } else {
            newMahasiswa->next = head;
            head->prev = newMahasiswa;
            head = newMahasiswa;
        }
    }

    // Fungsi untuk menambahkan mahasiswa di belakang
    void tambahBelakang(string nama, int nim) {
        Mahasiswa* newMahasiswa = new Mahasiswa(nama, nim);
        if (tail == nullptr) {
            head = newMahasiswa;
            tail = newMahasiswa;
        } else {
            newMahasiswa->prev = tail;
            tail->next = newMahasiswa;
            tail = newMahasiswa;
        }
    }

    // Fungsi untuk menambahkan mahasiswa di tengah
    void tambahTengah(string nama, int nim, int posisi) {
        if (posisi <= 1) {
            tambahDepan(nama, nim);
            return;
        }

        Mahasiswa* newMahasiswa = new Mahasiswa(nama, nim);
        Mahasiswa* current = head;
        int counter = 1;

        while (current != nullptr && counter < posisi - 1) {
            current = current->next;
            counter++;
        }

        if (current == nullptr) {
            cout << "Posisi melebihi jumlah mahasiswa dalam list." << endl;
            delete newMahasiswa;
            return;
        }

        newMahasiswa->prev = current;
        newMahasiswa->next = current->next;
        current->next = newMahasiswa;
        if (newMahasiswa->next != nullptr) {
            newMahasiswa->next->prev = newMahasiswa;
        } else {
            tail = newMahasiswa;
        }
    }

    // Fungsi untuk menghapus mahasiswa di depan
    void hapusDepan() {
        if (head == nullptr) {
            cout << "List mahasiswa sudah kosong." << endl;
            return;
        }

        Mahasiswa* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
    }

    // Fungsi untuk menghapus mahasiswa di belakang
    void hapusBelakang() {
        if (tail == nullptr) {
            cout << "List mahasiswa sudah kosong." << endl;
            return;
        }

        Mahasiswa* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
    }

    // Fungsi untuk menghapus mahasiswa di tengah
    void hapusTengah(int posisi) {
        if (posisi <= 1) {
            hapusDepan();
            return;
        }

        Mahasiswa* current = head;
        int counter = 1;

        while (current != nullptr && counter < posisi) {
            current = current->next;
            counter++;
        }

        if (current == nullptr) {
            cout << "Posisi melebihi jumlah mahasiswa dalam list." << endl;
            return;
        }

        if (current == head) {
            hapusDepan();
        } else if (current == tail) {
            hapusBelakang();
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }

    // Fungsi untuk mencetak daftar mahasiswa
    void cetakList() {
        Mahasiswa* current = head;
        while (current != nullptr) {
            cout << "NIM: " << current->nim << ", Nama: " << current->nama << endl;
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList daftarMahasiswa;

    int pilihan;
    string nama;
    int nim, posisi;

    do {
        cout << "Menu:" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Hapus Depan" << endl;
        cout << "5. Hapus Belakang" << endl;
        cout << "6. Hapus Tengah" << endl;
        cout << "7. Cetak List" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore(); // Ignore newline character left by previous input
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                daftarMahasiswa.tambahDepan(nama, nim);
                break;
            case 2:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore(); // Ignore newline character left by previous input
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                daftarMahasiswa.tambahBelakang(nama, nim);
                break;
            case 3:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore(); // Ignore newline character left by previous input
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                cout << "Masukkan Posisi Tengah: ";
                cin >> posisi;
                daftarMahasiswa.tambahTengah(nama, nim, posisi);
                break;
            case 4:
                daftarMahasiswa.hapusDepan();
                break;
            case 5:
                daftarMahasiswa.hapusBelakang();
                break;
            case 6:
                cout << "Masukkan Posisi Tengah: ";
                cin >> posisi;
                daftarMahasiswa.hapusTengah(posisi);
                break;
            case 7:
                daftarMahasiswa.cetakList();
                break;
            case 8:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }

        cout << endl;
    } while (pilihan != 8);

    return 0;
}#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    Mahasiswa* prev;
    Mahasiswa* next;

    Mahasiswa(string nama, int nim) {
        this->nama = nama;
        this->nim = nim;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Mahasiswa* head;
    Mahasiswa* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menambahkan mahasiswa di depan
    void tambahDepan(string nama, int nim) {
        Mahasiswa* newMahasiswa = new Mahasiswa(nama, nim);
        if (head == nullptr) {
            head = newMahasiswa;
            tail = newMahasiswa;
        } else {
            newMahasiswa->next = head;
            head->prev = newMahasiswa;
            head = newMahasiswa;
        }
    }

    // Fungsi untuk menambahkan mahasiswa di belakang
    void tambahBelakang(string nama, int nim) {
        Mahasiswa* newMahasiswa = new Mahasiswa(nama, nim);
        if (tail == nullptr) {
            head = newMahasiswa;
            tail = newMahasiswa;
        } else {
            newMahasiswa->prev = tail;
            tail->next = newMahasiswa;
            tail = newMahasiswa;
        }
    }

    // Fungsi untuk menambahkan mahasiswa di tengah
    void tambahTengah(string nama, int nim, int posisi) {
        if (posisi <= 1) {
            tambahDepan(nama, nim);
            return;
        }

        Mahasiswa* newMahasiswa = new Mahasiswa(nama, nim);
        Mahasiswa* current = head;
        int counter = 1;

        while (current != nullptr && counter < posisi - 1) {
            current = current->next;
            counter++;
        }

        if (current == nullptr) {
            cout << "Posisi melebihi jumlah mahasiswa dalam list." << endl;
            delete newMahasiswa;
            return;
        }

        newMahasiswa->prev = current;
        newMahasiswa->next = current->next;
        current->next = newMahasiswa;
        if (newMahasiswa->next != nullptr) {
            newMahasiswa->next->prev = newMahasiswa;
        } else {
            tail = newMahasiswa;
        }
    }

    // Fungsi untuk menghapus mahasiswa di depan
    void hapusDepan() {
        if (head == nullptr) {
            cout << "List mahasiswa sudah kosong." << endl;
            return;
        }

        Mahasiswa* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
    }

    // Fungsi untuk menghapus mahasiswa di belakang
    void hapusBelakang() {
        if (tail == nullptr) {
            cout << "List mahasiswa sudah kosong." << endl;
            return;
        }

        Mahasiswa* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
    }

    // Fungsi untuk menghapus mahasiswa di tengah
    void hapusTengah(int posisi) {
        if (posisi <= 1) {
            hapusDepan();
            return;
        }

        Mahasiswa* current = head;
        int counter = 1;

        while (current != nullptr && counter < posisi) {
            current = current->next;
            counter++;
        }

        if (current == nullptr) {
            cout << "Posisi melebihi jumlah mahasiswa dalam list." << endl;
            return;
        }

        if (current == head) {
            hapusDepan();
        } else if (current == tail) {
            hapusBelakang();
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }

    // Fungsi untuk mencetak daftar mahasiswa
    void cetakList() {
        Mahasiswa* current = head;
        while (current != nullptr) {
            cout << "NIM: " << current->nim << ", Nama: " << current->nama << endl;
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList daftarMahasiswa;

    int pilihan;
    string nama;
    int nim, posisi;

    do {
        cout << "Menu:" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Hapus Depan" << endl;
        cout << "5. Hapus Belakang" << endl;
        cout << "6. Hapus Tengah" << endl;
        cout << "7. Cetak List" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore(); // Ignore newline character left by previous input
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                daftarMahasiswa.tambahDepan(nama, nim);
                break;
            case 2:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore(); // Ignore newline character left by previous input
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                daftarMahasiswa.tambahBelakang(nama, nim);
                break;
            case 3:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore(); // Ignore newline character left by previous input
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                cout << "Masukkan Posisi Tengah: ";
                cin >> posisi;
                daftarMahasiswa.tambahTengah(nama, nim, posisi);
                break;
            case 4:
                daftarMahasiswa.hapusDepan();
                break;
            case 5:
                daftarMahasiswa.hapusBelakang();
                break;
            case 6:
                cout << "Masukkan Posisi Tengah: ";
                cin >> posisi;
                daftarMahasiswa.hapusTengah(posisi);
                break;
            case 7:
                daftarMahasiswa.cetakList();
                break;
            case 8:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }

        cout << endl;
    } while (pilihan != 8);

    return 0;
}
