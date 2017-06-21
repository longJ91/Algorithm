// ¹®Á¦ : https://www.acmicpc.net/problem/11721
//
#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	int len = str.size();
	for (int i = 1; i <= len; i++){
		cout << str.at(i-1);
		if (i % 10 == 0) cout << endl;
	}
	cout << endl;
	return 0;
}