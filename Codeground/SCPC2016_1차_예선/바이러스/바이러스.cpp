#include "stdafx.h"
#include <stdio.h>


int main(void) {
	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
	�� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
	freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� '�ð� �ʰ�'�� ���� ���� �Ǿ��� ��,
	printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	�ð� �ʰ� ������ ����� ��� ������ �ް��� �ϽŴٸ� "setbuf(stdout, NULL);" �� ����Ͻñ� �ٶ��ϴ�. */
	//setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		int K, L, N, M, CN;
		int k[101] = { 0, };
		int m[101][101] = { 0, };
		int result = 0;
		int s, e;

		scanf("%d%d", &K, &L);
		scanf("%d%d", &N, &M);

		for (int i = 1; i <= M; i++) {
			scanf("%d%d", &s, &e);

			m[s][e] = m[e][s] = 1;
			k[s] += 1;
			k[e] += 1;
		}

		CN = N;

		int pass;

		while (1) {
			pass = 1;

			if (N == 0) break;

			for (int i = 1; i <= CN; i++) {
				if (k[i] < K && k[i] != -1) {
					N--;
					k[i] = -1;
					result += i;
					pass = 0;
					for (int j = 1; j <= CN; j++) {
						if (m[i][j] == 1) {
							m[i][j] = m[j][i] = 0;
							k[j] -= 1;
						}
					}
					break;
				}
			}

			for (int i = 1; i <= CN; i++) {
				if (N - L < k[i] + 1 && k[i] != -1) {
					N--;
					k[i] = -1;
					result += i;
					pass = 0;
					for (int j = 1; j <= CN; j++) {
						if (m[i][j] == 1) {
							m[i][j] = m[j][i] = 0;
							k[j] -= 1;
						}
					}
					break;
				}
			}

			if (pass == 1) break;
		}

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%d\n", test_case, result);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}