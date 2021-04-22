#include <iostream>
#include <fstream>
#include "band.h"

std::ifstream fin("sample_input.txt" );

int main() {

    std::string band_name;
    std::vector < std::unique_ptr < album > > albums;
    std::vector < std::unique_ptr < song > > singles;
    std::vector < std::shared_ptr < artist > > members;
    std::vector < std::shared_ptr < person > > people;

    getline( fin, band_name );

    std::string f_name, l_name, gen, date;
    int age;
    int members_nr;

    std::string role, line;
    std::vector < std::string > instruments;

    fin >> members_nr;

    person pers;

    for( int i = 1; i <= members_nr; ++i ) {

        fin >> pers;
        fin.get();
        getline( fin, role );

        getline( fin, line );

        int last = 0;
        for( int i = 0; i < line.size(); ++i )
            if( line[i] == ' ' ){
                instruments.push_back( line.substr( last, i-last ) );
                last = i+1;
            }

        people.push_back( std::make_shared < person > ( pers ) );
        members.push_back( std::make_shared < artist > ( artist( *people.back() , role, instruments ) ) );
    }

    int mng_index;
    fin >> mng_index;
    fin.get();

    manager mng = manager( *members[mng_index-1], band_name );

    person *ptr = &(*members[0]);
    std::cout << *ptr << "Job: " << ptr -> get_job() << "\n\n";

    std::cout << *members[0] << '\n';

    ptr = &mng;
    std::cout << mng.get_name() << '\n' << ptr -> get_job() << "\n\n";

    std::string a_name, s_name, performer;
    int length;
    std::vector < std::unique_ptr < song >  > songs;
    song _song, single;

    getline( fin, a_name );
    fin >> length;
    fin.get();

    for( int i = 1; i <= length; ++i )
    {
        if( i % 2 == 0 ) {
            fin >> _song;
            songs.push_back( std::make_unique < song > ( _song ) );
        }
        else{
            getline( fin, s_name );
            getline( fin, date );
            getline( fin, performer );
            songs.push_back( std::make_unique < song > ( song( s_name, date, performer) ) );
        }
    }

    album Steal_this_album( a_name, songs );
    std::cout << Steal_this_album << '\n';

    std::cout << Steal_this_album.get_song( 4 ) << '\n';

    fin >> single;

    albums.push_back( std::make_unique < album > ( Steal_this_album ) );
    singles.push_back( std::make_unique < song > ( single ) );

    band SOAD( band_name, members, person(), albums, singles );

    std::cout << SOAD << '\n';

    return 0;
}
