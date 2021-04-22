#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "artist.h"

void artist::set_role( const std::string &r ){
    role = r;
}
void artist::set_intruments( const std::vector < std::string > &i ){
    instruments = i;
}
void artist::add_instrument( const std::string &i ){
    instruments.push_back( i );
}

std::vector < std::string > artist::get_instruments(){
    return instruments;
}
std::string artist::get_job() {
    return role;
}

bool artist::check_instrument( const std::string &instrument ){
    for( int i = 0; i < instruments.size(); ++i ){
        if( instruments[i] == instrument ) return true;
    }
    return false;
}

std::ostream& operator<< ( std::ostream &cout, const artist &a ){
    cout << a.first_name << ' ' << a.last_name << '\n';
    cout << "Main role: " << a.role << '\n';
    cout << "Instruments played: ";
    for( int i = 0; i < a.instruments.size(); ++i ){
        cout << a.instruments[i];
        if( i != a.instruments.size()-1 )
            cout << ", ";
    }
    cout << '\n';
    return cout;
}
std::istream& operator>> ( std::istream &cin, artist &a ){
    cin >> a.first_name >> a.last_name >> a.gender >> a.age >> a.birth_date >> a.role;
    if( a.age < 0 ) std::cout << a.age << " is not a valid age!";
    return cin;
}

artist &artist::operator= ( const artist &a ){
    this -> first_name = a.first_name;
    this -> last_name = a.last_name;
    this -> gender = a.gender;
    this -> age = a.age;
    this -> birth_date = a.birth_date;
    this -> role = a.role;
    this -> instruments = a.instruments;
    return *this;
}

bool artist::operator==( const artist &a ){
    if( first_name == a.first_name && last_name == a.last_name && gender == a.gender && age == a.age && birth_date == a.birth_date && role == a.role ){
        for (int i = 0; i < instruments.size() && i < a.instruments.size(); ++i)
            if ( instruments[i] != a.instruments[i])
                return false;
        return true;
    }
    return false;
}
