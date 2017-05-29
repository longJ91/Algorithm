// ¹®Á¦ : https://www.acmicpc.net/problem/10820
#include <iostream>
#include <string>

using namespace std;

int main() {

	string str,result = "";
	int low, up, number, space;
	
	while (getline(cin, str)) {
		if(str == "") break;
		low = up = number = space = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str.at(i)==' ') space++;
			else if (str.at(i) >= 48 && str.at(i) <= 57) number++;
			else if (str.at(i) >= 65 && str.at(i) <= 90) up++;
			else low++;
		}
		result += to_string(low);
		result += " ";
		result += to_string(up);
		result += " ";
		result += to_string(number);
		result += " ";
		result += to_string(space);
		result += "\n";
	}
	
	cout << result;
	cout << "";

	return 1;
}