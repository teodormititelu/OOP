#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "song.h"

class album{
    std::string name;
    std::vector < std::unique_ptr < song > > songs;

public:
    album(){
        name = "";
        songs.clear();
    }
    album( const std::string &_name, std::vector < std::unique_ptr < song > > &_songs ){
        name = _name;
        for( int i = 0; i < _songs.size(); ++i )
            songs.push_back( std::move( _songs[i] ) );
        _songs.clear();
    }
    album( album &_album ){
        name = _album.name;
        songs.clear();
        for( int i = 0; i < _album.songs.size(); ++i )
            songs.push_back( std::move ( _album.songs[i] ) );
        _album.songs.clear();
    }

    std::string get_name() const;
    int get_length() const;
    song get_song( int index ) const;
    bool check_song( const song &_song );

    void set_name( const std::string &_name );
    void add_song( const song &_song );

    friend std::istream& operator>> ( std::istream &cin, album &_album );
    friend std::ostream& operator<< ( std::ostream &cout, const album &_album );

    album &operator= ( album& _album );
};
