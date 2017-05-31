// ¹®Á¦ : https://www.acmicpc.net/problem/11005
//
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int N, B, temp;
	string R="";
	cin >> N; cin >> B;
	while (N > 0) {
		temp = N%B;
		if (temp >= 10) R+=(char)(temp-10+'A');
		else R += (char)(temp + '0');
		N = (N - temp) / B;
	}
	reverse(R.begin(), R.end());
	cout << R;
	return 0;
}