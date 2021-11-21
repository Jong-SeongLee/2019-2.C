//2019.8.9 실습내용

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//탐색(검색)
// 순차탐색 -> 전진이동법, 전위법, 계수법
//이전 탐색
void viwe();
void viwe2();
void front_move();//전진이동법
void trans();//전위법
void count();//계수법

int arr[2][10] = { 20,301,43,132,4,48,84,29,10,200 };
int arr2[10] = { 20,301,43,132,4,48,84,29,10,200 };
void main() {
	while (1) {
		count(); //계수밥
		view(); //계수법 뷰
		trans();
		front_move(); //전진이동법
		view2();//
	}
}
void view() {

}
void front_move() {
	int i, k, num;
	printf("찾을 숫자 : ");
	scanf("%d", &num);
	for (i = 0; i < 10; i++) {
		if (arr2[i] == num) {
			for (k = i; k > 0; k--) {
				arr2[k] = arr[k - 1];
			}
			arr2[0] = num;
			printf("찾았다.\n");
			break;
		}
	}
}
