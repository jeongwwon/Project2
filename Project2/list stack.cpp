#include <iostream>

class node {
public:
	int data;
	node* next;
};
class list {
public:
	int top,maxsize;
	node* head;
	list(int size) {
		maxsize = size;
		top = -1;
		
	};
	bool isfull(),isempty();
	int pop();
	void push(int data);
	void print();
};

bool list::isempty() {
	if (top == -1) {
		std::cout << "������ ������ϴ�" << std::endl;
		return 0;
	}
	else
		return 1;
}
bool list::isfull() {
	if (top == maxsize-1) {
		std::cout << "������ ��á���ϴ�." << std::endl;
		return 0;
	}
	else
		return 1;
}
void list::push(int data) {
	node* newnode = new node;
	newnode->data = data;
	newnode->next = NULL;
	if (isfull()) {
		if (head == NULL) {
			head = newnode;
			std::cout << "�ε���:" << ++top << "�� data:" << data << "�� ���ԵǾ����ϴ�." << std::endl;
		}
		else {
			node* temp = head;
			for (int i = 0; i < top;i++){// 0 1 2
				temp = temp->next;
		}
			temp->next = newnode;
			std::cout << "�ε���:" << ++top << "�� data:" << data << "�� ���ԵǾ����ϴ�." << std::endl;
	}
		}
	else
		std::cout << "�����Ͱ� ���� á���ϴ�." << std::endl;
}
void list::print() {
	for (node* temp=head; temp!=NULL; temp=temp->next) {
		std::cout << temp->data << ' ';
	}
}
int main() {
	list t(5);
	t.push(1);
	t.push(2);
	t.push(3);
	t.push(4);
	t.push(4);
	t.print();


}
