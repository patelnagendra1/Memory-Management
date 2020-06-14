#include<bits/stdc++.h>
using namespace std;
 struct node
 {
 	int data;
 	int start;

 	struct node *next;
 };

 	struct node *head;
 	struct node *cur;
 	int c=0;
 	
 std::vector<pair<int,int>> vs;	
 int search(int a)
 {
 	for(auto x:vs)
 	{
 		if(a > x.first && a < x.second)
 			return 0;
 	}
 	return 1;
 }
 void create()
 {

 	cout<<"Enter the starting address ";
 	int a;
 	cin>>a;
 	cout<<"Enter memory blocks"<<endl;
 	
 		int x;
 		cin>>x;
 		if(search(a)&& search(a+x))
 		{
	 		vs.push_back({a,a+x});

	 		if(head==NULL)
	 		{
	 			head=(struct node*)malloc(sizeof(struct node));
	 			head->data=x;
	 			head->next=NULL;
	 			head->start=a;
	 			cur=head;
	 			c++;
	 		}
	 		else
	 		{
	 		struct node *p;
	 		p=(struct node*)malloc(sizeof(struct node));
	 		p->data=x;
	 		p->next=NULL;
	 		p->start=a;
	 		cur->next=p;
	 		cur=p;
	 		c++;
	 		}
	 	}
	 	else
	 	{
	 		cout<<"\nmemory overlap"<<endl;
	 	}


 	
 }

 void traverse()
 {
 	cout<<"Free list => ";
 	struct node *p=head;
 	while(p!=NULL)
 	{
 		cout<<p->data<<" ";
 		p=p->next;
 	}
 	cout<<endl;
 	
 }
void swap(struct node *a, struct node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp;

    temp=a->start;
    a->start=b->start;
    b->start=temp; 
}

void bubbleSort() 
{ 
    int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
  
    /* Checking for empty list */
    if (head == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = head; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->start > ptr1->next->start) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}
vector<int>v[100];
void job()
{
	cout<<"Enter job ";
	int x;
	cin>>x;
	struct node *p=head;
	int cc=0;
	int max=100000;
	int flag=0;
	while(p!=NULL)
	{
		if((((p->data)-x) < max)&&((p->data))>=x)
		{
			max=p->data-x;
			
			flag=1;
		}
		
			p=p->next;
		
		
	}
	p=head;
	// cout<<"hii"<<endl;
	// cout<<max<<endl;
	
	while(((p->data-x)!=max)&&(p->next!=NULL))
	{
		p=p->next;
		cc++;
	}
	//cout<<cc<<endl;
	if(p!=NULL)
	{
		p->data=max;
		v[cc].push_back(x);
	}
	if(flag==0)
		cout<<"can't fit"<<endl;
}
void traverseadd()
{
	cout<<"occupied list =>\n";
	for (int i = 0; i < c; ++i)
	{
		if(v[i].size()==0)
			cout<<0<<endl;
		else
		{
			for(int j=0;j<v[i].size();j++)
			{
				cout<<v[i][j]<<" ";

			}
			cout<<endl;
			
		}
		/* code */
	}
	cout<<endl;
}
 int main()
 {
 	while(1)
 	{
 		cout<<"1) create"<<" "<<"2) traverse "<<"3) job "<<"4) end"<<endl;
 		int x;
 		cin>>x;
 		if(x==1)
 		{
 			cout<<endl;
	 		create();
	 		bubbleSort();
 		}
	 	if(x==2)
	 	{
	 		traverse();
	 		traverseadd();
	 	}
	 	if(x==3)
	 	{
	 		
	 		job();
	 	}
	 	if(x==4)
	 		break;
	 	cout<<endl;
	 }
 }