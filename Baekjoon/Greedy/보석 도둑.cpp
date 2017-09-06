// 문제 : https://www.acmicpc.net/problem/1202
// Greedy  multiset 이용
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second > b.second;
}
unsigned long long result = 0;
int main() {
	int N, K;
	cin >> N >> K;
	//first - weight, second - cost
	vector< pair<int, int> > jewelry(N);
	multiset<int> bag;
	for (int i = 0; i < N; i++) cin >> jewelry[i].first >> jewelry[i].second;
	int weight;
	for (int i = 0; i < K; i++) {
		cin >> weight;
		bag.insert(weight);
	}
	sort(jewelry.begin(), jewelry.end(), cmp);
	//sort(bag.begin(), bag.end());
	for (int i = 0; i < N; i++) {
		int weight, cost;
		weight = jewelry[i].first;
		cost = jewelry[i].second;
		auto it = bag.lower_bound(weight);
		if (it != bag.end()) {
			result += cost;
			bag.erase(it);
		}
	}
	cout << result;
	return 1;
}