#include <string>
#include <vector>

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
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int len = cities.size();
	int flag = 1;

	for (int i = 0; i<len; i++) {
		int tempLen = cities[i].size();
		flag = 1;
		ToLower(cities[i]);
		for (int j = i - 1; j > i - 1 - cacheSize && j >= 0; j--) {
			if (0 == cities[i].compare(cities[j])) {
				answer += 1;
				flag = 0;
			}
			if (flag == 0) break;
		}
		if (flag) answer += 5;
	}
	return answer;
}
