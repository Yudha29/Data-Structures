#include <iostream>
#include <stdlib.h>

//inisialisasi struct
struct Node {
	int data;
	Node* next;
};

//buat variable head dan ptr
Node* head = NULL, * ptr = NULL;

//cek apakah stack kosong
bool isEmpty() {
	//jika head == null maka stack kosong
	if (head == NULL)
		return true;

	//jika head != null maka stack tidak kosong
	return false;
}

//tambah elemen sebagai elemen teratas pada stack
void push(int element) {
	//alokasi memori untuk buat node baru
	ptr = (struct Node *)malloc(sizeof(struct Node));
	//set datanya
	ptr->data = element;
	//buat next elemen dari node tersebut jadi head
	ptr->next = head;
	//ubah posisi head ke node yang baru
	head = ptr;
}

//keluarkan element teratas pada stack
int pop() {
	//jika stack kosong
	if (isEmpty())
		//return 0 berarti false tidak bisa pop()
		return 0;

	//simpan data yang ada di head
	int temp = head->data;

	//set ptr sebagai head
	ptr = head;
	//set head sebagai elemen setelah head
	head = head->next;

	//delete ptr
	delete ptr;

	//keluarkan data tempnya
	return temp;
}

//bersihkan stack
void clear() {
	//selama stack tidak kosong maka pop()
	while (!isEmpty())
		pop();
}

//dapatkan elemen teratas pada stack tanpa menghapus
int topEl() {
	return head->data;
}

int main() {
	push(1);
	std::cout << "push(1)" << '\n';
	push(2);
	std::cout << "push(2)" << '\n';
	push(9);
	std::cout << "push(9) " << '\n';
	std::cout << "topEl() " << topEl() << '\n';
	std::cout << "pop() " << pop() << '\n';
	std::cout << "topEl() " << topEl() << '\n';
	clear();
	std::cout << "clear() " << '\n';
	std::cout << "isEmpty() " << (isEmpty() ? "Ya" : "tidak") << '\n';
	push(3);
	std::cout << "push(3) " << '\n';
	std::cout << "isEmpty() " << (isEmpty() ? "Ya" : "tidak") << '\n';
	std::cout << "topEl() " << topEl() << '\n';

	return 0;
}