#include "stdafx.h"
/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

long long Answer;
int D[50001][101];
int L[50001];
int main(int argc, char** argv)
{
	int T, test_case;
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
		int n, k, l, temp, sum;
		cin >> n >> k >> l;
		for (int i = 1; i <= l; i++) {
			cin >> temp;
			L[temp] = 1;
		}
		for (int i = 1; i <= k; i++) {
			if (L[i] == 1)continue;
			D[i][i] = 1;
			D[i][0] = 1;
		}
		for (int i = 1; i <= n; i++) {
			if (L[i] == 1) continue;
			sum = 0;
			for (int j = 1; j <= k && i - j > 0; j++) {
				if (L[i - j] == 1) continue;
				D[i][j] += (D[i - j][0] + 1000000009 - D[i - j][j]) % 1000000009;
				sum = (sum + D[i][j]) % 1000000009;
			}
			D[i][0] += sum % 1000000009;
		}
		Answer = D[n][0];
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;

		for (int i = 1; i <= 50000; i++) {
			L[i] = 0;
			for (int j = 0; j <= 100; j++) D[i][j] = 0;
		}
	}

	return 0;//Your program should return 0 on normal termination.
}