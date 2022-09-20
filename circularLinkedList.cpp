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
void display(Node *&head);
int displayReverse(Node *head);
int countLength(Node *&head);
void insertionAtSpecificPosition(Node *&head, int pos, int val);
int searchByValueUnique(Node *&head, int key);
void searchByValueDuplicate(Node *&head, int key);
Test searchByValueDuplicateReturn(Node *&head, int key);
void searchByValueUnique(Node *&head, int searchValue, int value);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void deletionAtSpecificPosition(Node *&head, int position);
void deletionByValueUnique(Node *&head, int value);
void insertionByValueDuplicate(Node *&head, int searchValue, int value);
void deletionByValueDuplicate(Node *&head, int value);

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

    while (temp->Next != head)
    {
        temp = temp->Next;
    }

    newNode->Next = head;
    temp->Next = newNode;
}

void insertionAtHead(Node *&head, int val)
{
    // s1: newNode Creation
    Node *newNode = new Node(val);
    // s2: Update of newNode->Next
    newNode->Next = head;
    // s3: Update the tail with newNode
    if (head == NULL)
    {
        head = newNode;
        newNode->Next = head;
        return;
    }
    Node *temp = head;
    while (temp->Next != head)
    {
        temp = temp->Next;
    }

    temp->Next = newNode;
    // s4: Update of head
    head = newNode;
}

void display(Node *&head)
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "The Linked List is Empty." << endl;
        return;
    }

    do
    {
        cout << temp->value;
        temp = temp->Next;
        if (temp != head)
            cout << "->";
    } while (temp != head);
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

    do
    {
        count++;
        temp = temp->Next;
    } while (temp != head);
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

void searchByValueDuplicate(Node *&head, int key)
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

Test searchByValueDuplicateReturn(Node *&head, int key)
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

void insertionByValueDuplicate(Node *&head, int searchValue, int value)
{
    // Step 1: Search the position of the searchValue
    Test position = searchByValueDuplicateReturn(head, searchValue);

    int i = 1;
    // Step 2: Insert the value at the position+1
    while (i < position.position[0])
    {
        insertionAtSpecificPosition(head, position.position[i] + i, value);
        i++;
    }
}

void deletionAtHead(Node *&head)
{
    Node *temp = NULL;
    temp = head;
    if (temp != NULL)
    {
        Node *delNode = temp;
        while (temp->Next != head)
        {
            temp = temp->Next;
        }
        temp->Next = delNode->Next;
        head = delNode->Next;
        delete delNode;
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
    if (temp != NULL && temp->Next != head)
    {
        while (temp->Next->Next != head)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = delNode->Next;
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

void deletionByValueDuplicate(Node *&head, int value)
{
    // Step 1: Search the position of the Value
    Test position = searchByValueDuplicateReturn(head, value);

    int i = 1;
    if (position.position[0] == 1)
    {
        cout << "Value not found." << endl;
    }
    else
    {
        // Step 2: Delete the values
        while (i < position.position[0])
        {
            deletionAtSpecificPosition(head, position.position[i] - i + 1);
            i++;
        }
    }
}

Node *reverseNonRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if (head == NULL)
    {
        cout << "The linked list is empty" << endl;
        return head;
    }
    Node *next = head->Next;

    while (true)
    {
        current->Next = prev;
        prev = current;
        current = next;
        if (current == NULL)
            break;

        next = next->Next;
    }
    return prev;
}

Node *reverseRecursive(Node *&head)
{
    if (head->Next == NULL || head == NULL)
    {
        return head;
    }
    Node *newHead = reverseRecursive(head->Next);
    head->Next->Next = head;
    head->Next = NULL;

    return newHead;
}

int findMid(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    if (head == NULL)
    {
        return -1;
    }
    while (fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    }

    return slow->value;
}

bool detectCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
        // Cycle check
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

void makeCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *startNode;
    int count = 1;

    if (head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }
    while (temp->Next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->Next;
        count++;
    }

    temp->Next = startNode;
}

void removeCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    // Step 1: fast != slow
    do
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    } while (fast != slow);

    // Step 2: Re Initialization of fast
    fast = head;

    // Step 3: fast -> Next = slow->Next
    while (fast->Next != slow->Next)
    {
        slow = slow->Next;
        fast = fast->Next;
    }

    // Step 4:
    slow->Next = NULL;
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
         << "Choice 7: Deletion at Head" << endl
         << "Choice 8: Deletion at Tail" << endl
         << "Choice 9: Deletion at specific position" << endl
         << "Choice 10: Deletion by Value (Unique List)" << endl
         << "Choice 11: Insetion after a specifiic value in a duplicate list" << endl
         << "Choice 12: Delete by Value (Duplicate List)" << endl
         << "Choice 13: Reverse non recursive." << endl
         << "Choice 14: Reverse Recursive." << endl
         << "Choice 15: Finding mid (Slow-Fast pointer method)" << endl
         << "Choice 16: Make Cycle" << endl
         << "Choice 17: Remove Cycle(if any)" << endl
         << "Choice 0: Exit" << endl
         << endl;
    int choice;
    cout << "Enter Choice: ";
    cin >> choice;
    while (choice != 0)
    {

        int position;
        int value;
        int searchValue;
        int delValue;
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
            T = searchByValueDuplicateReturn(head, value);
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

            cin >> delValue;
            deletionByValueUnique(head, delValue);
            break;
        case 11:
            cout << "Enter the value to search: ";
            cin >> searchValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            insertionByValueDuplicate(head, searchValue, value);
            break;
        case 12:
            cout << "Enter the value to Delete: ";
            cin >> delValue;
            deletionByValueDuplicate(head, delValue);
            break;
        case 13:
            head = reverseNonRecursive(head);
            break;
        case 14:
            head = reverseRecursive(head);
            break;
        case 15:
            int mid;
            mid = findMid(head);
            if (mid == -1)
            {
                cout << "Your list is empty." << endl;
            }
            else
            {
                cout << "Mid value is " << mid << endl;
            }
            break;
        case 16:
            cout << "Enter the position: ";
            cin >> position;
            makeCycle(head, position);
            break;
        case 17:
            bool cycleStatus;
            cycleStatus = detectCycle(head);
            if (cycleStatus == true)
            {
                removeCycle(head);
            }
            else
            {
                cout << "There is No Cycle in the list" << endl;
            }
        default:
            break;
        }
        cout << "Next choice: ";
        cin >> choice;
    }

    display(head);
    cout << endl;
    cout << "Length : ";
    cout << countLength(head);
    return 0;
}