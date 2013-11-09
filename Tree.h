// Filename: Tree.h
// Date Created: 16/10/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#ifndef LANCE_TREE_H
#define LANCE_TREE_H
namespace lance_project {
	template <class T>
	class Tree {
		public:
			// The default constructor for the Tree.
			Tree();
			// The print method is recursive. It iteratively invokes
			// the same method passing it the left & right node to traverse
			// down a branch. It prints out the data contained in the node.
			void print(Node<T>* node);
			// The insert method receives an item, and adds it to the tree. It 
			// positions the generic item based on a compareTo method that must be
			// in the object. It uses the private add method recursively.
			void insert(T* item);
			// The remove method removes and item in the tree. It uses the remove method
			// in the Node class recursively.
			void remove(T* item);
			// The search method finds an item in the tree, and returns the data. It is a recursive
			// method which traverses the list based on the compareTo method belonging to the data class.
			T* search(Node<T>* node, T* item);
			// The calcSearchDepth method is recursive, counting the amount it takes to find a specific item.
			// It returns the total comparisons it takes.
			int calcSearchDepth(Node<T>* node, T* item, int depth);
			// Setter for the root node.
			void setRoot(Node<T>* root);
			// Getter for the root node.
			Node<T>* getRoot();
			// Getter for the size.
			int getSize();
		private:
			int size;
			Node<T>* root;
			// The add method is recursive which gets invoked by the insert method.
			void add(Node<T>* node, T* item);
	};
}
#include "Tree.template"
#endif
