#include <iostream>

using namespace std;

struct Element
{
    int exponent;
    int coef;
    Element *next;
};

int main()
{
    void add_element( Element *&list , int exponent , int coef );
    void display_polynomial( Element *);
    void add_two_polynomials( Element *poly_1 , Element *poly_2 , Element *&poly_3 );
    
    Element *polynomial_1 = NULL;
    Element *polynomial_2 = NULL;
    Element *polynomial_3 = NULL;
    
    add_element( polynomial_1 , 2 , 4 );
    add_element( polynomial_1 , 1 , 6 );
    //add_element( polynomial_1 , 0 , 13 );
    
    cout<<endl<<"Polynomial 1 :"<<endl;
    display_polynomial( polynomial_1 );
    
    //add_element( polynomial_2 , 2 , 2 );
    add_element( polynomial_2 , 1 , 8 );
    add_element( polynomial_2 , 0 , 24 );
    
    cout<<endl<<"Polynomial 2 :"<<endl;
    display_polynomial( polynomial_2 );
    
    cout<<endl<<"Add Poly_1 and poly_2 into poly_3 :"<<endl;
    add_two_polynomials( polynomial_1 , polynomial_2 , polynomial_3 );
    display_polynomial( polynomial_3 );

    return 0;
}

void add_element( Element *&list , int exponent , int coef )
{
    Element *new_element = new Element;
    
    new_element->exponent = exponent;
    new_element->coef = coef;
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

void display_polynomial( Element *list )
{
    if( !list )
    {
        cout<<endl<<"list empty"<<endl;
    }
    else
    {
        Element *current = list;
        cout<<endl;
        while( current )
        {
            if( current->exponent == 0 )
            {
                cout<<current->coef;
            }
            else
            {
                if( current->exponent == 1 )
                {
                    cout<<current->coef<<"X";
                }
                else
                {
                    cout<<current->coef<<"X^"<<current->exponent;
                }
                if( current->next )
                {
                    cout<<" + ";
                }
            }
            current = current->next;
        }
        cout<<endl;
    }
}

void add_two_polynomials( Element *poly_1 , Element *poly_2 , Element *&poly_3 )
{
    Element *current_1 = poly_1;
    Element *current_2 = poly_2;
    poly_3 = new Element;
    Element *current_3 = poly_3;
    
    while( current_1 != NULL && current_2 != NULL )
    {
        Element *new_term = new Element;
        if( current_1->exponent == current_2->exponent )
        {
            new_term->exponent = current_1->exponent;
            new_term->coef = current_1->coef + current_2->coef;
            
            current_1 = current_1->next;
            current_2 = current_2->next;
        }
        else
        {
            if( current_1->exponent > current_2->exponent )
            {
                new_term->exponent = current_1->exponent;
                new_term->coef = current_1->coef;
                
                current_1 = current_1->next;
            }
            else
            {
                new_term->exponent = current_2->exponent;
                new_term->coef = current_2->coef;
                
                current_2 = current_2->next;
            }
        }
        current_3->next = new_term;
        current_3 = current_3->next;
    }
    
    while( current_1 != NULL )
    {
        Element *new_term = new Element;
        
        new_term->exponent = current_1->exponent;
        new_term->coef = current_1->coef;
        
        current_1 = current_1->next;
        
        current_3->next = new_term;
        current_3 = current_3->next;
    }
    
    while( current_2 != NULL )
    {
        Element *new_term = new Element;
        
        new_term->exponent = current_2->exponent;
        new_term->coef = current_2->coef;
        
        current_2 = current_2->next;
        
        current_3->next = new_term;
        current_3 = current_3->next;
    }
    
    current_3->next = NULL;
    
    poly_3 = poly_3->next;
}

