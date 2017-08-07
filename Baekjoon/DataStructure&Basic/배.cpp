// 문제 : https://www.acmicpc.net/problem/1092
/*
1. 크레인 무게 제한과 박스의 무게를 각각 별도의 자료에 저장하고 정렬한다.
2. 크레인 무게 제한보다 같거나 작은 수 중 가장 큰 값을 가지는 박스 무게 인덱스(크레인이 이동 시켜야 할 가장 적절한 짐 수)를 새로운 자료에 저장한다.
(단, 성능을 위해서 이분 탐색)
3-1. 크레인 무게 제한 최대값과 박스 무게 최대값을 비교해서 박스 무게 최대값이 더 큰 경우 이동 불가능
3-2. 박스를 이동하는 최솟값을 구한다.
4. 박스의 갯수 최대값인 M은 10,000(만)이므로 최대 이동 가능 횟수는 10,000으로 볼 수 있다.
5. 현재 크레인이 이동 가능 절적한 박스가 0 이면 자신보다 무게 제한이 작은 크레인들 중 0보다 큰 짐 수를 가지고 있는 짐을 대신 이동시켜준다.
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