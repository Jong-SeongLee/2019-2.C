//2019.8.8

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void push_(int x); //스택에 데이터를 입력
void pop_(); //스택에서 데이터를 제거 or 처리
void view(); //확인용
typedef struct queue {
	int num;
	struct queue *next;
	struct queue *prev;
}queue;
queue *head=NULL, *tail=NULL, *sp=NULL; //sp=지금 처리할 데이터

void main() {
	queue *head = malloc(sizeof(queue));
	head->next = NULL;
	head->prev = NULL;
	tail = head;
	sp = head;

	push_(10);
	push_(20);
	push_(30);
	push_(40);
	push_(50); //스텍 = 10-20-30-40-50
	printf("\t1번출력\n");
	view();
	//10을 보여주고 10을 제거
	//10-20-30-40-50 큐 출력
	printf("\t2번출력\n");
	view();
	push_(60);//10-20-60
	printf("\t3번출력\n");
	view();
}
void push_(int x) {
	queue *temp = malloc(sizeof(queue));
	while (tail->next != NULL)
		tail = tail->next;
	temp->next = NULL;
	temp->prev = tail;
	tail->next = temp;
	temp->num = x;
	tail = temp;
	sp = temp; //sp는 지금 처리해야할 데이터 = 가장 나중에 들어온 데이터 = temp
}
void view() {
	queue *temp;
	if (sp->next == NULL) { //sp의 앞쪽이 NULL일때 = sp가 head일때
		temp = sp->next; //temp = sp의 다음으로
		sp = sp->next->next; //sp=다음다음으로
	}
	else {
		temp = sp; //sp의 앞쪽이 NULL이 아닐때 = sp가 head가 아닐떄
		sp = sp->next; //temp=sp
	}
	printf("%d\n", temp->num);
}
