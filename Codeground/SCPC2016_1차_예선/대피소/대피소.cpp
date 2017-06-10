#include "stdafx.h"
#include <stdio.h>

int N, M, K, CN;
int m[2001][2001] ;
int RN[2001] ;
int RV[2001] ;
int k[2001] ;
int s, e, v;

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
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.

		for (int i = 0; i < 2001; i++){
			for (int j = 0; j < 2001; j++) {
				m[i][j] = 0;
			}
			RN[i] = k[i] = 0;
			RV[i] = 100000;
		}

		scanf("%d%d%d", &N, &M, &K);

		for (int i = 1; i <= M; i++){
			scanf("%d%d%d", &s, &e, &v);
			m[s][e] = m[e][s] = v;
		}

		for (int i = 1; i <= K; i++){
			scanf("%d", &v);
			RV[v] = 0;
			RN[v] = v;
			k[i] = v;
		}

		CN = N;

		int pass;

		while (1) {
			pass = 1;

			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (i == j ) continue;
					if (RV[i] + m[i][j] < RV[j] && m[i][j] != 0) {
						RV[j] = RV[i] + m[i][j];
						RN[j] = RN[i];
						pass = 0;
					}
				}
			}
			if (pass == 1)break;
		}

		int rv, rn;
		rv = rn = 0;

		for (int i = 1; i <= N; i++){
			rv += RV[i];
			rn += RN[i];
		}

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%d\n%d\n", test_case,rv,rn);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}