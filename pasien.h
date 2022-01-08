#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;


struct pasien{
	int cond[10], usia;
	int priority, id;
	string nama, jenis_klm;
	pasien *next;
};
class UGD{
	public :
		UGD();
		bool isFull();
		
		int decision(int, int, int);
		int pernapasan();
		int kondisiJantung();
		int tekananDarah();
		
		void deQueue(pasien *);
		void deQueue();
		void pisah();
		void inputManual();
		void inputFile();
		void input(pasien *, pasien *);
		void cetak();
		void enqueue(int prioritas, int usia, int nafas, int jantung, int darah);
		
		string ambilnama();
		string ambilklm();
		int ambilid();
		int ambilpriority();
		int ambilusia();
		
	private :
		int maks, length;
		pasien *front;
		pasien *rear;
		pasien *merah, *kuning, *hijau, *hitam;
};

UGD::UGD(){
	front = NULL;
	maks = 8;
	length = 0;
}

string UGD::ambilnama() {
	return front->nama;
}

string UGD::ambilklm() {
	return front->jenis_klm;
}

int UGD::ambilid() {
	return front->id;
}

int UGD::ambilpriority() {
	return front->priority;
}

int UGD::ambilusia() {
	return front->usia;
}

void UGD::deQueue(pasien *root){
	pasien *hapus = root;
	
	root = root->next;
	
	delete hapus;
	
	
}

void UGD::deQueue(){
	string nama = front->nama;
	cout << "pasien bernama "<< nama << endl;
	pasien *hapus = front;
	
	front = front->next;
	
	delete hapus;
}

bool UGD::isFull(){
	if(length >= maks){
		return true;
	} else{
		return false;
	}
}

int UGD::pernapasan(){
	int temp;
	do{
		system("cls");
		cout<<"=========================="<<endl;
		cout<<" Kondisi Pernapasan Pasien"<<endl;
		cout<<"=========================="<<endl;
		cout<<"  1. Pernapasan Sesak"<<endl;
		cout<<"  2. Pernapasan Lancar"<<endl;
		cout<<"  3. Tidak Bernapas"<<endl;
		cout<<"=========================="<<endl;
		cout<<" Masukkan Pilihan : ";
		cin>>temp;
	}while(temp > 3);
	return temp;
}

int UGD::kondisiJantung(){
	int temp;
	do{
		system("cls");
		cout<<"=========================="<<endl;
		cout<<"  Kondisi Detak Jantung"<<endl;
		cout<<"=========================="<<endl;
		cout<<"  1. Berdetak"<<endl;
		cout<<"  2. Tidak Berdetak"<<endl;
		cout<<"=========================="<<endl;
		cout<<" Masukkan Pilihan : ";
		cin>>temp;
	}while(temp > 2);
	return temp;
}

int UGD::tekananDarah(){
	int temp;
	do{
		system("cls");
		cout<<"=========================="<<endl;
		cout<<"  Kondisi Tekanan Darah"<<endl;
		cout<<"=========================="<<endl;
		cout<<"  1. 90/60 - 120/80"<<endl;
		cout<<"  2. Diatas 120/80 "<<endl;
		cout<<"  3. Dibawah 90/60 "<<endl;
		cout<<"=========================="<<endl;
		cout<<" Masukkan Pilihan : ";
		cin>>temp;
	}while(temp > 3);
	return temp;
}

int UGD::decision(int x, int y, int z){
	int napas = x, jantung = y, tensi = z;
	
	if(napas == 1){
		
		if(jantung == 1){
			
			if(tensi == 1){
				return 2;
			}
			else{
				return 1;
			}
			
		}
		else{
			return 1;
		}
	}
	else if(napas == 2){
		
		if(jantung == 1){
					
			if(tensi == 1){
				return 3;
			}
			else{
				return 2;
			}
			
		}
		else{
			return 1;
		}
		
	}
	else{
		
		if(jantung == 1){
			
			if(tensi == 1){
				return 1;
			}
			else{
				return 0;
			}
			
		}
		else{
			return 0;
		}
	}
}

void UGD::inputManual() {
	pasien *newNode = new pasien();
	
	if(!isFull()){
		// hasil decision disimpan di prioritas untuk dibandingkan
		newNode->cond[0] = pernapasan();
		newNode->cond[1] = kondisiJantung();
		newNode->cond[2] = tekananDarah();		
		newNode->priority = decision(newNode->cond[0],newNode->cond[1],newNode->cond[2]);
		
		system("cls");
		cout<<" Prioritas Pasien Adalah : "<<newNode->priority<<endl;;
		
		cout<<" Masukan ID : ";
		cin>>newNode->id;
		
		cin.ignore();
		cout<<" Masukkan Nama Pasien : ";
		getline(cin, newNode->nama);
		
		cout<<" Masukkan Jenis Kelamin (L/P) :";
		cin>>newNode->jenis_klm;
		
		cout<<" Masukkan Usia ";
		cin>>newNode->usia;
	
		if (front == NULL){
			front= newNode;
			rear = newNode;
			rear->next = NULL;
		}
		else if(front->priority > newNode->priority){
			newNode->next = front;
			front = newNode;
		}
		else{
			pasien *temp = front;
	
		    while (temp->next != NULL && temp->next->priority <= newNode->priority) {
		        temp = temp->next;
		    }
		    
		    if(temp != rear){
		    	newNode->next = temp->next;
		    	temp->next = newNode;
			}
			else{
				temp->next = newNode;
				rear = newNode;
				rear->next = NULL;
			}
		}
		length++;
	}
	else{
		cout<<"Antrian Data Penuh";
	}
}

void UGD::enqueue(int prioritas, int usia, int nafas, int jantung, int darah) {

	pasien *newNode = new pasien();
	
	if(!isFull()){
		// hasil decision disimpan di prioritas untuk dibandingkan
		newNode->cond[0] = nafas;
		newNode->cond[1] = jantung;
		newNode->cond[2] = darah;		
		newNode->priority = prioritas;
		
		system("cls");
		cout<<" Prioritas Pasien Adalah : "<<newNode->priority<<endl;;
		
	}
}

void UGD::inputFile(){
	ifstream file;
	file.open("data.txt");
	pasien *newNode = new pasien();
	
	if(!file.fail()){
		do{
			if(!isFull()){
				
				if (front == NULL){
					front= newNode;
					rear = newNode;
					rear->next = NULL;
				}
				else if(front->priority > newNode->priority){
					newNode->next = front;
					front = newNode;
				}
				else{
					pasien *temp = front;
			
				    while (temp->next != NULL && temp->next->priority <= newNode->priority) {
				        temp = temp->next;
				    }
				    
				    if(temp != rear){
				    	newNode->next = temp->next;
				    	temp->next = newNode;
					}
					else{
						temp->next = newNode;
						rear = newNode;
						rear->next = NULL;
					}
				}
				length++;
			}
			else{
				cout<<"Antrian Data Penuh";
			}
		} while(!file.eof());
	}
	else{
		cout<<"File Tidak Ditemukan";
	}
}

void UGD::input(pasien *base, pasien *root){
	
}

void UGD::cetak(){
	pasien *print = front;
	
	system("cls");
	while(print != NULL){
		cout<<"================================"<<endl;
		cout<<"Prioritas : "<<print->priority<<endl;
		cout<<"Nama      : "<<print->id<<endl;
		cout<<"ID        : "<<print->id<<endl;
		
		print = print->next;
	}
	
	getch();
}

void UGD::pisah(){
	pasien *pisah = front;
	
	while(pisah != NULL){
		if(pisah->priority == 1){
			input(pisah,merah);
		}
		else if(pisah->priority == 2){
			input(pisah,kuning);
		}
		else if(pisah->priority == 3){
			input(pisah,hijau);
		}
		else if(pisah->priority == 4){
			input(pisah,hitam);
		}
		pisah = pisah->next;
	}
}

