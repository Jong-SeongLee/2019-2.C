//2019.7.26작성
//별을 키보드로 이동해보는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(void) {
	int a[10][10] = { { 1,0,0,0,0,0,0,0,0,0 },
					{ 0,0,0,0,0,0,0,0,0,0 },
					{ 0,0,0,0,0,0,0,0,0,0 },
					{ 0,0,0,0,0,0,0,0,0,0 },
					{ 0,0,0,0,0,0,0,0,0,0 },
					{ 0,0,0,0,0,0,0,0,0,0 },
					{ 0,0,0,0,0,0,0,0,0,0 },
					{ 0,0,0,0,0,0,0,0,0,0 },
					{ 0,0,0,0,0,0,0,0,0,0 },
					{ 0,0,0,0,0,0,0,0,0,0 } };
	int i, p, q, j, y;
	q = 0;
	y = 0;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			if (a[i][j] == 0) {
				printf(" ");
			}
			else if (a[i][j] == 1) {
				printf("★");
			}
			else if (a[i][j] == 2) {
				printf("S");
			}printf("\n");
	}
	while (1) {
		p = getch();
		system("cls");
		switch (p) {
		case 75://왼쪽
			if (q >= 0) {
				a[q][y] = 0;
				a[q][y - 1] = 1;
				y--;
			}
			break;
		case 77://오른쪽
			if (q <= 9) {
				a[q][y] = 0;
				a[q][y + 1] = 1;
				y++;
			}
			break;
		case 72://위
			if (y >= 0) {
				a[q][y] = 0;
				a[q-1][y] = 1;
				q--;
			}
			break;
		case 80://아래
			if (y < 10) {
				a[q][y] = 0;
				a[q+1][y] = 1;
				q++;
			}
			break;
		}
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				if (a[i][j] == 0) {
					printf(" ");
				}
				else if (a[i][j] == 1) {
					printf("★");
				}
				else if (a[i][j] == 2) {
					printf("S");
				}
			}
			printf("\n");

		}
	}
	return 0;
}
