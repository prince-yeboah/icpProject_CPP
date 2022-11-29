#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Airport.c++"
#include "Airline.c++"
#include "route.c++"
#include "Graph.cpp"
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

 /* list of all airports in the city*/
map<string, vector<Airport>> city_airports_map; 
map<string, vector<Airport>>::iterator it;
/* list of all flights that leave the source */
map<string, vector<Airline>> airline_map;
map<string, vector<Airline>>::iterator its;
map<string, string> active_flights;  
map<string, vector<Routes>> routes_map; 
map<string, vector<Routes>>::iterator itr;
vector<Airport> all_airports;
vector<Airline> all_airlines;
vector<Routes> all_routes;

void airportFileReader(string filename)
{

    ifstream inputStream;
    inputStream.open("airports.csv");

    if (inputStream.fail())
    {
        cout << "Couldn't open the file!" << endl;
    }

    string line = "";
    getline(inputStream, line);
    while (getline(inputStream, line))
    {
        string Airport_ID;
        string Name;
        string City;
        string Country;
        string IATA;
        string ICAO;
        string Latitude;
        string Longitude;
        stringstream inputString(line);
        /*using getline to read from the file separating each column with a , */
        getline(inputString, Airport_ID, ',');
        getline(inputString, Name, ',');
        getline(inputString, City, ',');
        getline(inputString, Country, ',');
        getline(inputString, IATA, ',');
        getline(inputString, ICAO, ',');
        getline(inputString, Latitude, ',');
        getline(inputString, Longitude, ',');

        Airport new_airport(Airport_ID, Name, City, Country, IATA, ICAO, Latitude, Longitude);

        all_airports.push_back(new_airport);
        string airport_city_key = new_airport.getCity() + "," + " " + new_airport.getCountry();

        it = city_airports_map.find(airport_city_key);
        if (it != city_airports_map.end())
        {
            it->second.push_back(new_airport);
        }
        else
        {
            vector<Airport> new_airport_list;
            new_airport_list.push_back(new_airport);
            city_airports_map.insert({airport_city_key, new_airport_list});
        }

        line = "";
    }
    inputStream.close();
}

void airlineFileReader(string filename)
{
    ifstream inputStream;
    inputStream.open("airlines.csv");

    if (inputStream.fail())
    {
        cout << "Couldn't open the file!" << endl;
    }

    string line = "";
    getline(inputStream, line);
    while (getline(inputStream, line))
    {
        string Airline_ID;
        string Name;
        string Alias;
        string IATA;
        string ICAO;
        string Callsign;
        string Country;
        string Active;

        stringstream inputString(line);
        /*using getline to read from the file separating each column with a , */
        getline(inputString, Airline_ID, ',');
        getline(inputString, Name, ',');
        getline(inputString, Alias, ',');
        getline(inputString, IATA, ',');
        getline(inputString, ICAO, ',');
        getline(inputString, Callsign, ',');
        getline(inputString, Country, ',');
        getline(inputString, Active, ',');

        Airline new_airline(Airline_ID, Name, Alias, IATA, ICAO, Callsign, Country, Active);
        all_airlines.push_back(new_airline);

        its = airline_map.find(new_airline.getAirlineId());
        if (its != airline_map.end())
        {
            its->second.push_back(new_airline);
        }
        else
        {
            vector<Airline> new_airline_list;
            new_airline_list.push_back(new_airline);
            airline_map.insert({new_airline.getAirlineId(), new_airline_list});
        }

        if (new_airline.isActive() == "Y")
        {
            active_flights.insert({new_airline.getAirlineId(), new_airline.getIata()});
        }
    }

    inputStream.close();
}

void routeFileReader(string filename)
{
    ifstream inputStream;
    inputStream.open("routes.csv");

    if (inputStream.fail())
    {
        cout << "Couldn't open the file!" << endl;
    }

    string line = "";
    getline(inputStream, line);
    while (getline(inputStream, line))
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

        stringstream inputString(line);
        getline(inputString, Airline, ',');
        getline(inputString, Airline_ID, ',');
        getline(inputString, Source_Airport, ',');
        getline(inputString, Source_Airport_ID, ',');
        getline(inputString, Destination_Airport, ',');
        getline(inputString, Destination_Airport_ID, ',');
        getline(inputString, Codeshare, ',');
        getline(inputString, Stops, ',');
        getline(inputString, Equipment, ',');

        Routes new_route(Airline, Airline_ID, Source_Airport, Source_Airport_ID, Destination_Airport, Destination_Airport_ID, Codeshare, Stops, Equipment);

        all_routes.push_back(new_route);

        itr = routes_map.find(new_route.getSourceAirport());
        if (itr != routes_map.end())
        {
            itr->second.push_back(new_route);
        }
        else
        {
            vector<Routes> new_route_list;
            new_route_list.push_back(new_route);
            routes_map.insert({new_route.getSourceAirport(), new_route_list});
        }
    }
    inputStream.close();
}

vector<string> readInputfile(string inputfile)
{
    string cities[2];
    string countries[2];
    vector<string> flight;

    ifstream inputStream;
    inputStream.open(inputfile);

    if (inputStream.fail())
    {
        cout << "Couldn't open the file!" << endl;
    }

    int count = 0;
    string line = "";
    while (getline(inputStream, line))
    {
        string city;
        string country;
        stringstream inputString(line);
        getline(inputString, city, ',');
        getline(inputString, country, ',');

        cities[count] = city;
        countries[count] = country;

        count++;
    }
    inputStream.close();
    flight.push_back(cities[0]);
    flight.push_back(cities[1]);
    flight.push_back(countries[0]);
    flight.push_back(countries[1]);
    return flight;
}

string getInput()
{
    string inputfile = "";
    cout << "Enter a file name: " << endl;
    cin >> inputfile;
    return inputfile;
}

int main(int argc, const char **argv)
{
    vector<string> flight_path = readInputfile(getInput());
    string start_city = flight_path[0];
    string start_country = flight_path[2];
    string dest_city = flight_path[1];
    string dest_country = flight_path[3];

    airportFileReader("airports.csv");
    airlineFileReader("airlines.csv");
    routeFileReader("routes.csv");
    return 0;
}