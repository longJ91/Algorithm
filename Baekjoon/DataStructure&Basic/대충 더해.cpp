//���� : https://www.acmicpc.net/problem/8949
/*
1. ���ڸ� ���ڿ��� �Է� �޴´�.
2. ���ڿ��� �� ���ڸ� ���� Ÿ������ �����Ѵ�.
3. 2���� ���� Ÿ�� ���ڸ� ���� ������ �����Ѵ�.
4. ���� ����� ���� �������� �����Ͽ� ��� ���ڿ��� �����Ѵ�.
5. ��, ���ڿ� �ڿ������� �۾��� �����Ѵ�.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
	string n1, n2, result = "";
	
	cin >> n1 >> n2;

	int len_of_n1, len_of_n2, min_of_len;
	//0 - ����, 1 - n1 �� �涧, 2 - n2 �� �涧
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
