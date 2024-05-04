#include <iostream>

using namespace std;

typedef int Info; 

struct Elem
{
    Elem* link;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
void Print(Elem* L);
bool hasAdjacentDuplicates(Elem* L);
void del(Elem* L, Info number);

int main()
{
    Elem* first = NULL,
        * last = NULL;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        Info value;
        cin >> value;
        enqueue(first, last, value);
    }

    Print(first);

    if (hasAdjacentDuplicates(first))
        cout << "(Y)The list contains a pair of adjacent elements with the same values." << endl;
    else
        cout << "(N)The list does not contain a pair of adjacent elements with the same values." << endl;

    return 0;

}

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

void Print(Elem* L)
{
    while (L != NULL)
    {
        cout << L->info << " ";
        L = L->link;
    }
    cout << endl;
}

bool hasAdjacentDuplicates(Elem* L)
{
    while (L != NULL && L->link != NULL)
    {
        if (L->info == L->link->info)
            return true;
        L = L->link;
    }
    return false;
}
void del(Elem* L, Info number)
{
    while (L != NULL && L->link != NULL) {
        if (L->link->info > number) {
            Elem* tmp = L->link->link;
            delete L->link;
            L->link = tmp;
        }
        else
            L = L->link;
    }
}
