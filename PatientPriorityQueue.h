//
// Created by dzzn on 11/11/2021.
//

#ifndef P3_PATIENTPRIORITYQUEUE_H
#define P3_PATIENTPRIORITYQUEUE_H

#include <vector>
#include "Patient.h"
#include <cassert>
#include <string>

using namespace std;

class PatientPriorityQueue{
public:
    PatientPriorityQueue();
    //~PatientPriorityQueue();
    int add(Patient);
    Patient peek() const;
    //int peek() const;
    //int peek();
    void next();
    void remove();
    void list();

private:
    int size;
    int capacity;
    vector<Patient> patients;
    void siftUp(Patient);
    void siftDown(Patient);
    Patient getParent(Patient) const;
    Patient getLeftChild(Patient) const;
    Patient getRightChild(Patient) const;

};

/*
 *
 */
PatientPriorityQueue::PatientPriorityQueue() {
    size = 0;
    capacity = 0;
}
Patient PatientPriorityQueue::peek() const {
//int PatientPriorityQueue::peek() const {
//    assert(!empty());
    //return patients.at(0);
    return patients.front();
    //return patients.back();
    //return patients.size();
}

int PatientPriorityQueue::add(Patient newPatient) {

    newPatient.setArrivalOrder(size);
    patients.push_back(newPatient);
    return patients.size();
}


#endif //P3_PATIENTPRIORITYQUEUE_H

