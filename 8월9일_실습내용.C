//2019.8.9 삽입정렬 실습내용

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct sort {
	int num;
	struct sort *prev;
	struct sort *next;
}sort;

void init();
void input();
int num_cmp(int n, sort *tmp);
void view();
void sort_();
int cnt = 0;

sort *head = NULL, *tail = NULL;

void main() {
	init();
	srand((int)time(NULL));
	for (int i = 1; i <= 10; i++)
		input(); //랜덤 숫자 10개 만들기
	view(); //정렬되지 않은 숫자 보여주기
	sort_(); //숫자 정렬하기
	view(); //정렬된 숫자 보여주기
}
void init() {
	head = (sort*)malloc(sizeof(sort));
	head->prev = NULL;
	head->next = NULL;
	tail = head;
}
void input() {
	int num;
	sort *data = (sort*)malloc(sizeof(sort));
	//	sort *temp = head->next;
	data->next = NULL;
	data->prev = NULL;
	num = rand() % 50 + 1;
	while (num_cmp(num, head->next)) {
		num = rand() % 50 + 1;
	}
	data->num = num;
	tail->next = data;
	data->prev = tail;
	tail = data;
}

int num_cmp(int n, sort *tmp) {
	while (tmp != NULL) {
		if (tmp->num == n)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

void view() {
	sort* show = head->next;
	while (show != NULL) {
		printf("%d ", show->num);
		show = show->next;
	}
	printf("\n");
}

void sort_() {//삽입정렬
	int cnt = 0;
	sort* read = head->next; //첫 숫자를 기준으로 설정
	sort* cmp, *temp;
	while (read->next != NULL) {
		printf("현재기준점 = %d\n", read->num);
		cmp = read->next;
		while (cmp != NULL) {
			printf("비교중 = %d %d\n", read->num, cmp->num);
			if (read->num > cmp->num) {
				printf("cmp를 read 앞으로\n");
				temp = cmp->prev; //temp = cmp->next가 아니라 prev를 써야한다.
				cmp->prev->next = cmp->next;
				if (cmp->next != NULL)
					cmp->next->prev = cmp->prev;

				read->prev->next = cmp;
				cmp->prev = read->prev;
				cmp->next = read;
				read->prev = cmp;

				read = cmp; //기준점을 재설정한다.
				cmp = temp; //cmp의 순서를 원상태로 돌려준다.

				//cmp=temp;
				//select=select->prev;
				cnt++;
			}
			printf("임시확인 =\n");
			view();
			printf("\n");
			cmp = cmp->next;
		}
		printf("기준값 이동 = %d", read->num);
		read = read->next;
		printf("%d\n=================================%d\n", read->num);
	}
	printf("정렬시도횟수 = %d\n", cnt);
}
