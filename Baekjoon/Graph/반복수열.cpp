// 문제 : https://www.acmicpc.net/problem/2331
// vector, map을 활용
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int main() {
	int A,P,R = 0;
	vector<long long> S;
	map<long long, int> check;
	cin >> A >> P;
	S.push_back(A);
	check.insert(pair<long long, int>(A, 1));
	bool flag = true;
	long long num;
	while (flag) {
		long long temp, next = 0;
		temp = S.back();
		while (temp != 0) {
			next += pow((temp % 10), P);
			temp /= 10;
		}
		S.push_back(next);
		if (check.count(next) == 0) check.insert(pair<long long,int>(next, 1));
		else if (check.find(next)->second == 1) check.find(next)->second++;
		else {
			flag = false;
			num = next;
		}
	}
	int l = S.size();
	for (int i = 0; i < l; i++) {
		if (num == S.at(i)) break;
		R++;
	}
	cout << R << endl;
	return 0;
}