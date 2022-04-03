#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rec
{
    char day[10];
    char climate[10];
    char pattern[100];
};

void Addrec(struct rec* journal) { 
	char tmp[100]; 
    printf("\n\t\t**************************\n");
    printf("\t\t* WELCOME TO THE ADD MENU *");
    printf("\n\t\t**************************\n");
    printf("\n\t ENTER DATE OF YOUR RECORD\t ");
    printf("\n\t (NOTE: Format is 0112000 or 01Jan2000)\t :");
    scanf("%s", tmp);

    strcpy(journal->day, tmp); 
    printf("\t ENTER CLIMATE OF THE DAY\t\t : ");
    scanf("%s", tmp);

    strcpy(journal->climate, tmp); 
    printf("\t ENTER PATTERN OF THE DAY\t\t : ");
    scanf("%s",tmp);

    strcpy(journal->pattern, tmp); 
    printf("\n\n\t\t      *****************\n");
    printf("\t\t      *EXITED ADD MENU* ");
    printf("\n\t\t      *****************\n");
}

int Viewrec(char tmp[100],struct rec* journal)
{
    int flag = 0;
    char a[100]; 
    if (strcmp(tmp, journal->day) == 0)
    {
        flag = 1;
        printf("\t\tDATE\t : %s\n\t\tCLIMATE\t : %s\n\t\tPATTERN\t : %s\n", journal->day, journal->climate, journal->pattern);
        return 1; 
    }
     if (flag==0)
   	{
    	return 0;
	}
}
 
int main()
{
  int ch,i=0;
  char realkey[6] = "12345";
  char key[6];
  struct rec journal [100];
  int flag=0,viewflag=0;
  char tmp[100];
  
  printf("\n\t\t********************************");
  printf("\n\t\t KEY PROTECTED PERSONAL JOURNAL");
  printf("\n\t\t********************************");
  
  printf("\nKindly Enter key: ");
  scanf("%s",key);
  
  if(strcmp(key,realkey)==0)
  {
      	printf("\n\t****LOGIN YOUR JOURNAL****\n\nMake A Choice of Action");
      	printf("\n\t 1. Add Record");
    	printf("\n\t 2. View Record");
        printf("\n\t 3. Exit Record");
  }
  else{
      while(1)
      {
          printf("Re-enter key: ");
           scanf("%s",key);
           if(strcmp(key,realkey)==0)
           {
               printf("\n\t****LOGIN YOUR JOURNAL****\n\nMake A Choice of Action");
               printf("\n\t 1. Add Record");
    		   printf("\n\t 2. View Record");
        	   printf("\n\t 3. Exit Record");
               break;
           }
      }
  
    
  }

while(1){
		printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        if(ch == 3)
		{
        	printf("\n\n\t\t CLOSE THE JOURNAL\n");
        	break;
        }
switch(ch)
{
    case 1:
        Addrec(&journal[i]);
        i++;
        break;

    case 2:
        printf("\n\n\t****************************");
        printf("\n\t *HERE IS THE VIEWING MENU*");
        printf("\n\t****************************");
        printf("\n Enter date of your record : ");
        scanf("%s",tmp);
        int j;
        for (j = 0; j <= i; j++)
        {
             if (Viewrec(tmp, &journal[j]) == 1)
            {
            	printf("\n\n\t\t******************\n");
            	printf("\t\t *EXIT VIEW MENU*");
            	printf("\n\t\t******************\n");
            	viewflag = 1;
            	break;
            }
        }
    if (viewflag == 0)
    {
        printf("\n\n\t\t***********************");
        printf("\n\t\t* THERE IS NO RECORD *");
    }
        break;
	

		
    default:
    	printf("\n\t\t** ENTER VALID CHOICE **");	
}
}
    return 0;
}



