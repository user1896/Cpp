/*
    L2 série4 Ex1 (ASD)
*/
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
};

struct Circle
{
    int data;
    Circle *next;
};

int main ()
{
    void add_node( Node *&tree , int new_data );
    void display_tree( Node *tree );
    void add_circle_start( Circle *&circle_start , int new_data );
    void add_circle_end( Circle *&circle_start , int new_data );
    void display_circle( Circle *circle_start );
    void transform_tree_to_circle( Node *tree , Circle *&circle_start );
    
    Node *tree = NULL;
    
    add_node( tree , 11 );
    add_node( tree , 5 );
    add_node( tree , 2 );
    add_node( tree , 13 );
    add_node( tree , 10 );
    
    cout<<"Tree"<<endl;
    display_tree( tree );
    cout<<endl;
    
    //////////////////////////////////////////////////////////////////////////
    // Circle
    //////////////////////////////////////////////////////////////////////////
    
    Circle *circle_start = NULL;
    
    transform_tree_to_circle( tree , circle_start );
    
    cout<<endl<<"Circle"<<endl;
    display_circle( circle_start );
    
    return 0;
}

void transform_tree_to_circle( Node *tree , Circle *&circle_start )
{
    void add_circle_end( Circle *&circle_start , int new_data );
    
    if( tree )
    {
        transform_tree_to_circle( tree->left , circle_start );
        add_circle_end( circle_start , tree->data );
        transform_tree_to_circle( tree->right , circle_start );
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
            add_node( tree->left , new_data );
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

void add_circle_start( Circle *&circle_start , int new_data )
{
    Circle *new_element = new Circle;
    new_element->data = new_data;
    
    if( !circle_start )
    {
        new_element->next = new_element;
        circle_start = new_element;
    }
    else
    {
        Circle *current = circle_start;
        new_element->next = circle_start;
        
        while( current->next != circle_start )
        {
            current = current->next;
        }
        current->next = new_element;
        circle_start = new_element;
    }
}

void add_circle_end( Circle *&circle_start , int new_data )
{
    Circle *new_element = new Circle;
    new_element->data = new_data;
    
    if( !circle_start )
    {
        new_element->next = new_element;
        circle_start = new_element;
    }
    else
    {
        new_element->next = circle_start;
        
        Circle *current = circle_start;
        
        while( current->next != circle_start )
        {
            current = current->next;
        }
        current->next = new_element;
    }
}

void display_circle( Circle *circle_start )
{
    if( !circle_start )
    {
        cout<<endl<<"Circle is empty!"<<endl;
    }
    else
    {
        cout<<endl<<circle_start->data<<"\t";
        Circle *current = circle_start->next;
        
        while( current != circle_start )
        {
            cout<<current->data<<"\t";
            current = current->next;
        }
        cout<<endl;
    }
}


