//2019.8.19 작성

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
깊이 우선 탐색
시작정점의 한방향으로 갈수 있는 경로가
있는곳까지 가다가 더이상 못가게되면
마지막에 만났던 갈림길로 돌아와서
다른방향으로 돌아가며 순회 하는방법
가장 마지막에 만났던 갈림길로 돌아와서 하기에
후입선출 스택이용
*/
typedef struct node {
	int v;
	struct node*link;
}node;

typedef struct graph {
	int n;
	node*adj[7];
	int visit[7]; //이미 탐색한 노드를 기록
}graph;

typedef struct stack {
	int data;
	struct stack*link;
}stack;

void insert(graph*, int u, int v); //정점의 연결
void view(graph*g);
void dfs(graph*g, int v);
void push(int v);
int pop();

stack *top;

void main() {
	graph*g1;
	int i;
	g1 = (graph*)malloc(sizeof(graph));
	g1->n = 7;
	memset(g1->visit, 0, sizeof(g1->visit));
	for (i = 0; i < 7; i++)
		g1->adj[i] = NULL;
	//A=0,~~~~,G=6
	insert(g1, 0, 2);
	insert(g1, 0, 1);

	insert(g1, 1, 4);
	insert(g1, 1, 3);
	insert(g1, 1, 0);

	insert(g1, 2, 4);
	insert(g1, 2, 0);

	insert(g1, 3, 6);
	insert(g1, 3, 1);

	insert(g1, 4, 6);
	insert(g1, 4, 2);
	insert(g1, 4, 1);

	insert(g1, 5, 6);

	insert(g1, 6, 5);
	insert(g1, 6, 4);
	insert(g1, 6, 3);

	printf("g1의 인접리스트\n");
	view(g1);
	printf("\n깊이우선탐색\n\n");
	dfs(g1, 0);
}
void insert(graph*g, int u, int v) {
	node*grp_node;
	grp_node = (node*)malloc(sizeof(node));
	grp_node->v = v;
	grp_node->link = g->adj[u];
	g->adj[u] = grp_node;
}

void view(graph*g) {
	int i;
	node*p;
	for (i = 0; i < 7; i++) {
		printf("\n%c의 인접리스트 : ", i + 65);
		p = g->adj[i];
		while (p) {
			printf("-> %c ", p->v + 65);
			p = p->link;
		}
	}
	printf("\n");
}

int pop() {
	int i;
	stack*temp = top;
	i = temp->data;
	top = temp->link;
	free(temp);
	return i;
}

void push(int v) {
	stack*temp = (stack*)malloc(sizeof(stack));
	temp->data = v;
	temp->link = top;
	top = temp;
}

void dfs(graph*g, int v) {
	node*w;
	top = NULL;
	push(v);
	g->visit[v] = 1;
	printf("%c ", v + 65);
	while (top != NULL) {
		w = g->adj[v];
		while (w) {
			if (!g->visit[w->v]) { //시도하는 노드가 방문하지 않은곳일경우
				push(w->v); //스택에 현재노드를 추가
				g->visit[w->v] = 1; //방문기록
				printf("%c ", w->v + 65);
				v = w->v;
				w = g->adj[v];
			}
			else w = w->link; //탐색을 시도하는 노드가 이미 방문했던 곳이라면
		}
		v = pop();
	}
}