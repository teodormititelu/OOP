#pragma once

#include <iostream>
#include "person.h"

class artist : public person{

    std::string role; // lead vocal, drummer, lead guitar ...
    std::vector < std::string > instruments;

public:

    artist() : person(){
        role = "None";
        instruments.clear();
    }
    artist( const person &p ) : person(p){}
    artist( const person &p, const std::string &r, const std::vector < std::string > &i ) : person(p){
        role = r;
        instruments = i;
    }

    void set_role( const std::string &r );
    void set_intruments( const std::vector < std::string > &i );
    void add_instrument( const std::string &i );

    std::vector < std::string > get_instruments();
    std::string get_job() override;

    bool check_instrument( const std::string &instrument );

    friend std::ostream& operator<< ( std::ostream &out, const artist &a );
    friend std::istream& operator>> ( std::istream &in, artist &a );

    artist &operator= ( const artist &a );

    bool operator==( const artist &a );
};

