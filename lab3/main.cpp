#include "container.h"
#include "sort.h"
#include "base.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	cout << "/* --------------- */" << endl;
	cout << "/* Generating Tree */" << endl;
	cout << "/* --------------- */" << endl;

	//3 + 7 * 4 - 2
	Op A = Op(3);
	Op B = Op(7);
	Op C = Op(4);
	Op D = Op(2);
	Base* a = &A;
	Base* b = &B;
	Base* c = &C;
	Base* d = &D;
	Mult B_C = Mult(b,c);	//7 * 4
	Base* b_c = &B_C;
	Add B_C_A = Add(b_c, a);	//28 + 3
	Base* b_c_a = &B_C_A;
	Sub T1 = Sub(b_c_a, d);	//31 - 2
	Base* t1 = &T1;
	cout << "T1: " << t1->evaluate() << ", ";

	//5 - 8 + 6 / 3
	Op A2 = Op(6);
	Op B2 = Op(3);
	Op C2 = Op(8);
	Op D2 = Op(5);
	Base* a2 = &A2;
	Base* b2 = &B2;
	Base* c2 = &C2;
	Base* d2 = &D2;
	Div A2_B2 = Div(a2,b2);	//6 / 3
	Base* a2_b2 = &A2_B2;
	Sub D2_C2 = Sub(d2, c2);	//5 - 8
	Base* d2_c2 = &D2_C2;
	Add T2 = Add(d2_c2, a2_b2);	//-3 + 2
	Base* t2 = &T2;
	cout << "T2: " << t2->evaluate() << ", ";
	
	//30 - 6 * 2 - 8 
	Op A3 = Op(30);
	Op B3 = Op(6);
	Op C3 = Op(2);
	Op D3 = Op(8);
	Base* a3 = &A3;
	Base* b3 = &B3;
	Base* c3 = &C3;
	Base* d3 = &D3;
	Mult B3_C3 = Mult(b3,c3);	//6 * 2
	Base* b3_c3 = &B3_C3;
	Sub A3_B3_C3 = Sub(a3,b3_c3);	//30 - 12 
	Base* a3_b3_c3 = &A3_B3_C3;
	Sub T3 = Sub(a3_b3_c3, d3);	//18 - 8
	Base* t3 = &T3;
	cout << "T3: " << t3->evaluate() << ", ";

	//7 - 8 + 27 / 9
	Op A4 = Op(27);
	Op B4 = Op(9);
	Op C4 = Op(8);
	Op D4 = Op(7);
	Base* a4 = &A4;
	Base* b4 = &B4;
	Base* c4 = &C4;
	Base* d4 = &D4;
	Div A4_B4 = Div(a4,b4);	//27 / 9
	Base* a4_b4 = &A4_B4;
	Sub D4_C4 = Sub(d4, c4);	//7 - 8
	Base* d4_c4 = &D4_C4;
	Add T4 = Add(d4_c4, a4_b4);	//-1 + 3
	Base* t4 = &T4;
	cout << "T4: " << t4->evaluate() << endl;

	cout << "/* ------------------------------------- */" << endl;
	cout << "/* Generating Vector Containers and Sort */" << endl;
	cout << "/* ------------------------------------- */" << endl;

	//initializing objects
	selectionSort ss;			//selection sort object
	Sort* s = &ss;				
	bubbleSort bb;				//bubble sort object
	Sort* bubble = &bb;

	cout << "Vector container values:" << endl;
	//Container* cont;
	ContainerVector t1_vec(s);		//putting selection sort object in containerVector initialization for sorting purposes
	t1_vec.add_element(t1); 		//adding Base* elements in vector 
	t1_vec.add_element(t2); 
	t1_vec.add_element(t3); 
	t1_vec.add_element(t4); 
	//t1_vec.print(); 
	Container* t1_vec_p = &t1_vec; 	//container* to get vector object
	t1_vec_p->print();				//print container

	cout << "Selection sorted container values:" << endl;
	t1_vec_p->sort();			//sort container vector in desending order for proper functionality
	t1_vec_p->print();			//print sorted container

	//selectionSort ss;
	//Sort* selection_sort = &ss;
	//ContainerVector t1_vec_select(selection_sort);	

	//reset container vector for bubble sort
	ContainerVector t1_vec2(bubble);		//putting bubble sort object in containerVector initialization for sorting purposes
	t1_vec2.add_element(t1); 				//adding Base* elements in
	t1_vec2.add_element(t2); 
	t1_vec2.add_element(t3); 
	t1_vec2.add_element(t4); 
	//t1_vec.print(); 
	//cout << "Vector container values:" << endl;
	Container* t1_vec_p2 = &t1_vec2; 		//container* to get vector object
	//t1_vec_p2->print();					//print container

	cout << "Bubble sorted container values:" << endl;
	t1_vec_p2->sort();			//sort container vector in ascending order for proper functionality
	t1_vec_p2->print();			//print sorted container

	cout << "/* ----------------------------------- */" << endl;
	cout <<	"/* Generating List Containers and Sort */" << endl;
	cout << "/* ----------------------------------- */" << endl;

	cout << "List container values: " << endl;
	ContainerList t2_list(s);		//creating a container list of Base* with selection sort object
	t2_list.add_element(t1);		//adding Base* elements in
	t2_list.add_element(t2);
	t2_list.add_element(t3);
	t2_list.add_element(t4);
	//t2_list.print();
	Container* t2_list_p = &t2_list;	//container* to get list object
	t2_list_p->print();					//print container
	
	/*cout << "Swaped index 0 and 1" << endl;
	t2_list_p->swap(0,1);
	t2_list_p->print();		//print container */
	
	cout << "Selection sorted list values:" << endl;
	t2_list_p->sort();			//sort container list in descending order
	t2_list_p->print();			//print sorted list

	//resetting container list for bubble sort
	cout << "List container values: " << endl;
	ContainerList t2_list2(bubble);		//creating a container list of Base* with bubble sort object
	t2_list2.add_element(t1);			//adding Base* elements in
	t2_list2.add_element(t2);
	t2_list2.add_element(t3);
	t2_list2.add_element(t4);
	//t2_list.print();
	Container* t2_list_p2 = &t2_list2;	//container* to get list object
	//t2_list_p2->print();				//print container

	cout << "Bubble sorted list values:" << endl;
	t2_list_p2->sort();					//sort container vector in ascending order
	t2_list_p2->print();				//print container
	
	return 0;
}
