#include <iostream>
#include <string>
#include "song.h"

void song::set_name( string &_name ){
    name = _name;
}
void song::set_release_date( string &_release_date ){
    release_date = _release_date;
}
void song::set_performer( string &_performer ){
    performer = _performer;
}
void song::add_collaborator( string &collaborator ){
    collaborators.push_back( collaborator );
}

string song::get_name() const {
    return name;
}
string song::get_release_date() const {
    return release_date;
}
string song::get_performer() const {
    return performer;
}
bool song::has_collaborator( string &collaborator ){
    for( int i = 0; i < collaborators.size(); ++i )
        if( collaborators[i] == collaborator ) return true;
    return false;
}

istream& operator>> ( istream &cin, song &_song ){
    getline( cin, _song.name );
    getline( cin, _song.release_date );
    getline( cin, _song.performer );
    return cin;
}
ostream& operator<< ( ostream &cout, const song& _song ){
    cout << "Name: " << _song.name << '\n';
    cout << "Released on: " << _song.release_date << '\n';
    cout << "Performed by: " << _song.performer << '\n';
    if( !_song.collaborators.empty() ){
        cout << "Collaborators: ";
        for( int i = 0; i < _song.collaborators.size(); ++i ) {
            cout << _song.collaborators[i];
            if( i != _song.collaborators.size()-1 ) cout << ", ";
        }
        cout << '\n';
    }
    return cout;
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