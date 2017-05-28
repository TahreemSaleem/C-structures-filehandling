# include <stdio.h>
#define SIZE 10
struct info
{	
	int rollnumber;
	char name[20];
	int marks;
}e[SIZE];
int main()
{
	int sum=0,i,rollnumber,marks; 
	char name[30];
	float average=0;
	FILE *myfile;
	
	//opening file
	myfile = fopen("test.txt", "w");
	for (i=0; i<SIZE; i++)
	{   
   

		printf ("Enter Rollnumber of student no. %d: ", i+1);
		scanf ("%d", &e[i].rollnumber); 
		
		printf ("Enter Name of student no. %d: ", i+1);
		scanf ("%s", &e[i].name);
	
		
		printf ("Enter marks of student No. %d: ", i+1);
		scanf ("%d", &e[i].marks);
		
		fprintf (myfile,"%20d%28s%20d\n", e[i].rollnumber, e[i].name,  e[i].marks);
        sum=sum+e[i].marks;
			
		
		printf ("\n");
	}fclose(myfile); //closeing file

	 average=(float)(sum/SIZE);
	
	
	printf ("%20s%28s%20s\n","Rollnumber","Name","Marks");
	
	
	myfile = fopen("test.txt", "r");		//opening file again
	while (!feof(myfile))
	{		
		fscanf (myfile,"%20d%28s%20d\n",&rollnumber, name, &marks);
		printf ("%20d%28s%20d\n", rollnumber, name,  marks);
	}
	fclose(myfile);				//fileclosed

	
	 printf("the averge is %.2f",average);
	
	return 0;
}
