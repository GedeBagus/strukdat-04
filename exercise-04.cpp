/*
Nama : Gede Bagus Darmagita
NPM: 140810180068
Tanggal: 20 maret 2019
Deskripsi: Mengerjakan exercise-04
*/

#include<iostream>
using namespace std;

struct pegawai{
    char nama[100];
    char divisi[25];
    char gaji[50];
    pegawai* next;
};
typedef pegawai* lazada;
typedef lazada list;

void createList (list& first);
void createElmt (lazada& pBaru);
void insertFirst (list& first, lazada pBaru);
void insertLast (list& first, lazada pBaru);
void deleteFirst (list& first, lazada& pHapus);
void deleteLast (list& first, lazada& pHapus);
void traversal (list first);

main (){
    int pilihan;
    lazada karyawan;
    list database;

    createList (database);
    while(1){
        system("cls");
        cout << "--DATABASE LAZADA--" << endl;
        cout << "1. Tambah data (awal)" << endl;
        cout << "2. Tambah data (akhir)" << endl;
        cout << "3. Hapus data (awal)" << endl;
        cout << "4. Hapus data (akhir)" << endl;
        cout << "5. Tampilkan data" << endl;
        cout << "6. Exit" << endl;
        cout << "Masukan Pilihan : "; cin >> pilihan;
        switch (pilihan){
            case 1:
            createElmt (karyawan);
            insertFirst (database, karyawan);
            break;

            case 2:
            createElmt (karyawan);
            insertLast (database, karyawan);
            break;

            case 3:
            deleteFirst (database, karyawan);
            break;

            case 4:
            deleteLast (database, karyawan);
            break;

            case 5:
            cout << "NAMA\t\t\t ||\t\t\t DIVISI\t\t\t ||\t\t\t GAJI" << endl;
            traversal (database);
            break;

            case 6:
            return 0;
            break;
        }
        system("pause");
    }
}

void createList (list& first){
    first = NULL;
}

void createElmt (lazada& pBaru){
    pBaru = new pegawai;
    cout << "Nama\t: "; cin.ignore(); cin.getline(pBaru->nama, 100);
    cout << "Divisi\t: "; cin >> pBaru->divisi;
    cout << "Gaji\t: "; cin >> pBaru->gaji;
    pBaru->next = NULL;
}

void insertFirst (list& first, lazada pBaru){
    if (first == NULL){
        first = pBaru;
    }
    else {
        pBaru->next = first;
        first = pBaru;
    }
}

void insertLast (list& first, lazada pBaru){
    lazada last;
    if (first == NULL){
        first = pBaru;
    }
    else {
        last = first;
        while (last->next != NULL){
            last =  last->next;
        }
        last->next = pBaru;
    }
}

void deleteFirst (list& first, lazada& pHapus){
    if (first == NULL){
        pHapus = NULL;
        cout << "Tidak ada data yang dihapus!" << endl;
    }
    else if (first->next == NULL){
        pHapus = first;
        first = NULL;
    }
    else {
        pHapus = first;
        first = first->next;
        pHapus->next = NULL;
    }
}

void deleteLast (list& first, lazada& pHapus){
    lazada last, precLast;
    if (first == NULL){
        pHapus = NULL;
        cout << "Tidak ada data yang dihapus!" << endl;
    }
    else if (first->next == NULL){
        pHapus = first;
        first = NULL;
    }
    else {
        last = first;
        precLast = NULL;
        while (last->next != NULL){
            precLast = last;
            last = last->next;
        }
        pHapus = last;
        precLast->next = NULL;
    }
}

void traversal (list first){
    lazada pBantu;
    pBantu = first;
    while (pBantu != NULL){
        cout << pBantu->nama << "\t\t" << pBantu->divisi << "\t\t\t\t\t\t" << pBantu->gaji << endl;
        pBantu = pBantu->next;
    }
}