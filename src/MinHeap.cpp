#include <iostream>
#include "MinHeap.h"

using namespace std;

// Constructor
MinHeap::MinHeap()
{
    size = 0;
    arrivalCounter = 0;
}

// Check whether heap is empty
bool MinHeap::isEmpty()
{
    return size == 0;
}

// Check whether heap is full
bool MinHeap::isFull()
{
    return size == MAX_SIZE;
}

// Compare two patients
bool MinHeap::hasHigherPriority(const Patient& a,
                               const Patient& b)
{
    if (a.priority != b.priority)
        return a.priority < b.priority;

    return a.arrivalOrder < b.arrivalOrder;
}

// Find patient index
int MinHeap::findPatientIndex(int id)
{
    for (int i = 0; i < size; i++)
    {
        if (heap[i].id == id)
            return i;
    }

    return -1;
}

// Insert patient
bool MinHeap::insertPatient(Patient p)
{
    if (isFull() || findPatientIndex(p.id) != -1)
        return false;

    p.arrivalOrder = arrivalCounter++;

    heap[size] = p;

    heapifyUp(size);

    size++;

    return true;
}

// Heapify Up
void MinHeap::heapifyUp(int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (hasHigherPriority(heap[index], heap[parent]))
        {
            swap(heap[index], heap[parent]);

            index = parent;
        }
        else
        {
            break;
        }
    }
}

// Heapify Down
void MinHeap::heapifyDown(int index)
{
    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        int smallest = index;

        if (left < size &&
            hasHigherPriority(heap[left], heap[smallest]))
        {
            smallest = left;
        }

        if (right < size &&
            hasHigherPriority(heap[right], heap[smallest]))
        {
            smallest = right;
        }

        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);

            index = smallest;
        }
        else
        {
            break;
        }
    }
}

// Remove next patient
bool MinHeap::removeNextPatient(Patient& p)
{
    if (isEmpty())
        return false;

    p = heap[0];

    heap[0] = heap[size - 1];

    size--;

    if (!isEmpty())
        heapifyDown(0);

    return true;
}

// Display all patients
void MinHeap::displayPatients()
{
    if (isEmpty())
    {
        cout << "\nNo patients waiting.\n";
        return;
    }

    cout << "\n--- WAITING PATIENTS ---\n";

    for (int i = 0; i < size; i++)
    {
        cout << "\nID: " << heap[i].id;
        cout << "\nName: " << heap[i].name;
        cout << "\nCondition: " << heap[i].condition;
        cout << "\nPriority: " << heap[i].priority;
        cout << "\n----------------------\n";
    }
}

// Search patient
bool MinHeap::searchPatient(int id)
{
    int index = findPatientIndex(id);

    if (index == -1)
        return false;

    cout << "\nPatient Found!\n";

    cout << "ID: " << heap[index].id << endl;
    cout << "Name: " << heap[index].name << endl;
    cout << "Condition: " << heap[index].condition << endl;
    cout << "Priority: " << heap[index].priority << endl;

    return true;
}

// Update patient priority
bool MinHeap::updatePriority(int id, int newPriority)
{
    int index = findPatientIndex(id);

    if (index == -1)
        return false;

    heap[index].priority = newPriority;

    if (index > 0 &&
        hasHigherPriority(heap[index],
                          heap[(index - 1) / 2]))
    {
        heapifyUp(index);
    }
    else
    {
        heapifyDown(index);
    }

    return true;
}

// Display next patient
bool MinHeap::displayNextPatient()
{
    if (isEmpty())
        return false;

    cout << "\n--- NEXT PATIENT ---\n";

    cout << "ID: " << heap[0].id << endl;
    cout << "Name: " << heap[0].name << endl;
    cout << "Condition: " << heap[0].condition << endl;
    cout << "Priority: " << heap[0].priority << endl;

    return true;
}