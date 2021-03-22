#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "artist.h"
#include "song.h"
#include "album.h"

using namespace std;

class band{

    string name;
    vector < artist > members;
    person manager;
    vector < album > albums;
    vector < song > singles;

public:

    band(){
        name = "";
        members.clear();
        albums.clear();
        singles.clear();
        manager = person();
    }
    band( string _name, vector < artist > _members, person _manager, vector < album > _albums, vector < song > _singles){
        name = _name;
        members = _members;
        manager = _manager;
        albums = _albums;
        singles = _singles;
    }
    ~band(){
        cout << name << " broke up\n";
    }

    string get_name();
    person get_manager();
    bool check_member( artist &_member );
    bool check_album( album &_album );
    bool check_single( song &_song );
    
    void set_name( string &_name );
    void set_manager( person &_manager );
    void add_member( artist &_artist);
    void add_album( album &_album );
    void add_single( song &_song );
    
    friend ostream& operator<< ( ostream &cout, const band& _band );
};

