#include<iostream>

int rec(int n) {
	int minus1=1, minus2=1, cur=1;
	for (int i = 0; i <n-2; i++) {
		if (n < 2) {
			cur = 1;
		}
		minus2 = minus1;
		minus1 = cur;
		cur = minus1 + minus2;
	}
	return cur;
}

int main() {
	std::cout << rec(3);
}