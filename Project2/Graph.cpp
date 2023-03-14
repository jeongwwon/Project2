#include<iostream>
#include<stdlib.h>
class node {
public:
	int dst;
	node* next;
};
class graph {
public:
	int count;
	node* arr; //정점의 개수만큼 할당된 노드
};
class stack {
public:
	int top;
	int* arr; //stack의 주소 저장
	int capacity;
};
void stack_initialize(stack* stk, int count);
void push(stack* stk, int val);
void graph_initialize(graph* grp, int count);
void adddirectedEdge(graph* grp, int src, int dst);
void addundirectedEdge(graph* grp, int src, int dst);
void graph_display(const graph* grp);
void memoryfree(graph* grp);
int pop(stack* stk);
int getsize(const stack* stk);
int capacity(const stack* stk);
void DFSReculsive(graph* grp, int index, int* visited);
void DFS(graph* grp, int source);
void DFS_stack(graph* grp, int source);

void stack_initialize(stack* stk, int count) {
	stk->arr = new int;
	stk->top = 0;
	stk->capacity = count;
}
void push(stack* stk, int val) {
	if (stk->top >= stk->capacity) {
		std::cout << "stack overflow" << std::endl;
		return ;
	}
	stk->arr[stk->top++] = val; //*(stk.arr) == 실제값
}
int pop(stack* stk) {
	if (stk->top <= 0) {
		std::cout << "stack underflow" << std::endl;
		return -1;
	}
	return stk->arr[--(stk->top)];
}
int getcapacitiy(const stack* stk) {
	return stk->capacity;
}
int getsize(const stack* stk) {
	return stk->top;
}
void graph_initialize(graph* grp, int count) {
	grp->count = count;
	grp->arr= new node;
}
void adddirectedEdge(graph* grp, int src, int dst) {
	node* newnode = new node;
	newnode->dst = dst;
	newnode->next = grp->arr[src].next;
	grp->arr[src].next = newnode;
}
void graph_display(const graph* grp) {
	node* cur = NULL;
	if (grp == NULL)
		return;
	for (int i = 0; i < grp->count; i++) {
		cur = grp->arr[i].next;
		std::cout << "출발지 노드: i" << std::endl;
		while (cur) {
			std::cout << cur->dst << std::endl;
			cur = cur->next;
		}
		std::cout << '\n';
	}
}
	void memoryfree(graph * grp) {
		//int i=0;
		node* delnode;
		for (int i = 0; i < grp->count; i++) {
			while (grp->arr[i].next) {
				delnode = grp->arr[i].next;
				grp->arr[i].next = delnode->next;
					delete delnode;
			}
			delete grp->arr;
		}
	}