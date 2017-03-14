#include "stdafx.h"

// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>

int N[100002];
int n, temp;

int main(void) {
	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
	�� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		int r, pass; 

		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) scanf("%d", &N[i]);
		

		N[0] = N[n + 1] = r = temp = 0;

		int a, b;
		int A, B, C;

		while (1) {
			pass = 1;
			for (int i = 1; i <= n; i++) {
				if (i == 1) {
					A = N[0];
					B = N[1];
					C = N[2];
				}
				else {
					A = B;
					B = C;
					C = N[i+1];
				}
				if (B != 0) {
					N[i]--;

					a = A < C ? A : C;

					N[i] = N[i] > a ? a : N[i];
					
					pass = 0;
				}
				temp += B;
			}
			if (pass == 1 || temp == 0 ) break;
			r++;
			temp = 0;
		}
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%d\n", test_case,r);

	}
	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}