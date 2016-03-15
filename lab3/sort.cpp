//#include "sort.h"
#include "base.h"
#import "sort.h"
#import "container.h"
#include <iterator>
#include <iostream>
using namespace std;

//class Container;

selectionSort::selectionSort(){}

//Selection Sort for Descending Order
void selectionSort::sort(Container* container)
{
	
	int first;
	//Base* temp;
	int numLength = container->size();

	for(unsigned int i = numLength - 1; i > 0; i--)
	{
		first = 0;	//initialize to nothing
		for(unsigned int j = 1; j <= i; j++)
		{
			if(container->at(j)->evaluate() < container->at(first)->evaluate())
			{
				first = j;	//initialize j as minimum value
			}

		}
		//cout << container->at(first)->evaluate() << endl;
		//cout << container->at(i)->evaluate() << endl;
		//cout << "before swap" << endl;
		//container->print();
		container->swap(first,i);		//swap values in container
		//cout << "after swap" << endl;
		//container->print();
	} 
		
}

bubbleSort::bubbleSort(){}

//Bubble sort for Ascending Order
void  bubbleSort::sort(Container* container)
{
	bool flag = true;	//for checking
	int numLength = container->size();	//size of container

	for(unsigned int i = 1; i <= numLength && flag; i++)
	{
		flag = false;	
		for(unsigned int j = 0; j < numLength-1; j++)
		{
			if(container->at(j + 1)->evaluate() < container->at(j)->evaluate())		//if next value is smaller than current then swap
			{
				container->swap(j + 1, j);
				flag = true;	//to show that a swap occured
			}
		}
	}

}