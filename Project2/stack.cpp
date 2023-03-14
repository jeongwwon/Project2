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
		std::cout<<"�ε���:" << top << "�� data:" << data << "�� �߰� �Ǿ����ϴ�." << std::endl;
	}
	else
		std::cout << "������ ����á���ϴ�." << std::endl;
}
template<class T>
T stack<T>::pop() {
	if (isempty()) {
		std::cout << "�ε���:" << top << "�� data:"<< stack1[top] <<"�� �����Ǿ����ϴ�" << std::endl;
		return stack1[top--];
	}
	
}
template<class T>
void stack<T>::print() {
	if (isempty()) {
		std::cout << "print ��°�:";
		for (int i = 0; i <= top; i++) {
			std::cout << stack1[i] ;
		}
	}
	else {
		std::cout << "�����Ͱ� ������ϴ�." << std::endl;
	}
	}


int main() {
	int max;
	std::cout << "stack�� max size�� �Է��ϼ���" << std::endl;
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
	std::cout << "return ��:" << st.pop() << std::endl;
	std::cout << "return ��:" << st.pop() << std::endl;
	std::cout << "return ��:" << st.pop() << std::endl;/*
	std::cout << "return ��:" << st.pop() << std::endl;
	std::cout <<"return ��:" <<st.pop() << std::endl;
	std::cout <<"return ��:" <<st.pop() << std::endl;*/
	st.print();

}
