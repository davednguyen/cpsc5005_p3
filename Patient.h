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
    string to_string();

private:
    //variables
    string name;
    string priorityCode;
    int arrivalOrder;

};


#endif //P3_PATIENT_H
