//2019.8.15 포인터와 malloc 활용 연습
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct {
	char **fruit;
	char *name;
	int num;
}student;
void main() {
	student *temp;
	temp = (student*)malloc(sizeof(student));
	temp[0].fruit = (char**)malloc(sizeof(char*));
	for (int i = 0; i < 5; i++) {
		temp[0].fruit[i] = (char*)malloc(20);
	}
	strcpy(temp[0].fruit[0], "사과");
	strcpy(temp[0].fruit[1], "바나나");
	strcpy(temp[0].fruit[2], "복숭아");
	strcpy(temp[0].fruit[3], "파인애플");
	strcpy(temp[0].fruit[4], "수박");
	for (int i = 0; i < 5; i++) {
		printf("%s\n", temp[0].fruit[i]);
	}
	free(temp);
}
