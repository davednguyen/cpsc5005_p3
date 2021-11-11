//
// Created by dzzn on 11/8/2021.
//

#ifndef P3_PATIENT_H
#define P3_PATIENT_H
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


class Patient {
public:
    Patient();
    Patient(string, int);
    string to_string();
    void add (string, int);
    string to_string() const;
    //overloaded operators
    void setPriorityCode(int);
    void setArrivalOrder(int);
    int getPriorityCode();

    Patient operator + (const Patient &); // Overloaded +
    Patient operator - (const Patient &); // Overloaded -
    Patient operator ++ ();				    // Prefix ++
    Patient operator ++ (int);			    // Postfix ++
    bool operator > (Patient);		// Overloaded >
    bool operator < (Patient);		// Overloaded <
    bool operator == (Patient);		// Overloaded ==

    //in driver files may need to save patients
    //priority code base on arrival
    //overloaded operators in order to properly add, peek, and remove patients from the waiting room,
    //example: void operator= (const SomeClass &rval);

    //default contruucstor
    //overloaded operators ==, overload < and > operators
    //setter and getters
    // Overloaded operator functions


private:
    //variables
    string name;
    //string priorityCode;
    int priorityCode;
    int arrivalOrder;

};

/*
 *
 */
Patient::Patient(string name, int code) {
    this->name = name;
    this->priorityCode = code;
}

/*
 *
 */
string Patient::to_string() {
    stringstream  ss;
    ss << "Name: " << name << " priority code: " << priorityCode ;
    return ss.str();
}

/*
 *
 */
int Patient::getPriorityCode() {
    return priorityCode;
}

/*
 *
 */
void Patient::setPriorityCode(int code) {
    priorityCode = code;
}

/*
 *
 */
void Patient::setArrivalOrder(int order) {
    arrivalOrder = order;
}

/*
 *
 */
bool Patient::operator == (Patient patient)
{
    if(priorityCode == patient.getPriorityCode())
    {
        return true;
    }else{
        return false;
    }
}

/*
 *
 */
bool Patient::operator < (Patient patient) {
    if(priorityCode < patient.getPriorityCode())
    {
        return true;
    }else{
        return false;
    }
}

/*
 *
 */
bool Patient::operator > (Patient patient)
{
    if(priorityCode > patient.getPriorityCode())
    {
        return true;
    }else{
        return false;
    }
}
#endif //P3_PATIENT_H
