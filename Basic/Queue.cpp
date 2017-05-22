// 巩力 : https://www.acmicpc.net/problem/10845
// queue甫 流立 备泅
#include <iostream>
#include <string>

using namespace std;

struct queue {
	int data[100000];
	int front = -1, back = -1;
}Q;

bool empty() {
	if (Q.back - Q.front + 1 > 0 && Q.front != -1 && Q.back != -1) return false;
	return true;
}

void push(int number) {
	if (Q.front == -1) Q.front++;
	Q.data[++Q.back] = number;
}

int pop() {
	if (!empty()) return Q.data[Q.front++];
	return -1;
}

int front() {
	if (!empty()) return Q.data[Q.front];
	return -1;
}

int back() {
	if (!empty()) return Q.data[Q.back];
	return -1;
}

int size() {
	if (!empty()) return Q.back - Q.front + 1;
	return 0;
}

int main() {
	int num, temp;
	string cmd, result = "";

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> cmd;

		if (cmd == "push") {
			cin >> temp;
			push(temp);
			continue;
		}
		else if (cmd == "pop") result += to_string(pop());
		else if (cmd == "size") result += to_string(size());
		else if (cmd == "empty") empty() ? result += "1": result += "0";
		else if (cmd == "front") result += to_string(front());
		else if (cmd == "back") result += to_string(back());
		result += "\n";
	}

	cout << result;
	cout << "";

	return 1;
}