// ���� : https://www.acmicpc.net/problem/10867
// Set �ڷᱸ�� ����ؼ� �ߺ� ���� �� ����
#include <iostream>
#include <set>
using namespace std;
int N, num;
int main() {
	cin.sync_with_stdio(false);
	cin >> N;
	set<int> s;
	for (int n = 0; n < N; n++) {
		cin >> num;
		s.insert(num);
	}
	for (auto it = s.begin(); it != s.end(); ++it) cout << *it << " ";
	return 0;
}