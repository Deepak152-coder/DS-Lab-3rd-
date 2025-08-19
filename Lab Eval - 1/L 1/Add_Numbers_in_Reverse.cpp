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

Node *addTwoLists(Node *h1, Node *h2)
{
    int carry = 0;
    Node *sumHead = NULL;
    Node *sumTail = NULL;

    while (h1 != NULL || h2 != NULL || carry != 0)
    {
        int d1;
        if (h1 != NULL)
        {
            d1 = h1->val;
        }
        else
        {
            d1 = 0;
        }

        int d2;
        if (h2 != NULL)
        {
            d2 = h2->val;
        }
        else
        {
            d2 = 0;
        }

        int total = d1 + d2 + carry;
        int digit = total % 10;
        carry = total / 10;

        Node *temp = new Node(digit);

        if (sumHead == NULL)
        {
            sumHead = sumTail = temp;
        }
        else
        {
            sumTail->next = temp;
            sumTail = temp;
        }

        if (h1 != NULL)
        {
            h1 = h1->next;
        }
        if (h2 != NULL)
        {
            h2 = h2->next;
        }
    }

    return sumHead;
}

void Display(Node *head)
{
    if (head == NULL)
    {
        cout << endl;
        return;
    }
    cout << head->val << " ";
    // if (head->next != NULL)
    // {
    //     cout << " -> ";
    // }
    Display(head->next);
}

int main()
{
    // List 1: 2 -> 4 -> 3
    Node *h1 = new Node(2);
    h1->next = new Node(4);
    h1->next->next = new Node(3);

    // List 2: 5 -> 6 -> 4
    Node *h2 = new Node(5);
    h2->next = new Node(6);
    h2->next->next = new Node(4);

    Node *result = addTwoLists(h1, h2);

    Display(result);

    return 0;
}
