#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int test_case, N, M, K, A, B, result;
int a[10], b[10], a_time[10], b_time[10], a_customer[10], b_customer[10], receipt_number[1001], repair_number[1001];
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second < b.second;
}
int main() {
	cin.sync_with_stdio(false);
	cin >> test_case;
	for (int test = 1; test <= test_case; test++) {
		cin >> N >> M >> K >> A >> B;
		vector<pair<int, int> > t;
		int temp, cnt = 0;
		result = 0;
		memset(a, -1, sizeof(a));
		memset(b, -1, sizeof(b));
		memset(receipt_number, -1, sizeof(receipt_number));
		memset(repair_number, -1, sizeof(repair_number));
		for (int i = 1; i <= N; i++) {
			cin >> a_time[i];
		}
		for (int i = 1; i <= M; i++) {
			cin >> b_time[i];
		}
		for (int i = 1; i <= K; i++) {
			cin >> temp;
			t.push_back(make_pair(i, temp));
		}
		sort(t.begin(), t.end(), cmp);
		int time = -1;
		priority_queue<int> prev_receipt;
		queue<int> prev_repair;
		while (true) {
			time++;
			//고객 도착
			int t_size = t.size(), pos = 0;
			for (int k = 0; k < t_size; k++) {
				if (time == t[k].second) {
					prev_receipt.push(-t[k].first);
					pos++;
				}
				else if (time < t[k].second) break;
			}
			if (pos != 0) t.erase(t.begin(), t.begin() + pos);
			//접수
			for (int k = 1; k <= N; k++) {
				if (a[k] == -1) {
					if (!prev_receipt.empty()) {
						a_customer[k] = -prev_receipt.top();
						receipt_number[-prev_receipt.top()] = k;
						prev_receipt.pop();
						a[k] = a_time[k];
					}
					else break;
				}
			}
			//정비 접수
			for (int k = 1; k <= M; k++) {
				if (b[k] == -1) {
					if (!prev_repair.empty()) {
						b_customer[k] = prev_repair.front();
						repair_number[prev_repair.front()] = k;
						prev_repair.pop();
						b[k] = b_time[k];
					}
					else break;
				}
			}
			//시간별 접수, 정비 시간 감소 시키기
			for (int k = 1; k <= N; k++) {
				if (a[k] == -1) continue;
				a[k]--;
			}
			for (int k = 1; k <= M; k++) {
				if (b[k] == -1) continue;
				b[k]--;
				if (b[k] == 0) {
					b[k]--;
					cnt++;
				}
			}
			//정비 전
			vector<pair<int, int> > temp_prev_repair;
			for (int k = 1; k <= N; k++) {
				if (a[k] == 0) {
					a[k]--;
					temp_prev_repair.push_back(make_pair(a_customer[k], k));
				}
			}
			sort(temp_prev_repair.begin(), temp_prev_repair.end(), cmp);
			int len = temp_prev_repair.size();
			for (int k = 0; k < len; k++) {
				prev_repair.push(temp_prev_repair[k].first);
			}

			if (cnt == K) break;
		}
		for (int k = 1; k <= K; k++) {
			if (receipt_number[k] == A && repair_number[k] == B) result += k;
		}
		if (result == 0) result = -1;
		cout << "#" << test << " " << result << "\n";
	}
	return 0;
}