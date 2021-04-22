#include <iostream>
#include <string>
#include <vector>
#include "album.h"
#include "song.h"

std::string album::get_name() const {
    return name;
}
int album::get_length() const{
    return songs.size();
}
song album::get_song( int index ) const{
    try {
        if( index < 1 || index > songs.size() ) throw( index );
        return *songs[index - 1];
    }
    catch ( int index ){
        std::cout << "Index out of range [songs[" << index << "])\n";
    }
    return song();
}
bool album::check_song( const song &_song ){
    for( int i = 0; i < songs.size(); ++i )
        if( *songs[i] == _song) return true;
    return false;
}

void album::set_name( const std::string &_name ){
    name = _name;
}
void album::add_song( const song &_song ){
    songs.push_back( std::make_unique < song > ( _song ) );
}

std::istream& operator>> ( std::istream &cin, album &_album ){
    try{
        getline( cin, _album.name );
        int length;
        cin >> length;
        cin.get();

        if( length < 0 ) throw(length);
        song _song;
        for( int i = 0; i < length; ++i ) {
            cin >> _song;
            _album.songs.push_back( std::make_unique < song > ( _song ) );
        }
    }
    catch (int length ){
        std::cout << "Invalid input\n" << length << "is not a valid length!\n";
    }
    return cin;
}
std::ostream& operator<< (std::ostream &cout, const album &_album ){
    cout << "Album name: " << _album.name << " (" << _album.songs.size() << " songs)\n";
    cout << "Songs: ";
    for( int i = 0; i < _album.songs.size(); ++i ){
        cout << _album.songs[i] -> get_name() ;
        if( i != _album.songs.size()-1 )
            cout << ", ";
    }
    cout << '\n';
    return cout;
}

album &album::operator= ( album& _album ){
    this -> name = _album.name;
    songs.clear();
    for( int i = 0; i < _album.songs.size(); ++i )
        this -> songs.push_back( std::move ( _album.songs[i] ) );
    _album.songs.clear();

    return *this;
}

