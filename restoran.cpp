#include "restoran.h"

ElemenPosisi* buatPosisi(string namaPosisi) {
    ElemenPosisi* P = new ElemenPosisi;
    P->data.namaPosisi = namaPosisi;
    P->atasan = nullptr;
    P->bawahanPertama = nullptr;
    P->bawahanBerikutnya = nullptr;
    return P;
}

void tambahBawahan(ElemenPosisi* atasan, ElemenPosisi* bawahan) {
    if (atasan == nullptr || bawahan == nullptr) {
        return;
    }

    bawahan->atasan = atasan;

    if (atasan->bawahanPertama == nullptr) {
        atasan->bawahanPertama = bawahan;
    } else {
        ElemenPosisi* temp = atasan->bawahanPertama;
        while (temp->bawahanBerikutnya != nullptr) {
            temp = temp->bawahanBerikutnya;
        }
        temp->bawahanBerikutnya = bawahan;
    }
}

void tambahRekan(ElemenPosisi* posisi, ElemenPosisi* rekan) {
    if (posisi == nullptr || rekan == nullptr) {
        return;
    }

    while (posisi->bawahanBerikutnya != nullptr) {
        posisi = posisi->bawahanBerikutnya;
    }

    posisi->bawahanBerikutnya = rekan;
    rekan->atasan = posisi->atasan;
}

void tampilkanStruktur(ElemenPosisi* pimpinan, int tingkat) {
    if (pimpinan == nullptr) {
        return;
    }

    for (int i = 0; i < tingkat; i++) {
        cout << " ";
    }
    cout << "- " << pimpinan->data.namaPosisi << endl;

    tampilkanStruktur(pimpinan->bawahanPertama, tingkat + 1);
    tampilkanStruktur(pimpinan->bawahanBerikutnya, tingkat);
}

ElemenPosisi* cariPosisi(ElemenPosisi* pimpinan, string namaPosisi) {
    if (pimpinan == nullptr) {
        return nullptr;
    }

    if (pimpinan->data.namaPosisi == namaPosisi) {
        return pimpinan;
    }

    ElemenPosisi* hasil = cariPosisi(pimpinan->bawahanPertama, namaPosisi);
    if (hasil != nullptr) {
        return hasil;
    }

    return cariPosisi(pimpinan->bawahanBerikutnya, namaPosisi);
}

int hitungBawahan(ElemenPosisi* atasan) {
    if (atasan == nullptr || atasan->bawahanPertama == nullptr) {
        return 0;
    }

    int jumlah = 0;
    ElemenPosisi* temp = atasan->bawahanPertama;

    while (temp != nullptr) {
        jumlah++;
        temp = temp->bawahanBerikutnya;
    }

    return jumlah;
}

bool adalahPimpinan(ElemenPosisi* posisi) {
    if (posisi == nullptr) {
        return false;
    }

    if (posisi->bawahanPertama != nullptr) {
        return true;
    }

    return false;
}

int hitungTotalPosisi(ElemenPosisi* pimpinan) {
    if (pimpinan == nullptr) {
        return 0;
    }

    return 1
        + hitungTotalPosisi(pimpinan->bawahanPertama)
        + hitungTotalPosisi(pimpinan->bawahanBerikutnya);
}

void tampilkanPosisiTanpaBawahan(ElemenPosisi* pimpinan) {
    if (pimpinan == nullptr) {
        return;
    }

    if (pimpinan->bawahanPertama == nullptr) {
        cout << "- " << pimpinan->data.namaPosisi << endl;
    }

    tampilkanPosisiTanpaBawahan(pimpinan->bawahanPertama);
    tampilkanPosisiTanpaBawahan(pimpinan->bawahanBerikutnya);
}

void tampilkanDetailPosisi(ElemenPosisi* posisi) {
    if (posisi == nullptr) {
        return;
    }

    cout << "\nNama Posisi: " << posisi->data.namaPosisi << endl;

    if (posisi->atasan != nullptr) {
        cout << "Atasan: " << posisi->atasan->data.namaPosisi << endl;
    } else {
        cout << "Atasan: -" << endl;
    }

    int jumlah = hitungBawahan(posisi);
    cout << "Jumlah Bawahan: " << jumlah << endl;

    cout << "Daftar Bawahan: ";
    if (jumlah == 0) {
        cout << "-" << endl;
    } else {
        cout << endl;
        ElemenPosisi* temp = posisi->bawahanPertama;
        while (temp != nullptr) {
            cout << "  - " << temp->data.namaPosisi << endl;
            temp = temp->bawahanBerikutnya;
        }
    }

    cout << "Rekan Sejajar: ";
    if (posisi->atasan == nullptr) {
        cout << "-" << endl;
    } else {
        ElemenPosisi* temp = posisi->atasan->bawahanPertama;
        bool ada = false;

        while (temp != nullptr) {
            if (temp != posisi) {
                cout << temp->data.namaPosisi;
                ada = true;
                if (temp->bawahanBerikutnya != nullptr) {
                    cout << ", ";
                }
            }
            temp = temp->bawahanBerikutnya;
        }

        if (!ada) {
            cout << "-";
        }
        cout << endl;
    }
}
