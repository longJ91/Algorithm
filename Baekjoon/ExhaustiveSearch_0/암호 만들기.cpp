// 문제 : https://www.acmicpc.net/problem/1759
// 완전탐색
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int L, C;
vector<int> set(15, 150);
void go(const int count, const int index, vector<int> order) {
	if (count == L + 1) {
		string str = "";
		char temp;
		//a 모음, b 자음
		int a, b;
		a = b = 0;
		for (int i = 0; i < L; i++) {
			temp = char(set[order[i]] + 'a');
			if (temp == 'a' || temp == 'i' || temp == 'o' || temp == 'e' || temp == 'u') a++;
			else b++;
			str += temp;
		}
		if (a >= 1 && b >= 2) cout << str << "\n";
		return;
	}
	if (L - count + 1 > C - index) return;
	for (int i = index; i < C; i++) {
		order[count - 1] = i;
		go(count + 1, i + 1, order);
	}
}
int main() {
	cin >> L >> C;
	char temp;
	for (int i = 0; i < C; i++) {
		cin >> temp;
		set[i] = temp - 'a';
	}
	sort(set.begin(), set.end());
	vector<int> order(L);
	go(1, 0, order);
	return 1;
}