#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Node {
	char data[10];
	struct Node * next;
};

struct Node * head = NULL, * ptr = NULL;
int main() {
	
	int i = 0;
	do {
		char input[10];
		
		cout << "Input Data " << i << " : ";
		gets(input);
		
		if (strlen(input) == 0)
			break;
		
		struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
		strcpy(temp->data, input);
		temp->next = NULL;
		
		if (head == NULL) {
			head = temp;
			
			ptr = head;
		} else {
			ptr->next = temp;

			ptr = ptr->next;
		}
		
		i++;
	} while (true);
	
	ptr = head;
	cout << "\n\nUnsorted Linked List : \n\n";
	
	do {
		cout << "[" << ptr->data << "] --> alamatnya " << ptr << " --> next ptr " << ptr->next << "\n";
		ptr = ptr->next;
	} while (ptr != NULL);
	
	ptr = head;
	while (ptr != NULL) {
		struct Node * helperPtr = ptr; 
		
		while (helperPtr != NULL && helperPtr->next != NULL) {
			if (strcmp(helperPtr->data, helperPtr->next->data) > 0) {
				char temp[10] = "";
				strcpy(temp, helperPtr->data);
				
				strcpy(helperPtr->data,helperPtr->next->data);
				strcpy(helperPtr->next->data, temp);
			}
			
			helperPtr = helperPtr->next;
		}
		
		ptr = ptr->next;
	}
	
	ptr = head;
	cout << "\n\nSorted Linked List : \n\n";
	do {
		cout << "[" << ptr->data << "] --> alamatnya " << ptr << " --> next ptr " << ptr->next << "\n";
		ptr = ptr->next;
	} while (ptr != NULL);
	
	return 0;
}
