#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	string B[30][30];
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			B[i][j] = board[i][j];
		}
	}

	int flag = 1;
	while (flag == 1) {
		flag = 0;
		int deleteSet[30][30];
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (i == 0 || j == 0 || B[i][j] == "") continue;
				string temp = B[i][j];
				if (B[i - 1][j] == temp && B[i][j - 1] == temp && B[i - 1][j - 1] == temp) {
					deleteSet[i][j] = deleteSet[i - 1][j] = deleteSet[i][j - 1] = deleteSet[i - 1][j - 1] = -1;
					flag = 1;
				}
			}
		}
		if (flag == 1) {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j<n; j++) {
					if (deleteSet[i][j] == -1) {
						B[i][j] = "";
						answer++;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = m - 1; j > 0; j--) {
					if (B[j][i] == "") {
						for (int k = j - 1; k >= 0; k--) {
							if (B[k][i] != "") {
								B[j][i] = B[k][i];
								B[k][i] = "";
								break;
							}
						}
					}
				}
			}
			for (int i = 0; i < m; i++) {
				for (int j = 0; j<n; j++) {
					deleteSet[i][j] = 0;
				}
			}
		}
	}

	return answer;
}
