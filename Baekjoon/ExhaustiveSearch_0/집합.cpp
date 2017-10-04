// 문제 : https://www.acmicpc.net/problem/11723
// bitmask - 내 코드 시간초과 나는 이유를 잘 모르겠음;
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void add(int &, const int);
void remove(int &, const int);
bool check(const int, const int);
bool check_t(const int, const int);
void toggle(int &, const int);
void all(int &);
void empty(int &);

void add(int &s, const int v) {
	if (check_t(s,v)) {
		return;
	}
	s |= 1 << v;
}
void remove(int &s, const int v) {
	if (!check_t(s,v)) {
		return;
	}
	s &= ~(1 << v);
}
bool check(const int s, const int v) {
	if (s & (1 << v)) {
		printf("1\n");
		//cout << 1 << "\n";
		return true;
	}
	else {
		printf("0\n");
		//cout << 0 << "\n";
		return false;
	}
}
bool check_t(const int s, const int v) {
	if (s & (1 << v)) {
		return true;
	}
	else {
		return false;
	}
}
void toggle(int &s, const int v) {
	s ^= 1 << v;
}
void all(int &s) {
	s = (1 << 20) - 1;
}
void empty(int &s) {
	s = 0;
}

int main() {

	int M;
	
	cin >> M;

	int s = 0;
	string command;
	int value;
	for (int i = 0; i < M; i++) {
		cin >> command;
		if (command == "all" || command == "empty") {
			if (command == "all") all(s);
			else empty(s);
		}
		else {
			cin >> value;
			value--;
			if (command == "add") add(s, value);
			else if (command == "remove") remove(s, value);
			else if (command == "check") check(s, value);
			else toggle(s, value);
		}
	}

	return 1;
}

/*
#include <cstdio>
#include <cstring>
using namespace std;
char b[111];
int main() {
	int n = 20;
	int m;
	scanf("%d", &m);
	int s = 0;
	int x;
	while (m--) {
		scanf("%s", b);
		if (!strcmp(b, "add")) {
			scanf("%d", &x); x--;
			s = (s | (1 << x));
		}
		else if (!strcmp(b, "remove")) {
			scanf("%d", &x); x--;
			s = (s & ~(1 << x));
		}
		else if (!strcmp(b, "check")) {
			scanf("%d", &x); x--;
			int res = (s & (1 << x));
			if (res) {
				puts("1");
			}
			else {
				puts("0");
			}
		}
		else if (!strcmp(b, "toggle")) {
			scanf("%d", &x); x--;
			s = (s ^ (1 << x));
		}
		else if (!strcmp(b, "all")) {
			s = (1 << n) - 1;
		}
		else if (!strcmp(b, "empty")) {
			s = 0;
		}
	}
	return 0;
}
*/