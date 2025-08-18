#include <iostream>
using namespace std;

struct Customer
{
    string name;
    int total_bill;
    Customer *next;

    Customer(string n, int b)
    {
        name = n;
        total_bill = b;
        next = NULL;
    }
};

// Insert in descending order based on total_bill
void insertInDescending(Customer *&head, string name, int bill)
{
    Customer *t = new Customer(name, bill);

    if (head == NULL || head->total_bill < bill)
    {
        t->next = head;
        head = t;
        return;
    }

    Customer *temp = head;
    while (temp->next != NULL && temp->next->total_bill >= bill)
    {
        temp = temp->next;
    }
    t->next = temp->next;
    temp->next = t;
}

// No ternary operator version
double findAverage(Customer *head)
{
    double sum = 0;
    int count = 0;

    Customer *temp = head;
    while (temp != NULL)
    {
        sum += temp->total_bill;
        count++;
        temp = temp->next;
    }

    if (count == 0)
    {
        return 0;
    }
    else
    {
        return sum / count;
    }
}

void displayAboveAverage(Customer *head, double avg)
{
    Customer *temp = head;
    cout << "Customers with bill greater than average (" << avg << "): ";

    while (temp != NULL)
    {
        if (temp->total_bill > avg)
        {
            cout << temp->name << " ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Customer *head = NULL;

    insertInDescending(head, "Ram", 500);
    insertInDescending(head, "Shyam", 1200);
    insertInDescending(head, "Aman", 800);
    insertInDescending(head, "Ravi", 300);

    double avg = findAverage(head);
    displayAboveAverage(head, avg);

    return 0;
}
