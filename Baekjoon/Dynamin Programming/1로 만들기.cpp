// ���� : https://www.acmicpc.net/problem/1463
// Top - Down(ū ������ ���� ������ ����)   OR   Botton - Up(���� �������� �ϳ� �� �ذ��ϸ� ū ������ �ذ� ����)   ��� �� ������ ����� Ȱ��
// Botton Up Ȱ��
#include <iostream>
using namespace std;
int R[1000001];
int main() {
	int X;
	cin >> X;
	R[1] = 0;
	for (int i = 2; i <= X; i++) {
		R[i] = R[i - 1] + 1;
		if (i % 2 == 0 && R[i] > R[i / 2] + 1) R[i] = R[i / 2] + 1;
		if (i % 3 == 0 && R[i] > R[i / 3] + 1) R[i] = R[i / 3] + 1;
	}
	cout << R[X] << endl;
	return 0;
}