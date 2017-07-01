#include <iostream>
#include <string>
#include <stack>
using namespace std;

int Answer;
int R[1000000];
//주어진 조건 2번 3번을 바탕으로 알고리즘 다시 설계
int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	string str;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> str;
		int result = 0, len = str.size(), max = 0;
		char temp, pre;
		for (int i = 0; i < len; i++) {
			stack<char> S;
			result = 0;
			for (int j = i; j < len; j++){
				temp = str.at(j);
				if (temp == '(' || temp == '{' || temp == '[') S.push(temp);
				else {
					if (S.empty()) break;
					pre = S.top();
					if (pre == '(' && temp == ')') result += 2;
					else if(pre == '{' && temp == '}') result += 2;
					else if (pre == '[' && temp == ']') result += 2;
					else {
						break;
					}
					S.pop();
				}
				//올바른 괄호
				if (S.empty()) {
					R[j] = result;
					if (j - result >= 0) R[j] += R[j - result];
					i = j;
					break;
				}
			}
			if (R[i] > max) max = R[i];
		}
		for (int i = 0; i < len; i++) R[i] = 0;
		Answer = max;
		if (len == 0) Answer = 0;
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}