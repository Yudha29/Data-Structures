#include <iostream.h>
#include <conio.h>

int stack[40]; //inisialisasi array untuk stack
int index; //variable untuk menampung index dari element teratas
int size = 0; //variable untuk menampung size dari array

//cek apakah array kosong
bool isEmpty() {
	//jika size == 0 maka berarti kosong
	if (size == 0)
		return true;
		
	//jika tidak maka tidak kosong
	return false;
}

//tambah data ke dalam array
void push(int element) {
	if (isEmpty())
		//jika array kosong set index jadi 0 untuk memasukan pada sel pertama
		index = 0;
	else
		//jika tidak maka increment untuk menunjuk sel setelah sel yang berisi data teratas
		index++;

	//isi data nya ke sel yang telah ditunjuk index
	stack[index] = element;
	size++;
}

//untuk mengeluarkan element teratas pada stack
int pop() {
	if (isEmpty())
		//jika stack kosong return false artinya tidak dapat push
		return false;
	
	//simpan data yang ada
	int temp = stack[index];
	index--;
	size--; //turunkan jumlah size

	//return data teratas
	return temp;
}

//untuk bersihkan stack
void clear() {
	//selama stack belum kosong maka terus pop untuk keluarkan datanya
	while (!isEmpty())
		pop();
}

//untuk mendapat element teratas tanpa menghapus
int topEl() {
	//keluarkan element teratas pada stack
	return stack[index];
}

int main() {
	push(1); //masukan 1 ke stack
	push(2); //masukan 2 ke stack
	push(9); //masukan 9 ke stack
	cout << topEl() << '\n'; //dapatkan element teratas dari stack
	cout << pop() << '\n'; //keluarkan element teratas pada stack
	cout << topEl() << '\n'; //dapatkan element teratas dari stack
	push(3); //masukan 3 ke stack
	cout << topEl() << '\n'; //dapatkan element teratas dari stack

	getch();

	return 0;
}