#include <string>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int first = 0, second = 0, thrid = 0;
	int len = dartResult.size();
	int flag = 1, index = 1;
	first = dartResult.at(0) - '0';
	if (dartResult.at(1) == '0') {
		first = 10;
		index = 2;
	}
	for (int i = index; i<len; i++) {
		if (dartResult.at(i) == '0' || dartResult.at(i) == '1' || dartResult.at(i) == '2' || dartResult.at(i) == '3' || dartResult.at(i) == '4' || dartResult.at(i) == '5' || dartResult.at(i) == '6' || dartResult.at(i) == '7' || dartResult.at(i) == '8' || dartResult.at(i) == '9') {
			flag++;
			if (flag == 2) {
				second = dartResult.at(i) - '0';
				if (dartResult.at(i + 1) == '0') {
					second = 10;
					i++;
				}
			}
			else if (flag == 3) {
				thrid = dartResult.at(i) - '0';
				if (dartResult.at(i + 1) == '0') {
					thrid = 10;
					i++;
				}
			}
			continue;
		}
		if (flag == 1) {
			if (dartResult.at(i) == 'D') first = first * first;
			else if (dartResult.at(i) == 'T') first = first * first * first;
			else if (dartResult.at(i) == '*') first *= 2;
			else if (dartResult.at(i) == '#') first *= -1;
		}
		else if (flag == 2) {
			if (dartResult.at(i) == 'D') second = second * second;
			else if (dartResult.at(i) == 'T') second = second * second * second;
			else if (dartResult.at(i) == '*') {
				second *= 2;
				first *= 2;
			}

			else if (dartResult.at(i) == '#') {
				second *= -1;
			}
		}
		else if (flag == 3) {
			if (dartResult.at(i) == 'D') thrid = thrid * thrid;
			else if (dartResult.at(i) == 'T') thrid = thrid * thrid * thrid;
			else if (dartResult.at(i) == '*') {
				thrid *= 2;
				second *= 2;

			}

			else if (dartResult.at(i) == '#') {
				thrid *= -1;
			}
		}
	}
	answer = first + second + thrid;
	return answer;
}