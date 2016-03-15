#include "iterator.h"
#include "composite.h"
#include<iostream>
#include <iostream>
#include <stack>
using namespace std;
UnaryIterator::UnaryIterator(Base* ptr): Iterator(ptr){}
PreOrderIterator::PreOrderIterator(Base* ptr):Iterator(ptr){}
void UnaryIterator::first()
{
    current_ptr = self_ptr->get_left();
}

void UnaryIterator::next()
{
    current_ptr = NULL;
}

bool UnaryIterator::is_done()
{
//    if(current_ptr == self_ptr->get_left())
//    {
//        current_ptr = NULL;
//        return false;
//    }
//    return true;
    if(current_ptr == NULL)
    {
        return true;
    }
    return false;
}

Base* UnaryIterator::current()
{
    return current_ptr;
    
}

OperatorIterator ::OperatorIterator(Base* ptr): Iterator(ptr){}

void OperatorIterator ::first()
{
    current_ptr = self_ptr->get_left();
}

void OperatorIterator ::next()
{
    if(current_ptr == self_ptr->get_left())
    {
        current_ptr = self_ptr->get_right();
    }
    else
    {
        current_ptr = NULL;
    }
}

bool OperatorIterator ::is_done()
{
    if(current_ptr == NULL)
    {
        return true;
    }
    return false;
    

}

Base* OperatorIterator ::current()
{
    return current_ptr;
}

void PreOrderIterator::first()
{
	//empty the stack (just in case something was left from another run)

	//create iterator for Base* that we built the iterator for

	//initialize that iterator and push it onto the stack
    if(self_ptr->get_left() == NULL)
    {
        return;
    }
    while(!iterators.empty())
    {
        //cout << ' ' << iterators.top();
        iterators.pop();
    }
    Iterator* i = self_ptr->create_iterator();
    i->first();
//    if(i->current() != NULL)
//    {
        iterators.push(i);
//    }
    
}

void PreOrderIterator::next()
{
    if(iterators.size() == 0)
    {
        return;
    }
	//create an iterator for the item on the top of the stack

	//initialize the iterator and push it onto the stack

	//as long as the top iterator on the stack is done, pop it off the
	//stack and then advance whatever iterator is now on top of the stack
    
    Iterator* i = iterators.top()->current()->create_iterator();
    i->first();
    iterators.push(i);
    //cout << "here" << endl;
    while(iterators.size() > 0 && iterators.top()->is_done())
    {
        //if()
        iterators.pop();
        if(iterators.size() == 0)
        {
            return;
            //break;
        }
//
        
        iterators.top()->next();
    
        
    }
}

bool PreOrderIterator::is_done()
{
	//return true if there are no more elements on stack to iterate
	if(iterators.empty())
	{
		return true;
	}

	return false;
}

Base* PreOrderIterator::current()
{
	//return current for the top iterator in the stack
    return iterators.top()->current();
}
