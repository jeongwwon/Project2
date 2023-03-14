#include<iostream>

struct node {
	node* next;
	int dst;
};
struct graph {
	node* arr;
	int count;
};
struct stack {
	int* arr;
	int top;
	int capacity;
};
void graph_initialize(graph* p, int count) {
	p->count = count;
	p->arr = new node[count];
	for (int i = 0; i < count; i++) {
		p->arr[i].dst = i;
		p->arr[i].next = NULL;
	}
}
void directgraph(graph* p, int src, int des) {
	node* newnode = new node;
	newnode->dst = des;
	newnode->next = NULL;
	if (p->arr[src].next == NULL) {
		p->arr[src].next = newnode;
		return;
	}
	newnode->next = p->arr[src].next;
	p->arr[src].next = newnode;
}
void undirectgraph(graph* p, int src, int des) {
	directgraph(p, src, des);
	directgraph(p, des, src);
}
void display(const graph* g) {
	node* cur = NULL;
	if (g == NULL) {
		return;
	}
	for (int i = 0; i < g->count; i++) {
		cur = g->arr[i].next;
		std::cout << "시작 노드:" << i << std::endl;
		while (cur) {
			std::cout << cur->dst << std::endl;
			cur = cur->next;
		}
		std::cout << std::endl;
	}
}
int main() {
	graph grp;
	graph_initialize(&grp, 9);
	undirectgraph(&grp, 0, 1);
	undirectgraph(&grp, 1, 2);
	undirectgraph(&grp, 1, 3);
	undirectgraph(&grp, 2, 3);
	undirectgraph(&grp, 2, 4);
	undirectgraph(&grp, 3, 4);
	undirectgraph(&grp, 3, 5);
	undirectgraph(&grp, 5, 6);
	undirectgraph(&grp, 5, 7);
	undirectgraph(&grp, 6, 8);
	//dfs_stack(&grp, 0);
	display(&grp);
}