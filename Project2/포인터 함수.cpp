#include<iostream>

void reculsive(int* a) {
	for (int i = 0; i < 3; i++) {
		std::cout << a[i] << std::endl;
	}
}
int main() {
	int a[3] = { 0,1,2 };
	reculsive(a + 2);
}