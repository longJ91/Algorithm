// ���� : https://www.acmicpc.net/problem/1978
// N�� �Ҽ����, N/2���� �۰ų� ���� �ڿ����� ������ �������� �ʴ´�.
// N�� �Ҽ����, ��ƮN���� �۰ų� ���� �ڿ����� ������ �������� �ʴ´�.
#include <iostream>
using namespace std;
int main() {
	int N,temp,result=0,flag;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		flag = 1;
		if (temp < 2) flag = -1;
		for (int j = 2; j*j <= temp; j++) {
			if (temp % j == 0) {
				flag = -1;
				break;
			}
		}
		if (flag == 1) result++;
	}
	cout << result;
	return 0;
}