#include <iostream>
#include <stdlib.h>

int pop();
int topEl();
void print();
void clear();
bool isFull();
bool isEmpty();
void printMenu();
void addToStack();
void push(int element);

const int maxSize = 20; //define the max size of stack
int stack[maxSize]; // define the array that we will use as stack
int size = 0, lastIndex = 0; //define the size and lastIndex of stack

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
		case 7:
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
	int temp = stack[lastIndex];

	size--; //deduct the size of stack by 1
	lastIndex--; //deduct the lastIndex to reference the previous cel

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

	return stack[lastIndex]; //otherwise return the top element of stack
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

bool isFull()
{
	//if size equal to maxsize then return true otherwise return false
	return size == maxSize;
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
	std::cout << "4. Bersihkanstack" << '\n';
	std::cout << "5. Cek apakah stack kosong" << '\n';
	std::cout << "6. Tampilkan isi stack" << '\n';
	std::cout << "0. Keluar" << '\n';
}

void addToStack()
{
	//while stack is not full then
	while (!isFull()) {
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
	//if stack is full
	if (isFull()) {
		//print message stack is full
		std::cout << "Stack penuh" << '\n';
	}
	else {
		if (!isEmpty())
			//add the index by 1 to reference to the next sel
			lastIndex++;
		else
			lastIndex = 0;

		//otherwise add element as top element of stack
		stack[lastIndex] = element;

		size++; //add size by 1
	}
}

