#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "person.h"
#include "artist.h"
#include "manager.h"
#include "song.h"
#include "album.h"

class band {

    std::string name;
    std::vector < std::shared_ptr < artist > > members;
    manager mng;
    std::vector < std::unique_ptr < album > > albums;
    std::vector < std::unique_ptr < song > > singles;

public:

    band(){
        name = "";
        members.clear();
        albums.clear();
        singles.clear();
        mng = manager();
    }
    band( const std::string &_name, std::vector < std::shared_ptr < artist > > &_members, const manager &_manager, std::vector < std::unique_ptr < album > > &_albums, std::vector < std::unique_ptr < song > > &_singles){
        name = _name;

        members = _members;

        mng = _manager;

        for( int i = 0; i < _albums.size(); ++i )
            albums.push_back( std::move( _albums[i] ) );
        _albums.clear();

        for( int i = 0; i < _singles.size(); ++i )
            singles.push_back( std::move( _singles[i] ) );
        _singles.clear();

    }
    ~band(){
        std::cout << name << " broke up\n";
    }

    std::string get_name();
    manager get_manager();
    bool check_member( const artist &_member );
    bool check_song( const song &_song );
    bool check_single( const song &_song );

    void set_name( const std::string &_name );
    void set_manager( const manager &_manager );
    void add_member( const artist &_artist);
    void add_album( album &_album );
    void add_single( const song &_song );
    
    friend std::ostream& operator<< ( std::ostream &cout, const band& _band );
};

