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

HugeInt HugeInt::operator*(const HugeInt &right )const
{
    int hold = 0 ;
    for (int i = 0 ; i <= 29 ; i++ )
    {
        if (right.integer[ i ] != 0)
        {
            hold = i ;
            break ;
        }
    }

    HugeInt temp1, temp2 , temp3 ;
    int carry = 0 ;
    int let = 0 ;

    for ( int use = 29 ; use >= hold ; use--)
    {
        for( int i = 29; i>= 0 ; i-- )
        {
            temp1.integer[i] = ( integer[i] * right.integer[ use ]) + carry;
            if ( temp1.integer[i] > 9 )
            {
                carry = temp1.integer[i] / 10 ;
                temp1.integer[i] %= 10;

            }
            else 
                carry = 0 ;
        }

        if ( let > 0 )
        {
            for ( int i = 0 ; i < let ; i++ )
            {
                int m = 0 ;
                while( temp1.integer[ m ] == 0)
                    m++ ;
                for( ; m <= 29 ; m++ )
                    temp1.integer[ m - 1 ] = temp1.integer[ m ] ;
                
                temp1.integer[ m - 1 ] = 0 ;
            }
        }
        let++;
        temp2 = temp2 + temp1;
        temp1 = temp3 ;

    }
    return temp2 ;
}