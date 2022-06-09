/*
Programmer: Ray, Stephen

Course: CSC161

Submission Date: [11/09/2021]

Function definitions used in the C17_Main program.

*/

#include "C17_Header2.h"
#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

//The menuSelection function accepts an int and stack as parameters and allows the user to make a selection
void linkedListStack::menuSelection(int identifier, linkedListStack &stack)
{
    //If the identifier variable is 1 display the initial welcome message to the user
    if (identifier == 1)
    {
        cout << "This program allows the user to create and edit two stacks using linked lists.\n";
        cout << "The program will then compare the two stacks to determine if they are equal.\n\n";
    }

    //Declare and initialize the userChoice variable
    int userChoice = 0;

    //Use the userChoice variable to allow the user to manipulate the current stack as much as they want
    while (userChoice != 4)
    {
        cout << "Make a selection to edit or display stack " << identifier << ":" << endl;
        cout << "Enter 1 to push a number into stack " << identifier << ":" << endl;
        cout << "Enter 2 to pop a number off of stack " << identifier << ":" << endl;
        cout << "Enter 3 to display stack " << identifier << ":" << endl;
        cout << "Enter 4 to complete stack " << identifier << ":" << endl;

        cin >> userChoice;

        //Using the received userChoice value, determine what action should be taken for the current stack

        if (userChoice == 1)
        {
            stack.push(identifier);
        }

        if (userChoice == 2)
        {
            stack.pop(identifier);
        }

        if (userChoice == 3)
        {
            stack.display(identifier);
        }
    }

}

//The setUserNum() function receives input from the user and assigns this value to the private variable userNum
void linkedListStack::setUserNum(int identifier)
{
    //Declare and initialize local variable num of int data type
    int num = 0;

    cout << "\nEnter an integer to add to stack " << identifier << ":\n";
    cin >> num;

    //Input validation ensures that the user will enter an integer
    while(cin.fail())
    {
        //Clear cin stream
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        cout << "Enter an integer to enter into stack " << identifier << ":\n" << endl;
        cin >> num;
    }

    //Assign private variable userNum the value in num
    userNum = num;
}

//Getter function getUserNum() returns the userNum private variable
int linkedListStack::getUserNum() const
{
    return userNum;
}

//Constructor
linkedListStack::linkedListStack()
{
    top = NULL;
    userNum = 0;
}

//Destructor
linkedListStack::~linkedListStack()
{
    delete top;
}

//The push function accepts the int identifier variable as a parameter and pushes a new number into the current stack
void linkedListStack::push(int identifier)
{
    struct node *p;

    //Call the setter and getter functions to receive a number from the user
    setUserNum(identifier);
    getUserNum();

    //Create a new node and add the number entered by the user(userNum) as data for the node
    p = new node;
    p-> info = userNum;
    p->next = NULL;

    //If the top of the stack is not null, then the next node becomes the top
    if (top != NULL)
        {
            p->next = top;
        }

    top = p;
}

//The pop() function accepts the int identifier variable as a parameter and pops the top number off of the current stack
void linkedListStack::pop(int identifier)
{
    struct node *temp;

    //If the stack top is empty, then there is no number that can be popped off and a message is displayed
    if (top == NULL)
        {
            cout << "\nThe stack is Empty" << endl;
        }

    else
        {
            //Create a temporary node(temp) to hold the place of top, the next node then becomes the new top and temp is deleted
            temp = top;
            top = top -> next;
            cout << "\nThe value popped is " << temp -> info << endl;
            delete temp;
        }

}

//The display() function accepts the int identifier as a parameter and displays the current stack
void linkedListStack::display(int identifier)
{
    struct node *p = top;

    //Display message if the current stack is empty
    if (top == NULL)
    {
        cout << "\nNothing in stack" << endl;
    }

    //Display the contents of the current stack
    else
    {
        cout << "\nThe contents of stack " << identifier << ":\n";

        //Cycle through the data in the stack and display the elements
        while (p != NULL)
        {
            cout << p-> info << endl;
            p = p -> next;
        }
    }
}

//Overloading the relational operator ==
bool linkedListStack::operator==(const linkedListStack& st1) const
{
    struct node *p = top;
    struct node *q = st1.top;


    //Cycle through the nodes of the two stacks and compare the data, if the data is not equivalent the function returns false
    while(p != nullptr)
    {
        if(p-> info != q-> info)
        {
            return false;
        }

        p = p-> next;
        q = q-> next;
    }

    return true;
}
