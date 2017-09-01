// ¹®Á¦ : https://www.acmicpc.net/problem/1931
// Greedy
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct discuss {
	unsigned long start, end, time;
};
bool cmp(const discuss &a, const discuss &b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	else {
		return a.end < b.end;
	}
}
int main() {

	int n;
	cin >> n;
	vector <discuss> listOfDiscuss;
	for (int i = 0; i < n; i++) {
		discuss temp;
		cin >> temp.start >> temp.end;
		temp.time = temp.end - temp.start;
		listOfDiscuss.push_back(temp);
	}
	sort(listOfDiscuss.begin(), listOfDiscuss.end(),cmp);
	int now = 0;
	int ans = 0;
	int len = listOfDiscuss.size();
	for (int i = 0; i<len; i++) {
		if (now <= listOfDiscuss[i].start) {
			now = listOfDiscuss[i].end;
			ans += 1;
		}
	}
	cout << ans;
	return 1;
}