#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "band.h"

std::string band::get_name(){
    return name;
}
manager band::get_manager(){
    return mng;
}
bool band::check_member( const artist &_artist){
    for( int i = 0; i < members.size(); ++i )
        if( *members[i] == _artist ) return true;
    return false;    
}
bool band::check_song( const song &_song ){
    for( int i = 0; i < albums.size(); ++i )
        if( albums[i] -> check_song( _song ) )
            return true;
    return false;
}
bool band::check_single( const song &_song ){
    for( int i = 0; i < singles.size(); ++i )
        if( *singles[i] == _song ) return true;
    return false;
}

void band::set_name( const std::string &_name ){
    name = _name;
}
void band::set_manager( const manager &_manager ){
    mng = _manager;
}
void band::add_member( const artist &_artist){
    members.push_back( std::make_shared< artist > ( _artist ) );
}
void band::add_album( album &_album ){
    albums.push_back( std::make_unique < album > ( _album ) );
}
void band::add_single( const song &_song ){
    singles.push_back( std::make_unique < song > ( _song ) );
}

std::ostream& operator<< ( std::ostream &cout, const band& _band ){
    cout << "Band name: " << _band.name << '\n';
    cout << "Members: ";
    for( int i = 0; i < _band.members.size(); ++i ){
        cout << _band.members[i] -> get_first_name() << ' ' << _band.members[i] -> get_last_name();
        if( i != _band.members.size()-1 )
            cout << ", ";
    }
    cout << '\n';
    for( int i = 0; i < _band.albums.size(); ++i ){
        cout << quoted( _band.albums[i] -> get_name() ) << ": ";
        cout << _band.albums[i] -> get_length() << ", ";
        for( int j = 1; j <= _band.albums[i] -> get_length(); ++j ){
            cout << quoted( ( _band.albums[i] -> get_song( j ) ).get_name() );
            if( j != _band.albums[i] -> get_length() )
                cout << ", ";
        }
        cout << '\n';
    }
    cout << "Singles: ";
    for( int i = 0; i < _band.singles.size(); ++i ){
        cout << quoted( _band.singles[i] -> get_name() );
        if( i != _band.singles.size() - 1 )
            cout << ", ";
    }
    cout << '\n';
    return cout;
}
