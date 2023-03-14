#include<iostream>
#define SIZE 100
class heap {
public:
	int* arr;
	int capacity;
	int size;
};
void shiftup(int* arr, int index) {
	int temp;
	int paridx = (index - 1) / 2;
	if (paridx >= 0) {
		if (arr[index] > arr[paridx]) {
			temp = arr[index];
			arr[index] = arr[paridx];
			arr[paridx] = temp;
			shiftup(arr, paridx);
		}
	}
}
void shiftdown(int *arr,int index,int size) {
	int temp;
	int left = (2 * index) + 1;
	int right = left + 1;
	int large=-1;
	if (left < size) {
		large = left;
	}
	if (right < size && arr[left] < arr[right]) {
		large = right;
	}
	if (large!=-1 && arr[index] < arr[large]) {
		temp = arr[index];
		arr[index] = arr[large];
		arr[large] = temp;
		shiftdown(arr, large, size);
	}
}
void heapadd(heap* p, int value) {
	p->arr[p->size] = value;
	shiftup(p->arr, p->size);
	p->size++;
}

void heapify(heap *p,int* a, int size) {
	p->arr = a;
	p->size = size;
	p->capacity = SIZE;
	for (int i =p->size / 2 - 1; i >= 0; i--) {
		shiftdown(p->arr, i,p->size);
	}
}
int heapremove(heap* p) {
	int temp = p->arr[p->size];
	p->arr[0] = p->arr[p->size - 1];
	p->size--;
	shiftdown(p->arr, 0, p->size);
	return temp;
}

int main() {
	heap heap;
	int a[SIZE] = {3,8,4,9,5,1,7,2};
	heapify(&heap,a,8);
	heapadd(&heap, 10);
	heapadd(&heap, 20);
	heapadd(&heap, 30);
	heapadd(&heap, 40);
	heapadd(&heap, 50);
	heapadd(&heap, 60);
	heapadd(&heap, 70);
	for (int i = 0; i < 20; i++) {
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "Å©±â:" << heap.size;
}