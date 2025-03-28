#include <bits/stdc++.h>
using namespace std;

int pil;
bool keluar;
int jumlah;
int no;
int pp;

struct mahasiswa{
    int nim;
    string nama;
    int harian;
    int uts;
    int uas;
    float na;
    char predikat;
    string status;
};

struct mahasiswa mhs[100]; 

void tambahMahasishwa(){
    cout<<"\nTambah Data Mahasiswa\n\nJumlah mahasiswa yang akan ditambahkan : ";
    cin>>jumlah;
    for (int i=1; i<=jumlah; i++){
        cout<<"Mahasiswa ke-"<<pp<<"\n--------------------------"<<endl;
        cout<<"Nim \t: ";  cin>>mhs[no].nim;
        cout<<"Nama \t: "; getline(cin>>ws, mhs[no].nama);
        cout<<"[nilai]\n";
        cout<<"Harian \t: "; cin>>mhs[no].harian;
        cout<<"Uts \t: "; cin>>mhs[no].uts;
        cout<<"Uas \t: "; cin>>mhs[no].uas;
        mhs[no].na=((40.0/100)*mhs[no].harian)+((30.0/100)*mhs[no].uts)+((30.0/100)*mhs[no].uas);
        if(mhs[no].na>=85 && mhs[no].na<=100) {mhs[no].predikat='A'; mhs[no].status="Lulus";}
        else if(mhs[no].na>=70 && mhs[no].na<=84) {mhs[no].predikat='B'; mhs[no].status="Lulus";}
        else if(mhs[no].na>=55 && mhs[no].na<=69) {mhs[no].predikat='C'; mhs[no].status="Lulus";}
        else if(mhs[no].na>=40 && mhs[no].na<=54) {mhs[no].predikat='D'; mhs[no].status="Lulus";}
        else if(mhs[no].na<40) {
            mhs[no].predikat='E';
            mhs[no].status="Tidak Lulus";
        }
        no++;
        pp++;
        cout<<endl;
    }
    cout<<"[DATA TELAH DITAMBAHKAN]\n";
    system("pause");
    system("cls");
}

void tmpilkanMahasiswa(){
    for (int i=0; i<no; i++){
        cout<<"Mahasiswa ke-"<<i+1<<"\n--------------------------"<<endl;
        cout<<"Nim \t: "<<mhs[i].nim<<endl;
        cout<<"Nama \t: "<<mhs[i].nama<<endl;
        cout<<"[nilai]\n";
        cout<<"Harian \t: "<<mhs[i].harian<<endl;
        cout<<"Uts \t: "<<mhs[i].uts<<endl;
        cout<<"Uas \t: "<<mhs[i].uas<<endl;
        cout<<"[Hasil Akhir]\n";
        cout<<"Nilai Akhir \t: "<<mhs[i].na<<endl;
        cout<<"Predikat \t: "<<mhs[i].predikat<<endl<<endl;
    }
    cout<<"[DATA BERHASIL DIMUNCULKAN]\n";
    system("pause");
    system("cls");
}

void cariMahasiswa(){
    int p;
    cout<<"\nMencari Data Mahasiswa\n\n1. Cari Berdasarkan NIM\n2. Cari Berdasarkan NAMA\nPilih : "; cin>>p;
    if (p == 1){
        int cari;
        bool found;
        cout<<"Masukkan NIM Mahasiswa yang akan dicari : "; cin>>cari;
        for(int i=0; i<no; i++){
            if (mhs[i].nim==cari){
                found=true;
                system("cls");
                cout<<"[DATA DITEMUKAN]\n"<<endl;
                cout<<"Nim \t: "<<mhs[i].nim<<endl;
                cout<<"Nama \t: "<<mhs[i].nama<<endl;
                cout<<"[Hasil Akhir]\n";
                cout<<"Nilai Akhir \t: "<<mhs[i].na<<endl;
                cout<<"Predikat \t: "<<mhs[i].predikat<<endl;
                cout<<"Status \t: "<<mhs[i].status<<endl;
            }
        }
        if(found==false) cout<<"[DATA TIDAK DITEMUKAN]\n";
        system("pause");
        system("cls");
    }
    else if(p == 2){
        string cari;
        bool found;
        cout<<"Masukkan NIM Mahasiswa yang akan dicari : "; getline(cin>>ws, cari);
        for(int i=0; i<no; i++){
            if (mhs[i].nama==cari){
                found=true;
                system("cls");
                cout<<"[DATA DITEMUKAN]\n"<<endl;
                cout<<"Nim \t: "<<mhs[i].nim<<endl;
                cout<<"Nama \t: "<<mhs[i].nama<<endl;
                cout<<"[Hasil Akhir]\n";
                cout<<"Nilai Akhir \t: "<<mhs[i].na<<endl;
                cout<<"Predikat \t: "<<mhs[i].predikat<<endl;
                cout<<"Status \t: "<<mhs[i].status<<endl;
            }
        }
        if(found==false) cout<<"[DATA TIDAK DITEMUKAN]\n";
        system("pause");
        system("cls");
    }
}

int particion (mahasiswa mhs[], int low, int high){
    string pivot = mhs[high].nama;
    int i=(low-1);

    for (int j=low; j< high; j++){
        if ( mhs[j].nama < pivot){
            i++;
            swap(mhs[i], mhs[j]);
        }
    }
    swap(mhs[i+1], mhs[high]);
    return (i+1);
}

void quickSort(mahasiswa mhs[], int low, int high){
    if(low<high){
        int pi = particion (mhs, low, high);

        quickSort(mhs, low, pi-1);
        quickSort(mhs, pi+1, high);
    }
}

void urutkanMahasiswa(){
    int p;
    cout<<"\nMengurutkan Data Mahasiswa\n\n1. Urutkan Berdasarkan NIM\n2. Urutkan Berdasarkan NAMA\nPilih : "; cin>>p;
    if (p == 1){
        // int n = sizeof(mhs)/sizeof(mhs[0]);
        for (int i=0; i<no; i++){
            struct mahasiswa key = mhs[i];
            int j=i-1;
            
            while (j>=0 &&  mhs[j].nim > key.nim){
                mhs[j+1]=mhs[j];
                j=j-1;
            }
            mhs[j+1]=key;
        }
        cout<<"[HASIL PENGURUTAN]\n";
        for (int i=0; i<no; i++){
            cout<<"Mahasiswa ke-"<<i+1<<"\n--------------------------"<<endl;
            cout<<"Nim \t: "<<mhs[i].nim<<endl;
            cout<<"Nama \t: "<<mhs[i].nama<<endl;
            cout<<"[nilai]\n";
            cout<<"Harian \t: "<<mhs[i].harian<<endl;
            cout<<"Uts \t: "<<mhs[i].uts<<endl;
            cout<<"Uas \t: "<<mhs[i].uas<<endl;
            cout<<"[Hasil Akhir]\n";
            cout<<"Nilai Akhir \t: "<<mhs[i].na<<endl;
            cout<<"Predikat \t: "<<mhs[i].predikat<<endl<<endl;
        }
        system("pause");
        system("cls");
    }
    else if(p == 2){
        quickSort(mhs, 0, no-1);
        cout<<"[HASIL PENGURUTAN]\n";
        for (int i=0; i<no; i++){
            cout<<"Mahasiswa ke-"<<i+1<<"\n--------------------------"<<endl;
            cout<<"Nim \t: "<<mhs[i].nim<<endl;
            cout<<"Nama \t: "<<mhs[i].nama<<endl;
            cout<<"[nilai]\n";
            cout<<"Harian \t: "<<mhs[i].harian<<endl;
            cout<<"Uts \t: "<<mhs[i].uts<<endl;
            cout<<"Uas \t: "<<mhs[i].uas<<endl;
            cout<<"[Hasil Akhir]\n";
            cout<<"Nilai Akhir \t: "<<mhs[i].na<<endl;
            cout<<"Predikat \t: "<<mhs[i].predikat<<endl<<endl;
        }
        system("pause");
        system("cls");
    }
}

int main(){
    keluar = false;
    no=0;
    pp=no+1;
    while(!keluar){
        cout<<"Menu :\n1. Tambah Mahasiswa\n2. Tampilkan Mahasiswa\n3. Cari Mahasiswa\n4. Urutkan Data Mahasiswa\n5. Keluar\npilih : "; cin>>pil;
        switch(pil){
            case 1:
                system("cls");
                tambahMahasishwa();
            break;
            case 2:
                system("cls");
                tmpilkanMahasiswa();
            break;
            case 3:
                system("cls");
                cariMahasiswa();
            break;
            case 4:
                system("cls");
                urutkanMahasiswa();
            break;
            case 5:
                cout<<"[PROGRAM SELESAI]\n"; 
                return 0;
            break;
        }
    }
    return 0;
}