//
// Created by Roger Osae on 29/11/2022.
//
#include <iostream>

using namespace std;

class Airlines{
public:
    //member variables for the Airlines class
    string airline_id;
    string name;
    string alias;
    string iatacode;
    string iacocode;
    string callsign;
    string country;
    string active;

    //member functions for the Airport class
    string getAirlineID();
    void setAirlineID(string airline_id);

    string getAirlineName();
    void setAirlineName(string name);

    string getAlias();
    void setAlias(string alias);

    string getIacoCode();
    void setIacoCode(string iacocode);

    string getIataCode();
    void setIataCode(string iatacode);

    string getCallsign();
    void setCallsign(string callsign);

    string getCountry();
    void setCountry(string country);

    string getActiveState();
    void setActiveState(string active);

    string toString();

    Airlines(string airline_id,string name,string alias,string iatacode,string iacocode,string callsign,string country,string active ){
        this->airline_id=airline_id;
        this->name=name;
        this->alias=alias;
        this->active=active;
        this->callsign=callsign;
        this->country=country;
        this->iacocode=iacocode;
        this->iatacode=iatacode;
    }

    const string &getAirlineId() const;

    void setAirlineId(const string &airlineId);

    const string &getName() const;

    void setName(const string &name);

    const string &getIatacode() const;

    void setIatacode(const string &iatacode);

    const string &getIacocode() const;

    void setIacocode(const string &iacocode);

    const string &getActive() const;

    void setActive(const string &active);
};

const string &Airlines::getAirlineId() const {
    return airline_id;
}

void Airlines::setAirlineId(const string &airlineId) {
    airline_id = airlineId;
}

const string &Airlines::getName() const {
    return name;
}

void Airlines::setName(const string &name) {
    Airlines::name = name;
}

const string &Airlines::getIatacode() const {
    return iatacode;
}

void Airlines::setIatacode(const string &iatacode) {
    Airlines::iatacode = iatacode;
}

const string &Airlines::getIacocode() const {
    return iacocode;
}

void Airlines::setIacocode(const string &iacocode) {
    Airlines::iacocode = iacocode;
}

const string &Airlines::getActive() const {
    return active;
}

void Airlines::setActive(const string &active) {
    Airlines::active = active;
}
string Airlines:: toString(){
    return this->airline_id + " " + active + " "+country + " " + alias + " " + iatacode+" "+iacocode+" "+callsign+" "+name;
}




