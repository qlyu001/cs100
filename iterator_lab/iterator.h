#ifndef ITERATOR_H
#define ITERATOR_H

//#include "composite.h"
#include <stack>
#include <cstdlib>
using namespace std;

class Base;

class Iterator
{
	protected:
		Base* self_ptr;
		Base* current_ptr;

	public:
    Iterator(Base* ptr){ this->self_ptr = ptr; }
    //Iterator(){};

		//sets up the iterator to start at the beginning of traversal
		virtual void first() = 0;

		//move to next element
		virtual void next() = 0;

		//returns if you have finished iterating through all elements
		virtual bool is_done() = 0;

		//return the element the iterator is currently at
		virtual Base* current() = 0;
   
};

//used to iterate over composite nodes w/ 2 children
//initialize to left then left to right child then NULL
class OperatorIterator : public Iterator
{
	public:
    OperatorIterator(Base* ptr);
    
		void first();
		void next();

		bool is_done();
		Base* current();
};

//used to iterate over composite nodes w/ 1 child (Sqr)
//initialize to only child (declared as left child) to NULL
class UnaryIterator : public Iterator
{
	public:
    UnaryIterator(Base* ptr);
		void first();

		void next();

		bool is_done();
		Base* current();
};

//iterate over leaf nodes
class NullIterator : public Iterator
{
	public:
    NullIterator(Base* ptr): Iterator(ptr){}
    //don't need to do anything
		void first()
    {
        current_ptr = NULL;
    }
		void next()
    {
        current_ptr = NULL;
    }

		//always return true b/c leafs have no children
		bool is_done()
		{ return true; }

		//always return NULL
		Base* current()
		{ return NULL; }
};

//has additional stack data member to keep track of collection iterators
//that we need to traverse
class PreOrderIterator : public Iterator
{
	protected:
		stack<Iterator*> iterators;

	public:
    PreOrderIterator(Base* ptr);

		void first();
		void next();
		bool is_done();
		Base* current();
};

#endif
