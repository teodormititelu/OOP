#ifndef PROJECT_1_ALBUM_H
#define PROJECT_1_ALBUM_H

#include <iostream>
#include <string>
#include "song.h"

using namespace std;

class album{
    string name;
    vector < song > songs;
    string type;

public:
    album(){
        name = type = "";
        songs.clear();
    }
    album( string &_name, vector < song > &_songs, string _type = "LP" ){
        name = _name;
        songs = _songs;
        type = _type;
    }

    string get_name();
    string get_type();
    bool check_song( song &_song );

    void set_name( string &_name );
    void set_type( string &_type );
    void add_song( song &_song );

    friend istream& operator>> ( istream &cin, album &_album );
    friend ostream& operator<< (ostream &cout, const album &_album );

    album &operator= ( const album& _album );

    bool operator==( const album &_album );
};
#endif //PROJECT_1_ALBUM_H
