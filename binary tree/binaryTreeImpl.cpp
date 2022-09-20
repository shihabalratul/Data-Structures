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
    chk += to_string(root->data);
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
    isMirror(root, root);
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

int main()
{
    int n;
    cin >> n;

    treeNode *root = new treeNode(2);
    root->leftChild = new treeNode(2);
    root->rightChild = new treeNode(5);
    // root->leftChild->leftChild = new treeNode(5);
    // root->leftChild->rightChild = new treeNode(2);
    root->rightChild->leftChild = new treeNode(5);
    root->rightChild->rightChild = new treeNode(7);

    // treeNode *reversed = invert_tree(root);
    cout << second_minimum(root) << endl;
    // average_level(root);

    // printTree(root, 0);
    // printTree(reversed, 0);
    // int preOrder[n], inOrder[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> preOrder[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> inOrder[i];
    // }

    // treeNode *root = buildTreePreIn(preOrder, inOrder, 0, n - 1);
    // string chklevel = "";
    // levelOrderTraversal(root, chklevel, n);
    // cout << chklevel << endl
    //      << endl;

    // treeNode *allNodes[n];
    // treeNode *allNodes2[n];

    // for (int i = 0; i < n; i++)
    // {
    //     allNodes[i] = new treeNode(-1);
    //     // allNodes2[i] = new treeNode(-1);
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     int value, left, right;
    //     cin >> value >> left >> right;
    //     allNodes[i]->data = value;
    //     if (left != -1)
    //     {
    //         allNodes[i]->leftChild = allNodes[left];
    //     }

    //     if (right != -1)
    //     {
    //         allNodes[i]->rightChild = allNodes[right];
    //     }
    // }

    if (is_unival(root))
    {
        cout << "Is symetric" << endl;
    }
    else
    {
        cout << "Is not symetric" << endl;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     int value, left, right;
    //     cin >> value >> left >> right;
    //     allNodes2[i]->data = value;
    //     if (left != -1)
    //     {
    //         allNodes2[i]->leftChild = allNodes2[left];
    //     }

    //     if (right != -1)
    //     {
    //         allNodes2[i]->rightChild = allNodes2[right];
    //     }
    // }

    // if (isSame(allNodes[0], allNodes2[0]))
    // {
    //     cout << "Trees are Same" << endl;
    // }
    // else
    // {
    //     cout << "Trees Are Not Same" << endl;
    // }

    // printTree(allNodes[0], 0);
    // printTree(allNodes2[0], 0);
    string preOrder = "";
    string inOrderTraversal = "";
    string postOrderTraversal = "";
    string levelOrder = "";

    // boundaryTraversal(allNodes[0]);
    // boundaryTraversal(allNodes2[0]);
    // preOrderTraversal(allNodes[0], preOrder);
    // inOrder(allNodes[0], inOrderTraversal);
    // postOrder(allNodes[0], postOrderTraversal);
    // levelOrderTraversal(allNodes[0], levelOrder, 2);
    // cout
    //     << "Preorder Traversal: " << preOrder << endl;
    // cout << "Inorder Traversal: " << inOrderTraversal << endl;
    // cout << "Postorder Traversal: " << postOrderTraversal << endl;
    // cout << "Level order Traversal: " << levelOrder << endl;
    return 0;
}
/*
9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6
*/

/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1
*/