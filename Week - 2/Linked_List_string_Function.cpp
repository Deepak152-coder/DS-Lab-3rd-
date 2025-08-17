#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node(string data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtEnd(Node *&head, string val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *t = head;
    while (t->next != NULL)
        t = t->next;
    t->next = temp;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printStartingWith(Node *head, char ch)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.length() > 0 && temp->data[0] == ch)
            cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool searchString(Node *head, string x)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == x)
            return true;
        temp = temp->next;
    }
    return false;
}

void findMaxLength(Node *head)
{
    Node *temp = head;
    string longest = head->data;
    while (temp != NULL)
    {
        if (temp->data.length() > longest.length())
            longest = temp->data;
        temp = temp->next;
    }
    cout << "Longest string: " << longest << endl;
}

void containsXYZ(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.find("xyz") != string::npos)
        {
            cout << temp->data << " contains xyz" << endl;
        }
        temp = temp->next;
    }
}

void swapPositions(Node *head, int p1, int p2)
{
    Node *temp = head;
    Node *node1 = NULL;
    Node *node2 = NULL;
    int i = 1;
    while (temp != NULL)
    {
        if (i == p1)
            node1 = temp;
        if (i == p2)
            node2 = temp;
        temp = temp->next;
        i++;
    }
    if (node1 == NULL || node2 == NULL)
    {
        cout << "Invalid positions" << endl;
        return;
    }
    string x = node1->data;
    node1->data = node2->data;
    node2->data = x;
}

void deleteByValue(Node *&head, string x)
{
    if (head == NULL)
        return;
    if (head->data == x)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *prev = head;
    Node *cur = head->next;
    while (cur != NULL)
    {
        if (cur->data == x)
        {
            prev->next = cur->next;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

int main()
{
    Node *head = NULL;
    insertAtEnd(head, "apple");
    insertAtEnd(head, "hello");
    insertAtEnd(head, "xyzabc");
    insertAtEnd(head, "world");
    insertAtEnd(head, "banana");

    printList(head);
    printStartingWith(head, 'a');

    if (searchString(head, "hello"))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    findMaxLength(head);
    containsXYZ(head);

    swapPositions(head, 2, 5);
    printList(head);

    deleteByValue(head, "xyzabc");
    printList(head);

    return 0;
}
