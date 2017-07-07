// https://www.acmicpc.net/problem/10815
// Binary Search (dq)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N;
	vector<int> n(N);
	for (int i = 0; i < N; i++) cin >> n[i];
	sort(n.begin(), n.end());
	cin >> M;
	vector<int> m(M);
	int temp, find, left, right, mid;
	for (int i = 0; i < M; i++) cin >> m[i];
	for (int i = 0; i < M; i++){
		temp = m[i];
		find = 0;
		left = 0;
		right = N - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (n[mid] == temp) {
				find = 1;
				break;
			}
			if (n[mid] < temp) left = mid + 1;
			else right = mid - 1;
		}
		cout << find << " ";
	}
	return 0;
}
/*
���⼭ ���� ���� ��ü�� ������ M�� ��ŭ�� �ݺ����� ����ɶ� �󸶳� ����ϰ� �ܼ��� �۾��� �ϴ��Ŀ� ���� ���� ���̰� ���� �߻��Ѵ�.
�� ��� �Ʒ��� ���� ��Ÿ�Ϸδ� �ð� �ʰ��� �߻��Ѵ�.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
int N, M;
cin >> N;
vector<int> n(N);
for (int i = 0; i < N; i++) cin >> n[i];
sort(n.begin(), n.end());
cin >> M;
int temp, find, left, right, mid;
for (int i = 0; i < M; i++){
find = 0;
left = 0;
right = N-1;
cin >> temp;
while (left <= right) {
mid = (left + right) / 2;
if (n[mid] == temp) {
find = 1;
break;
}
if (n[mid] < temp) left = mid + 1;
else right = mid - 1;
}
cout << find << " ";
}
return 0;
}
*/