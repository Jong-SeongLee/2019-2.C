//2019.8.5
//포인터와 파일 디스크럽터를 응용하여 도서관 관리 프로그램 제작

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct book{
	int book_num;
	char book_name[20];
}book;
typedef struct user{
	int user_num;
	char user_name[20];
}user;
int ucnt = 0;
int bcnt = 0;
int menu();
book* book_series_show(book *p); //책 목록 보여주기
book* book_series_load(book *p); //책 목록 로드
book* book_series_new(book *p); //신규도서 등록
user* user_load(user *x); //회원 목록 로드
user* user_show(user *x); //회원 목록 보여주기
user* user_new(user *x); //신규회원 등록
void main() {
	FILE *fp, *fx;
	book *p;
	user *x;
	p = (book*)malloc(sizeof(book));
	p = book_series_load(p);
	x = (user*)malloc(sizeof(user));
	x = user_load(x);
	while (1) {
		switch (menu()) {
		case 1:
			printf("1.도서 관리 메뉴\n");
			book_series_show(p);
			break;
		case 2:
			printf("2.회원 관리 메뉴\n");
			user_show(x);
			break;
		case 3:
			printf("3.신규 회원 등록 메뉴\n");
			x=user_new(x);
			break;
		case 4:
			printf("4.신규 도서 등록 메뉴\n");
			p=book_series_new(p);
			break;
		default:
			goto exit;
			break;
		}
		system("cls");
	}
exit:
	system("cls");
	printf("종료");
}

int menu() {
	int i;
	printf("1.도서 관리\n");
	printf("2.도서 회원 관리\n");
	printf("3.신규 회원 등록\n");
	printf("4.신규 도서 등록\n");
	printf("5.종료\n");
	scanf("%d", &i);
	return i;
}

book* book_series_show(book *p) {
	for (int i = 0; i < bcnt; i++) {
		printf("순번 = %d, 이름 = %s\n", p[i].book_num, p[i].book_name);
	}
	system("pause");
	return p;
}

book* book_series_load(book *p) {
	FILE *fp;
	fp = fopen("C:\\test97\\book.txt", "r");
	while (!feof(fp)) {
		if (bcnt > 0) {
			p = realloc(p, sizeof(book)*(bcnt + 1));
		}
		fscanf(fp, "%d %s\n", &p[bcnt].book_num, p[bcnt].book_name);
		bcnt++;
	}
	fclose(fp);
	return p;
}

book* book_series_new(book *p) {
	FILE *px;
	if (bcnt > 0) {
		p = realloc(p, sizeof(user)*(bcnt + 1));
	}

	scanf("%d %s", &p[bcnt].book_num, p[bcnt].book_name);
	px = fopen("C:\\test97\\user.txt", "a");
	fprintf(px, "\n%d %s", p[bcnt].book_num, p[bcnt].book_name); //입력후 메모장에 출력
	bcnt++;

	fclose(px);
	return p;
}

user* user_load(user *x) {
	FILE *fx;
	fx = fopen("C:\\test97\\user.txt", "r");
	while (!feof(fx)) {
		if (ucnt > 0) {
			x = realloc(x, sizeof(user)*(ucnt + 1));
		}
		fscanf(fx, "%d %s\n", &x[ucnt].user_num, x[ucnt].user_name);
		ucnt++;
	}
	fclose(fx);
	return x;
}

user* user_show(user *x) {
	for (int i = 0; i < ucnt; i++) {
		printf("이용자 번호 = %d, 이용자 성명 = %s\n", x[i].user_num, x[i].user_name);
	}
	system("pause");
	return x;
}

user* user_new(user *x) {
	FILE *fx;
	if (ucnt > 0) {
		x = realloc(x, sizeof(user)*(ucnt + 1));
	}

	scanf("%d %s", &x[ucnt].user_num, x[ucnt].user_name);
	fx = fopen("C:\\test97\\user.txt", "a");
	fprintf(fx, "\n%d %s", x[ucnt].user_num, x[ucnt].user_name); //입력후 메모장에 출력
	ucnt++;

	fclose(fx);
	return x;
}
