// codeground.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>

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
		int N, K;
		int* stone;
		int max_distanse, result, position;

		scanf("%d",&N);

		stone = (int*)malloc(sizeof(int)*N);

		result = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &(stone[i - 1]));
			//가장 처음 입력 받았을때 최대 거리 초기화
			if (i == 1)
				max_distanse = 0;
			//이전 돌 위치와 현재 돌 위치를 비교해서 거리를 구하고, 그 값이 현재 최고 거리보다 클 경우 최대 거리를 변경
			else {
				if (max_distanse < stone[i - 1] - stone[i - 2])
					max_distanse = stone[i - 1] - stone[i - 2];
			}
		}
		
		scanf("%d", &K);

		//결과와 현재 위치를 초기화
		result = 0;
		position = 0;
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		//점프 가능 값을 초과한 돌 사이의 거리가 존재 할 경우 -1 출력
		if (max_distanse > K)
			printf("%d\n", -1);
		else {
			//돌의 수만큼 loop를 돌며 가장 최대로 이동 할 수 있는 돌로 이동하며 result 값을 도출
			for (int j = 0; j < N; j++)
			{
				//현재 위치에서 점프 가능한 범위를 넘어서면 이전 돌로 이동한다.
				if (position + K < stone[j]) {
					position = stone[j-1];
					result++;
				}
				//현재 위치에서 점프 가능한 최대 범위의 돌이 나타나면 바로 이동한다.
				else if(position + K == stone[j]){
					position = stone[j];
					result++;
				}
				//현재 위치와, 도착지점 거리 차이가 최대 점프 횟수보다 적으면 바로 끝 지점으로 넘어간다.
				if (position + K >= stone[N - 1]) {
					result++;
					break;
				}
			}
			//결과 출력
			printf("%d\n", result);
		}
		//메모리 해제
		free(stone);
	}
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}