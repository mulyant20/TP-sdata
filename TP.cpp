#include<iostream>

#include "pasien.h"
using namespace std;

int main(){
	UGD x;
	int pil;
	bool cond;
	cond = true;
	string data1[2];
	int data2[2];
	
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
				string nama;
				string klm;
				int id;
				int prioritas;
				int usia;
				cout<<"antrian baru" <<endl;
				for(int i = 0; i < 2; i++) {
					nama = x.ambilnama();
					klm = x.ambilklm();
					id = x.ambilid();
					prioritas = x.ambilpriority();
					usia = x.ambilusia();
					
					x.deQueue();
				}
				
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
						break;
					}
					else{
						
					}
				}while(1);
				break;
			}
			case 4 : {
				
				break;
			}
			case 5 : {
				
				break;
			}
			case 6 : {
				cond = false;
				break;
			}
			default : {
				
				break;
			}
		}
	}
}
