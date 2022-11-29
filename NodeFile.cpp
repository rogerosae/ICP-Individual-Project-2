//
// Created by Roger Osae on 29/11/2022.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <hashtable.h>
#include "routes.cpp"
using namespace std;

class NodeFile{
private:
    NodeFile *node_parent;
    string sourceAirportCode;
    string airlineCode;
    int Stop;
    vector<Routes>successors;

public:

    NodeFile(NodeFile *node_parent, string sourceAirportCode, string airlineCode, int Stop, vector<Routes>successors) {
        this->node_parent = node_parent;
        this->sourceAirportCode = sourceAirportCode;
        this->airlineCode = airlineCode;
        this->Stop = Stop;
        this->successors = successors;
    }
    string to_string();
    bool operator==(const NodeFile &obj);
    int hashCode();

    NodeFile getParentNode();
    void setParentNode(NodeFile *node_parent);

    string getAirportCode();
    void setAirportCode(string sourceAirportCode);

    string getAirlineCode();
    void setAirlineCode(string airlineCode);

    int getStops();
    void setStops(int Stop);

    vector<Routes> getSuccessors();
    void setSuccessors(vector<Routes> successors);


    vector<string> solutionPath();
};
string NodeFile:: to_string(){
    return "Node{parentNode= ", *node_parent,
            ", airportCode='" + sourceAirportCode + '\'' +
            ", airlineCode='" + airlineCode + '\'' +
            ", stops=", Stop,
            ", successors=", successors,
            "}";
}
bool NodeFile:: operator==(const NodeFile &obj){

    if (*this == obj) {
        return true;
    }
    if (&obj == NULL || typeid(obj) != typeid(this)){
        return false;
    }
    NodeFile node = (NodeFile) obj;
    return  node_parent==node.node_parent && sourceAirportCode==node.sourceAirportCode
            && airlineCode==node.airlineCode && successors==node.successors && Stop == node.Stop;
}
int NodeFile:: hashCode(){
    return hash(*node_parent, sourceAirportCode, airlineCode, Stop, successors);
}

NodeFile NodeFile:: getParentNode() {
    return *node_parent;
}

void NodeFile:: setParentNode(NodeFile *node_parent) {
    this->node_parent = node_parent;
}

string NodeFile:: getAirportCode() {
    return sourceAirportCode;
}

void NodeFile:: setAirportCode(string sourceAirportCode) {
    this->sourceAirportCode = sourceAirportCode;
}

string NodeFile:: getAirlineCode() {
    return airlineCode;
}

void NodeFile:: setAirlineCode(string airlineCode) {
    this->airlineCode = airlineCode;
}

int NodeFile:: getStops() {
    return Stop;
}

void NodeFile:: setStops(int stops) {
    this->Stop = Stop;
}

vector<Routes> NodeFile:: getSuccessors() {
    return successors;
}

void NodeFile:: setSuccessors(vector<Routes> successors) {
    this->successors = successors;
}
vector<string> NodeFile:: solutionPath(){
    vector<string> airportCodes;
    vector<string> airlineCodes;
    vector<string> solution;
    vector<int> Stop;
    NodeFile thisNode = *this;

    while(&thisNode != NULL){
        airlineCodes.push_back(thisNode.getAirlineCode());
        airportCodes.push_back(thisNode.getAirportCode());
        Stop.push_back(thisNode.getStops());
        thisNode = *thisNode.node_parent;
    }
    reverse(airlineCodes.begin(), airlineCodes.end());
    reverse(airportCodes.begin(), airportCodes.end());

    for (int i = 0;i < airlineCodes.size()-1;i++){
        string result = airlineCodes.at(i+1) + " from " + airportCodes.at(i) + " to " +
                        airportCodes.at(i+1) + " " +Stop.at(i) + " stops.";
        solution.push_back(result);
    }

    return solution;

}

