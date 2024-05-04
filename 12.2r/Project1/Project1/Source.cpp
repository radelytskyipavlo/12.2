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
void inputElements(Elem*& first, Elem*& last, int n);

int main()
{
    Elem* first = NULL,
        * last = NULL;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:" << endl;

    inputElements(first, last, n);

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
    if (L != NULL)
    {
        cout << L->info << " ";
        Print(L->link);
    }
    else
    {
        cout << endl;
    }
}

bool hasAdjacentDuplicates(Elem* L)
{
    if (L == NULL || L->link == NULL)
        return false;
    if (L->info == L->link->info)
        return true;
    return hasAdjacentDuplicates(L->link);
}

void inputElements(Elem*& first, Elem*& last, int n)
{
    if (n > 0) {
        Info value;
        cin >> value;
        enqueue(first, last, value);
        inputElements(first, last, n - 1);
    }
}
