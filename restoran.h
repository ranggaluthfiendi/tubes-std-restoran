#ifndef RESTORAN_H_INCLUDED
#define RESTORAN_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct DataPosisi {
    string namaPosisi;
};

struct ElemenPosisi {
    DataPosisi data;
    ElemenPosisi* atasan;
    ElemenPosisi* bawahanPertama;
    ElemenPosisi* bawahanBerikutnya;
};

ElemenPosisi* buatPosisi(string namaPosisi);

void tambahBawahan(ElemenPosisi* atasan, ElemenPosisi* bawahan);
void tambahRekan(ElemenPosisi* posisi, ElemenPosisi* rekan);

void tampilkanStruktur(ElemenPosisi* pimpinan, int tingkat = 0);

ElemenPosisi* cariPosisi(ElemenPosisi* pimpinan, string namaPosisi);

int hitungBawahan(ElemenPosisi* atasan);
bool adalahPimpinan(ElemenPosisi* posisi);
int hitungTotalPosisi(ElemenPosisi* pimpinan);
void tampilkanPosisiTanpaBawahan(ElemenPosisi* pimpinan);

void tampilkanDetailPosisi(ElemenPosisi* posisi);

#endif
