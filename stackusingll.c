#include<stdio.h>
  #include<stdlib.h>
   #include<malloc.h>

   struct STACK
    {
       int data;
       struct STACK *link;
    };
    struct STACK *top=NULL,*p,*temp;
    void push()
     {
	int ele;


	printf("Enter the element:");
	scanf("%d",&ele);
	p=(struct STACK *) malloc(sizeof(struct STACK));
	p->data=ele;
	p->link=NULL;

	   if(top==NULL)
	    {
	      top=p;
	    }
	    else
	    {
	      p->link=top;
	    }
	    top=p;
     }
     void disp()
      {   
          int t;      
          temp=top;
		      //temp1=p;
	 if(top==NULL)
	  {
	    printf("\n There are no elements in the STACK");
	  }
	  else
	  {     printf("\n The STACK elements are:");

	    while(temp!=NULL)
	     {
		t=temp->data;

		printf("\t%d",t);

		temp=temp->link;
		//temp1=temp;
	     }
	  }
   }
	   void pop()
       {
		int t;
	      if(top==NULL)
		{
		  printf("There are no elements:");
		}
		else
		{
		   t=top->data;
		   printf("\n The deleted element is%d",t);
		   top=top->link;
		}
	   }


       void main()
	{  
	int ch;
	  while(1)
	  {    printf("\n\t\t\tSTACK OPERATIONS ARE");
	       printf("\n\t\t\t\t1.push");
	       printf("\n\t\t\t\t2.pop");
	       printf("\n\t\t\t\t3.disp");
	       printf("\n\t\t\t\t4.exit");
	       printf("\n\t\tEnter your choice:");
	       scanf("%d",&ch);
	   switch(ch)
	    {
		case 1:  
			 push();
			 break;
		case 2:  
			 pop();
			 break;
		case 3: disp();
			 break;
		case 4: exit(0);
			 break;
		default: printf("\n INVALID CHOICE, Try again:");
	     }

	 }
	 
}
