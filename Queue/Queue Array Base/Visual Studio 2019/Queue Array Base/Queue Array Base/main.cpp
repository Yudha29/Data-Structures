#include <iostream>
#include <array>

//alokasi array untuk queue
std::array<int, 40> queue;
/*
	firstIndex = index dari elemen pertama pada queue
	lastIndex = index dari elemen terakhir pada queue
	size = size dari queue
*/
int firstIndex = 0, lastIndex = 0, size = 0;

//check queue empty or not
bool isEmpty() {
	//if size == 0 then return true it means the stack is empty
	if (size == 0)
		return true;

	//otherwise return false, it means stack is not empty
	return false;
}

//masukan element sebagai element terakhir
void enqueue(int element) {
	if (!isEmpty())
		//jika queue tidak kosong maka set index untuk menunjuk sel setelah sel dimana element terakhir berada
		lastIndex++;

	//set data pada element terakhir pada queue
	queue[lastIndex] = element;

	size++; //tingkatkan jumlah size
}

//keluarkan element pertama
int dequeue() {
	//simpan data tempnya
	int temp = queue[firstIndex];
	firstIndex++; //increment first indexnya untuk menunjuk sel yang berisi data setelahnya
	size--; //kurangkan jumlah size
	//output datanya
	return temp;
}

//dapatkan element pertama dalam queue tanpa hapus
int firstEl() {
	return queue[firstIndex];
}

void clear() {
	//selama queue tidak kosong maka dequeue()
	while (!isEmpty())
		dequeue();
	firstIndex = 0;
	lastIndex = 0;
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