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
    void add(Patient);
    string peek() const;
    void next();
    string remove();
    void list();
    int Size();
    int getHighestPriorityCode();
    string to_string();

private:
    int count;
    int size;
    int capacity;
    vector<Patient> patients;
    int highestPriorityCode;
    void siftUp(Patient);
    void siftDown(Patient);
    Patient getParent(Patient) const;
    Patient getLeftChild(Patient) const;
    Patient getRightChild(Patient) const;
    void updatePriorityCode();
};

/*
 *
 */
PatientPriorityQueue::PatientPriorityQueue() {
    size = 1;
    capacity = 0;
    highestPriorityCode = 4;
    count = 1;
}

/*
 *
 */
string PatientPriorityQueue::peek() const {
    stringstream ss;
    for(int i = 0; i < patients.size(); i++){
        Patient patient = patients[i];
        if(patient.getPriorityCode() == highestPriorityCode){
            ss  <<"Highest priority patient to be called next: " << patient.getName();
        }
    }
    return ss.str();
}

/*
 *
 */
string PatientPriorityQueue::to_string() {
    stringstream ss;
    for(int j = 1; j <= 4; j++){
        for(int i = 0; i < patients.size(); i++){
            Patient patient = patients[i];
            if(patient.getPriorityCode() == j){
                ss  << patient.to_string() << endl;
            }
        }
    }
    return ss.str();
}

/*
 *
 */
void PatientPriorityQueue::add(Patient newPatient) {

    newPatient.setArrivalOrder(count);
    patients.push_back(newPatient);
    count++;
    size++;
    updatePriorityCode();
}

/*
 *
 */
string PatientPriorityQueue::remove() {

   stringstream ss;
   if(patients.size() > 0)
   for(int i = 0; i < patients.size(); i++){
       if (patients[i].getPriorityCode() == highestPriorityCode){
           vector<Patient>::iterator it;
           it = patients.begin() + i;
           ss << "This patient will now be seen: " << it->getName();
           patients.erase(it);
           highestPriorityCode = 4;
           updatePriorityCode();
           size--;
       }
   }else{
       ss << "There are no patients in the waiting area.";
   }
   return ss.str();
}

/*
 *
 */
int PatientPriorityQueue::Size() {
    return patients.size();
}

/*
 *
 */
int PatientPriorityQueue::getHighestPriorityCode() {
    return highestPriorityCode;
}
void PatientPriorityQueue::updatePriorityCode()  {
    if(patients.size() > 0){
        for(int i = 0; i < patients.size(); i++){
            if(patients[i].getPriorityCode() < highestPriorityCode){
                    highestPriorityCode = patients[i].getPriorityCode();
            }
        }
    }
}
#endif //P3_PATIENTPRIORITYQUEUE_H

