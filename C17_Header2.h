#ifndef C17_HEADER2_H
#define C17_HEADER2_H

//
struct node
{
    int info;
    struct node *next;

};

class linkedListStack
{
    struct node *top;

private:
    //Private member variable userNum is used to hold user input in a protected state
    int userNum;

public:
    //Setter and getter functions used to receive input from the user
    void setUserNum(int identifier);
    int getUserNum() const;
    //The menuSelection function allows the user to select options to manipulate the stacks
    void menuSelection(int identifier, linkedListStack &stack);

    //Member functions manipulate the linked list stacks
    void push(int identifier);
    void pop(int identifier);

    //Display function displays the selected list for the user to see
    void display(int identifier);

    //Overload the relational operator ==
    bool operator==(const linkedListStack&) const;

    //Constructor
    linkedListStack();
    //Destructor
    ~linkedListStack();
};

#endif
