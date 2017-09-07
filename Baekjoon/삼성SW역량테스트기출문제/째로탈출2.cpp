// 문제 : https://www.acmicpc.net/problem/13460
// 삼성 SW 기출
// 접근 잘못함 - DFS 방식도 존재
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int result = 11;
struct position {
	int i, j;
};
position hole;
//N - 세로 , M - 가로
int N, M;
//1 = 위, 2 = 아래, 3 = 왼쪽, 4 = 오른쪽
void go(const int direct, const int countOfSlope, vector< vector<int> > map, position red, position blue) {
	if (countOfSlope < 11) {
		//move
		if (direct == 1) {
			//직선 상에 존재
			if (red.j == blue.j) {
				if (red.i > blue.i) {
					for (int k = blue.i - 1; k >= 1; k--) {
						//#
						if (map[k][red.j] == -1) break;
						//.
						else if (map[k][red.j] == 0) blue.i--;
						//O
						else if (map[k][red.j] == 3) return ;
					}
					for (int k = red.i - 1; k >= 1; k--) {
						//#
						if (map[k][red.j] == -1) break;
						//.
						else if (map[k][red.j] == 0) red.i--;
						//O
						else if (map[k][red.j] == 3) {
							if (result > countOfSlope) result = countOfSlope;
							return;
						} 
					}
					if(red.i == blue.i) red.i++;
				}
				else {
					for (int k = blue.i - 1; k >= 1; k--) {
						//#
						if (map[k][red.j] == -1) break;
						//.
						else if (map[k][red.j] == 0) blue.i--;
						//O
						else if (map[k][red.j] == 3) return;
					}
					for (int k = red.i - 1; k >= 1; k--) {
						//#
						if (map[k][red.j] == -1) break;
						//.
						else if (map[k][red.j] == 0) red.i--;
						//O
						else if (map[k][red.j] == 3) {
							if (result > countOfSlope) result = countOfSlope;
							return;
						}
					}
					if (red.i == blue.i) blue.i++;
				}
			}
			else {
				//red
				for (int k = red.i - 1; k >= 1; k--) {
					//#
					if (map[k][red.j] == -1) break;
					//.
					else if (map[k][red.j] == 0) red.i--;
					//O
					else if (map[k][red.j] == 3) {
						if (countOfSlope < result) result = countOfSlope;
						return;
					}
				}
				//blue
				for (int k = blue.i - 1; k >= 1; k--) {
					//#
					if (map[k][blue.j] == -1) break;
					//.
					else if (map[k][blue.j] == 0) blue.i--;
					//O
					else if (map[k][blue.j] == 3) return;
				}
			}
		} 
		else if (direct == 2) {
			//직선 상에 존재
			if (red.j == blue.j) {
				if (red.i < blue.i) {
					for (int k = blue.i + 1; k < N; k++) {
						//#
						if (map[k][red.j] == -1) break;
						//.
						else if (map[k][red.j] == 0) blue.i++;
						//O
						else if (map[k][red.j] == 3) return;
					}
					for (int k = red.i + 1; k < N; k++) {
						//#
						if (map[k][red.j] == -1) break;
						//.
						else if (map[k][red.j] == 0) red.i++;
						//O
						else if (map[k][red.j] == 3) {
							if (result > countOfSlope) result = countOfSlope;
							return;
						}
					}
					if (red.i == blue.i) red.i--;
				}
				else {
					for (int k = blue.i + 1; k < N; k++) {
						//#
						if (map[k][red.j] == -1) break;
						//.
						else if (map[k][red.j] == 0) blue.i++;
						//O
						else if (map[k][red.j] == 3) return;
					}
					for (int k = red.i + 1; k < N; k++) {
						//#
						if (map[k][red.j] == -1) break;
						//.
						else if (map[k][red.j] == 0) red.i++;
						//O
						else if (map[k][red.j] == 3) {
							if (result > countOfSlope) result = countOfSlope;
							return;
						}
					}
					if (red.i == blue.i) blue.i--;
				}
			}
			else {
				//red
				for (int k = red.i + 1; k < N; k++) {
					//#
					if (map[k][red.j] == -1) break;
					//.
					else if (map[k][red.j] == 0) red.i++;
					//O
					else if (map[k][red.j] == 3) {
						if (countOfSlope < result) result = countOfSlope;
						return;
					}
				}
				//blue
				for (int k = blue.i + 1; k < N; k++) {
					//#
					if (map[k][blue.j] == -1) break;
					//.
					else if (map[k][blue.j] == 0) blue.i++;
					//O
					else if (map[k][blue.j] == 3) return;
				}
			}
		}
		else if (direct == 3) {
			//직선 상에 존재
			if (red.i == blue.i) {
				if (red.j > blue.j) {
					for (int k = blue.j - 1; k >= 1; k--) {
						//#
						if (map[red.i][k] == -1) break;
						//.
						else if (map[red.i][k] == 0) blue.j--;
						//O
						else if (map[red.i][k] == 3) return;
					}
					for (int k = red.j - 1; k >= 1; k--) {
						//#
						if (map[red.i][k] == -1) break;
						//.
						else if (map[red.i][k] == 0) red.j--;
						//O
						else if (map[red.i][k] == 3) {
							if (result > countOfSlope) result = countOfSlope;
							return;
						}
					}
					if (red.j == blue.j) red.j++;
				}
				else {
					for (int k = blue.j - 1; k >= 1; k--) {
						//#
						if (map[red.i][k] == -1) break;
						//.
						else if (map[red.i][k] == 0) blue.j--;
						//O
						else if (map[red.i][k] == 3) return;
					}
					for (int k = red.j - 1; k >= 1; k--) {
						//#
						if (map[red.i][k] == -1) break;
						//.
						else if (map[red.i][k] == 0) red.j--;
						//O
						else if (map[red.i][k] == 3) {
							if (result > countOfSlope) result = countOfSlope;
							return;
						}
					}
					if (red.j == blue.j) blue.j++;
				}
			}
			else {
				//red
				for (int k = red.j - 1; k >= 1; k--) {
					//#
					if (map[red.i][k] == -1) break;
					//.
					else if (map[red.i][k] == 0) red.j--;
					//O
					else if (map[red.i][k] == 3) {
						if (countOfSlope < result) result = countOfSlope;
						return;
					}
				}
				//blue
				for (int k = blue.j - 1; k >= 1; k--) {
					//#
					if (map[blue.i][k] == -1) break;
					//.
					else if (map[blue.i][k] == 0) blue.j--;
					//O
					else if (map[blue.i][k] == 3) return;
				}
			}
		}
		else {
			//직선 상에 존재
			if (red.i == blue.i) {
				if (red.j < blue.j) {
					for (int k = blue.j + 1; k < M; k++) {
						//#
						if (map[red.i][k] == -1) break;
						//.
						else if (map[red.i][k] == 0) blue.j++;
						//O
						else if (map[red.i][k] == 3) return;
					}
					for (int k = red.j + 1; k < M; k++) {
						//#
						if (map[red.i][k] == -1) break;
						//.
						else if (map[red.i][k] == 0) red.j++;
						//O
						else if (map[red.i][k] == 3) {
							if (result > countOfSlope) result = countOfSlope;
							return;
						}
					}
					if (red.j == blue.j) red.j--;
				}
				else {
					for (int k = blue.j + 1; k < M; k++) {
						//#
						if (map[red.i][k] == -1) break;
						//.
						else if (map[red.i][k] == 0) blue.j++;
						//O
						else if (map[red.i][k] == 3) return;
					}
					for (int k = red.j + 1; k < M; k++) {
						//#
						if (map[red.i][k] == -1) break;
						//.
						else if (map[red.i][k] == 0) red.j++;
						//O
						else if (map[red.i][k] == 3) {
							if (result > countOfSlope) result = countOfSlope;
							return;
						}
					}
					if (red.j == blue.j) blue.j--;
				}
			}
			else {
				//red
				for (int k = red.j + 1; k < M; k++) {
					//#
					if (map[red.i][k] == -1) break;
					//.
					else if (map[red.i][k] == 0) red.j++;
					//O
					else if (map[red.i][k] == 3) {
						if (countOfSlope < result) result = countOfSlope;
						return;
					}
				}
				//blue
				for (int k = blue.j + 1; k < M; k++) {
					//#
					if (map[blue.i][k] == -1) break;
					//.
					else if (map[blue.i][k] == 0) blue.j++;
					//O
					else if (map[blue.i][k] == 3) return;
				}
			}
		}
		//go
		if (countOfSlope != 10) {
			go(1, countOfSlope + 1, map, red, blue);
			go(2, countOfSlope + 1, map, red, blue);
			go(3, countOfSlope + 1, map, red, blue);
			go(4, countOfSlope + 1, map, red, blue);
		}			
	}
}
int main() {
	cin >> N >> M;
	//# = -1, . = 0, R = 1, B = 2, O = 3
	vector < vector <int> > map(M);
	position red, blue;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == '#') map[i].push_back(-1);
			else if (str[j] == '.') map[i].push_back(0);
			else if (str[j] == 'R') {
				map[i].push_back(0);
				red.i = i;
				red.j = j;
			}
			else if (str[j] == 'B') {
				map[i].push_back(0);
				blue.i = i;
				blue.j = j;
			}
			else {
				map[i].push_back(3);
				hole.i = i;
				hole.j = j;
			}
		}
	}
	go(1, 1, map, red, blue);
	go(2, 1, map, red, blue);
	go(3, 1, map, red, blue);
	go(4, 1, map, red, blue);
	if (result == 11) result = -1;
	cout << result;
	return 1;
}