#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void load(); //전적 로드
void text();//설명
void name(); //제목
int menu(); //번호
void check(); //전적확인
void easy_game(); //이지게임시작
void normal_game(); //노말게임시작
int x, y; //전역변수 승패
void reward(); //승리보상
void reset(); //전적 리셋
void main() {
	while (1) {
		name();
		load();
		reward();
		int a = menu();
		switch (a) {
		case 1:
			text();
			system("pause");
			break;
		case 2:
			easy_game();
			system("pause");
			break;
		case 3:
			normal_game();
			system("pause");
			break;
		case 4:
			check();
			system("pause");
			break;
		case 5:
			goto EXIT;
			break;
		case 100:
			reset();
			break;
		default:
			printf("재입력\n");
			system("pause");
			break;
		}
		system("cls");
	}
EXIT:
	system("cls");
	printf("종료");
}
void reset() {
	int a;
	printf("1.초기화\n2.취소\n초기화시 보상이 모두 사라집니다.");
	scanf("%d", &a);
	if (a == 1) {
		FILE *fp = fopen("C:\\user\\list.txt", "w");
		fprintf(fp, "%d %d", x * 0, y * 0);
		fclose(fp);
		reward();
	}
}
void reward() {
	if (x > 49) //50승 달성시 글씨색 변경
		system("color a");
	else if (x > 99) //100승 달성시 바탕색 변경
		system("color 1f");
	else system("color 7"); //기본설정
}
void load() {
	FILE *fp = fopen("C:\\user\\list.txt", "r");
	fscanf(fp, "%d %d", &x, &y);
	fclose(fp);
}
void name() {
	printf("===========================================\n");
	printf("\t\t제로게임\n");
	printf("===========================================\n");
}
int menu() {
	int i;
	printf("1. 게임설명\n");
	printf("2. (Easy)게임시작\n");
	printf("3. (Normal)게임시작\n");
	printf("4. 전적확인\n");
	printf("5. 게임종료\n");
	scanf("%d", &i);
	return i;
}
void text() { 
	printf("===========================================\n");
	printf("일반적인 제로게임 방식과 같습니다. 유저와 컴퓨터가 0에서 2까지 숫자를 정하고, 유저부터 0부터 4까지의 숫자로 공격합니다.\n컴퓨터의 숫자와 유저의 숫자를 더한 숫자와 일치할 경우 공격자의 승리로 게임종료 입니다.\n\nEasy모드는 컴퓨터의 공격 실수가 잦습니다.\nNormal모드는 컴퓨터가 공격 실수를 하지 않습니다.\n");
	printf("\n\n메인에서 100을 입력하면 전적초기화를 할 수 있습니다.");
	printf("\n일정 승리횟수를 달성하면?\n");
}
void check() {
	printf("현재전적 : %d승 %d패\n", x, y);
}
void normal_game() {
	if (x < 1) {
		printf("Easy모드에서 한번 승리해야 합니다.\n");
	}
	else {
		int user; //유저입력 값
		int com; //컴퓨터의 값
		int usert; //유저가 외치는 숫자
		int comt; //컴퓨터가 외치는 숫자
		int count = 1; //횟수
		srand((int)time(NULL));
		while (1) {
			com = rand() % 3; //0~2까지 랜덤 추출
			//조건에따라 (0~4) 공격
			switch (com) {
			case 0:
				comt = rand() % (2 + 1 - com) + com;
				break;
			case 1:
				comt = rand() % (3 + 1 - com) + com;
				break;
			case 2:
				comt = rand() % (4 + 1 - com) + com;
				break;
			}
			printf("[공격]숫자를 입력하세요 (0~2) : ");
			scanf("\n%d", &user);
			if (user > 2) {
				while (user > 2) {
					printf("숫자가 잘못 입력되었습니다.\n다시입력하세요 (0~2) : ");
					scanf("%d", &user);
				}
			}
			printf("플레이어 공격 (0~4) : ");
			scanf("%d", &usert);
			if (usert > 4) {
				while (usert > 4) {
					printf("숫자가 잘못 입력되었습니다.\n다시입력하세요 (0~4) : ");
					scanf("%d", &usert);
				}
			}
			if (usert == com + user) {
				printf("컴퓨터의 숫자 : %d\n", com);
				printf("%d라운드만에 유저 승리!\n", count);
				FILE *fp = fopen("C:\\user\\list.txt", "w");
				fprintf(fp, "%d %d", x + 1, y);
				fclose(fp);
				break;
			}
			else {
				printf("컴퓨터의 숫자 : %d\n", com);
				printf("공격 실패! 컴퓨터의 차례로 넘어갑니다.\n");
				printf("===========================================\n");
				count++;
				system("pause");
				system("cls");
			}
			printf("[수비]숫자를 입력하세요 (0~2) : ");
			scanf("\n%d", &user);
			if (user > 2) {
				while (user > 2) {
					printf("숫자가 잘못 입력되었습니다.\n다시입력하세요 (0~2) : ");
					scanf("%d", &user);
				}
			}
			com = rand() % 3; //0~2까지 랜덤 추출
			//조건에따라 (0~4) 공격
			switch (com) {
			case 0:
				comt = rand() % (2 + 1 - com) + com;
				break;
			case 1:
				comt = rand() % (3 + 1 - com) + com;
				break;
			case 2:
				comt = rand() % (4 + 1 - com) + com;
				break;
			}
			printf("컴퓨터의 공격 : %d !\n컴퓨터의 숫자 : %d\n", comt, com);
			if (comt == com + user) {
				printf("%d라운드만에 컴퓨터 승리!\n", count);
				FILE *fp = fopen("C:\\user\\list.txt", "w");
				fprintf(fp, "%d %d", x, y + 1);
				fclose(fp);
				break;
			}
			else printf("공격 실패! 유저의 차례로 넘어갑니다.\n");
			printf("===========================================\n");
			count++;
			system("pause");
			system("cls");
		}
	}
}
void easy_game() {
	int user; //유저입력 값
	int com; //컴퓨터의 값
	int usert; //유저가 외치는 숫자
	int comt; //컴퓨터가 외치는 숫자
	int count = 1; //횟수
	srand((int)time(NULL));
	while (1) {
		com = rand() % 3; //0~2까지 랜덤 추출
		comt = rand() % 5; //0~4까지 랜덤 추출
		printf("[공격]숫자를 입력하세요 (0~2) : ");
		scanf("\n%d", &user);
		if (user > 2) {
			while (user > 2) {
				printf("숫자가 잘못 입력되었습니다.\n다시입력하세요 (0~2) : ");
				scanf("%d", &user);
			}
		}
		printf("플레이어 공격 (0~4) : ");
		scanf("%d", &usert);
		if (usert > 4) {
			while (usert > 4) {
				printf("숫자가 잘못 입력되었습니다.\n다시입력하세요 (0~4) : ");
				scanf("%d", &usert);
			}
		}
		if (usert == com + user) {
			printf("컴퓨터의 숫자 : %d\n", com);
			printf("%d라운드만에 유저 승리!\n", count);
			FILE *fp = fopen("C:\\user\\list.txt", "w");
			fprintf(fp, "%d %d", x + 1, y);
			fclose(fp);
			break;
		}
		else {
			printf("컴퓨터의 숫자 : %d\n", com);
			printf("공격 실패! 컴퓨터의 차례로 넘어갑니다.\n");
			printf("===========================================\n");
			count++;
			system("pause");
			system("cls");
		}
		printf("[수비]숫자를 입력하세요 (0~2) : ");
		scanf("\n%d", &user);
		if (user > 2) {
			while (user > 2) {
				printf("숫자가 잘못 입력되었습니다.\n다시입력하세요 (0~2) : ");
				scanf("%d", &user);
			}
		}
		com = rand() % 3; //0~2까지 랜덤 추출
		comt = rand() % 5; //0~4까지 랜덤 추출
		printf("컴퓨터의 공격 : %d !\n컴퓨터의 숫자 : %d\n", comt, com);
		if (comt == com + user) {
			printf("%d라운드만에 컴퓨터 승리!\n", count);
			FILE *fp = fopen("C:\\user\\list.txt", "w");
			fprintf(fp, "%d %d", x, y + 1);
			fclose(fp);
			break;
		}
		else printf("공격 실패! 유저의 차례로 넘어갑니다.\n");
		printf("===========================================\n");
		count++;
		system("pause");
		system("cls");
	}

}