#include <iostream>
#include "band.h"
#include "album.h"
#include "song.h"
#include "artist.h"
#include "person.h"

using namespace std;

int main() {

    string band_name;
    vector < album > albums;
    vector < song > singles;
    vector < artist > members;
    vector < person > people;

    getline( cin, band_name );

    string f_name, l_name, gen, date;
    int age;
    int members_nr;

    string role, line;
    vector < string > instruments;

    cin >> members_nr;

    for( int i = 1; i <= members_nr; ++i ) {

        cin >> f_name >> l_name >> gen >> age >> date;
        cin.get();
        getline( cin, role );

        getline( cin, line );

        int last = 0;
        for( int i = 0; i < line.size(); ++i )
            if( line[i] == ' ' ){
                instruments.push_back( line.substr( last, i-last ) );
                last = i+1;
            }

        people.push_back( person( f_name, l_name, gen, age, date) );
        members.push_back( artist( people.back() , role, instruments ) );
    }

    cout << people[0] << '\n';
    cout << members[0] << '\n';

    string a_name, s_name, performer;
    int length;
    vector < song > songs;
    song _song, single;

    getline( cin, a_name );
    cin >> length;
    cin.get();

    for( int i = 1; i <= length; ++i )
    {
        if( i % 2 == 0 ) {
            cin >> _song;
            songs.push_back(_song);
        }
        else{
            getline( cin, s_name );
            getline( cin, date );
            getline( cin, performer );
            songs.push_back( song( s_name, date, performer) );
        }
    }

    album Steal_this_album( a_name, songs );
    cout << Steal_this_album << '\n';

    cout << Steal_this_album.get_song( 3 ) << '\n';

    cin >> single;

    albums.push_back( Steal_this_album );
    singles.push_back( single );

    band SOAD( band_name, members, person(), albums, singles);

    cout << SOAD << '\n';

    return 0;
}
