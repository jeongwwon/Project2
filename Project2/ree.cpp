#include<iostream>

int main() {
	int a[2][2] = {1,5,2,6};
	int(*p)[2];
	p = a;
	std::cout << *(*(p+1));
}	