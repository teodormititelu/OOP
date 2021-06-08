#pragma once

#include "band.h"
#include "compare.h"
#include <string>
#include <vector>
#include <ostream>
#include <algorithm>

//Conection Pool Design Pattern

class band_slot{
    band* booked_band;
    int slot_nr;
    bool occupied;
public:
    void book( band* band ){ occupied = true; booked_band = band; }
    bool free() const { return !occupied; }
    void cancel(){ occupied = false; booked_band = nullptr; }

    band_slot(int slotNr);

    band_slot( const band_slot& bandSlot );

    band *getBookedBand() const;

    int getSlotNr() const;

    int getCoef() const;// the criteria of comparison
    std::string getDay( int starting_day, int bands_per_day ) const;
    std::string getHour( int starting_hour, int bands_per_day ) const;

    friend void swap( band_slot &A, band_slot &B);

    band_slot& operator=(const band_slot &band_slot);
    //band_slot& band_slot::operator=(const band_slot&)
};
class festival {
    int number_of_slots = 0;
    std::vector < band_slot > Slots;
    int starting_day, number_of_days;
    std::string name;
    int starting_hour;
public:
    festival (const festival& ) = delete;
    festival& operator= (const festival& ) = delete;

    festival(int numberOfSlots, int startingDay, int numberOfDays, const std::string &name, int startingHour);

    band_slot& book_band( band* band) {
        for( auto& slot : Slots)
            if( slot.free() ){
                slot.book( band );
                return slot;
            }
        throw std::runtime_error( ( "No more slots to book" + band->get_name() + "!" ) );
    }

    band_slot* check_band( band* band );
    void cancel_band( band* band );

    friend std::ostream &operator<<(std::ostream &os, festival &festival);
};
