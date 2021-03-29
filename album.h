#pragma once

#include <iostream>
#include <string>
#include "song.h"

using namespace std;

class album{
    string name;
    vector < song > songs;

public:
    album(){
        name = "";
        songs.clear();
    }
    album( string _name, vector < song > _songs ){
        name = _name;
        songs = _songs;
    }

    string get_name() const;
    int get_length() const;
    song get_song( int index ) const;
    bool check_song( song &_song );

    void set_name( string &_name );
    void add_song( song &_song );

    friend istream& operator>> ( istream &cin, album &_album );
    friend ostream& operator<< (ostream &cout, const album &_album );

    album &operator= ( const album& _album );

    bool operator==( const album &_album );
};
