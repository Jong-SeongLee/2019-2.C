//2019.8.6 실습내용
//8.5일자 프로그램에서 기능을 추가

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct book {
	int book_num;
	char book_name[20];
}book;
typedef struct users {
	int users_num;
	char users_name[20];
	char **borrow_list; //대출도서목록
	int borrow_num; //대출도서권수
}users;

void users_load(); //메모장에서 회원목록을 불러와 동적배열에 옮기는 함수
void book_load(); //메모장에서 도서목록을 ~~
int menu(); //메뉴를 선택하는 함수
void show_users(); //동적배열에 저장된 회원정보를 화면에 출력하는 함수
void show_book(); //동적배열에 저장된 도서목록 ~~
/*void users_new(); //동적배열을 증가시키고, 새로운 회원정보를 입력하는 함수
void book_new(); //동적배열을 증가시키고, 새로운 도서정보를~~
void users_save(); //동적배열에 저장된 회원정보를 메모장으로 저장하는 함수
void book_save(); //동적배열에 저장된 도서정보~~
void book_control(); //대출/반납 정하는 함수
void book_borrow(); //빌리려는 책의 제목을 회원구조체의 멤버변수로 추가
void book_return(); //반납하려는 책의 제목을 회원구조체의 멤버변수에서 제거 */

int book_cnt = 0; //헌재프로그램에 저장된 책 수
int users_cnt = 0; //현재프로그램에 저장된 회원 수
book *book_data = NULL; //책 목록
users *users_data = NULL; //회원 목록

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
/*		case 3:
			users_new();
			break;
		case 4:
			book_new();
			break;
		case 5:
			book_control();
			break;*/
		case 6:
			goto exit;
			break;
		default:
			goto exit;
			break;
		}
		system("cls");
	}
exit:
	system("cls");
	printf("프로그램 종료");
}

int menu() {
	int i = 0;
	printf("\t메뉴선택\n=====================\n");
	printf("1. 전체 회원 목록\n");
	printf("2. 전체 도서 목록\n");
	printf("3. 회원 등록\n");
	printf("4. 도서 등록\n");
	printf("5. 도서 대출 관리\n");
	printf("6. 프로그램 종료\n=====================\n");
	scanf("%d", &i);
	return i;
}

void users_load() {
	FILE *fu;
	fu = fopen("C:\\test97\\user.txt", "r");
	if (fu != NULL) {
		while (!feof(fu)) {
			if (users_cnt > 0) {
				users_data = realloc(users_data, sizeof(users)*(users_cnt + 1));
			}
			fscanf(fu, "%d %s\n", &users_data[users_cnt].users_num, users_data[users_cnt].users_name);
			users_data[users_cnt].borrow_list = NULL;
			users_data[users_cnt].borrow_num = 0;
			users_cnt++;
		}
		fclose(fu);
	}
}

void show_users() {
	for (int i = 0; i < users_cnt; i++) {
		printf("이용자 번호 = %d, 이용자 성명 = %s\n", users_data[i].users_num, users_data[i].users_name);
	}
	system("pause");
}

/*void users_new() {

}*/

void book_load() {
	FILE *fb;
	fb = fopen("C:\\test97\\book.txt", "r");
	if (fb != NULL) {
		while (!feof(fb)) {
			if (book_cnt > 0) {
				book_data = realloc(book_data, sizeof(book)*(book_cnt + 1));
			}
			fscanf(fb, "%d %s\n", &book_data[book_cnt].book_num, book_data[book_cnt].book_name);
			book_cnt++;
		}
		fclose(fb);
	}
}

void show_book() {
	for (int i = 0; i < book_cnt; i++) {
		printf("순번 = %d, 이름 = %s\n", book_data[i].book_num, book_data[i].book_name);
	}
	system("pause");
}
