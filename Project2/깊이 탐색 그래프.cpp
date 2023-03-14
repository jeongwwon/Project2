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


void stack_initialize(stack* s, int count) {
	s->top = 0;
	s->capacity = count;
	s->arr = new int[count];
	for (int i = 0; i < count; i++) {
		s->arr[i] = 0;
	}
}
void push(stack* s, int val) {
	if (s->capacity<=s->top ) {
		std::cout << "stack overflow" << std::endl;
		return;
	}
	s->arr[s->top++] = val;
}
int pop(stack* s) {
	if (s->top <= 0) {
		std::cout << "empty stack" << std::endl;
	}
	return s->arr[--(s->top)];
}
int getsize(const stack* s) {
	return s->top;
}
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
	node* cur=NULL;
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
void dfsreculsive(graph* g, int count, int* visited) {
	node* cur = g->arr[count].next;
	std::cout << "호출된 노드의 destination: " << cur->dst << std::endl;
	visited[count] = 1;
	while (cur) {
		int destination=cur->dst;
		if (visited[destination] == 0) {
			std::cout << "꺼낸 데이터:" << destination << std::endl;
 			dfsreculsive(g, destination, visited);  // 1. 1 visited 2. 3. visited 4. 
		}
		cur = cur->next;
	}
}
void dfs(graph* g,int count) {
	int* visited = new int[g->count];
	for (int i = 0; i < g->count; i++) {
		visited[i] = 0;
	}
	dfsreculsive(g, count, visited);
}
void dfs_stack(graph* g, int vertex) {
	int count = g->count;
	int* visited = new int[count];
	for (int i = 0; i < count; i++) {
		visited[i] = 0;
	}
	stack stk;
	stack_initialize(&stk, 9);
	push(&stk, vertex);
	visited[vertex] = 1;
	while (getsize(&stk) != 0) {
		int trav= pop(&stk);
		node* culnode = g->arr[trav].next;
		std::cout << "꺼낸 데이터:" << trav << std::endl;
		while (culnode) {
			int dst=culnode->dst;
			if (visited[dst] == 0) {
				push(&stk, dst);
				visited[dst] = 1;
			}
			culnode = culnode->next;
		}
		std::cout << std::endl;
		}
	delete[]stk.arr;
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
	dfs(&grp, 0);
	//display(&grp);
}