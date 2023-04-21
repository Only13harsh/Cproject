#include "stdio.h"
#include <stdlib.h>

struct details
{
    char name[70];
    char address[70];
    char email[70];
    int phone_no;
    char lname[30];
    int serial_number;
    char warranty_status[20];
    char expert_name[100];
};

void create()
{

    FILE *fp;
    struct details *s;
    int n, i, j, c = 0;
    printf("No_Of_Client: ");
    scanf("%d", &n);
    fflush(stdin);

    s = (struct details *)calloc(n, sizeof(struct details));
    fp = fopen("client_detail.txt", "w");

    for (i = 0; i < n; i++)
    {
        printf("\nEnter Client Detials_no_%d: \n\n", ++c);

        printf("     %-12s:", "Enter name");
        scanf("%[^\n]s", s[i].name);
        fflush(stdin);

        printf("     %-12s:", "Address");
        scanf("%[^\n]s", s[i].address);
        fflush(stdin);

        printf("     %-12s:", "Phone_No");
        scanf("%d", &s[i].phone_no);
        fflush(stdin);

        printf("     %-12s:", "Email_Id ");
        scanf("%[^\n]s", s[i].email);
        fflush(stdin);

        printf("\n");

        printf("     %-16s", "Laptop name:");
        scanf("%[^\n]s", s[i].lname);
        fflush(stdin);

        printf("     %-16s", "Serial_No:");
        scanf("%d", &s[i].serial_number);
        fflush(stdin);

        printf("     %-16s", "Warranty Status:");
        scanf("%[^\n]s", s[i].warranty_status);
        fflush(stdin);

        printf("     %-16s", "Expert_Name:");
        scanf("%[^\n]s", s[i].expert_name);
        fflush(stdin);

        fwrite(&s[i], sizeof(struct details), 1, fp);
    }
    fclose(fp);
}

void display()
{
    struct details s1;
    FILE *fp;
    fp = fopen("client_detail.txt", "r");
    printf("\n%s", "+====================+======================+==============+======================+================+==============+===========+====================+");

    printf("\n|  %-18s|  %-20s|  %-12s|  %-20s|  %-14s|  %-12s|  %-9s|  %-18s|", "      NAME", "      ADDRESS", " PHONE_NO", "       EMAIL", "   LAPTOP", "   S.NO", "WARRANTY", "     EXPERT");
    printf("\n%s", "+====================+======================+==============+======================+================+==============+===========+====================+");

    while (fread(&s1, sizeof(struct details), 1, fp))
    {
        printf("\n|  %-18s|  %-20s|  %-12d|  %-20s|  %-14s|  %-12d|  %-9s|  %-18s|", s1.name, s1.address, s1.phone_no, s1.email, s1.lname, s1.serial_number, s1.warranty_status, s1.expert_name);
        printf("\n%s", "+--------------------+----------------------+--------------+----------------------+----------------+--------------+-----------+--------------------+");
    }
    fclose(fp);

    
}

void append()
{
    FILE *fp;
    struct details *s;
    int n, i, j, c = 0;
    printf("No_Of_Client: ");
    scanf("%d", &n);
    fflush(stdin);

    s = (struct details *)calloc(n, sizeof(struct details));
    fp = fopen("client_detail.txt", "a");

    for (i = 0; i < n; i++)
    {
        printf("\nEnter Client Detials%d: \n\n", ++c);

        printf("     %-12s:", "Enter name");
        scanf("%[^\n]s", s[i].name);
        fflush(stdin);

        printf("     %-12s:", "Address");
        scanf("%[^\n]s", s[i].address);
        fflush(stdin);

        printf("     %-12s:", "Phone_No");
        scanf("%d", &s[i].phone_no);
        fflush(stdin);

        printf("     %-12s:", "Email_Id ");
        scanf("%[^\n]s", s[i].email);
        fflush(stdin);

        printf("\n");

        printf("     %-16s", "Laptop name:");
        scanf("%[^\n]s", s[i].lname);
        fflush(stdin);

        printf("     %-16s", "Serial_No:");
        scanf("%d", &s[i].serial_number);
        fflush(stdin);

        printf("     %-16s", "Warranty Status:");
        scanf("%[^\n]s", s[i].warranty_status);
        fflush(stdin);

        printf("     %-16s", "Expert_Name:");
        scanf("%[^\n]s", s[i].expert_name);
        fflush(stdin);

        printf("\n");

        fwrite(&s[i], sizeof(struct details), 1, fp);
    }
    fclose(fp);
}

void search()
{
    int s_no, found = 0;
    struct details s1;
    FILE *fp;
    printf("Serial_No: ");
    scanf("%d", &s_no);

    printf("\n%s", "+====================+======================+==============+======================+================+==============+===========+====================+");
    // printf("\n%s","________________________________________________________________________________________");
    printf("\n|  %-18s|  %-20s|  %-12s|  %-20s|  %-14s|  %-12s|  %-9s|  %-18s|", "      Name", "      Address", " Phone_no", "       Email", "   Laptop", "   S.No", "Warranty", "     Expert");
    // printf("\n%s","-----------------------------------------------------------------------------------------");
    printf("\n%s", "+====================+======================+==============+======================+================+==============+===========+====================+");

    fp = fopen("client_detail.txt", "r");
    while (fread(&s1, sizeof(struct details), 1, fp))
    {

        if (s1.serial_number == s_no)
        {
            ++found;
            printf("\n|  %-18s|  %-20s|  %-12d|  %-20s|  %-14s|  %-12d|  %-9s|  %-18s|", s1.name, s1.address, s1.phone_no, s1.email, s1.lname, s1.serial_number, s1.warranty_status, s1.expert_name);
            printf("\n%s", "+--------------------+----------------------+--------------+----------------------+----------------+--------------+-----------+--------------------+");
        }
    }
    fclose(fp);
    if (found == 0)
    {
       printf("\n\n\t\t\t\t\t\t\t\t\033[1;31m NO Data Found\033[0m...... ");
    }
}

void update()
{
    int s_no, found = 0;
    struct details s1;
    FILE *fp, *fp1;
    printf("Serial_No: ");
    scanf("%d", &s_no);
    fflush(stdin);

    fp = fopen("client_detail.txt", "r");
    fp1 = fopen("temp.txt", "w");
    while (fread(&s1, sizeof(struct details), 1, fp))
    {

        if (s1.serial_number == s_no)
        {
            ++found;

            printf("\nEnter Client Detials: \n\n");
            printf("     %-12s:", "Enter name");
            scanf("%[^\n]s", s1.name);
            fflush(stdin);

            printf("     %-12s:", "Address");
            scanf("%[^\n]s", s1.address);
            fflush(stdin);

            printf("     %-12s:", "Phone_No");
            scanf("%d", &s1.phone_no);
            fflush(stdin);

            printf("     %-12s:", "Email_Id ");
            scanf("%[^\n]s", s1.email);
            fflush(stdin);

            printf("\n");

            printf("     %-16s", "Laptop name:");
            scanf("%[^\n]s", s1.lname);
            fflush(stdin);

            printf("     %-16s", "Serial_No:");
            scanf("%d", &s1.serial_number);
            fflush(stdin);

            printf("     %-16s", "Warranty Status:");
            scanf("%[^\n]s", s1.warranty_status);
            fflush(stdin);

            printf("     %-16s", "Expert_Name:");
            scanf("%[^\n]s", s1.expert_name);
            fflush(stdin);

            printf("\n");
        }
        fwrite(&s1, sizeof(struct details), 1, fp1);
        // fclose(fp);
    }
    fclose(fp1);
    fclose(fp);
    if (found == 0)
    {
        printf("\n                     Data Not Found                      \n");
    }
    else
    {
        fp = fopen("client_detail.txt", "w");
        fp1 = fopen("temp.txt", "r");
        while (fread(&s1, sizeof(struct details), 1, fp1))
        {
            fwrite(&s1, sizeof(struct details), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    }
}

void delete()
{
    int s_no, found = 0;
    struct details s1;
    FILE *fp, *fp1;
    printf("Serial_No: ");
    scanf("%d", &s_no);
    fflush(stdin);

    fp = fopen("client_detail.txt", "r");
    fp1 = fopen("temp.txt", "w");
    while (fread(&s1, sizeof(struct details), 1, fp))
    {

        if (s1.serial_number == s_no)
        {
            ++found;
        }
        else
        {
            fwrite(&s1, sizeof(struct details), 1, fp1);
        }
    }
    fclose(fp1);
    fclose(fp);

    if (found == 0)
    {
        printf("\n                     Data Not Found                      \n");
    }
    else
    {
        fp = fopen("client_detail.txt", "w");
        fp1 = fopen("temp.txt", "r");
        while (fread(&s1, sizeof(struct details), 1, fp1))
        {
            fwrite(&s1, sizeof(struct details), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    }
}

int main()
{
    system("cls");
    int ch;
    char a;
    do
    {
        printf("\033[34m");
        printf("\t\t\t  #############################################################################################\n");
        printf("\t\t\t  #############################################################################################\n");
        printf("\t\t\t  ###################|                                                  |######################\n");
        printf("\t\t\t  ###################|                \033[1;31mLAPTOP REPAIR SYSTEM              |######################\n");
        printf("\t\t\t  ###################|                                                  |######################\n");
        printf("\t\t\t  #############################################################################################\n");
        printf("\t\t\t  #############################################################################################\n");
        printf("\033[0m\n");

        printf("\033[36m");
        printf("\nAvailable Options are:\n");
        printf("\n        1)Create");
        printf("\n        2)Display");
        printf("\n        3)Append");
        printf("\n        4)Search");
        printf("\n        5)Update");
        printf("\n        6)Delete");
        printf("\n        0)Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            printf("\n\n\t\t\t\t\t\t\t\033[1;33mPress Enter To Continue\033[0m...... \n");
            getchar();
            system("cls");
            break;
        case 2:
            display();
            printf("\n\n\t\t\t\t\t\t\t\033[1;33mPress Enter To Continue\033[0m...... \n");
             getchar();
            gets(&a);
            system("cls");
            break;
        case 3:
            append();
            printf("\n\n\t\t\t\t\t\t\t\033[1;33mPress Enter To Continue\033[0m...... \n");
             gets(&a);
            system("cls");
            break;
        case 4:
            search();
            printf("\n\n\t\t\t\t\t\t\t\033[1;33mPress Enter To Continue\033[0m...... \n");
             fflush(stdin);
             gets(&a);
            // system("cls");
            break;
        case 5:
            update();
            printf("\n\n\t\t\t\t\t\t\t\033[1;33mPress Enter To Continue\033[0m...... \n");
             gets(&a);
            system("cls");
            break;
        case 6:
            delete ();
            printf("\n\n\t\t\t\t\t\t\t\033[1;33mPress Enter To Continue\033[0m...... \n");
             gets(&a);
            system("cls");
            break;
        case 0:
            break;
        }

    } while (ch != 0);
}