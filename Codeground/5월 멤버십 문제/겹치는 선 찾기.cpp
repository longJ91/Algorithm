/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int Answer;
bool compare(const pair<int, int>& firstElem, const pair<int, int>& secondElem) {
	if (firstElem.first < secondElem.first) return true;
	return false;
}
bool compare2(const int& a, const int& b)
{
	return a > b;
};
int main(int argc, char** argv)
{
	int T, test_case, num, A, B;
	vector<pair<int, int>> temp;
	queue<int> a, Set;
	vector<int> b;

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
		Answer = 0;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> A; cin >> B;
			temp.push_back(make_pair(A, B));
		}

		sort(temp.begin(), temp.end(), compare);

		for (int i = 0; i < num; i++) {
			a.push(temp.at(i).first); b.push_back(temp.at(i).second);
		}
		sort(b.begin(), b.end(), compare2);
		for (int i = 1; i < 100001 + 1; i++) {
			while ((!a.empty() && i == a.front())) {
				Set.push(1);
				a.pop();
			}
			while (!b.empty() && i == b.back()) {
				Set.pop();
				b.pop_back();
			}
			if (Answer < Set.size()) Answer = Set.size();
		}
		temp.clear();
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}