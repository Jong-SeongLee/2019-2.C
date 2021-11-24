//2019.8.5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct game {
	char name[20];
	int price;
	int users;
}game;

int cnt = 0;

int menu();
game* load(game *p);
game* show(game *p);
game* input(game *p);
game* save(game *p);

void main() {
	FILE *fp;
	struct game *p;
	int i;
	p = (game*)malloc(sizeof(game));
	p = load(p);
	while (1) {
		switch (menu()) {
		case 1:
			show(p);
			break;
		case 2:
			p = input(p);
			break;
		case 3:
			free(p);
			return;
		default:
				printf("다시선택해주세요");
				break;
		}
		system("cls");
	}
}

game* load(game *p) {
	FILE *fp;
	int i;
	fp = fopen("C:\\test97\\data.txt", "r");
	while (!feof(fp)) {
		if (cnt > 0) {
			p = realloc(p, sizeof(game)*(cnt + 1));
		}
		fscanf(fp, "%s %d %d\n", p[cnt].name, &p[cnt].price, &p[cnt].users);
		cnt++;
	}
	fclose(fp);
	return p;
}

int menu() {
	int sel;
	printf("1.등록된 게임정보 출력\n");
	printf("2.신규게임 등록\n");
	printf("3.")
}

game* show(game *p) {
	for (int i = 0; i < cnt; i++) {
		printf("게임이름 = %s, 가격 = %d, 유저수 = %d\n", p[i].name, p[i].price, p[i].users);
	}
	system("pause");
}

game* input(game *p) {
	if (cnt > 0) {
		p = realloc(p, sizeof(game)*(cnt + 1));
	}
	printf("신규게임이름 = ");
	getchar();
	pritnf("신규게임가격 = ");
	scanf("%d", &p[cnt].price);
	printf("신규게임 이용자 수 = ");
	scanf("%d", &p[cnt].users);
	cnt++;

	save(p);
	return p;
}

void save(game *p) {
	FILE *fp;
	fp = fopen("C:\\test97\\data.txt", "w");
	for (int i = 0; i < cnt; i++) {

	}
}
