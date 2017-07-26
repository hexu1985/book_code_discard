/* --------------->> ilist.cpp <<---------------- */
#include <iostream>
#include "ilist.h" 

ilist_item *ilist::find(int value)
{   // 在链表中查找值为value的第一个节点 
    ilist_item *ptr = _at_front;
    while (ptr) {
        if (ptr->value() == value)
            break;
        ptr = ptr->next();
    }
    
    return ptr;
}

void ilist::display(std::ostream &os)
{   // 顺序显示链表中的所有节点 
    os << "\n( " << _size << " )( ";
    
    ilist_item *ptr = _at_front;
    while (ptr) {
        os << ptr->value() << " ";
        ptr = ptr->next();
    }
    os << ")\n";
}

void ilist::remove_all()
{   // 删除链表中的所有节点 
    while (_at_front)
        remove_front();
    
    _size = 0;
    _at_front = _at_end = 0;
}

int ilist::remove(int value)
{
    ilist_item *plist = _at_front;
    int elem_cnt = 0;
    
    while (plist && plist->value() == value) {  // 删除链表头值为value的节点 
        plist = plist->next();
        remove_front();
        ++elem_cnt;
    }
    
    if (!plist)     // 表空，返回 
        return elem_cnt;
        
    ilist_item *prev = plist;   // 此处的plist所指节点的值不等于value 
    plist = plist->next();      // plist后移一个节点 
    
    while (plist) {
        if (plist->value() == value) {  // 如果plist所指节点的值等于value
            prev->next(plist->next());  // prev->_next = plist->_next
            delete plist;
            ++elem_cnt;
            bump_down_size();
            plist = prev->next();
            if (!plist) {
                _at_end = prev;
                return elem_cnt;
            }
        } else {    // 如果plist所指节点的值不等于value
            prev = plist;
            plist = plist->next();
        }
    }
    
    return elem_cnt;
} 
        
void ilist::concat(const ilist &il)
{   // 将il链表的所有节点附加(复制)到this链表的后面 
    ilist_item *ptr = il._at_front;
    while (ptr) {
        insert_end(ptr->value());
        ptr = ptr->next();
    }
}

void ilist::reverse()
{   // 将链表翻转(翻转元素的顺序) 
	if (!_at_end)
	   return;
	   
    ilist_item *ptr = _at_front;
    ilist_item *prev = 0;
    
    _at_front = _at_end;
    _at_end = ptr;
    
    while (ptr != _at_front) {
        ilist_item *tmp = ptr->next();
        ptr->next(prev);
        prev = ptr;
        ptr = tmp;
    }
    
    _at_front->next(prev);
}

void ilist::reverse2()
{	// 效果同reverse, 但是算法是何旭实现的, 而非Lippman。
	if (!_at_end)
		return;
	
	ilist_item *ptr = _at_front;
    ilist_item *prev = 0;
    
    _at_front = _at_end;
    _at_end = ptr;
	
	while (ptr != _at_front) {
		prev = ptr->next();
		ptr->next(_at_front->next());
		_at_front->next(ptr);
		ptr = prev;
	}
}
