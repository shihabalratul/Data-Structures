#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

struct Test
{
    int position[1000];
};

// Function Declaration
void insertAtTail(Node *&head, int val);
void insertionAtHead(Node *&head, int val);
void display(Node *n);
int displayReverse(Node *head);
int countLength(Node *&head);
void insertionAtSpecificPosition(Node *&head, int pos, int val);
int searchByValueUnique(Node *&head, int key);
void searchByValueDulicate(Node *&head, int key);
Test searchByValueDulicateReturn(Node *&head, int key);
void searchByValueUnique(Node *&head, int searchValue, int value);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void deletionAtSpecificPosition(Node *&head, int position);
void deletionByValueUnique(Node *&head, int value);

// Function implementation
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }

    temp->Next = newNode;
}

void insertionAtHead(Node *&head, int val)
{
    // s1: newNode Creation
    Node *newNode = new Node(val);
    // s2: Update of newNode->Next
    newNode->Next = head;
    // s3: Update of head
    head = newNode;
}

void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
            cout << " -> ";

        n = n->Next;
    }
}

int displayReverse(Node *head)
{
    if (head->Next != NULL)
        cout << displayReverse(head->Next) << " ";

    return head->value;
}

int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }
    return count;
}

int searchByValueUnique(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;

    if (temp == NULL)
    {
        return -1;
    }

    while (temp->value != key)
    {
        if (temp->Next == NULL)
        {
            return -1;
        }
        temp = temp->Next;
        count++;
    }
    return count;
}

void insertionAtSpecificPosition(Node *&head, int pos, int val)
{
    int i = 0;
    Node *temp = head;

    while (i < pos - 2)
    {
        temp = temp->Next;
        i++;
    }
    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

void searchByValueDulicate(Node *&head, int key)
{
    Node *temp = head;
    int size;
    size = countLength(head);
    int position[size + 1], k = 1;
    int count = 1;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            // cout<< count<< " ";
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }

    if (flag == 0)
        cout << "The value you are looking is not in the list." << endl;
    else
    {
        position[0] = k;
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
                cout << ",";
        }
    }
    cout << endl;
}

Test searchByValueDulicateReturn(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int size;
    size = countLength(head);
    int k = 1;
    int count = 1;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            // cout<< count<< " ";
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }

    T.position[0] = k;
    return T;
}

void insertionByValueUnique(Node *&head, int searchValue, int value)
{
    // Step 1: Search the position of the searchValue
    int position;
    position = searchByValueUnique(head, searchValue);

    // Step 2: Insert the value at the position+1
    insertionAtSpecificPosition(head, position + 1, value);
}

void deletionAtHead(Node *&head)
{
    Node *temp = NULL;
    temp = head;
    if (temp != NULL)
    {
        head = temp->Next;
        delete (temp);
    }
    else
    {
        cout << "There is No value in the linked list" << endl;
    }
}

void deletionAtTail(Node *&head)
{
    Node *temp = NULL;
    temp = head;
    if (temp != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = NULL;
        delete delNode;
    }
    else
    {
        if (temp == NULL)
            cout << "There is No value in the linked list" << endl;
        else
            deletionAtHead(head);
    }
}

void deletionAtSpecificPosition(Node *&head, int position)
{
    Node *temp = head;
    if (temp != NULL && position <= countLength(head))
    {
        if (position == 1)
        {
            deletionAtHead(head);
        }
        else if (position == countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
            int i = 1;

            while (i < position - 1)
            {
                temp = temp->Next;
                i++;
            }

            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
    else
    {
        // if (position > countLength(head))
        cout << "Position Out of Bound" << endl;
        // Position is Out of range

        // LL is NULL
    }
}

void deletionByValueUnique(Node *&head, int value)
{
    // Find the position of the value
    int position;
    position = searchByValueUnique(head, value);
    // Delete the Node at that position
    if (position == -1)
    {
        cout << "Value not Found in the Linked List" << endl;
    }
    else
    {
        deletionAtSpecificPosition(head, position);
    }
}

int main()
{
    Node *head = NULL;

    // Choice 1: Insertion at Head
    // Choice 2: Insetion at Tail
    cout << "Choice 1: Insertion at Head" << endl
         << "Choice 2: Insertion at Tail" << endl
         << "Choice 3: Insertion at specific position" << endl
         << "Choice 4: Search a value(Uniqe List)" << endl
         << "Choice 5: Search a value(Duplicate enabled List)" << endl
         << "Choice 6: Insertion after a specific value." << endl
         // << "Choice 7: Insetion after a specifiic value in a duplicate list"
         << "Choice 7: Deletion at Head" << endl
         << "Choice 8: Deletion at Tail" << endl
         << "Choice 9: Deletion at specific position" << endl
         << "Choice 10: Deletion by Value Unique List)" << endl
         << "Choice 0: Exit" << endl
         << endl;
    int choice;
    cout << "Enter Choice: ";
    cin >> choice;
    while (choice != 0)
    {

        int position;
        int value;
        switch (choice)
        {
        case 1:
            cout << "Enter the Value: ";
            cin >> value;
            insertionAtHead(head, value);
            break;
        case 2:
            cout << "Enter the Value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter the desired position: ";
            cin >> position;
            cout << "Enter the Value: ";
            cin >> value;
            insertionAtSpecificPosition(head, position, value);
        case 4:
            cout << "Enter the value to search: ";
            cin >> value;
            position = searchByValueUnique(head, value);

            if (position != -1)
            {
                cout << "The number is at  Position: " << position << endl;
            }
            else
            {
                cout << "The number is not in the List: " << endl;
            }
            break;
        case 5:
            cout << "Enter the value to search: ";
            cin >> value;
            // cout<< "The number at Position :";
            Test T;
            T = searchByValueDulicateReturn(head, value);
            if (T.position[0] == 1)
            {
                cout << "The search value is not yet in the list.";
            }
            else
            {
                int size = T.position[0];
                cout << "The value is found at Position: ";
                for (int i = 1; i < size; i++)
                {
                    cout << T.position[i];
                    if (i < size - 1)
                        cout << ", ";
                }
                cout << endl;
            }
            break;
        case 6:
            cout << "Enter the value to search: ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            insertionByValueUnique(head, searchValue, value);
            break;
        case 7:
            deletionAtHead(head);
            break;
        case 8:
            deletionAtTail(head);
            break;
        case 9:
            cout << "Enter the position to delete: ";
            cin >> position;
            if (head == NULL)
            {
                cout << "There is No Value in the Linked List" << endl;
                break;
            }
            deletionAtSpecificPosition(head, position);
            break;
        case 10:
            cout << "Enter the value to Delete: ";
            int delValue;
            cin >> delValue;
            deletionByValueUnique(head, delValue);
            // if (head == NULL)
            // {
            //     cout << "There is No Value in the Linked List" << endl;
            //     break;
            // }

            break;
        default:
            break;
        }
        cout << "Next choice: ";
        cin >> choice;
    }

    // insertAtTail(head, 1);
    // insertAtTail(head, 5);
    // insertAtTail(head, 8);
    // insertAtTail(head, 9);
    // Node* second = new Node();
    // Node* third = new Node();
    // Node* fourth = new Node();

    // head->value = 1;
    // second->value = 5;
    // third->value = 8;
    // fourth->value = 9;

    // head->Next = second;
    // second->Next = third;
    // third->Next = fourth;
    // fourth->Next = NULL;

    display(head);
    cout << endl;
    cout << "Length : ";
    cout << countLength(head);
    return 0;
}