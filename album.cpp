#include <iostream>
#include <string>
#include <vector>
#include "album.h"
#include "song.h"

using namespace std;

string album::get_name(){
    return name;
}
string album::get_type(){
    return type;
}
bool album::check_song( song &_song ){
    for( int i = 0; i < songs.size(); ++i )
        if( songs[i] == _song) return true;
    return false;
}

void album::set_name( string &_name ){
    name = _name;
}
void album::set_type( string &_type ){
    type = _type;
}
void album::add_song( song &_song ){
    songs.push_back( _song );
}

istream& operator>> ( istream &cin, album &_album ){
    cin >> _album.name >> _album.type;
    return cin;
}
ostream& operator<< (ostream &cout, const album &_album ){
    cout << "Album name: " << _album.name << " (" << _album.type << " )\n";
    cout << "Songs: ";
    for( int i = 0; i < _album.songs.size(); ++i ){
        cout << _album.songs[i];
        if( i != _album.songs.size()-1 )
            cout << ", ";
    }
    cout << '\n';
    return cout;
}

album &album::operator= ( const album& _album ){
    this -> name = _album.name;
    this -> type = _album.type;
    for( int i = 0; i < _album.songs.size(); ++i )
        this -> songs.push_back( _album.songs[i] );

    return *this;
}

bool album::operator==( const album &_album ){
    if( name == _album.name && type == _album.type ) {
        for (int i = 0; i < songs.size() && i < _album.songs.size(); ++i)
            if ( songs[i] != _album.songs[i])
                return false;
        return true;
    }
    return false;
}
