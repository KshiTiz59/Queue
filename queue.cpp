1. WAP to implement Queue.
a. Insert an element into the queue.
b. Delete an element from the queue.
c. Display the contents of the queue.

2. WAP to implement Circular Queue.
a. Insert an element into the circular queue.
b. Delete an element from the circular queue.
c. Display the contents of the circular queue.
  
3. WAP to implement Double Ended Queue.
a. Insert an element into the double ended queue.
b. Delete an element from the double ended queue.
c. Display the contents of the double ended queue.
  
4. WAP to implement Priority Queue.
a. Insert an element into the priority queue.
b. Delete an element from the priority queue.
c. Display the contents of the priority queue.
  
5.WAP to implement a stack using queues.
6. WAP to implement a queue using stacks.
7.WAP to implement n stacks in a single array.
8.WAP to implement n queues in a single array.
9.WAP to implement Stack using Linked List.
10.WAP to implement Queue using Linked List.
  
  //Q1:
  #include <stdio.h>
#define max 10 
int queue_array[max];
int rear = - 1;
int front = - 1;

void insert()
{
    int add_item;
    if (rear == max - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("Insert the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} 
void Delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} 
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
 }
}
in main()
{
insert();
insert();
insert();
insert();
insert();
display();
Delete();
Delete();
printf("Queue after deletion is :\n");
display();
} 
 

//Q2:
// circular queue
#include<bits/stdc++.h>
using namespace std;

class Queue
{
    public:
int front,rear;
int size,*arr;
Queue(int n)
{
    front=rear=-1;
    size=n;
    arr=new int[n];
}
void enQueue(int n);
int deQueue();
void displayQueue();
};
void Queue::enQueue(int value)
{
    if((front==0 &&rear==size-1)||(rear==(front-1)%(size-1)))
    {
    cout<<"Queue is Full"<<endl;
    }
    else if(front==-1)
    {
        front=rear=0;
        arr[rear]=value;
    }
    else if(rear==size-1 &&front!=0)
    {
        rear=0;
        arr[rear]=value;
    }
    else{
        rear++;
        arr[rear]=value;
    }
}

int Queue::deQueue()
{
    if(front==-1)
    cout<<"Queue is Empty"<<endl;
int data=arr[front];
arr[front]=-1;
if(front==rear)//last element
{
    front=rear=-1;
}
else if(front==size-1)
front=0;
else
front++;
return data;
}
void Queue::displayQueue()
{
    if(front==-1)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Elements in Circular Queue are :";
    if(rear>=front)
    {
        for(int i=front;i<=rear;i++)
        cout<<arr[i]<<" ";
    }
    else{
        for (int i = front; i < size; i++)
            printf("%d ", arr[i]);
 
        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
}

int main()
{
    Queue q(5);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
 q.displayQueue();
cout<<"\nDeleted element :"<<q.deQueue()<<endl;
cout<<"Deleted element :"<<q.deQueue()<<endl;
 q.displayQueue();
}

//Q3:
# include<stdio.h>
# define MAX 5

int deque_arr[MAX];
int left = -1;
int right = -1;

void insert_right()
{
	int added_item;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{	printf("Queue Overflow\n");
		return;}
	if (left == -1)  
	{	left = 0;
		right = 0;}
	else
	if(right == MAX-1)  
		right = 0;
	else
		right = right+1;
	printf("Input the element for adding in queue : ");
	scanf("%d", &added_item);
	deque_arr[right] = added_item ;
}

void insert_left()
{	int added_item;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{	printf("Queue Overflow \n");
		return;	 }
	if (left == -1)
	{	left = 0;
		right = 0;	 }
	else
	if(left== 0)
		left=MAX-1;
	else
		left=left-1;
	printf("Input the element for adding in queue : ");
	scanf("%d", &added_item);
	deque_arr[left] = added_item ;	 }

void delete_left()
{	if (left == -1)
	{	printf("Queue Underflow\n");
		return ;	}
	printf("Element deleted from queue is : %d\n",deque_arr[left]);
	if(left == right) 
	{	left = -1;
		right=-1;	 }
	else
		if(left == MAX-1)
			left = 0;
		else
			left = left+1;
}

void delete_right()
{if (left == -1)
	{printf("Queue Underflow\n");
		return ;	 }
	printf("Element deleted from queue is : %d\n",deque_arr[right]);
	if(left == right) 
	{	left = -1;
		right=-1;	 }
	else
		if(right == 0)
			right=MAX-1;
		else
			right=right-1;	}

void display_queue()
{	int front_pos = left,rear_pos = right;
	if(left == -1)
	{	printf("Queue is empty\n");
		return;	 }
	printf("Queue elements :\n");
	if( front_pos <= rear_pos )
	{	while(front_pos <= rear_pos)
		{	printf("%d ",deque_arr[front_pos]);
			front_pos++;	}	}
	else
	{	while(front_pos <= MAX-1)
		{	printf("%d ",deque_arr[front_pos]);
			front_pos++;	}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{	printf("%d ",deque_arr[front_pos]);
			front_pos++;
		}
	}
	printf("\n");
}

void input_que()
{	int choice;
	do
	{	printf("1.Insert at right\n");
		printf("2.Delete from left\n");
		printf("3.Delete from right\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{	case 1:
			insert_right();
			break;
		 case 2:
			delete_left();
			break;
		 case 3:
			delete_right();
			break;
		 case 4:
			display_queue();
			break;
		 case 5:
            break;
		 default:
			printf("Wrong choice\n");
		}
	}while(choice!=5);
}

void output_que()
{	int choice;
	do
	{	printf("1.Insert at right\n");
		printf("2.Insert at left\n");
		printf("3.Delete from left\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			insert_right();
			break;
		 case 2:
			insert_left();
			break;
		 case 3:
			delete_left();
			break;
		 case 4:
			display_queue();
			break;
		 case 5:
			break;
		 default:
			printf("Wrong choice\n");
		}
	}while(choice!=5);
}

int main()
{	int choice;
	printf("1.Input restricted dequeue\n");
	printf("2.Output restricted dequeue\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
	 case 1 :
		input_que();
		break;
	 case 2:
		output_que();
		break;
	 default:
		printf("Wrong choice\n");
	}
}
 
//Q4:
#include<stdio.h>
#define N 20
int Q[N],Pr[N];
int r = -1,f = -1;
void enqueue(int data,int p)
{
	int i;
	if((f==0)&&(r==N-1)) //Check if Queue is full
		printf("Queue is full");
	else
	{
		if(f==-1)//if Queue is empty
		{
			f = r = 0;
			Q[r] = data;
			Pr[r] = p;

		}
		else if(r == N-1)
	{
		for(i=f;i<=r;i++) { Q[i-f] = Q[i]; Pr[i-f] = Pr[i]; r = r-f; f = 0; for(i = r;i>f;i--)
			{
				if(p>Pr[i])
		{
			Q[i+1] = Q[i];
			Pr[i+1] = Pr[i];
		}
		else
			break;
		Q[i+1] = data;
				Pr[i+1] = p;
				r++;
			}
		}
	}
	else
	{
		for(i = r;i>=f;i--)
	{
		if(p>Pr[i])
		{
			Q[i+1] = Q[i];
			Pr[i+1] = Pr[i];	
		}
		else
			break;
	}
	Q[i+1] = data;
		Pr[i+1] = p;
		r++;
		}	
	}

}
void print() 
{
int i;
	for(i=f;i<=r;i++)
	{
		printf("\nElement = %d\tPriority = %d",Q[i],Pr[i]);
	}
}
int dequeue() 
{
	if(f == -1)
	{
		printf("Queue is Empty");
	}	
	else
	{
		printf("deleted Element = %d\t Its Priority = %d",Q[f],Pr[f]);
		if(f==r)
			f = r = -1;
		else
			f++;
	}
}
int main()
{
	int opt,n,i,data,p;
	printf("Enter Your Choice:-");
	do{
		printf("\n\n1 for Insert the Data in Queue\n2 for show the Data in Queue \n3 for Delete the data from the Queue\n0 for Exit");
		scanf("%d",&opt);
		switch(opt){
			case 1:
		printf("\nEnter the number of data");
		scanf("%d",&n);
		printf("\nEnter your data and Priority of data");
		i=0;
		while(i<n){
			scanf("%d %d",&data,&p);
			enqueue(data,p);
			i++;
		}
		break;
	case 2:
		print();
		break;
	case 3:
		 dequeue();
		break;
	case 0:
		break;
	default:
		printf("\nIncorrect Choice");

		}
	}while(opt!=0);
        return 0;
}

  //Q5:
#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop()
    {

        if (q1.empty())
            return;
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

};


int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<"Stack element are :"<<endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
     s.pop();
    cout << s.top() << endl;
     s.pop();
    cout << s.top() << endl;
    return 0;
}
  
 



//Q6:
    // Queue implementation using stack
#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int>s1;
    stack<int>s2;
    public:
    void Insert(int data)
    {
        s1.push(data);
        cout<<data<<" is inserted in Queue"<<endl;
    }
    int Delete(){
        if(s1.empty() && s2.empty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        if(s2.empty())
        {
            while(!s1.empty())
            {
              s2.push(s1.top());
              s1.pop();  
            }
            cout<<s2.top()<<" is deleted from the Queue"<<endl;
            s2.pop();
        }
    }
    void Display()
    {
        while(!s2.empty())
        {
            cout<<s2.top()<<" ";
            s2.pop();
        }
    }
};

int main()
{
    Queue q;
    q.Insert(10);
    q.Insert(20);
    q.Insert(30);
    q.Insert(40);
    q.Insert(50);
    q.Delete();
    cout<<"Contents of the Queue are:"<<endl;
    q.Display();
}



//Q9:


#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* link;
};
struct Node* top;

void push(int data)
{
	struct Node* temp = new Node();
	if (!temp)
	{
		cout << "\nHeap Overflow";
		exit(1);
	}

	temp->data = data;
	temp->link = top;
	top = temp;
}

int isEmpty()
{
	return top == NULL;
}

void pop()
{
	struct Node* temp;

	if (top == NULL)
	{
		cout << "\nStack Underflow" << endl;
		exit(1);
	}
	else
	{
		temp = top;
		top = top->link;
		temp->link = NULL;
		free(temp);
	}
}

void display()
{
	struct Node* temp;

	if (top == NULL)
	{
		cout << "\nStack Underflow";
		exit(1);
	}
	else
	{
		temp = top;
		while (temp != NULL)
		{
			cout << temp->data << "-> ";
			temp = temp->link;
		}
	}
}

int main()
{
	
	
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
cout<<"Elements in stack are :"<<endl;
	display();

	pop();
	pop();
cout<<"\n After popping stack is :"<<endl;
	display();

	return 0;
}




//Q10:

#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;   

void insert()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
  printf("Enter value :\n");  
  scanf("%d",&item);  
  ptr -> data = item;  
  if(front == NULL)  
  {  
      front = ptr;  
      rear = ptr;   
      front -> next = NULL;  
      rear -> next = NULL;  
  }  
  else   
  {  
      rear -> next = ptr;  
      rear = ptr;  
      rear->next = NULL;  
        }  
    }  
}   

void delete ()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  

void display()  
{  
      struct node *ptr;  
  ptr = front;      
  if(front == NULL)  
  {  
          printf("\nEmpty queue\n");  
  }  
  else  
  {   printf("\nprinting values .....\n");  
      while(ptr != NULL)   
      {  
              printf("\n%d\n",ptr -> data);  
          ptr = ptr -> next;  
      }  
    }  
}  

void main ()  
{  
  insert ();
  insert ();
  insert ();
  insert ();
  insert ();
  printf("Queue is :\n");
  display();
  delete ();
  delete ();
  printf("Queue after deletion is :\n");
  display();

}  
  




