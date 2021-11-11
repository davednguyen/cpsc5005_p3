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

    //in driver files may need to save patients
    //priority code base on arrival
    //overloaded operators in order to properly add, peek, and remove patients from the waiting room,
    //example: void operator= (const SomeClass &rval);

    //default contruucstor
    //overloaded operators ==, overload < and > operators
    //setter and getters

private:
    //variables
    string name;
    //string priorityCode;
    int priorityCode;
    int arrivalOrder;

};


#endif //P3_PATIENT_H
