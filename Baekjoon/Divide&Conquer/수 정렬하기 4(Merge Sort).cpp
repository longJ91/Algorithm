// ¹®Á¦ : https://www.acmicpc.net/problem/11931
// Merge Sort
#include <iostream>
#include <stdio.h>
using namespace std;
int firstSet[1000000];
int secondSet[1000000];
void sort(int left, int right) {
	int mid = (left + right) / 2;
	if (left == right) return;
	sort(left, mid);
	sort(mid + 1, right);
	int index = left, start = left, a = left, b = mid + 1;
	while (a <= mid && b <= right) {
		if (firstSet[a] < firstSet[b]) secondSet[index++] = firstSet[a++];
		else secondSet[index++] = firstSet[b++];
	}
	while (a <= mid) secondSet[index++] = firstSet[a++];
	while (b <= right) secondSet[index++] = firstSet[b++];
	for (int i = start; i < index; i++) firstSet[i] = secondSet[i];
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) scanf("%d", &firstSet[i]);
	sort(0, N-1);
	for (int i = N-1; i >= 0; i--) printf("%d\n", firstSet[i]);
	return 0;
}