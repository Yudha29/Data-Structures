#include <iostream>
#include <string.h>

using namespace std;

/*define struct node that has two attribute
 * data
 * next = next mengacu pada elemen selanjutnya dalam linked list
*/
struct Node {
	char data[10];
	Node * next;
};

/*
 * head = mengacu pada element pertama dalam linked list
 * ptr = adalah variable yang digunakan untuk mengakses elemen elemen dalam linked list
 * tail = mengacu pada element terakhir dalam linked list
*/
Node * head = NULL, * ptr = NULL, * tail = NULL;

//procedure ini digunakan untuk input tiap elemen linked list satu persatu
void fillLinkedList() {	
	cout << "Input data (input string kosong untuk berhenti)" << '\n';
	
	for (int i=1;;i++) {
		//tempString untuk menyimpan text yang akan di masukan ke sebagai data dalam elemen linked list
		char tempString[10] = "";
		
		//meminta inputan untuk memasukan data
		cout << "Enter text : ";
		cin.getline(tempString, 9);
		
		//cek apakah text yang dimasukan tidak kosong apabila kosong maka program akan break
		//dan berhenti meminta inputan
		if (strlen(tempString) == 0) break;
		
		//mendefinisikan sebuah node, new Node mempunyai fungsi yang sama dengan malloc yaitu untuk melakukan
		//dynamic alocation memory
		Node * tempNode = new Node;
		//mengisi attribute data dalam tempNode dengan data yang telah di input(tempString)
		strcpy(tempNode->data, tempString);
		//set nilai selanjutnya setelah tempNode sebagai null
		tempNode->next = NULL;
		
		//cek apakah kita telah menginput data pada head
		if (head == NULL) {
			//jika belum maka kita akan jadikan tempNode sebagai head
			head = tempNode;
			
			//saat ini kita hanya punya satu element jadi tail dan head akan mengacu pada satu element yang sama
			tail = head;
		} else {
			//jika head telah di input maka kita akan menambahkan elemen baru sebagai elemen terakhir dalam linked list
			tail->next = tempNode;
			//lalu karena ini adalah elemen terakhir maka kita harus menjadikan tail sebagai tempNode
			tail = tempNode;
		}
	}
}

void insertString(char * outputText, string message) {
	do {
		//meminta inputan data
		cout << "\n" << message << " : ";
		cin.getline(outputText, 9);
		
		//jika data yang di input kosong maka munculkan pesan
		if (strlen(outputText) == 0) cout << "Mohon input textnya" << '\n';
		//selama data yang di input kosong maka program akan terus bertanya ulang sampai data nya benar
	} while (strlen(outputText) == 0);
}

//insert behind akan menambahkan sebuah elemen baru sebagai elemen terakhir dalam linked list
void insertBehind() {
//	char dataInput[10] = "";
//	
//	insertString(dataInput, "Masukan data yang ingin di input di bagian akhir");
//	
//	//membuat sebuah node baru
//	Node * tempNode = new Node;
//	//masukan atribute data dalam tempnode sebagai data yang di input
//	strcpy(tempNode->data, dataInput);
//	//karena insert behind akan menjadikan elemen yang di input sebagai elemen terakhir maka nextnya tidak mengacu ke manapun
//	//jadi set saja sebagai null
//	tempNode->next = NULL;
//	//karena elemen baru telah di tambahkan sebagai elemen terakhir maka ubah elemen terakhirnya jadi tempNode
//	tail->next = tempNode;
//	tail = tail->next;
	ptr = head;

	while (ptr != NULL && ptr->next != NULL) {
		ptr = ptr->next;
	}
	
	Node * temp = new Node;
	strcpy(temp->data, "test");
	temp->next = NULL;
	
	ptr->next = temp;
}

//insert top akan menambahkan sebuah elemen baru sebagai elemen pertama dalam linked list
void insertTop() {
	char dataInput[10] = "";
	
	//procedure untuk input data
	insertString(dataInput, "Masukan data yang ingin di input di bagian awal");
	
	//membuat sebuah node baru
	Node * tempNode = new Node;
	
	//masukan atribute data dalam tempnode sebagai data yang di input
	strcpy(tempNode->data, dataInput);
	//karena insert Top akan menjadikan elemen yang di input sebagai elemen pertama 
	//jadi head tidak akan lagi tapi data ke dua jadi next elemen dari tempNode akan menjadi head
	tempNode->next = head;
	//karena elemen baru telah di tambahkan sebagai elemen pertama maka ubah head jadi tempNode
	head = tempNode;
}

void menyisipData(Node * nodeYangKetemu) {
	char dataInput[10] = "";
	
	insertString(dataInput, "Masukan data yang ingin di sisipkan");
	
	//membuat sebuah node baru
	Node * tempNode = new Node;
	
	//masukan atribute data dalam tempnode sebagai data yang di input
	strcpy(tempNode->data, dataInput);
	//karena kita akan masukan data setelah node yang ketemu saat search
	//maka next dari tempNode adalah next dari node yang ditemukan
	tempNode->next = nodeYangKetemu->next;
	//lalu nilai next pada node yang ditemukan akan di ubah menjadi tempnode
	nodeYangKetemu->next = tempNode;
	
	//jika node yang ketemu adalah tail	
	if (nodeYangKetemu == tail) {
		//maka ubah tailnya menjadi tempnode karena sekarang tempnode akan menjadi elemen terakhir
		tail = tempNode;
	}
}

void search(bool sisipData) {
	//meminta inputan data apa yang ingin dicari
	char dataCari[10] = "";
	insertString(dataCari, "Masukan data yang ingin di dicari");
	
	//boolean untuk mewakili status apakah datanya ketemu atau tidak
	bool dataKetemu = false;
	
	//ptr digunakan untuk menjelahi seluruh elemen dalam linked list
	//ia harus mulai menjelajahi dari elemen pertama jadi harus di set terlebih dahulu sebagai elemen pertama
	ptr = head;
	do {
		//apabila data yang dicari ketemu
		if (strcmp(dataCari, ptr->data) == 0) {
			//data ditemukan print data tersebut
			cout << "Data " << ptr->data << " yang dicari berada pada alamat " << ptr << "\n";
		
			//data ketemu maka ubah status dataKetemu menjadi true
			dataKetemu = true;
			
			if (sisipData == true) {
				menyisipData(ptr);
				
				break;
			}
		}
		
		//ubah nilai ptr yang mewakili elemen saat ini sebagai elemen selanjutnya dalam linked list
		ptr = ptr->next;
	} while (ptr != NULL);
	
	//jika data tidak ketemu
	if (dataKetemu == false) {
		cout << "Data tidak ditemukan " << '\n';
	}
}

void print() {
	//ubah ptr yang akan loop seluruh elemen menjadi head
	ptr = head;
	
	cout << "\nList Data : \n";
	do {
		//print setiap data
		cout << "[\t" << ptr->data << "\t] --> alamatnya " << ptr << " --> next ptr " << ptr->next << '\n';
		
		//ubah ptr menjadi ptr->next untuk pergi ke elemen selanjutnya
		ptr = ptr->next;
	} while (ptr != NULL);
}

int main() {
	//isi data dalam linked list
	fillLinkedList();
	
	do {
		int menu = 0;
		//print semua data dalam linked list
		print();
		
		cout << "Menu : \n";
		cout << "1. Add Bottom\n";
		cout << "2. Add Top\n";
		cout << "3. Search\n";
		cout << "4. Search & Sisipkan\n";
		cout << "5. Keluar\n";
		
		cout << "Input Menu(1-4) : ";
		cin >> menu;
		
		if (cin.fail()) {
			cin.clear();
		}
		
		cin.ignore(32676, '\n');
		
		switch (menu) {
			case 1:
				//jika menu = 1 maka lakukan insert data sebagai element terakhir
				insertBehind();
				break;
			case 2:
				//jika menu = 2 maka lakukan insert data sebagai element pertama
				insertTop();
				break;
			case 3:
				//jika menu = 3 maka lakukan search data
				search(false);
				break;
			case 4:
				//jika menu = 4 maka sisipkan data setelah search
				search(true);
				break;
			case 5:
				//jika menu = 5 maka keluar dari program
				exit(0);
				break;
			default:
				//jika menu bukan 1,2,3,4,5 maka minta user peringatan
				cout << "Masukan menu dari (1-4)\n";
		}
	} while (true);
	
	return 0;
}
