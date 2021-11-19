//2019.8.8 버블정렬 실습내용

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

void sort_() {//버블정렬
	sort* read = head->next;
	sort* cmp1, *cmp2, *ok=NULL; //ok = 정렬이 완료된 변수
	while (read->next != NULL) {
		cmp1 = head->next; //첫번째 숫자 설정
		cmp2 = cmp1->next; //두번째 숫자 설정
	}
}
