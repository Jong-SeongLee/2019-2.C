//2019.8.6
//기존 도서관리프로그램 기능 확장

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*메뉴
1.책 등록
	책번호, 제목

2.신규 회원 정보 입력
	회원번호, 회원이름, 회원 나이, 현재 빌린 책목록(여러권)

3.대출관리
	특정 회원 선택, 회원정보+현재 빌린 책 목록 출력+빌릴 책 추가/반납한 책 제거

4.회원정보목록
	전체회원정보 출력하기
5.
6.종료
*/


typedef struct book {	//책 구조체
	int num;			//책 번호
	char title[20];		//책 제목
}book;

typedef struct users {	//회원 구조체
	int num;			//회원번호
	char name[10];		//회원 이름
	char **borrow_list;	//대출도서목록
	int borrow_num;		//대출도서권수
}users;

void users_load();		//메모장에서 회원목록을 불러와 동적배열에 옮기는 함수
void book_load();		//메모장에서 도서목록을 ~~~
int menu();				//메뉴를 선택하는 함수
void show_users();		//동적배열에 저장된 회원정보를 화면에 출력하는 함수
void show_book();		//동적배열에 저장된 도서목록을 ~~~
void users_new();		//동적배열을 증가시키고, 새로운 회원정보를 입력하는 함수
void book_new();		//동적배열을 증가시키고, 새로운 도서정보를~~
void users_save();		//동적배열에 저장된 회원정보를 메모장으로 저장하는 함수
void book_save();		//동적배열에 저장된 도서정보를~~~
void book_control();	// 대출/반납인지 정하는 함수
void book_borrow();		//빌리려는 책의 제목을 회원구조체의 멤버변수로 추가
void book_return();		//반납하려는 책의 제목을 회원구조체의 멤버변수에서 제거

int book_cnt = 0;			//현재 프로그램에 저장된 책의 권수
int users_cnt = 0;			//현재 프로그램에 저장된 회원 수

book *book_data = NULL;		//책목록
users *users_data = NULL;	//회원목록

//


void main() {
	book_data = (book*)malloc(sizeof(book));
	users_data = (users*)malloc(sizeof(users));
	book_load();
	users_load();
	while (1) {
		switch (menu()) {
		case 1:
			show_users();
			break;
		case 2:
			show_book();
			system("pause");
			break;
		case 3:
			users_new();
			break;
		case 4:
			book_new();
			break;
		case 5:
			book_control();
			break;
		case 6:
			free(users_data);
			free(book_data);
			printf("종료\n");
			system("pause");
			return;
		}
		system("cls");
	}

}

void book_load() {
	FILE *fp;
	fp = fopen("C:\\test97\\book.txt", "r");
	if (fp != NULL) {
		while (!feof(fp)) {
			if (book_cnt)
				book_data = realloc(book_data, sizeof(book)*(book_cnt + 1));
			fscanf(fp, "%d %s\n", &book_data[book_cnt].num, book_data[book_cnt].title);
			book_cnt++;
		}
		fclose(fp);
	}
}

void users_load() {
	FILE *fp;
	fp = fopen("C:\\test97\\users.txt", "r");
	if (fp != NULL) {
		while (!feof(fp)) {
			if (users_cnt)
				users_data = realloc(users_data, sizeof(users)*(users_cnt + 1));
			fscanf(fp, "%d %s\n", &users_data[users_cnt].num, users_data[users_cnt].name);
			users_data[users_cnt].borrow_list = NULL;
			users_data[users_cnt].borrow_num = 0;
			users_cnt++;
		}
		fclose(fp);
	}
}

int menu() {
	int sel;
	printf("메뉴선택\n");
	printf("1.전체회원정보보기\n");
	printf("2.등록 서적 보기\n");
	printf("3.회원등록\n");
	printf("4.도서등록\n");
	printf("5.대출관리\n");
	printf("6.종료\n");
	printf("선택 = \n");
	scanf("%d", &sel);
	return sel;
}

void show_users() {
	int i, k;
	if (users_cnt == 0) {
		printf("등록된 이용자가 없습니다.\n사용자 등록을 먼저 진행해주세요.\n");
	}
	else {
		for (i = 0; i < users_cnt; i++) {
			printf("이용자번호 = %d, 이용자 성명 = %s :: ", users_data[i].num, users_data[i].name);
			if (users_data[i].borrow_num == 0)
				printf("대출중인 도서가 없습니다.");
			else {
				printf("대출권수 = %d권, ", users_data[i].borrow_num);
				for (k = 0; k < users_data[i].borrow_num; k++) {
					printf("%s ", users_data[i].borrow_list[k]);
				}
			}
			printf("\n");
		}
		system("pause");
	}

}
void show_book() {
	int i;
	if (book_cnt == 0) {
		printf("등록된 도서가 없습니다.\n도서 등록을 먼저 진행해주세요.\n");
	}
	else {
		printf("도서번호 :     도서명\n");
		for (i = 0; i < book_cnt; i++)
			printf("%8d : %s\n", book_data[i].num, book_data[i].title);
	}
}

void users_new() {
	if (users_cnt)
		users_data = realloc(users_data, sizeof(users)*(users_cnt + 1));
	printf("신규회원의 이름 = ");
	getchar();
	gets(users_data[users_cnt].name);
	users_data[users_cnt].num = (users_cnt + 1);
	users_data[users_cnt].borrow_list = NULL;
	users_data[users_cnt].borrow_num = 0;

	users_cnt++;
	users_save();
}

void book_new() {
	if (book_cnt)
		book_data = realloc(book_data, sizeof(book)*(book_cnt + 1));
	printf("신규도서명 = ");
	getchar();
	gets(book_data[book_cnt].title);
	book_data[book_cnt].num = (book_cnt + 1);
	book_cnt++;
	book_save();
}

void users_save() {
	int i;
	FILE *fp;
	fp = fopen("C:\\test97\\users.txt", "w");
	for (i = 0; i < users_cnt; i++)
		fprintf(fp, "%d %s\n", users_data[i].num, users_data[i].name);
	fclose(fp);
}

void book_save() {
	int i;
	FILE *fp;
	fp = fopen("C:\\test97\\book.txt", "w");
	for (i = 0; i < book_cnt; i++)
		fprintf(fp, "%d %s\n", book_data[i].num, book_data[i].title);
	fclose(fp);
}

void book_control() {
	int x, y;
	printf("도서대출/반납자 회원번호 = ");
	scanf("%d", &x);
	printf("%d번 회원\n", x);
	printf("1.대출 / 2.반납 = ");
	scanf("%d", &y);
	if (y == 1)
		book_borrow(x);
	else if (y == 2)
		book_return(x);
	else
		printf("없는 명령입니다.\n");
}

void book_borrow(int x) {
	int i, z;

	printf("어느책을 대출합니까(번호)? = ");
	show_book();
	scanf("%d", &z);
	if (users_data[x - 1].borrow_list == NULL)
		users_data[x - 1].borrow_list = (char**)malloc(sizeof(char*));
	else
		users_data[x - 1].borrow_list = realloc(users_data[x - 1].borrow_list, sizeof(char*)*(users_data[x - 1].borrow_num + 1));
	i = users_data[x - 1].borrow_num;
	users_data[x - 1].borrow_list[i] = (char*)malloc(20);
	strcpy(users_data[x - 1].borrow_list[i], book_data[z - 1].title);
	users_data[x - 1].borrow_num++;

}
void book_return(int x) {
	int i, z;
	printf("어느책을 반납합니까? = ");
	printf("현재 대출목록\n");

	for (i = 0; i < users_data[x - 1].borrow_num; i++) {
		printf("%d. %s\n", i + 1, users_data[x - 1].borrow_list[i]);
	}
	printf("입력 = ");
	scanf("%d", &z);
	while (z < users_data[x - 1].borrow_num) {
		users_data[x - 1].borrow_list[z - 1] = users_data[x - 1].borrow_list[z];
		z++;
	}
	users_data[x - 1].borrow_num--;
	users_data[x - 1].borrow_list = realloc(users_data[x - 1].borrow_list, sizeof(char*)*(users_data[x - 1].borrow_num));

}
