#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;


struct pasien{
	int cond[10], usia;
	int priority, id;
	string nama, gol_dar,alamat,riwayat;
	char jenis_klm;
	pasien *next;
};
class UGD{
	public :
		UGD();
		bool isFull(int , int);
		
		int decision(int, int, int);
		int pernapasan();
		int kondisiJantung();
		int tekananDarah();
		
		void deQueueCadangan();
		void deQueueCadangan(int );
		void deQueueWarna(int , int);
		void deQueue();
		void pisah();
		void inputManual();
		void inputFile();
		void inputMerah(pasien *);
		void inputKuning(pasien *);
		void inputHijau(pasien *);
		void inputHitam(pasien *);
		void backUpAntrian(pasien *);
		void cetak();
		void cetak(int );
		void cari(int );
		void rujuk(int );
		
	private :
		int maks, length, no;
		int lengthMerah, lengthKuning, lengthHijau, lengthHitam;
		int maksMerah, maksKuning, maksHijau, maksHitam;
		pasien *front;
		pasien *rear, *rearCadangan;
		pasien *merah, *kuning, *hijau, *hitam, *cadangan;
};

UGD::UGD(){
	front = rear = rearCadangan = NULL;
	merah = kuning = hijau = hitam = cadangan = NULL;
	maks = 8;
	length = lengthMerah= lengthKuning= lengthHijau= lengthHitam= 0;
	maksMerah = 3;
	maksKuning = 3;
	maksHijau = 5; 
	maksHitam = 3;
	no = 1;
}

void UGD::cari(int A) {
	pasien *print = cadangan;
	while(print != NULL) {
		if(print->id == A) {
			cout<<"=========================="<<endl;
			cout<<"Prioritas        : "<<print->priority<<endl;
			cout<<"ID Pasien        : "<<print->id<<endl;
			cout<<"Nama             : "<<print->nama<<endl;
			cout<<"Jenis Kelamin    : "<<print->jenis_klm<<endl;
			cout<<"Usia             : "<<print->usia<<endl;
			cout<<"Golongan Darah   : "<<print->gol_dar<<endl;
			cout<<"Riwayat Penyakit : "<<print->riwayat<<endl;
			break;
		}
		else if(print->next == NULL){
			cout<<"Pasien Tidak Ditemukan ";
		}
		print = print->next;
	}
}

void UGD::rujuk(int x){
	pasien *print = cadangan;
	while(print != NULL){
		if(print->id == x) {
			cout<<"=========================="<<endl;
			cout<<"Prioritas        : "<<print->priority<<endl;
			cout<<"ID Pasien        : "<<print->id<<endl;
			cout<<"Nama             : "<<print->nama<<endl;
			cout<<"Jenis Kelamin    : "<<print->jenis_klm<<endl;
			cout<<"Usia             : "<<print->usia<<endl;
			cout<<"Golongan Darah   : "<<print->gol_dar<<endl;
			cout<<"Riwayat Penyakit : "<<print->riwayat<<endl;
			
			deQueueCadangan(print->id);
			deQueueWarna(print->priority, print->id);
			break;
		}
		else if(print->next == NULL){
			cout<<"Pasien Tidak Ditemukan ";
		}
		print = print->next;
	}
	getch();
}

void UGD::deQueueWarna(int prioritas, int x){
	pasien *back = new pasien();
	
	if(prioritas == 1){
		pasien *print = merah;
		
		while (print != NULL){
			if(print->id == x){
				pasien *hapus = print;
				
				if(print == merah){
					merah = merah->next;
				}
				else if(print->next == NULL){
					back->next = NULL;
				}
				else{
					back->next = print->next;
				}
				
				lengthMerah--;				
				delete hapus;
				break;
			}		
			
			if(print->next != NULL && print->next->id == x){
				back = print;
			}
			print = print->next;
		}
	}
	else if(prioritas == 2){
		pasien *print = kuning;
		
		while (print != NULL){
			if(print->id == x){
				pasien *hapus = print;
				
				if(print == kuning){
					kuning = kuning->next;
				}
				else if(print->next == NULL){
					back->next = NULL;
				}
				else{
					back->next = print->next;
				}
				
				lengthKuning--;
				delete hapus;
				break;
			}		
			
			if(print->next != NULL && print->next->id == x){
				back = print;
			}
			print = print->next;
		}
	}
	else if(prioritas == 3){
		pasien *print = hijau;
		
		while (print != NULL){
			if(print->id == x){
				pasien *hapus = print;
				
				if(print == hijau){
					hijau = hijau->next;
				}
				else if(print->next == NULL){
					back->next = NULL;
				}
				else{
					back->next = print->next;
				}
				
				lengthHijau--;
				delete hapus;
				break;
			}		
			
			if(print->next != NULL && print->next->id == x){
				back = print;
			}
			print = print->next;
		}
	}
	else if(prioritas == 4){
		pasien *print = hitam;
		
		while (print != NULL){
			if(print->id == x){
				pasien *hapus = hitam;
				
				if(print == hitam){
					hitam = hitam->next;
				}
				else if(print->next == NULL){
					back->next = NULL;
				}
				else{
					back->next = print->next;
				}
				
				lengthHitam--;
				delete hapus;
				break;
			}		
			
			if(print->next != NULL && print->next->id == x){
				back = print;
			}
			print = print->next;
		}
	}	
}

void UGD::deQueueCadangan(int x){
	pasien *print = cadangan;
	pasien *back = new pasien();
	while (print != NULL){
		if(print->id == x){
			pasien *hapus = print;
			
			if(print == cadangan){
				cadangan = cadangan->next;
			}
			else if(print->next == NULL){
				back->next = NULL;
			}
			else{
				back->next = print->next;
			}
			
			delete hapus;
			break;
		}		
		
		if(print->next != NULL && print->next->id == x){
			back = print;
		}
		print = print->next;
	}
}

void UGD::deQueueCadangan(){
	pasien *hapus = cadangan;
	
	cadangan = cadangan->next;
	delete hapus;
}

void UGD::deQueue(){
	if(front != NULL && (merah == NULL && kuning == NULL && hijau == NULL && hitam == NULL)){
		pasien *hapus = front;
		
		front = front->next;
		
		delete hapus;
		length--;
		deQueueCadangan();
	}
	else if(front != NULL){
		pasien *hapus = front;
		
		front = front->next;
		length--;
		delete hapus;
	}
	else{
		pasien *hapus = new pasien();
		
		if(cadangan->priority == 1){
			lengthMerah--;
			hapus = merah;
			merah = merah->next;
			delete hapus;
		}
		else if(cadangan->priority == 2){
			lengthKuning--;
			hapus = kuning;
			kuning = kuning->next;
			delete hapus;
		}
		else if(cadangan->priority == 3){
			lengthHijau--;
			hapus = hijau;
			hijau = hijau->next;
			delete hapus;
		}
		else if(cadangan->priority == 4){
			lengthHitam--;
			hapus = hitam;
			hitam = hitam->next;
			delete hapus;
		}
		deQueueCadangan();
	}
}

bool UGD::isFull(int x, int y){
	if(x >= y){
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
				return 4;
			}
			
		}
		else{
			return 4;
		}
	}
}

void UGD::inputManual() {
	pasien *newNode = new pasien();
	
	if(!isFull(length, maks)){
		// hasil decision disimpan di prioritas untuk dibandingkan
		newNode->cond[0] = pernapasan();
		newNode->cond[1] = kondisiJantung();
		newNode->cond[2] = tekananDarah();		
		newNode->priority = decision(newNode->cond[0],newNode->cond[1],newNode->cond[2]);
		
		system("cls");
		cout<<" Prioritas Pasien Adalah : "<<newNode->priority<<endl;
		newNode->id = no;
		no++;
		cout<<" ID Pasien               : "<<newNode->id<<endl;
		
		cin.ignore();
		cout<<" Masukkan Nama Pasien    : ";
		getline(cin, newNode->nama);
		
		cout<<" Masukkan Jenis Kelamin (L/P) : ";
		cin>>newNode->jenis_klm;
		cout<<" Masukkan Usia Pasien    : ";
		cin>>newNode->usia;
		cout<<" Masukkan Golongan Darah : ";
		cin>>newNode->gol_dar;
		
		cin.ignore();
		cout<<" Masukkan Alamat Pasien  : ";
		getline(cin, newNode->alamat);
		cout<<" Masukkan Riwayat Penyakit    : ";
		getline(cin, newNode->riwayat);
		
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
		backUpAntrian(newNode);
	}
	else{
		cout<<"Antrian Data Penuh";
	}
}


void UGD::inputFile(){
	ifstream file;
	file.open("data.txt");
	
	if(!file.fail()){
		do{
			if(!isFull(length, maks)){
				pasien *newNode = new pasien();
				file>>newNode->priority;
				no++;
				file>>newNode->id;
				file.ignore();
				getline(file,newNode->nama);
				file>>newNode->jenis_klm;
				file>>newNode->usia;
				file>>newNode->gol_dar;
				file.ignore();
				getline(file, newNode->alamat);
				getline(file, newNode->riwayat);
				
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
				backUpAntrian(newNode);
			}
			else{
				cout<<"Antrian Data Penuh";
			}
		}while(!file.eof());
	}
	else{
		cout<<"File Tidak Ditemukan";
	}
}

void UGD::inputMerah(pasien *base){
	pasien *newNode = new pasien();
	if(!isFull(lengthMerah, maksMerah)){		
		for(int i = 0; i < 3; i++){
			newNode->cond[i] = base->cond[i];
		}
		
		newNode->priority = base->priority;
		newNode->id = base->id;
		newNode->nama = base->nama;
		newNode->jenis_klm = base->jenis_klm;
		newNode->usia = base->usia;
		newNode->gol_dar = base->gol_dar;
		newNode->alamat = base->alamat;
		newNode->riwayat = base->riwayat;
		newNode->next = NULL;
	
		if (merah == NULL){
			merah= newNode;
			merah->next = NULL;
		}
		else if(merah->priority > newNode->priority){
			newNode->next = merah;
			merah = newNode;
		}
		else{
			pasien *temp = merah;
	
		    while (temp->next != NULL && temp->next->priority <= newNode->priority) {
		        temp = temp->next;
		    }
		    
			temp->next = newNode;
		}
		lengthMerah++;
	}
	else{
		cout<<"Antrian Ruang Merah Penuh";
		getch();
	}
}

void UGD::inputKuning(pasien *base){
	pasien *newNode = new pasien();
	if(!isFull(lengthKuning, maksKuning)){
		for(int i = 0; i < 3; i++){
			newNode->cond[i] = base->cond[i];
		}
		
		newNode->priority = base->priority;
		newNode->id = base->id;
		newNode->nama = base->nama;
		newNode->jenis_klm = base->jenis_klm;
		newNode->usia = base->usia;
		newNode->gol_dar = base->gol_dar;
		newNode->alamat = base->alamat;
		newNode->riwayat = base->riwayat;
		newNode->next = NULL;
	
		if (kuning == NULL){
			kuning= newNode;
		}
		else if(kuning->priority > newNode->priority){
			newNode->next = kuning;
			kuning = newNode;
		}
		else{
			pasien *temp = kuning;
	
		    while (temp->next != NULL && temp->next->priority <= newNode->priority) {
		        temp = temp->next;
		    }
		    
			temp->next = newNode;
		}
		lengthKuning++;
	}
	else{
		cout<<"Antrian Ruang Kuning Penuh";
		getch();
	}
}
void UGD::inputHijau(pasien *base){
	pasien *newNode = new pasien();
	if(!isFull(lengthHijau, maksHijau)){
		for(int i = 0; i < 3; i++){
			newNode->cond[i] = base->cond[i];
		}
		
		newNode->priority = base->priority;
		newNode->id = base->id;
		newNode->nama = base->nama;
		newNode->jenis_klm = base->jenis_klm;
		newNode->usia = base->usia;
		newNode->gol_dar = base->gol_dar;
		newNode->alamat = base->alamat;
		newNode->riwayat = base->riwayat;
		newNode->next = NULL;
		if (hijau == NULL){
			hijau= newNode;
		}
		else if(hijau->priority > newNode->priority){
			newNode->next = hijau;
			hijau = newNode;
		}
		else{
			pasien *temp = hijau;
	
		    while (temp->next != NULL && temp->next->priority <= newNode->priority) {
		        temp = temp->next;
		    }
		    
			temp->next = newNode;
		}
		lengthHijau++;
	}
	else{
		cout<<"Antrian Ruang Hijau Penuh";
		getch();
	}
}
void UGD::inputHitam(pasien *base){
	pasien *newNode = new pasien();
	
	if(!isFull(lengthHitam, maksHitam)){
		for(int i = 0; i < 3; i++){
			newNode->cond[i] = base->cond[i];
		}
		
		newNode->priority = base->priority;
		newNode->id = base->id;
		newNode->nama = base->nama;
		newNode->jenis_klm = base->jenis_klm;
		newNode->usia = base->usia;
		newNode->gol_dar = base->gol_dar;
		newNode->alamat = base->alamat;
		newNode->riwayat = base->riwayat;
		newNode->next = NULL;
		if (hitam == NULL){
			hitam= newNode;
		}
		else if(hitam->priority > newNode->priority){
			newNode->next = hitam;
			hitam = newNode;
		}
		else{
			pasien *temp = hitam;
	
		    while (temp->next != NULL && temp->next->priority <= newNode->priority) {
		        temp = temp->next;
		    }
		    
			temp->next = newNode;
		}
		lengthHitam++;
	}
	else{
		cout<<"Antrian Ruang Hitam Penuh";
		getch();
	}
}

void UGD::backUpAntrian(pasien *base){
	pasien *newNode = new pasien();
	
	for(int i = 0; i < 3; i++){
		newNode->cond[i] = base->cond[i];
	}
	
	newNode->priority = base->priority;
	newNode->id = base->id;
	newNode->nama = base->nama;
	newNode->jenis_klm = base->jenis_klm;
	newNode->usia = base->usia;
	newNode->gol_dar = base->gol_dar;
	newNode->alamat = base->alamat;
	newNode->riwayat = base->riwayat;
	newNode->next = NULL;
	
		if (cadangan == NULL){
			cadangan= newNode;
			rearCadangan = newNode;
			rearCadangan->next = NULL;
		}
		else if(cadangan->priority > newNode->priority){
			newNode->next = cadangan;
			cadangan = newNode;
		}
		else{
			pasien *temp = cadangan;
	
		    while (temp->next != NULL && temp->next->priority <= newNode->priority) {
		        temp = temp->next;
		    }
		    
		    if(temp != rearCadangan){
		    	newNode->next = temp->next;
		    	temp->next = newNode;
			}
			else{
				temp->next = newNode;
				rearCadangan = newNode;
				rearCadangan->next = NULL;
			}
		}
}
void UGD::cetak(){
	pasien *print = cadangan;
	
	system("cls");
	cout<<"================================"<<endl;
	cout<<"           ANTRIAN PASIEN "<<endl;
	while(print != NULL){
		cout<<"================================"<<endl;
		cout<<"Prioritas        : "<<print->priority<<endl;
		cout<<"ID Pasien        : "<<print->id<<endl;
		cout<<"Nama             : "<<print->nama<<endl;
		cout<<"Jenis Kelamin    : "<<print->jenis_klm<<endl;
		cout<<"Usia             : "<<print->usia<<endl;
		cout<<"Golongan Darah   : "<<print->gol_dar<<endl;
		cout<<"Riwayat Penyakit : "<<print->riwayat<<endl;
		
		print = print->next;
	}
	
	getch();
}

void UGD::cetak(int x){
	switch (x){
		case 2 :{
			pasien *print = merah;
	
			system("cls");
			cout<<"================================"<<endl;
			cout<<"           ANTRIAN MERAH "<<endl;
			while(print != NULL){
				cout<<"================================"<<endl;
				cout<<"Prioritas        : "<<print->priority<<endl;
				cout<<"ID Pasien        : "<<print->id<<endl;
				cout<<"Nama             : "<<print->nama<<endl;
				cout<<"Jenis Kelamin    : "<<print->jenis_klm<<endl;
				cout<<"Usia             : "<<print->usia<<endl;
				cout<<"Golongan Darah   : "<<print->gol_dar<<endl;
				cout<<"Riwayat Penyakit : "<<print->riwayat<<endl;
				
				print = print->next;
			}
			
			getch();
			break;
		}
		case 3 :{
			pasien *print = kuning;
	
			system("cls");
			cout<<"================================"<<endl;
			cout<<"           ANTRIAN KUNING "<<endl;
			while(print != NULL){
				cout<<"================================"<<endl;
				cout<<"Prioritas        : "<<print->priority<<endl;
				cout<<"ID Pasien        : "<<print->id<<endl;
				cout<<"Nama             : "<<print->nama<<endl;
				cout<<"Jenis Kelamin    : "<<print->jenis_klm<<endl;
				cout<<"Usia             : "<<print->usia<<endl;
				cout<<"Golongan Darah   : "<<print->gol_dar<<endl;
				cout<<"Riwayat Penyakit : "<<print->riwayat<<endl;
				print = print->next;
			}
			
			getch();
			break;
		}
		case 4 :{
			pasien *print = hijau;
	
			system("cls");
			cout<<"================================"<<endl;
			cout<<"           ANTRIAN HIJAU "<<endl;
			while(print != NULL){
				cout<<"================================"<<endl;
				cout<<"Prioritas        : "<<print->priority<<endl;
				cout<<"ID Pasien        : "<<print->id<<endl;
				cout<<"Nama             : "<<print->nama<<endl;
				cout<<"Jenis Kelamin    : "<<print->jenis_klm<<endl;
				cout<<"Usia             : "<<print->usia<<endl;
				cout<<"Golongan Darah   : "<<print->gol_dar<<endl;
				cout<<"Riwayat Penyakit : "<<print->riwayat<<endl;
				
				print = print->next;
			}
			
			getch();
			break;
		}
		case 5 :{
			pasien *print = hitam;
	
			system("cls");
			cout<<"================================"<<endl;
			cout<<"           ANTRIAN HITAM "<<endl;
			while(print != NULL){
				cout<<"================================"<<endl;
				cout<<"Prioritas        : "<<print->priority<<endl;
				cout<<"ID Pasien        : "<<print->id<<endl;
				cout<<"Nama             : "<<print->nama<<endl;
				cout<<"Jenis Kelamin    : "<<print->jenis_klm<<endl;
				cout<<"Usia             : "<<print->usia<<endl;
				cout<<"Golongan Darah   : "<<print->gol_dar<<endl;
				cout<<"Riwayat Penyakit : "<<print->riwayat<<endl;
				
				print = print->next;
			}
			
			getch();
			break;
		}
	}
}

void UGD::pisah(){
	pasien *jalan = front;
	
	while(jalan != NULL){
		if(jalan->priority == 1){
			inputMerah(jalan);
		}
		else if(jalan->priority == 2){
			inputKuning(jalan);
		}
		else if(jalan->priority == 3){
			inputHijau(jalan);
		}
		else if(jalan->priority == 4){
			inputHitam(jalan);
		}
		jalan = jalan->next;
		deQueue();
	}
}


