#include<iostream>
template<class T>
class stack {
private:
	int top, maxsize;
	T* stack1;     // arraystack
	
public:
	stack(int size);
	bool isfull(), isempty();
	T pop(); 
	void push(T element);
	void print();
	T remove();
};
template <class T>
T stack<T>::remove() {
	for (int i = 0; i < maxsize; i++) {
		stack1[i] = NULL;
	}
	return *stack1;
}
template <class T>
stack<T>::stack(int size) {
	maxsize = size;
	stack1 = new T[maxsize];
	top = -1;
}
template <class T>
bool stack<T>::isfull() {
	if (top == maxsize-1)
		return 1;
	else
		return 0;
}
template <class T>
bool stack<T>::isempty() {
	if (top == -1)
		return 1;
	else
		return 0;
}
template <class T>
T stack<T>::pop() {
	if (isempty() == 1)
		std::cout << "empty!" << '\n';
	else
		return stack1[top--];
}
template <class T>
void stack<T>::push(T element) {
	if (isfull() == 1)
		std::cout << "full!" << std::endl;
	else
		stack1[++top] = element;
}
template <class T>
void stack<T>::print() {
	for (int i = 0; i < top + 1; ++i)
		std::cout << stack1[i] << std::endl;
}

int main() {
	stack<char> st(3);
	st.push('j');
	st.push('l');
	st.push('t');
	//st.remove();
	st.print();
}