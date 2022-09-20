#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void printTree(treeNode *root, int level);
void spacePrint(int level);
void printRightNonLeaves(treeNode *root);

void printTree(treeNode *root, int level)
{
    if (root == NULL) // When the tree is empty
    {
        return;
    }

    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << endl;
    }
    else
    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->data << endl;
    }

    if (root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->leftChild, level + 1);
    }

    if (root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->rightChild, level + 1);
    }
}

void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "    ";
    }
}

void preOrderTraversal(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }

    chk += to_string(root->data);
    preOrderTraversal(root->leftChild, chk);
    preOrderTraversal(root->rightChild, chk);
}

void inOrder(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->leftChild, chk);
    chk += to_string(root->data) + " ";
    inOrder(root->rightChild, chk);
}

void postOrder(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->leftChild, chk);
    postOrder(root->rightChild, chk);
    chk += to_string(root->data);
}

int levelOrderTraversal(treeNode *root, string &chk, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int level = 0;
    queue<treeNode *> q;
    q.push(root);
    q.push(NULL);
    int max = -999;

    while (!q.empty())
    {
        treeNode *chkNode = q.front();
        q.pop();
        if (chkNode != NULL)
        {
            if (level == k)
            {
                if (max < chkNode->data)
                {
                    max = chkNode->data;
                }
            }
            cout << chkNode->data << " ";
            // chk += to_string(chkNode->data);
            if (chkNode->leftChild != NULL)
            {
                q.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL)
            {
                q.push(chkNode->rightChild);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
                level++;
            }
        }
    }
    return max;
}

int searchInorder(int inOrder[], int current, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i] == current)
        {
            return i;
        }
    }

    return -1;
}

treeNode *buildTreePreIn(int preOrder[], int inOrder[], int start, int end)
{
    static int id = 0;
    int current = preOrder[id];
    id++;
    treeNode *newNode = new treeNode(current);

    if (start == end)
    {
        return newNode;
    }

    int pos = searchInorder(inOrder, current, start, end);
    newNode->leftChild = buildTreePreIn(preOrder, inOrder, start, pos - 1);
    newNode->rightChild = buildTreePreIn(preOrder, inOrder, pos + 1, end);

    return newNode;
}

void printLeaves(treeNode *root)
{
    if (root == NULL)
        return;
    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << " ";
        return;
    }
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}

void printLeftNonLeaves(treeNode *root)
{
    if (root == NULL)
        return;

    if (root->leftChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }
    else if (root->rightChild != NULL)
    {
        cout << root->data << " ";
        printRightNonLeaves(root->rightChild);
    }
}

void printRightNonLeaves(treeNode *root)
{
    if (root == NULL)
        return;
    if (root == NULL)
        return;

    if (root->rightChild != NULL)
    {
        cout << root->data << " ";
        printRightNonLeaves(root->rightChild);
    }
    else if (root->leftChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }
}

void boundaryTraversal(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    // LB Non-Leaves
    printLeftNonLeaves(root->leftChild);
    // LB Leaves
    printLeaves(root->leftChild);
    // RB leaves
    printLeaves(root->rightChild);
    // RB Non-Leaves
    printRightNonLeaves(root->rightChild);
}

bool isSame(treeNode *root1, treeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 != NULL && root2 != NULL)
    {
        if (root1->data == root2->data)
        {
            if (isSame(root1->leftChild, root2->leftChild) && isSame(root1->rightChild, root2->rightChild))
                return true;
        }
    }

    return false;
}

void level_order(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<treeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        treeNode *chkNode = q.front();
        q.pop();

        if (chkNode != NULL)
        {
            cout << chkNode->data << " ";
            if (chkNode->leftChild != NULL)
            {
                q.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL)
            {
                q.push(chkNode->rightChild);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}

void level_order_reverse(treeNode *root)
{
    if (root == NULL)
        return;
    queue<treeNode *> q;
    stack<treeNode *> s;
    q.push(root);
    q.push(NULL);
    // s.push(root);

    while (!q.empty())
    {
        treeNode *chkNode = q.front();
        q.pop();
        if (chkNode != NULL)
        {
            s.push(chkNode);
            if (chkNode->rightChild != NULL)
            {
                q.push(chkNode->rightChild);
            }
            if (chkNode->leftChild != NULL)
            {
                q.push(chkNode->leftChild);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }

    while (!s.empty())
    {
        treeNode *chk = s.top();
        s.pop();
        cout << chk->data << " ";
    }
}

void zigzag_order(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<treeNode *> q;
    q.push(root);
    q.push(NULL);

    int n = 1;

    while (!q.empty())
    {
        treeNode *chkNode = q.front();
        q.pop();

        if (chkNode != NULL)
        {
            cout << chkNode->data << " ";
            if (n % 2 == 0)
            {
                if (chkNode->leftChild != NULL)
                {
                    q.push(chkNode->leftChild);
                }
                if (chkNode->rightChild != NULL)
                {
                    q.push(chkNode->rightChild);
                }
            }
            else
            {
                if (chkNode->rightChild != NULL)
                {
                    q.push(chkNode->rightChild);
                }
                if (chkNode->leftChild != NULL)
                {
                    q.push(chkNode->leftChild);
                }
            }
            n++;
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}

bool isMirror(treeNode *root1, treeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 != NULL && root2 != NULL)
    {
        if (root1->data == root2->data)
        {
            return (
                isMirror(root1->leftChild, root2->rightChild) && isMirror(root1->rightChild, root2->leftChild));
        }
    }

    return false;
}

bool isSymmetric(treeNode *root)
{
    return isMirror(root, root);
}

treeNode *invert_tree(treeNode *root)
{

    if (root == NULL)
    {
        return root;
    }
    treeNode *newRoot = new treeNode(root->data);
    newRoot->leftChild = invert_tree(root->rightChild);
    newRoot->rightChild = invert_tree(root->leftChild);
    return newRoot;
}

int tiltHelper(treeNode *root, int *tilt)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = tiltHelper(root->leftChild, tilt);
    int right = tiltHelper(root->rightChild, tilt);

    *tilt += abs(left - right);

    return (root->data + left + right);
}

int findTilt(treeNode *root)
{
    int tilt = 0;
    tiltHelper(root, &tilt);
    return tilt;
}

void average_level(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<treeNode *> q;
    q.push(root);
    q.push(NULL);

    int element = 0;
    int sum = 0;

    while (!q.empty())
    {
        treeNode *chkNode = q.front();
        q.pop();

        if (chkNode != NULL)
        {
            sum += chkNode->data;

            if (chkNode->leftChild != NULL)
            {
                q.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL)
            {
                q.push(chkNode->rightChild);
            }
            element++;
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
            float avg = sum / (float)element;
            cout << avg << " ";
            sum = 0;
            element = 0;
        }
    }
}

bool is_unival(treeNode *root)
{
    if (root == NULL)
        return true;
    if (root->leftChild != NULL)
    {
        if (root->leftChild->data != root->data)
        {
            return false;
        }
    }
    if (root->rightChild != NULL)
    {
        if (root->rightChild->data != root->data)
        {
            return false;
        }
    }
    return (is_unival(root->rightChild) && is_unival(root->leftChild));
}

int second_minimum(treeNode *root)
{
    if (root == NULL)
    {
        return -1;
    }

    int second_min = INT_MAX;
    int min = INT_MAX;
    queue<treeNode *> q;
    queue<treeNode *> q1;
    q.push(root);
    q.push(NULL);
    q1.push(root);
    q1.push(NULL);

    while (!q.empty())
    {
        treeNode *chkNode = q.front();
        q.pop();
        if (chkNode != NULL)
        {

            if (chkNode->data < min)
            {

                min = chkNode->data;
            }

            if (chkNode->leftChild != NULL)
            {
                q.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL)
            {
                q.push(chkNode->rightChild);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }

    while (!q1.empty())
    {
        treeNode *chkNode = q1.front();
        q1.pop();
        if (chkNode != NULL)
        {
            if (chkNode->data < second_min && chkNode->data > min)
            {

                second_min = chkNode->data;
            }

            if (chkNode->leftChild != NULL)
            {
                q1.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL)
            {
                q1.push(chkNode->rightChild);
            }
        }
        else
        {
            if (!q1.empty())
            {
                q1.push(NULL);
            }
        }
    }

    // if (second_min == INT_MAX)
    // {
    //     return -1;
    // }

    return second_min;
}

treeNode *insertionBST(treeNode *root, int value)
{
    treeNode *newNode = new treeNode(value);
    if (root == NULL)
    {
        root = newNode;
        return root;
    }

    // value< root->data
    if (value < root->data)
    {
        root->leftChild = insertionBST(root->leftChild, value);
    }
    // value> root->data
    else if (value > root->data)
    {
        root->rightChild = insertionBST(root->rightChild, value);
    }

    return root;
}

treeNode *searchBST(treeNode *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == value)
    {
        cout << root->data << endl;
        return root;
    }
    else if (value < root->data)
    {
        cout << root->data << "->";
        return searchBST(root->leftChild, value);
    }
    else
    {
        cout << root->data << "->";
        return searchBST(root->rightChild, value);
    }
}

treeNode *inordersucc(treeNode *root)
{
    treeNode *curr = root;

    while (curr->leftChild != NULL)
    {
        curr = curr->leftChild;
    }

    return curr;
}

treeNode *deletionBST(treeNode *root, int value)
{
    // if (root == NULL)
    // {
    //     return root;
    // }
    if (value < root->data)
    {
        root->leftChild = deletionBST(root->leftChild, value);
    }
    else if (value > root->data)
    {
        root->rightChild = deletionBST(root->rightChild, value);
    }
    else
    {

        if (root->leftChild == NULL)
        { // CASE 1 | CASE 2
            treeNode *temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL)
        { // CASE 2
            treeNode *temp = root->leftChild;
            free(root);
            return temp;
        }
        else
        { // CASE3
            treeNode *temp = inordersucc(root->rightChild);
            root->data = temp->data;
            root->rightChild = deletionBST(root->rightChild, temp->data);
        }
    }
    return root;
}

int main()
{
    int n;
    cin >> n;
    treeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        root = insertionBST(root, value);
    }

    string chk = "";
    inOrder(root, chk);
    cout << chk << endl;

    int key;
    cin >> key;

    // if (searchBST(root, key) == NULL)
    // {
    //     cout << endl
    //          << "The Value does not exist in the BST" << endl;
    // }
    // else
    // {
    //     cout << endl
    //          << "Value exist in the BST" << endl;
    // }

    root = deletionBST(root, key);

    string after = "";
    inOrder(root, after);
    cout << after << endl;

    cout << endl
         << endl;
    return 0;
}

/*
11
11 5 9 43 34 1 2 7 8 6 21
*/