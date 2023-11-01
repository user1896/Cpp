/*
    Sort Stack 2023 (ASD)
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
    void push( Stack *&my_stack , int new_key );
    void display( Stack *&my_stack );
    void sort_stack( Stack *&my_stack );
    
    Stack *my_stack = NULL;
    
    push( my_stack , 21 );
    push( my_stack , 11 );
    push( my_stack , 1 );
    push( my_stack , 22 );
    push( my_stack , 2 );
    
    display( my_stack );
    
    cout<<endl<<"Sort the stack :"<<endl;
    sort_stack( my_stack );
    display( my_stack );
    
    return 0;
}

void sort_stack( Stack *&my_stack )
{
    void push( Stack *&my_stack , int new_key );
    int pop( Stack *&my_stack );
    int pop_min( Stack *&my_stack );
    
    if( !my_stack )
    {
        cout<<endl<<"Stack is empty!"<<endl;
    }
    else
    {
        Stack *sorted_stack = NULL;
        
        while( my_stack )
        {
            push( sorted_stack , pop_min( my_stack ) );
        }
        
        while( sorted_stack )
        {
            push( my_stack , pop( sorted_stack ) );
        }
    }
}

// The plan is to pop the minimum and put it in a stack that will be sorted in the end.
// so at the end our main stack (my_stack) will be empty because we poped every element of it,
// and our new "sorted_stack" will be sorted, so now we just point "my_stack" to "sorted_stack".

int pop_min( Stack *&my_stack )
{
    void push( Stack *&my_stack , int new_key );
    int pop( Stack *&my_stack );
    
    if( !my_stack )
    {
        return 0;
    }
    else
    {
        Stack *tmp_stack = NULL;
        int min = my_stack->key;
        
        while( my_stack )
        {
            if( my_stack->key < min )
            {
                min = my_stack->key;
            }
            push( tmp_stack , pop( my_stack ) );
        }
        
        while( tmp_stack )
        {
            if( tmp_stack->key == min )
            {
                min = pop( tmp_stack );
                break;
            }
            else
            {
                push( my_stack , pop( tmp_stack ) );
            }
        }
        
        while( tmp_stack )
        {
            push( my_stack , pop( tmp_stack ) );
        }
        
        return min;
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

