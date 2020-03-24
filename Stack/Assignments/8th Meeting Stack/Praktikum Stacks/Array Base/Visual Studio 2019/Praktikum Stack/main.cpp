#include <iostream>
#include <array>

std::array<int, 20> stack;
int lastIndex = 0;
int size = 0;

bool isEmpty() {
	if (size == 0)
		return true;

	return false;
}

bool isFull() {
	if (size == stack.size())
		return true;

	return false;
}

int peek() {
	return stack[lastIndex - 1];
}

int pop() {
	lastIndex--;
	size--;

	int temp = stack[lastIndex];

	return temp;
}

void push(int element) {
	stack[lastIndex] = element;

	lastIndex++;
	size++;
}

void print() {
	int temp = pop();

	std::cout << temp << '\n';

	if (!isEmpty())
		print();

	push(temp);
}

void clear() {
	if (!isEmpty()) {
		pop();
		clear();
	}
}

void pushToStack() {
	std::cout << "Input Data, Untuk mengakhiri isi 0 \n";

	int tempData;
	int i = 1;
	do {
		std::cout << "Input Data ke " << i << " :";

		std::cin >> tempData;

		if (!isFull() && tempData) {
			push(tempData);
		} else if (!tempData) {
			break;
		} else {
			std::cout << "Stack penuh\n";
		}

		i++;
	} while (true);
}

void printMenu() {
	std::cout << "Menu\n";
	std::cout << "1. Tambah data ke stacks\n";
	std::cout << "2. Keluarkan data dari stacks\n";
	std::cout << "3. Tampilkan data teratas dari stacks\n";
	std::cout << "4. Bersihkan stacks\n";
	std::cout << "5. Check stacks apakah stacks kosong\n";
	std::cout << "6. Tampilkan isi stack\n";
	std::cout << "0. Keluar\n";
}

int main() {
	do {
		system("cls");
		printMenu();

		int selected;

		std::cout << "Pilihan anda : ";
		std::cin >> selected;

		switch (selected)
		{
		case 1:
			pushToStack();
			break;
		case 2:
			std::cout << "Data yang dikeluarkan : " << pop() << "\n";
			break;
		case 3:
			std::cout << "Data teratas pada stack : " << peek() << "\n";
			break;
		case 4:
			clear();
			std::cout << "Stack telah dibersihkan\n";
			break;
		case 5:
			if (isEmpty())
				std::cout << "Stack kosong\n";
			else
				std::cout << "Stack tidak kosong\n";
			break;
		case 6:
			if (!isEmpty())
				print();
			else
				std::cout << "Stack kosong\n";
			break;
		case 0:
			exit(0);
			break;
		}
		system("pause");
		
	} while (true);

	return 0;
}