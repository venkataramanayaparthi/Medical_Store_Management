#ifndef REPORT_H_INCLUDED
#define REPORT_H_INCLUDED
struct sales_report
{
	char medi_id[6];
	char medir_name[20];
	char cust_name[30];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct sales_report s_r;
FILE *ptrs_r;

struct purchase_report
{
	char medi_id[6];
	char medir_name[20];
	char supp_name[30];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct purchase_report p_r;
FILE *ptrp_r;

struct profit_report
{
	char medi_id[6];
	char medir_name[20];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float unit;
	float profit;
};
struct profit_report pr_r;
FILE *ptrpr_r;

void linkfloat()
{
	float f,*p;
	p=&f;
	f=*p;
}
int t(void)
{

    time_t t = time(NULL) ;
    struct tm local = *localtime( &t );
    local.tm_mon=local.tm_mon+1;
    local.tm_year=local.tm_year+1900;
	printf("\n\t\t\t\tDate: %d-%d-%d ",local.tm_mday,local.tm_mon,local.tm_year);
	printf("\n\t\t\t\tTime: %d:%d:%d",local.tm_hour,local.tm_min,local.tm_sec);
	return 0;
}
void report_menu()
{
	int ch;
	do
	{
	  system("cls");


	  printf("\n\t\t\t\t---------------\n");

	  printf("\n\t\t\t\tReport Menu.\n");

	  printf("\n\t\t\t\t---------------\n");

	  printf("\n\t\t\t\t1.P");

	  printf("urchase Report\n");

	  printf("\n\t\t\t\t2.S");

	  printf("ale Report\n");

	  printf("\n\t\t\t\t3.Pr");

	  printf("o");

	  printf("fit Report\n");

	  printf("\n\t\t\t\t4.D");

	  printf("a");

	  printf("ily Sale Report\n");

	  printf("\n\t\t\t\t5.D");

	  printf("aily Purchase Report\n");

	  printf("\n\t\t\t\t6.M");

	  printf("ain Menu\n");

	  printf("\n\t\t\t\tselect from above list ");

	  scanf("%d",&ch);
	  switch(ch)
	  {
		case 1:pur_rpt();
			 break;
		case 2:sale_rpt();
			 break;
		case 3:profit_rpt();
			 break;
		case 4:sale_rpt_daily();
			 break;
		case 5:pur_rpt_daily();
			 break;
		case 6:main_menu();
			 break;
		default:
			printf("\n\n\t\t\t\tPlese Enter right character ONLY (P,S,O,M).\n");
			getch();
	  }
	}while(ch!=7);

}
void sale_rpt()
{
  char ch;
  int j;
  FILE *ptrs_r;
  struct sales_report s_r;
  system("cls");
  t();
	   ptrs_r=fopen("saleRpt.dat","r");
	   if(ptrs_r==NULL)
	   {
		printf("\n\t\t Can not open File! \n");
		getche();
		report_menu();
	   }
	   system("cls");

	   printf("\n\t\tSales Report\n");

	   printf("\n\t\tID.  Medicine. Customer. Qty.  Rate.\tTotal.\tDate\n");

	   printf("\n\n\t\t===================================================================\n");

	   while(fscanf(ptrs_r,"%s %s %s %d %f %f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,&s_r.qty,&s_r.rate,&s_r.total,&s_r.sDay,&s_r.sMonth,&s_r.sYear)!=EOF)
	   {
		printf("\n\t\t%s",s_r.medi_id);

		printf("\t%s",s_r.medir_name);

		printf("\t%s",s_r.cust_name);

		printf("\t%d",s_r.qty);

		printf("\t%.2f",s_r.rate);

		printf("\t%.2f",s_r.total);

		printf("\t%d-%d-%d\n",s_r.sDay,s_r.sMonth,s_r.sYear);

	   }
	   printf("\n\n\t\t===================================================================\n");

	   printf("\n\n\t\t\t\tPress any key to go to REPORT MENU ...........\n\n");

	   getche();
}
//======================= VIEW PURCHASE REPORT ===========================
void pur_rpt()
{
  char ch;
  int j;
  system("cls");
  t();

	   ptrp_r=fopen("purreport.dat","r");
	   if(ptrp_r==NULL)
	   {
		printf("\n\t Can not open File! \n");
		getche();
		report_menu();
	   }

	   printf("\n\n\t\tPurchase Report\n");

	   printf("\n\t\tID.  Medicine. Supplier.  Qty.  Rate.   Total.    Date\n");

	   printf("\n\t==========================================================================================\n");


	   while(fscanf(ptrp_r,"%s %s %s   %d %f %f %d %d %d",p_r.medi_id,p_r.medir_name,p_r.supp_name,&p_r.qty,&p_r.rate,&p_r.total,&p_r.sDay,&p_r.sMonth,&p_r.sYear)!=EOF)
	   {

		printf("\n\t\t%s",p_r.medi_id);

		printf("\t%s",p_r.medir_name);

		printf("\t%s",p_r.supp_name);

		printf("\t%d",p_r.qty);

		printf("\t%.2f",p_r.rate);

		printf("\t%.2f",p_r.total);

		printf("\t %d-%d-%d\n",p_r.sDay,p_r.sMonth,p_r.sYear);

	   }

	   printf("\n\t==========================================================================================\n");

	   printf("\n\n\t\tPress any key to go to REPORT MENU ...........\n");

	   getche();
}
//========================= report of profit ===========================

void profit_rpt()
{
  char ch;
  int j,profit=0;
  system("cls");
  t();
	   ptrpr_r=fopen("profitRpt.dat","r");
	   if(ptrpr_r==NULL)
	   {
		printf("\n\t Can not open File! \n");

	   }

	   printf("\n\n\t\tProfit Report\n");


	   printf("\n\n\t\tID. Medicine.   Date \t Qty.  Unit Price  Sale Price. Profit. \n");

	   printf("\n\n\t\t===================================================================\n");

	   while(fscanf(ptrpr_r,"%s %s %d %d %d %d %f %f %f \n",pr_r.medi_id,pr_r.medir_name,&pr_r.sDay,&pr_r.sMonth,&pr_r.sYear,&pr_r.qty,&pr_r.unit,&pr_r.rate,&pr_r.profit)!=EOF)
	   {


		printf("\n\n\t\t%s",pr_r.medi_id);

		printf("\t%s",pr_r.medir_name);

		printf("  %d-%d-%d",pr_r.sDay,pr_r.sMonth,pr_r.sYear);

		printf("  %d",pr_r.qty);

		printf(" \t%.2f",pr_r.unit);

		printf("\t \t%.2f",pr_r.rate);

		printf(" \t%.2f\n",pr_r.profit);

		profit=profit+pr_r.profit;

	   }

	   printf("\n\n\t\t===================================================================\n");

	   printf("\033[0;36m");

	   printf("\n\n\t\t\t\tThe total profit is : %d",profit);

	   printf("\033[0m");

	   printf("\n\n\tPress Enter to go to REPORT MENU ...........\n");

	   getche();
}

void sale_rpt_daily()
{
  char ch;
  int j,d,m,y;
  FILE *ptrs_r;
  float total=0.00;
  struct sales_report s_r;
  system("cls");

	   ptrs_r=fopen("saleRpt.dat","r");
	   if(ptrs_r==NULL)
	   {
		printf("\n\t\t Can not open File! \n");
		getche();
		report_menu();
	   }
	   system("cls");

	   printf("\n\n\t\tEnter Date(dd-mm-yyyy):  ");
	   scanf("%d-%d-%d",&d,&m,&y);
	   system("cls");

	     t();

	   printf("\n\n\t\tSales Report\n");

	   printf("\n\t\tID. Medicine. Customer. Qty.   Rate.   Total.   Date\n");

	   printf("\n\t\t===================================================================\n");

	   while(fscanf(ptrs_r,"%s %s %s %d %f %f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,&s_r.qty,&s_r.rate,&s_r.total,&s_r.sDay,&s_r.sMonth,&s_r.sYear)!=EOF)
	   {
		if(d==s_r.sDay &&m== s_r.sMonth && y==s_r.sYear)
		{

		printf("\n\t\t%s",s_r.medi_id);

		printf("\t%s",s_r.medir_name);

		printf("\t%s",s_r.cust_name);

		printf("\t%d",s_r.qty);

		printf("\t%.2f",s_r.rate);

		printf("\t%.2f",s_r.total);

		printf("\t%d-%d-%d\n",s_r.sDay,s_r.sMonth,s_r.sYear);

		total=total+s_r.total;
		}
	   }

	   printf("\n\t\t===================================================================\n");

	   printf("\n\t\tTotal:        %.2f\n",total);

	    printf("\n\t\tPress any key to go to REPORT MENU ...........\n");

	   getche();
}
void pur_rpt_daily()
{
  char ch;
  int j,d,m,y;
  float total=0.00;
  struct purchase_report p_r;
  FILE *ptrp_r;

	   ptrp_r=fopen("purreport.dat","r");
	   if(ptrp_r==NULL)
	   {
		printf("\n\t\t Can not open File! \n");
		getche();
		report_menu();
	   }
	   system("cls");

	   printf("\n\n\t\tEnter Date(dd-mm-yyyy):  ");
	   scanf("%d-%d-%d",&d,&m,&y);
	   system("cls");

	   t();

	   printf("\n\t\tPurchase Report\n");

	   printf("\n\t\tID. Medicine. Supplier.  Qty.  Rate.   Total.   Date\n");

	   printf("\n\t\t===================================================================\n");

	   while(fscanf(ptrp_r,"%s %s %s %d %f %f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,&p_r.qty,&p_r.rate,&p_r.total,&p_r.sDay,&p_r.sMonth,&p_r.sYear)!=EOF)
	   {
		if(d==p_r.sDay &&m== p_r.sMonth && y==p_r.sYear)
		{

		printf("\n\t\t%s",p_r.medi_id);

		printf("\t%s",p_r.medir_name);

		printf("\t%s",p_r.supp_name);

		printf("\t%d",p_r.qty);

		printf("\t%.2f",p_r.rate);

		printf("\t%.2f",p_r.total);

		printf("\t%d-%d-%d\n",p_r.sDay,p_r.sMonth,p_r.sYear);

		total=total+p_r.total;
		}
	   }

	    printf("\n\t\t===================================================================\n");

	   printf("\n\t\tTotal:        %.2f\n",total);

	   printf("\n\t\tPress Enter to go to REPORT MENU ...........\n");

	   getche();
}


#endif // REPORT_H_INCLUDED
