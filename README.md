# Hospital Emergency Triage Management System

## 1. Introduction

The Hospital Emergency Triage Management System is a
menu-driven C++ application designed to simulate the
management of patients in a hospital emergency department.

Patients are registered and assigned priority levels
according to the urgency assigned by hospital staff.

The system uses a Priority Queue implemented using
a Min-Heap to determine which patient should be called next.

## 2. Problem Statement

In a hospital emergency department, patients arrive
with different levels of medical urgency.

A normal queue processes patients according to arrival
time, which does not account for different urgency levels.

This project implements a priority-based system that
allows patients with higher urgency to be called first.

## 3. Data Structure Used

Priority Queue using Min-Heap.

The Min-Heap is implemented manually using an array
without using the STL priority_queue.

## 4. Features

- Patient registration
- Display waiting patients
- Call next patient
- Search patient by ID
- Update patient priority
- Display next patient
- Handle empty and full heap conditions
- Prevent duplicate patient IDs

## 5. Priority System

| Priority | Meaning |
|----------|---------|
| 1 | Highest urgency |
| 2 | High urgency |
| 3 | Medium urgency |
| 4 | Low urgency |
| 5 | Lowest urgency |

This is an educational simulation.

## 6. Technologies Used

- C++
- Data Structures
- Min-Heap
- Git and GitHub

## 7. Project Structure

Hospital-Emergency-Triage-System/

- include/
  - Patient.h
  - MinHeap.h
- src/
  - main.cpp
  - MinHeap.cpp
- README.md
- AI_LOG.md
- .gitignore

## 8. Time Complexity

| Operation | Complexity |
|-----------|------------|
| Insert Patient | O(log n) |
| Remove Patient | O(log n) |
| Search Patient | O(n) |
| Display Patients | O(n) |
| Update Priority | O(n) |
| Display Next Patient | O(1) |

## 9. Team Members

| Name | USN | Responsibility |
|------|-----|----------------|
| Member 1 | USN | Min-Heap |
| Member 2 | USN | Patient Management |
| Member 3 | USN | Interface and Testing |

## 10. How to Run

Compile using:

g++ -std=c++17 src/main.cpp src/MinHeap.cpp -Iinclude -o hospital

Run:

./hospital

On Windows:

hospital.exe

## 11. Future Enhancements

- Graphical user interface
- Patient history
- Persistent data storage
- Detailed reports