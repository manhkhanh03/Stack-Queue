#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int msv;
    string name;
};

struct Node
{
    Student *data;
    Node *next;
};

struct Stack
{
    Node *top;
};

Student *createStudent(Student *Sv)
{
    Sv = new Student;
    cout << "\nNhap msv: ", cin >> Sv->msv;
    cout << "Nhap name: ", cin >> Sv->name;
    return Sv;
}

Node *createNode(Student *Sv)
{
    Node *p = new Node;
    p->data = createStudent(Sv);
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

void push(Stack &S, Student *Sv)
{
    Node *p = createNode(Sv);
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
    Student *Sv = S.top->data;
    cout << "Name: " << Sv->name << endl;
    cout << "Masv: " << Sv->msv << endl;
}

void out(Stack S)
{
    Node *p = S.top;
    while (p != NULL)
    {
        Student *Sv = p->data;
        cout << "Masv: " << Sv->msv << endl;
        cout << "Name: " << Sv->name << endl;
        p = p->next;
    }
}

int main()
{
    Student *Sv;
    Stack S;
    createStack(S);
    push(S, Sv);
    push(S, Sv);
    // pop(S);
    out(S);
    // top(S);
}