#include "stdafx.h"
/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

int Answer;
long long A[100001];
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
		int M;
		long long min = 1000000000000, d = 0, sum =0;
		bool flag = true;
		cin >> M;
		for (int i = 1; i <= M; i++) cin >> A[i];
		for (int i = 2; i <= M; i++) {
			d = A[i] - A[i - 1];
			sum += d;
			if (i == 2) {
				min = d;
				continue;
			}
			if (i > 2) min > d ? min = d : 0;
			if (d != 0 && min == 0) flag = false;
			if (min > 0 && d == 0) flag == false;
			sum %= 1000000000000;
		}
		if (!flag) Answer = 0;
		else if (min == 0) Answer = 1;
		else {
			Answer = 0;
			//????
			for (long long d = 1; d <= min; d++) min % d == 0 ? Answer++ : 0;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}