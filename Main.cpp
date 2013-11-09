// Filename: Main.cpp
// Date Created: 16/10/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#include <iostream>
#include <cstdlib>
#include "Student.h"
#include "Node.h"
#include "Tree.h"

using namespace std;
using lance_project::Student;
using lance_project::Node;
using lance_project::Tree;

// The shuffle method randomises the elements
// of the received string array. 
void shuffle(string values[], int size) {
	string temp;
	int random, last;
	// Iterates throughout the indices, starting at
	// the length of the array, decrementing with
	// each iteration.
	for (last = size; last > 1; last--) {
		// calculates a random index with the max value of the last variable.
		random = rand() % last;
		// Swaps the last element with the random element.
		temp = values[random];
		values[random] = values[last - 1];
		values[last - 1] = temp;
	}
}

// The printHDStudents is a recursive method,
// that prints out students with a grade >= 85.
void printHDStudents(Node<Student>* node) {
	if (node != NULL) {
		// Traverses through to the left node.
		printHDStudents(node->getLeft());
		// If the current node's student object has
		// a grade >= 85, it will print out the data.
		if (node->getData()->getGrade() >= 85) {
			cout << node->getData() << endl;
		}
		// Traverses through to the right node.
		printHDStudents(node->getRight());
	}
}

// The remove method iterates throughout the received string name values, and searches
// the tree based on the name. If a student is found & the grade is less than 50, it then
// removes the object from the tree.
void remove(Tree<Student>* tree, string values[], int size) {
	for (int i = 0; i < size; i++) { // Iterates throughout the name array.
		// Searches for the name within the tree.
		Student* student = tree->search(tree->getRoot(), new Student(values[i]));
		if (student != NULL) { // If the student is found
			if (student->getGrade() < 50) { // and the grade is less than 50
				tree->remove(student); // removes the object from the tree.
			}
		}
	}
}

// The getTotalGrades is a recursive method that traverses the entire tree, adding
// the grades with each invocation.
float getTotalGrades(Node<Student>* node) {
	float total = 0; // default value.
	if (node != NULL) {
		// sets the total to the grade.
		total = node->getData()->getGrade();
		// traverses down the left branch, adding the returned total
		total += getTotalGrades(node->getLeft());
		// traverses down the right branch, adding the returned total
		total += getTotalGrades(node->getRight());
	}
	return total; // returns the total.
}

// The comparisons method is used to add the total amount of comparisons it takes
// to find a specific node. It traverses the entire tree, invoking the calcSearchDepth
// method to find the amount it takes.
int comparisons(Tree<Student>* tree, Node<Student>* node) {
	int total = 0;
	if (node != NULL) {
		// Sets the total to the returned value from the calcSearchDepth method.
		total = tree->calcSearchDepth(tree->getRoot(), node->getData());
		// traverses down the left branch, adding the returned total 
		total += comparisons(tree, node->getLeft());
		// traverses down the right branch, adding the returned total
		total += comparisons(tree, node->getRight());
	}
	return total; // returns the total.
}

// The calcAvgGrades method invokes the getTotalGrades method. It divides
// the result with the size of the tree.
void calcAvgGrades(Tree<Student>* tree) {
	cout << (getTotalGrades(tree->getRoot()) / tree->getSize()) << endl;
}

// The calcAvgComparisons method invokes the comparisons method. It divides
// the result with the size of the tree. 
void calcAvgComparisons(Tree<Student>* tree) {
	cout << (comparisons(tree, tree->getRoot()) / tree->getSize()) << endl;
}

int main() {
	const int size = 50;
	string values[] = {"Adam", "Adrian", "Alexander", "Andrew", "Ashley", "Benjamin", "Bradley", "Brobie", "Callan",
						"Callum", "Cameron", "Chris", "Damian", "David", "Dillon", "Dylan", "Ethan", "Frederik",
						"Hong", "Hugh", "Jackson", "Jacob", "James", "Jared", "Jodi", "Jonathan", "Joshua", "Julius",
						"Kelly", "Kenias", "KiSoon", "Lance", "Liam", "Madison", "Magdalena", "Marcus", "Mark", "Melanie",
						"Min", "Mitchell", "Nicholas", "Ryan", "Sang", "Shane", "Simon", "Thomas", "Timothy", "Trent",
						"Troy", "Zannif"};
	
	// Prompts to enter a seed.
	int seed;
	cout << "Please enter a seed: ";
	cin >> seed;
	
	srand(seed); // Seeds the random number generator with the entered value.
	shuffle(values, size); // Shuffles the elements in the array.
	// Instantiates a tree.
	Tree<Student>* tree = new Tree<Student>();
	// Iterates for each name in the list.
	for (int i = 0; i < size; i++) {
		// Instantiates a student with the name, and a random grade.
		// Adds the student to the tree.
		tree->insert(new Student(values[i], rand() % 100));
	}
	
	// Performs step 3, printing out the entire tree.
	cout << "------------------------------------------------" << endl;
	cout << "Step 3) Print out all names and grades" << endl;
	cout << "------------------------------------------------" << endl;
	tree->print(tree->getRoot());
	
	// Performs step 4, printing out students with a grade >= 85.
	cout << "------------------------------------------------" << endl;
	cout << "Step 4) Print out students with a grade >= 85." << endl;
	cout << "------------------------------------------------" << endl;
	printHDStudents(tree->getRoot());
	
	// Performs step 5, printing out the average grade of the class.
	cout << "------------------------------------------------" << endl;
	cout << "Step 5) Print out the average grade of the class." << endl;
	cout << "------------------------------------------------" << endl;
	calcAvgGrades(tree);
	
	// Performs step 6, average amount of comparisons it takes to find a student.
	cout << "------------------------------------------------" << endl;
	cout << "Step 6) Count the average number of comparisons." << endl;
	cout << "------------------------------------------------" << endl;
	calcAvgComparisons(tree);
	
	// Performs step 7, deletes students with grades < 50.
	cout << "------------------------------------------------" << endl;
	cout << "Step 7) Delete students with a grade < 50." << endl;
	cout << "------------------------------------------------" << endl;
	remove(tree, values, size);
	tree->print(tree->getRoot());
	cout << endl << "Average grade: ";
	calcAvgGrades(tree);
	
	// Performs step 8, redoes step 6 (calculating the average comparisons).
	cout << "------------------------------------------------" << endl;
	cout << "Step 8) Redo step 6, average comparisons." << endl;
	cout << "------------------------------------------------" << endl;
	calcAvgComparisons(tree);
	return 0;
}
