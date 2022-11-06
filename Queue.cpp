#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *first;
    Node *last;
};

void createQueue(Queue &Q)
{
    Q.first = Q.last = NULL;
}

Node *createNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

bool isEmpty(Queue Q)
{
    return Q.first == NULL ? true : false;
}

void enQueue(Queue &Q, int x)
{
    Node *p = createNode(x);
    if (isEmpty(Q))
        Q.first = p;
    else
        Q.last->next = p;
    Q.last = p;
}

void deQueue(Queue &Q)
{
    if (!isEmpty(Q))
    {
        Node *p = Q.first;
        Q.first = p->next;
        delete p;
    }
}

void front(Queue Q)
{
    if (isEmpty(Q))
        cout << "Rong!";
    else
    {
        Node *p = Q.first;
        cout << p->data;
    }
}

int main()
{
    Queue Q;
    createQueue(Q);

    enQueue(Q, 6);
    deQueue(Q);
    enQueue(Q, 4);

    front(Q);
}