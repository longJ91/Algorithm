// ¹®Á¦ : https://www.acmicpc.net/problem/11576
//
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
	int A, B, L, temp, ten = 0;
	string result = "";
	cin >> A >> B >> L;
	for (int i = L - 1; i >= 0; i--) {
		cin >> temp;
		ten += (int)pow(A, (double)i) * temp;
	}
	while (ten != 0) {
		result += ten%B + '0';
		ten /= B;
	}
	L = result.size();
	for (int i = L - 1; i >= 0; i--) cout << result.at(i) -'0' << " ";

	return 0;
}