#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node(char data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtEnd(Node *&head, char val)
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

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool matchSub(Node *start, Node *pattern)
{
    Node *p = pattern;
    int count = 0;
    while (start != NULL && p != NULL && count < 3)
    {
        if (start->data != p->data)
            return false;
        start = start->next;
        p = p->next;
        count++;
    }
    return (count == 3);
}

void removeThree(Node *&head, Node *startPrev)
{
    Node *cur = (startPrev == NULL) ? head : startPrev->next;
    for (int i = 0; i < 3; i++)
    {
        Node *toDel = cur;
        if (cur == NULL)
            return;
        cur = cur->next;
        delete toDel;
    }
    if (startPrev == NULL)
    {
        head = cur;
    }
    else
    {
        startPrev->next = cur;
    }
}

void removePattern(Node *&head, Node *patternHead)
{
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL && temp->next != NULL && temp->next->next != NULL)
    {
        if (matchSub(temp, patternHead))
        {
            removeThree(head, prev);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    char arr1[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    for (int i = 0; i < 10; i++)
        insertAtEnd(head1, arr1[i]);

    char arr2[5] = {'X', 'Y', 'C', 'D', 'E'};
    for (int i = 0; i < 5; i++)
        insertAtEnd(head2, arr2[i]);

    cout << "First List: ";
    display(head1);
    cout << "Second List: ";
    display(head2);

    removePattern(head1, head2);

    cout << "After removal: ";
    display(head1);

    return 0;
}
