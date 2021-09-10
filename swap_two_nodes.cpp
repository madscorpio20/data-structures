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
	cout << endl;
}
Node *swapNodes(Node *head, int i, int j)
{
    int index1;
    int index2;
	if(i<=j)
    {
         index1 = i;
         index2 = j;
    }
    else
    {
         index1 = j;
         index2 = i;    
    }
    if(i==j)
        return head;
    if(index1==0 && index2-index1==1)
    {
        Node *curr1 = head;
        Node *prev2 = curr1;
        Node *curr2 = curr1->next;
        head = curr2;
        curr1->next = curr2->next;
        curr2->next = curr1;
        return head;
    }
    else if(index1 == 0 && index2-index1!=0)
    {
        Node *curr1 = head;
        Node *later1 = curr1->next;
        int count = 0;
        Node *temp = head;
        while(count< index2-1)
        {
            temp = temp->next;
            count++;
        }
        Node *prev2 = temp;
        Node *curr2 = temp->next;
        head = curr2;
        curr1->next = curr2->next;
        curr2->next = later1;
        prev2->next = curr1;
        return head;
    }
    else if(index1!=0 && index2-index1 == 1)
    {
        int count = 0;
        Node *temp = head;
        while(count<index1-1)
        {
            temp = temp->next;
            count++;
        }
        Node *prev1 = temp;
        Node *curr1 = temp->next;
        Node *curr2 = curr1->next;
        prev1->next = curr2;
        curr1->next = curr2->next;
        curr2->next = curr1;
        return head;
    }
    else if(index1!=0 && index2-index1!=0)
    {
        int count = 0;
        Node *temp = head;
        while(count<index1-1)
        {
            temp = temp->next;
            count++;            
        }
        Node *prev1 = temp;
        Node *curr1 = temp->next;
        while(count<index2-1)
        {
            temp =temp->next;
            count++;
        }
        Node *prev2 = temp;
        Node *curr2 = temp->next;
        Node *later2 = curr2->next;
        prev1->next = curr2;
        curr2->next = curr1->next;
        curr1->next = later2;
        prev2->next = curr1;
        return head;
    }
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}