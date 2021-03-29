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
    return songs.size();
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
    int length;
    cin >> length;
    cin.get();

    song _song;
    for( int i = 0; i < length; ++i ) {
        cin >> _song;
        _album.songs.push_back( _song );
    }
    return cin;
}
ostream& operator<< (ostream &cout, const album &_album ){
    cout << "Album name: " << _album.name << " (" << _album.songs.size() << " songs)\n";
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
    songs.clear();
    for( int i = 0; i < _album.songs.size(); ++i )
        this -> songs.push_back( _album.songs[i] );

    return *this;
}

bool album::operator==( const album &_album ){
    if( name == _album.name && get_length() == _album.get_length() ) {
        for (int i = 0; i < songs.size() && i < _album.songs.size(); ++i)
            if ( songs[i] != _album.songs[i])
                return false;
        return true;
    }
    return false;
}
