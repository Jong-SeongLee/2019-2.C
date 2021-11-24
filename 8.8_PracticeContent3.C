//2019.8.8 정렬 구현 및 실습내용

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
	head->prev=NULL;
	head->next=NULL;
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

int num_cmp(int n,sort *tmp) {
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

void sort_() {
	sort* read = head->next;//첫 순서를 기준으로 설정
	sort *cmp, *temp;
	int cnt = 0;
	while (read->next != NULL) { //read가 마지막 숫자가 될때까지
		cmp = read->next;//비교대상인 숫자를 설정
		while (cmp != NULL) {
			if (read->num > cmp->num) { //기준숫자 read가 비교숫자 cmp보다 클때=숫자위치를 바꿔야 할때
				read->prev->next = cmp;//기준위치에 비교대상인 숫자를 설
				if (cmp->next != NULL)//평범하게 교체
					cmp->next->prev = read;
				else
					tail = read; //비교대상이 마지막이라면 기준점을 마지막 숫자
				if (read->next != cmp) { //비교대상과 기준이 떨어져있는 숫자라면
					read->next->prev = cmp;//temp를 이용해서 정보를 저장
					cmp->prev->next = read;

					temp = read->prev;
					read->prev = cmp->prev;
					cmp->prev = temp;

					temp = read->next;
					read->next = cmp->next;
					cmp->next = temp;

				}
				else {
					//비교대상과 기준이 이웃한 숫자라면
					cmp->prev = read->prev;
					read->prev = cmp;
					read->next = cmp->next;
					cmp->next = read;
				}
				temp = read;
				read = cmp;
				cmp = temp;
				printf("임시확인 = ");
				view();
				printf("\n");
			}
			//기준숫자 read가 비교숫자 cmp보다 작을때 = 숫자위치 고정
		cnt++;
		cmp = cmp->next; //다음 비교숫자로 넘어간다
		}
	read = read->next;//수열 끝까지 비교를 마쳤으면 기준숫자를 옮긴다.
	}
printf("정렬시도 횟수= %d\n",cnt);
}
