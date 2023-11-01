#include <iostream>

using namespace std;

struct Stack
{
    int key;
    Stack *next;
};

int main()
{
    void partition_stack( Stack *&main_stack , int main_stack_size , Stack *&partition_1 , Stack *&partition_2 );
    void read_stack( Stack *stack );
    void push( Stack  *&stack , int value );
    int pop( Stack *&stack );
    
    Stack *main_stack = NULL;
    Stack *partition_1 = NULL;
    Stack *partition_2 = NULL;
    
    push( main_stack , 11 );
    push( main_stack , 12 );
    push( main_stack , 13 );
    push( main_stack , 14 );
    push( main_stack , 15 );
    push( main_stack , 16 );
    
    cout<<endl<<"Main stack :"<<endl;
    read_stack( main_stack );
    
    partition_stack( main_stack , 6 , partition_1 , partition_2 );

    cout<<endl<<"Partition 1 :"<<endl;
    read_stack( partition_1 );
    
    cout<<endl<<"Partition 2 :"<<endl;
    read_stack( partition_2 );
    
    cout<<endl<<"Main stack after partitioning"<<endl;
    read_stack( main_stack );
    
    return 0;
}

void partition_stack( Stack *&main_stack , int main_stack_size , Stack *&partition_1 , Stack *&partition_2 )
{
    void push( Stack  *&stack , int value );
    int pop( Stack *&stack );
    
    for( int i = 0 ; i < main_stack_size / 2 ; i++ )
    {
        push( partition_1 , pop( main_stack ) );
    }
    
    for( int i = 0 ; i < main_stack_size / 2 ; i++ )
    {
        push( partition_2 , pop( main_stack ) );
    }
}

void read_stack( Stack *stack )
{
    void push( Stack  *&stack , int value );
    int pop( Stack *&stack );
    
    if( !stack )
    {
        cout<<endl<<"Stack is empty"<<endl;
    }
    else
    {
        Stack *save_stack = NULL;
        int poped_value;
        cout<<endl;
        while( stack != NULL )
        {
            poped_value = pop( stack );
            cout<<poped_value<<"\t";
            push( save_stack , poped_value );
        }
        cout<<endl;
        while( save_stack != NULL )
        {
            push( stack , pop( save_stack ) );
        }
    }
}

void push( Stack  *&stack , int value )
{
    Stack *new_item = new Stack;
    new_item->key = value;
    new_item->next = stack;
    stack = new_item;
}

int pop( Stack *&stack )
{
    if( !stack )
    {
        return 0;
    }
    else
    {
        Stack *save_to_delete = stack;
        int pop_value = stack->key;
        stack = stack->next;
        delete save_to_delete;
        return pop_value;
    }
}
