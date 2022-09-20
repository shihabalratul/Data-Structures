#include <bits/stdc++.h>
using namespace std;

template <typename N>
class Node
{
public:
    N value;
    Node *next;
    Node *prev;

    Node(N val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

template <typename S>
class Stack
{
    Node<S> *head;
    Node<S> *top;
    int count = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }
    // PUSH
    void push(S val)
    {
        Node<S> *newNode = new Node<S>(val);

        if (head == NULL)
        {
            head = top = newNode;
            count++;
            return;
        }

        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count++;
    }
    // POP
    S pop()
    {
        Node<S> *delNode;
        delNode = top;
        S chk;
        // If there is No Element
        // if (head == NULL)
        // {
        //     cout << "Stack Underflow" << endl;
        // }

        // There is only 1 elements
        if (top == head)
        {
            chk = head->value;
            head = top = NULL;
        }
        // There is More than 1 element
        else
        {
            top = delNode->prev;
            top->next = NULL;
            chk = delNode->value;
        }

        delete delNode;
        count--;
        return chk;
    }
    // EMPTY
    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // SIZE
    int size()
    {

        return count;
    }
    // TOP
    S Top()
    {
        S chk;
        if (top == NULL)
        {
            cout << "Stack Underflow | There is no element in the stack";
        }
        else
        {
            chk = top->value;
            return chk;
        }
    }

    void print()
    {
        Node<S> *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << " " << endl;
            temp = temp->next;
        }
    }
};
