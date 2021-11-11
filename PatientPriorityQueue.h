//
// Created by dzzn on 11/8/2021.
//
#include <vector>
#include "Patient.h"

#ifndef P3_PATIENTPRIORITYQUEUE_H
#define P3_PATIENTPRIORITYQUEUE_H


class PatientPriorityQueue {
    //arrival number assigned by priority queue
    //arriavle
public:
    PatientPriorityQueue();
    void add(Patient &);


private:
    vector<Patient> patients;
    int count;
};

/*
 *
 */
PatientPriorityQueue::PatientPriorityQueue() {

}

void PatientPriorityQueue::add(Patient & newPatient) {

    newPatient.setArrivalOrder(count);
    patients.push_back(newPatient);
    count++;
}
#endif //P3_PATIENTPRIORITYQUEUE_H
