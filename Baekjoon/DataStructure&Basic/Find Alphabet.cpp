//문제 : https://www.acmicpc.net/problem/10809
//소문자 26개의 문자열을 int 배열로 선언해 알파벳 순서대로 인덱스를 활용
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