#include "restoran.h"

int main() {
    Node* execChef = createNode("Executive Chef / Chief Cook");
    Node* sousChef = createNode("Sous Chef / Asst Chief Cook");
    addChild(execChef, sousChef);

    int pilihan;
    string parentName, newPosisi, searchName;
    Node* parentNode;
    Node* found;

    while (true) {
        cout << "\n=== MENU MLL ORGANISASI KITCHEN ===\n";
        cout << "1. Tampilkan Struktur\n";
        cout << "2. Tambah Child\n";
        cout << "3. Tambah Sibling\n";
        cout << "4. Cari Posisi\n";
        cout << "5. Hitung Anak dari Posisi\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            display(execChef);
        }

        else if (pilihan == 2) {
            cout << "Masukkan nama parent: ";
            getline(cin, parentName);
            parentNode = search(execChef, parentName);

            if (!parentNode) {
                cout << "Parent tidak ditemukan.\n";
            } else {
                cout << "Masukkan nama posisi baru: ";
                getline(cin, newPosisi);
                addChild(parentNode, createNode(newPosisi));
                cout << "Child berhasil ditambahkan.\n";
            }
        }

        else if (pilihan == 3) {
            cout << "Masukkan nama node untuk tambah sibling: ";
            getline(cin, parentName);
            parentNode = search(execChef, parentName);

            if (!parentNode) {
                cout << "Node tidak ditemukan.\n";
            } else {
                cout << "Masukkan nama posisi sibling baru: ";
                getline(cin, newPosisi);
                addSibling(parentNode, createNode(newPosisi));
                cout << "Sibling berhasil ditambahkan.\n";
            }
        }

        else if (pilihan == 4) {
            cout << "Masukkan nama posisi yang dicari: ";
            getline(cin, searchName);
            found = search(execChef, searchName);

            if (!found)
                cout << "Tidak ditemukan.\n";
            else
                cout << "Ditemukan: " << found->posisi << endl;
        }

        else if (pilihan == 5) {
            cout << "Masukkan nama posisi: ";
            getline(cin, parentName);
            parentNode = search(execChef, parentName);

            if (!parentNode)
                cout << "Posisi tidak ditemukan.\n";
            else
                cout << "Jumlah anak: " << countChildren(parentNode) << endl;
        }

        else if (pilihan == 6) {
            cout << "Program selesai.\n";
            break;
        }

        else {
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
