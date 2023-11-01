#include <iostream>

using namespace std;

struct Element
{
    int key;
    Element *next;
};

int main()
{
    void conjuncting_two_lists( Element *list_1 , Element *list_2 , Element *&list_3 );
    void add_element( Element *&list , int new_key );
    void display_list( Element *list );
    void sort_list( Element *&list );
    
    Element *list_1 = NULL;
    Element *list_2 = NULL;
    Element *list_3 = NULL;
    
    add_element( list_1 , 22 );
    add_element( list_1 , 11 );
    add_element( list_1 , 14 );
    add_element( list_1 , 13 );
    
    cout<<endl<<"List 1 :"<<endl;
    display_list(list_1);
    
    add_element( list_2 , 27 );
    add_element( list_2 , 25 );
    add_element( list_2 , 11 );
    add_element( list_2 , 24 );
    
    cout<<endl<<"List 2 :"<<endl;
    display_list(list_2);
    
    sort_list( list_1 );
    cout<<endl<<"Sorting List 1 :"<<endl;
    display_list(list_1);
    
    sort_list( list_2 );
    cout<<endl<<"Sorting List 2 :"<<endl;
    display_list(list_2);
    
    cout<<endl<<"conjuncting list 1 and list 2 into list 3 :"<<endl;
    conjuncting_two_lists( list_1 , list_2 , list_3 );
    display_list(list_3);

    return 0;
}

void conjuncting_two_lists( Element *list_1 , Element *list_2 , Element *&list_3 )
{
    void add_element( Element *&list , int new_key );
    while( list_1 && list_2 )
    {
        if( list_1->key < list_2->key )
        {
            add_element( list_3 , list_1->key );
            list_1 = list_1->next;
        }
        else
        {
            if( list_2->key < list_1->key )
            {
                add_element( list_3 , list_2->key );
                list_2 = list_2->next;
            }
            else
            {
                add_element( list_3 , list_1->key );
                list_1 = list_1->next;
                list_2 = list_2->next;
            }
        }
    }
    while( list_1 )
    {
        add_element( list_3 , list_1->key );
        list_1 = list_1->next;
    }
    while( list_2 )
    {
        add_element( list_3 , list_2->key );
        list_2 = list_2->next;
    }
}

void add_element( Element *&list , int new_key )
{
    Element *new_element = new Element;
    new_element->key = new_key;
    new_element->next = NULL;
    
    if( !list )
    {
        list = new_element;
    }
    else
    {
        Element *current = list;
        while( current->next != NULL )
        {
            current = current->next;
        }
        current->next = new_element;
    }
}

void display_list( Element *list )
{
    if( !list )
    {
        cout<<endl<<"List is empty"<<endl;
    }
    else
    {
        Element *current = list;
        cout<<endl;
        while( current != NULL )
        {
            cout<<current->key<<"\t";
            current = current->next;
        }
        cout<<endl;
    }
}

void sort_list( Element *&list )
{
    Element *pre_min_list( Element *list );
    if( !list )
    {
        cout<<endl<<"can't sort an empty list"<<endl;
    }
    else
    {
        if( list->next != NULL )
        {
            Element *pre_min = pre_min_list( list );
            if( pre_min->next->key < list->key )
            {
                Element *save = list;
                list = pre_min->next;
                pre_min->next = pre_min->next->next;
                list->next = save;
            }
            // At this point "list" is pointing at the minimum Element.
            
            Element *anchor = list;
            while( anchor->next->next != NULL )
            {
                pre_min = pre_min_list( anchor->next );
                if( pre_min->next->key < anchor->next->key )
                {
                    Element *save = anchor->next;
                    anchor->next = pre_min->next;
                    pre_min->next = pre_min->next->next;
                    anchor->next->next = save;
                }
                anchor = anchor->next;
            }
        }
    }
}

Element *pre_min_list( Element *list )
{
    if( !list )
    {
        return NULL;
    }
    else
    {
        if( !list->next )
        {
            return NULL;
        }
        else
        {
            Element *pre_min = list;
            Element *current = list->next;
            
            while( current->next != NULL )
            {
                if( current->next->key < pre_min->next->key )
                {
                    pre_min = current;
                }
                current = current->next;
            }
            return pre_min;
        }
    }
}

