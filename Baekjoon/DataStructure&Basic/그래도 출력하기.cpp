#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
	string str;
	getline(cin, str);
	while (str.size() > 0) {
		cout << str << "\n";
		getline(cin, str);
	}
	return 1;
}