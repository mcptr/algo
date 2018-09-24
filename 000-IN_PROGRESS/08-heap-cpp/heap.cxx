#include <iostream>


class PriorityQueue
{
public:
	PriorityQueue(int cap) :
		capacity_(cap),
		array_(new int[cap])
	{
	}

	~PriorityQueue()
	{
		delete array_;
	}

	bool empty() const
	{
		return true;
	}

	void insert(int)
	{
	}

	int pop_front()
	{
		return 0;
	}

private:
	int capacity_;
	int* array_;

};

int main()
{
	PriorityQueue q(8);

	return 0;
}
