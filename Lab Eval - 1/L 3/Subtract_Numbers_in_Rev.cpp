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

Node *subtractTwoLists(Node *h1, Node *h2)
{
    int borrow = 0;
    Node *diffHead = NULL;
    Node *diffTail = NULL;

    while (h1 != NULL || h2 != NULL)
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

        d1 = d1 - borrow;
        if (d1 < d2)
        {
            d1 = d1 + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        int digit = d1 - d2;

        Node *temp = new Node(digit);

        if (diffHead == NULL)
        {
            diffHead = diffTail = temp;
        }
        else
        {
            diffTail->next = temp;
            diffTail = temp;
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

    return diffHead;
}

void Display(Node *head)
{
    if (head == NULL)
    {
        // cout << endl;
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
    Node *h1 = new Node(7);
    h1->next = new Node(8);
    h1->next->next = new Node(6);

    Node *h2 = new Node(5);
    h2->next = new Node(6);
    h2->next->next = new Node(4);

    Node *result = subtractTwoLists(h1, h2);

    Display(result);

    return 0;
}
