#include <iostream>

struct Node
{
  int data;
  Node* link;
};


// Test - stack
void Insert(Node*& head, int data){ 
  Node* temp = new Node();
  temp->data = data;
  temp->link = NULL;
  
  if (head != NULL) temp->link = head;
  head = temp;

};

// not a stack function
void InsertN(Node*& head, int data, int index) {
  Node* temp1 = new Node();

  temp1->data = data;
  temp1->link = NULL;

  if (index == 1) {
    temp1->link = head;
    head = temp1;
    return;
  }

  Node* temp2 = head;

  for (int i = 0;  i<index-2; i++) {
    temp2 = temp2->link;
  }
  temp1->link = temp2->link;
  temp2->link = temp1;
}

// Deletes node at position n
void deleteN(Node*& head, int index) {
  Node* temp1 = head;

  if (index == 1) {
    head = temp1->link; // head now points to second node.
    delete temp1;
    return;
  }

  int i;
  for(i = 0; i < index - 2; i++) {
    temp1 = temp1->link;
  }

  // temp1 points to (n-1)th Node
  Node* temp2 = temp1->link; // nth Node
  temp1->link = temp2->link; // (n+1)th Node
  delete temp2; // free memory from temp2
}


void Print(Node* head) {
  std::cout << "Linked List: ";
  while (head != NULL) {
    std::cout << head->data;
    head = head->link;
    std::cout << ' ';
  };
  std::cout << '\n';

};

int top(Node* head){ 
  return head->data;
}
// operador de alteração de estado -> permite passagem por referência, alterando o original e não a cópia
void pop(Node*& head) {
  if (head == NULL) {
    std::cout << "empty list\n";
    return ;
  };

  Node* temp = head;
  head = head->link;
  delete temp;

}

int main() {

  Node* head;
  head = NULL; // empty list

  // Insert(head, 10);
  // Insert(head, 20);
  // Insert(head, 30);
  // Insert(head, 100);

  InsertN(head, 2, 1);  // 2
  InsertN(head, 3, 2);  // 2, 3
  InsertN(head, 4, 1);  // 4, 2, 3
  InsertN(head, 5, 2); // 4, 5, 2, 3
  
  // std::cout << "Dentro do main após as inserções com passagem por referência - head: " << head << "\n";
  Print(head);
  
  std::cout << "\nTop stack: " << top(head);
  pop(head);
  std::cout << "\nNew top stack: " << top(head);

}

