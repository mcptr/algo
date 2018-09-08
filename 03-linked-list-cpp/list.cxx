#include <iostream>


template <typename T>
struct list_node
{
	T data;
	list_node<T>* next;

	list_node(const T& value) : data(value) {}
};

template <typename T>
class list
{
public:
	typedef list_node<T> list_node_t;

	list() : front_(nullptr) {}

	~list()
	{
		clear();
	}

	void append(const T& value)
	{
		auto new_node = new list_node_t(value);
		if(!front_) {
			front_ = new_node;
		}
		else {
			list_node_t* curr = front_;
			while(curr->next) {
				curr = curr->next;
			}

			curr->next = new_node;
		}
	}
	
	void clear()
	{
		list_node_t* p = front_;
		while(p) {
			delete front_;
			front_ = p->next;
			p = p->next;
		}
		front_ = nullptr;
	}

	bool remove(const T& value)
	{
		if(!front_) { return false; }

		list_node_t* p;

		if(front_->data == value) {
			p = front_->next;
			delete front_;
			front_ = p;
			return true;
		}

		p = front_;
		while(p && p->next) {
			if(p->next->data == value) {
				list_node_t* next = p->next->next;
				delete p->next;
				p->next = next;
				return true;
			}
			else {
				p = p->next;
			}
		}

		return false;
	}

	void insert_sorted(const T& value)
	{
		if(!front_) {
			append(value);
			return;
		}

		list_node_t* newnode = new list_node_t(value);
		if(value < front_->data) {
			newnode->next = front_;
			front_ = newnode;
		}
		else {
			list_node_t* p = front_;
			while(p->next && p->next->data < value) {
				p = p->next;
			}

			newnode->next = p->next;
			p->next = newnode;
		}
	}

	void print() const
	{
		list_node_t* p = front_;
		std::cout << "[ ";
		while(p) {
			std::cout << p->data << ", ";
			p = p->next;
		}
		std::cout << "]" << std::endl;
	}

private:
	list_node_t* front_;
};


int main()
{
	list<int> l;
	for(int i = 0; i < 10; i += 2) {
		l.append(i);
	}

	l.print();
	l.append(20);
	l.remove(8);
	l.print();
	l.remove(20);
	l.print();
	l.remove(0);
	l.print();

	l.insert_sorted(1);
	l.insert_sorted(3);
	l.print();
	l.insert_sorted(5);
	l.print();
	l.insert_sorted(7);
	l.insert_sorted(9);
	l.insert_sorted(8);
	l.print();

	l.clear();
	l.print();
	
	return 0;
}
