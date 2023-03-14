#include<iostream>
long double reculsive(int n) {
	if (n == 0) {
		return 1;
	}
	return n * reculsive(n - 1);
}
int main() {
	std::cout<<reculsive(20);
}