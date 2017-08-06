//문제 : https://www.acmicpc.net/problem/8949
/*
1. 숫자를 문자열로 입력 받는다.
2. 문자열의 각 문자를 숫자 타입으로 변형한다.
3. 2개의 숫자 타입 숫자를 덧셈 연산을 진행한다.
4. 연산 결과를 문자 형식으로 변형하여 결과 문자열에 저장한다.
5. 단, 문자열 뒤에서부터 작업을 진행한다.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
	string n1, n2, result = "";
	
	cin >> n1 >> n2;

	int len_of_n1, len_of_n2, min_of_len;
	//0 - 동일, 1 - n1 더 길때, 2 - n2 더 길때
	int possible;
	
	len_of_n1 = n1.size();
	len_of_n2 = n2.size();

	if (len_of_n1 == len_of_n2) possible = 0;
	else if (len_of_n1 > len_of_n2) possible = 1;
	else possible = 2;

	int temp, distance_of_each_len;

	len_of_n1 > len_of_n2 ? distance_of_each_len = len_of_n1 - len_of_n2 : distance_of_each_len = len_of_n2 - len_of_n1;

	if (possible == 0) {
		for (int i = 0; i < len_of_n1; i++){
			temp = (n1.at(i) - '0') + (n2.at(i) - '0');
			result += to_string(temp);
		}
	}
	else if (possible == 1) {
		for (int i = 0; i < len_of_n1; i++) {
			if (i + 1 <= distance_of_each_len) result += n1.at(i);
			else {
				temp = (n1.at(i) - '0') + (n2.at(i - distance_of_each_len) - '0');
				result += to_string(temp);
			}
		}
	}
	else {
		for (int i = 0; i < len_of_n2; i++) {
			if (i + 1 <= distance_of_each_len) result += n2.at(i);
			else {
				temp = (n2.at(i) - '0') + (n1.at(i - distance_of_each_len) - '0');
				result += to_string(temp);
			}
		}
	}

	cout << result;
	return 0;
}
