#include<iostream>

using namespace std;

class node
{
    public:

    int data;
    node * left;
    node * right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class binaryTree
{  
    
    public:
    
    node * root;

    binaryTree()
    {
        root = NULL;
    }

    void insertData( int data)
    {
        node * n = new node(data);
        if( root == NULL)
        {
            root = n;
        }
        else
        {
            node * temp = root;
            node * prev = temp;
            while( temp != NULL )
            {
                prev = temp;
                if( data > temp->data)
                {
                    temp = temp->right;
                }
                else
                {
                    temp = temp->left;
                }

            }

            if( data > prev->data)
            {
                prev->right = n;
            }
            else
            {
                prev->left = n;
            }
        }
    }

    node * searchData( int data)
    {
        if ( root == NULL)
        {
            return NULL;
        }
        else
        {
            node * temp = root;
            node * prev;
            while( temp != NULL && data != prev->data )
            {
                prev = temp;
                if( data > temp->data)
                {
                    temp = temp->right;
                }
                else
                {
                    temp = temp->left;
                }
            }

            if( data == prev->data)
            {
                cout<<" found " << endl;
                return prev;
            }
            else
            {
                cout<<" not found";
                return NULL;
            }
        }
    }
    
    void preOrder(node * value)
    {
        cout << "Preorder is : ";
        if( value != NULL)
        {
            cout << value->data << endl;
            preOrder(value->left);
            preOrder(value->right);
        }
    }

    void postOrder( node * value)
    {
        cout<< " post order is : ";
        if( value != NULL)
        {
            postOrder( value->left );
            postOrder( value->right );
            cout << value->data << endl;
        }
    }
    
    
    void printTree(node * value)
    {
        if(value != NULL)
        {
            printTree(value->left);
            cout<<value->data<<endl;
            printTree(value->right);
        }
    }
};


int main()
{
    binaryTree * bst = new binaryTree();
    bst->insertData(32);
    bst->insertData(34);
    bst->insertData(31);
    bst->insertData(33);
    bst->insertData(38);
    bst->insertData(30);
    bst->printTree(bst->root);
    node * searchAddress = bst->searchData(39);
}
