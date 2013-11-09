// Filename: Node.h
// Date Created: 16/10/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#ifndef LANCE_NODE_H
#define LANCE_NODE_H
namespace lance_project {
	template <class T>
	class Node {
		public:
			// The default constructor for the Node.
			Node();
			// The constructor recieves the data.
			Node(T* data);
			// The constructor recieves the data, left, and right node.
			Node(T* data, Node<T>* left, Node<T>* right);
			// The destructor destroys the object.
			~Node();
			// The remove object is a recursive method, which removes a specific
			// node matching the received item based on the compareTo method.
			Node<T>* remove(Node<T>* parent, T* item);
			// Setter for the data.
			void setData(T* data);
			// Setter for the left node.
			void setLeft(Node<T>* left);
			// Setter for the right node.
			void setRight(Node<T>* right);
			// Getter for the data.
			T* getData();
			// Getter for the left node.
			Node<T>* getLeft();
			// Getter for the right node.
			Node<T>* getRight();
		private:
			T* data; // The node data.
			Node<T>* left; // The left branch.
			Node<T>* right; // The right branch.
			// A private method used to locate the smallest node, which is
			// used by the remove method.
			T* min(); 
	};
}
#include "Node.template"
#endif
