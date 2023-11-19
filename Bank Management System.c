#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//all functions
void login_menu();
void main_menu();
void close_program();
void data_to_file(FILE *);
int data_from_file(FILE *);
void new_account();
void edit_account();
void check_account();
void view_accounts();
void transactionf();
double interest( double, double, int);
//int remove_accountf();
//void view_transactions();

struct date{
    int day, month, year;
};

struct account_detail {
    int account_number;
    char name [60];
    int age;
    char address [60];
    int phone_number [12];
    char citizenship [20];
    int account_type;
    char account_typo [30];
    double amount;
    struct date dob_date, creation_date, withdraw_date, deposit_date;
} add, update, check, remove_account, transaction ;

//-------------------------------------------------------------------------------------------------------------------//
//main function
int main() {

    login_menu(); //calling login_menu()

    return 0;
}
//end of main function

//===================================================================================================================//

//function declaration

//login menu
void login_menu(){

    //declaring password
    char password[10]="bankmgnt";

    //declaring password variable
    char pass[10];

    //creating environment
    system("cls");
    system("color 7");

    //login menu prompt
    printf("\n\n\n\n\t\t\tWelcome to Banking Management Program\n\n\n");
    printf("\t\t\tPlease Enter your Credentials to Log in\n\n\n");
    printf("\t\t\tEnter Your Password: ");

    //taking password
    scanf("%s", pass);

    //verifying
    if (strcmpi(pass, password) == 0){
        printf("\n\n\n\t\t\tPassword Match!\n\n");
        system("cls");
        printf("\n\n\t\t\tWelcome");

        //welcome to main menu
        system("cls");
        main_menu();

    }
    else { //wrong password menu
        printf("\n\n\n\t\t\tWrong Password!\a\a\a");

        //login error trying options
        login_try:
        printf("\n\n\n\n\n\t\t\t1.\tTry Again\n\n\t\t\t0.\tExit\n\n\t\t\tChoice: ");

        //wrong password menu options
        int option;
        scanf("%d", &option);

        if (option == 1){
            login_menu();
        }
        else if (option == 0){
            close_program();
        }
        else{
            printf("\n\n\t\t\tInvalid!\a");
            goto login_try;
        }
    }
}
//------------------------------------------------------------------------------------------------------------------//

//main menu
void main_menu(void){

    //declaring choice variable
    int choice;

    switch_menu:

    //creating environment
    system("cls");
    system("color 7");



    //menu prompt
    printf("\n\n\t\t\tBanking Management System\t\t\t\n");
    printf("\n\n\n\t\t\t\xB2\xB2\tMAIN MENU\t\xB2\xB2\t\t\t\n\n\n\n");
    printf("\t\t1.\tCreate New Account\n"
           "\t\t2.\tUpdate Information of Existing Account\n"
           "\t\t3.\tCheck the Detail of Existing Account\n"
           "\t\t4.\tView Account Holders List\n"
           "\t\t5.\tMake Transactions\n"
           //"\t\t6.\tRemove Existing Account\n"
           //"\t\t7.\tView Last Transactions\n"
           "\t\t0.\tExit\n\n\n\n"
           "\t\tEnter Your Choice: ");

    //taking choice
    scanf("%d", &choice);


    //re-routing choice
    switch(choice){
        case 1:new_account();       break;
        case 2:edit_account();      break;
        case 3:check_account();     break;
        case 4:view_accounts();     break;
        case 5:transactionf();      break;
        //case 6:remove_accountf();   break;
        //case 7:view_transactions(); break;
        case 0:close_program();     break;
        default:goto switch_menu;   break;
    }
}
//-------------------------------------------------------------------------------------------------------------------//

//close program function()
void close_program(){
    printf("\n\n\n\n\t\t\tThis project is created by"
           "\n\t\t\t\t\t\t\tMir Suhail Asarat (2002019)"
           "\n\t\t\t\t\t\t\tMehedi Hasan Babu (2002037)"
           "\n\t\t\t\t\t\t\tMd. Sadman Sakib (2002070)\n\n\n\n\n\n\n\n");
}
//-------------------------------------------------------------------------------------------------------------------//

//new_account
void new_account(){


    system ("cls");

    //int choice;
    FILE *ptr;

    ptr = fopen ("record.dat", "a+");


    printf("\n\n\n\n\t\t\tADD RECORD\n\n");

    account_number_try:
    printf("\t\t\tEnter the Account Number: ");
    scanf("%d", &check.account_number);

    //checking account number in file
    while(data_from_file(ptr) != EOF){
        if (check.account_number == add.account_number){
            printf("\t\t\tAccount number is already in use! \a");
            goto account_number_try;
        }
        else
            goto account_creation_form;
    }

    account_creation_form:

    //passing account number from check.account_number to add.account_number
    add.account_number = check.account_number;


    //form prompt
    printf("\t\t\tAccount Holder Name: ");
    scanf("%s", add.name);

    printf("\n\t\t\tDate Of Birth (<dd><mm><yyyy>) : ");
    scanf("%d %d %d", &add.dob_date.day, &add.dob_date.month, &add.dob_date.year);

    printf("\n\t\t\tAge: ");
    scanf("%d", &add.age);

    printf("\n\t\t\tAddress: ");
    scanf("%s", &add.address);

    printf("\n\t\t\tCitizenship: ");
    scanf("%s", &add.citizenship);

    printf("\n\t\t\tPhone Number: ");
    scanf("%s", &add.phone_number);

    printf("\n\t\t\t||Account Types||\n"
           "\t\t1.\tCurrent\n"
           "\t\t2.\tSavings\n"
           "\t\t3.\tFixed Deposit (1 Year)\n"
           "\t\t4.\tFixed Deposit (2 Years)\n"
           "\t\t5.\tFixed Deposit (3 Years)\n"
           "\n\n\t\t\tAccount Type: ");
    scanf("%d", &add.account_type);

    printf("\t\t\tAccount Creation Date (<dd><mm><yyyy>) : ");
    scanf("%d %d %d", &add.creation_date.day, &add.creation_date.month, &add.creation_date.year);

    printf("\t\t\tDeposit Amount: ");
    scanf("%lf", &add.amount);

    printf("\t\t\tDeposit Date (<dd><mm><yyyy>) : ");
    scanf("%d %d %d", &add.deposit_date.day, &add.deposit_date.month, &add.deposit_date.year);

    //writing to ptr
    data_to_file(ptr);

    fclose(ptr);

    printf("\n\n\t\t\tAccount created successfully!");

    add_invalid_try:
    printf("\n\n\n\t\t\t0.\tMain Menu\n\n\t\t\tEnter: ");
    int option;
    scanf("%d", &option);

    if (option == 0)
        main_menu();
    else{
        printf("\n\n\t\t\tINVALID!\a;");
        system ("cls");
        goto add_invalid_try;
    }
}
//-------------------------------------------------------------------------------------------------------------------//

void view_accounts(){


    FILE *view;
    view = fopen ("record.dat","r");

    int lit = 0;

    system("cls");
    printf("\n\n\tAccount Number\tAccount Holder Name\tPhone Number\tAddress\n");
    printf("\t|--------------|\t|-------------------|\t|-------------|\t|-------------|\n");

    while(data_from_file(view) != EOF){
        printf("\t%d\t%s\t%d\t%d", add.account_number, add.name, add.phone_number, add.address);
        lit++;
    }

        invalid_view_menu_selection:
        printf("\n\n\t\t\t1.\tMain Menu"
        "\n\t\t\t0.\tExit"
        "\n\t\tChoice: ");
        int op;
        scanf("%d", &op);


        if (op == 1){
        main_menu();
        }
        else if (op == 0){
        close_program();
        }
        else{
        printf("\n\n\t\t\tINVALID INPUT!\a\a");
        system ("cls");
        goto invalid_view_menu_selection;
        }

    fclose (view);

    if (lit == 0){
        system ("cls");
        printf("\n\n\n\t\t\tNO RECORDS!\n\n");
    }

    //for invalid account number
    view_accounts_invalid:
    printf("\n\n\n\t\t\t1.\tMain Menu\n"
           "\t\t\t0.\tExit\n");
    int option;
    scanf("%d", &option);

    if (option == 1){
        main_menu();
    }
    else if (option == 0){
        close_program();
    }
    else{
        printf("\n\n\t\t\tINVALID!\a\n");
        system ("cls");
        goto view_accounts_invalid;
    }
}
//-------------------------------------------------------------------------------------------------------------------//

//edit account
void edit_account() {

    int choice, lit = 0;
    FILE *oldrec, *newrec;
    oldrec = fopen("record.dat", "r");
    newrec = fopen("newrec.dat", "w");

    printf("\n\n\t\t\tAccount Number: ");
    scanf("%d", &update.account_number);

    while (data_from_file(oldrec) != EOF) {
        if (add.account_number == update.account_number) {
            lit = 1;
            edit_account_change_menu:
            printf("\n\t\t\tChange"
                   "\n\t\t1.\tAddress"
                   "\n\t\t2.\tPhone Number");
            scanf("%d", &choice);
            system("cls");

            if (choice == 1) {
                printf("\n\n\n\t\t\tNew Address: ");
                scanf("%s", add.address);

                data_to_file(newrec);

                system("cls");
                printf("\n\n\t\tCHANGES SAVED!");
                main_menu();
            } else if (choice == 2) {
                printf("\n\n\n\t\t\tNew Phone Number: ");
                scanf("%s", add.phone_number);

                data_to_file(newrec);

                system("cls");
                printf("\n\n\t\tCHANGES SAVED!");
                main_menu();
            } else {
                printf("\n\n\t\tINVALID!\n");
                system("cls");
                goto edit_account_change_menu;
            }
        } else {
            data_to_file(newrec);
        }

    }

        fclose(oldrec);
        fclose(newrec);
        remove("record.dat");
        rename("newrec.dat", "record.dat");

        if (lit == 0) {
            system("cls");
            printf("\n\n\t\tRECORD NOT FOUND!\a");

            edit_account_invalid:
            printf("\n\n\n\t\t\t1.\tTry Again"
                   "\n\t\t\t2.\tMain Menu"
                   "\n\t\t\t0.\tExit"
                   "\n\t\t\tChoice: ");
            int option;
            scanf("%d", &option);

            if (option == 1) {
                edit_account();
            }
            else if (option == 2) {
                main_menu();
            }
            else if (option == 0) {
                close_program();
            }
            else {
                printf("\n\n\t\tINVALID!\a");
                goto edit_account_invalid;
            }
        }
}
//-------------------------------------------------------------------------------------------------------------------//

//transaction function
void transactionf(void){
    int choice, lit = 0;
    FILE *oldrec, *newrec;
    oldrec = fopen ("record.dat", "r");
    newrec = fopen ("newrec.dat", "w");

    system ("cls");

    printf("\n\n\t\t\tEnter Account Number: ");
    scanf("%d", &transaction.account_number);

    /*if (transaction.account_number == EOF){
        system ("cls");
        main_menu();
    }*/

    while (data_from_file(oldrec) != EOF) {
        if (add.account_number == transaction.account_number) {
            lit = 1;

            if (add.account_type == 3 || add.account_type == 4 || add.account_type == 5) {
                printf("\n\n\n\t\tDEPOSIT AND WITHDRAW FROM FIXED ACCOUNT IS UNAVAILABLE!\a");
                system("cls");
                main_menu();
            }
            else if (add.account_type == 1 || add.account_type == 2) {

                transaction_choice_error_try:
                printf("\n\n\n\t\t\t1.\tDeposit"
                       "\n\t\t\t2.\tWithdraw"
                       "\n\n\n\t\tChoice: ");
                scanf("%d", &choice);

                if (choice == 1) {
                    printf("\n\n\t\t\tDeposit Amount (BDT) : ");
                    scanf("%lf", &transaction.amount);
                    add.amount += transaction.amount;
                    printf("\n\t\t\tDeposit Date (<dd><mm><yyyy>) : ");
                    scanf("%d %d %d", &add.deposit_date.day, &add.deposit_date.month, &add.deposit_date.year);

                    data_to_file(newrec);

                    printf("\n\n\t\tDEPOSIT SUCCESSFUL!");
                    system("cls");
                    main_menu();
                }
                else if (choice == 2) {
                    printf("\n\n\t\t\tWithdraw Amount (BDT) : ");
                    scanf("%lf", &transaction.amount);

                    if (transaction.amount <= add.amount) {
                        add.amount -= transaction.amount;
                        printf("\n\t\t\tWithdraw Date (<dd><mm><yyyy>) : ");
                        scanf("%d %d %d", &add.withdraw_date.day, &add.withdraw_date.month, &add.withdraw_date.year);

                        data_to_file(newrec);

                        printf("WITHDRAW SUCCESSFUL!");
                        system("cls");
                        main_menu();
                    }
                    else if (transaction.amount > add.amount) {
                        printf("\n\n\t\tINSUFFICIENT MONEY\a");
                        system("cls");
                        main_menu();
                    }
                    else {
                        printf("\n\n\t\tINVALID INPUT!\n\n\t\t TRY AGAIN\a\a");
                        main_menu();
                    }
                }
                else {
                    printf("\n\n\t\tINVALID CHOICE!\a\a");
                    system("cls");
                    goto transaction_choice_error_try;
                }
            }
        }
        else {
            data_to_file(newrec);
        }
    }

    fclose(oldrec);
    fclose(newrec);
    remove ("record.dat");
    rename ("newrec.dat", "record.dat");

    if (lit == 0){
        printf("\n\t\tRECORD NOT FOUND!\a");

        invalid_transaction:
        printf("\n\n\t\t\t1.\tTry Again"
               "\n\t\t\t2.\tMain Menu"
               "\n\t\t\t0.\tExit");
        int option;
        scanf("%d", &option);


        if (option == 1){
            transactionf();
        }
        else if (option == 2){
            main_menu();
        }
        else if (option == 0){
            close_program();
        }
        else{
            printf("\n\n\t\t\tINVALID INPUT!\a\a");
            system ("cls");
            goto invalid_transaction;
        }
    }
}
//-------------------------------------------------------------------------------------------------------------------//
/*
//remove account function
int remove_accountf(){
    FILE *oldrec, *newrec;
    int lit = 0;
    oldrec = fopen ("record.dat", "r");
    newrec = fopen ("newrec.dat", "w");

    system ("cls");

    printf("\n\n\t\tEnter Account Number: ");
    scanf("%d", remove_account.account_number);


    while (data_from_file(oldrec) != EOF){
        lit = 1;
        if (remove_account.account_number == add.account_number){
            ///
            printf("\n\t\tRECORD DELETED!\a");
        }
        else{
            data_to_file(newrec);
            main_menu();
        }
    }

    fclose(oldrec);
    fclose(newrec);
    remove ("record.dat");
    rename ("newrec.dat", "record.dat");

    if (lit == 0){
        printf("\n\n\t\tRECORD NOT FOUND\a");
        invalid_remove_account:
        printf("\n\n\t\t\t1.\tTry Again"
               "\n\t\t\t2.\tMain Menu"
               "\n\t\t\t0.\tExit");
        int option;
        scanf("%d", &option);

        if (option == 1){
            remove_accountf();
        }
        else if (option == 2){
            main_menu();
        }
        else if (option == 0){
            close_program();
        }
        else{
            printf("\n\n\t\t\tINVALID INPUT!\a\a");
            system ("cls");
            goto invalid_remove_account;
        }
    }
}
 */
//--------------------------------------------------------------------------------------------------------------------//

//check account function
void check_account(void){

    int lit = 0, rate, choice;
    double time, interest_value;
    FILE *ptr;
    ptr = fopen ("record.dat", "r");

    system ("cls");
    printf("\n\n\t\tCheck By\n"
           "\t\t\t1.\tAccount Number\n"
           "\t\t\t2.\tAccount Holder Name\n"
           "\n\t\tChoice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n\t\t\tEnter Account Number: ");
        scanf("%d", &check.account_number);

        while (data_from_file(ptr) != EOF) {
            if (add.account_number == check.account_number) {
                lit = 1;

                system("cls");
                printf("\n\n\t\tAccount Number: \t%d\n"
                       "\t\tAccount Holder: %s\n"
                       "\t\tDate Of Birth: %s\n"
                       "\t\tAge: %d\n"
                       "\t\tAddress: %s\n"
                       "\t\tPhone Number: %s\n"
                       "\t\tCitizenship: %s\n"
                       "\t\tAccount Type: %d\n"
                       "\t\tAmount Deposited: %.2lf\n"
                       "\t\tAccount Creation Date (<dd><mm><yyyy>) : %d/%d/%d\n",
                       add.account_number,
                       add.name,
                       add.dob_date,
                       add.age,
                       add.address,
                       add.phone_number,
                       add.citizenship,
                       add.account_type,
                       add.amount,
                       add.creation_date.day,
                       add.creation_date.month,
                       add.creation_date.year);

                //checking account type
                if (add.account_type == 3) {
                    time = 1.0;
                    rate = 9;
                    interest_value = interest(time, add.amount, rate);
                    printf("\n\t\tInterest will be %.2lf on %d/%d/%d\n",
                           interest_value,
                           add.deposit_date.day,
                           add.deposit_date.month,
                           add.deposit_date.year + 1);
                } else if (add.account_type == 4) {
                    time = 2.0;
                    rate = 11;
                    interest_value = interest(time, add.amount, rate);
                    printf("\n\t\tInterest will be %.2lf on %d/%d/%d\n",
                           interest_value,
                           add.deposit_date.day,
                           add.deposit_date.month,
                           add.deposit_date.year + 2);
                } else if (add.account_type == 5) {
                    time = 3.0;
                    rate = 13;
                    interest_value = interest(time, add.amount, rate);
                    printf("\n\t\tInterest will be %.2lf on %d/%d/%d\n",
                           interest_value,
                           add.deposit_date.day,
                           add.deposit_date.month,
                           add.deposit_date.year + 3);
                } else if (add.account_type == 1) {
                    printf("\n\t\tIt is a Current Account");
                } else if (add.account_type == 2) {
                    time = (1.0 / 12.0);
                    rate = 8;
                    interest_value = interest(time, add.amount, rate);
                    printf("\n\t\tInterest will be %.2lf on %d day of every month\n",
                           interest_value,
                           add.deposit_date.day);
                }

                invalid_check_menu_selection:
                printf("\n\n\t\t\t1.\tMain Menu"
                "\n\t\t\t0.\tExit"
                "\n\t\tChoice: ");
                int option;
                scanf("%d", &option);


                if (option == 1){
                main_menu();
                }
                else if (option == 0){
                close_program();
                }
                else{
                printf("\n\n\t\t\tINVALID INPUT!\a\a");
                system ("cls");
                goto invalid_check_menu_selection;
                }
            }
        }
    }

    fclose (ptr);

    if (lit == 0){
        system ("cls");
        printf("\n\n\t\tRECORD NOT FOUND!\a\a");

        invalid_view_account:
        printf("\n\n\t\t\t1.\tTry Again"
               "\n\t\t\t2.\tMain Menu"
               "\n\t\t\t0.\tExit"
               "\n\t\tChoice: ");
        int option;
        scanf("%d", &option);


        if (option == 1){
            view_accounts();
        }
        else if (option == 2){
            main_menu();
        }
        else if (option == 0){
            close_program();
        }
        else{
            printf("\n\n\t\t\tINVALID INPUT!\a\a");
            system ("cls");
            goto invalid_view_account;
        }
    }
}
//-------------------------------------------------------------------------------------------------------------------//

//data from file
int data_from_file(FILE *file_name){
    fscanf (file_name,"%d %s %d %s %s %s %d %lf %d %d %d %d %d %d %d %d %d %d %d %d",
            &add.account_number,
            add.name,
            &add.age,
            add.address,
            add.phone_number,
            add.citizenship,
            &add.account_type,
            &add.amount,
            &add.dob_date.day,
            &add.dob_date.month,
            &add.dob_date.year,
            &add.creation_date.day,
            &add.creation_date.month,
            &add.creation_date.year,
            &add.deposit_date.day,
            &add.deposit_date.month,
            &add.deposit_date.year,
            &add.withdraw_date.day,
            &add.withdraw_date.month,
            &add.withdraw_date.year);
}
//--------------------------------------------------------------------------------------------------------------------//

//data to file
void data_to_file(FILE *file_name){
    fprintf(file_name, "%d %s %d %s %s %s %d %lf %d %d %d %d %d %d %d %d %d %d %d %d",
            add.account_number,
            add.name,
            add.age,
            add.address,
            add.phone_number,
            add.citizenship,
            add.account_type,
            add.amount,
            add.dob_date.day,
            add.dob_date.month,
            add.dob_date.year,
            add.creation_date.day,
            add.creation_date.month,
            add.creation_date.year,
            add.deposit_date.day,
            add.deposit_date.month,
            add.deposit_date.year,
            add.withdraw_date.day,
            add.withdraw_date.month,
            add.withdraw_date.year);
}
//-------------------------------------------------------------------------------------------------------------------//

//interest
double interest( double t, double amount, int rate){
    double SI;
    SI = (rate*t*amount)/100.0; //calculating interest
    return (SI);
}
//------------------------------------------------------------ --------------------------------------------------------//
