//문제 : https://www.acmicpc.net/problem/1406
//2개의 stack을 활용
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	stack<char> LSet, RSet;
	string sentence, result = "";
	char cmd, cmd_temp;
	int num;

	cin >> sentence;

	for (int i = 0; i < (int)sentence.size(); i++) LSet.push(sentence.at(i));

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> cmd;

		if (cmd == 'P') {
			cin >> cmd_temp;
			LSet.push(cmd_temp);
		}
		else if (cmd == 'L') {
			//커서가 맨 앞이 아닐때
			if (!LSet.empty()) {
				RSet.push(LSet.top());
				LSet.pop();
			}
		}
		else if (cmd == 'D') {
			//커서가 맨 뒤가 아닐때
			if (!RSet.empty()) {
				LSet.push(RSet.top());
				RSet.pop();
			}
		}
		else if (cmd == 'B') {
			//커서가 맨 앞이 아닐때
			if (!LSet.empty()) LSet.pop();
		}
	}

	while (!RSet.empty()) {
		LSet.push(RSet.top());
		RSet.pop();
	}

	while (!LSet.empty()) {
		result += LSet.top();
		LSet.pop();
	}

	reverse(result.begin(), result.end());

	cout << result;

	return 1;
}