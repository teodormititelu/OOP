#pragma once

#include <iostream>
#include <string>

class person{

protected:

    std::string first_name, last_name;
    std::string gender;
    int age;
    std::string birth_date;

public:

    person(){
        first_name = last_name = gender = birth_date = "None";
        age = 0;
    }
    person( const std::string &f_name, const std::string &l_name, const std::string &gen, int x, const std::string &date){
        first_name = f_name;
        last_name = l_name;
        gender = gen;
        age = x;
        birth_date = date;
    }
    virtual ~person() {}

    void set_name( const std::string &f_name, const std::string &l_name );
    void set_gender( const std::string &gen );
    void set_age( int x );
    void set_birth_date( const std::string &date );

    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_name() const { return get_first_name() + " " + get_last_name(); }
    int get_age() const;
    std::string get_birth_date() const;
    virtual std::string get_job() ;

    friend std::ostream& operator<< (std::ostream &out, const person &p);
    friend std::istream& operator>> (std::istream &in, person &p);

    person &operator=(const person &p);

    bool operator==( const person &p );
};
