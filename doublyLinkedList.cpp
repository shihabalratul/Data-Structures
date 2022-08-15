#include <bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int val;
    doublyNode *prev;
    doublyNode *next;

    doublyNode(int val)
    {
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtTail(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    doublyNode *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtHead(doublyNode *&head, int val)
{
    // S1: newNode Creation
    doublyNode *newNode = new doublyNode(val);

    // S2: Update of head->prev
    if (head != NULL)
        head->prev = newNode;

    // S3: Update of newNode->Next
    newNode->next = head;

    // S4: Update of head
    head = newNode;
}

void display(doublyNode *n)
{
    while (n != NULL)
    {
        cout << n->val;
        if (n->next != NULL)
            cout << " -> ";

        n = n->next;
    }
}

void displayReversed(doublyNode *head)
{
    doublyNode *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        cout << temp->val;
        if (temp->prev != NULL)
            cout << " -> ";

        temp = temp->prev;
    }
}

int countLength(doublyNode *&head)
{
    int count = 0;
    doublyNode *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    doublyNode *head = NULL;

    int value, position;
    cout << "Choice 1: Insertion at Head" << endl
         << "Choice 2: Insertion at Tail" << endl
         << "Choice 3: Display list" << endl
         << "Choice 4: Show list length" << endl
         << "Choice 5: Display list reversed" << endl
         << "Choice 0: Exit" << endl
         << endl;

    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "The List: ";
            display(head);
            cout << endl;
            break;
        case 4:
            cout << "Lists length: ";
            cout << countLength(head);
            cout << endl;
            break;
        case 5:
            cout << "Reversed List: ";
            displayReversed(head);
            cout << endl;
            break;
        default:
            break;
        }

        cout << "Next Choice: ";
        cin >> choice;
    }
    return 0;
}
