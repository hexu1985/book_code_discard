/* -------------------->> ilist.h <<----------------------- */
#include <iostream>

class ilist_item {  // 链表节点类 
public:
	ilist_item(int value, ilist_item *item_to_link_to = 0);
	int value() {return _value;}
	ilist_item *next() {return _next;}

	void next(ilist_item *link) {_next = link;}
	void value(int new_value) {_value = new_value;}
	
private:
	int _value;
	ilist_item *_next;
};

inline ilist_item::ilist_item(int value, ilist_item *item) : _value(value)
{   // 在item指向的节点后插入值为value的节点 
	if (!item)
		_next = 0;
	else {
		_next = item->_next;
		item->_next = this;
	}
}

class ilist {   // 链表类 
public:
	// 缺省构造函数
	ilist() : _at_front(0), _at_end(0), _size(0) {}
	
	int size();
	
	void bump_up_size();
	void bump_down_size();
	
	void insert(ilist_item *ptr, int value);
	void insert_front(int value);
	void insert_end(int value);
	
	ilist_item *find(int value);
	
	void display(std::ostream &os = std::cout);
	
	void remove_front();
	void remove_all();
	
	int remove(int value);
	
	void concat(const ilist &il);
	void reverse();
	void reverse2();
		
private:
	ilist_item *_at_front;
	ilist_item *_at_end;
	int _size;
	
	// 禁止用一个链表对象初始化或赋值给另一个
	ilist(const ilist &);
	ilist &operator=(const ilist&);
};

inline void ilist::bump_up_size()
{   // 将链表的大小加1 
    ++_size;
}

inline void ilist::bump_down_size()
{   // 将链表的大小减1 
    --_size;
}

inline void ilist::insert(ilist_item *ptr, int value)
{   // 在ptr指向的节点后插入值为value的节点
	if (!ptr)
		insert_front(value);
	else {
		bump_up_size();
		new ilist_item(value, ptr);
	}
}

inline void ilist::insert_front(int value)
{   // 在链表头节点前插入值为value的节点
	ilist_item *ptr = new ilist_item(value);
	
	if (!_at_front)
		_at_front = _at_end = ptr;
	else {
		ptr->next(_at_front);
		_at_front = ptr;
	}
	bump_up_size();
}

inline void ilist::insert_end(int value)
{   // 在链表尾节点后插入值为value的节点
	if (!_at_end)
		_at_end = _at_front = new ilist_item(value);
	else
		_at_end = new ilist_item(value, _at_end);
	
	bump_up_size();
}

inline void ilist::remove_front()
{   // 删除链表头节点 
    if (_at_front) {
        ilist_item *ptr = _at_front;
        _at_front = _at_front->next();
        
        bump_down_size();
        delete ptr;
    }
}

    
