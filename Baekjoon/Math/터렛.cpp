// 문제 : https://www.acmicpc.net/problem/1002
// 원의 외접, 내접 이론 숙지
#include <iostream>
#include <math.h>
#include <stdlib.h>     /* abs */
using namespace std;
int main() {
	int T, R;
	int x1, y1, r1, x2, y2, r2;
	double D;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		D = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
		if (x1 == x2 && y1 == y2 && r1 == r2) R = -1;
		else if (abs(r1 - r2) < D && (r1 + r2) > D) R = 2;
		else if ((r1 + r2) == D || abs(r1 - r2) == D) R = 1;
		else if ((r1 + r2) < D || abs(r1 - r2) > D) R = 0;
		else R = 0;
		cout << R << endl;
	}
	
	return 0;
}