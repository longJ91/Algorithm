#include "stdafx.h"



#include <stdio.h>

int N[201][201];
int C[201];


int main(void) {
	/* �Ʒ� freopen �Լ��� sample_input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� sample_input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�
	�� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
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
		int n, l;
		int s, e;
		int result;

		scanf("%d", &n);
		scanf("%d", &l);

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) N[i][j] = 0;
			C[i] = 0;
		}

		for (int i = 1; i <= l; i++) {
			scanf("%d%d", &s, &e);
			N[s][e] = N[e][s] = 1;
		}

		int pass = n;

		while (1) {
			for (int i = 1; i <= n; i++) {
				if (C[i] == 0) {
					for (int j = 1; j <= n; j++) {
						if (N[i][j] == 1 && C[j] != 0) {
							C[i] = -(C[j]);
							pass--;
							break;
						}
						if (j == n && C[i] == 0) {
							C[i] = 1;
							pass--;
						}
					}
				}
			}

			for (int i = 1; i <= n; i++) {
				if (C[i] != 0) {
					for (int j = 1; j <= n; j++) {
						if (N[i][j] == 1 && C[i] == C[j]) {
							pass = -1;
							break;
						}
					}
				}
				if (pass == -1) break;
			}

			if (pass == -1) {
				result = 0;
				break;
			}
			if (pass == 0) {
				result = 1;
				break;
			}
		}


		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%d\n", test_case, result);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}