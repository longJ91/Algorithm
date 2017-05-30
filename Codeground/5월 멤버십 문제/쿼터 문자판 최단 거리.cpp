/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <string>

using namespace std;

string Answer;
string Set[3][7] = { {"Q","W","E","R","T","Y","U"},{ "A","S","D","F","G","H","J" },{ "Z","X","C","V", "B","N","M" } };

int main(int argc, char** argv)
{
	int T, test_case, L, row_index,col_index, temp_row,temp_col, S_row, S_col;
	string S,E, temp;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = "";
		cin >> S; cin >> E;
		temp = S;
		Answer += temp;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 8; j++) {
				if (Set[i][j] == E) {
					row_index = i;
					col_index = j;
					i = 3;
					j = 8;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 8; j++) {
				if (Set[i][j] == S) {
					S_row = i;
					S_col = j;
					i = 3;
					j = 8;
				}
			}
		}
		while (temp != E) {
			if (temp == "H") {
				temp = "U";
				Answer += temp;
			}
			else if (temp == "J"){ 
				temp = "Q";
				Answer += temp;
			}
			else if (temp == "N"){
				temp = "J";
				Answer += temp;
			}
			else {
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 8; j++) {
						if (Set[i][j] == temp) {
							temp_row = i;
							temp_col = j;
							i = 3;
							j = 8;
						}
					}
				}
				if(temp_col )


			}
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}