#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class song{

    string name;
    string release_date;
    string performer;
    vector < string > collaborators;

    friend class album;

public:

    song(){
        name = release_date = performer = "";
        collaborators.clear();
    }
    song( string _name, string _release_date, string _performer ) {
        name = _name;
        release_date = _release_date;
        performer = _performer;
    }

    void set_name( string &_name );
    void set_release_date( string &_release_date );
    void set_performer( string &_performer );
    void add_collaborator( string &collaborator );

    string get_name() const;
    string get_release_date() const;
    string get_performer() const;
    bool has_collaborator( string &collaborator );

    friend istream& operator>> ( istream &cin, song &_song );
    friend ostream& operator<< ( ostream &cout, const song& _song );

    song &operator= ( const song& song );

    bool operator==( const song &_song );
    bool operator!=( const song &_song );
};
