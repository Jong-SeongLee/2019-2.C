#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct node {
	int var; //데이터
	struct node* link;
}node;

typedef struct graph {
	int n; //정점개수
	node *list[7]; //정점헤드에대한 배열
}graph;

void make_graph(graph*g);
void show(graph*g);

int grp_arr[7][7] = {
	{0,1,1,0,0,0,0},
	{1,0,0,1,1,0,0},
	{1,0,0,0,1,0,0},
	{0,1,0,0,0,0,1},
	{0,1,1,0,0,0,1},
	{0,0,0,0,0,0,1},
	{0,0,0,1,1,1,0}
};

void main() {
	graph*g1;
	int i;
	g1 = (graph*)malloc(sizeof(graph));
	g1->n = 7;
	for (i = 0; i < 7; i++)
		g1->list[i] = NULL;
	make_graph(g1);
	show(g1);
}

void make_graph(graph*g) {
	int i, k;
	node *data = NULL;
	for (i = 0; i < 7; i++) {
		for(k = 0; k < 7; k++) {
			if (grp_arr[i][k]) {
				data = (node*)malloc(sizeof(node));
				data->var = k;
				data->link = g->list[i];
				g->list[i] = data;
			}
		}
	}
}

void show(graph*g) {
	int i, dg = 0;
	node *p;
	for (i = 0; i < g->n; i++) {
		printf("\n정점 %c의 인접리스트 : ", i + 65);
		p = g->list[i];
		dg = 0;
		while (p) {
			printf("%c", p->var + 65);
			p = p->link;
			dg++;
		}
		printf("  차수 : %d", dg);
	}
}