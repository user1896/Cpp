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
    void add_element_to_list( List *&,  int );
    void display_list( List *);
    void devide_list_without_sacrifice( List *, int , List *&, List *&);
    void devide_list_with_sacrifice( List *&, int , List *&, List *&);
    
    List *D1 = NULL;
    List *D2 = NULL;
    List *D3 = NULL;
    
    display_list(D1);
    
    add_element_to_list( D1 , 11 );
    add_element_to_list( D1 , 22 );
    add_element_to_list( D1 , 33 );
    add_element_to_list( D1 , 44 );
    add_element_to_list( D1 , 55 );
    add_element_to_list( D1 , 66 );
    add_element_to_list( D1 , 77 );
    add_element_to_list( D1 , 88 );
    
    //devide_list_without_sacrifice(D1,4,D2,D3);
    devide_list_with_sacrifice(D1,8,D2,D3);
    
    cout<<endl<<"display D1 :"<<endl;
    display_list(D1);
    
    cout<<endl<<"display D2 :"<<endl;
    display_list(D2);
    
    cout<<endl<<"display D3 :"<<endl;
    display_list(D3);
    
    return 0;
}

void add_element_to_list( List *&list ,  int x )
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

void display_list( List *list )
{
    if( !list )
    {
        cout<<endl<<"List is not initialized"<<endl;
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

void devide_list_without_sacrifice( List *D1 , int lenght_of_original_list , List *&D2 , List *&D3 )
{
    if( lenght_of_original_list < 2 )
    {
        cout<<endl<<"List is too short, it can't be devided"<<endl;
    }
    else
    {
        if( lenght_of_original_list % 2 == 1 )
        {
            cout<<endl<<"List can't be split evenly"<<endl;
        }
        else
        {
            D2 = new List;
            D3 = new List;
            
            Element *new_element_forD2 = new Element;
            new_element_forD2->key = D1->first->key;
            new_element_forD2->next = D1->first->next;
            
            Element *current_D1 = D1->first->next;
            
            D2->first = new_element_forD2;
            Element *current_D2 = D2->first;
            
            for( int i = 2 ; i <= lenght_of_original_list/2 ; i++ )
            {
                Element *new_element_forD2 = new Element;
                new_element_forD2->key = current_D1->key;
                new_element_forD2->next = current_D1->next;
                
                current_D1 = current_D1->next;
                
                current_D2->next = new_element_forD2;
                current_D2 = current_D2->next;
            }
            
            Element *new_element_forD3 = new Element;
            new_element_forD3->key = current_D2->next->key;
            new_element_forD3->next = NULL;
            
            current_D1 = current_D1->next;
            
            current_D2->next = NULL;
            
            D3->first = new_element_forD3;
            Element *current_D3 = D3->first;
            
            for( int i = 2 ; i <= lenght_of_original_list/2 ; i++ )
            {
                Element *new_element_forD3 = new Element;
                new_element_forD3->key = current_D1->key;
                new_element_forD3->next = current_D1->next;
                
                current_D1 = current_D1->next;
                
                current_D3->next = new_element_forD3;
                current_D3 = current_D3->next;
            }
            
            current_D3->next = NULL;
        }
    }
}

void devide_list_with_sacrifice( List *&D1 , int lenght_of_original_list , List *&D2 , List *&D3 )
{
    if( lenght_of_original_list < 2 )
    {
        cout<<endl<<"List is too short, it can't be devided"<<endl;
    }
    else
    {
        if( lenght_of_original_list % 2 == 1 )
        {
            cout<<endl<<"List can't be split evenly"<<endl;
        }
        else
        {
            D2 = D1;
            D1 = NULL;
            
            Element *current_D2 = D2->first;
            
            for( int i = 1 ; i < lenght_of_original_list/2 ; i++ )
            {
                current_D2 = current_D2->next;
            }
            D3 = new List;
            D3->first = current_D2->next;
            current_D2->next = NULL;
        }
    }
}
