//2019.8.8
//스택 연습

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void push_(int x); //스택에 데이터를 입력
void pop_(); //스택에서 데이터를 제거 or 처리
void view(); //확인용
typedef struct stack {
	int num;
	struct stack *next;
	struct stack *prev;
}stack;
stack *head, *tail, *sp; //sp=지금 처리할 데이터

void main() {
	stack *head = malloc(sizeof(stack));
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
	//50-40-30-20-10 스텍출력
	//10-20-30-40-50 큐 출력
	pop_();//10-20-30-40
	printf("\t2번출력\n");
	view();
	pop_();
	pop_();
	push_(60);//10-20-60
	printf("\t3번출력\n");
	view();
}
void push_(int x) {
	stack *temp = malloc(sizeof(stack));
	while (tail->next != NULL)
		tail = tail->next;
	temp->next = NULL;
	temp->prev = tail;
	tail->next = temp;
	temp->num = x;
	tail = temp;
	sp = temp; //sp는 지금 처리해야할 데이터 = 가장 나중에 들어온 데이터 = temp
}
void pop_() {
	stack *temp = tail; //tail데이터를 제거할 것 이므로 제거할 데이터 앞의 데이터를 tail로 설정한다.
	tail = tail->prev;
	tail->next = NULL;
	sp = tail; //sp는 지금 처리해야할 데이터 = 가장 나중에 들어온 데이터 = tail
	free(temp);
}
void view() {
	while (sp->prev != NULL) {
		printf("%d\n",sp->num);
		sp = sp->prev;
	}
}
