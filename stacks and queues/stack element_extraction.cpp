/*
    L2 série3 Ex3 (ASD)
*/
#include <iostream>

using namespace std;

struct Stack
{
    int key;
    Stack *next;
};

int main ()
{
    bool push_if_key_unique( Stack *&my_stack , int key_unique );
    int extract_element( Stack *&my_stack , int key_extract );
    void push( Stack *&my_stack , int new_key );
    int pop( Stack *&my_stack );
    void display( Stack *&my_stack );
    
    Stack *my_stack = NULL;
    int key_extract;
    int key_unique;
    
    push( my_stack , 11 );
    push( my_stack , 12 );
    push( my_stack , 13 );
    push( my_stack , 14 );
    push( my_stack , 15 );
    
    display( my_stack );
    
    cout<<endl<<"Enter a number to extract from the stack : ";
    cin>>key_extract;
    
    if( extract_element( my_stack , key_extract ) )
    {
        cout<<endl<<"New Stack after extraction :"<<endl;
        display( my_stack );
    }
    else
    {
        cout<<endl<<"Item not found"<<endl;
    }
    
    cout<<endl<<"Enter a unique key to add to the stack : ";
    cin>>key_unique;
    
    if( push_if_key_unique( my_stack , key_unique ) == true )
    {
        cout<<endl<<"Key added successfully."<<endl;
        display( my_stack );
    }
    else
    {
        cout<<endl<<"Key already exists."<<endl;
    }
    
    return 0;
}

bool push_if_key_unique( Stack *&my_stack , int key_unique )
{
    void push( Stack *&my_stack , int new_key );
    int pop( Stack *&my_stack );
    
    if( !my_stack )
    {
        push( my_stack , key_unique );
        return true;
    }
    else
    {
        Stack *tmp_stack = NULL;
        int saved_key;
        bool is_key_exists = false;
        
        while( my_stack )
        {
            saved_key = pop( my_stack );
            push( tmp_stack , saved_key );
            if( saved_key == key_unique )
            {
                is_key_exists = true;
                break;
            }
        }
        
        while( tmp_stack )
        {
            push( my_stack , pop( tmp_stack ) );
        }
        
        if( is_key_exists == false )
        {
            push( my_stack , key_unique );
            return true;
        }
        else
        {
            return false;
        }
    }
}

int extract_element( Stack *&my_stack , int key_extract )
{
    void push( Stack *&my_stack , int new_key );
    int pop( Stack *&my_stack );
    
    if( !my_stack )
    {
        return 0;
    }
    else
    {
        int saved_key;
        Stack *tmp_stack;
        bool is_key_found = false;
        
        while( my_stack )
        {
            saved_key = pop( my_stack );
            if( saved_key == key_extract )
            {
                is_key_found = true;
                break;
            }
            else
            {
                push( tmp_stack , saved_key );
            }
        }
        while( tmp_stack )
        {
            push( my_stack , pop( tmp_stack ) );
        }
        
        if( is_key_found == true )
        {
            return saved_key;
        }
        else
        {
            return 0;
        }
    }
}

void display( Stack *&my_stack )
{
    void push( Stack *&my_stack , int new_key );
    int pop( Stack *&my_stack );
    
    if( !my_stack )
    {
        cout<<endl<<"Stack is empty"<<endl;
    }
    else
    {
        Stack *tmp_stack = NULL;
        int saved_key;
        
        cout<<endl;
        while( my_stack )
        {
            saved_key = pop( my_stack );
            cout<<saved_key<<"\t";
            push( tmp_stack , saved_key );
        }
        cout<<endl;
        while( tmp_stack )
        {
            push( my_stack , pop( tmp_stack ) );
        }
    }
}

void push( Stack *&my_stack , int new_key )
{
    Stack *new_element = new Stack;
    new_element->key = new_key;
    new_element->next = my_stack;
    my_stack = new_element;
}

int pop( Stack *&my_stack )
{
    if( !my_stack )
    {
        return 0;
    }
    else
    {
        Stack *tmp_for_deleted = my_stack;
        int saved_key = my_stack->key;
        
        my_stack = my_stack->next;
        delete tmp_for_deleted;
        tmp_for_deleted = NULL;
        
        return saved_key;
    }
}
