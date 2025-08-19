#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

Node *MoveLastNToFront(Node *head, int n)
{
    if (head == NULL || n == 0)
        return head;

    Node *temp = head;
    int length = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        length++;
    }
    Node *tail = temp;

    if (n == length)
        return head;

    Node *newTail = head;
    for (int i = 1; i < length - n; i++)
    {
        newTail = newTail->next;
    }

    Node *newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

void Display(Node *head)
{
    if (head == NULL)
    {
        cout << endl;
        return;
    }
    cout << head->val;
    if (head->next != NULL)
    {
        cout << " -> ";
    }
    Display(head->next);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    int n = 3;

    cout << "Original list: ";
    Display(head);

    Node *newHead = MoveLastNToFront(head, n);

    cout << "Modified list: ";
    Display(newHead);

    return 0;
}
