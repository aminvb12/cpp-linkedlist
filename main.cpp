#include <iostream>
#include <cstring>

using namespace std;


class Node {
public:
    int data;
    Node *next;
    Node *prev;
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
        this->head->prev = nullptr;
    }

    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    int getSize() { return this->size; }

    void deleteFirstNode();

    void deletePosition(int);

    Node *createNewNode(int data);

    int getTail() { return this->tail->data; }

    Node *getHead() { return this->head; }

    bool search(int data);

    void insertLast(int data);

    void insert_first(int data);

    void display();

    Node *secondSearch(int data);
};

Node *LinkedList::createNewNode(int data) {
    Node *newNode = new Node();
    newNode->next = nullptr;
//    newNode->prev = nullptr;
    newNode->data = data;
    if (!this->head) {
        this->head = newNode;
        this->tail = newNode;
    }
    if (!this->tail) {
        this->tail->next = newNode;
        this->tail = newNode;
    }
    return newNode;
}


bool LinkedList::search(int data) {
    if (this->head->data == data) {
        return true;
    }
    this->head = this->getHead()->next;
    return search(data);
}


void LinkedList::insertLast(int data) {
    if (this->head) {
        Node *temp = this->createNewNode(data);
        this->tail->next = temp;
        temp->prev = this->tail;
        this->tail = temp;
    } else {
        this->createNewNode(data);
    }
    this->size++;
}

void LinkedList::insert_first(int data) {
    if (this->head) {
        Node *temp = new Node();
        temp->next = head;
        head->prev = temp;
        temp->prev = nullptr;
        temp->data = data;
        head = temp;
    } else if (!this->head) {
        this->createNewNode(data);
    }

    this->size++;
}

void LinkedList::display() {
    Node *temp = new Node();
    temp = head;
    while (temp != NULL) {
        string arrow = (temp->next) ? ("->") : (" ");
        cout << temp->data << arrow;
        temp = temp->next;
    }
}

void LinkedList::deleteFirstNode() {
    Node *temp = this->getHead();
    this->head = this->getHead()->next;
    delete (temp);
}

Node *LinkedList::secondSearch(int data) {
    Node *temp = this->getHead();
    while (temp != nullptr) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
}


void LinkedList::deletePosition(int data) {
    Node *temp = this->secondSearch(data);
    temp->prev->next = temp->next;
    delete (temp);

}


int main() {
    LinkedList *test = new LinkedList();
    test->insert_first(12);
    test->insert_first(14);
    test->insertLast(18);
    test->insertLast(22);
    test->insert_first(10);
    test->deletePosition(12);
    test->display();


    return 0;
}


