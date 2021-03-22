#pragma once

#include <iostream>
#include "person.h"

using namespace std;

class artist : public person{

    string role; // lead vocal, drummer, lead guitar ...
    vector < string > instruments;

public:

    artist() : person(){
        role = "None";
        instruments.clear();
    }
    artist( person p ) : person(p){}
    artist( person p, string r, vector < string > i ) : person(p){
        role = r;
        instruments = i;
    }

    void set_role( string &r );
    void set_intruments( vector < string > &i );
    void add_instrument( string &i );

    string get_role();
    vector < string > get_instruments();

    bool check_instrument( string &instrument );

    friend ostream& operator<< ( ostream &cout, const artist &a );
    friend istream& operator>> ( istream &cin, artist &a );

    artist &operator= ( const artist &a );

    bool operator==( const artist &a );
};

