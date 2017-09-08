// 문제 : https://www.acmicpc.net/problem/10974
// 완전탐색 - 순열
// 첫번째 인덱스부터 자신의 인덱스를 포함한 이후 인덱스와 스왑을 진행하며 스왑을 한번 진행 했을시 인덱스 자체를 증가시켜 다음 permutation을 콜한다.
#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int> &set, const int a, const int b) {
	int temp;
	temp = set[a];
	set[a] = set[b];
	set[b] = temp;
}
void permutation(vector<int> set, int n, int index) {
	if (index == n - 1) {
		for (int i = 0; i < n; i++) cout << set[i] << " ";
		cout << "\n";
		return ;
	}
	for (int i = index; i < n; i++) {
		swap(set, index, i);
		permutation(set, n, index + 1);
	}
}
int main() {
	int n;
	cin >> n;
	vector<int> set(n);
	for (int i = 0; i < n; i++) set[i] = i + 1;
	permutation(set, n, 0);
	return 1;
}