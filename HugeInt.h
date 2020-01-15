#ifndef HUGEINT_H
#define HUGEINT_H

#include<iostream>
using namespace std;

class HugeInt
{
    friend ostream &operator << ( ostream& , const HugeInt &);
    public:
        HugeInt( long = 0);
        HugeInt ( const char * ) ;

        HugeInt operator+ ( const HugeInt & ) const ;
        HugeInt operator+ ( int ) const ;
        HugeInt operator+ ( const char* ) const ;
        HugeInt operator*( const HugeInt & )const ;
        bool operator != ( const HugeInt &right ) const{
            return !( *this == right ) ;
        }
        bool operator==( const HugeInt & ) const ;
        bool operator<(const HugeInt &) const ;
        bool operator<= ( const HugeInt &right ) const
        {
            return !( right < *this );
        }
        bool operator> ( const HugeInt &right ) const
        {
            right < *this ;
        }
        bool operator >= (const HugeInt &right )const
        {
            return !(*this < right ) ;
        }

    private:
        int integer[ 30 ] ;
}

#endif