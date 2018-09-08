#include <iostream>


template <class T>
class stack
{
public:
	stack(std::size_t max_size)
		: max_size_(max_size), stack_(new T[max_size]()) { }

	~stack()
	{
		delete stack_;
	}

	void push(const T& value)
	{
		if(is_full()) {
			throw std::runtime_error("full");
		}

		top_++;
		stack_[top_] = value;
	}
	
	T pop()
	{
		if(is_empty()) {
			throw std::runtime_error("empty");
		}
		top_--;
		return stack_[top_];
	}

	T peek() const
	{
		if(is_empty()) {
			throw std::runtime_error("empty");
		}
		return stack_[top_];
	}

	bool is_full() const
	{
		return (top_ == max_size_ + 1);
	}

	bool is_empty() const
	{
		return (top_ < 0);
	}
	
	inline long size() const { return top_; }

	inline long top_index() const { return top_; }
	
	void print() const
	{
		std::cout << "[";
		for (long i = 0; i <= top_; i++) {
			std::cout << stack_[i] << ", ";
		}
		std::cout << "]" << std::endl;
	}
private:
	long top_ = -1;
	long max_size_;
	T *stack_;
};



int main()
{
	stack<int> s(5);
	std::cout << s.top_index() << std::endl;

	s.push(1);
	std::cout << "PEEK: " << s.peek() << std::endl;
	s.push(2);
	std::cout << "PEEK: " << s.peek() << std::endl;
	s.push(3);

	s.print();

	s.pop();
	std::cout << "PEEK: " << s.peek() << std::endl;
	s.pop();
	std::cout << "PEEK: " << s.peek() << std::endl;
	s.print();

	s.pop();
	s.print();

	std::cout << "TOP: " << s.top_index() << std::endl;
	std::cout << "EMPTY: " << s.is_empty() << std::endl;
	return 0;
}
