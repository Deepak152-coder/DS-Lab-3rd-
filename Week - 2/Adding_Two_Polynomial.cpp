#include <iostream>
using namespace std;

class Node
{
public:
    int coeff;
    int pow;
    Node *next;
    Node(int c, int p)
    {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

void insert(Node *&head, int c, int p)
{
    Node *temp = new Node(c, p);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = temp;
    }
}

void display(Node *head)
{
    Node *t = head;
    while (t != NULL)
    {
        cout << t->coeff << "x^" << t->pow;
        if (t->next != NULL)
            cout << " + ";
        t = t->next;
    }
    cout << endl;
}

Node *add(Node *p, Node *q)
{
    Node *res = NULL;
    while (p != NULL && q != NULL)
    {
        if (p->pow == q->pow)
        {
            insert(res, p->coeff + q->coeff, p->pow);
            p = p->next;
            q = q->next;
        }
        else if (p->pow > q->pow)
        {
            insert(res, p->coeff, p->pow);
            p = p->next;
        }
        else
        {
            insert(res, q->coeff, q->pow);
            q = q->next;
        }
    }
    while (p != NULL)
    {
        insert(res, p->coeff, p->pow);
        p = p->next;
    }
    while (q != NULL)
    {
        insert(res, q->coeff, q->pow);
        q = q->next;
    }
    return res;
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;

    insert(poly1, 5, 2); // 5x^2
    insert(poly1, 4, 1); // 4x^1

    insert(poly2, 3, 2); // 3x^2
    insert(poly2, 1, 0); // 1

    display(poly1); // 5x^2 + 4x^1
    display(poly2); // 3x^2 + 1x^0

    Node *result = add(poly1, poly2);
    display(result);

    return 0;
}
