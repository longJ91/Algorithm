// ���� : https://www.acmicpc.net/problem/10808
// �ɰ��� ���ĺ��� �ƽ�Ű�ڵ� ����(�ҹ��ڶ� 97) 97�� ���־� �ε����� Ȱ��
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int result[26] = { 0, };

	cin >> str;

	for (int i = 0; i < str.size(); i++) result[str.at(i) - 97]++;
	
	for (int i = 0; i < 26; i++) cout << result[i] << " ";
	
	cout << "";

	return 1;
}