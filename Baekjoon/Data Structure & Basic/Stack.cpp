#include <iostream>
#include <string>

using namespace std;

struct stack{
	int data[100000];
	int size = 0;
}stack;

bool empty() {
	if (stack.size == 0) return false;
	else return true;
}

void push(int num) {
	stack.data[stack.size++] = num;
}

void pop() {
	if (empty()) cout << stack.data[--stack.size] << "\n";
	else cout << "empty\n";
}

void top() {
	if (empty()) cout << stack.data[stack.size-1] << "\n";
	else cout << "empty\n";
}



int main() {

	
	string cmd;
	int num, temp;

	while (1) {
		cout << "Enter cmd (push, pop, top, empty, exit) ";
		cin >> cmd;

		if (cmd == "push") {
			cout << "number : ";
			cin >> num;
			push(num);
		}
		else if (cmd == "pop") {
			pop();
		}
		else if (cmd == "top") {
			top();
		}
		else if (cmd == "empty") {
			if (empty()) cout << "not empty\n";
			else cout << "empty\n";
		}
		else if (cmd == "exit") {
			break;
		}
		else {
			cout << "Check your cmd !\n";
		}
	}

	return 1;
}