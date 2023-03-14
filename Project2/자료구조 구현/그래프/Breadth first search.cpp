#include<iostream>

struct node {
	int vertex;
	node* next;
};
struct graph {
	int vertexcount;
	node* arr;
};
struct queue {
	int front, rear,capacity;
	int count;
	int* queue;
};
void bfsreculsive(graph* g, queue* q, int search, int* visited);

void graphinitialize(graph *g,int size){
	g->vertexcount = size;
	g->arr = new node[size];
	for (int i = 0; i < g->vertexcount; i++) {
		g->arr[i].vertex = i;
		g->arr[i].next = NULL;
	}
}
void directgraph(graph* g, int src, int dst) {
	node* newnode = new node;
	newnode->vertex = dst;
	newnode->next = NULL;
	if (g->arr[src].next == NULL) {
		g->arr[src].next = newnode;
		return;
	}
	newnode->next = g->arr[src].next;
	g->arr[src].next = newnode;
}
void undirectgraph(graph *g,int src,int dst){
	directgraph(g, src, dst);
	directgraph(g, dst, src);
}
void memoryfree(graph* g) {
	node* delnode;
	for (int i = 0; i < g->vertexcount; i++) {
		while (g->arr[i].next) {
			delnode = g->arr[i].next;
			g->arr[i].next = delnode->next;
			delete delnode;
		}
	}
	delete[]g->arr;
	std::cout << "포인터 동적 메모리 해제\n";
}
void display(graph *g) {
	node* culnode;
	for (int i = 0; i < g->vertexcount; i++) {
		std::cout << "출발지 노드:" << i << std::endl;
		culnode = g->arr[i].next;
		while (culnode) {
			std::cout << culnode->vertex << ' ';
			culnode = culnode->next;
		}
		std::cout << std::endl;
	}
}
int is_empty(queue* q) {
	if (q->rear == q->front) {
		return 0;
	}
	else
		return 1;
}
void queueinitialize(queue* q, int size) {
	q->capacity = size;
	q->queue = new int[size];
	for (int i = 0; i < q->capacity; i++) {
		q->queue[i] = 0;
	}
	q->rear = 0;
	q->front = 0;
}
int dequeue(queue *q){
	if (q->front == q->rear) {
		std::cout << "큐가 비었습니다." << std::endl;
		return NULL;
}
	return q->queue[q->front++];
}
void enqueue(queue* q,int count){
	if (q->capacity <= q->rear) {
		std::cout << "큐가 꽉찼습니다." << std::endl;
		return;
	}
	q->queue[q->rear] = count;
	q->rear++;
}
void bfs(graph*g,int search){
	int* memory = new int[g->vertexcount];
	for (int i = 0; i < g->vertexcount; i++) {
		memory[i] = 0;
	}
	queue que;
	queueinitialize(&que, g->vertexcount);
	enqueue(&que, search);
	memory[search] = 1;
	bfsreculsive(g, &que, search,memory);
	}
void bfsreculsive(graph* g, queue* q, int search, int* visited) {
	node* culnode = g->arr[search].next;
	while (culnode) {
		if (visited[culnode->vertex] == 0) {
			enqueue(q, culnode->vertex);
			visited[culnode->vertex] = 1;
		}
		culnode = culnode->next;
	}
	if (is_empty(q) != 0) {
		int dst = dequeue(q);
		std::cout << "꺼낸 데이터:" << dst << std::endl;
		bfsreculsive(g, q, dst, visited);
	}
}


int main() {
	graph grp;
	graphinitialize(&grp, 9);
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
	bfs(&grp, 5);
	memoryfree(&grp);
}