#include <string>
#include <map>


using namespace std;
//http://blog.naver.com/PostView.nhn?blogId=flower_excel&logNo=20207430673&categoryNo=0&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1 ÂüÁ¶
void ToLower(string& str)
{
	bool bStartExtension = false;

	std::string::iterator it = str.begin();
	while (it != str.end())
	{
		unsigned char c = *it;

		if (bStartExtension)
		{
			bStartExtension = false;
		}
		else
		{
			if (c < 128 && !bStartExtension)
			{
				*it = tolower(c);
			}
			else
			{
				bStartExtension = true;
			}
		}
		it++;
	}
}
int min(const int a, const int b) {
	if (a > b) return b;
	return a;
}
int max(const int a, const int b) {
	if (a < b) return b;
	return a;
}
int solution(string str1, string str2) {
	int answer = 0;
	ToLower(str1);
	ToLower(str2);
	map<string, int> first;
	map<string, int> second;

	int len1 = str1.size(), len2 = str2.size();
	for (int i = 0; i<len1 - 1; i++) {
		if ((str1.at(i) >= 97 && str1.at(i) <= 122) && (str1.at(i + 1) >= 97 && str1.at(i + 1) <= 122)) {
			string str = "";
			str += str1.at(i);
			str += str1.at(i + 1);

			if (first.count(str) > 0) first.find(str)->second++;
			else first.insert(make_pair(str, 1));
		}
	}
	for (int i = 0; i<len2 - 1; i++) {
		if ((str2.at(i) >= 97 && str2.at(i) <= 122) && (str2.at(i + 1) >= 97 && str2.at(i + 1) <= 122)) {
			string str = "";
			str += str2.at(i);
			str += str2.at(i + 1);

			if (second.count(str) > 0) second.find(str)->second++;
			else second.insert(make_pair(str, 1));
		}
	}
	double same, sum, result;
	same = sum = result = 0;
	len1 = first.size(), len2 = second.size();
	for (map<string, int>::iterator it = first.begin(); it != first.end(); ++it) {
		string s1;
		int v1;
		s1 = it->first;
		v1 = it->second;
		if (second.count(s1) > 0) {
			same += min(v1, second.find(s1)->second);
			sum += max(v1, second.find(s1)->second);
		}
		else {
			sum += v1;
		}
	}
	for (map<string, int>::iterator it = second.begin(); it != second.end(); ++it) {
		string s1;
		int v1;
		s1 = it->first;
		v1 = it->second;
		if (!(first.count(s1) > 0)) {
			sum += v1;
		}
	}
	if (same == 0 && sum == 0) result = 1;
	else result = same / sum;

	answer = result * 65536;

	return answer;
}
