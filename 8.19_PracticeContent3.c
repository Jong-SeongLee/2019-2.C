//2019.8.19 작성

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
너비우선탐색
시작정점으로부터 인접한 정점들을 모두
방문하고나서 방문했던정점을 시작으로 다시 인접한
정점들에 방문을 하는탐색방법
인접한 정점들에 대해서 차례로 방문하고,
다시 인접한 정점에 방문을 하는 반복
선입선출구조 -->큐 이용
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

typedef struct queue {
	int data;
	struct queue*link;
}queue;

typedef struct qtype {
	queue *front, *rear;
}qtype;

void insert(graph*, int u, int v); //정점의 연결
void view(graph*Q);
void wfs(graph*Q, int v);
void enQ(qtype*Q, int i);
int deQ(qtype*Q);



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
	printf("\n너비우선탐색\n");
	wfs(g1, 0);
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

int deQ(qtype*Q) {
	queue*old = Q->front;
	int i;
	if (Q->front == NULL)
		return;
	i = old->data;
	Q->front = Q->front->link;
	if (Q->front == NULL)
		Q->rear = NULL;
	free(old);
	return i;
}

void enQ(qtype*Q, int i) {
	queue*grp_node = (queue*)malloc(sizeof(queue));
	grp_node->data = i;
	grp_node->link = NULL;
	if (Q->front == NULL) {
		Q->front = grp_node;
		Q->rear = grp_node;
	}
	else {
		Q->rear->link = grp_node;
		Q->rear = grp_node;
	}
}

void wfs(graph*g, int v) {
	node*w;
	qtype*Q = (qtype*)malloc(sizeof(qtype));
	Q->front = NULL;
	Q->rear = NULL;
	g->visit[v] = 1;
	printf("%c ", v + 65);
	enQ(Q, v);
	while (Q->front != NULL) {
		v = deQ(Q);
		for (w = g->adj[v]; w; w = w->link) {
			if (!g->visit[w->v]) {
				g->visit[w->v] = 1;
				printf("%c ", w->v + 65);
				enQ(Q, w->v);
			}
		}
	}
}