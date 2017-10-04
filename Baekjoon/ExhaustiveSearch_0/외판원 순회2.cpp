// 문제 : https://www.acmicpc.net/problem/10971
// 완전탐색 - 도시간의 가는 간선과 오는 간선의 비용이 달라서 완전탐색 활용
#include <iostream>
#include <vector>
using namespace std;
int N;
int result = 20000000;
vector< vector<int> > W(10);
void swap(const int a, const int b, vector<int> &set) {
	int temp;
	temp = set[a];
	set[a] = set[b];
	set[b] = temp;
}
void permutation(const int count_city, const int index, vector<int> set) {
	if (count_city == N + 1) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (i == N - 1) {
				if (W[set[i]][set[0]] == 0) return;
				sum += W[set[i]][set[0]];
			}
			else {
				if (W[set[i]][set[i + 1]] == 0) return;
				sum += W[set[i]][set[i + 1]];
			}
		}
		if (result > sum) result = sum;
		return;
	}
	for (int i = index; i < N; i++) {
		swap(index, i, set);
		permutation(count_city + 1, index + 1, set);
	}
}
int main() {
	cin >> N;
	vector <int> set(N);
	int temp;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			cin >> temp;
			W[i].push_back(temp);
		}
		set[i] = i;
	}
	permutation(1, 0, set);
	cout << result;
	return 1;
}
