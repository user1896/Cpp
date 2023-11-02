/*
    L2 série4 Ex 6 + 7 (ASD)
*/
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
};

int main ()
{
    void add_node( Node *&tree , int new_data );
    void display_tree( Node *tree );
    int tree_depth( Node *tree );
    bool is_left_null( Node *tree );
    
    Node *tree_1 = NULL;
    //Node *tree_2 = NULL;
    
    add_node( tree_1 , 11 );
    /*add_node( tree_1 , 5 );
    add_node( tree_1 , 2 );*/
    add_node( tree_1 , 13 );
    /*add_node( tree_1 , 10 );
    add_node( tree_1 , -15 );
    add_node( tree_1 , 4 );
    add_node( tree_1 , -9 );*/
    
    cout<<endl<<"Tree 1 :"<<endl<<endl;
    display_tree( tree_1 );
    cout<<endl;
    
    cout<<endl<<"The depth of the tree is : "<<tree_depth( tree_1 )<<endl;
    
    if( is_left_null( tree_1 ) == true )
    {
        cout<<endl<<"Every left node in our tree is NULL."<<endl;
    }
    else
    {
        cout<<endl<<"Left nodes exists!"<<endl;
    }
    
    return 0;
}

bool is_left_null( Node *tree )
{
    if( !tree )
    {
        return true;
    }
    else
    {
        if( tree->left )
        {
            return false;
        }
        else
        {
            return true && is_left_null( tree->right );
        }
    }
}

int tree_depth( Node *tree )
{
    if( tree )
    {
        if( !tree->left  && !tree->right )
        {
            return 1;
        }
        else
        {
            int left_child = 1 + tree_depth( tree->left );
            int right_child = 1 + tree_depth( tree->right );
            
            return left_child > right_child ? left_child : right_child;
        }
    }
    else
    {
        return 0;
    }
}

void add_node( Node *&tree , int new_data )
{
    if( !tree )
    {
        tree = new Node;
        tree->data = new_data;
        tree->right = NULL;
        tree->left = NULL;
    }
    else
    {
        if( tree->data < new_data )
        {
            add_node( tree->right , new_data );
        }
        else
        {
            if( tree->data > new_data )
            {
                add_node( tree->left , new_data );
            }
        }
    }
}

void display_tree( Node *tree )
{
    if( tree )
    {
        display_tree( tree->left );
        cout<<tree->data<<"\t";
        display_tree( tree->right );
    }
}

