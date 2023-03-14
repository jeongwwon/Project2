#include<iostream>
struct node {
	int vertex;
	node* next;
};
struct graph {
	node* head;
	int vertexcount;
};

void graphinitialize(graph* p, int count) {
	p->vertexcount = count;
	p->head = new node[count];
	for (int i = 0; i < p->vertexcount; i++) {
		p->head[i].vertex = i;
		p->head[i].next = NULL;
	}
}

void directedge(graph * p, int src, int des) {
	node* newnode = new node;
	newnode->vertex = des;
	newnode->next = NULL;
	if (p->head[src].next == NULL) {
		p->head[src].next = newnode;
		return;
	}
	newnode->next = p->head[src].next;
	p->head[src].next = newnode;
}
void undirectedge(graph* p, int src, int des) {
	directedge(p, src, des);
	directedge(p, des, src);
}
void display(graph*p){
	node* culnode;
	for (int i = 0; i < p->vertexcount; i++) {
		culnode = p->head[i].next;
		std::cout << "출발지 노드:" << p->head[i].vertex << std::endl;
		while (culnode != NULL) {
			std::cout << culnode->vertex << ' ';
			culnode = culnode->next;
		}
		std::cout << std::endl;
	}
}

int main() {
	graph grp;
	graphinitialize(&grp, 4);
	undirectedge(&grp, 0, 1);
	undirectedge(&grp, 0, 2);
	undirectedge(&grp, 1, 2);
	undirectedge(&grp, 2, 3);
	display(&grp);
}