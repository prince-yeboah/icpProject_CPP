#include <string>
using namespace std;

class Airline
{
private:
    string Airline_ID;
    string Name;
    string Alias;
    string IATA;
    string ICAO;
    string Callsign;
    string Country;
    string Active;

public:
    Airline(string, string, string, string, string, string, string, string);

public:
    string getAirlineId();
    string getName();
    string getAlias();
    string getIata();
    string getIcao();
    string getCallsign();
    string getCountry();
    string isActive();
    string to_string();
};

Airline::Airline(string Airline_ID, string Name, string Alias, string IATA, string ICAO,
                 string Callsign, string Country, string Active)
{
    this->Airline_ID = Airline_ID;
    this->Name = Name;
    this->Alias = Alias;
    this->IATA = IATA;
    this->ICAO = ICAO;
    this->Callsign = Callsign;
    this->Country = Country;
    this->Active = Active;
}

string Airline::getAirlineId()
{
    return Airline_ID;
}

string Airline::getName()
{
    return Name;
}

string Airline::getAlias()
{
    return Alias;
}

string Airline::getIata()
{
    return IATA;
}

string Airline::getIcao()
{
    return ICAO;
}

string Airline::getCallsign()
{
    return Callsign;
}

string Airline::getCountry()
{
    return Country;
}

string Airline::isActive()
{
    return Active;
}

string Airline::to_string()
{
    return "ID: " + getAirlineId() + ", Name: " + getName() + ", Active Status: " + isActive();
}