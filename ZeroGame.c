#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void load(); //���� �ε�
void text();//����
void name(); //����
int menu(); //��ȣ
void check(); //����Ȯ��
void easy_game(); //�������ӽ���
void normal_game(); //�븻���ӽ���
int x, y; //�������� ����
void reward(); //�¸�����
void reset(); //���� ����
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
			printf("���Է�\n");
			system("pause");
			break;
		}
		system("cls");
	}
EXIT:
	system("cls");
	printf("����");
}
void reset() {
	int a;
	printf("1.�ʱ�ȭ\n2.���\n�ʱ�ȭ�� ������ ��� ������ϴ�.");
	scanf("%d", &a);
	if (a == 1) {
		FILE *fp = fopen("C:\\user\\list.txt", "w");
		fprintf(fp, "%d %d", x * 0, y * 0);
		fclose(fp);
		reward();
	}
}
void reward() {
	if (x > 49) //50�� �޼��� �۾��� ����
		system("color a");
	else if (x > 99) //100�� �޼��� ������ ����
		system("color 1f");
	else system("color 7"); //�⺻����
}
void load() {
	FILE *fp = fopen("C:\\user\\list.txt", "r");
	fscanf(fp, "%d %d", &x, &y);
	fclose(fp);
}
void name() {
	printf("===========================================\n");
	printf("\t\t���ΰ���\n");
	printf("===========================================\n");
}
int menu() {
	int i;
	printf("1. ���Ӽ���\n");
	printf("2. (Easy)���ӽ���\n");
	printf("3. (Normal)���ӽ���\n");
	printf("4. ����Ȯ��\n");
	printf("5. ��������\n");
	scanf("%d", &i);
	return i;
}
void text() { 
	printf("===========================================\n");
	printf("�Ϲ����� ���ΰ��� ��İ� �����ϴ�. ������ ��ǻ�Ͱ� 0���� 2���� ���ڸ� ���ϰ�, �������� 0���� 4������ ���ڷ� �����մϴ�.\n��ǻ���� ���ڿ� ������ ���ڸ� ���� ���ڿ� ��ġ�� ��� �������� �¸��� �������� �Դϴ�.\n\nEasy���� ��ǻ���� ���� �Ǽ��� ����ϴ�.\nNormal���� ��ǻ�Ͱ� ���� �Ǽ��� ���� �ʽ��ϴ�.\n");
	printf("\n\n���ο��� 100�� �Է��ϸ� �����ʱ�ȭ�� �� �� �ֽ��ϴ�.");
	printf("\n���� �¸�Ƚ���� �޼��ϸ�?\n");
}
void check() {
	printf("�������� : %d�� %d��\n", x, y);
}
void normal_game() {
	if (x < 1) {
		printf("Easy��忡�� �ѹ� �¸��ؾ� �մϴ�.\n");
	}
	else {
		int user; //�����Է� ��
		int com; //��ǻ���� ��
		int usert; //������ ��ġ�� ����
		int comt; //��ǻ�Ͱ� ��ġ�� ����
		int count = 1; //Ƚ��
		srand((int)time(NULL));
		while (1) {
			com = rand() % 3; //0~2���� ���� ����
			//���ǿ����� (0~4) ����
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
			printf("[����]���ڸ� �Է��ϼ��� (0~2) : ");
			scanf("\n%d", &user);
			if (user > 2) {
				while (user > 2) {
					printf("���ڰ� �߸� �ԷµǾ����ϴ�.\n�ٽ��Է��ϼ��� (0~2) : ");
					scanf("%d", &user);
				}
			}
			printf("�÷��̾� ���� (0~4) : ");
			scanf("%d", &usert);
			if (usert > 4) {
				while (usert > 4) {
					printf("���ڰ� �߸� �ԷµǾ����ϴ�.\n�ٽ��Է��ϼ��� (0~4) : ");
					scanf("%d", &usert);
				}
			}
			if (usert == com + user) {
				printf("��ǻ���� ���� : %d\n", com);
				printf("%d���常�� ���� �¸�!\n", count);
				FILE *fp = fopen("C:\\user\\list.txt", "w");
				fprintf(fp, "%d %d", x + 1, y);
				fclose(fp);
				break;
			}
			else {
				printf("��ǻ���� ���� : %d\n", com);
				printf("���� ����! ��ǻ���� ���ʷ� �Ѿ�ϴ�.\n");
				printf("===========================================\n");
				count++;
				system("pause");
				system("cls");
			}
			printf("[����]���ڸ� �Է��ϼ��� (0~2) : ");
			scanf("\n%d", &user);
			if (user > 2) {
				while (user > 2) {
					printf("���ڰ� �߸� �ԷµǾ����ϴ�.\n�ٽ��Է��ϼ��� (0~2) : ");
					scanf("%d", &user);
				}
			}
			com = rand() % 3; //0~2���� ���� ����
			//���ǿ����� (0~4) ����
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
			printf("��ǻ���� ���� : %d !\n��ǻ���� ���� : %d\n", comt, com);
			if (comt == com + user) {
				printf("%d���常�� ��ǻ�� �¸�!\n", count);
				FILE *fp = fopen("C:\\user\\list.txt", "w");
				fprintf(fp, "%d %d", x, y + 1);
				fclose(fp);
				break;
			}
			else printf("���� ����! ������ ���ʷ� �Ѿ�ϴ�.\n");
			printf("===========================================\n");
			count++;
			system("pause");
			system("cls");
		}
	}
}
void easy_game() {
	int user; //�����Է� ��
	int com; //��ǻ���� ��
	int usert; //������ ��ġ�� ����
	int comt; //��ǻ�Ͱ� ��ġ�� ����
	int count = 1; //Ƚ��
	srand((int)time(NULL));
	while (1) {
		com = rand() % 3; //0~2���� ���� ����
		comt = rand() % 5; //0~4���� ���� ����
		printf("[����]���ڸ� �Է��ϼ��� (0~2) : ");
		scanf("\n%d", &user);
		if (user > 2) {
			while (user > 2) {
				printf("���ڰ� �߸� �ԷµǾ����ϴ�.\n�ٽ��Է��ϼ��� (0~2) : ");
				scanf("%d", &user);
			}
		}
		printf("�÷��̾� ���� (0~4) : ");
		scanf("%d", &usert);
		if (usert > 4) {
			while (usert > 4) {
				printf("���ڰ� �߸� �ԷµǾ����ϴ�.\n�ٽ��Է��ϼ��� (0~4) : ");
				scanf("%d", &usert);
			}
		}
		if (usert == com + user) {
			printf("��ǻ���� ���� : %d\n", com);
			printf("%d���常�� ���� �¸�!\n", count);
			FILE *fp = fopen("C:\\user\\list.txt", "w");
			fprintf(fp, "%d %d", x + 1, y);
			fclose(fp);
			break;
		}
		else {
			printf("��ǻ���� ���� : %d\n", com);
			printf("���� ����! ��ǻ���� ���ʷ� �Ѿ�ϴ�.\n");
			printf("===========================================\n");
			count++;
			system("pause");
			system("cls");
		}
		printf("[����]���ڸ� �Է��ϼ��� (0~2) : ");
		scanf("\n%d", &user);
		if (user > 2) {
			while (user > 2) {
				printf("���ڰ� �߸� �ԷµǾ����ϴ�.\n�ٽ��Է��ϼ��� (0~2) : ");
				scanf("%d", &user);
			}
		}
		com = rand() % 3; //0~2���� ���� ����
		comt = rand() % 5; //0~4���� ���� ����
		printf("��ǻ���� ���� : %d !\n��ǻ���� ���� : %d\n", comt, com);
		if (comt == com + user) {
			printf("%d���常�� ��ǻ�� �¸�!\n", count);
			FILE *fp = fopen("C:\\user\\list.txt", "w");
			fprintf(fp, "%d %d", x, y + 1);
			fclose(fp);
			break;
		}
		else printf("���� ����! ������ ���ʷ� �Ѿ�ϴ�.\n");
		printf("===========================================\n");
		count++;
		system("pause");
		system("cls");
	}

}