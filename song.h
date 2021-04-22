#pragma once

#include <iostream>
#include <string>
#include <vector>

class song{

    std::string name;
    std::string release_date;
    std::string performer;
    std::vector < std::string > collaborators;

    friend class album;

public:

    song(){
        name = release_date = performer = "None";
        collaborators.clear();
    }
    song( std::string _name, std::string _release_date, std::string _performer ) {
        name = _name;
        release_date = _release_date;
        performer = _performer;
    }

    void set_name( const std::string &_name );
    void set_release_date(  const std::string &_release_date );
    void set_performer( const std::string &_performer );
    void add_collaborator( const std::string &collaborator );

    std::string get_name() const;
    std::string get_release_date() const;
    std::string get_performer() const;
    bool has_collaborator( const std::string &collaborator );

    friend std::istream& operator>> ( std::istream &in, song &_song );
    friend std::ostream& operator<< ( std::ostream &out, const song& _song );

    song &operator= ( const song& song );

    bool operator==( const song &_song );
    bool operator!=( const song &_song );
};
