// ¹®Á¦ : https://www.acmicpc.net/problem/1157
//
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	string str;
	int len;
	cin >> str;
	len = str.size();
	map<char, int> set;
	int max = 1;
	for (int i = 0; i < len; i++){
		char temp;
		temp = str.at(i);
		if (temp < 97) temp += 32;
		if (set.count(temp) > 0) {
			set.find(temp)->second++;
			if (max < set.find(temp)->second) max = set.find(temp)->second;
		}
		else set.insert(make_pair(temp, 1));
	}
	len = set.size();
	int check = 0;
	char key;
	for (map<char, int>::iterator it = set.begin(); it != set.end(); ++it){
		if (max == it->second) {
			check++;
			key = it->first;
		}
	}
	char result;
	if (set.find(key)->first >= 97) result = set.find(key)->first - 32;
	else result = set.find(key)->first;
	check == 1 ? cout << result << endl: cout << "?" << endl;
	return 0;
}