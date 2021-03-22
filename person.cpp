#include <iostream>
#include <string>
#include "person.h"

using namespace std;

void person::set_name( string &f_name, string &l_name ){
    first_name = f_name;
    last_name = l_name;
}
void person::set_gender( string &gen ){
    gender = gen;
}
void person::set_age( int &x ){
    age = x;
}
void person::set_birth_date( string &date ){
    birth_date = date;
}
string person::get_first_name() const{
    return first_name;
}
string person::get_last_name() const{
    return last_name;
}
int person::get_age() const{
    return age;
}
string person::get_birth_date() const{
    return birth_date;
}

ostream& operator<< (ostream &cout, const person &p){
    cout << p.first_name << ' ' << p.last_name << '\n';
    cout << "Gender: " << p.gender << '\n';
    cout << "Age: " << p.age << " (birth date: " << p.birth_date << ")\n";;
    return cout;
}
istream& operator>> (istream &cin, person &p){
    cin >> p.first_name >> p.last_name >> p.gender >> p.age >> p.birth_date;
    return cin;
}

person &person::operator=(const person &p){
    this -> first_name = p.first_name;
    this -> last_name = p.last_name;
    this -> gender = p.gender;
    this -> age = p.age;
    this -> birth_date = p.birth_date;

    return *this;
}

bool person::operator== ( const person &p ){
    if( first_name == p.first_name && last_name == p.last_name && gender == p.gender && age == p.age && birth_date == p.birth_date)
        return true;
    return false;
}