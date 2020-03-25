#include <iostream>
#include <stdlib.h>

int pop();
int topEl();
void print();
void clear();
bool isEmpty();
void printMenu();
void addToStack();
void push(int element);

struct Node {
	int data;
	Node* next;
};

Node * head = NULL, * ptr = NULL;
int size = 0;

int main()
{
	do {
		int menu;

		printMenu();
		std::cout << "Pilihan anda : ";
		std::cin >> menu;

		switch (menu) {
		case 1:
			addToStack();
			break;
		case 2:
			std::cout << "Data yang di pop : " << pop() << '\n';
			break;
		case 3:
			std::cout << "Data teratas pada stack : " << topEl() << '\n';
			break;
		case 4:
			clear();
			break;
		case 5:
			std::cout << (isEmpty() ? "Stack kosong" : "Stack tidak kosong") << '\n';
			break;
		case 6:
			if (isEmpty())
				std::cout << "Stack kosong" << '\n';
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

int pop()
{
	//if stack empty
	if (isEmpty()) {
		std::cout << "Stack kosong" << '\n';
		//then return 0 it means cannot pop() becase the stack is empty
		return 0;
	}

	//otherwise save the top element of stack to variable
	int temp = head->data;

	ptr = head; //set ptr equal to head
	head = head->next; //move head to the next element
	delete ptr; //delete the ptr

	size--;

	return temp; //return the top data of stack
}

int topEl()
{
	//if the stack empty
	if (isEmpty()) {
		std::cout << "Stack kosong" << '\n';
		//then return 0 it means cannot get the top element becase the stack is empty
		return 0;
	}

	return head->data; //otherwise return the top element of stack
}

//recursion function
void print()
{
	//if stack is not empty
	if (!isEmpty()) {
		//pop element from stack
		int temp = pop();

		//print the element
		std::cout << "|\t" << temp << "\t|" << '\n';

		//call this function back
		print();

		//push back the element to stack
		push(temp);
	}
}

void clear()
{
	//if stack is not empty
	if (!isEmpty()) {
		//pop the element
		pop();

		//call this function again
		clear();
	}
	else {
		//otherwise print message that says the stack is empty now
		std::cout << "Stack telah Kosong" << '\n';
	}
}

bool isEmpty()
{
	//if size is equal to 0 then return false, otherwise return true
	return size == 0;
}

void printMenu()
{
	std::cout << "1. Tambah data ke stack" << '\n';
	std::cout << "2. Keluarkan data dari stack" << '\n';
	std::cout << "3. Tampilkan data teratas pada stack" << '\n';
	std::cout << "4. Bersihkan stack" << '\n';
	std::cout << "5. Cek apakah stack kosong" << '\n';
	std::cout << "6. Tampilkan isi stack" << '\n';
	std::cout << "0. Keluar" << '\n';
}

void addToStack()
{
	//while stack is not full then
	while (true) {
		//initialise variable to hold inputted data
		int tempData = 0;
		//print message
		std::cout << "Input data ke " << size + 1 << " : ";
		//input data
		std::cin >> tempData;

		//if inputted data is 0
		if (tempData == 0) break;

		//push data to stack
		push(tempData);
	}
}

void push(int element)
{
	//otherwise add element as top element of stack
	ptr = (Node*)malloc(sizeof(Node));
	//set the element
	ptr->data = element;
	//set the next equal to head
	ptr->next = head;
	//change head = ptr to make head as the first element
	head = ptr;

	size++; //add size by 1
}

