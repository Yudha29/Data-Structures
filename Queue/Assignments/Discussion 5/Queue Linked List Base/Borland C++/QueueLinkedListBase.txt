#include <iostream>
#include <stdlib.h>

void print();
void clear();
int firstEl();
int dequeue();
bool isEmpty();
void printMenu();
void addToQueue();
void enqueue(int element);

struct Node {
	int data;
	Node* next;
};

Node* head = NULL, *tail = NULL, *ptr = NULL;
int size = 0;

void print()
{
	int i = 1, currentSize = size;
	while (i <= currentSize) {
		const int element = dequeue();
		cout << "|\t" << element << "\t|" << '\n';

		enqueue(element);

		i++;
	}
}

void clear()
{
	//while queue is not empty
	while (!isEmpty())
		//dequeue element from queue until queue empty
		dequeue();

	//after empty print message
	cout << "Queue telah dibersihkan" << '\n';
}

int firstEl()
{
	if (isEmpty()) {
		cout << "queue Kosong" << '\n';
		return 0;
	}
	return head->data;
}

int dequeue()
{
	//if queue is empty
	if (isEmpty()) {
		//print message that says queue empty
		cout << "Queue kosong" << '\n';
		return 0;
	}
	int temp = head->data;
	//set ptr equal to head
	ptr = head;
	
	//if next element of head is exists
	if (head->next != NULL)
		//move head to the next element
		head = head->next;
	else {
		head = NULL;
		tail = NULL;
	}

	//destroy node at ptr
	delete ptr;

	size--; //decreased size by 1

	//return the data
	return temp;
}

void enqueue(int element)
{
	if (isEmpty()) {
		//alloc memory to save the struct
		head = (Node*)malloc(sizeof(Node));
		//set the next of this element to null
		head->next = NULL;
		//set the data of the node
		head->data = element;
		//set the tail equal to height because now we just have one element
		tail = head;
	}
	else {
		//alloc memory to the next element after tail
		tail->next = (Node*)malloc(sizeof(Node));
		//set the next to null
		tail->next->next = NULL;
		//set data
		tail->next->data = element;

		tail = tail->next; //set tail to latest element
	}

	size++; //increase the size by 1
}

bool isEmpty()
{
	return size == 0;
}

void printMenu()
{
	cout << "1. Tambah data ke queue" << '\n';
	cout << "2. Keluarkan data pertama dari queue" << '\n';
	cout << "3. Tampilkan data pertama pada queue" << '\n';
	cout << "4. Bersihkan queue" << '\n';
	cout << "5. Cek apakah queue kosong" << '\n';
	cout << "6. Tampilkan isi queue" << '\n';
	cout << "0. Keluar" << '\n';
}

void addToQueue()
{
	//while queue is not full then
	while (true) {
		//initialise variable to hold inputted data
		int tempData = 0;
		//print message
		cout << "Input data ke " << size + 1 << " : ";
		//input data
		cin >> tempData;

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
		cout << "Pilihan anda : ";
		cin >> menu;

		switch (menu) {
		case 1:
			addToQueue();
			break;
		case 2:
			cout << "Data yang di pop : " << dequeue() << '\n';
			break;
		case 3:
			cout << "Data teratas pada queue : " << firstEl() << '\n';
			break;
		case 4:
			clear();
			break;
		case 5:
			cout << (isEmpty() ? "queue kosong" : "queue tidak kosong") << '\n';
			break;
		case 6:
			if (isEmpty())
				cout << "queue kosong" << '\n';
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