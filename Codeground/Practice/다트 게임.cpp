#include "stdafx.h"

/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <math.h>

using namespace std;

int Answer;

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
		int A, B, C, D, E, N, R = 0;
		cin >> A >> B >> C >> D >> E >> N;
		for (int i = 0; i < N; i++){
			double x, y, multiple = 1, base = 1;
			cin >> x >> y;
			double d = sqrt(pow(x, 2.0) + pow(y, 2.0));
			
			//배수 구분
			if (d < A) {
				R += 50;
				continue;
			}
			else if (d > B && d < C) multiple = 3;
			else if (d > D && d < E) multiple = 2;
			else if (d > E) continue;
			
			//기본 점수 구분
			double angle;
			angle = atan2(y, x) * 180 / 3.1415926535;
				if (-9 <= angle && angle < 9) base = 6;
			else if (-9 + 18 * 1 <= angle && angle < 9 + 18 * 1) base = 13;
			else if (-9 + 18 * 2 <= angle && angle < 9 + 18 * 2) base = 4;
			else if (-9 + 18 * 3 <= angle && angle < 9 + 18 * 3) base = 18;
			else if (-9 + 18 * 4 <= angle && angle < 9 + 18 * 4) base = 1;
			else if (-9 + 18 * 5 <= angle && angle < 9 + 18 * 5) base = 20;
			else if (-9 + 18 * 6 <= angle && angle < 9 + 18 * 6) base = 5;
			else if (-9 + 18 * 7 <= angle && angle < 9 + 18 * 7) base = 12;
			else if (-9 + 18 * 8 <= angle && angle < 9 + 18 * 8) base = 9;
			else if (-9 + 18 * 9 <= angle && angle < 9 + 18 * 9) base = 14;
			else if (-9 + 18 * 10 <= angle || angle < -(-9 + 18 * 10)) base = 11;
			else if (-9 + -(18 * 1) <= angle && angle < 9 + -(18 * 1)) base = 10;
			else if (-9 + -(18 * 2) <= angle && angle < 9 + -(18 * 2)) base = 15;
			else if (-9 + -(18 * 3) <= angle && angle < 9 + -(18 * 3)) base = 2;
			else if (-9 + -(18 * 4) <= angle && angle < 9 + -(18 * 4)) base = 17;
			else if (-9 + -(18 * 5) <= angle && angle < 9 + -(18 * 5)) base = 3;
			else if (-9 + -(18 * 6) <= angle && angle < 9 + -(18 * 6)) base = 19;
			else if (-9 + -(18 * 7) <= angle && angle < 9 + -(18 * 7)) base = 7;
			else if (-9 + -(18 * 8) <= angle && angle < 9 + -(18 * 8)) base = 16;
			else if (-9 + -(18 * 9) <= angle && angle < 9 + -(18 * 9)) base = 8;
			int temp = (base * multiple);
			R += temp;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		Answer = R;

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}