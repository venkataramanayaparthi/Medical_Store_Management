
struct bill
{
	char billno[6];
	char cname[30];
	char mediname[30];
	int medi_qty;
	float medi_rate;
	float total;
	int day;
	int month;
	int year;

};
struct bill bil;
FILE *ptrbill;
void bill()
{
    struct bill bil;
    time_t t = time(NULL) ;
    struct tm local = *localtime( &t );
    local.tm_mon=local.tm_mon+1;
    local.tm_year=local.tm_year+1900;

	   FILE *ptrbill;
	   char id[6];
	   int j=1,d1,m,y,k;
	   float netamt=0.0;

	   system("cls");
	   printf("\n\t\t\t\tDate: %d-%d-%d ",local.tm_mday,local.tm_mon,local.tm_year);
	printf("\n\t\t\t\tTime: %d:%d:%d",local.tm_hour,local.tm_min,local.tm_sec);
	   ptrbill=fopen("dbbill.dat","r");

	   printf("\n\n\t\tEnter bill no and name combined : ");
	   scanf("%s",&id);
	   system("cls");
	   printf("\n\t\t\t\tDate: %d-%d-%d ",local.tm_mday,local.tm_mon,local.tm_year);
       printf("\n\t\t\t\tTime: %d:%d:%d",local.tm_hour,local.tm_min,local.tm_sec);
	   printf("\n\n\t\tBill No-Customer name ");
	   printf(" %s",id);

	   printf("\n\n\t\tSr.No   Medicine  customer    Qty   Rate   Total  purchase date");

	   printf("\n\n\t\t---------------------------------------------------------------------");

	   while(fscanf(ptrbill,"%s %s %s %d %f %f %d %d %d",bil.billno,bil.cname,bil.mediname,&bil.medi_qty,&bil.medi_rate,&bil.total,&bil.day,&bil.month,&bil.year)!=EOF)
	   {

		       do
		       {
			if(strcmp(id,bil.billno)==0)
			{

				printf("\n\n\t\t %d",j);

				printf("\t %s",bil.mediname);

				printf("\t    %s",bil.cname);

				printf("      %d",bil.medi_qty);

				printf("    %.2f",bil.medi_rate);

				printf("    %.2f",bil.total);

				printf("   %d-%d-%d\n",bil.day,bil.month,bil.year);

				j++;

				netamt=netamt+bil.total;

				printf("                                \n\n");


			}


		}while(feof(ptrbill));

	   }


	   printf("\n\t\t---------------------------------------------------------------------");

	   printf("\n\n\t\t\t\tNet Amount : ");
	   printf("%.2f",netamt);


        printf("\n\n\t\t\t\tPress Any key to go to  MENU ...........");

	   fclose(ptrbill);
	   getch();
}
