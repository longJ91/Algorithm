// 문제 : https://www.acmicpc.net/problem/1463
// Top - Down(큰 문제를 작은 문제로 만들어서)   OR   Botton - Up(작은 문제부터 하나 씩 해결하면 큰 문제를 해결 가능)   방식 중 가능한 방법을 활용
// Botton Up 활용
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