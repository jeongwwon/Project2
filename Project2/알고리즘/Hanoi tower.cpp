#include<iostream>
void hanoi(int n, int start, int end, int midle) {
	if (n == 1) {
		std::cout << start << ' ' << end << std::endl;
		return;
	}
	else {
		hanoi(n - 1, start, midle, end);
		std::cout << start << ' ' << end << std::endl;
		hanoi(n - 1, midle, end, start);
	}
}

int main() {
	hanoi(5, 1, 3, 2);
}

