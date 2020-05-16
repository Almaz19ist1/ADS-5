#include <iostream>
struct SYM
{
	char ch;
	int prior;
};

struct ITEM
{
	SYM data;
	ITEM* next;
};

class TPQueue
{
public:
	TPQueue() :begin(nullptr), end(nullptr) {}
	~TPQueue();
	void push(SYM& data);
	SYM pop();
	void print();
	ITEM create(SYM& data);
private:
	ITEM* begin;
	ITEM* end;
};

ITEM TPQueue::create(SYM& data)
{
	ITEM* item = new ITEM;
	item->data = data;
	item->next = nullptr;
	return *item;
}

TPQueue::~TPQueue()
{
	while (begin)
		pop();
}

void TPQueue::push(SYM& data)
{
	if (begin && end)
	{
		ITEM* temp = begin;
		while (temp)
		{
			if ((temp->data.prior >= data.prior) && (data.prior > temp->next->data.prior))
			{
				ITEM temp_1 = create(data);
				temp_1.next = temp->next;
				temp->next = &temp_1;
				break;
			}
			temp = temp->next;
		}
	}
	else
	{
		*begin = create(data);
		end = begin;
	}
}

SYM TPQueue::pop()
{
	if (begin)
	{
		ITEM* temp = begin->next;
		SYM data = begin->data;
		delete begin;
		begin = temp;
		return data;
	}
	else
	{
		return;
	}
}

void TPQueue::print()
{
	ITEM* temp = begin;
	while (temp)
	{
		std::cout << temp->data.ch << ' ';
		temp = temp->next;
	}
	std::cout << std::endl;
}
