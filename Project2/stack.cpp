#include<iostream>
template<class T>
class stack {
private:
	T* stack1;
	int maxsize, top;
public:
	stack<T>() {};
	stack(int size);
	bool isfull(), isempty();
	void push(T data);
	T pop();
	void print();
};
template<class T>
stack<T>::stack(int size):maxsize(size) {
	stack1 = new T[maxsize];
	top = -1;
}
template<class T>
bool stack<T>::isempty() {
	if (top == -1) {
		std::cout << "Stack is empty!" << std::endl;
		return 0;
	}
	else
		return 1;
}
template<class T>
bool stack<T>::isfull() {
	if (top == maxsize) {
		std::cout << "Stack is full!" << std::endl;
		return 0;
	}
	else
		return 1;
}
template<class T>
void stack<T>::push(T data) {
	if (isfull()) {
		stack1[++top] = data;
		std::cout<<"인덱스:" << top << "에 data:" << data << "가 추가 되었습니다." << std::endl;
	}
	else
		std::cout << "스택이 가득찼습니다." << std::endl;
}
template<class T>
T stack<T>::pop() {
	if (isempty()) {
		std::cout << "인덱스:" << top << "에 data:"<< stack1[top] <<"가 삭제되었습니다" << std::endl;
		return stack1[top--];
	}
	
}
template<class T>
void stack<T>::print() {
	if (isempty()) {
		std::cout << "print 출력값:";
		for (int i = 0; i <= top; i++) {
			std::cout << stack1[i] ;
		}
	}
	else {
		std::cout << "데이터가 비었습니다." << std::endl;
	}
	}


int main() {
	int max;
	std::cout << "stack의 max size를 입력하세요" << std::endl;
	std::cin >> max;
	stack<char> st(max);
	st.push('j');
	st.push('e');
	st.push('o');
	st.push('n');
	st.push('g');
	st.push('w');
	st.push('o');
	st.push('n');
	std::cout << "return 값:" << st.pop() << std::endl;
	std::cout << "return 값:" << st.pop() << std::endl;
	std::cout << "return 값:" << st.pop() << std::endl;/*
	std::cout << "return 값:" << st.pop() << std::endl;
	std::cout <<"return 값:" <<st.pop() << std::endl;
	std::cout <<"return 값:" <<st.pop() << std::endl;*/
	st.print();

}
