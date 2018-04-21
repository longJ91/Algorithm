#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int c, n, k, result;

int main() {
	cin >> c;
	while (c--) {
		priority_queue<int> min_heap;
		int temp;
		cin >> n;
		result = 0;
		for (int i = 0; i < n; i++){
			cin >> k;
			min_heap.push(-k);
		}
		for (int i = 1; i < n; i++) {
			temp = 0;
			temp += min_heap.top();
			min_heap.pop();
			temp += min_heap.top();
			min_heap.pop();
			min_heap.push(temp);
			result += temp;
		}
		cout << -result << "\n";
	}
	return 0;
}