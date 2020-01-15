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