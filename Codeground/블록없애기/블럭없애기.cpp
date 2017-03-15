#include "stdafx.h"

// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>

int N[100002];
int n, temp;

int main(void) {
	/* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
	그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
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
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n%d\n", test_case,r);

	}
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}