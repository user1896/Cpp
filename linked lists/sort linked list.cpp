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
    void add_element_to_linked_list( List *&, int );
    void output_linked_list( List *);
    void sort_linked_list( List *);
    
    List *list = NULL;
    
    add_element_to_linked_list( list , 33 );
    add_element_to_linked_list( list , 55 );
    add_element_to_linked_list( list , 44 );
    add_element_to_linked_list( list , 11 );
    add_element_to_linked_list( list , 22 );
    
    output_linked_list( list );
    
    sort_linked_list(list);
    
    output_linked_list( list );

    return 0;
}

void add_element_to_linked_list( List *&list , int x )
{
    Element *new_element = new Element;
    new_element->key = x;
    new_element->next = NULL;
    
    if( !list )
    {
        list = new List;
        list->first = new_element;
    }
    else
    {
        if( !list->first )
        {
            list->first = new_element;
        }
        else
        {
            Element *current = list->first;
            while( current->next )
            {
                current = current->next;
            }
            current->next = new_element;
        }
    }
}

void output_linked_list( List *list )
{
    if( !list )
    {
        cout<<endl<<"List is not initialised"<<endl;
    }
    else
    {
        if( !list->first )
        {
            cout<<endl<<"List is empty"<<endl;
        }
        else
        {
            Element *current = list->first;
            cout<<endl;
            while( current )
            {
                cout<<current->key<<"\t";
                current = current->next;
            }
            cout<<endl;
        }
    }
}

void sort_linked_list( List *list )
{
    if( !list )
    {
        cout<<endl<<"List is not initialised"<<endl;
    }
    else
    {
        if( !list->first )
        {
            cout<<endl<<"List is empty"<<endl;
        }
        else
        {
            if( list->first->next )
            {
                Element *crawler = list->first;
                // The only purpose of the variable "min" is to be used inside the condition of "if" inside the loop "while"
                // because the element that saves the real min element should be pointing at the element before him, so later
                // we can connect the list again, but here the variable "min" can not point to the element before the real min
                // because our pointer of the first element in the list (list->first) belongs to a struct of type "List".
                Element *min = list->first;
                Element *saved_min_element = NULL;
                bool min_found = false;
                
                while( crawler->next )
                {
                    if( crawler->next->key < min->key )
                    {
                        saved_min_element = crawler;
                        min = crawler->next;
                        min_found = true;
                    }
                    crawler = crawler->next;
                }
                
                if( min_found == true )
                {
                    Element *tmp_element = list->first;
                    
                    list->first = saved_min_element->next;
                    saved_min_element->next = saved_min_element->next->next;
                    list->first->next = tmp_element;
                }
                
                Element *anchor = list->first;
                
                while( anchor->next->next )
                {
                    crawler = anchor->next;
                    min = anchor->next;
                    saved_min_element = NULL;
                    min_found = false;
                    
                    while( crawler->next )
                    {
                        if( crawler->next->key < min->key )
                        {
                            saved_min_element = crawler;
                            min = crawler->next;
                            min_found = true;
                        }
                        crawler = crawler->next;
                    }
                    
                    if( min_found == true )
                    {
                        Element *tmp_element = anchor->next;
                        
                        anchor->next = saved_min_element->next;
                        saved_min_element->next = saved_min_element->next->next;
                        anchor->next->next = tmp_element;
                    }
                    
                    anchor = anchor->next;
                }
            }
        }
    }
}
