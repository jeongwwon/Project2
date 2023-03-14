#include<iostream>
class node {
public:
	int data;
	node* next;
};

class list {
public:
	int count;
	node* head;
	list() {
		head = NULL;
		count = 0;
	}
	void insert(int index, int data);
	void remove(int index);
	void print();
};

void list::insert(int index, int data) {
	if (index <= list::count) {
		node* newnode = new node; //새로운 노드를 class node의 포인터로 초기화
		newnode->data = data;        //초기화된 data를 파라미터로 초기화
		newnode->next = NULL; 
		if (head == NULL) {             //list의 head값이 없을때 새로운 노드의 주소를 head값 입력
			head = newnode;
		}
		// list가 비어있을때
		else {
			node* temp = head; // 비어있지 않다면 head를 가르키는 포인터 temp 지정
			for (int i = 0; i < index-1 ; i++) //index=2
			{
				temp = temp->next;   // 0 (1) 3newnode.next->{2}
			}
			if (temp->next != NULL) {
				newnode->next = temp->next; //현재 노드의 다음을 새로운 노드의 다음노드로 지정
			}
			temp->next = newnode;     // 1.처음에 인덱스-1 만큼의 현재 head의 next를 head로 지정 2.head의 next가 비어있지 않다면 변경한 head의 next를 newnode의
			//next로 지정 3.newnode를 head의 next로 삽입
		}
		count++;
		std::cout << "index:" << index <<',' << "data:" << data << "  " << "inserted!" << std::endl;
	}
	else
		std::cout << "fail!" << std::endl;
}
void list::remove(int index) {
	if (index < list::count) {
		node* temp = head;
		int tdata;
		if (index == 0) {  //리스트 가장 앞원소 제거
			tdata = head->data;
			head = head->next;
			delete temp;
		}
		else
		{
			node* prev = head;    //prev 를 head로지정
			for (int i = 0; i < index - 1; i++)
			{
				prev = prev->next;  // index-1 만큼 head이동
			}
			temp = prev->next;   //변경된 head의 next를 temp로 지정  (*prev).next
			tdata = temp->data;  //temp의 data를 tdata에 할당
			prev->next = temp->next; //temp의 next를 변경된 head의 next로 지정 -> temp 삭제
			delete temp;
		}
		std::cout << "index:" << index <<',' << "data:" << tdata << "  " << "deleted!!" << std::endl;
}
	else {
		std::cout << "fail remove!" << std::endl;
	}
	count--;
}
void list::print()
{
	for (node* temp = head; temp != NULL; temp = temp->next)
	{
		std::cout << temp->data << " ";
	}
	std::cout << std::endl;
}

int main()
{

	list llist;

	for (int i = 0; i < 5; i++) {
		llist.insert(i, i);
	}

	llist.print();

	llist.remove(3);
	llist.remove(8);

	llist.insert(3, 10);
	llist.remove(10);
	
	llist.print();
	
	std::cout << llist.count << "  this ";
}




