// codeground.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stdlib.h>

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
		int N, K;
		int* stone;
		int max_distanse, result, position;

		scanf("%d",&N);

		stone = (int*)malloc(sizeof(int)*N);

		result = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &(stone[i - 1]));
			//���� ó�� �Է� �޾����� �ִ� �Ÿ� �ʱ�ȭ
			if (i == 1)
				max_distanse = 0;
			//���� �� ��ġ�� ���� �� ��ġ�� ���ؼ� �Ÿ��� ���ϰ�, �� ���� ���� �ְ� �Ÿ����� Ŭ ��� �ִ� �Ÿ��� ����
			else {
				if (max_distanse < stone[i - 1] - stone[i - 2])
					max_distanse = stone[i - 1] - stone[i - 2];
			}
		}
		
		scanf("%d", &K);

		//����� ���� ��ġ�� �ʱ�ȭ
		result = 0;
		position = 0;
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		//���� ���� ���� �ʰ��� �� ������ �Ÿ��� ���� �� ��� -1 ���
		if (max_distanse > K)
			printf("%d\n", -1);
		else {
			//���� ����ŭ loop�� ���� ���� �ִ�� �̵� �� �� �ִ� ���� �̵��ϸ� result ���� ����
			for (int j = 0; j < N; j++)
			{
				//���� ��ġ���� ���� ������ ������ �Ѿ�� ���� ���� �̵��Ѵ�.
				if (position + K < stone[j]) {
					position = stone[j-1];
					result++;
				}
				//���� ��ġ���� ���� ������ �ִ� ������ ���� ��Ÿ���� �ٷ� �̵��Ѵ�.
				else if(position + K == stone[j]){
					position = stone[j];
					result++;
				}
				//���� ��ġ��, �������� �Ÿ� ���̰� �ִ� ���� Ƚ������ ������ �ٷ� �� �������� �Ѿ��.
				if (position + K >= stone[N - 1]) {
					result++;
					break;
				}
			}
			//��� ���
			printf("%d\n", result);
		}
		//�޸� ����
		free(stone);
	}
	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}