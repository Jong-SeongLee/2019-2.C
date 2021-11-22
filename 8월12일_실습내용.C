#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct member {
	int num; //숫자
	int count; //찾은횟수
	struct member *pre;
	struct member *next;
}mem;

void input(); //랜덤숫자를 리스트에 추가
int num_cmp(int p, mem*temp); //input 함수에서 중복되는 숫자 피하기
void view(); //검색횟수+현재 리스트에 있는 숫자 보여주기
void search(); //숫자를 입력받고, 같은 숫자를 가진 데이터를 검색
mem *head = NULL, *tail = NULL;

void main() {
	int i;
	srand((int)time(NULL));
	head = (mem*)malloc(sizeof(mem));
	head->pre = NULL;
	head->next = NULL;
	tail = head;
	for (i = 1; i <= 10; i++)
		input();
	view();
	while (1) {
		system("cls");
		view();
		search();
	}
	return;
}

void input() { //랜덤숫자를 리스트에 추가
	int num;
	mem *data = (mem*)malloc(sizeof(mem));
	data->next = NULL;
	data->pre = NULL;
	data->count = 0;
	num = rand() % 50 + 1;
	while (num_cmp(num, head->next)) {
		num = rand() % 50 + 1;
	}
	data->num = num;
	tail->next = data;
	data->pre = tail;
	tail = data;
}

int num_cmp(int p, mem*temp) { //input 함수에서 숫자를 생성할 때 중복을 막는 함수
	while (temp != NULL) {
		if (temp->num == p)
			return 1;
		temp = temp->next;
	}
	return 0;
}

void view() {
	mem* show = head->next;
	while (show != NULL) {
		printf("%d (%d)", show->num, show->count);
		show = show->next;
	}
	printf("\n");
}
void search() {
	mem *list = head->next, *cmp = head->next;
	int num;
	printf("찾을 숫자 : ");
	scanf("%d", &num);
	while (list != NULL) {
		if (list->num == num) 
			list->count++;
		while (cmp != list) { //현재 검색한 데이터(list)보다 검색횟수가 적은 데이터를 찾는다.
			if (cmp->count <= list->count) { //검색한 데이터(list)를 선형리스트에서 빼내는 과정
				list->pre->next = list->next;
				if (list->next != NULL) 
					list->next->pre = list->pre;
				else
					tail = list->pre; //검색한 데이터(list)를 cmp앞쪽에 끼워넣는 과정
				cmp->pre->next = list;
				list->pre = cmp->pre;
				list->next = cmp;
				cmp->pre = list;
				break;
			}
			cmp = cmp->next;
		}
		break;
	}
	list = list->next;
}
