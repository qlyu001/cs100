#include "visitor.h"
#include "composite.h"
#include <string>

PrintVisitor::PrintVisitor(){}
//doing nothing
//void PrintVisitor::rootNode()
//{
//    return;
//}
//visiting a square node
void PrintVisitor::sqrNode()
{
    output += " ^ ";
}

void PrintVisitor::multNode()
{
    output += " * ";
}
void PrintVisitor::subNode()
{
    output += " - ";
}
void PrintVisitor::addNode()
{
    output += " + ";
}
void PrintVisitor::opNode(Op* op)
{
    double b = op->evaluate();
    output += " ";
    output += to_string(b);
    output += " ";
}

void PrintVisitor::execute()
{
    cout << output << endl;
}