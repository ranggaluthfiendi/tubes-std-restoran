#include "restoran.h"

int main() {
    ElemenPosisi* executiveChef = buatPosisi("Executive Chef");
    ElemenPosisi* sousChef = buatPosisi("Executive Sous Chef");
    tambahBawahan(executiveChef, sousChef);

    int menu;
    string namaTarget, namaBaru;
    ElemenPosisi* posisiTarget;

    while (true) {
        cout << "\n=== STRUKTUR ORGANISASI KITCHEN ===\n";
        cout << "1. Tampilkan Struktur\n";
        cout << "2. Tambah Bawahan(Child)\n";
        cout << "3. Tambah Rekan Sejajar(Sibling)\n";
        cout << "4. Cari Posisi(Detail)\n";
        cout << "5. Hitung Jumlah Bawahan(Count Child)\n";
        cout << "6. Tampilkan Posisi Tanpa Bawahan(Leaf)\n";
        cout << "7. Hitung Total Posisi(Total Node)\n";
        cout << "8. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            tampilkanStruktur(executiveChef);
        }
        else if (menu == 2) {
            cout << "Masukkan nama atasan: ";
            getline(cin, namaTarget);
            posisiTarget = cariPosisi(executiveChef, namaTarget);

            if (posisiTarget == nullptr) {
                cout << "Posisi tidak ditemukan.\n";
            } else {
                cout << "Masukkan nama bawahan baru: ";
                getline(cin, namaBaru);
                tambahBawahan(posisiTarget, buatPosisi(namaBaru));
            }
        }
        else if (menu == 3) {
            cout << "Masukkan nama posisi: ";
            getline(cin, namaTarget);
            posisiTarget = cariPosisi(executiveChef, namaTarget);

            if (posisiTarget == nullptr) {
                cout << "Posisi tidak ditemukan.\n";
            } else {
                cout << "Masukkan nama rekan baru: ";
                getline(cin, namaBaru);
                tambahRekan(posisiTarget, buatPosisi(namaBaru));
            }
        }
        else if (menu == 4) {
            cout << "Masukkan nama posisi: ";
            getline(cin, namaTarget);
            posisiTarget = cariPosisi(executiveChef, namaTarget);

            if (posisiTarget == nullptr) {
                cout << "Posisi tidak ditemukan.\n";
            } else {
                tampilkanDetailPosisi(posisiTarget);
            }
        }
        else if (menu == 5) {
            cout << "Masukkan nama atasan: ";
            getline(cin, namaTarget);
            posisiTarget = cariPosisi(executiveChef, namaTarget);

            if (posisiTarget == nullptr) {
                cout << "Posisi tidak ditemukan.\n";
            } else {
                cout << "Jumlah bawahan: " << hitungBawahan(posisiTarget) << endl;
            }
        }
        else if (menu == 6) {
            tampilkanPosisiTanpaBawahan(executiveChef);
        }
        else if (menu == 7) {
            cout << "Total posisi: " << hitungTotalPosisi(executiveChef) << endl;
        }
        else if (menu == 8) {
            break;
        }
        else {
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
