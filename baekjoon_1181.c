#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>	//qsort
#include <string.h>	//strlen , strcpy
#include <malloc.h>	//malloc

typedef struct {
	int len;		//입력받은 문자열의 길이 구하는 용도
	char str[51];	//입력받은 문자열 저장
}words;

int compare(const void* a, const void* b) {		//qsort 함수를 사용하기 위한 compare함수
	words astr = *(words*)a;
	words bstr = *(words*)b;
	int len_a = strlen(astr.str);
	int len_b = strlen(bstr.str);

	if (len_a != len_b) return (len_a - len_b);
	return strcmp(astr.str, bstr.str);

	//a 가 b보다 문자열의 길이가 같을 때, 사전순으로 앞에 있으면 음수를 반환함
	//a와 b가 문자열이 같지 않으면 a와 b의 문자열의 차를 반환함.
	//쉽게 얘기해 우선순위가 a가 b보다 앞에있다면 음수를, 같다면 0을, b가 a보다 앞에있다면 양수를 반환
}


int main() {
	words* word;	//입력받을 수 있는 문자열의 개수가 20000개이기 때문에 동적할당을 위해 선언
	char tmp[51] = {0,};	//중복되어 입력받는 문자열을 걸러내기 위해 먼저 임시로 문자열을 입력받을 변수
	int n, flag=0,cnt=0;	//맨처음 입력받을 문자열의 개수를 받기위한 n, 입력받은 문자열이 중복되었는지 아닌지를 확인하기 위한 flag
	// 중복된 문자열들은 지우고 중복되지 않은 문자열들만 따로 새로운 배열에 차례대로 넣기 위한 cnt
	// 따라서 중복된 문자열을 입력받으면 반드시 cnt의 값은 n보다 작음


	scanf("%d", &n);		//입력할 문자열의 개수 받기
	word= (words*)malloc(sizeof(words)*n);	// 입력받을 문자열의 개수 만큼 구조체 배열 동적할당, free(word) 반드시 해줘야 함

	for (int i = 0; i < n; i++) {
		scanf("%s", tmp);		//임시 저장

		for (int j = 0; j < i; j++) {	//중복된 문자열 검수
			if (strcmp(word[j].str, tmp) == 0) {
				flag = 1;	//중복된 문자열을 입력받으면 flag = 1 이 됨
				break;		//그리고 for문 탈출
			}
		}
		if (flag == 0) {	//for 문 실행 후 flag 값 확인해서 중복된 문자열이 아닌 경우
			strcpy(word[cnt].str, tmp);	//중복되지 않은 문자열들만 저장하는 배열에 카피
			cnt++;						//저장되었으므로 값 +1
		}
		flag = 0;			//다시 비교를 위해 flag = 0 으로 초기화
	}

	qsort(word, cnt, sizeof(words), compare);		//qsort 함수 실행

	for (int i = 0; i < cnt; i++) {
		printf("%s\n", word[i].str);	//정렬된 이후의 문자열들을 출력
	}

	free(word);	//동적할당 한 구조체 배열의 할당 종료 선언
}

// 구조체 배열이 아닌 2차원 배열로 입력받은 문자열의 순서와, 그 값을 저장 할 수 있지만, 구조체 배열로 문제 풀었음

