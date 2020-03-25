#include <iostream>
#include <array>
#include <stdlib.h>

void print();
void clear();
int firstEl();
int dequeue();
bool isFull();
bool isEmpty();
void printMenu();
void addToQueue();
int getNextIndex(int index);
void enqueue(int element);

const int maxSize = 10;
std::array<int, maxSize> queue;
int size = 0, lastIndex = 0, firstIndex = 0;

void print()
{
	int i = 1, currentSize = size;
	while (i <= currentSize) {
		int index = firstIndex;
		const int element = dequeue();
		std::cout << "data ke " << i << " pool[ " << index << " ] |\t" << element << "\t|" << '\n';

		enqueue(element);

		i++;
	}
}

void clear()
{
	//while queue is not empty
	while (!isEmpty()) {
		//dequeue element from queue until queue empty
		dequeue();
		firstIndex = 0;
		lastIndex = 0;
	}

	//after empty print message
	std::cout << "Queue telah dibersihkan" << '\n';
}

int firstEl()
{
	if (isEmpty()) {
		std::cout << "queue Kosong" << '\n';
		return 0;
	}

	return queue[firstIndex];
}

int dequeue()
{
	//if queue is empty
	if (isEmpty()) {
		//print message that says queue empty
		std::cout << "Queue kosong" << '\n';

		return 0;
	}
	int temp = queue[firstIndex];
	
	firstIndex = getNextIndex(firstIndex);
	size--;

	//return the data
	return temp;
}

int getNextIndex(int index) {
	//if the size is greater than the maxSize
	if (index >= maxSize - 1) {
		//return 0 means the first element of array
		return 0;
	}

	//otherwise return the next element
	return index + 1;
}

void enqueue(int element)
{
	//check is the queue full
	if (!isFull()) {
		//if not increase the last index
		if (!isEmpty())
			//get the next Index
			lastIndex = getNextIndex(lastIndex);
		else
			//set last index to 0
			lastIndex = 0;

		//set the data
		queue[lastIndex] = element;

		size++; //increase the size by 1
	}
	else {
		std::cout << "Queue is Full" << '\n'; // print message
	}
}


bool isEmpty()
{
	return size == 0;
}

bool isFull() {
	//if the size is not equal to 0 and the next last index equal to the index of first element
	return size != 0 && getNextIndex(lastIndex) == firstIndex;
}

void printMenu()
{
	std::cout << "1. Tambah data ke queue" << '\n';
	std::cout << "2. Keluarkan data pertama dari queue" << '\n';
	std::cout << "3. Tampilkan data pertama pada queue" << '\n';
	std::cout << "4. Bersihkan queue" << '\n';
	std::cout << "5. Cek apakah queue kosong" << '\n';
	std::cout << "6. Tampilkan isi queue" << '\n';
	std::cout << "0. Keluar" << '\n';
}

void addToQueue()
{
	//while queue is not full then
	while (!isFull()) {
		//initialise variable to hold inputted data
		int tempData = 0;
		//print message
		std::cout << "Input data ke " << size + 1 << " pool [" << (isEmpty() ? 0 : getNextIndex(lastIndex)) << "] " << " : ";
		//input data
		std::cin >> tempData;

		//if inputted data is 0
		if (tempData == 0) break;

		//push data to queue
		enqueue(tempData);
	}
}

int main()
{
	do {
		int menu;

		printMenu();
		std::cout << "Pilihan anda : ";
		std::cin >> menu;

		switch (menu) {
		case 1:
			addToQueue();
			break;
		case 2:
			std::cout << "Data yang di pop : " << dequeue() << '\n';
			break;
		case 3:
			std::cout << "Data teratas pada queue : " << firstEl() << '\n';
			break;
		case 4:
			clear();
			break;
		case 5:
			std::cout << (isEmpty() ? "queue kosong" : "queue tidak kosong") << '\n';
			break;
		case 6:
			if (isEmpty())
				std::cout << "queue kosong" << '\n';
			else
				print();
			break;
		case 0:
			exit(0);
			break;
		}
		system("pause");
		system("cls");
	} while (true);


	return 0;
}