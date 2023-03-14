#include<iostream>

void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}
void bubblesort(int* a,int count) {
	int temp;
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a + j, a + j + 1);
			}
		}
	}
}
void recbubblesort(int* a,int count) {
	if (count <= 0) {
		return;
	}
	for (int i = 0; i < count-1; i++) { 
		if (a[i] > a[i + 1]) {
			swap(a+i, a+i+1);
		}
	}
	recbubblesort(a, count - 1);
}
void selectionsort(int* a, int count) {
	int minidx;
	for (int i = 0; i < count - 1; i++) {
		minidx = i;
		for (int j = i+1; j < count; j++) {
			if (a[minidx] > a[j]) {
				minidx = j;
			}
		}
		swap(a + i, a + minidx);
	}
}
void insertsort(int* a, int count) {
	for (int i = 1; i < count; i++) {
		int temp = i;
		std::cout <<"current 인덱스:" << i << std::endl;
		for (int j = i-1; 0 <= j;j--) {
			if (a[j] > a[temp]) {
				swap(a + j, a + temp);
				std::cout <<"temp 감소" << --temp << std::endl;
			}
		}
	}
}
void recinsertsort(int* a, int size,int count) {
	if (count == size) {
		return;
	}
	if (count == 0) {
		recinsertsort(a, size, count + 1);
		return;
	}
	int temp = count;
	for (int i = temp-1; 0<=i ; i--) {
		if (a[i] > a[temp]) {
			swap(a + i, a + temp);
			std::cout << "temp 값:" << temp << "," << "i값:" << i << std::endl;
			for (int i = 0; i < size; i++) {
				std::cout << a[i] << ' ';
			}
			std::cout << std::endl;
			temp--;
		}
		std::cout << std::endl;
	}
	recinsertsort(a, size, count + 1);
}
void display(const int *a,int count) {
	for (int i = 0; i < count; i++) {
		std::cout << a[i] << ' ';
	}
}
int main() {
	int* newnode = new int[5];
	newnode[0] = 5;
	newnode[1] = 4;
	newnode[2] = 3;
	newnode[3] = 2;
	newnode[4] = 1;
	recinsertsort(newnode,5,0);
	display(newnode, 5);
}
	