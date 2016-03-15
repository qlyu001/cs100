#ifndef BASE_H
#define BASE_H

#include <cmath>
#include <iostream>
using namespace std;

class Base
{
	public:
		Base() {}; //constructor
		virtual double evaluate() = 0; //pure virtual function, to return value of tree
};

//leaf: represents a number
class Op: public Base
{
	private:
		double a;

	public:
		Op(double i)
		{ a = i; }
	
		double evaluate()
		{ return a; }
};

class Mult: public Base
{
	private:
		Base* base1;
		Base* base2;	
	
	public:
		Mult(Base* a, Base* b):base1(a), base2(b){}		

		double evaluate()
		{ return base1->evaluate() * base2->evaluate(); }
};

class Div: public Base
{
	private:
		Base* base1; 
		Base* base2;	

	public:
		Div(Base* a, Base* b):base1(a), base2(b){}		

		double evaluate()
		{ return base1->evaluate() / base2->evaluate(); }
};

class Add: public Base
{
	private:	
		Base* base1; 
		Base* base2;	

	public:
		Add(Base* a, Base* b):base1(a), base2(b){}

		double evaluate()
		{ return base1->evaluate() + base2->evaluate(); }
};

class Sub: public Base
{
	private:
		Base* base1; 
		Base* base2;	
	
	public:
		Sub(Base* a, Base* b):base1(a), base2(b){}

		double evaluate()
		{ return base1->evaluate() - base2->evaluate(); }
};

class Sqr: public Base
{
	private:
		Base* base1;
	
	public:
		Sqr(Base* a):base1(a){}

		double evaluate()
		{ return base1->evaluate() * base1->evaluate(); }
};

#endif
