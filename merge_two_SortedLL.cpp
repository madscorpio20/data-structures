#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if (head1 == head2 || head2 == NULL || head1 == NULL)
    {
        if (head1 == NULL)
            return head2;
        else
            return head1;
    }
    Node *fh = NULL;
    Node *ft = NULL;
    if (head1->data < head2->data)
    {
        fh = head1;         // final head
        ft = head1;         // final tail
        head1 = head1->next;
    }
    else
    {
        fh = head2;
        ft = head2;
        head2 = head2->next;
    }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            ft->next = head1;
            ft = head1;
            head1 = head1->next;
        }
        else
        {
            ft->next = head2;
            ft = head2;
            head2 = head2->next;
        }
    }
    while (head1 != NULL)
    {
        ft->next = head1;
        ft = head1;
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        ft->next = head2;
        ft = head2;
        head2 = head2->next;
    }
    return fh;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head1 = takeinput();
        Node *head2 = takeinput();
        Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
        print(head3);
    }
    return 0;
}