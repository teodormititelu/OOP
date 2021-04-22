#include <iostream>
#include <string>
#include "person.h"

void person::set_name( const std::string &f_name, const std::string &l_name ){
    first_name = f_name;
    last_name = l_name;
}
void person::set_gender( const std::string &gen ){
    gender = gen;
}
void person::set_age( int x ){
    age = x;
}
void person::set_birth_date( const std::string &date ){
    birth_date = date;
}
std::string person::get_first_name() const{
    return first_name;
}
std::string person::get_last_name() const{
    return last_name;
}
int person::get_age() const{
    return age;
}
std::string person::get_birth_date() const{
    return birth_date;
}
std::string person::get_job() {
    return "unemployed";
}

std::ostream& operator<< (std::ostream &cout, const person &p){
    cout << p.first_name << ' ' << p.last_name << '\n';
    cout << "Gender: " << p.gender << '\n';
    cout << "Age: " << p.get_age() << " (birth date: " << p.get_birth_date() << ")\n";;
    return cout;
}
std::istream& operator>> (std::istream &cin, person &p){
    cin >> p.first_name >> p.last_name >> p.gender >> p.age >> p.birth_date;
    if( p.age < 0 ) std::cout << p.age << " is not a valid age!\n";
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