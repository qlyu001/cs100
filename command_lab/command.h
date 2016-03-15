#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command 
{
    
public:
	OpCommand(){};			//default constructor

	OpCommand(int op)
	{
     	this->root = new Op(op);
	}
};

class AddCommand : public Command 
{
public:
	AddCommand(){};			//default constructor

	AddCommand(Command* curr, int val)
	{
        Base* temp = new Op(val);
		this->root = new Add(curr->get_root(),temp);
        //cout << "I am in AddCommand" << endl;
	}
};

class SubCommand : public Command 
{
public:
	SubCommand(){};			//default constructor

	SubCommand(Command* curr, int val)
	{
         Base* temp = new Op(val);
		this->root = new Sub(curr->get_root(), temp);
	}
};

class MultCommand : public Command 
{
public:
	MultCommand(){};		//default constructor

	MultCommand(Command* curr, int val)
	{
        Base* temp = new Op(val);
		this->root = new Mult(curr->get_root(),temp);
	}
};

class SqrCommand : public Command 
{
public:
	SqrCommand(){};			//default constructor

	SqrCommand(Command* curr)
	{
    
		this->root = new Sqr(curr->get_root());
	}
};
#endif //__COMMAND_CLASS__
