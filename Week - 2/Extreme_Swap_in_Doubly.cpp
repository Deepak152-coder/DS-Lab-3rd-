#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insertEnd(Node *&head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *t = head;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = temp;
    temp->prev = t;
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

void ExtremeSwap(Node *head)
{
    if (head == NULL)
        return;
    Node *left = head;
    Node *right = head;
    while (right->next != NULL)
    {
        right = right->next;
    }
    while (left != NULL && right != NULL && left != right && left->prev != right)
    {
        int t = left->data;
        left->data = right->data;
        right->data = t;
        left = left->next;
        right = right->prev;
    }
}

int main()
{
    Node *head = NULL;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    insertEnd(head, 6);
    insertEnd(head, 7);
    insertEnd(head, 8);

    ExtremeSwap(head);

    printList(head);

    return 0;
}
