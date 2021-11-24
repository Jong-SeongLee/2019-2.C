//2019.8.6 실습내용

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//동적배열 =
//데이터의 입출력속도가 매우 빠르다.
//데이터의 삭제와 추가가 느리다.

//연결리스트
//배열보다 입출력속도가 느림
//데이터의 삭제와 추가가 빠르다
//int, char ...등으로 구현하지 않는다
//구조체로 연결리스트 구현한다
//데이터와 데이터간의 연결을 메모리 주소로 연결

typedef struct {
	int num;
	char name[20];
	struct test *next; //내부참조, 다음 리스트의 주소
}test;

test* input(test *top); //리스트에 데이터 추가
void view(test *top);

void main() {
	//리스트 - 단일리스트
	test *head = NULL; //리스트의 가장 처음 데이터
	head = input(head);
	head = input(head);
	head = input(head);
	view(head);

}
test* input(test *top) {
	test *data; //현재 추가하려는 데이터
	test *tail = top; //마지막 데이터
	data = (test*)malloc(sizeof(test)); //malloc으로 데이터 확보
	printf("번호=");
	scanf("%d", &data->num);
	printf("이름=");
	getchar();
	scanf("%s", data->name);
	data->next = NULL;
	if (top == NULL)
		return data;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = data;
	return top;
}
void view(test *top) {
	test *temp = top;
	while (temp != NULL) {
		printf("%d, %s\n", temp->num, temp->name);
		temp = temp->next;
	}
}
