#include <iostream>

using namespace std;

struct Element
{
    int key;
    Element *next;
};

struct List
{
    Element *first;
};

int main()
{
    void add_element_to_list( List *& , int );
    void display_list( List * );
    void cocatenate_two_lists( List * , List * , List * );
    
    List *list_1 = new List;
    List *list_2 = new List;
    List *list_3 = new List;
    
    add_element_to_list(list_1,22);
    add_element_to_list(list_1,44);
    add_element_to_list(list_1,66);
    
    add_element_to_list(list_2,33);
    add_element_to_list(list_2,55);
    add_element_to_list(list_2,77);
    
    display_list(list_2);
    
    cocatenate_two_lists( list_1 , list_2 , list_3 );
    
    display_list(list_3);
    
    return 0;
}

void cocatenate_two_lists( List *list_1 , List *list_2 , List *list_3 )
{
    
    if( list_1->first != NULL || list_2->first != NULL )
    {
        Element *current_1 = list_1->first;
        Element *current_2 = list_2->first;
        
        list_3->first = new Element;
        
        if( current_1->key < current_2->key )
        {
            *list_3->first = *current_1;
            list_3->first->next = NULL;
            current_1 = current_1->next;
        }
        else
        {
            *list_3->first = *current_2;
            list_3->first->next = NULL;
            current_2 = current_2->next;
        }
        
        Element *current_3 = list_3->first;
        
        while( current_1 != NULL && current_2 != NULL )
        {
            Element *list_3_element = new Element;
            current_3->next = list_3_element;
            
            if( current_1->key < current_2->key )
            {
                *list_3_element = *current_1;
                list_3_element->next = NULL;
                current_1 = current_1->next;
            }
            else
            {
                *list_3_element = *current_2;
                list_3_element->next = NULL;
                current_2 = current_2->next;
            }
            current_3 = current_3->next;
        }
        if( current_1 != NULL )
        {
            while( current_1 != NULL )
            {
                Element *list_3_element = new Element;
                current_3->next = list_3_element;
                
                *list_3_element = *current_1;
                list_3_element->next = NULL;
                
                current_3 = current_3->next;
                current_1 = current_1->next;
            }
        }
        else
        {
            while( current_2 != NULL )
            {
                Element *list_3_element = new Element;
                current_3->next = list_3_element;
                
                *list_3_element = *current_2;
                list_3_element->next = NULL;
                
                current_3 = current_3->next;
                current_2 = current_2->next;
            }
        }
    }
    else
    {
        cout<<endl<<"Both lists are empty, we can't concatenate them"<<endl;
    }
}

void add_element_to_list( List *&list , int new_key )
{
    Element *new_element = new Element;
    new_element->key = new_key;
    new_element->next = NULL;
    
    if( list->first == NULL )
    {
        list->first = new_element;
    }
    else
    {
        Element *current = list->first;
        while( current->next != NULL )
        {
            current = current->next;
        }
        current->next = new_element;
    }
}

void display_list( List *list )
{
    if( list->first == NULL )
    {
        cout<<endl<<"List is empty"<<endl;
    }
    else
    {
        Element *current = list->first;
        cout<<endl;
        while( current != NULL )
        {
            cout<<"\t"<<current->key;
            current = current->next;
        }
        cout<<endl;
    }
}



