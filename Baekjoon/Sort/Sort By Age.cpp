// 문제 : https://www.acmicpc.net/problem/10814
// vector, sort 활용 and 사용자 정보를 저장할 struct 구현과 sort 할 때 필요한 compare 함수 구현
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct information {
	int age, join;
	string name;
}I;
bool compare(const information &a, const information &b) {
	if (a.age < b.age) return true;
	else if (a.age == b.age) return a.join < b.join;
	else return false;
}
int main() {
	int T;
	vector<information> Set;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> I.age; cin >> I.name; I.join = i;
		Set.push_back(I);
	}
	sort(Set.begin(), Set.end(), compare);
	for (vector<information>::iterator it = Set.begin(); it != Set.end(); ++it) cout << it->age << " " << it->name << "\n";
	return 1;
}