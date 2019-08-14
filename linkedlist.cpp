
#include<bits/stdc++.h>
#include<cmath>

using namespace std;

struct point
{
  int data1;
  int data2;
}pt;
struct Node
{
  struct point pt;
  Node *next;
};
struct Node *head = NULL;

void AddFirst(int x,int y)
{
  Node *temp = new Node;
  temp -> pt.data1 = x;
  temp -> pt.data2 = y;
  if(head == NULL)
  {
    head = temp;
    return ;
  }
  temp -> next = head;
  head = temp;
  return ;
}

void DelFirst()
{
  if(head == NULL)
  {
    cout << "-1";
    return ;
  }
  if(head -> next == NULL)
  {
    delete(head);
    head == NULL;
    return ;
  }
  Node *temp = head;
  head = head -> next;
  delete(temp);
  return ;
}

void Del(int x, int y)
{
  Node *temp = head;
  Node *temp1 = NULL;
  Node *prev = NULL;
  while(temp != NULL)
  {
    if(temp -> pt.data1 == x && temp -> pt.data2 == y)
    {
      break;
    }
    prev=temp;
    temp = temp -> next;
  }
  if(temp == NULL)
  {
    cout << "-1"<<endl;
    return ;
  }
  temp1 = temp -> next;
  if(temp == head)
  {
    DelFirst();
    return ;
  }
  delete(temp);
  prev -> next = temp1;
  return ;
}

float distance(int a, int b)
{
  float  d;
  d = sqrt ((a*a)+(b*b));
  return d;
}
void search(float d)
{
  int n=0;
  Node *temp;
  temp=head;
  while(temp)
  {
    if(distance(temp -> pt.data1 , temp -> pt.data2) <= d)
    {
      n++;
    }
    temp = temp -> next;
  }
  if(n==0)n--;
  cout << n << endl;
}

void search(int x, int y)
{
  Node *temp;
  int n=0;
  temp = head;
  while(temp != NULL)
  {
    if(temp -> pt.data1 == x && temp -> pt.data2 == y)
    {
      n++;
      temp = temp -> next;
      continue;
    }
    temp = temp -> next;
  }
  if(n>0)
  {
   cout << "True" <<  endl;
  }
  if(n==0)
  {
   cout << "False" << endl;
  }

  return ;
}

void length()
{
  int l=0;
  Node *temp;
  temp = head;
  while(temp)
  {
    l++;
    temp = temp -> next;
  }
  cout << l<<endl;
  return ;
}
void print()
{
  Node *temp=head;
  while(temp)
  {
    cout << "(" << temp -> pt.data1 << "," << temp -> pt.data2 << ")" << endl;
    temp = temp -> next;
  }
}

int main(void)
{
  int choice;
  int x,y;
  float d;
  int test;
  cin >> test;
  while(test--)
  {
    cin >> choice;
  switch(choice)
  {
    case 1:   cin >> x >> y;
              AddFirst(x,y);
              break;
    case 2:   DelFirst();
              break;
    case 3:   cin >> x >> y;
              Del(x,y);
              break;
    case 4:   cin >> d;
              search(d);
              break;
    case 5:   cin >> x >> y;
              search(x,y);
              break;
    case 6:   length();
              break;
    case 7:   print();
              break;
  }
 }
}

