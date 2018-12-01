#include <iostream>
using namespace std;




class Node {
public:
    int data;
    Node *next ;
};


class LinkedList {
private:
    Node *head;
    Node *tail;
    int size = 0;
public:
    LinkedList(Node *head) : head(head) {}
    LinkedList(int data) {
        this->head->data = data;
        this->head->next = nullptr;
    }

    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }

    int getSize(){ return this->size; }

    Node *createNewNode (int data);

    int getTail(){ return this->tail->data; }

    Node *getHead (){ return this->head; }

    bool search(Node *head , int data);

    void insertLast(int data);

    void insert_first(int data);

    void display();
};

Node* LinkedList::createNewNode(int data) {
    Node *newNode = new Node();
    newNode->next = nullptr;
    newNode->data = data;
    if(!this->head){
        this->head = newNode;
        this->tail = newNode;
    }
    if(!this->tail){
        this->tail->next = newNode;
        this->tail = newNode;
    }
    return newNode;
}

bool LinkedList::search(Node *head, int data) {
    if(head->data == data){
        return true;
    }
    return search(head->next , data);
}


void LinkedList::insertLast(int data) {
    if(this->head){
        Node *temp = this->createNewNode(data);
        this->tail->next = temp;
        this->tail = temp;
    }
    else{
        this->createNewNode(data);
    }
    this->size++;
}

void LinkedList::insert_first(int data) {
    if (this->head) {
        Node *temp = new Node();
        temp->next = head;
        temp->data = data;
        head = temp;
        this->size ++;
    }
    else if(!this->head){
        this->createNewNode(data);
        this->size++;
    }
}

void LinkedList::display() {
    Node *temp = new Node();
    temp = head;
    while (temp != NULL) {
        string arrow = (temp->next) ? ("->") : (" ");
        cout << temp->data <<arrow;
        temp = temp->next;
    }
}


int main() {
    LinkedList *test = new LinkedList();
    test->insert_first(12);
    test->insert_first(14);
    test->insertLast(18);
    test->insertLast(22);
    test->insert_first(10);
    test->display();
    cout<<test->getHead()->data<<endl;
    cout<<test->getSize()<<endl;
    cout<<test->search(test->getHead() , 18)<<endl;
    return 0;
}


