//���� : https://www.acmicpc.net/problem/10799
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	stack<char> Set;
	string data;
	int sum = 0;
	cin >> data;
	
	for (int i = 0; i < data.size(); i++) {
		if (data.at(i) == '(') {
			Set.push(data.at(i));
		}
		else {
			Set.pop();
			//���� ���ڰ� '(' �̸� "()" �������� �����ؼ� �������� ����
			data.at(i - 1) == '(' ? sum += Set.size() : sum++;
		}
	}

	cout << sum;

	return 1;
}