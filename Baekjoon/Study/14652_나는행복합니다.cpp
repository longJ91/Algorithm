// ¹®Á¦ : https://www.acmicpc.net/problem/14652
//
#include <iostream>
using namespace std;
int N, M, K;
int main() {
	cin >> N >> M >> K;
	int i, j;
	if (K == 0) i = j = 0;
	else {
		i = K / M;
		j = K % M;
	}
	cout << i << " " << j << endl;
	return 1;
}