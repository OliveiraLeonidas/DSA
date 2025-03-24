#include <iostream>

class Node {
  public:
    int data;
    Node* next_node;
};

class LinkedList {
  public:
    LinkedList() {
      head = NULL;
      counter = 0;
    }

    void insert(int data) {
      Node* temp = new Node();
      temp->data = data;
      temp->next_node = NULL;
      
      if (this->head != NULL) temp->next_node = this->head;
      this->head = temp;
      this->counter++;
    }
    
    void insertN(int data, int index) {
      Node* temp1 = new Node();

      temp1->data = data;
      temp1->next_node = NULL;
    
      if (index == 1) {
        temp1->next_node = this->head;
        this->head = temp1;
        return;
      };
    
      Node* temp2 = this->head;
    
      for (int i = 0;  i<index-2; i++) {
        temp2 = temp2->next_node;
      };

      if(temp2 == NULL) {
        std::cout << "Error: index out limit. \n";
        delete temp1;
        return;
      };

      temp1->next_node = temp2->next_node;
      temp2->next_node = temp1;

    }
    
    void printList() {
      Node* temp = head;
      std::cout << "Linked List: ";
      while (temp != NULL) {
        std::cout << temp->data;
        temp = temp->next_node;
        std::cout << ' ';
      };
      std::cout << '\n';
    }
    
    int top() {
      if (this->head == NULL) {
        std::cout << "Empty list\n";
        return -1;
      };
      return this->head->data;
    }
    
    void pop() {
      if (this->head == NULL) {
        std::cout << "empty list\n";
        return ;
      };
    
      Node* temp = this->head;
      this->head = this->head->next_node;
      delete temp;
      if (counter > 0){ 
        this->counter--;
      } else {
        std::cout << "list is empty\n";
      }
    }

    void deleteN(int index) {
      if (this->head == NULL) {
        std::cout << "empty list\n";
        return ;
      };

      Node* temp1 = head;
      if (index == 1) {
        head = temp1->next_node; // head now points to second node.
        delete temp1;
        return;
      }
    
      int i;
      for(i = 0; i < index - 2; i++) {
        temp1 = temp1->next_node;
      }
    
      // temp1 points to (n-1)th Node
      Node* temp2 = temp1->next_node; // nth Node
      temp1->next_node = temp2->next_node; // (n+1)th Node
      delete temp2; // free memory from temp2
    }
  
    int void length() {
      return this->counter;
    }

    private:
    Node* head;
    int counter;
    
};

int main() {
  LinkedList list;

  list.insert(10);
  list.insert(20);
  list.insert(30);
  list.insert(100);
  list.printList(); 

  // list.insertN(50, 3);
  // list.printList(); 
  // std::cout << "Top: " << list.top() << "\n"; 

  // list.pop();
  // list.printList(); 

  // std::cout << "Top: " << list.top() << "\n";

  // list.deleteN(2);
  list.printList(); 

  return 0;
}