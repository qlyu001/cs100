#ifndef CONTAINER_H
#define CONTAINER_H

#include "base.h"
#include "sort.h"
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

class Sort;
//class selectionSort;
/*
class Sort
{
	public:
		Sort(){};	//constructor
		virtual void sort(Container* container) = 0;
};
*/

class Container
{
	protected:
		Sort* sort_function;

	public:
		//constructors
		Container() : sort_function(NULL){};
		Container(Sort* function) : sort_function(function){};

		//non virtual functions
		void set_sort_function(Sort* sort_function)
		{/* this = sort_function;*/ }

		//pure virtual functions
		virtual void add_element(Base* element) = 0;
		virtual void print() = 0;
		virtual void sort() = 0;
		virtual void swap(int i, int j) = 0;
		virtual Base* at(int i) = 0;
		virtual int size() = 0;
};

//container of vector
class ContainerVector: public Container
{
	private:
		vector<Base*> a;
		Sort* s;

	public:
		//constructors
		ContainerVector(): s(NULL){}	//sort object empty		
		ContainerVector(Sort* function)	//sets argument as current sort object
		{ s = function; }

		void add_element(Base* element)	//add elements to vector
		{ a.push_back(element); }

		//prints elements in vector
		void print()	
		{
			for(unsigned int i = 0; i < a.size(); i++)
			{ 	
				if(i != 0)	//add comma till last number
				{ cout << ", "; }

				cout << a.at(i)->evaluate();	//output value
			}
			cout << endl;
		}
		
		void sort()
		{
			//selectionSort ss;
			//Sort* s = &ss;
			s->sort(this);		//sort the current container object
		}
		
		void swap(int i, int j)		//swap 2 values at given position
		{
			Base* temp = a.at(i);
			a.at(i) = a.at(j);
			a.at(j) = temp;	
		}

		Base* at(int i)			//return value at position i
		{ return a.at(i); }

		int size()				//return container size
		{ return a.size(); }
};

//container of List
class ContainerList: public Container
{
	private:
		list<Base*> a;
		Sort* s;

	public: 
		//default constructor
		ContainerList(): s(NULL){}			//sort object empty
		ContainerList(Sort* function)		//set argument as current sort object
		{ s = function; }

		void add_element(Base* element)		//adding elements to container
		{ a.push_back(element); }

		void print()						//print contents of container
		{
			for(list<Base*>::iterator i = a.begin(); i != a.end(); ++i)
			{ 
				if(i != a.begin())			//add comma till end
				{ cout << ", "; }	

				cout << (*i)->evaluate();	//print value
			}
			cout << endl;
		}

		void sort()							//sort container list
		{
			//selectionSort ss;
			//Sort* s = &ss;
			s->sort(this);
		}

		void swap(int i, int j)				//swap 2 values at given position
		{

			Base* tmp = at(i);				
			Base* tmp2 = at(j);

			if(tmp != NULL and tmp2 != NULL and i != j)		//if values are NULL and are not in same index
			{
				list<Base*>::iterator start;
				list<Base*>::iterator end;	
				int counter = 0;

				for(list<Base*>::iterator pos = a.begin(); pos != a.end(); pos++)
				{
					if(counter == i)
					{ start = pos; }
					else if(counter == j)
					{ end = pos; }

					counter++;
				}
				//cout << (*start)->evaluate() << endl;
				//cout << (*end)->evaluate() << endl;
				iter_swap(start,end);
			}	
		}

		Base* at(int i)		//return element at ith position in list
		{
			int counter = 0; 	
			for(list<Base*>::iterator j = a.begin(); j != a.end(); j++)
			{
				
				if(counter == i)	//if iterator pos == ith position
				{ 
					//cout << "Found value at index " << i << endl;
					return *j; 		//return element
				}		
				counter++; 
			}
			//cout << "Index " << i << " was not found." << endl;
			return NULL; 	//if list is empty
		}

		int size()			//return size of container
		{ return a.size(); }
};

#endif
