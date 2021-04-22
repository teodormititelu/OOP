#include <iostream>
#include <string>
#include "song.h"

void song::set_name( const std::string &_name ){
    name = _name;
}
void song::set_release_date( const std::string &_release_date ){
    release_date = _release_date;
}
void song::set_performer( const std::string &_performer ){
    performer = _performer;
}
void song::add_collaborator( const std::string &collaborator ){
    collaborators.push_back( collaborator );
}

std::string song::get_name() const {
    return name;
}
std::string song::get_release_date() const {
    return release_date;
}
std::string song::get_performer() const {
    return performer;
}
bool song::has_collaborator( const std::string &collaborator ){
    for( int i = 0; i < collaborators.size(); ++i )
        if( collaborators[i] == collaborator ) return true;
    return false;
}

std::istream& operator>> ( std::istream &in, song &_song ){
    getline( in, _song.name );
    getline( in, _song.release_date );
    getline( in, _song.performer );
    return in;
}
std::ostream& operator<< ( std::ostream &out, const song& _song ){
    out << "Name: " << _song.name << '\n';
    out << "Released on: " << _song.release_date << '\n';
    out << "Performed by: " << _song.performer << '\n';
    if( !_song.collaborators.empty() ){
        out << "Collaborators: ";
        for( int i = 0; i < _song.collaborators.size(); ++i ) {
            out << _song.collaborators[i];
            if( i != _song.collaborators.size()-1 ) out << ", ";
        }
        out << '\n';
    }
    return out;
}

song &song::operator= ( const song& _song ){
    this -> name = _song.name ;
    this -> release_date = _song.release_date;
    this -> performer = _song.performer;
    collaborators.clear();
    for( int i = 0; i <= _song.collaborators.size(); ++i )
        this -> collaborators.push_back( _song.collaborators[i] );

    return *this;
}
bool song::operator== ( const song& _song ){
    if( name == _song.name && release_date == _song.release_date && performer == _song.performer && collaborators == _song.collaborators)
        return true;
    return false;
}
bool song::operator!= ( const song& _song ){
    if( name == _song.name && release_date == _song.release_date && performer == _song.performer && collaborators == _song.collaborators)
        return false;
    return true;
}