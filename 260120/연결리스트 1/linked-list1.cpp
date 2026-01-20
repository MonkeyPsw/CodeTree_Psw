#include <iostream>

using namespace std;

string S_init;
int N;
int command[250000];
string S_value[250000];

struct Node {
    string str;
    Node *prev, *next;
    Node(string str) : str(str), prev(nullptr), next(nullptr) {}
};

void InsertNext(Node *u, Node *singleton)
{
    singleton->prev = u;
    singleton->next = u->next;

    if (singleton->prev != nullptr)
        singleton->prev->next = singleton;
    if (singleton->next != nullptr)
        singleton->next->prev = singleton;
}

void InsertPrev(Node *u, Node *singleton)
{
    singleton->prev = u->prev;
    singleton->next = u;

    if (singleton->prev != nullptr)
        singleton->prev->next = singleton;
    if (singleton->next != nullptr)
        singleton->next->prev = singleton;
}

void Pop(Node *u)
{
    if (u->prev != nullptr)
        u->prev->next = u->next;
    if (u->next != nullptr)
        u->next->prev = u->prev;

    u->prev = u->next = nullptr;
}

void Print(Node *u)
{
    if (u->prev != nullptr)
        cout << u->prev->str;
    else
        cout << "(Null)";

    cout << " " << u->str << " ";

    if (u->next != nullptr)
        cout << u->next->str;
    else
        cout << "(Null)";
    
    cout << endl;
}

int main() {
    cin >> S_init;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == 1 || command[i] == 2) {
            cin >> S_value[i];
        }
    }

    Node *cur = new Node(S_init);

    for (int i = 0; i < N; i++)
    {
        if (command[i] == 1)
        {
            Node *val = new Node(S_value[i]);
            InsertPrev(cur, val);
        }
        else if (command[i] == 2)
        {
            Node *val = new Node(S_value[i]);
            InsertNext(cur, val);
        }
        else if (command[i] == 3)
        {
            if (cur->prev != nullptr)
                cur = cur->prev;
        }
        else
        {
            if (cur->next != nullptr)
                cur = cur->next;
        }

        Print(cur);
    }

    return 0;
}
