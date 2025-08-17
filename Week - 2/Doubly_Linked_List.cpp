#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

Node *head = NULL;

void insertEnd(int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *t = head;
    while (t->next != NULL)
        t = t->next;
    t->next = temp;
    temp->prev = t;
}

void printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void checkDivisible(int m)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data % m == 0)
            cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteGreater(int x)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *nxt = temp->next;
        if (temp->data > x)
        {
            if (temp->prev == NULL)
            {
                head = temp->next;
                if (head != NULL)
                    head->prev = NULL;
                delete temp;
            }
            else
            {
                temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
                delete temp;
            }
        }
        temp = nxt;
    }
}

int countBetweenDuplicate(int val)
{
    Node *temp = head;
    int startPos = -1, endPos = -1, pos = 0;

    while (temp != NULL)
    {
        if (temp->data == val)
        {
            if (startPos == -1)
                startPos = pos;
            else
            {
                endPos = pos;
                break;
            }
        }
        pos++;
        temp = temp->next;
    }

    if (startPos != -1 && endPos != -1)
        return endPos - startPos - 1;
    else
        return 0;
}

int main()
{
    int arr[] = {1, 3, -9, 45, 2, -56, 3, 56, 100, -67, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        insertEnd(arr[i]);

    cout << "List: ";
    printList();

    cout << "Divisible by 3: ";
    checkDivisible(3);

    deleteGreater(50);
    cout << "After deleting >50: ";
    printList();

    int val = 3;
    int countVal = countBetweenDuplicate(val);
    cout << "Number of elements between first pair of " << val << ": " << countVal << endl;

    return 0;
}
