//¹®Á¦ : https://www.acmicpc.net/problem/9012
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string temp;
	int num;
	bool flat;

	cin >> num;

	for (int i = 0; i < num; i++ ) {
		stack<char> STACK;

		flat = true;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			if (temp.at(j) == '(') {
				STACK.push(temp.at(j));
			}
			else {
				if (STACK.empty()) flat = false;
				else STACK.pop();
			}
		}
		if (!STACK.empty()) flat = false;
		flat == true ? cout << "YES\n" : cout << "NO\n";
	}

	return 1;
}