#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include <vector>
#include "command.h"

using namespace std;

class Menu {
	private:
		int history_index;				//keep track of position in history
		vector<Command*> history;		//holds all commands that have been run

	public:
		//Base constructor to set up all necessary members
		Menu() : history_index(-1){};

		void execute() 
		{
			//Prints the current commands value (based on history_index), if no commands exist
			//print 0 by default
			if(history_index < 0)
			{ cout << 0 << endl; }

			cout << history.at(history_index)->execute() << endl;
		};
		
		bool initialized() {
			//Return true if the history has been primed with a single op instruciton
			//This is necessary because that is the base of a calculation
			if(history_index >= 0)
			{
//                if(typeid(history.at(0)) == typeid(Op))
//                {
//                    return true;
//                }
//                else
//                {
//                    return false;
//                }
                return true;
            }
            return false;
        };
		void add_command(Command* cmd)
		{
			//Adds a command to history in the appropriate posiiton (based on history_index)
            if(history_index - 1 != history.size())
            {
                for(int i = history.size(); i > history_index + 1; --i)
                {
                    history.pop_back();
                }
            }
            
            history.push_back(cmd);
            
            history_index++;
		};
		Command* get_command() 
		{
			//Returns the command in history we are currently referring to (based on history_index)
            //cout << "I am in get_command()" << endl;
			return history.at(history_index);
		};
		void undo() 
		{
			//Moves to the last command in history (if possible)
			if(history_index > 0)
			{
                history_index--;
				//cout << history.at(history_index) << endl;
			}
			else
			{
				cout << "Error: no more undos available" << endl;
			}
		};
		void redo() 
		{
			//Moves to the next command in history (if possible)
			if(history_index < history.size() - 1)
			{
				history_index++;
				//cout << history.at(history_index) << endl;
			}
			else
			{
				cout << "Error: no more redos available" << endl;
			}
		};
};

#endif //__MENU_CLASS__
