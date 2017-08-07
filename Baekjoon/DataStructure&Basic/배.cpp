// ���� : https://www.acmicpc.net/problem/1092
/*
1. ũ���� ���� ���Ѱ� �ڽ��� ���Ը� ���� ������ �ڷῡ �����ϰ� �����Ѵ�.
2. ũ���� ���� ���Ѻ��� ���ų� ���� �� �� ���� ū ���� ������ �ڽ� ���� �ε���(ũ������ �̵� ���Ѿ� �� ���� ������ �� ��)�� ���ο� �ڷῡ �����Ѵ�.
(��, ������ ���ؼ� �̺� Ž��)
3-1. ũ���� ���� ���� �ִ밪�� �ڽ� ���� �ִ밪�� ���ؼ� �ڽ� ���� �ִ밪�� �� ū ��� �̵� �Ұ���
3-2. �ڽ��� �̵��ϴ� �ּڰ��� ���Ѵ�.
4. �ڽ��� ���� �ִ밪�� M�� 10,000(��)�̹Ƿ� �ִ� �̵� ���� Ƚ���� 10,000���� �� �� �ִ�.
5. ���� ũ������ �̵� ���� ������ �ڽ��� 0 �̸� �ڽź��� ���� ������ ���� ũ���ε� �� 0���� ū �� ���� ������ �ִ� ���� ��� �̵������ش�.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> limit_weight;
vector<int> index_of_limit_weight(50, 0);

int main() {
	int N, M;
	
	cin >> N;
	
	int temp;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		limit_weight.push_back(temp);
	}
	sort(limit_weight.begin(), limit_weight.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		//scanf("%d",&temp);
		cin >> temp;
		//2.
		for (int j = 0; j < N; j++){
			if (temp <= limit_weight[j]) {
				index_of_limit_weight[j]++;
				break;
			}
			//3-1
			if (j == N - 1) {
				cout << -1;
				return 0;
			}
		}
	} 

	int total = 0, result;
	
	for (int k = 1; k <= 10000; k++) {
		for (int a = 0; a < N; a++) {
			if (index_of_limit_weight[a] > 0) {
				index_of_limit_weight[a]--;
				total++;
			}
			else {
				//5.
				for (int b = a-1; b >= 0; b--){
					if (index_of_limit_weight[b] > 0) {
						index_of_limit_weight[b]--;
						total++;
						break;
					}
				}
			}
		}
		if (total == M) {
			result = k;
			break;
		}
	}

	cout << result;
	return 0;
}