// ¹®Á¦ : https://www.acmicpc.net/problem/11728
// Merge
#include <iostream>
#include <stdio.h>
using namespace std;
int leftSet[1000000];
int rightSet[1000000];
int Set[2000000];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) scanf("%d", &leftSet[i]);
	for (int i = 0; i < M; i++) scanf("%d", &rightSet[i]);
	int L, R, S;
	L = R = S = 0;
	while (L < N && R < M) leftSet[L] <= rightSet[R] ? Set[S++] = leftSet[L++] : Set[S++] = rightSet[R++];
	while (L < N) Set[S++] = leftSet[L++];
	while (R < M) Set[S++] = rightSet[R++];
	for (int i = 0; i < S; i++) printf("%d ", Set[i]);
	
	return 0;
}