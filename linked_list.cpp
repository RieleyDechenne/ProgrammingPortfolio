#include "linked_list.hpp"
#include <iostream>

// g++ -std=c++11 linked_list.cpp main.cpp -o linked_list
// ./ linked_list


    //Constructor Definition for Node: Initializes the key and value of the node
    // and sets the next pointer to nullptr
Node::Node(int key, double val){
    value = val;
    next = nullptr;
}

    //Deconstructor Declaration for Node: Deletes the next node
Node::~Node(){                 
    if (next!=nullptr) {
		delete next;
		next = nullptr;
	}
}

    //Constructor for LinkedList Declaration: Sets the head pointer to nullptr
LinkedList::LinkedList(){      
    head = nullptr;
}

    //Deconstructor Definition for LinkedList class: Deletes the head node
    // and sets the head pointer to nullptr
LinkedList::~LinkedList(){     
    if(head != nullptr){
        delete head;
        head = nullptr;
    }
}

    //get_head() function definition: Returns the head pointer of the linked list
Node* LinkedList::get_head() const{   
    return head;
}

    //push_front() function definition: Adds a new node to the front of the linked list
void LinkedList::push_front(int key, double value){ 
    //Checks to see if the list is empty, if so, it creates a new node and assigns it to head with key and value      
    if(head == nullptr){
        head = new Node(key, value);
    }
    //If the list is not empty, it creates a new node and sets it as the new head
    else{
        Node* new_node = new Node(key, value);
        new_node->next = head;
        head = new_node;
    }
}

    //push_back() function definition: Adds a new node to the end of the linked list
void LinkedList::push_back(int key, double value){
    //Checks to see if the list is empty, if so, it creates a new node and assigns it to head          
    if(head == nullptr){
        head = new Node(key, value);
    }
    //If the list is not empty, goes through the list and adds the new node to the end
    else{
        Node* iter;
        for(iter = head; iter->next != nullptr; iter = iter->next);
        iter->next = new Node(key, value);
    }
}

    //insert() function definition: Inserts a new node with the given key and value at the specified index
void LinkedList::insert(int key, double value, int index){
    //Checks to see if the list is empty, if so, inserts at the front
    if(head == nullptr){            
        push_front(key, value);
        return;
    }

}

    //at() function definition: Returns the node at the specified index, or nullptr if the index is invalid
Node* LinkedList::at(int index) const{
    if(index < 0){
        return nullptr;
    }
    else{
        int count = 0;
        Node* current = head;
        while(current != nullptr){
            if(count == index){
                return current;
            }
            else{
                count++;
                current = current->next;
            }
        }
        return nullptr;
    }
}

    //size() function definition: Returns the size of the linked list
int LinkedList::size() const{                                 
    int count = 0;
    for(Node* iter = head; iter != nullptr; iter = iter->next){
        count++;
    }
    return count;
}

    //remove() function definition: Removes the first node with the specified value from the linked list
bool LinkedList::remove(int val){
    //Checks to see if the list is empty, if so, returns false
    if(head == nullptr){        
        return false;
    }
    //If the head node contains the value, it removes the head node and updates the head pointer
    if(head->value == val){       
        Node* temp = head;
        head = head->next;
        temp->next = temp;
        delete temp;
        return true;
    }

    Node* iter = head;
    //Iterates through the list to find the node with the specified value
    while(iter-> next != nullptr && iter->next->value != val){
        iter = iter->next;
    }
    //if the node is not found, returns false
    if(iter->next == nullptr){
        return false;
    }
    //If the node is found, removes it from the list and deletes it
    Node* temp = iter->next;
    iter->next = temp->next;
    temp->next = nullptr;
    delete temp;
    return true;

}

    //remove_key() function definition: Removes a node with the specified key from the linked list
bool LinkedList::remove_key(int key){
    //If the list is empty, returns false
    if(head == nullptr){
        return false;
    }
    //If the head node contains the key, it removes the head node and updates the head pointer
    // and deletes the head node, then returns true
    else if (head->key == key){
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return true;
    }
    //If the head node does not contain the key, it iterates through the list to find the node with the specified key
    //If the node is not found, returns false
    else {
        Node* iter = head;
        while(iter->next != nullptr){
            if(iter->next->key == key){
                Node* temp = iter->next;
                iter->next = temp->next;
                temp->next = nullptr;
                delete temp;
                return true;
            }
            else{
                iter = iter->next;
            }
        }
        return false;
    }
}

    //remove_value() function definition: Removes a node with the specified value from the linked list
bool LinkedList::remove_value(double value){   
    //If the list is empty, returns false         
    if(head == nullptr){
        return false;
    }
    //If the head node contains the value, it traverses through the list to find the node with the specified value
    else{
        Node* iter;
        for(iter = head; (iter->next->value == value); iter = iter->next){
            Node* temp = iter->next;
            iter->next = temp->next;
            temp->next = temp;
            delete temp;
            return true;
        }
        return true;
    }
}

    //print() function definition: Prints the values of the linked list
void LinkedList::print() const{
    if(head == nullptr){
        std::cout << "List is empty." << std::endl;
    }
    else{
        Node* iter = head;
        while(iter != nullptr){
            std::cout << iter->value << " ";
            iter = iter->next;
        }
    }
}

    //selection_sort() function definition: Sorts the linked list using selection sort
void LinkedList::selection_sort(){
    //If the list is empty, do nothing
    if(head == nullptr){
        return;
    }
    //Iterates through the list to find the minimum node and swaps it with the current node
    Node* i = head;
    while(i != nullptr){
        Node* minNode = i;
        Node* j = i->next;
        while(j != nullptr){
            if(j->value < minNode->value){
                minNode = j;
            }
            j = j->next;
        }
    //If the minimum node is not the current node, swap their values
        if(minNode != i){
            std::swap(i->value, minNode->value);
        }
        i = i->next;
    }
}

    //bubble_sort() function definition: Sorts the linked list using bubble sort
void LinkedList::bubble_sort(){
    //If the list is empty, do nothing
    if(head == nullptr){
        return;
}
    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while(current->next != nullptr){
            Node* next = current->next;
            if(current->value > next->value){
                std::swap(current->value, next->value);
                swapped = true;
            }
        } 
    } while(swapped);
}
