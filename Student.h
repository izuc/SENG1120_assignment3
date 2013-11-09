// Filename: Student.h
// Date Created: 16/10/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#ifndef LANCE_STUDENT_H
#define LANCE_STUDENT_H
namespace lance_project {
	class Student {
		public:
			// The default constructor.
			Student();
			// The constructor receives the name.
			Student(std::string name);
			// The constructor recieves the name, and grade.
			Student(std::string name, float grade);
			// Setter for the name.
			void setName(std::string name);
			// Setter for the grade.
			void setGrade(float grade);
			// Getter for the name.
			std::string getName();
			// Getter for the grade.
			float getGrade();
			// The compareTo method compares the received object.
			// Returns a 0 if they match, a negative number if the object
			// is considered smaller, or a greater number if the object is greater.
			int compareTo(Student* student);
		private:
			std::string name; // Students name.
			float grade; // Students grade.
	};
	// Overloaded print operator, which prints out the student's name & grade.
	std::ostream & operator<<(std::ostream & out, Student* student);
}
#endif
