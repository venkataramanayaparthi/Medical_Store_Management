#ifndef MAIN_MENU_H_INCLUDED
#define MAIN_MENU_H_INCLUDED
void main_menu()
{
int choice =0;
    while(choice != 9)
    {
        system("cls");

        printf("\t\t\t\t");

        printf("\t");

        printf("Welcome To Medical Store \n\n");



          warning();

          printf("\t\t\t\t");

        printf("===============================================\n\n");

         printf("\t\t\t\t");

         printf("\t");

        printf("*********Main Menu*********\n\n");

         printf("\t\t\t\t");

        printf("===============================================\n\n");

         printf("\t\t\t\t");

        printf("Choose one option from the following list ...\n\n");

        printf("\t\t\t\t");

        printf("\t");

        printf("1.Supplier Info\n\n");

        printf("\t\t\t\t");

        printf("\t");

        printf("2.Customer Info\n\n");

        printf("\t\t\t\t");

        printf("\t");

        printf("3. Medicine Info\n\n");

        printf("\t\t\t\t");

        printf("\t");

        printf("4. Report\n\n");

        printf("\t\t\t\t");

        printf("\t");

        printf("5. Bill\n\n");

        printf("\t\t\t\t");

        printf("\t");

        printf("6.Exit\n\n");

        printf("\t\t\t\t");

        printf("Enter your choice?");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            supplier();
            break;
            case 2:
            customer();
            break;
            case 3:
            medicine();
            break;
            case 4:
            report_menu();
            break;
            case 5:
            bill();
            break;
            case 6:system("cls");
                printf("\033[0;33m");
                printf("\n\n\n\n\n\t\t\t**********THANKS FOR VISITING**********\t\t\n\n");
                printf("\n\n\n\n\n\t\t\t##########PLEASE VISIT AGAIN##########\t\t\n\n");
                printf("\033[0m");
                getche();
                system("cls");
            exit(0);
            break;
            default:
            printf("Please enter valid choice..");
        }
    }
}


#endif // MAIN_MENU_H_INCLUDED
