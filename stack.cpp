#include<iostream>

using namespace std;

class node
{       

    public:

        int data;
        node * next;

        node(int data)
        {
            this->data = data;
            next = NULL;
        }
};

class stackll
{
    node * top;
    
    public:
    stackll () 
    {
        top = NULL;
    }

    void push(int data)
    {
        node *n = new node(data);
        n->next = top;
        top = n;
    }

    void print()
    {
        node * temp = top;
        while(temp != NULL)
        {
            cout<<temp->data<<endl;
            temp =  temp-> next;
        }
    }
    
    void pop()
    {
        node * temp = top;
        top = top->next;
        delete(temp);
    }

    int topStack()
    {
        return top->data;
    }
};

int main()
{
    stackll *s = new stackll();
    s->push(16);
    s->push(20);
    s->push(35);
    s->print();
    s->push(40);
    s->print();
    s->pop();
    s->print();
    s->pop();
    s->print();
    cout<<" top is :" << s->topStack();
}
