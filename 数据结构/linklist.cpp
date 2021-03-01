#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    Node *next;
}Node ,*LinkList;
bool Init(LinkList &l)
{
    l->next = NULL;
    l->data = 0;
    return true;
}
bool LinkListInsert(int elem,LinkList &l) //there is headinsert
{
    Node *tmp = new Node;
    tmp->data = elem;
    tmp->next = l->next;
    l->next = tmp;
    l->data++;
    return true;
}
bool LinkListDelete(int elem,LinkList &l)
{
    LinkList p;
    p = l->next;
    while(p->next->next != NULL)
    {
        if(p->next->data == elem)
        {
            p->next = p->next->next;
            p->data = p->next->data;
            return true;
        }
        p = p->next;
    }
    if(p->next->data == elem)
    {
        p->next = NULL;
        return true;
    }
    else
    {
        return false;
    }
}
int GetElem(int location,LinkList l)
{
    int elem = 0;
    while(elem != location)
    {
        l = l->next;
    }
    elem = l->data;
    return elem;
}
int LocateElem(int elem,LinkList l)
{
    int locat = 0;
    return locat;
}
bool DestroyLinkList(LinkList &l)
{
    Node *tmp;
    while(l->next != NULL)
    {
        tmp = l->next;
        delete l;
        l = tmp;
    }
    return true;
}
void PrintLinkList(LinkList l)
{
    int i = 0;
    while(l->next != NULL)
    {
        cout<<"this is "<<i<<' '<<l->data<<endl;
        i++;
        l = l->next;
    }
    cout<<"this is "<<i<<' '<<l->data<<endl;
    return;
}
bool Empty(LinkList l)
{
    if(l->next == NULL)
    return true;
    else
    return false;
}
int main()
{
    cout<<'1'<<endl;
    LinkList l = new Node;
    Init(l);
    Empty(l);
    cout<<l->data<<' '<<l->next<<endl;
    LinkListInsert(1,l);
    LinkListInsert(2,l);
    LinkListInsert(3,l);
    PrintLinkList(l);
    cout<<endl;
    LinkListDelete(1,l);
    PrintLinkList(l);
    cout<<endl;
    LinkListInsert(5,l);
    PrintLinkList(l);
    DestroyLinkList(l);
    return 0;
}
