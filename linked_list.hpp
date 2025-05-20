#ifndef LINKEDLIST_HPP      //Checks to see if any header files have been declared under this name
#define LINKEDLIST_HPP      //If no other files exist then this code defines the header file 

#include <iostream>      //Includes the iostream library for input and output

struct Node {
    public:
        // Key and value identifiers for the node class
        int key;
        double value;

        // Pointer to the next node
        Node* next;

        // Constructor and Destructor
        Node(int key, double value);
        ~Node();

};

class LinkedList {                                                                                                                                                                                                                                                                                                                                                                                                      private:
        Node* head;
    public:
        // Constructor and Destructor
        LinkedList();
        ~LinkedList();

        // Returns the head node.
        Node* get_head() const;

        // Adds a node to the front of the list.
        void push_front(int key, double value);

        // Adds a node to the back of the list.
        void push_back(int key, double value);

        // Inserts a node at a specific index.
        void insert(int key, double value, int index);

        // Searches for a node by key.
        double search(int key) const;

        // Returns the Node at a specific index.
        Node* at(int index) const;

        // Returns the size of the node
        int size() const;

        // Removes a node 
        bool remove(int val);

        // Removes a node by key
        bool remove_key(int key);

        // Removes a node by value
        bool remove_value(double value);

        // Prints the list 
        void print() const;

        // Sorts the list using selection sorting
        void selection_sort();

        // Sorts the list using bubble sorting
        void bubble_sort();

};

#endif      //Ends the header file