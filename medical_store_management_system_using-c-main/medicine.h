#ifndef MEDICINE_H_INCLUDED
#define MEDICINE_H_INCLUDED
struct medical
{
	char id[6];
	char medi_name[20];
	int rack;
	char cabnit[2];
	int quantity;
	float sale;
	float total;
	float unit;
	float cost;
	float profit;
	float bye;
	int qty;
	char pur_date[15];
	char exp_date[15];
	char manu_date[15];
	int bill_no;
	char comp_name[20];
	char supp_name[30];
 };
 struct medical temp;
struct medical x[20];
FILE *ptr;
char a[10];

void medicine()
{
	int ch;
	do
	{
	  system("cls");


	  printf("\n\t\t\t-----------------------------------------\n");

	  printf("\n\t\t\t\tMedicine Menu.\n");

	  printf("\n\t\t\t-----------------------------------------\n");

	  printf("\n\t\t\t\t1.P");

	  printf("urchase New Medicine\n");


	  printf("\n\t\t\t\t2.S");

	  printf("ale Medicine\n");

	  printf("\n\t\t\t\t3.Sto");

	  printf("c");

	  printf("k of Medicine\n");

	  printf("\n\t\t\t\t4.Update Sto");

	  printf("c");

	  printf("k of Medicine\n");

	  printf("\n\t\t\t\t5.Se");

	  printf("a");

	  printf("rch Medicine by id\n");

	   printf("\n\t\t\t\t6.Se");

	  printf("a");

	  printf("rch Medicine by name\n");

	  printf("\n\t\t\t\t7.M");

	  printf("ain Menu\n");

	  printf("\n\t\t\t\tPress select from above  ");
	  scanf("%d",&ch);
        switch(ch)
	  {
		case 1:medi_entry();
			 break;
		case 2:medi_sale();
			 break;
		case 3:sort_m_id();
			 break;
		case 4:update_stock();
             break;
		case 5:medi_search();
			 break;
        case 6:medi_search_name();
			 break;
        case 7:main_menu();
			 break;
		default:

			printf("\n\t\t\t\tPlease enter correct number");
			getch();
	  }
	}while(ch!=0);

}
void ventry(char t[],int code)
{
  int i=0;
	if(code==0)
	{
		while((t[i]=getch())!='\r' && i<30)
		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) || t[i]==32 || t[i]=='_')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}
	else if(code==1)
	{
		while((t[i]=getch())!='\r' && i<10 )
		if((t[i]>=48 && t[i]<=57) || t[i]==46 ||  t[i]=='-')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}
	else if(code==2)
	{
		while((t[i]=getch())!='\r' && i<30 )
		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) ||(t[i]>=48 && t[i]<=57) || t[i]==32 || t[i]==8 ||t[i]=='@'||t[i]=='.')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}

	t[i]='\0';
}
void medi_entry()
{
  char id[6];
  int ch;

//  struct date d;
    time_t t = time(NULL) ;
    struct tm local = *localtime( &t );
    local.tm_mon=local.tm_mon+1;
    local.tm_year=local.tm_year+1900;
  int f;
  FILE *fp;
  system("cls");
	  //getdate(&d);

	  ptrp_r=fopen("purreport.dat","a");
	  ch='Y';
	  while(ch=='Y')
	  {
		system("cls");

		supp_list();

		printf(" \n\t\t\t\tMEDICINE PURCHASE  \n");
		{
		    printf("\n\t\t\t==========================================================\n");

			printf("\n\n\t\t\tMEDICINE ID    : ");

			ventry(temp.id,1);

			strcpy(id,temp.id);

			fp=fopen("medical.dat","r");
			while((fread(&temp,sizeof(temp),1,fp))==1)
			{

			if(strcmp(id,temp.id)==0)
			{
				f=1;
				break;
			}
			}
			fclose(fp);
			if(f==1)
			{

				printf("\n\n\t\t\tID Allready Exists\n");
				getche();
				system("cls");
				medi_entry();
			}
			else
			{
			ptr=fopen("medical.dat","a+b");
			strcpy(temp.id,id);
			strcpy(p_r.medi_id,temp.id);
			}

			printf("\n\n\t\t\tMEDICINE NAME  : ");

			ventry(temp.medi_name,0);

			strcpy(p_r.medir_name,temp.medi_name);

			printf("\n\n\t\t\t\tENTER RACK NO  : ");

			ventry(a,1);

			temp.rack= atoi(a);//atoi() used for convert str to int.

			printf("\n\n\t\t\tCABNIT NO      : ");

			ventry(temp.cabnit,2);

			printf("\n\n\t\t\tCOMPANY NAME   : ");

			ventry(temp.comp_name,0);

			printf("\n\n\t\t\tSUPPLIER NAME  : ");

			ventry(temp.supp_name,0);

			strcpy(p_r.supp_name,temp.supp_name);

			printf("\n\n\t\t\tUNIT COST   Rs.:  ");

			ventry(a,1);

			temp.unit= atof(a);

			p_r.rate=temp.unit;

			printf("\n\n\t\t\tSALE COST   Rs.: ");

			ventry(a,1);

			temp.sale= atof(a);

			printf("\n\n\t\t\tQUANTITY       :  ");

			ventry(a,1);

			temp.quantity= atoi(a);

			p_r.qty=temp.quantity;

			printf("\n\n\t\t\tMFG.DATE(dd-mm-yyyy):") ;

			ventry(temp.manu_date,1);

			printf("\n\n\t\t\tEXP.DATE(dd-mm-yyyy): ");

			ventry(temp.exp_date,1);

			printf("\n\t\t\t==========================================================\n");
			temp.total=temp.quantity*temp.sale;


			printf("\n\t\t\tTOTAL SALE COST = Rs. %.2f\n",temp.total);
			temp.cost=(temp.unit*temp.quantity);

			printf("\n\t\t\tTOTAL UNIT COST = Rs. %.2f\n",temp.cost);
			p_r.total=temp.cost;
			p_r.sDay=local.tm_mday;
			p_r.sMonth=local.tm_mon;
			p_r.sYear=local.tm_year;
		 }

		printf("\n\t\t\t1.S");

		printf("ave");

		printf("\t\t2.C");

		printf("ancel\n");

		printf("\n\t\t\tEnter following from list : ");

		scanf("%d",&ch);

		if(ch==1)
		{
			fwrite(&temp,sizeof(temp),1,ptr);
			fflush(stdin);

			fprintf(ptrp_r,"%s %s %s %d %.2f %.2f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,p_r.qty,p_r.rate,p_r.total,p_r.sDay,p_r.sMonth,p_r.sYear);
			system("cls");

			printf("\n\t\t\tMedicine Added sucessfully!!!!!!\n");

			printf("\n\t\t\tMore entries  [y/n]\n");
			ch=toupper(getche());

		}

	   }
	   fclose(ptr);
	   fclose(ptrp_r);
}
void medi_sale()
{
  struct bill bil;

 time_t t = time(NULL) ;
    struct tm local = *localtime( &t );
    local.tm_mon=local.tm_mon+1;
    local.tm_year=local.tm_year+1900;
  int j,n,i,a,billno;
  int d1,m,y;
  float b,total,rate;
  char tar[30],ch,mediname[30],c_name[30],cname[30];
  FILE *fp,*fpc;
  int count=0;

  d1=local.tm_mday;
  m=local.tm_mon;
  y=local.tm_year;
	   ch='y';
	   while(ch=='y')
	   {
		fp = fopen("dbbill.dat","a");
		ptr1 = fopen(fname_c,"r");
		ptr = fopen("medical.dat","r");
		ptrs_r=fopen("saleRpt.dat","a");
		ptrpr_r=fopen("profitRpt.dat","a");
		system("cls");

	cust_list();


		printf("\n\t\t\t\tENTER MEDICINE ID TO BE SOLD  : ");
		ventry(tar,1);

		j=0;
		while((fread(&temp,sizeof(temp),1,ptr))==1)
		{
			if((strcmp(temp.id,tar)<0) || (strcmp(temp.id,tar)>0))
			{
				x[j] = temp;
				j++;
			}
			else if((strcmp(temp.id,tar)==0))
			{


				printf("\n\t\t\t\t Medicine Name        : %s\n",temp.medi_name);

				printf("\n\t\t\t\t Quantity in stock    : %d\n",temp.quantity);

				printf("\n\t\t\t\t Sales price          : %.2f\n",temp.sale);

				printf("\n\t\t\t\tEnter bill number     : ");

				ventry(bil.billno,1);

				printf("\n\n\t\t\t\tEnter customer Name   : ");

				ventry(c_name,0);

				printf("\n\n\t\t\t\tQuantity want to sale : ");

				scanf("%d",&a);

				pr_r.profit=(temp.sale-temp.unit)*a;
				x[j]=temp;
				x[j].quantity=(x[j].quantity-a);
				x[j].total=(x[j].quantity*temp.sale);
				x[j].cost=(x[j].quantity*temp.unit);
				x[j].bye=(x[j].sale*a);
				b=x[j].bye;
				x[j].qty=a;
				j++;
				count++;
				strcpy(bil.cname,c_name);
				strcpy(s_r.cust_name,c_name);
				strcpy(bil.mediname,temp.medi_name);
				bil.medi_qty=a;
				bil.medi_rate=temp.sale;
				bil.total=temp.sale*a;

				bil.day=d1;
				bil.month=m;
				bil.year=y;

				fprintf(fp,"%s %s %s %d %.2f %.2f %d %d %d\n",bil.billno,bil.cname,bil.mediname,bil.medi_qty,bil.medi_rate,bil.total,bil.day,bil.month,bil.year);
				fflush(stdin);

				fclose(fp);

				s_r.sDay=d1;
				s_r.sMonth=m;
				s_r.sYear=y;
				strcpy(s_r.medi_id,tar);
				strcpy(s_r.medir_name,temp.medi_name);
				s_r.qty=a;
				s_r.rate=temp.sale;
				s_r.total=temp.sale*a;

				fprintf(ptrs_r,"%s %s %s %d %.2f %.2f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,s_r.qty,s_r.rate,s_r.total,s_r.sDay,s_r.sMonth,s_r.sYear);
				fflush(stdin);
				fclose(ptrs_r);

				pr_r.sDay=d1;
				pr_r.sMonth=m;
				pr_r.sYear=y;
				strcpy(pr_r.medi_id,tar);
				strcpy(pr_r.medir_name,temp.medi_name);
				pr_r.qty=a;
				pr_r.rate=temp.sale;
				pr_r.unit=temp.unit;
				fprintf(ptrpr_r,"%s %s %d %d %d %d %.2f %.2f  %.2f\n",pr_r.medi_id,pr_r.medir_name,d1,pr_r.sMonth,pr_r.sYear,pr_r.qty,pr_r.unit,pr_r.rate,pr_r.profit);
				fflush(stdin);
				fclose(ptrpr_r);

			}
		}
		if (count==0)
		{
			system("cls");
			;
			printf("\n\t\t\t\tNot in stock!!!!!\n");
			getch();
			return;
		}
		fclose(ptr1);
		fclose(ptr);
		n = j;
		system("cls");
		ptr=fopen("medical.dat","wb");
		for(i=0; i<n; i++)
		fwrite(&x[i],sizeof(x[i]),1,ptr);
		fclose(ptr);

		printf("\n\t\t\t\t* Price paid by customer = %.2f\n",b);

		printf("\n\t\t\t\t* Quantity sold          = %d\n",a);
		getch();

		printf("\n\t\t\t\tmore enteries=(y/n) :\n");
		ch=getche();
	   }


}
//===========================MEDICINE STOCK=====================================
void stock()
{
  char ch;
  int i,c,d,m,y;
  struct medical temp;
  time_t t = time(NULL) ;
    struct tm local = *localtime( &t );
    local.tm_mon=local.tm_mon+1;
    local.tm_year=local.tm_year+1900;
    d=local.tm_mday;
    m=local.tm_mon;
    y=local.tm_year;
	   do
	   {
		system("cls");
		ptr=fopen("medical.dat","r");
		if(ptr==NULL)
		{
			printf("\n\t\t\t\t Can not open File! \n");
			getche();
			medicine();
		}
		system("cls");

		printf(" \n\t\t\t\tSTOCK OF MEDICINE\n ");

		i=14;

		printf("\n\t\t\t\t ID.  MEDICINE  QTY  Supplier  Exp.Date\n");

		printf("\n\t\t\t==================================================================\n");

		while((fread(&temp,sizeof(temp),1,ptr))==1)
		{

			printf("\n\t\t\t\t %s",temp.id);

			printf(" \t%s",temp.medi_name);

			printf(" \t%d",temp.quantity);

			printf(" \t%s",temp.supp_name);

			printf(" \t%s\n",temp.exp_date);

		}

		printf("\n\t\t\t==================================================================\n");
		printf("\n\t\t\t\tPress [1] for Update Medicine Stock  & [0] for medicine menu \n");
		c = (getche());
		switch (c)
		{
			case '0':
                medicine();
				 break;
			case '1':
			    update_stock();
				 break;
		}

	   }while(c != '1');
	   getche();
}
//=============================== FOR MEDICINE SEARCH ====================
void medi_search_name()
{
  char mname[20];
  int i,c;
  system("cls");
	   ptr=fopen("medical.dat","r");
	   if(ptr==NULL)
	   {
		printf("\n\t\t\t\t Can not open File! \n");
		getche();
		medicine();
	   }
	   system("cls");


	   printf("\n\t\t\t\tEnter Medicine name to be searched : ");
	   scanf("%s",&mname);
	   system("cls");

	   printf(" \n\n\t\t\t\tMEDICINE \n");

	   printf("\n\t\t\t\tID.  MEDICINE.  QTY.  Supplier.  Exp.Date\n");

	   printf("\n\t\t\t\t==================================================================\n");
	   while((fread(&temp,sizeof(temp),1,ptr))==1)
	   {
		if(strcmp(mname,temp.medi_name)==0)
		{

			printf("\n\n\t\t\t\t%s",temp.id);

			printf("\t%s",temp.medi_name);

			printf("\t%d",temp.quantity);

			printf("\t%s",temp.supp_name);

			printf("\t%s\n",temp.exp_date);

			break;
		}

	   }
	   getche();

}
void medi_search()
{
  char mid[6];
  int i,c;
  system("cls");
	   ptr=fopen("medical.dat","r");
	   if(ptr==NULL)
	   {
		printf("\n\t\t\t\t Can not open File! \n");
		getche();
		medicine();
	   }
	   system("cls");


	   printf("\n\t\t\t\tEnter Medicine Id to be searched : ");
	   scanf("%s",&mid);
	   system("cls");

	   printf(" \n\n\t\t\t\tMEDICINE \n");

	   printf("\n\t\t\t\tID.  MEDICINE.  QTY.  Supplier.  Exp.Date\n");

	   printf("\n\t\t\t\t==================================================================\n");
	   while((fread(&temp,sizeof(temp),1,ptr))==1)
	   {
		if(strcmp(mid,temp.id)==0)
		{

			printf("\n\n\t\t\t\t%s",temp.id);

			printf("\t%s",temp.medi_name);

			printf("\t%d",temp.quantity);

			printf("\t%s",temp.supp_name);

			printf("\t%s\n",temp.exp_date);

			break;
		}

	   }

	   getche();

}
//============================ FOR MEDICINE UPDATE =====================
void update_stock()
{
  char mid[6];
  int j,a,count=0,n;
  system("cls");
	   ptr=fopen("medical.dat","rb");
	   if(ptr==NULL)
	   {
		printf("\n\t\t\t\t Can not open File! \n");
		getche();
		medicine();
	   }
	   system("cls");


	   printf("\n\t\t\t\tPress Enter to go to MENU ...........\n");

	   printf(" \n\t\t\t\tUPDATE MEDICINE QUANTITY \n");

	   printf("\n\t\t\t\tEnter medicine id to be update qty: \n");
	   scanf("%s",&mid);
	   j=0;

	   while((fread(&temp,sizeof(temp),1,ptr))==1)
	   {
		if((strcmp(temp.id,mid)<0) || (strcmp(temp.id,mid)>0))
		{
			x[j] = temp;
			j++;
		}
		else
		{

			printf("\n\t\t\t\tMedicine Name     : %s\n",temp.medi_name);

			printf("\n\t\t\t\tQuantity in stock : %d\n",temp.quantity);

			printf("\n\t\t\t\tQuantity want to update : ");
			scanf("%d",&a);
			x[j]=temp;
			x[j].quantity=(x[j].quantity+a);
			x[j].total=(x[j].quantity*temp.sale);
			x[j].cost=(x[j].quantity*temp.unit);
			x[j].bye=(x[j].sale*a);
			x[j].qty=a;
			j++;
			count++;
		}
	   }
	   if (count==0)
	   {
		 system("cls");

		 printf("\n\n\t\t\t\tNot in stock!!!!!!\n");
		 getch();
		 return;
	   }
	   fclose(ptr);
	   n = j;
	   system("cls");
	   ptr=fopen("medical.dat","wb");
	   for(int i=0; i<n; i++)
	   fwrite(&x[i],sizeof(x[i]),1,ptr);
	   fclose(ptr);
}
void warning()
{
	ptr=fopen("medical.dat","rb");
	printf("\t\t\t\t");
	printf("###############################################\n\n");
	printf("\033[0;33m");

	while((fread(&temp,sizeof(temp),1,ptr))==1)
	{

		if(temp.quantity<10)
		{

			printf("\n\t\t\t\t%s : ",temp.medi_name);
			printf("Quantity of this medicine is less then 10\n");

		}

	}
	 printf("\033[0m");
     printf("\n\n");
     printf("\t\t\t\t");
     printf("###############################################\n\n");
}
void sort_m_id()
{
    system("cls");
    struct medical temp_m;
 int a[2000], count = 0, i, j, t, c;
 FILE *fpo;
 fpo = fopen("medical.dat", "rb");
 while (fread(&temp_m, sizeof(temp_m), 1, fpo))
 {
  a[count] = atoi(temp_m.id);
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
printf("\t\t\t\t\t sorted list of medicine details\n\n");
printf("\t\t\t\t========================================================\n\n");
printf("\t\t\t\tID. medicine quantity supplier Exp.date\n");
printf("\n\t\t\t\t========================================================\n\n");
 count = c;
 for (i = 0; i<count; i++)
 {
  rewind(fpo);
  while (fread(&temp_m, sizeof(temp_m), 1, fpo))
  {

         if (a[i] == atoi(temp_m.id))
         {
             printf("\n\n\t\t\t\t%s",temp_m.id);

			printf("\t%s",temp_m.medi_name);

			printf("\t%d",temp_m.quantity);

			printf("\t%s",temp_m.supp_name);

			printf("\t%s\n",temp_m.exp_date);
         }

  }


 }
 printf("\n\t\t\t\t========================================================\n\n");
 getche();
}
#endif // MEDICINE_H_INCLUDED
