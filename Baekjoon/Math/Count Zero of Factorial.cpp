// 문제 : https://www.acmicpc.net/problem/1676
// 0이 나타나는 이유는 5 * 2로 인해서 발생. 여기서 2는 5보다 많이 나오기 때문에 5의 갯수를 세준다. 단, 5를 가지는 값 중 25처럼 5를 2개 이상 가지는 값을 추가로 카운트 해야 한다.
#include <iostream>
using namespace std;
int main() {
	int N, R = 0;
	cin >> N;
	if (N >= 5) R += N / 5;
	if (N >= 25) R += N / 25;
	if (N >= 125) R += N / 125;
	cout << R;
	return 0;
}