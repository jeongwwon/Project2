#include<iostream>
void quicksort(int *arr,int left,int right){
	int temp=0;
	int pl = left;
	int pr = right;
	int pivot = arr[(left +right) / 2];
	do {
		while (arr[pl] < pivot) {
			pl++;
		}
		while (pivot < arr[pr]) {
			pr--;
		}
		if (pl <= pr) {
			temp = arr[pl];
			arr[pl] = arr[pr];
			arr[pr] = temp;
			pl++;
			pr--;
		}
	}
	while (pl <= pr);
	if (left < pr) {
		quicksort(arr, left, pr);
	}
	if (pl < right) {
		quicksort(arr, pl, right);
	}
	}
int main() {
	int arr[] = {3,2,7,5,8,1,4,6};
	int left = 0;
	int right = 7;
	quicksort(arr, left, right);
	for (int i = 0; i < 8; i++) {
		std::cout << arr[i] << ' ';
	}
}