#ifndef __VISITOR_CLASS__
#define __VISITOR_CLASS__
#include<iostream>
//#include "composite.h"
using namespace std;
class Base;
class Op;
class addNode;
class rootNode;

class Visitor
{
public:
    virtual void rootNode() = 0;
    virtual void sqrNode() = 0;
    virtual void multNode() = 0;
    virtual void subNode() = 0;
    virtual void addNode() = 0;
    virtual void opNode(Op* op) = 0;
    virtual void execute() = 0;
};
class PrintVisitor : public Visitor
{
private:
    string output;
    
public:
    
    PrintVisitor();
    //doing nothing
    void rootNode()
    {
        output += " aaaaaa ";
        return;
    }
    //visiting a square node
    void sqrNode();
    
    void multNode();
    void subNode();
    void addNode();
    void opNode(Op* op);
    
    void execute();
};

#endif