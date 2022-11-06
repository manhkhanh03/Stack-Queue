#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Stack
{
    Node *top;
};

Node *createNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void createStack(Stack &S)
{
    S.top = NULL;
}

bool isEmpty(Stack S)
{
    return S.top == NULL ? true : false;
}

void push(Stack &S, int x)
{
    Node *p = createNode(x);
    if (isEmpty(S))
        S.top = p;
    else
    {
        p->next = S.top;
        S.top = p;
    }
}

void pop(Stack &S)
{
    if (S.top == NULL)
        cout << "Rong!";
    else
    {
        Node *p = S.top;
        S.top = p->next;
        delete p;
    }
}

void top(Stack S)
{
    cout << S.top->data << " ";
}

void out(Stack S)
{
    Node *p = S.top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    Stack S;
    createStack(S);
    push(S, 7);
    push(S, 4);
    pop(S);
    out(S);
    top(S);
}