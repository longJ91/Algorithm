// 문제 : https://www.acmicpc.net/problem/10157
// 삼성 sw 대비
/*
((c - 1) - (k * 2)) + ((r - 1) - ( k * 2)) *  2 [0<=k]를 통해서 몇 번째 바퀴에 있는지 찾기
한바퀴 돌때마다 최소 범위는 + 1, 최대 범위는 - 1 해준다
마지막으로 정확한 좌표 값을 얻기위해 r c r c 총 4번의 구간을 나눠 결과를 도출

홀 홀 에서도 C R 값이 같으면 마지막 가운데 한자리가 생김 예외 처리 해줘야함
*/
#include <iostream>
using namespace std;
int C, R, K;
int x, y;
int main() {
	cin >> C >> R >> K;
	x = y = 0;
	int C_begin, C_end, R_begin, R_end;
	C_begin = R_begin = 1;
	C_end = C;
	R_end = R;
	int temp = 0, prev_temp = 0, k_range;
	k_range = C / 2;
	if (C % 2 == 1) {
		if (C == R) {
			x = y = (C + 1) / 2;
			cout << x << " " << y << endl;
			return 1;
		}
		k_range++;
	}
	for (int k = 0; k < k_range; k++) {
		int size = ((((C - 1) - (k * 2)) + ((R - 1) - (k * 2))) * 2);
		temp += size;
		if (temp >= K) {
			K -= prev_temp;
			temp = 0;
			int range = R_end - R_begin;
			if (range >= K) {
				x = C_begin;
				y = R_begin + (K - temp) - 1;
				break;
			}
			temp += R_end - R_begin;
			range += C_end - C_begin;
			if (range >= K) {
				y = R_end;
				x = C_begin + (K - temp) - 1;
				break;
			}
			temp += C_end - C_begin;
			range += R_end - R_begin;
			if (range >= K) {
				x = C_end;
				y = R_end - (K - temp) + 1;
				break;
			}
			temp += R_end - R_begin;
			range += C_end - C_begin;
			if (range >= K) {
				y = R_begin;
				x = C_end - (K - temp) + 1;
				break;
			}
		}
		C_begin++;
		R_begin++;
		C_end--;
		R_end--;
		prev_temp += size;
	}
	if(x == 0) cout << 0 << endl;
	else cout << x << " " << y <<endl;
	return 1;
}