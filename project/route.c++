#include <string>
using namespace std;

class Routes
{
    string Airline;
    string Airline_ID;
    string Source_Airport;
    string Source_Airport_ID;
    string Destination_Airport;
    string Destination_Airport_ID;
    string Codeshare;
    string Stops;
    string Equipment;

public:
    Routes(string, string, string, string, string, string, string, string, string);
    string to_string();
    string getAirline();
    string getAirlineId();
    string getSourceAirport();
    string getSourceAirportId();
    string getDestinationAirport();
    string getDestinationAirportId();
    string getCodeshare();
    string getStops();
    string getEquipment();
};

Routes::Routes(string airline, string airlineId, string sourceAirport, string sourceAirportId, string destinationAirport, string destinationAirportId, string codeshare, string stops, string equipment)
{
    this->Airline = airline;
    this->Airline_ID = airlineId;
    this->Source_Airport = sourceAirport;
    this->Source_Airport_ID = sourceAirportId;
    this->Destination_Airport = destinationAirport;
    this->Destination_Airport_ID = destinationAirportId;
    this->Codeshare = codeshare;
    this->Stops = stops;
    this->Equipment = equipment;
}

string Routes::getAirline()
{
    return Airline;
}

string Routes::getAirlineId()
{
    return Airline_ID;
}

string Routes::getSourceAirport()
{
    return Source_Airport;
}

string Routes::getSourceAirportId()
{
    return Source_Airport_ID;
}

string Routes::getDestinationAirport()
{
    return Destination_Airport;
}

string Routes::getDestinationAirportId()
{
    return Destination_Airport_ID;
}

string Routes::getCodeshare()
{
    return Codeshare;
}

string Routes::getStops()
{
    return Stops;
}

string Routes::getEquipment()
{
    return Equipment;
}

string Routes::to_string()
{
    return "Airline: " + getAirline() + " Airline_id: " + getAirlineId() + " source " + getSourceAirport() + " destination " + getDestinationAirport();
}