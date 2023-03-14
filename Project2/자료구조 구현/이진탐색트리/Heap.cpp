#include<iostream>
#define SIZE 10
/*heap은 complete binary tree 가정
 root에 최대값이 있으면 Maxheap,최소면 Minheap*/

class Heap {
public:
	int* arr;
	int size;
	int capacity;
};
void shiftdown(int* arr, int index, int size) {
	int temp;
	int left = (2 * index) + 1;
	int right = left + 1;
	int large=-999;
	if (left < size) {
		large = left;
	}
	if (right < size&&arr[left]<arr[right]) {
		large = right;
	}
	if (large!=-999 && arr[index] < arr[large]) {
		temp = arr[large];
		arr[large] = arr[index];
		arr[index] = temp;
		shiftdown(arr, large, size);
	}
}
void shiftup(int* arr, int index) {
	int temp;
	int parentidx = (index - 1) / 2;
	if (parentidx >= 0) {
		if (arr[index] < arr[parentidx]) {
			temp = arr[index];
			arr[index] = arr[parentidx];
			arr[parentidx] = temp;
			shiftup(arr, parentidx);
		}
	}
}
//자식 노드가 있는 노드들만 비교
void heapify(Heap *p,int *a,int size) {
	p->arr= a;    // 배열 a의 첫번째 주소를 가르키는 포인터 arr 
	p->size = size;
	p->capacity = SIZE;
	for (int i = p->size / 2 - 1; i >= 0; i--) {
		shiftdown(p->arr, i,p->size);
	}
}
void heapadd(Heap* p, int value) {
	p->arr[p->size] = value;  
	shiftup(p->arr, p->size);
	p->size++;
}
int heapremove(Heap* p) {
	int temp = p->arr[0];
	p->arr[0] = p->arr[SIZE - 1];
	p->size--;
	shiftdown(p->arr, 0, p->size);
	return temp;
}

int main() {
	int a[SIZE] = { 3,9,2,1,5,4,10};
	Heap heap;
	heapify(&heap, a, 7);
	/*heapadd(&heap, 10);
	heapadd(&heap, 5);
	heapadd(&heap, 6);
	std::cout << heapremove(&heap) << std::endl;
	std::cout << heapremove(&heap) << std::endl;*/
	//std::cout << heapremove(&heap) << std::endl;
	//std::cout << heapremove(&heap) << std::endl;
	for (int i = 0; i < SIZE; i++) {
		std::cout << a[i] << ' ';
	}
}