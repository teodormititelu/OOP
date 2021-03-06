#include <iostream>
#include <fstream>
#include "band.h"
#include "festival.h"

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

    std::cout << *dynamic_cast<person*>(members[0].get()) << '\n';

    std::cout << *members[0] << '\n';

    person *ptr = &mng;
    std::cout << mng.get_name() << '\n' << ptr -> get_job() << "\n\n";

    for( int i = 0; i < members.size(); ++i ){
        ptr = &(*members[i]);
        std::cout << ptr -> get_name() << ": " << ptr -> get_job() << "\n";
    }
    std:: cout << '\n';

    std::string a_name, s_name, performer, s_length;
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
            getline( fin, performer );
            getline( fin, date );
            getline( fin, s_length );
            songs.push_back( std::make_unique < song > ( song( s_name, performer, date, s_length) ) );
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

    festival JHL( 9, 5, 3, "Jurilovca Heavy Load", 20 );
    std::shared_ptr RB = std::make_shared< artist >( artist( person( "Razvan", "Bucur", "Male", 20, "05/06/2001" ) ) );
    std::vector < std::shared_ptr< artist > > A1m ( { RB } );
    std::vector < std::unique_ptr < song > > A1s;
    std::vector < std::unique_ptr< album > > A1a;
    A1a.push_back(std::make_unique< album > ("Bubuie Cernavoda", A1s ));
    std::vector < std::unique_ptr< song > >A1sg;

    band Anexa1( "Anexa1", A1m, *dynamic_cast <person*> ( RB.get() ),A1a,A1sg );

    JHL.book_band( &SOAD );
    JHL.book_band( &Anexa1 );

    std::cout << JHL << '\n';

    return 0;
}
