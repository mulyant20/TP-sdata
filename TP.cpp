#include<iostream>

#include "pasien.h"
using namespace std;

int main(){
	UGD x;

	int pil;
	bool cond;
	cond = true;
	x.inputFile();
	
	while(cond){
		system("cls");
		cout<<"=========================="<<endl;
		cout<<"        MENU UTAMA"<<endl;
		cout<<"=========================="<<endl;
		cout<<" 1. Input Pasien"<<endl;
		cout<<" 2. Cari Pasien"<<endl;
		cout<<" 3. Cetak Antrian Pasien"<<endl;
		cout<<" 4. Pasien Keluar"<<endl;
		cout<<" 5. Rujuk Pasien"<<endl;
		cout<<" 6. Keluar"<<endl;
		cout<<"=========================="<<endl;
		cout<<" Masukkan Pilihan : ";
		cin>>pil;
		switch(pil){
			case 1 : {
				x.inputManual();
				break;
			}
			case 2 : {
				int search;
				system("cls");
				cout<<"=========================="<<endl;
				cout<<"     Pencarian Pasien"<<endl;
				cout<<"=========================="<<endl;
				cout<<" Masukkan ID Pasien : ";
				cin>>search;
				x.cari(search);
				getch();
				break;
			}
			case 3 : {
				do{
					system("cls");
					cout<<"=========================="<<endl;
					cout<<"        Pilihan Cetak"<<endl;
					cout<<"=========================="<<endl;
					cout<<" 1. Cetak Seluruh Antrian"<<endl;
					cout<<" 2. Cetak Antrian Merah"<<endl;
					cout<<" 3. Cetak Antrian Kuning"<<endl;
					cout<<" 4. Cetak Antrian Hijau"<<endl;
					cout<<" 5. Cetak Antrian Hitam"<<endl;
					cout<<"=========================="<<endl;
					cout<<" Masukkan Pilihan : ";
					cin>>pil;
					if(pil == 1){
						x.cetak();
						break;
					}
					else if(pil > 1 && pil <= 5){
						x.pisah();
						x.cetak(pil);
						break;
					}
				}while(1);
				break;
			}
			case 4 : {
				x.deQueue();
				break;
			}
			case 5 : {
				int search;
				system("cls");
				cout<<"=========================="<<endl;
				cout<<"     Pencarian Pasien"<<endl;
				cout<<"=========================="<<endl;
				cout<<" Masukkan ID Pasien : ";
				cin>>search;
				x.rujuk(search);
				break;
			}
			case 6 : {	
				cond = false;
				break;
			}
		}
	}
}