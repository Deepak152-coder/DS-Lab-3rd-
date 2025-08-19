#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int marks;
    Student *next;

    Student(string n, int m)
    {
        name = n;
        marks = m;
        next = nullptr;
    }
};

// Inserting in ascending order based on marks
void insertStudent(Student *&head, string name, int marks)
{
    Student *t = new Student(name, marks);

    if (head == nullptr || marks < head->marks)
    {
        t->next = head;
        head = t;
        return;
    }

    Student *temp = head;
    while (temp->next != nullptr && temp->next->marks <= marks)
    {
        temp = temp->next;
    }

    t->next = temp->next;
    temp->next = t;
}

void displayAbove(Student *head, int threshold)
{
    int count = 0;
    Student *temp = head;

    while (temp != nullptr && temp->marks <= threshold)
    {
        temp = temp->next;
    }

    cout << "Students with marks above " << threshold << ":\n";
    while (temp != nullptr)
    {
        cout << temp->name << " (" << temp->marks << ")\n";
        count++;
        temp = temp->next;
    }

    cout << "Total count: " << count << endl;
}

int main()
{
    Student *head = nullptr;

    insertStudent(head, "Alice", 75);
    insertStudent(head, "Bob", 85);
    insertStudent(head, "Charlie", 65);
    insertStudent(head, "David", 90);
    insertStudent(head, "Eve", 80);

    int threshold;
    cout << "Enter the threshold marks : ";
    cin >> threshold;

    displayAbove(head, threshold);

    return 0;
}
