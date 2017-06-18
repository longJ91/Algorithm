#include "stdafx.h"

/* please use the chemical symbols in the periodic table below when you solve this problem.
"h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al",
"si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe",
"co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr",
"y","zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb",
"te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au",
"hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "rf", "db", "sg",
"bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd",
"pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "ac",
"th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md",
"no", "lr"   */

/*
you should use the statndard input/output

in order to receive a score properly.

do not use file input and output

please be very careful.
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

string answer;
map<string, int> set;
bool check[2][50004];
int main(int argc, char** argv)
{
	int t, test_case;
	/*
	the freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	to test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	you may remove the comment symbols(//) in the below statement and use it.
	use #include<cstdio> or #include <stdio.h> to use the function in your program.
	but before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);
	string symblos[] = {"h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al",
		"si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe",
		"co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr",
		"y","zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb",
		"te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au",
		"hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "rf", "db", "sg",
		"bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd",
		"pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "ac",
		"th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md",
		"no", "lr" };
	for (int i = 0; i < 114; i++) set.insert(pair<string,int>(symblos[i],1));
	
	cin >> t;
	for (test_case = 0; test_case < t; test_case++)
	{
		string temp;
		cin >> temp;
		int l = temp.size();
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) check[i][j] = true;
		for (int i = 2; i < l+2; i++) {
			if(i>2){
				if ((check[0][i - 1] == true || check[1][i - 1] == true) && (set.count(temp.substr(i - 2,1)) > 0)) check[0][i] = true;
				else check[0][i] = false;
				if ((check[0][i - 2] == true || check[1][i - 2] == true) && (set.count(temp.substr(i - 3, 2)) > 0)) check[1][i] = true;
				else check[1][i] = false;
			}
			else {
				if ((check[0][i - 1] == true || check[1][i - 1] == true) && (set.count(temp.substr(i - 2, 1)) > 0)) check[0][i] = true;
				else check[0][i] = false;
				check[1][i] = false;
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		implement your algorithm here.
		the answer to the case will be stored in variable answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		check[0][l + 2 -1] == true || check[1][l + 2 -1] == true ? answer = "YES" : answer = "NO";

		// print the answer to standard output(screen).
		cout << "case #" << test_case + 1 << endl;
		cout << answer << endl;
		for (int i = 0; i < 2; i++) for (int j = 0; j < 50004; j++) check[i][j] = false;

	}

	return 0;//your program should return 0 on normal termination.
}