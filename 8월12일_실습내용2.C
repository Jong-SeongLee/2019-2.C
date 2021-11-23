//2019.8.12
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//tree
//여러종류의 리스트를 하나로 묶은 구조
//최상위 개체(노드)를 root
//부모 - 자식 (형제)
//깊이(depth) -> root로부터 거리

typedef struct tree {
	int num; //식별번호
	int depth; //깊이
	char name[10]; //노드의 이름(폴더 이름)
	struct tree *parent; //부모
	struct tree *child; //자식
	struct tree *brother; // 형제
}tree;

typedef struct path { //출력을 위한 구조체, 구조상 필요한 구조체 X
	struct tree *p;
	struct path *next;
}path;

void init();
void input(tree *parent);
void view(tree *parent);
tree *move(tree *parent);
void path_free();
int menn();
void all_view(tree *parent);
void save();
void save_f(FILE *f, tree *parent);
void load();

tree *head = NULL, *tail = NULL;
tree;

void main() {
	tree *parent;
	init();
	parent = root;
	// load();
	while (1) {
		printf("=====================\n");
		view(parent);
		printf("=====================\n");
	}
	switch (menu()) {
	case 1:
		input(parent);
		break;
	case 2:
		parent = move(parent);
		break;
	case 3:
		if (parent != root) {
			//path_free();
			parent = parent->parent;
		}
		break;
	case 4:
		all_view(root);
		system("pause");
		break;
	}
	system("cls");
}
int menu() {
	int n;
	printf("1.자식 생성\n");
	printf("2.이동\n");
	printf("3.이전으로\n");
	printf("4.전체보기\n");
	printf("선택 : \n");
	scanf("%d", &n);
	return n;

}

void init(){ //뿌리를 만드는 코드
	root = (tree*)malloc(sizeof(tree));
	root->parent = NULL;
	root->child = NULL;
	root->brother = NULL;
	root->num = 0;
	root->depth = 0;
	strcpy(root->name, "root");
	//경로 리스트를 초기화
	head = (path*)malloc(sizeof(path));
	head->p = root;
	head->next = NULL;
	tail = head;
}

void view(tree *parent) {
	tree *child;
	path *now = head;
	printf("경로 : ");
	while (now != NULL) { //path 구조체에 들어있는 정보를 출력
		printf("/%s", now->p->name);
		now = now->next;
	}
	printf("\n부모 (현재 작업 중인 폴더): %d, %s \n",parent->num,parent->name);
	child = parent->child;
	while (child != NULL) {
		printf("%d, %s\n", child->num, child->name);
		child = child->brother;
	}
} 

void input(tree *parent) {
	//트리에 새로운 노드를 입력하는 함수, 현재 경로상에 자식노드를 추가
	tree *data = (tree*)malloc(sizeof(tree));
	tree *child; //노드에 형제노드를 추가해주기 위한 임시공간
	data->num = ++count; //노드의 번호는 노드 갯수에 따라 자동으로 설정
	printf("이름 : ");
	scanf("%s", data->name);
	data->parent = NULL;
	data->child = NULL;
	data->brother = NULL;
	if (parent->child == NULL) { 
		//현재 부모노드에 자식노드가 하나도 없는경우
		parent->child = data;
		data->parent = parent;
	}
	else {
		//부모노드에 자식노드가 있을경우 자식노드간에 형제관계를 설정해야한다.
		//프로그램적으로 하나의 노드는 하나의 자식만 가질수 있기 때문에 취하는 임시방편
		child = parent->child;
		while (child->brother != NULL)
			child = child->brother; //형제노드의 연결리스트 마지막으로 이동
		child->brother = data;
		data->parent = parent;
	}
	data->depth = parent->depth + 1; //새로 추가한 노드의 깊이는 부모노드의
	save();
}

tree* move(tree *parent) { //현재 자식노드중 하나로 이동하는 코드
	int num;
	tree *child = parent->child;
	printf("자식 번호 선택 : ");
	scanf("%d", &num);
	while (child != NULL) {
		if (child->num == num)
			break;
		child = child->brother;
	}
	//탐색한 자식노드를 경로리스트에 추가하는 코드
	tail->next = (path*)malloc(sizeof(path)); //경로 리스트에 정보를 추가
	tail->next->p = child;
	tail->next->next = NULL;
	tail = tail->next;
	return child;
}

void path_free() { //경로를 해제하는 함수 
	path *del = tail;
	tail = head;
	while (tail->next != del)
		tail = tail->next;
	tail->next = NULL;
	free(del);
}
void all_view(tree *parent) {
	int i;
	for (i = 0; i < parent->depth; i++)
		printf(" ");
	printf("%s\n", parent->name);
	if (parent->child != NULL)
		all_view(parent->child);
	if(parent->brother !=NULL)
		all_view(parent.)
}

if (data->deapth <= apr->deapth) {
	p = par->deapth;
	d = data->deapth;
	for (i = 0; i <= 9(p - d); i++)
		par = par->parent;
}
if (data->deapth - 1 > par->deapth) {
	par = par->child;
	while (par->brother != NULL)
		par = par->brother;
	if (per->child != NULL) {
		par->child = data;
		daa->parent = par;
	}
	else {
		ch = par->child;
	}
}
