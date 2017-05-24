// ¹®Á¦ : https://www.acmicpc.net/problem/10866
//
#include <iostream>
#include <string>

using namespace std;

struct deque {
	int data[100000];
	int front = -1, back = -1;
}deque;

bool empty() {
	if (deque.back - deque.front + 1 > 0 && deque.front != -1 && deque.back != -1) return false;
	return true;
}

void push_front(int number) {
	if (deque.front == -1) {
		deque.back = deque.front = 49999;
		deque.data[deque.front] = number;
	}else deque.data[--deque.front] = number;
}

int pop_front() {
	if (!empty()) return deque.data[deque.front++];
	return -1;
}

void push_back(int number) {
	if (deque.front == -1) {
		deque.back = deque.front = 49999;
		deque.data[deque.back] = number;
	}else deque.data[++deque.back] = number;
}

int pop_back() {
	if (!empty()) return deque.data[deque.back--];
	return -1;
}

int front() {
	if (!empty()) return deque.data[deque.front];
	return -1;
}

int back() {
	if (!empty()) return deque.data[deque.back];
	return -1;
}

int size() {
	if (!empty()) return deque.back - deque.front + 1;
	return 0;
}

int main() {
	int num, temp;
	string cmd, result = "";

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> cmd;

		if (cmd == "push_front") {
			cin >> temp;
			push_front(temp);
			continue;
		}
		else if (cmd == "pop_front") result += to_string(pop_front());
		else if (cmd == "push_back") {
			cin >> temp;
			push_back(temp);
			continue;
		}
		else if (cmd == "pop_back") result += to_string(pop_back());
		else if (cmd == "size") result += to_string(size());
		else if (cmd == "empty") empty() ? result += "1" : result += "0";
		else if (cmd == "front") result += to_string(front());
		else if (cmd == "back") result += to_string(back());
		result += "\n";
	}

	cout << result;
	cout << "";

	return 1;
}