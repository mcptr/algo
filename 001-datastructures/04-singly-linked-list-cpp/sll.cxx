#include <iostream>
#include <iomanip>


struct list_node
{
	int data;
	list_node *next;

	list_node(int value) : data(value), next(nullptr) {}
	
};


class list
{
public:
	~list()
	{
		clear();
	}

	inline std::size_t size() const
	{
		return size_;
	}

	inline bool is_empty() const
	{
		return head_ == nullptr;
	}

	void clear()
	{
		list_node *p;

		while(head_) {
			p = head_->next;
			delete head_;
			head_ = p;
			size_--;
		}
	}

	void append(int value)
	{
		if(!head_) {
			head_ = new list_node(value);
		}
		else {
			list_node *ptr = head_;

			while(ptr && ptr->next) {
				ptr = ptr->next;
			}

			ptr->next = new list_node(value);
		}

		size_++;
	}

	void insert(int value)
	{
		if(!head_) {
			append(value);
			return;
		}

		list_node *new_node = new list_node(value);

		if(head_->data > value) {
			new_node->next = head_;
			head_ = new_node;
		}
		else {

			list_node *ptr = head_;
			while(ptr->next && ptr->next->data < value) {
				ptr = ptr->next;
			}
			new_node->next = ptr->next;
			ptr->next = new_node;
		}

		size_++;
	}

	const list_node *nth_from_end(int n)
	{
		list_node *ahead_ptr = head_;
		list_node *ptr = head_;

		for(int i = 0; i < n; i++) {
			ahead_ptr = ahead_ptr->next;
			if(!ahead_ptr) {
				return nullptr;
			}
		}

		while(ahead_ptr->next) {
			ahead_ptr = ahead_ptr->next;
			ptr = ptr->next;
		}

		return ptr;
	}

	
	bool remove(int value)
	{
		list_node *p;
		bool ok = false;

		if(!head_) { return false; }

		if(head_->data == value) {
			p = head_->next;
			delete head_;
			head_ = p;
			ok = true;
		}
		else {
			p = head_;
			while(p->next && p->next->data != value) {
				p = p->next;
			}
			if(!p->next) {
				ok = false;
			}
			else {
				list_node *nn = p->next->next;
				delete p->next;
				p->next = nn;
				ok = true;
			}
		}

		if(ok) {
			size_--;
		}
		return ok;
	}

	void reverse()
	{
		list_node *p = head_;
		list_node *last_head = head_;
		while(p->next) {
			head_ = p->next;
			p->next = head_->next;
			head_->next = last_head;
			last_head = head_;
		}
	}
	
	void reverse_two_step()
	{
		list_node *p = head_;
		while(p && p->next) {
			p = p->next;
		}

		list_node *new_head = p;
		list_node *tmp;
		p = head_;

		while(p != new_head) {
			tmp = p->next;

			p->next = new_head->next;
			new_head->next = p;
			p = tmp;
		}
		head_ = new_head;
	}
	
	void display() const
	{
		if(is_empty()) {
			std::cout << "(Empty)"<< std::endl;
		}
		else {
			list_node *ptr = head_;
			while(ptr) {
				std::cout << ptr->data << " ";
				ptr = ptr->next;
			}
			std::cout << std::endl;
		}
	}

private:
	list_node *head_ = nullptr;
	std::size_t size_ = 0;
};


int main()
{
	list l;
	l.append(5);
	l.append(10);
	l.append(20);

	l.insert(15);
	l.insert(4);

	l.display();

	l.remove(4);
	l.display();

	l.reverse();
	l.display();

	l.reverse_two_step();
	l.display();

	for(std::size_t i = 0; i < l.size() + 2; i++) {
		const list_node *p;
		if((p = l.nth_from_end(i)) != nullptr) {
			std::cout << "nth_from_end(" << i << "): "
					  << std::dec << std::setw(2) << p->data
					  << " (" << std::hex << p << ")" << std::endl;
		}
		else {
			std::cout << "NO nth_from_end(" << i << "): "
					  << "(none) (" << std::hex << (void*)p << ")" << std::endl;
		}
	}

	
	l.clear();

	l.display();

	return 0;
}
