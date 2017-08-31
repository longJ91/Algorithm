// ¹®Á¦ : https://www.acmicpc.net/problem/14502
// brute-force + BFS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 0 - ºóÄ­, 1 - º®, 2 - ¹ÙÀÌ·¯½º
int originalOfMap[8][8];
int maxOfResult;
int main() {

	int N, M, orginalOfSafeArea = 0;
	vector < pair< int, int> > originalOfVirus;
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		cin >> originalOfMap[i][j];
		if (originalOfMap[i][j] == 0) orginalOfSafeArea++;
		else if (originalOfMap[i][j] == 2) originalOfVirus.push_back(make_pair(i, j));
	}
	int lenByOriginalOfVirus = originalOfVirus.size();
	int nextOfI, nextOfJ;
	for (int firstOfI = 0, firstOfJ = 0; firstOfI < N && firstOfJ < M;) {
		//ºóÄ­ÀÏ¶§
		if (!(originalOfMap[firstOfI][firstOfJ] == 1 || originalOfMap[firstOfI][firstOfJ] == 2)) {
			if (firstOfJ + 1 >= M) {
				nextOfJ = (firstOfJ + 1) % M;
				nextOfI = firstOfI + 1;
			}
			else {
				nextOfJ = firstOfJ + 1;
				nextOfI = firstOfI;
			}
			for (int secondOfI = nextOfI, secondOfJ = nextOfJ; secondOfI < N && secondOfJ < M;) {
				//ºóÄ­ÀÏ¶§
				if (!(originalOfMap[secondOfI][secondOfJ] == 1 || originalOfMap[secondOfI][secondOfJ] == 2)) {
					if (secondOfJ + 1 >= M) {
						nextOfJ = (secondOfJ + 1) % M;
						nextOfI = secondOfI + 1;
					}
					else {
						nextOfJ = secondOfJ + 1;
						nextOfI = secondOfI;
					}
					for (int thirdOfI = nextOfI, thirdOfJ = nextOfJ; thirdOfI < N && thirdOfJ < M;) {
						//ºóÄ­ÀÏ¶§
						if (!(originalOfMap[thirdOfI][thirdOfJ] == 1 || originalOfMap[thirdOfI][thirdOfJ] == 2)) {
							//ÀÓ½Ã map ÃÊ±âÈ­
							int tempOfMap[8][8], tempOfSafeArea = orginalOfSafeArea;
							for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) tempOfMap[i][j] = originalOfMap[i][j];
							//ÀÓ½Ã º®
							tempOfMap[firstOfI][firstOfJ] = tempOfMap[secondOfI][secondOfJ] = tempOfMap[thirdOfI][thirdOfJ] = 1;
							tempOfSafeArea -= 3;
							//BFS
							queue< pair<int, int> > BFS;
							for (int i = 0; i < lenByOriginalOfVirus; i++)
								BFS.push(make_pair(originalOfVirus[i].first, originalOfVirus[i].second));
							int i, j;
							while (!BFS.empty()) {
								i = BFS.front().first;
								j = BFS.front().second;
								BFS.pop();
								//À§
								if (i - 1 >= 0 && tempOfMap[i - 1][j] == 0) {
									tempOfMap[i - 1][j] = 2;
									tempOfSafeArea--;
									BFS.push(make_pair(i - 1, j));
								}
								//¾Æ·¡
								if (i + 1 < N && tempOfMap[i + 1][j] == 0) {
									tempOfMap[i + 1][j] = 2;
									tempOfSafeArea--;
									BFS.push(make_pair(i + 1, j));
								}
								//¿ÞÂÊ
								if (j - 1 >= 0 && tempOfMap[i][j - 1] == 0) {
									tempOfMap[i][j - 1] = 2;
									tempOfSafeArea--;
									BFS.push(make_pair(i, j - 1));
								}
								//¿À¸¥ÂÊ
								if (j + 1 < M && tempOfMap[i][j + 1] == 0) {
									tempOfMap[i][j + 1] = 2;
									tempOfSafeArea--;
									BFS.push(make_pair(i, j + 1));
								}
							}
							maxOfResult < tempOfSafeArea ? maxOfResult = tempOfSafeArea : 0;
							if (++thirdOfJ >= M) {
								thirdOfJ %= M;
								++thirdOfI;
							}
						}
						else {
							if (++thirdOfJ >= M) {
								thirdOfJ %= M;
								++thirdOfI;
							}
						}
						
					}
					if (++secondOfJ >= M) {
						secondOfJ %= M;
						++secondOfI;
					}
				}
				else {
					if (++secondOfJ >= M) {
						secondOfJ %= M;
						++secondOfI;
					}
				}
			}
			if (++firstOfJ >= M) {
				firstOfJ %= M;
				++firstOfI;
			}
		}
		else {
			if (++firstOfJ >= M) {
				firstOfJ %= M;
				++firstOfI;
			}
		}
	}

	cout << maxOfResult;

	return 1;
}