// 문제 : https://www.acmicpc.net/problem/2873
// Greedy ?
#include <iostream>
#include <string>
using namespace std;
int map[1001][1001];
int main() {
	int R, C;
	cin >> R >> C;
	for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) cin >> map[i][j];
	string result="";
	//홀 홀
	if (R % 2 == 1 && C % 2 == 1) {
		for (int r = 1; r <= R; r++) for (int c = 1; c <= C; c++) {
			if (r == R && c == C) break;
			if (r % 2 == 1) c != C ? result += "R" : result += "D";
			else c != C ? result += "L" : result += "D";
		}
	}
	//짝 짝
	else if (R % 2 == 0 && C % 2 == 0) {
		int value = 1000;
		pair<int, int> position;
		//Find black position
		for (int r = 1; r <= R; r++) for (int c = 1; c <= C; c++) {
			if((r % 2 == 1 && c % 2 == 0) || (r % 2 == 0 && c % 2 == 1)) if (value > map[r][c]) {
				value = map[r][c];
				position.first = r;
				position.second = c;
			}
		}
		map[position.first][position.second] = -1;
		int flag = 1;
		for (int r = 1; r <= R; r++) for (int c = 1; c <= C; c++) {
			if (r + 1 == position.first) {
				int tempFlag = 1;
				//R 못감
				if (r % 2 == 0) {
					for (int column = C; column > 0; column--) for (int row = r; row <= r + 1; row++) {
						if ((column == 1 && row == r + 1)) {
							result += "D";
							r++;
							c = C;
							break;
						}
						//D 할때만 black position 만남
						if (column % 2 == 0) {
							if (tempFlag == 1) {
								//D
								if (row == r) {
									if (map[row + 1][column] != -1) result += "D";
									else {
										tempFlag = 0;
										continue;
									}
								}
								//L
								else result += "L";
							}
							else {
								//U
								if (row == r) result += "U";
								//L
								else result += "L";
							}
						}
						else {
							if (tempFlag == 1) {
								//U
								if (row == r) result += "U";
								//L
								else result += "L";
							}
							else {
								//D
								if (row == r) result += "D";
								//L
								else result += "L";
							}
						}
					}
				}
				//L 못감
				else {
					for (int column = 1; column <= C; column++) for (int row = r; row <= r + 1; row++) {
						if (column == C && row == r + 1) {
							result += "D";
							r++;
							c = C;
							break;
						}
						//D 할때만 black position 만남
						if (column % 2 == 1) {
							if (tempFlag == 1) {
								//D
								if (row == r) {
									if (map[row + 1][column] != -1) result += "D";
									else {
										tempFlag = 0;
										continue;
									}
								}
								//R
								else result += "R";
							}
							else {
								//U
								if (row == r) result += "U";
								//R
								else result += "R";
							}
						}
						else {
							if (tempFlag == 1) {
								//U
								if (row == r) result += "U";
								//R
								else result += "R";
							}
							else {
								//D
								if (row == r) result += "D";
								//R
								else result += "R";
							}
						}
					}
				}
				flag = 0;
			}
			else if (r == position.first) {
				int tempFlag = 1;
				//R 못감
				if (r % 2 == 0) {
					/*for (int column = C; column > 0; column--) for (int row = r; row <= r + 1; row++) {
						//tempFlag = 1 D, L
						//tempFlag = 0 U, L
						//D 할때만 black position 만남
						if (column % 2 == 0) {
							if (tempFlag == 1) {
								//D
								if (row == r) {
									if (map[row + 1][column] != -1) result += "D";
									else {
										tempFlag = 0;
										continue;
									}
								}
								//L
								else result += "L";
							}
							else {
								//L
								if (row == r) result += "L";
								//U
								else result += "U";
							}
						}
						else {
							if (tempFlag == 1) {
								//U
								if (row == r + 1) result += "U";
								//L
								else result += "L";
							}
							else {
								//D
								if (row == r) result += "D";
								//L
								else result += "L";
							}
						}
					}*/
				}
				//L 못감
				else {
					for (int column = 1; column <= C; column++) for (int row = r; row <= r + 1; row++) {
						if (column == C && row == r + 1) {
							result += "D";
							r++;
							c = C;
							break;
						}
						//U 할때만 black position 만남
						if (column % 2 == 1) {
							if (tempFlag == 1) {
								//D
								if (row == r) {
									result += "D";
								}
								//R
								else result += "R";
							}
							else {
								//U
								if (row == r) result += "U";
								//R
								else result += "R";
							}
						}
						else {
							if (tempFlag == 1) {
								//U
								if (row == r) {
									if(map[row][column] != -1) result += "U";
									else {
										tempFlag = 0;
										continue;
									}
								}
								//R
								else result += "R";
							}
							else {
								//D
								if (row == r) result += "D";
								//R
								else result += "R";
							}
						}
					}
				}
				flag = 0;
			}
			else {
				if(flag == 1){
					if (r == R && c == C) break;
					if (r % 2 == 1) c != C ? result += "R" : result += "D";
					else c != C ? result += "L" : result += "D";
				}
				else {
					if (r == R && c == C) break;
					if (r % 2 == 1) c != C ? result += "L" : result += "D";
					else c != C ? result += "R" : result += "D";
				}
			}
		}
		if (value != 1000) if (result.size() == (R * C) - 1) result = result.substr(0, result.size() - 1);
	}
	//홀 짝
	else {
		if (R % 2 == 1) {
			for (int r = 1; r <= R; r++) for (int c = 1; c <= C; c++) {
				if (r == R && c == C) break;
				if (r % 2 == 1) c != C ? result += "R" : result += "D";
				else c != C ? result += "L" : result += "D";
			}
		}
		else {
			for (int c = 1; c <= C; c++) for (int r = 1; r <= R; r++) {
				if (r == R && c == C) break;
				if (c % 2 == 1) r != R ? result += "D" : result += "R";
				else r != R ? result += "U" : result += "R";
			}
		}
	}
	cout << result;
	return 1;
}