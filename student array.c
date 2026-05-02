#include<stdio.h>
struct student
{
	int rno;
	char name[20];
	float per;
};
int main()
{
	struct student s[100];
	int n,i;
	float per;
	printf("enter no of students:\n");
	scanf("%d",&n);
	printf("enter student details:\n");
	for(i=0;i<n;i++)
	{
		printf("enter student %d rno:",i+1);
		scanf("%d",&s[i].rno);
		printf("enter student %d name:",i+1);
		scanf("%s",&s[i].name);
		printf("enter student %d per:",i+1);
		scanf("%f",&per);
		s[i].per=per;
	}
	printf("\n display student details");
	for(i=0;i<n;i++)
	{
		printf("\n %d %s %f",s[i].rno,s[i].name,s[i].per);
	}
	return 0;
}
