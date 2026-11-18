#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

struct Patient
{
    int id;
    string name;
    string condition;
    int priority;
    int arrivalOrder;
};

#endif