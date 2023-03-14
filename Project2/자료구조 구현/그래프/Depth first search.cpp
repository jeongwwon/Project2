#include<iostream>

struct node {
	int dst;
	node* next;
};

struct graph {
	int count;
	node* arr;
};

struct stack {
	int top;
	int* arr;
	int capacity;
};

void stack_initialize(stack* s, int count);
void push(stack* s, int val);
void graph_initialize(graph* g, int count);
void directgraph(graph* g, int src, int dst);
void undirectgraph(graph* g, int src, int dst);
void display(const graph* g);
void memoryfree(graph* g);
int pop(stack* stk);
int getcapacity(const stack* stk);
int getsize(const stack* stk);
void dfsreculsive(graph* g, int index, int* visited);
void dfs(graph* g, int source);
void dfs_stack(graph* g, int source);


void stack_initialize(stack* s, int count) {
	s->arr = new int[count];
	for (int i = 0; i < count; i++) {
		s->arr[i] = 0;
	}
	s->top = 0;
	s->capacity = count;
}

void push(stack* s, int val) {
	if (s->top >= s->capacity) {
		std::cout << "stack overflow" << std::endl;
		return;
	}
	s->arr[s->top++] = val;
}
int pop(stack* stk) {
	if (stk->top <= 0) {
		std::cout << "empty stack" << std::endl;
	}
	return stk->arr[--(stk->top)];
}
int getcapacity(const stack* stk) {
	return stk->capacity;
}
int getsize(const stack* stk) {
	return stk->top;
}
void graph_initialize(graph* g, int count) {
	g->count = count;
	g->arr = new node[count];
	for (int i = 0; i < count; i++) {
		g->arr[i].dst = i;
		g->arr[i].next = NULL;
	}
}

void directgraph(graph* g, int src, int des) {
	node* newnode = new node;
	newnode->dst = des;
	newnode->next = NULL;
	if (g->arr[src].next == NULL) {
		g->arr[src].next = newnode;
		return;
	}
	newnode->next = g->arr[src].next;
	g->arr[src].next = newnode;
}

void undirectgraph(graph* g, int src, int des) {
	directgraph(g, src, des);
	directgraph(g, des, src);
}
void display(const graph* g) {
	node* cur = NULL;
	if (g == NULL) {
		return;
	}
	for (int i = 0; i < g->count; i++) {
		cur = g->arr[i].next;
		std::cout << "출발지 노드:" << i << std::endl;
		while (cur) {
			std::cout << cur->dst << std::endl;
			cur = cur->next;
		}
		std::cout << std::endl;
	}
}
void memoryfree(graph* g) {
	int i;
	node* delnode=NULL;
	for (int i = 0; i < g->count; i++) {
		while (g->arr[i].next) {
			delnode = g->arr[i].next;
			g->arr[i].next = delnode->next; 
			delete delnode;
		}
	}
	delete []g->arr;
}
void dfsreculsive(graph* g, int index, int* visited) {
	int destination;
	node* curnode = g->arr[index].next;
	visited[index] = 1;
	while (curnode) {  
		destination = curnode->dst;
		if (visited[destination] == 0) {
			std::cout << destination << std::endl;
			dfsreculsive(g, destination, visited);
		}
		curnode = curnode->next;
	}
}
void dfs(graph* g, int source) {
	int count = g->count;
	int* visited = new int[count];
	for (int i = 0; i < count; i++) {
		visited[i] = 0;
	}
	std::cout <<"시작 정점:"<< g->arr[source].dst << std::endl;
	dfsreculsive(g, source, visited);
}
void dfs_stack(graph* g, int source) {
	int count = g->count;
	int* visited = new int[count];
	for (int i = 0; i < count; i++) {
		visited[i] = 0;
	}
	int trav;
	int dst;
	stack stk;
	stack_initialize(&stk, 9);
	push(&stk, source);
	visited[source] = 1;
	while (getsize(&stk) != 0) {
		trav = pop(&stk);
		std::cout << "꺼낸 데이터:" << trav << std::endl;
		node* culnode = g->arr[trav].next;
		while (culnode) {
			dst = culnode->dst;
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
	undirectgraph(&grp,2, 3);
	undirectgraph(&grp, 2, 4);
	undirectgraph(&grp, 3, 4);
	undirectgraph(&grp, 3, 5);
	undirectgraph(&grp, 5, 6);
	undirectgraph(&grp, 5, 7);
	undirectgraph(&grp, 6, 8);
	dfs(&grp, 0);
	memoryfree(&grp);
}
