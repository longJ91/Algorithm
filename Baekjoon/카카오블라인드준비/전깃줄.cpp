// 문제 : https://www.acmicpc.net/problem/2565
// LIS (최대 증가 부분수열)을 통한 dp 문제
// 왼쪽 전봇대의 번호를 기준으로 오름차순 정렬을 하면, 오른쪽 전봇대의 번호들 중 LIS를 찾으면 해결되는 문제
/* 이러한 해결이 가능한 이유 :
N 층의 두 전봇대에서 N개의 선을 교차하지 않고 잇는 방법은

서로 같은 층끼리 이으면 되겠죠.

그런 경우 1-1,2-2,3-3,...N-N 이 됩니다.

왼쪽을 오름차순으로 정렬한다고 하면, 숫자가 점점 증가하는 방향이 이상적이라고 할 수 있죠.

여기서 한 선이 다른 선을 건드리게 될 때를 생각해보면, 그 선을 제외한 나머지 선 끼리는 다시 증가하는 구조를 갖게 됩니다.

결과적으로 오름차순으로 정렬된 선에서, 겹침을 유발하는 선만이 증가하는 구조를 깨뜨리게 되고, 그 외 나머지 선은 LIS로 구할 수 있죠.
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