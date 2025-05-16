#include <iostream>
#include <string>

template <typename T>
class Node {
  public:
    T data;
    Node* next_node;
};

template <typename T>
class Stack {
  public:
    Stack() : head(NULL), counter(0) {}

    void push(T data) {
      Node<T>* temp = new Node<T>();
      temp->data = data;
      temp->next_node = NULL;
      
      if (this->head != NULL) temp->next_node = this->head;
      this->head = temp;
      this->counter++;
    }
    
    T top() {
      if (this->head == NULL) {
        throw std::runtime_error("stack is empty");
      };
    
      return this->head->data;
    }
    
    void pop() {
      if (this->head == NULL) {
        std::cout << "empty list\n";
        return ;
      };
    
      Node<T>* temp = this->head;
      this->head = this->head->next_node;
      delete temp;
      
      if (counter > 0){ 
        this->counter--;
      }
    }

    int length() {
      return this->counter;
    }

    private:
    Node<T>* head;
    int counter;
    
};


void readCases(const std::string& cs) {
  Stack<char>* stack = new Stack<char>();
  
  for(char c : cs){ 
    if (c == '(') {
      stack->push(c);
    }
    else if (c == ')' && stack->length() > 0) {
      stack->pop();
    }
    else if (c == ')' && stack->length() == 0) {
      std::cout << "incorrect\n";
      return;
    }
   }

  std::cout << (stack->length() == 0 ? "correct\n" : "incorrect\n");
}

int main() {

   std::string caseData;
   
  try {
   while (std::getline(std::cin, caseData)) {
     readCases(caseData);
   }
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
  }
    

  return 0;
}