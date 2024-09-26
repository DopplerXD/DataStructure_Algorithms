#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    // Node(int x) { data = x, next = NULL; }
};
Node* createList()
{
    Node* newList = new Node;
    newList->next = NULL;
    return newList;
}
void insertNode(Node* L, int x)
{
    Node* p = L;
    while (p->next != NULL)
        p = p->next;
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    p->next = newNode;
}
void insertNode(Node* L, int x, int i)
{
    Node* p = L;
    int j = 0;
    while (p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
}
bool ifEmpty(Node* L)
{
    if (L->next == NULL)
        return true;
    return false;
}
void deleteNode(Node* L)
{
    if (ifEmpty(L))
    {
        cout << "Error!" << endl;
        return;
    }
    Node* p = L;
    while (p->next->next != NULL)
        p = p->next;
    p->next = NULL;
}
void deleteNode(Node* L, int i)
{
    if (ifEmpty(L))
    {
        cout << "Error!" << endl;
        return;
    }
    Node* p = L;
    int j = 1;
    while (p->next->next != NULL && j < i)
        p = p->next, j++;
    if (p->next->next == NULL && j < i)
    {
        cout << "Error!" << endl;
        return;
    }
    p->next = p->next->next;
}
void searchNode(Node* L, int i)
{
    Node* p = L;
    int j = 0;
    while (p->next != NULL && j < i)
        p = p->next, j++;
    if (p->next == NULL && j < i)
    {
        cout << "Error!" << endl;
        return;
    }
    cout << p->data << endl;
}
void getElem(Node* L, int i, int& e)
{
    Node* p = L;
    int j = 0;
    while (p->next && j < i)
        p = p->next, j++;
    if (!p || j > i) return 0;
    e = p->data;
}
int getLength(Node* L)
{
    Node* p = L;
    int len = 0;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
void output(Node* L)
{
    Node* p = L->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void test()
{
    Node* L = createList();
    cout << ifEmpty(L) << endl;
    insertNode(L, 4);
    insertNode(L, 5);
    insertNode(L, 6);
    insertNode(L, 10, 2);
    cout << ifEmpty(L) << endl << getLength(L) << endl;
    output(L);
    deleteNode(L);
    output(L);
    deleteNode(L, 4);
    deleteNode(L, 2);
    output(L);
    searchNode(L, 2);
}
int main()
{
    test();
    return 0;
}
