/*
Programmer: Ray, Stephen

Course: CSC161

Submission Date: [11/09/2021]

Function definitions used in the C17_Main program.

*/

#include <iostream>

// Include header file C17_Header.h

#include "C17_Header2.h"

using namespace std;

int main()
{
    //Instantiate two objects of the linkedListStack type called stack1 and stack2
    linkedListStack stack1;
    linkedListStack stack2;

    //Call the menuSelection function for stack1 and stack2 objects
    stack1.menuSelection(1, stack1);
    stack2.menuSelection(2, stack2);

    //Use the overloaded relational operator == to compare stack1 and stack2
    if(stack1 == stack2)
    {
        cout << "\n\nThe stacks are equal.";
    }

    else
        cout << "\n\nThe stacks are not equal.";

    return 0;
}



