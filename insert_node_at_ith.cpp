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
        next = NULL;
    }
};
Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
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
    cout<<endl;
}
Node *insertNode(int i, Node *head, int data)
{
    int count = 0;
    Node *temp = head;
    Node *newnode = new Node(data);
    if (i == 0)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    while (count < i - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}
int main()
{
    Node *head = takeinput();
    print(head);
    int i, data;
    cin >> i >> data;
    head = insertNode(i, head, data);
    print(head);
    return 0;
}