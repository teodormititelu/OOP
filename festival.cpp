
#include "festival.h"

band *band_slot::getBookedBand() const {
    return booked_band;
}

int band_slot::getSlotNr() const {
    return slot_nr;
}

void swap( band_slot &A, band_slot &B) {
    A.slot_nr = A.slot_nr ^ B.slot_nr;
    B.slot_nr = A.slot_nr ^ B.slot_nr;
    A.slot_nr = A.slot_nr ^ B.slot_nr;
}

std::string band_slot::getDay( int starting_day, int bands_per_day  ) const{

    int day = starting_day + ( (slot_nr - 1)/bands_per_day );
    switch (day) {
        case 1:
            return  "Monday";
        case 2:
            return  "Tuesday";
        case 3:
            return  "Wednesday";
        case 4:
            return  "Thursday";
        case 5:
            return  "Friday";
        case 6:
            return  "Saturday";
        case 7:
            return  "Sunday";
    }
    return "Invalid input";
}

std::string band_slot::getHour(int starting_hour, int bands_per_day) const{
    int nr = (slot_nr - 1) % bands_per_day;
    return  std::to_string( (starting_hour + nr)%24 ) + ":00";
}

band_slot::band_slot(int slotNr) : slot_nr(slotNr) {
    occupied = false;
}

int band_slot::getCoef() const{
    return slot_nr;
}

band_slot &band_slot::operator=(const band_slot &band_slot){
    this->slot_nr = band_slot.slot_nr;
    this->occupied = band_slot.occupied;
    this->booked_band = band_slot.booked_band;
    return  *this;
}

band_slot::band_slot(const band_slot& band_slot ) {
    this->slot_nr = band_slot.slot_nr;
    this->occupied = band_slot.occupied;
    this->booked_band = band_slot.booked_band;
}


band_slot* festival::check_band(band *band) {
    for( int i = 0; i < number_of_slots; ++i )
        if( band == Slots[i].getBookedBand() )
            return &Slots[i];
    return nullptr;
}

void festival::cancel_band(band *band) {
    band_slot* slot = check_band( band );

    if( slot )
        slot->cancel();
    else std::cout << band->get_name() + "is not booked at " + name;
}

festival::festival(int numberOfSlots, int startingDay, int numberOfDays, const std::string &name, int startingHour)
: number_of_slots(numberOfSlots), starting_day(startingDay), number_of_days(numberOfDays), name(name), starting_hour(startingHour) {
    for( int i = 0; i < numberOfSlots; ++i )
        Slots.push_back( band_slot(i+1) );
}

std::ostream &operator<<(std::ostream &os, festival &festival) {
    os << festival.name << ":\n";
    std::sort( festival.Slots.begin(), festival.Slots.end(), compare<band_slot> );
    for( int i = 0; i < festival.number_of_slots; ++i )
        if( !festival.Slots[i].free() ){
            os << "*" << festival.Slots[i].getDay(festival.starting_day, festival.number_of_slots/festival.number_of_days ) << " at ";
            os << festival.Slots[i].getHour(festival.starting_hour, festival.number_of_slots/festival.number_of_days ) << " - ";
            os << festival.Slots[i].getBookedBand()->get_name() << '\n';
        }
    return os;
}
