#include<iostream>

using namespace std;

class node
{       
    public:

        int data;
        node * next;

        node( int data)
        {
            this->data = data;
            this->next = NULL;
        }
};


class mainList
{
    public:
    
    node * head;
    mainList()
    {
        head = NULL;
    }

    void insert( int data)
    {
        node * temp;
        temp = head;
        node * n = new node(data);
        if( head == NULL)
        {
            head = n;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }

    void print()
    {
        if(head == NULL)
        {
            cout<<"list is empty";
            return;
        }
        else
        {
            node * temp = head;
            while(temp != NULL)
            {
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
    }

    void delete_ll(int del_data)
    {
        node * temp = head;
        node * temp1 = temp->next;
        if( head == NULL)
        {
            cout<<"no item in the list";
            return;
        }
        else if( head->data == del_data)
        {
            head = head->next;
            temp = head;
            return;
        }
        else
        {
            while( temp1 != NULL)
            {
                if(temp1->data == del_data)
                {
                    temp->next = temp1->next;
                    temp1->next = NULL;
                    return;
                }
        
                else
                {
                    temp = temp->next;
                    temp1 = temp->next;
                }
            }

            cout<<"element not found "<<endl;
        }
    }
};

int main()
{
    mainList* ll = new mainList();
    ll->insert(16);
    ll->insert(20);
    ll->insert(24);
    ll->insert(34);
    ll->print();
    ll->delete_ll(16);
    ll->print();
    ll->delete_ll(34);
    ll->print();
    ll->delete_ll(14);
    ll->print();
}
