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

    try{
        songs.push_back( std::make_unique < song > ( _song ) );
        length += _song.get_seconds();
        if( length > 7200 ) throw( length );
    }
    catch ( int length ){
        std::cout << name << " lasts longer than 2h [nobody will listen to it]\n";
    }

}

std::istream& operator>> ( std::istream &in, album &_album ){
    try{
        getline( in, _album.name );
        int length;
        in >> length;
        in.get();

        if( length < 0 ) throw(length);
        song _song;
        for( int i = 0; i < length; ++i ) {
            in >> _song;
            _album.songs.push_back( std::make_unique < song > ( _song ) );
        }
    }
    catch (int length ){
        std::cout << "Invalid input\n" << length << "is not a valid length!\n";
    }
    return in;
}
std::ostream& operator<< (std::ostream &out, const album &_album ){
    out << "Album name: " << _album.name << " (" << _album.songs.size() << " songs)\n";
    out << "Songs: ";
    for( int i = 0; i < _album.songs.size(); ++i ){
        out << _album.songs[i] -> get_name() ;
        if( i != _album.songs.size()-1 )
            out << ", ";
    }
    out << '\n';
    return out;
}

album &album::operator= ( album &&_album ){

    if( this != &_album ){
        this -> name = _album.name;
        _album.name = nullptr;
        songs.clear();
        for( int i = 0; i < _album.songs.size(); ++i )
            this -> songs.push_back( std::move ( _album.songs[i] ) );
        _album.songs.clear();
    }

    return *this;
}

