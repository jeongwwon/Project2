#include<iostream>
struct node {
	int vertex;
	node* next;
};
struct graph {
	node* head;
	int vercount;
};
void graphinitialize(graph* p,int count) {
	p->vercount = count;
	p->head = new node[count];
	for (int i = 0; i < p->vercount; i++) {
		p->head[i].vertex = i;
		p->head[i].next = NULL;
	}
}

void directedge(graph* p, int str, int end) {
	node* newnode = new node;
	newnode->vertex = end;
	//newnode->next = NULL;
	if (p->head[str].next == NULL) {
		p->head[str].next = newnode;
		return;
	}
	newnode->next = p->head[str].next;
	p->head[str].next = newnode;
}

void undirectedge(graph* p, int str, int end) {
	directedge(p, str,end);
	directedge(p, end, str);
}
void display(graph* p) {
	node* culnode;
	for (int i = 0; i < p->vercount; i++) {
		culnode = p->head[i].next;
		std::cout << "출발지 노드:" << p->head[i].vertex << std::endl;
		while (culnode != NULL) {
			std::cout << culnode->vertex << ' ';
			culnode = culnode->next;
		}
	}
}

int main() {
	graph grp;
	graphinitialize(&grp, 4);
	undirectedge(&grp, 0, 1);
	undirectedge(&grp, 0, 2);
	undirectedge(&grp, 2,3);
	undirectedge(&grp, 1,2);
	display(&grp);
}