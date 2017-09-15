#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<string> strs, string t)
{
	int answer = 0;
	int len = strs.size();
	set<string> A;
	for (int i = 0; i<len; i++) A.insert(strs[i]);
	len = t.size();
	vector<int> dp(len + 1, -1);
	dp[0] = 0;
	for (int i = 1; i <= len; i++) {
		if (dp[i - 1] != -1) {
			for (int k = 1; k <= 5; k++) {
				if (i + k - 1 <= len) {
					if (A.count(t.substr(i - 1, k)) > 0) {
						if (dp[i + k - 1] > dp[i - 1] + 1 || dp[i + k - 1] == -1) dp[i + k - 1] = dp[i - 1] + 1;
					}
				}
			}
		}
	}
	answer = dp[len];
	return answer;
}
int main() {

	vector<string> strs = { "app","ap","p","l","e","ple","pp" };
	string t = "apple";

	cout << solution(strs, t);

	return 1;
}