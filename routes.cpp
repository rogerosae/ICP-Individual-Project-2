//
// Created by roger on 29/11/2022.
//
#include <iostream>
using namespace std;


class Routes{
public:
    //member variables for Routes class
    string airlineCode;
    string airlineID;
    string destinationAirportCode;
    int Stops;


    //member functions for Routes class
    string getAirlineCode();
    void setAirlineCode(string airlineCode);

    string getAirlineID();
    void setAirlineID(string airlineID);


    string getDestinationAirportCode();
    void setAirportCode(string destinationAirportCode);


    const int & getStops();
    void setStop(int Stops);


    string toString();

    Routes( string airlineCode, string airlineID,string destinationAirportCode,int Stops){
        this->destinationAirportCode=destinationAirportCode;
        this->airlineCode=airlineCode;
        this->airlineID=airlineID;
        this->Stops=Stops;

    }

    const string &getAirlineId() const;

    void setAirlineId(const string &airlineId);

    void setDestinationAirportCode(const string &destinationAirportCode);

    void setStops(int stops);

};

const string &Routes::getAirlineId() const {
    return airlineID;
}

void Routes::setAirlineId(const string &airlineId) {
    airlineID = airlineId;
}

void Routes::setDestinationAirportCode(const string &destinationAirportCode) {
    Routes::destinationAirportCode = destinationAirportCode;
}

void Routes::setStops(int stops) {
    Stops = stops;
}






