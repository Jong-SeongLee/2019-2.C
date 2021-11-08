#2019.8.5 포인터연습
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
	int i, num;
	student *temp;
	temp = (student);
	printf("학생이 좋아하는 과일 입력");
	while (temp->num < 5) {
		printf("입력=");
		if (temp->num == 0) {
			temp->fruit=(*)
		}
	}
}
