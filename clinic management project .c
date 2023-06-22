
#include<stdio.h>
#include<conio.h>
#include<string.h>

char num1[];
int age[];
int total = 0,b = 0 ;

void WelcomeScreen(void);
void Title(void);
void MainMenu(void);
void Add_rec(void);
void func_List(void);
void Search_rec(void);
void Edit_rec(void);
void Dlt_rec(void);
void ex_it(void);

struct patient {
    int age;
    char gender;
    char first_Name[20];
    char last_Name[20];
    char contact_No[15];
    char address[30];
    char email[30];
    char doctor[30];
    char problem[20];
};
struct patient p,temp_c;

int main(void) {
    WelcomeScreen();
    Title();
    MainMenu();
}
void WelcomeScreen(void)
{
    printf("\n\n\n\n\n\t\t\t\t#########################################");
    printf("\n\t\t\t\t#\t\tWELCOME TO \t\t#");
    printf("\n\t\t\t\t#   SSA CLINIC CENTER MANAGEMENT SYSTEM #");
    printf("\n\t\t\t\t#########################################");
    printf("\n\n\n\nPress any key to continue.............\n");
    getch();
    system("cls");
}
void Title(void)
{
        printf("\n\n\t\t-------------------------------------------------------------------------------");
        printf("\n\t\t|                              SSA  CLINIC CENTER                             |");
        printf("\n\t\t-------------------------------------------------------------------------------");
}
void MainMenu(void)
{
    system("cls");
    int choose ;
    Title();
    printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record.\n");
    printf("\n\t\t\t\t2. Show Patients Record.\n");
    printf("\n\t\t\t\t3. Search Patients Record.\n");
    printf("\n\t\t\t\t4. Edit Patients Record .\n");
    printf("\n\t\t\t\t5. Delete Patients Record .\n");
    printf("\n\t\t\t\t6. Exit.\n");
    printf("\n\n\n\n\t\t\t\tChoose from 1 to 6:");
    scanf("%i",&choose);
    switch(choose)
    {
        case 1 :
            Add_rec();
            break ;
        case 2 :
            Show_list();
            break ;
        case 3 :
            Search_rec();
            break ;
        case 4 :
            Edit_rec();
            break ;
        case 5 :
            Dlt_rec();
            break ;
        case 6 :
            ex_it();
            break ;
        default :
            printf("\t\t\tInvalid entry . Please Enter right option :-  ");
            getch();
    }
}

void ex_it(void){
    system("cls");
    Title();
    printf("\n\n\n\n\n\n\t\t\t\t\THANK YOU FOR VISITING  :- ");
    getch();
}
void Add_rec() {
    system("cls");
    FILE* sa;
    sa = fopen("Record.dat", "a");
    if (sa == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\n\n\t\t\t!!!!!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!!!!!!");

    A:
    printf("\n\t\t\tFirst Name : ");
    scanf("%20s", p.first_Name); // Use %20s to limit the input to 20 characters
    p.first_Name[0] = toupper(p.first_Name[0]);

    if (strlen(p.first_Name) > 20 || strlen(p.first_Name) < 2) {
        printf("\n\t Invalid: The max range for the first name is 20 and the min range is 2.\n");
        goto A;
    } else {
        int total = 1;
        for (int b = 0; b < strlen(p.first_Name); b++) {
            if (!isalpha(p.first_Name[b])) {
                total = 0;
                break;
            }
        }
        if (!total) {
            printf("\n\t\t First name contains invalid characters.\n");
            printf("\n\t\t Please enter again: ");
            goto A;
        }
    }

    // Write the patient's record to the file
    fprintf(sa, "%s\n", p.first_Name);

    fclose(sa);
}

 void Show_list(){

 }
 void Search_rec(){
 }
  void Edit_rec(){
  }
 void Dlt_rec(){
 }

