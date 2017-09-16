#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i<n; i++) {
		string result = "";
		int temp;
		temp = (arr1[i] | arr2[i]);
		for (int j = 0; j<n; j++) {
			(temp & 1) == 1 ? result += "#" : result += " ";
			temp /= 2;
		}
		reverse(result.begin(), result.end());
		answer.push_back(result);
	}
	return answer;
}