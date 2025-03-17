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
    }

    void insert(int data) {
      Node* temp = new Node();
      temp->data = data;
      temp->next_node = NULL;
      
      if (this->head != NULL) temp->next_node = this->head;
      this->head = temp;
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
        std::cout << "Erro: indice fora do limtie. \n";
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
  
    private:
    Node* head;
    
};

int main() {
  LinkedList list;

  list.insert(10);
  list.insert(20);
  list.insert(30);
  list.insert(100);
  list.printList(); // Deve imprimir: 100 30 20 10

  list.insertN(50, 3); // Inserir 50 na posição 3
  list.printList(); // Deve imprimir: 100 30 50 20 10

  std::cout << "Topo: " << list.top() << "\n"; // Deve imprimir: 100

  list.pop();
  list.printList(); // Deve imprimir: 30 50 20 10

  std::cout << "Topo: " << list.top() << "\n"; // Deve imprimir: 30

  list.deleteN(2);
  list.printList(); 0

  return 0;
}