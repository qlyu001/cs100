#ifndef SORT_H
#define SORT_H

//#include "container.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
using namespace std;


//class Sort;
class Container;	//forward declaration
///*
class Sort
{
	public:
		Sort(){};	//constructor
		virtual void sort(Container* container) = 0;
};
//*/

//intializes selection sort for container* object
class selectionSort: public Sort
{
	public:
		selectionSort();	//constructor
		void sort(Container* container);
	
};

//initializes bubble sort
class bubbleSort: public Sort
{
	public:
		bubbleSort();	//constructor
		void sort(Container* container);

};

#endif
