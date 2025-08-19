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

Node *PartitionList(Node *head, int X)
{
    Node *leftStart = NULL;
    Node *leftEnd = NULL;
    Node *rightStart = NULL;
    Node *rightEnd = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        Node *nextNode = temp->next;
        temp->next = NULL;

        if (temp->val < X)
        {
            if (leftStart == NULL)
            {
                leftStart = leftEnd = temp;
            }
            else
            {
                leftEnd->next = temp;
                leftEnd = temp;
            }
        }
        else
        {
            if (rightStart == NULL)
            {
                rightStart = rightEnd = temp;
            }
            else
            {
                rightEnd->next = temp;
                rightEnd = temp;
            }
        }
        temp = nextNode;
    }

    if (leftStart == NULL)
    {
        return rightStart;
    }

    leftEnd->next = rightStart;
    return leftStart;
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
    // Manually creating linked list: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1
    Node *head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(1);

    int X = 5;

    cout << "Original list: ";
    Display(head);

    Node *newHead = PartitionList(head, X);

    cout << "Partitioned list: ";
    Display(newHead);

    return 0;
}
