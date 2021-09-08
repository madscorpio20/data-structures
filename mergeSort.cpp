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
Node *midPoint(Node *head)
{
  if(head == NULL || head->next == NULL)
  {
      return head;
  }
    Node *slow = head;
    Node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if(head1 == head2 || head2 == NULL || head1 == NULL)
    {
         if(head1 == NULL)
             return head2;
        else
            return head1;
    }
    Node *fh = NULL;
    Node *ft = NULL;
    if(head1->data < head2->data)
    {
        fh = head1;   // first head
        ft = head1;   // first tail
        head1 = head1->next;
    }
    else
    {
        fh = head2;
        ft = head2;
        head2 = head2->next;
    }
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data < head2->data)
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
    while(head1!=NULL)
    {
        ft->next = head1;
        ft = head1;
        head1 = head1->next;
    }
    while(head2!=NULL)
    {
        ft->next = head2;
        ft = head2;
        head2 = head2->next;
    }
    return fh;
    
}
Node *mergeSort(Node *head)
{
	if(head == NULL || head->next == NULL)
        return head;
    Node *mid = midPoint(head);
    Node *head1 = head;
    Node *head2 = mid->next;
    mid->next = NULL;
    Node *temp1 = mergeSort(head);
    Node *temp2 = mergeSort(head2);
    Node *finalhead = mergeTwoSortedLinkedLists(temp1,temp2);    
    return finalhead;
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}