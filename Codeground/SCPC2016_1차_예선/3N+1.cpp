#include "stdafx.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	cin >> T;	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		int N;
		cin >> N;
		unsigned long long min = 0;
		unsigned long long max = 1;
		for (int i = 0; i < N; i++)
			max *= 2;

		for (unsigned long long i = 1; i <= max; i++) {
			unsigned long long Tm = i; /// i Tm Ȯ���� ������ ���� ��
			int j = 0;
			while (j <= N) { // j�� Ƚ��
				if (Tm == 1)
					break;
				else if (Tm % 2 == 0)
					Tm /= 2;
				else
					Tm = 3 * Tm + 1;
				j++;
			}
			if (Tm == 1 && N == j) { // Ƚ���� N�̵Ǹ� break
				min = i;
				break;
			}
		}

		printf("Case #%d\n", test_case);
		printf("%llu %llu\n", min, max);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}