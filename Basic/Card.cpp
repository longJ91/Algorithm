// ���� : https://www.acmicpc.net/problem/11652
// map�� Ȱ���ؼ� sort ���� ����� ����
#include <iostream>
#include <map>
using namespace std;
int main() {
	int T;
	long temp, result;
	map<long, int> Set;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> temp;
		if (i == 0) result = temp;
		if (Set.count(temp) == 0) Set.insert(pair<long, int>(temp, 1));
		else {
			if (++Set.at(temp) > Set.at(result)) result = temp;
			else if (Set.at(temp) == Set.at(result)) if (temp < result) result = temp;
		}
	}
	cout << result << "\n";
	return 1;
}