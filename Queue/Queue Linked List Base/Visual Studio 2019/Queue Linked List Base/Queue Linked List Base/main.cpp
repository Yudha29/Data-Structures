#include <iostream>
#include <stdlib.h>

struct Node {
	int data;
	Node* next;
};

struct Node* head, * tail, * ptr;

//check queue empty or not
bool isEmpty() {
	//if head == null then return true it means the stack is empty
	if (head == NULL)
		return true;

	//otherwise return false, it means stack is not empty
	return false;
}

//masukan element sebagai element terakhir
void enqueue(int element) {
	if (isEmpty()) {
		//jika stack kosong maka alokasi memori untuk head
		head = (struct Node*)malloc(sizeof(struct Node));

		//set next dari head jadi null
		head->next = NULL;
		//buat tail dan head menjadi elemen yang sama
		tail = head;
	}
	else {
		//jika tidak kosong maka alokasi memori setelah tail
		tail->next = (struct Node*)malloc(sizeof(struct Node));
		//set next dari element setelah tail jadi null
		tail->next->next = NULL;
		//buat tail menjadi element yang terakhir di tambahkan
		tail = tail->next;
	}

	//isi data pada element terakhir
	tail->data = element;
}

//keluarkan element pertama
int dequeue() {
	//simpan data tempnya
	int temp = head->data;
	//set buat ptr berisi alamat memori yang sama dengan head
	ptr = head;
	//set head menjadi element setelah head
	head = head->next;
	//jika elemen setelah head adalah null berarti queue kosong
	if (isEmpty())
		//jika kosong maka set tail juga jadi null
		tail = NULL;

	//hapus data head yang lama yang tersimpan di dalam ptr
	delete ptr;

	//keluarkan datanya
	return temp;
}

//dapatkan element pertama dalam queue tanpa hapus
int firstEl() {
	return head->data;
}

void clear() {
	//selama queue tidak kosong maka dequeue()
	while (!isEmpty())
		dequeue();
}

int main() {
	enqueue(1);
	std::cout << "enqueue(1) " << '\n';
	enqueue(2);
	std::cout << "enqueue(2) " << '\n';
	enqueue(6);
	std::cout << "enqueue(6) " << '\n';
	std::cout << "dequeue() " << dequeue() << '\n';
	std::cout << "firstEl() " << firstEl() << '\n';
	clear();
	std::cout << "clear() " << '\n';
	enqueue(9);
	std::cout << "enqueue(9) " << '\n';
	std::cout << "firstEl() " << firstEl() << '\n';
	std::cout << "isEmpty() " << (isEmpty() ? "Ya" : "Tidak") << '\n';
	std::cout << "dequeue() " << dequeue() << '\n';
	std::cout << "isEmpty() " << (isEmpty() ? "Ya" : "Tidak") << '\n';
	system("pause");
}