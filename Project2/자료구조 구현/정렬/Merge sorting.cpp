#include<iostream>
void merge2(int* arr, int* newnode, int left, int mid, int right) {
	int idx1 = left;
	int idx2 = mid + 1;
	int idxm = left;
	for (int i = left; i <= right; i++) {
		newnode[i] = arr[i];
	}
	while (idx1 <= mid && idx2 <= right) {
		if (newnode[idx1] < newnode[idx2]) {
			arr[idxm++] = newnode[idx1++];
		}
		else {
			arr[idxm++] = newnode[idx2++];
		}
	}
		while (idx1 <= mid) {
			arr[idxm++] = newnode[idx1++];
		}
		while (idx2 <= right) {
			arr[idxm++] = newnode[idx2++];
		}
}
void merge1(int* arr, int* newnode, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge1(arr, newnode, left, mid);
		merge1(arr, newnode, mid + 1, right);
		merge2(arr, newnode, left, mid, right);
	}
}
void merge(int* arr, int size) {
	int left = 0;
	int right = size-1;
	int* newnode = new int[size];
	for (int i = 0; i < size; i++) {
		newnode[i] = 0;
	}
	merge1(arr, newnode, left, right);
}
int main() {
	int arr[] = { 7,5,2,4,1,3,8,6,10,11,9,20,100,100000,1000 };
	int size = sizeof(arr) / sizeof(arr[0]);
	merge(arr,size);
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ' ';
	}
}