/*
    L2 série3 Ex4 (ASD)
*/
#include <iostream>

using namespace std;

struct Queue
{
    int key;
    Queue *next;
};

int main ()
{
    void devide_to_even_and_odd( Queue *&my_queue , Queue *&odd_queue , Queue *&even_queue );
    void enqueue( Queue *&my_queue , int new_key );
    void display( Queue *&my_queue );
    
    Queue *my_queue = NULL;
    Queue *odd_queue = NULL;
    Queue *even_queue = NULL;
    
    enqueue( my_queue , 11 );
    enqueue( my_queue , 12 );
    enqueue( my_queue , 13 );
    enqueue( my_queue , 14 );
    enqueue( my_queue , 15 );
    enqueue( my_queue , 16 );
    enqueue( my_queue , 17 );
    enqueue( my_queue , 18 );
    
    display( my_queue );
    
    devide_to_even_and_odd( my_queue , odd_queue , even_queue );
    
    cout<<endl<<"Divide Queue by 2 :"<<endl;
    
    cout<<endl<<"Queue with ODD keys :";
    display( odd_queue );
    
    cout<<endl<<"Queue with EVEN keys :";
    display( even_queue );
    
    cout<<endl<<"Original queue after division :";
    display( my_queue );
    
    return 0;
}

void devide_to_even_and_odd( Queue *&my_queue , Queue *&odd_queue , Queue *&even_queue )
{
    void enqueue( Queue *&my_queue , int new_key );
    int dequeue( Queue *&my_queue );
    
    if( !my_queue )
    {
        cout<<endl<<"Queue is empty!"<<endl;
    }
    else
    {
        while( my_queue )
        {
            if( (my_queue->key % 2) == 0 )
            {
                enqueue( even_queue , dequeue( my_queue ) );
            }
            else
            {
                enqueue( odd_queue , dequeue( my_queue ) );
            }
        }
    }
}

void display( Queue *&my_queue )
{
    void enqueue( Queue *&my_queue , int new_key );
    int dequeue( Queue *&my_queue );
    
    if( !my_queue )
    {
        cout<<endl<<"Queue is empty!"<<endl;
    }
    else
    {
        Queue *tmp_queue = NULL;
        Queue *tmp_queue_2 = NULL;
        int saved_key;
        
        cout<<endl;
        while( my_queue )
        {
            saved_key = dequeue( my_queue );
            cout<<saved_key<<"\t";
            enqueue( tmp_queue , saved_key );
        }
        cout<<endl;
        
        while( tmp_queue )
        {
            enqueue( my_queue , dequeue( tmp_queue ) );
        }
    }
}

void enqueue( Queue *&my_queue , int new_key )
{
    Queue *new_element = new Queue;
    new_element->key = new_key;
    new_element->next = NULL;
    
    if( !my_queue )
    {
        my_queue = new_element;
    }
    else
    {
        Queue *current = my_queue;
        while( current->next )
        {
            current = current->next;
        }
        current->next = new_element;
    }
/*
	YOU CAN ALSO DO (instead of all of the above) :

    if( !my_queue )
    {
        my_queue = new Queue;
        my_queue->key = new_key;
        my_queue->next = NULL;
    }
    else
    {
        enqueue( my_queue->next , new_key );
    }
*/

}

int dequeue( Queue *&my_queue )
{
    if( !my_queue )
    {
        return 0;
    }
    else
    {
        Queue *tmp_for_delete = my_queue;
        int saved_key = my_queue->key;
        
        my_queue = my_queue->next;
        delete tmp_for_delete;
        tmp_for_delete = NULL;
        
        return saved_key;
    }
}
