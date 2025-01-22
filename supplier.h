#ifndef SUPPLIER_H_INCLUDED
#define SUPPLIER_H_INCLUDED
#include "main_menu.h"
struct supplier
{
int supp_id;
char supp_name[20];
char supp_city[20];
int supp_mob_no[11];
char supp_email[50];
};
struct supplier temp1;
char fname_s[]={"supplier.dat"};
void supplier()
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

	  printf("*********Supplier Menu*********\n\n");

	  printf("\t\t\t\t");

	  printf("\t\t");

	  printf("---------------\n\n");

	   printf("\t\t\t\t");

        printf("===============================================\n\n");

	  printf("\t\t\t\t");

	  printf("Choose one option from the following list ...\n\n");

        printf("\t\t\t\t");

        printf("\t");

	  printf("1.Add New Supplier\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("2.Update Supplier\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("3.Search Supplier id\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("4.Search Supplier name\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("5.List of Existing Supplier\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("6.List of a particular Supplier\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("7.delete Existing Supplier\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("8.sort list with id\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("9.Main Menu\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	   printf("Enter your choice?");

        scanf("%d",&choice);

	  switch(choice)
	  {
		case 1:
		    supp_entry();
			 break;
		case 2:
		    supp_update();
			 break;
		case 3:
		    search_s_id();
			 break;
        case 4:
             search_s_name();
			 break;
		case 5:
		    sort_id_s();
			 break;
        case 6:
            supp_list_id();
            break;
        case 7:
            supp_delete();
            break;
		case 8:main_menu();
			 break;
		default:

		    printf("\t\t\t\t");
			printf("Please enter valid choice..");
	  }
	}

}


void supp_entry()
{
    system("cls");
 FILE *fp;
struct supplier t2;

fp=fopen(fname_s,"ab");
printf("\t\t\t\t");

	   printf("===============================================\n\n");

	   printf("\t\t\t\t");

	   printf("\t\t");

	  printf("---------------\n\n");

	  printf("\t\t\t\t");

	  printf("\t");

	  printf("*********Supplier Entry Menu*********\n\n");

	  printf("\t\t\t\t");

	  printf("\t\t");

	  printf("---------------\n\n");

	   printf("\t\t\t\t");

        printf("===============================================\n\n");

printf("\n\t\t\t\tEnter ID:");
scanf("%d",&t2.supp_id);
int r=t2.supp_id;
if(avlid_s(r)==1){
    printf("\n\n\t\t\t\tID already exists");
    printf("\n\t\t\t\tEnter ID:");
    scanf("%d",&t2.supp_id);
}
printf("\n\t\t\t\tEnter name:");
scanf("%s",t2.supp_name);
printf("\n\t\t\t\tEnter city:");
scanf("%s",&t2.supp_city);
printf("\n\t\t\t\tEnter mobile number:");
ventry(t2.supp_mob_no,1);
printf("\n\t\t\t\tEnter email:");
scanf("%s",&t2.supp_email);
fwrite(&t2,sizeof(t2),1,fp);

fclose(fp);
}

//=========FOR Supplier DISPLAY LIST ==========
void supp_list()
{
    system("cls");
FILE *fp;
struct supplier ts;

fp=fopen(fname_s,"rb");
if(fp==NULL)
	   {

		printf("\n\t Can not open File! ");

		exit(0);
	   }
printf("\n\n\n");
printf("\t\t\t\t========================================================\n\n");
printf("\t\t\t\t\t\t All supplier Details\n\n");

printf("\t\t\t\tID\tName\tcity\tmobile number\temail\n\n");
printf("\t\t\t\t========================================================\n\n");


while(1)
{
fread(&ts,sizeof(ts),1,fp);

if(feof(fp))
{
break;
}
printf("\t\t\t\t%d\t",ts.supp_id);
printf("%s\t",ts.supp_name);
printf("%s\t",ts.supp_city);
printf("%s\t",ts.supp_mob_no);
printf("%s\t\n\n",ts.supp_email);

}
printf("\t\t\t\t========================================================\n\n");

fclose(fp);
getche();
}
void supp_list_id()
{
    system("cls");
    FILE *fp;
struct supplier ts;
int id,found=0;

fp=fopen(fname_s,"rb");

printf("\n\t\t\t\t\tEnter the supplier ID:");
scanf("%d",&id);
if(fp==NULL)
	   {

		printf("\n\t Can not open File! ");

		exit(0);
	   }

while(1)
{
fread(&ts,sizeof(ts),1,fp);

if(feof(fp))
{
break;
}
if(ts.supp_id==id)
{
found=1;
printf("\n\t\t\t\t========================================================\n\n");
printf("\t\t\t\t\t supplier Details of %d\n\n",ts.supp_id);
printf("\t\t\t\t========================================================\n\n");

printf("\t\t\t\t\tName\tcity\tmobile number\temail\n\n");

printf("\t\t\t\t\t%s\t",ts.supp_name);
printf("%s\t",ts.supp_city);
printf("%s\t",ts.supp_mob_no);
printf("%s\t\n\n",ts.supp_email);

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
//======================search Supplier==================

//===========================Search by SupplierId=========================
void search_s_id()
{
    system("cls");
 FILE *fp2;
 struct supplier temp_s;
 int r, s, avl;
 printf("\n\t\t\t\t\tEnter the ID you want to search  :");
 scanf("%d", &r);
 avl = avlid_s(r);
 if (avl == 0)
  printf("\n\n\t\t\t\t\tSupplier ID %d is not available in the file\n",r);
 else
 {
  fp2 = fopen(fname_s, "rb");
  while (fread(&temp_s, sizeof(temp_s), 1, fp2))
  {
   s = temp_s.supp_id;
   if (s == r)
   {
    printf("\n\t\t\t\t========================================================\n\n");
    printf("\t\t\t\t\t supplier Details of ID number%d\n\n",temp_s.supp_id);
    printf("\t\t\t\t========================================================\n\n");

    printf("\t\t\t\t\tName\tcity\tmobile number\temail\n\n");

    printf("\t\t\t\t\t%s\t",temp_s.supp_name);
    printf("%s\t",temp_s.supp_city);
    printf("%s\t",temp_s.supp_mob_no);
    printf("%s\t\n\n",temp_s.supp_email);

printf("\t\t\t\t========================================================\n\n");
   }
  }
  fclose(fp2);
 }
  getche();
}
/*****************************search by Suppliername******************************/
void search_s_name()
{
    system("cls");
  FILE *fp;
struct supplier ts;
int found=0;
char name[20];

fp=fopen(fname_s,"rb");
if(fp==NULL)
	   {

		printf("\n\t\t\t\t\t Can not open File! ");

		getche();
		supplier();
	   }

printf("\n\t\t\t\tEnter the supplier Name:");
scanf("%s",&name);

while(1)
{
fread(&ts,sizeof(ts),1,fp);

if(feof(fp))
{
break;
}
if(strcmp(name,ts.supp_name)==0)
{
    found=1;
   printf("\n\t\t\t\t========================================================\n\n");
    printf("\t\t\t\t\t supplier Details of name is %s\n\n",ts.supp_name);
    printf("\t\t\t\t========================================================\n\n");

    printf("\t\t\t\t\tid\tcity\tmobile number\temail\n\n");

    printf("\t\t\t\t\t%d\t",ts.supp_id);
    printf("%s\t",ts.supp_city);
    printf("%s\t",ts.supp_mob_no);
    printf("%s\t\n\n",ts.supp_email);

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
//============supplier update=================
void supp_update()
{
    system("cls");
  FILE *fp,*fp1;
struct supplier t,t1;
int id,found=0,count=0;

fp=fopen(fname_s,"rb");
fp1=fopen("temp_s.dat","wb");
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
if(t.supp_id==id)
{
found=1;
printf("\n\t\t\t\tEnter supplier ID:");
scanf("%d",&t.supp_id);

fflush(stdin);
printf("\n\t\t\t\tEnter supplier Name:");
scanf("%s",t.supp_name);
printf("\n\t\t\t\tEnter supplier city:");
scanf("%s",t.supp_city);
printf("\n\t\t\t\tEnter supplier mobile number:");
ventry(t.supp_mob_no,1);
printf("\n\t\t\t\tEnter email:");
scanf("%s",t.supp_email);

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
fp=fopen(fname_s,"wb");
fp1=fopen("temp_s.dat","rb");

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

int getsupp_id()
{
    system("cls");
 FILE *fp;
 struct supplier temp_s;
	 fp=fopen("supplier.dat","r");
	 if(fp==NULL)
	 {
	     printf("\n\n");

        printf("\t\t\t\t");

		printf("\t\t\t\tData not Found.....");
		getch();
	 }
	 else
	 {
		temp_s.supp_id=100;
		rewind(fp);
		while(fscanf(fp,"%d %s %s %s %s",&temp_s.supp_id,temp_s.supp_name,temp_s.supp_city, temp_s.supp_mob_no,temp_s.supp_email)!=EOF)
		{
		}
	 }
	 fclose(fp);
	 return temp_s.supp_id+1;
}
void supp_delete()
{
    system("cls");
    FILE *fp,*fp1;
struct supplier ts,t2;
int id,found=0,count=0;

fp=fopen(fname_s,"rb");
fp1=fopen("temp_s.dat","wb");
if(fp==NULL)
	   {

		printf("\n\t\t\t\t\t Can not open File! ");

		exit(0);
	   }

printf("\n\t\t\t\tEnter the supplier ID you want to Delete:");
scanf("%d",&id);

while(1)
{
fread(&ts,sizeof(ts),1,fp);

if(feof(fp))
{
break;
}
if(ts.supp_id==id)
{
found=1;
}
else
{
fwrite(&ts,sizeof(ts),1,fp1);
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
fp=fopen(fname_s,"wb");
fp1=fopen("temp_s.dat","rb");

while(1)
{
fread(&ts,sizeof(ts),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&ts,sizeof(ts),1,fp);
}
}
fclose(fp);
fclose(fp1);
}
void rname_s()
{
char name[20];

printf("\n\t\t\t\tEnter the New File Name:");
fflush(stdin);
scanf("%[^\n]",name);

rename(fname_s,name);

strcpy(fname_s,name);
}

void rremove_s()
{
FILE *fp,*fp1;
struct supplier ts;

char name[20];
char val[20];

printf("\n\t\t\t\tDo you want to make copy of it (Y/N):");
scanf("%s",val);

if(strcmp(val,"Y")==0)
{

printf("\n\t\t\t\tEnter the New File Name:");
fflush(stdin);
scanf("%[^\n]",name);

fp=fopen(name,"wb");
fp1=fopen(fname_s,"rb");

while(1)
{
fread(&ts,sizeof(ts),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&ts,sizeof(ts),1,fp);
}

fclose(fp);
fclose(fp1);

remove(fname_s);

strcpy(fname_s,name);
}
else
{
remove(fname_s);
}
}
int avlid_s(int id)
{
 FILE *fp;
 struct supplier temp_s;
 int c = 0;
 fp = fopen(fname_s, "rb");
 while (!feof(fp))
 {
  fread(&temp_s, sizeof(temp_s), 1, fp);

  if (id== temp_s.supp_id)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
//FUNCTION
void sort_id_s()
{
    system("cls");
    struct supplier temp_s;
 int a[2000], count = 0, i, j, t, c;
 FILE *fpo;
 fpo = fopen(fname_s, "rb");
 while (fread(&temp_s, sizeof(temp_s), 1, fpo))
 {
  a[count] = temp_s.supp_id;
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
printf("\t\t\t\t\t sorted list of supplier details\n\n");
printf("\t\t\t\t========================================================\n\n");
printf("\t\t\t\tID.\tName\tCity\tMobile Number\tEmail\n");
printf("\n\t\t\t\t========================================================\n\n");
 count = c;
 for (i = 0; i<count; i++)
 {
  rewind(fpo);
  while (fread(&temp_s, sizeof(temp_s), 1, fpo))
  {
   if (a[i] == temp_s.supp_id)
    printf("\n \t\t\t\t%d\t %s \t %s\t%s\t%s\n",temp_s.supp_id, temp_s.supp_name,temp_s.supp_city,temp_s.supp_mob_no,temp_s.supp_email);
  }
 }
 printf("\n\t\t\t\t========================================================\n\n");
 getche();

}



#endif // supplier_H_INCLUDED
