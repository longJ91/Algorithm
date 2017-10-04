// ���� : https://www.acmicpc.net/problem/10974
// ����Ž�� - ����
// ù��° �ε������� �ڽ��� �ε����� ������ ���� �ε����� ������ �����ϸ� ������ �ѹ� ���� ������ �ε��� ��ü�� �������� ���� permutation�� ���Ѵ�.
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