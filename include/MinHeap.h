#ifndef MINHEAP_H
#define MINHEAP_H

#include "Patient.h"

class MinHeap
{
private:

    static const int MAX_SIZE = 100;

    Patient heap[MAX_SIZE];

    int size;
    int arrivalCounter;

    void heapifyUp(int index);

    void heapifyDown(int index);

    int findPatientIndex(int id);

    bool hasHigherPriority(const Patient& a,
                           const Patient& b);

public:

    MinHeap();

    bool insertPatient(Patient p);

    bool removeNextPatient(Patient& p);

    void displayPatients();

    bool searchPatient(int id);

    bool updatePriority(int id, int newPriority);

    bool displayNextPatient();

    bool isEmpty();

    bool isFull();
};

#endif