#include <cctype>
#include <cstring>
#include "HugeInt.h"

using namespace std ;

HugeInt::HugeInt( long value )
{
    for ( int i = 0 ; i <= 29 ; i++ )
        integer[ i ] = 0 ;
    
    for ( int j = 29 ; value != 0  && j >= 0 ; j--)
    {
        integer[ j ] = value % 10 ;
        value /= 10 ;
    }
}

HugeInt::HugeInt( const char * strg )
{ 
    for ( int i = 0 ; i <= 29 ; i++ )
        integer[ i ] = 0 ;

    int length = strlen( strg ) ;
    
    for ( int j = 30 - length , k = 0 ; j <= 29 ;  j++ , k++)
        if ( isdigit( strg[ k ] ))
            integer[ j ] = strg[ k ] - '0' ;
}

HugeInt HugeInt::operator+ ( const HugeInt &op2 ) const 
{
    HugeInt temp ;
    int carry = 0 ;

    for( int i = 29; i >= 0  ; i-- )
    {
        temp.integer[ i ] = integer[ i ] + op2.integer[i ] + carry ;

        if( temp.integer[ i ] > 9 )
        {
            temp.integer[i] %= 10;
            carry = 1 ;
        }

        else 
        carry = 0 ;
    }

    return temp ;
}

HugeInt HugeInt::operator+( int op2 ) const 
{
    return *this + HugeInt( op2 ) ;
}

HugeInt HugeInt::operator+ ( const char * op2 ) const 
{
    return *this + HugeInt( op2 );
}

ostream &operator<< ( ostream &output , const HugeInt &num )
{
    int i ;
    for ( i = 0 ; ( num.integer[ i ] == 0 ) && ( i <= 29) ; i++)
    ;

    if ( i == 30 )
        output << 0 ;
    else
        {
            for(; i <= 29 ; i++ )
            output << num.integer[ i ] ;
        }
    return output ;
    
}

bool HugeInt::operator< ( const HugeInt &right ) const
{
    for( int i = 0 ; i <= 29 ; i++ )
    {
        if ( integer[ i] == right.integer[i] )
            continue ;
        if( integer[i] > right.integer[i] )
            return false ;
        else
            return true ;
        
    }
    return false ;
}

bool HugeInt::operator==( const HugeInt &right ) const
{
    for( int i = 0 ; i <= 29; i++)
        if( integer[i] != right.integer[i] )
            return false ;
    return true ;
}