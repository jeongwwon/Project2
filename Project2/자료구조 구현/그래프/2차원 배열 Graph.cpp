#include<iostream>
struct graph {
	int vercount;
	int** arr;
};
void graphintialize(graph *p,int count){
	p->vercount = count;
	p->arr = new int*[count];
	for (int i = 0; i < count; i++) {
		p->arr[i] = new int[count];
		for (int j = 0; j < count; j++) {
			p->arr[i][j] = 0;
		}
	}
}
void addedge(graph* p, int src, int des) {
	p->arr[src][des] = 1;
}
void addunedge(graph* p, int src, int des) {
	addedge(p, src, des);
	addedge(p, des, src);
}
void display(graph* p) {
	std::cout << "\n 간선 현황 \n" << std::endl;
	for (int i = 0; i < p->vercount; i++) {
		std::cout << "출발지:" << i << std::endl;
		for (int j = 0; j < p->vercount; j++) {
			std::cout << p->arr[i][j] << std::endl;
		}
		std::cout << std::endl;
	}
}
void memoryfree(graph* p) {
	for (int i = 0; i < p->vercount; i++) {
		std::cout << "동적메모리 해제" << std::endl;
		delete(p->arr[i]);
	}
	delete(p->arr);
	std::cout << "포인터 배열 동적 메모리 해제" << std::endl;
}
int main() {
	graph grp;
	graphintialize(&grp, 4);
	addunedge(&grp, 0, 1);
	addunedge(&grp, 0, 2);
	addunedge(&grp, 1, 2);
	addunedge(&grp, 2, 3);
	display(&grp);
	memoryfree(&grp);
}