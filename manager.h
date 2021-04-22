#pragma once

#include <iostream>
#include "person.h"

class manager : public person{
    std::string business;

public:

    manager() : person(){
        business = "None";
    }

    manager( const person &p ) : person(p) { business= "None"; }

    manager( const person &p, const std::string &_business ) : person(p) {
        business = _business;
    }

    std::string get_job() override{
        return "Manager at: " + business;
    }

    friend std::istream& operator >>  ( std::istream& cin, manager &m ){
        cin >> m.first_name >> m.last_name >> m.gender >> m.age >> m.birth_date >> m.business;
        return cin;
    }

    friend std::ostream& operator << ( std::ostream& cout, const manager &m ){
        cout << m.first_name << ' ' << m.last_name << '\n';
        cout << "Manager at:  " << m.business << '\n';
        return cout;
    }

    manager &operator = ( const manager& mng ){
        this -> first_name = mng.first_name;
        this -> last_name = mng.last_name;
        this -> business = mng.business;

        return *this;
    }
};