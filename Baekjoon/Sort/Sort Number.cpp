// 문제 : https://www.acmicpc.net/problem/2751
// stdlib.h 라이브러리 파일의 qsort 활용
#include <iostream>
#include <stdlib.h> 
#include <vector>
using namespace std;
int number[1000000];
int compare(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}
int main() {
	int T, temp;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> temp;
		number[i] = temp;
	}
	qsort(number, T, sizeof(int), compare);
	for (int i = 0; i < T; i++) cout << number[i] << "\n";
	return 0;
}