//���� : https://www.acmicpc.net/problem/10809
//�ҹ��� 26���� ���ڿ��� int �迭�� ������ ���ĺ� ������� �ε����� Ȱ��
#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;
	int result[26] = { 0, };

	cin >> str;

	for (int i = 0; i < str.size(); i++) if(result[str.at(i) - 97] == 0) result[str.at(i) - 97] = i + 1;
	
	for (int i = 0; i < 26; i++) {
		if(result[i] != 0) cout << result[i] - 1 << " ";
		else cout << "-1 ";
	}
	cout << "";

	return 1;
}