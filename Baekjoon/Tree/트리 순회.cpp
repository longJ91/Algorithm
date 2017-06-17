// 문제 : https://www.acmicpc.net/problem/1991
// 트리 순회 방법 1) Preorder 2) Inorder 3) Postorder, 이진트리는 모두 가능. 단, 이진 트리가 아닐 경우에 Inorder는 불가능
#include <iostream>
#include <string>
using namespace std;
struct tree {
	int L, R;
}T[100];
int Preorder(int N) {

	cout << char(N + '0');
	if (T[N].L != 0) Preorder(T[N].L);
	if (T[N].R != 0) Preorder(T[N].R);
	return 1;
}
int Inorder(int N) {
	if (T[N].L != 0) Inorder(T[N].L);
	cout << char(N + '0');
	if (T[N].R != 0) Inorder(T[N].R);
	return 1;
}
int Postorder(int N) {
	if (T[N].L != 0) Postorder(T[N].L);
	if (T[N].R != 0) Postorder(T[N].R);
	cout << char(N + '0');
	return 1;
}
int main() {
	int N;
	
	cin >> N;
	for (int i = 0; i < N; i++){
		string node, l, r;
		cin >> node >> l >> r;
		char NODE, L, R;
		NODE = node.at(0);
		L = l.at(0);
		R = r.at(0);
		if (L != '.') T[NODE - '0'].L = L - '0';
		if (R != '.') T[NODE - '0'].R = R - '0';
	}
	Preorder('A' - '0');
	cout << endl;
	Inorder('A' - '0');
	cout << endl;
	Postorder('A' - '0');
	cout << endl;
	return 0;
}