#include<vector>
using namespace std;
int min(const int a, const int b) {
	if (a > b) return b;
	return a;
}
int solution(vector<vector<int>> board)
{
	int answer = 0;
	int row, column;
	row = board.size();
	column = board[0].size();
	for (int r = 0; r < row; r++) for (int c = 0; c < column; c++) {
		if (r == 0 || c == 0) {
			if (board[r][c]) if (answer < board[r][c]) answer = 1;
		}
		else {
			if (board[r][c]) board[r][c] = min(min(board[r - 1][c], board[r][c - 1]), board[r - 1][c - 1]) + 1;
		}
		if (answer < board[r][c]) answer = board[r][c];
	}

	return answer * answer;
}