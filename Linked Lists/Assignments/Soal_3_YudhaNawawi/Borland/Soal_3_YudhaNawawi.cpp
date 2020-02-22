#include <iostream>
#include <string.h>
#include <string>

struct Node {
	char data[10];
	Node * next;
};

Node * head = 0, * ptr = 0, * prevPtr = 0;
int length = 0;

void fill() {
	cout << "Input data (Input data kosong untuk berhenti)\n";
	for (int i=0;;i++) {
		char tempData[10] = "";
		cout << "Data ke " << (i + 1) << " : ";
		cin.getline(tempData, 9);
		
		if (strlen(tempData) == 0) break;
		
		Node * temp = new Node;
		strcpy(temp->data, tempData);
		temp->next = 0;
		
		if (head == 0) {
			head = temp;	
			ptr = head;
		} else {
			ptr->next = temp;
			ptr = ptr->next;	
		}
		length++;
	}
}

void print() {
	cout << "\nList Data : \n";
	ptr = head;
	do {
		cout << "[\t" << ptr->data << "\t] --> alamatnya " << ptr << " next ptr " << ptr->next << '\n';		
		ptr = ptr->next;	
	} while (ptr != 0);
}


void search() {
	bool exists = false;
	char tempData[10] = "";
	ptr = head;
	prevPtr = 0;
	
	cout << "\nInput data yang ingin di cari (input data kosong untuk keluar) : ";
	cin.getline(tempData, 9);
	
	if (strlen(tempData) == 0) exit(0);
	
	do {
		if (strcmp(tempData, ptr->data) == 0) {
			exists = true;
			cout << "Data yang dicari berada pada alamat " << ptr << '\n';
			
			Node * tempStruct = new Node;
			
			char tempString[10] = "";
			cout << "\nInput data yang ingin disisipkan (input data kosong untuk kembali ke search) : ";
			cin.getline(tempString, 9);
			
			if (strlen(tempString) == 0) break;
			
			strcpy(tempStruct->data, tempString);
			tempStruct->next = ptr;
	
			if (ptr == head) {
				head = tempStruct;
			} else {
				prevPtr->next = tempStruct;
			}
			
			print();
			length++;
			
			break;
		}
		
		prevPtr = ptr;
		ptr = ptr->next;
	} while (ptr != 0);
	
	if (!exists) cout << "Data tidak ditemukan \n";
}

int main() {
	fill();
	print();
	do {
		search();
	} while (true);
	return 0;
}
