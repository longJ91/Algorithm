// ���� : https://www.acmicpc.net/problem/2565
// LIS (�ִ� ���� �κм���)�� ���� dp ����
// ���� �������� ��ȣ�� �������� �������� ������ �ϸ�, ������ �������� ��ȣ�� �� LIS�� ã���� �ذ�Ǵ� ����
/* �̷��� �ذ��� ������ ���� :
N ���� �� �����뿡�� N���� ���� �������� �ʰ� �մ� �����

���� ���� ������ ������ �ǰ���.

�׷� ��� 1-1,2-2,3-3,...N-N �� �˴ϴ�.

������ ������������ �����Ѵٰ� �ϸ�, ���ڰ� ���� �����ϴ� ������ �̻����̶�� �� �� ����.

���⼭ �� ���� �ٸ� ���� �ǵ帮�� �� ���� �����غ���, �� ���� ������ ������ �� ������ �ٽ� �����ϴ� ������ ���� �˴ϴ�.

��������� ������������ ���ĵ� ������, ��ħ�� �����ϴ� ������ �����ϴ� ������ ���߸��� �ǰ�, �� �� ������ ���� LIS�� ���� �� ����.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int, int> a, const pair<int,int> b) {
	return a.first < b.first;
}
// 0 - length, 1 - last number
int main() {
	int n;
	cin >> n;
	int l, r;
	vector< pair<int, int> > S;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		S.push_back(make_pair(l, r));
	}
	sort(S.begin(), S.end(), cmp);
	vector<int> LIS;
	for (int i = 0; i < n; i++) {
		int num = S.at(i).second;
		auto it = lower_bound(LIS.begin(), LIS.end(), num);
		if (it == LIS.end()) {
			LIS.push_back(num);
		}
		else {
			*it = num;
		}
	}
	cout << n - LIS.size() << endl;
	return 1;
}