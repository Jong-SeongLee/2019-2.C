#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int cnt = 0;
int translate(int origine, int transe);
int main() {
	int i, x, y;
	int *temp;
	printf("숫자 입력:");
	scanf("%d", &x);
	printf("출력할 진수 숫자 입력:");
	scanf("%d", &y);
	
	temp = translate(x, y);

	for (i = cnt; i > 0; i--) { //바꾼 진수가 들어있는 배열을 메인으로 전달받아서 출력
		printf("%d", temp[i - 1]);
	}

}
int translate(int origine, int trans) {
	int i;
	static int arr[100] = { 0 };
	while (origine > 0) {
		arr[cnt] = origine % trans;
		origine /= trans;
		cnt++;
	}
	return arr;
}