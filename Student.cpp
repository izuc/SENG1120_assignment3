// Filename: Student.cpp
// Date Created: 16/10/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#include<iostream>
#include<cstdlib>
#include "Student.h"

using namespace std;
using lance_project::Student;

namespace lance_project {

	// The default constructor.
	Student::Student() {
	
	}
	
	// The constructor accepts the name.
	Student::Student(string name) {
		this->name = name;
	}
	
	// The constructor accepts the name, and grade.
	Student::Student(string name, float grade) {
		this->name = name;
		this->grade = grade;
	}
	
	// Setter for the name attribute.
	void Student::setName(string name) {
		this->name = name;
	}
	
	// Setter for the grade attribute.
	void Student::setGrade(float grade) {
		this->grade = grade;
	}
	
	// Getter for the name attribute.
	string Student::getName() {
		return this->name;
	}
	
	// Getter for the grade attribute.
	float Student::getGrade() {
		return this->grade;
	}
	
	// The compareTo method receives a Student to compare the name with.
	int Student::compareTo(Student* student) {
		return this->getName().compare(student->getName());
	}
	
	// The overloaded print operator, prints out the name & grade.
	ostream & operator<<(ostream & out, Student* student) {
		out << student->getName() << " " << student->getGrade();
		return out;
	}
}
