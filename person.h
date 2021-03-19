#ifndef PROJECT_1_PERSON_H
#define PROJECT_1_PERSON_H

#include <iostream>
#include <string>

using namespace std;

class person{

protected:

    string first_name, last_name;
    string gender;
    int age;
    string birth_date;

public:

    person(){
        first_name = last_name = gender = birth_date = "None";
        age = 0;
    }
    person( string &f_name, string &l_name, string &gen, int &x, string &date){
        first_name = f_name;
        last_name = l_name;
        gender = gen;
        age = x;
        birth_date = date;
    }

    void set_name( string &f_name, string &l_name );
    void set_gender( string &gen );
    void set_age( int &x );
    void set_birth_date( string &date );

    string get_first_name();
    string get_last_name();
    int get_age();
    string get_birth_date();

    friend ostream& operator<< (ostream &cout, const person &p);
    friend istream& operator>> (istream &cin, person &p);

    person &operator=(const person &p);

    bool operator==( const person &p );
};

#endif //PROJECT_1_PERSON_H
