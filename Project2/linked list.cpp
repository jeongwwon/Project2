#include<iostream>

class node {
public:
	int data;
	node* next;
};

class list {
public:
	list() {
		head = NULL;
		count = 0;
	}
	node* head;
	int count;
	void insert(int index, int data);
	void remove(int index);
	void print();
};

void list::insert(int index, int data)
{
	if (index <= list::count) {
		node* newnode = new node;
		newnode->data = data;
		newnode->next = NULL;
		if (head == NULL) {
			head = newnode;
			std::cout << "index: " << index << "," << "data:" << data << "  inserted!" << std::endl;
		}
		else {
			node* temp = head;
			for (int i = 0; i < index - 1; i++) {
				temp = temp->next;
			}
			if (temp->next != NULL) {
				newnode->next = temp->next;
			}
			temp->next = newnode;
			std::cout << "index: " << index << "," << "data:" << data << "  inserted!" << std::endl;
		}
		count++;
	}
	else {
		std::cout << "insert fail!" << std::endl;
	}
}

void list::remove(int index) {

	node* temp = head;
	int tdata;
	if (index < list::count) {
		if (index == 0) {
			tdata = head->data;
			head = head->next;
			std::cout << "index:" << index << "  deleted!" << std::endl;
			delete temp;
			
		}
		else {
			node* prev = head;
			for (int i = 0; i < index - 1; i++) {
				prev = prev->next;
			}
			temp = prev->next;
			tdata = temp->data;
			prev->next = temp->next;
			delete temp;
		}
		std::cout << "index:" << index << "  deleted!" << std::endl;
		count--;
	}
	else {
		std::cout << "remove fail!" << std::endl;
	}
	}
void list::print() {
	for (node* temp=head; temp->data !=NULL; temp=temp->next) {
		std::cout << temp->data << ' ';
	}
	std::cout << std::endl;
}
int main() {
	list lst;
	lst.insert(0, 1);
	lst.insert(1, 2);
	lst.insert(2, 1);
	lst.insert(3, 1);
	lst.remove(2);
	lst.remove(3);
	lst.insert(3, 5);
	lst.print();
}