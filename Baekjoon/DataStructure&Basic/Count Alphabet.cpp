// 문제 : https://www.acmicpc.net/problem/10808
// 쪼개진 알파벳의 아스키코드 값인(소문자라 97) 97를 빼주어 인데스로 활용
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