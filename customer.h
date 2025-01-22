#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include "main_menu.h"
struct customer
{
int cust_id;
char cust_name[20];
char cust_city[20];
int cust_mob_no[11];
char cust_email[50];
};
struct customer temp_c;
FILE *ptr1;
char fname_c[]={"customer.dat"};
void customer()
{
	int choice=0;
	while(choice!=9)
	{
	  system("cls");

	  printf("\t\t\t\t");

	   printf("===============================================\n\n");

	   printf("\t\t\t\t");

	   printf("\t\t");

	  printf("---------------\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("*********Customer Menu*********\n\n");

	  printf("\t\t\t\t");

	  printf("\t\t");

	  printf("---------------\n\n");

	   printf("\t\t\t\t");

        printf("===============================================\n\n");

	  printf("\t\t\t\t");

	  printf("Choose one option from the following list ...\n\n");

        printf("\t\t\t\t");

        printf("\t");

	  printf("1.Add New Customer\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("2.Update Customer\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("3.Search Customer id\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("4.Search Customer name\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("5.List of Existing Customer\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("6.List of a particular customer\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("7.delete Existing Customer\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("8.Main Menu\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	   printf("Enter your choice?");

        scanf("%d",&choice);

	  switch(choice)
	  {
		case 1:
		    cust_entry();
			 break;
		case 2:
		    cust_update();
			 break;
		case 3:
		    search_c_id();
			 break;
        case 4:
             search_c_name();
			 break;
		case 5:
		    sort_id();
			 break;
        case 6:
            cust_list_id();
            break;
        case 7:
            cust_delete();
            break;
		case 8:main_menu();
			 break;
		default:

		    printf("\t\t\t\t");
			printf("Please enter valid choice..");
	  }
	}

}


void cust_entry()
{
    system("cls");
 FILE *fp;
struct customer t1;

fp=fopen(fname_c,"ab");
printf("\t\t\t\t");

	   printf("===============================================\n\n");

	   printf("\t\t\t\t");

	   printf("\t\t");

	  printf("---------------\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("****Customer Entry Menu****\n\n");

	  printf("\t\t\t\t");

	  printf("\t\t");

	  printf("---------------\n\n");

	   printf("\t\t\t\t");

        printf("===============================================\n\n");

printf("\n\t\t\t\tEnter ID:");
scanf("%d",&t1.cust_id);
int r=t1.cust_id;
if(avlid(r)==1){
    printf("\n\n\t\t\t\tID already exists");
    printf("\n\t\t\t\tEnter ID:");
    scanf("%d",&t1.cust_id);
}
printf("\n\t\t\t\tEnter name:");
scanf("%s",t1.cust_name);
printf("\n\t\t\t\tEnter city:");
scanf("%s",&t1.cust_city);
printf("\n\t\t\t\tEnter mobile number:");
ventry(t1.cust_mob_no,1);
printf("\n\t\t\t\tEnter email:");
scanf("%s",&t1.cust_email);
fwrite(&t1,sizeof(t1),1,fp);

fclose(fp);
}

//=========FOR CUSTOMER DISPLAY LIST ==========
void cust_list()
{
    system("cls");
FILE *fp;
struct customer t;

fp=fopen(fname_c,"rb");
if(fp==NULL)
	   {

		printf("\n\t Can not open File! ");

		exit(0);
	   }
printf("\n\n\n");
printf("\t\t\t\t========================================================\n\n");
printf("\t\t\t\t\t\t All customer Details\n\n");

printf("\t\t\t\tID\tName\tcity\tmobile number\temail\n\n");
printf("\t\t\t\t========================================================\n\n");


while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
printf("\t\t\t\t%d\t",t.cust_id);
printf("%s\t",t.cust_name);
printf("%s\t",t.cust_city);
printf("%s\t",t.cust_mob_no);
printf("%s\t\n\n",t.cust_email);

}
printf("\t\t\t\t========================================================\n\n");

fclose(fp);
getche();
}
void cust_list_id()
{
    system("cls");
    FILE *fp;
struct customer t;
int id,found=0;

fp=fopen(fname_c,"rb");

printf("\n\t\t\t\t\tEnter the customer ID:");
scanf("%d",&id);
if(fp==NULL)
	   {

		printf("\n\t Can not open File! ");

		exit(0);
	   }

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(t.cust_id==id)
{
found=1;
printf("\n\t\t\t\t========================================================\n\n");
printf("\t\t\t\t\t customer Details of %d\n\n",t.cust_id);
printf("\t\t\t\t========================================================\n\n");

printf("\t\t\t\t\tName\tcity\tmobile number\temail\n\n");

printf("\t\t\t\t\t%s\t",t.cust_name);
printf("%s\t",t.cust_city);
printf("%s\t",t.cust_mob_no);
printf("%s\t\n\n",t.cust_email);

printf("\t\t\t\t========================================================\n\n");
}
}
if(found==0)
{
printf("\n\t\t\t\tSorry No Record Found");
}
fclose(fp);
getche();
}
//======================search CUSTOMER==================

//===========================Search by CustomerId=========================
void search_c_id()
{
    system("cls");
 FILE *fp2;
 struct customer temp_c;
 int r, s, avl;
 printf("\n\t\t\t\t\tEnter the ID you want to search  :");
 scanf("%d", &r);
 avl = avlid(r);
 if (avl == 0)
  printf("\n\n\t\t\t\t\tCustomer ID %d is not available in the file\n",r);
 else
 {
  fp2 = fopen(fname_c, "rb");
  while (fread(&temp_c, sizeof(temp_c), 1, fp2))
  {
   s = temp_c.cust_id;
   if (s == r)
   {
    printf("\n\t\t\t\t========================================================\n\n");
    printf("\t\t\t\t\t customer Details of ID number%d\n\n",temp_c.cust_id);
    printf("\t\t\t\t========================================================\n\n");

    printf("\t\t\t\t\tName\tcity\tmobile number\temail\n\n");

    printf("\t\t\t\t\t%s\t",temp_c.cust_name);
    printf("%s\t",temp_c.cust_city);
    printf("%s\t",temp_c.cust_mob_no);
    printf("%s\t\n\n",temp_c.cust_email);

printf("\t\t\t\t========================================================\n\n");
   }
  }
  fclose(fp2);
 }
  getche();
}
/*****************************search by CUSTOMERname******************************/
void search_c_name()
{
    system("cls");
  FILE *fp;
struct customer t;
int found=0;
char name[20];

fp=fopen(fname_c,"rb");
if(fp==NULL)
	   {

		printf("\n\t\t\t\t\t Can not open File! ");

		getche();
		customer();
	   }

printf("\n\t\t\t\tEnter the customer Name:");
scanf("%s",&name);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(strcmp(name,t.cust_name)==0)
{
    found=1;
   printf("\n\t\t\t\t========================================================\n\n");
    printf("\t\t\t\t\t customer Details of name is %s\n\n",t.cust_name);
    printf("\t\t\t\t========================================================\n\n");

    printf("\t\t\t\t\tid\tcity\tmobile number\temail\n\n");

    printf("\t\t\t\t\t%d\t",t.cust_id);
    printf("%s\t",t.cust_city);
    printf("%s\t",t.cust_mob_no);
    printf("%s\t\n\n",t.cust_email);

printf("\t\t\t\t========================================================\n\n");
}
}
if(found==0)
{
printf("\n\t\t\t\tSorry No Record Found");
}
fclose(fp);
  getche();
}
//============CUSTOMER update=================
void cust_update()
{
    system("cls");
  FILE *fp,*fp1;
struct customer t,t1;
int id,found=0,count=0;

fp=fopen(fname_c,"rb");
fp1=fopen("temp_c.dat","wb");
if(fp==NULL)
	   {

		printf("\n\t\t\t\t\t Can not open File! ");

		exit(0);
	   }

printf("\n\t\t\t\tEnter the customer ID you want to Modify:");
scanf("%d",&id);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(t.cust_id==id)
{
found=1;
printf("\n\t\t\t\tEnter customer ID:");
scanf("%d",&t.cust_id);

fflush(stdin);
printf("\n\t\t\t\tEnter customer Name:");
scanf("%s",t.cust_name);
printf("\n\t\t\t\tEnter customer city:");
scanf("%s",t.cust_city);
printf("\n\t\t\t\tEnter customer mobile number:");
ventry(t.cust_mob_no,1);
printf("\n\t\t\t\tEnter email:");
scanf("%s",t.cust_email);

fwrite(&t,sizeof(t),1,fp1);
}
else
{
fwrite(&t,sizeof(t),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("\t\t\t\tSorry No Record Found\n\n");
}
else
{
fp=fopen(fname_c,"wb");
fp1=fopen("temp_c.dat","rb");

while(1)
{
fread(&t,sizeof(t),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&t,sizeof(t),1,fp);
}

}
fclose(fp);
fclose(fp1);
  getche();
      }
void cust_delete()
{
    system("cls");
    FILE *fp,*fp1;
struct customer t,t1;
int id,found=0,count=0;

fp=fopen(fname_c,"rb");
fp1=fopen("temp_c.dat","wb");
if(fp==NULL)
	   {

		printf("\n\t\t\t\t\t Can not open File! ");

		exit(0);
	   }

printf("\n\t\t\t\tEnter the customer ID you want to Delete:");
scanf("%d",&id);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(t.cust_id==id)
{
found=1;
}
else
{
fwrite(&t,sizeof(t),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("\t\t\t\tSorry No Record Found\n\n");
}
else
{
fp=fopen(fname_c,"wb");
fp1=fopen("temp_c.dat","rb");

while(1)
{
fread(&t,sizeof(t),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&t,sizeof(t),1,fp);
}
}
fclose(fp);
fclose(fp1);
}

int avlid(int id)
{
 FILE *fp;
 struct customer temp_c;
 int c = 0;
 fp = fopen(fname_c, "rb");
 while (!feof(fp))
 {
  fread(&temp_c, sizeof(temp_c), 1, fp);

  if (id== temp_c.cust_id)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
//FUNCTION
void sort_id()
{
    system("cls");
    struct customer temp_c;
 int a[2000], count = 0, i, j, t, c;
 FILE *fpo;
 fpo = fopen(fname_c, "rb");
 while (fread(&temp_c, sizeof(temp_c), 1, fpo))
 {
  a[count] = temp_c.cust_id;
  count++;
 }
 c = count;
 for (i = 0; i<count - 1; i++)
 {
  for (j = i + 1; j<count; j++)
  {
   if (a[i]>a[j])
   {
    t = a[i];
    a[i] = a[j];
    a[j] = t;
   }
  }
 }
printf("\n\t\t\t\t========================================================\n\n");
printf("\t\t\t\t\t sorted list of customer details\n\n");
printf("\t\t\t\t========================================================\n\n");
printf("\t\t\t\tID.\tName\tCity\tMobile Number\tEmail\n");
printf("\n\t\t\t\t========================================================\n\n");
 count = c;
 for (i = 0; i<count; i++)
 {
  rewind(fpo);
  while (fread(&temp_c, sizeof(temp_c), 1, fpo))
  {
   if (a[i] == temp_c.cust_id)
    printf("\n \t\t\t\t%d\t %s \t %s\t%s\t%s\n",temp_c.cust_id, temp_c.cust_name,temp_c.cust_city,temp_c.cust_mob_no,temp_c.cust_email);
  }

 }
  printf("\n\t\t\t\t========================================================\n\n");
 getche();

}
#endif // CUSTOMER_H_INCLUDED
