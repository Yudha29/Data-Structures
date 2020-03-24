#include <iostream>
#include <stdlib.h>

struct Node {
	int data;
	Node* next;
};

Node* head = NULL, * ptr = NULL;

bool isEmpty() {
	if (head == NULL)
		return true;

	return false;
}

void push(int element) {
	ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr->data = element;
	ptr->next = head;
	head = ptr;
}

int pop() {
	if (isEmpty())
		return 0;

	int temp = head->data;

	ptr = head;
	head = head->next;

	delete ptr;

	return temp;
}

void clear() {
	while (!isEmpty())
		pop();
}

int topEl() {
	return head->data;
}

int main() {
	push(1);
	push(2);
	push(9);
	std::cout << topEl() << '\n';
	std::cout << pop() << '\n';
	std::cout << topEl() << '\n';
	push(3);
	std::cout << topEl() << '\n';

	return 0;
}
