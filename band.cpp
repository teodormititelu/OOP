#include <iostream>
#include <vector>
#include <string>
#include "band.h"

string band::get_name(){
    return name;
}
person band::get_manager(){
    return manager;
}
bool band::check_member( artist &_artist){
    for( int i = 0; i < members.size(); ++i )
        if( members[i] == _artist ) return true;
    return false;    
}
bool band::check_album( album &_album ){
    for( int i = 0; i < albums.size(); ++i )
        if( albums[i] == _album ) return true;
    return false;
}
bool band::check_single( song &_song ){
    for( int i = 0; i < singles.size(); ++i )
        if( singles[i] == _song ) return true;
    return false;
}

void band::set_name( string &_name ){
    name = _name;
}
void band::set_manager( person &_manager ){
    manager = _manager;
}
void band::add_member( artist &_artist){
    members.push_back( _artist );
}
void band::add_album( album &_album ){
    albums.push_back( _album );
}
void band::add_single( song &_song ){
    singles.push_back( _song );
}

ostream& operator<< ( ostream &cout, const band& _band ){
    cout << "Band name: " << _band.name << '\n';
    cout << "Members: ";
    for( int i = 0; i < _band.members.size(); ++i ){
        cout << _band.members[i];
        if( i != _band.members.size()-1 )
            cout << ", ";
    }
    cout << '\n';
    return cout;
}