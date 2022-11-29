#include <string>
using namespace std;
class Airport
{
private:
    string Airport_ID;
    string Name;
    string City;
    string Country;
    string IATA;
    string ICAO;
    string Latitude;
    string Longitude;
    ;

public:
    Airport(string airportId, string name, string city, string country, string iata,
            string icao, string latitude, string longitude);

    string to_string();

    string getAirportId();

    string getName();

    string getCity();

    string getCountry();

    string getIata();

    string getIcao();

    string getLatitude();

    string getLongitude();
};

Airport::Airport(string airportId, string name, string city, string country, string iata, string icao, string latitude, string longitude)
{

    this->Airport_ID = airportId;
    this->Name = name;
    this->City = city;
    this->Country = country;
    this->IATA = iata;
    this->ICAO = icao;
    this->Latitude = latitude;
    this->Longitude = longitude;
}

string Airport::getAirportId()
{
    return Airport_ID;
}

string Airport::getName()
{
    return Name;
}

string Airport::getCity()
{
    return City;
}

string Airport::getCountry()
{
    return Country;
}

string Airport::getIata()
{
    return IATA;
}

string Airport::getIcao()
{
    return ICAO;
}

string Airport::getLatitude()
{
    return Latitude;
}

string Airport::getLongitude()
{
    return Longitude;
}

string Airport::to_string()
{
    return "ID: " + getAirportId() + ", Name: " + getName() + " IATO: " + getIata();
}
