#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
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
        head->next = head;
    }
    else
    {
        Node *t = head;
        while (t->next != head)
        {
            t = t->next;
        }
        t->next = temp;
        temp->next = head;
    }
}

void printList()
{
    if (head == NULL)
    {
        cout << "Empty List\n";
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int countNodes()
{
    if (head == NULL)
        return 0;
    int count = 0;
    Node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

bool hasNegative()
{
    if (head == NULL)
        return false;
    Node *temp = head;
    do
    {
        if (temp->data < 0)
            return true;
        temp = temp->next;
    } while (temp != head);
    return false;
}

int countGreater15()
{
    if (head == NULL)
        return 0;
    int c = 0;
    Node *temp = head;
    do
    {
        if (temp->data > 15)
            c++;
        temp = temp->next;
    } while (temp != head);
    return c;
}

void deleteValue(int x)
{
    if (head == NULL)
        return;
    if (head->next == head && head->data == x)
    {
        delete head;
        head = NULL;
        return;
    }
    if (head->data == x)
    {
        Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = head->next;
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *curr = head;
    Node *prev = NULL;
    do
    {
        prev = curr;
        curr = curr->next;
        if (curr->data == x)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }
    } while (curr != head);
}

bool updateValue(int oldVal, int newVal)
{
    Node *temp = head;
    if (temp == NULL)
        return false;
    do
    {
        if (temp->data == oldVal)
        {
            temp->data = newVal;
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    return false;
}

void insertAtPos(int val, int pos)
{
    int n = countNodes();
    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid position\n";
        return;
    }
    Node *temp = new Node(val);
    if (pos == 1)
    {
        if (head == NULL)
        {
            head = temp;
            head->next = head;
        }
        else
        {
            Node *last = head;
            while (last->next != head)
            {
                last = last->next;
            }
            temp->next = head;
            last->next = temp;
            head = temp;
        }
        return;
    }
    Node *p = head;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
}

bool isPrime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void deletePrime()
{
    if (head == NULL)
        return;
    int n = countNodes();
    for (int i = 0; i < n; i++)
    {
        Node *temp = head;
        if (isPrime(temp->data))
        {
            deleteValue(temp->data);
        }
        head = temp->next;
    }
}

bool isFibo(int x)
{
    if (x < 0)
        return false;
    int a = 0, b = 1;
    if (x == 0 || x == 1)
        return true;
    while (b < x)
    {
        int c = a + b;
        a = b;
        b = c;
    }
    return (b == x);
}

void deleteFibo()
{
    if (head == NULL)
        return;
    int n = countNodes();
    for (int i = 0; i < n; i++)
    {
        Node *temp = head;
        if (isFibo(temp->data))
        {
            deleteValue(temp->data);
        }
        head = temp->next;
    }
}

int main()
{
    insertEnd(5);
    insertEnd(8);
    insertEnd(17);
    insertEnd(20);
    insertEnd(-4);

    printList();
    cout << countNodes() << endl;
    cout << (hasNegative() ? "Yes" : "No") << endl;
    cout << countGreater15() << endl;

    deleteValue(8);
    printList();

    updateValue(17, 99);
    printList();

    insertAtPos(10, 2);
    printList();

    deletePrime();
    printList();

    deleteFibo();
    printList();

    return 0;
}
