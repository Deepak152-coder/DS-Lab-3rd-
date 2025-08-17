#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// (a) Insert at head
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
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

// (b) Count nodes and average
int countNodes(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

double average(Node *head)
{
    int sum = 0, count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    if (count == 0)
        return 0;
    return (double)sum / count;
}

// (c) Print first m nodes
void printFirstM(Node *head, int m)
{
    int total = countNodes(head);
    if (m > total)
    {
        cout << "Incorrect value of m" << endl;
        return;
    }
    Node *temp = head;
    for (int i = 0; i < m; i++)
    {
        if (temp == NULL)
        {
            break;
        }
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// (d) Find middle and check odd/even
void middleOddEven(Node *head)
{
    int total = countNodes(head);
    int midIndex = total / 2;
    Node *temp = head;
    for (int i = 0; i < midIndex; i++)
    {
        temp = temp->next;
    }
    cout << temp->data << " is ";
    if (temp->data % 2 == 0)
        cout << "even" << endl;
    else
        cout << "odd" << endl;
}

// (e) L elements from end (print last l nodes)
void lastLElements(Node *head, int l)
{
    int total = countNodes(head);
    int startIndex = total - l;
    Node *temp = head;
    for (int i = 0; i < startIndex; i++)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// (f) Find and delete first occurrence of a number
void deleteValue(Node *&head, int x)
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
    Node *curr = head->next;
    while (curr != NULL)
    {
        if (curr->data == x)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// (g) Swap first pair occurrences
void swapPair(Node *&head, int a, int b, int x, int y)
{
    Node *temp = head;
    Node *p1 = NULL;
    Node *p2 = NULL;

    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data == a && temp->next->data == b && p1 == NULL)
        {
            p1 = temp;
        }
        if (temp->data == x && temp->next->data == y && p2 == NULL)
        {
            p2 = temp;
        }
        temp = temp->next;
    }

    if (p1 != NULL && p2 != NULL)
    {
        p1->data = x;
        p1->next->data = y;
        p2->data = a;
        p2->next->data = b;
    }
}

// (h) Check sublist and return position (first occurrence)
int findSublist(Node *head, int sub[], int m)
{
    int pos = 1;
    Node *temp = head;

    while (temp != NULL)
    {
        Node *curr = temp;
        bool match = true;
        for (int i = 0; i < m; i++)
        {
            if (curr == NULL || curr->data != sub[i])
            {
                match = false;
                break;
            }
            curr = curr->next;
        }
        if (match)
        {
            return pos;
        }
        pos++;
        temp = temp->next;
    }
    return -1;
}

// (i) Reverse a sublist (assuming it exists)
void reverseSublist(Node *&head, int sub[], int m)
{
    int pos = findSublist(head, sub, m);
    if (pos == -1)
        return;

    Node *temp = head;
    Node *prevSub = NULL;
    for (int i = 1; i < pos; i++)
    {
        prevSub = temp;
        temp = temp->next;
    }

    Node *start = temp;
    Node *prev = NULL;
    for (int i = 0; i < m; i++)
    {
        Node *nxt = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nxt;
    }
    if (prevSub != NULL)
        prevSub->next = prev;
    else
        head = prev;

    start->next = temp;
}

// -------- MAIN (You can test each function here) -----------
int main()
{
    // Build Linked List
    Node *head = NULL;
    int arr[] = {1, 3, -9, 45, 2, 3, 56, 100, -67};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        insertAtHead(head, arr[i]);
    }

    // Display list
    cout << "Linked List: ";
    display(head);

    // (b) count + average
    cout << "Total nodes: " << countNodes(head) << endl;
    cout << "Average: " << average(head) << endl;

    // (c)
    cout << "First 4 elements: ";
    printFirstM(head, 4);

    // (d)
    cout << "Middle element odd/even: ";
    middleOddEven(head);

    // (e)
    cout << "Last 3 elements: ";
    lastLElements(head, 3);

    // (f)
    cout << "Deleting 45 if exists... " << endl;
    deleteValue(head, 45);
    display(head);

    // (g) Swap pairs {1,3} with {56,100}
    swapPair(head, 1, 3, 56, 100);
    cout << "After Swap Pair: ";
    display(head);

    // (h) find sublist {3, -9, 45}
    int sublist1[] = {3, -9, 45};
    int pos1 = findSublist(head, sublist1, 3);
    if (pos1 != -1)
    {
        cout << "Sublist exists at position: " << pos1 << endl;
    }
    else
    {
        cout << "Sublist not found" << endl;
    }

    // (i) reverse sublist {3, -9, 45}
    reverseSublist(head, sublist1, 3);
    cout << "After reverse sublist: ";
    display(head);

    return 0;
}
