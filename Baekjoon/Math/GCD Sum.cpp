// 문제 : https://www.acmicpc.net/problem/9613
// vector를 활용해서 자료 저장
#include <iostream>
#include <vector>
using namespace std;
int GCD(int x, int y) {
	if (y == 0) return x;
	else return GCD(y, x%y);
}
int main() {
	int T,N,A,R;
	vector<int> Set;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> A;
			Set.push_back(A);
		}
		R = 0;
		for (int j = 0; j < N; j++) {
			for (int k = j+1; k < N; k++) {
				R += GCD(Set.at(j), Set.at(k));
			}
		}
		Set.clear();
		cout << R <<'\n';
	}
	return 1;
}