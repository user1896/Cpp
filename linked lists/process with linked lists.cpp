#include <iostream>

using namespace std;

struct Processor
{
    int id;
    int priority;
    Processor *next;
};

int main()
{
    void add_processor( Processor *&, int id , int priority );
    void display_linked_processors( Processor *);
    void invert_list( Processor *& );
    void delete_processor( Processor *&, int priority_val );
    
    Processor **array;
    int M = 3;
    int N = 3;
    
    array = new Processor*[M];
    
    for( int i = 0 , counter = 1  ; i < M ; i++ )
    {
        array[i] = NULL;
        for( int j = 0 ; j < N ; j++ , counter++ )
        {
            add_processor( array[i] , counter , counter );
        }
    }
    
    cout<<endl<<"Display array of the lists of processors"<<endl;
    
    for( int i = 0 ; i < M ; i++ )
    {
        display_linked_processors( array[i] );
    }
    
    cout<<endl<<"Inverting the lists :"<<endl;
    for( int i = 0 ; i < M ; i++ )
    {
        invert_list( array[i] );
        display_linked_processors( array[i] );
    }
    
    delete_processor( array[1] , 5 );
    
    cout<<endl<<"Displaying the array after deleting the Processor of priority '5' from list 2"<<endl;
    for( int i = 0 ; i < M ; i++ )
    {
        display_linked_processors( array[i] );
    }
    
    return 0;
}

void add_processor( Processor *&L , int id , int priority )
{
    Processor *new_proc = new Processor;
    new_proc->id = id;
    new_proc->priority = priority;
    new_proc->next = NULL;
    
    if( !L )
    {
        L = new_proc;
    }
    else
    {
        Processor *current = L;
        while ( current->next != NULL )
        {
            current = current->next;
        }
        current->next = new_proc;
    }
}

void display_linked_processors( Processor *L )
{
    if( !L )
    {
        cout<<endl<<"List is empty"<<endl;
    }
    else
    {
        Processor *current = L;
        cout<<endl;
        while( current != NULL )
        {
            cout<<current->id<<"\t";
            current = current->next;
        }
        cout<<endl;
    }
}

void invert_list( Processor *&L )
{
    if( !L )
    {
        cout<<endl<<"can't invert an empty list"<<endl;
    }
    else
    {
        Processor *current = L->next;
        L->next = NULL;
        while( current != NULL )
        {
            Processor *save = current->next;
            current->next = L;
            L = current;
            current = save;
        }
    }
}

void delete_processor( Processor *&L , int priority_val )
{
    if( !L )
    {
        cout<<endl<<"can't delete from an empty list"<<endl;
    }
    else
    {
        if( L->priority == priority_val )
        {
            Processor *save_to_delete = L;
            L = L->next;
            delete save_to_delete;
        }
        else
        {
            Processor *current = L;
            while( current->next != NULL )
            {
                if( current->next->priority == priority_val )
                {
                    Processor *save_to_delete = current->next;
                    current->next = current->next->next;
                    delete save_to_delete;
                    break;
                }
                else
                {
                    current = current->next;
                }
            }
        }
    }
}
