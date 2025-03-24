#include <iostream>

struct Node
{
  int data;
  Node* next_node;
};



// Test - stack
void Insert(Node*& head, int data){ 
  Node* temp = new Node();
  temp->data = data;
  temp->next_node = NULL;
  
  if (head != NULL) temp->next_node = head;
  head = temp;

};

void insertfinal(Node*& head, int data) {
  Node* temp = new Node();
  temp->data = data;
  temp->next_node = NULL;

  if (head == NULL) {
    head = temp;
    return;
  }

  // percorre a lista encadeada
  Node* lastNode = new Node();
  while (lastNode != NULL) {
    lastNode = lastNode->next_node;
  }
  
  //verifica o último nó ao final da lista
  lastNode = temp->next_node;
}

// interative method - Reverse a linkedlist
Node* Reverse(Node*& head) {
  Node *current, *prev, *next;
  current = head;
  prev = NULL;

  while (current != NULL) {
    next = current->next_node;
    current->next_node = prev; 
    prev = current;
    current = next;
  }

  head = prev;
  return head;
}

void InsertN(Node*& head, int data, int index) {
  Node* temp1 = new Node();

  temp1->data = data;
  temp1->next_node = NULL;

  if (index == 1) {
    temp1->next_node = head;
    head = temp1;
    return;
  }

  Node* temp2 = head;

  for (int i = 0;  i<index-2; i++) {
    temp2 = temp2->next_node;
  }
  temp1->next_node = temp2->next_node;
  temp2->next_node = temp1;
}

void deleteN(Node*& head, int index) {
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


void Print(Node* head) {
  std::cout << "Linked List: ";
  while (head != NULL) {
    std::cout << head->data;
    head = head->next_node;
    std::cout << ' ';
  };
  std::cout << '\n';

};

int top(Node* head){ 
  return head->data;
}

void pop(Node*& head) {
  if (head == NULL) {
    std::cout << "empty list\n";
    return ;
  };

  Node* temp = head;
  head = head->next_node;
  delete temp;

}



int main() {

  Node* head;
  head = NULL; // empty list

  // insertfinal(head, 10);
  // insertfinal(head, 20);
  // insertfinal(head, 30);
  // insertfinal(head, 100);

  Insert(head, 10);
  Insert(head, 20);
  Insert(head, 30);
  Insert(head, 100);

  // InsertN(head, 2, 1);  // 2
  // InsertN(head, 3, 2);  // 2, 3
  // InsertN(head, 4, 1);  // 4, 2, 3
  // InsertN(head, 5, 2); // 4, 5, 2, 3
  
  Print(head);

  Reverse(head);
  Print(head);
  
  // std::cout << "\nTop stack: " << top(head);
  // pop(head);
  // std::cout << "\nNew top stack: " << top(head);

}

