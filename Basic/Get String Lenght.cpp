// ���� : https://www.acmicpc.net/problem/2743
// for�� ���ǹ��� ���ڿ� �迭�� Ȱ���� ���ڿ� ���̸� ���Ѵ�.
#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;
	int count = 0;

	cin >> str;

	for (int i = 0; str[i]; i++) count++;

	cout << count;

	return 1;
}