#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>	//qsort
#include <string.h>	//strlen , strcpy
#include <malloc.h>	//malloc

typedef struct {
	int len;		//�Է¹��� ���ڿ��� ���� ���ϴ� �뵵
	char str[51];	//�Է¹��� ���ڿ� ����
}words;

int compare(const void* a, const void* b) {		//qsort �Լ��� ����ϱ� ���� compare�Լ�
	words astr = *(words*)a;
	words bstr = *(words*)b;
	int len_a = strlen(astr.str);
	int len_b = strlen(bstr.str);

	if (len_a != len_b) return (len_a - len_b);
	return strcmp(astr.str, bstr.str);

	//a �� b���� ���ڿ��� ���̰� ���� ��, ���������� �տ� ������ ������ ��ȯ��
	//a�� b�� ���ڿ��� ���� ������ a�� b�� ���ڿ��� ���� ��ȯ��.
	//���� ����� �켱������ a�� b���� �տ��ִٸ� ������, ���ٸ� 0��, b�� a���� �տ��ִٸ� ����� ��ȯ
}


int main() {
	words* word;	//�Է¹��� �� �ִ� ���ڿ��� ������ 20000���̱� ������ �����Ҵ��� ���� ����
	char tmp[51] = {0,};	//�ߺ��Ǿ� �Է¹޴� ���ڿ��� �ɷ����� ���� ���� �ӽ÷� ���ڿ��� �Է¹��� ����
	int n, flag=0,cnt=0;	//��ó�� �Է¹��� ���ڿ��� ������ �ޱ����� n, �Է¹��� ���ڿ��� �ߺ��Ǿ����� �ƴ����� Ȯ���ϱ� ���� flag
	// �ߺ��� ���ڿ����� ����� �ߺ����� ���� ���ڿ��鸸 ���� ���ο� �迭�� ���ʴ�� �ֱ� ���� cnt
	// ���� �ߺ��� ���ڿ��� �Է¹����� �ݵ�� cnt�� ���� n���� ����


	scanf("%d", &n);		//�Է��� ���ڿ��� ���� �ޱ�
	word= (words*)malloc(sizeof(words)*n);	// �Է¹��� ���ڿ��� ���� ��ŭ ����ü �迭 �����Ҵ�, free(word) �ݵ�� ����� ��

	for (int i = 0; i < n; i++) {
		scanf("%s", tmp);		//�ӽ� ����

		for (int j = 0; j < i; j++) {	//�ߺ��� ���ڿ� �˼�
			if (strcmp(word[j].str, tmp) == 0) {
				flag = 1;	//�ߺ��� ���ڿ��� �Է¹����� flag = 1 �� ��
				break;		//�׸��� for�� Ż��
			}
		}
		if (flag == 0) {	//for �� ���� �� flag �� Ȯ���ؼ� �ߺ��� ���ڿ��� �ƴ� ���
			strcpy(word[cnt].str, tmp);	//�ߺ����� ���� ���ڿ��鸸 �����ϴ� �迭�� ī��
			cnt++;						//����Ǿ����Ƿ� �� +1
		}
		flag = 0;			//�ٽ� �񱳸� ���� flag = 0 ���� �ʱ�ȭ
	}

	qsort(word, cnt, sizeof(words), compare);		//qsort �Լ� ����

	for (int i = 0; i < cnt; i++) {
		printf("%s\n", word[i].str);	//���ĵ� ������ ���ڿ����� ���
	}

	free(word);	//�����Ҵ� �� ����ü �迭�� �Ҵ� ���� ����
}

// ����ü �迭�� �ƴ� 2���� �迭�� �Է¹��� ���ڿ��� ������, �� ���� ���� �� �� ������, ����ü �迭�� ���� Ǯ����

