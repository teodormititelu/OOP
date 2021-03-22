#include <iostream>
#include <string>
#include <vector>
#include "album.h"
#include "song.h"

using namespace std;

string album::get_name() const {
    return name;
}
int album::get_length() const{
    return length;
}
song album::get_song( int index ) const{
    return songs[index];
}
bool album::check_song( song &_song ){
    for( int i = 0; i < songs.size(); ++i )
        if( songs[i] == _song) return true;
    return false;
}

void album::set_name( string &_name ){
    name = _name;
}
void album::add_song( song &_song ){
    songs.push_back( _song );
}

istream& operator>> ( istream &cin, album &_album ){
    getline( cin, _album.name );
    cin >> _album.length;
    cin.get();

    song _song;
    for( int i = 0; i < _album.length; ++i ) {
        cin >> _song;
        _album.songs.push_back( _song );
    }
    return cin;
}
ostream& operator<< (ostream &cout, const album &_album ){
    cout << "Album name: " << _album.name << " (" << _album.length << " songs)\n";
    cout << "Songs: ";
    for( int i = 0; i < _album.songs.size(); ++i ){
        cout << _album.songs[i].get_name() ;
        if( i != _album.songs.size()-1 )
            cout << ", ";
    }
    cout << '\n';
    return cout;
}

album &album::operator= ( const album& _album ){
    this -> name = _album.name;
    this -> length = _album.length;
    for( int i = 0; i < _album.songs.size(); ++i )
        this -> songs.push_back( _album.songs[i] );

    return *this;
}

bool album::operator==( const album &_album ){
    if( name == _album.name && length == _album.length ) {
        for (int i = 0; i < songs.size() && i < _album.songs.size(); ++i)
            if ( songs[i] != _album.songs[i])
                return false;
        return true;
    }
    return false;
}
