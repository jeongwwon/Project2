#include<iostream>
struct node {
	int des;
	node* next;
};
int main() {
	int count = 4;
	node* arr = new node[count];
	std::cout << arr << std::endl;;
}