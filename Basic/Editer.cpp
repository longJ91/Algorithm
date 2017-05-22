//���� : https://www.acmicpc.net/problem/1406
//2���� stack�� Ȱ��
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
			//Ŀ���� �� ���� �ƴҶ�
			if (!LSet.empty()) {
				RSet.push(LSet.top());
				LSet.pop();
			}
		}
		else if (cmd == 'D') {
			//Ŀ���� �� �ڰ� �ƴҶ�
			if (!RSet.empty()) {
				LSet.push(RSet.top());
				RSet.pop();
			}
		}
		else if (cmd == 'B') {
			//Ŀ���� �� ���� �ƴҶ�
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