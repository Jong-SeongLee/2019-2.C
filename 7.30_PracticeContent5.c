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
	printf("���� �Է�:");
	scanf("%d", &x);
	printf("����� ���� ���� �Է�:");
	scanf("%d", &y);
	
	temp = translate(x, y);

	for (i = cnt; i > 0; i--) { //�ٲ� ������ ����ִ� �迭�� �������� ���޹޾Ƽ� ���
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