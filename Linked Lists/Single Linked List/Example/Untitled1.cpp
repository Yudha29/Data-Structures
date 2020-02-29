#include <iostream>

using namespace std;

main() {
	struct Node {
		int data;
	};
	
	Node * test = new Node;
	test->data = 10;
	
	cout << test;
	
	return 0;
}
