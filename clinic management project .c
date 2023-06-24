#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_SPECIALTIES 100
#define MAX_PATIENTS 100
#define MAX_MEDICINES 100
#define MAX_EQUIPMENT 100

int count = 0;

struct Speciality
{
    int serial_no;
    int doc_id;
    char name[50];
    int age;
    char gender[20];
    char address[70];
    char contact_No[15];
    char symptoms[150];
    int pre_Admission_Status;
    int id;
    double price;
    float cost;
};

struct Speciality total[MAX_SPECIALTIES];

void WelcomeScreen()
{
    printf("\n\n\n\n\n\t\t\t\t#########################################");
    printf("\n\t\t\t\t#\t\tWELCOME TO \t\t#");
    printf("\n\t\t\t\t#   SSA CLINIC CENTER MANAGEMENT SYSTEM #");
    printf("\n\t\t\t\t#########################################");
    printf("\n\n\n\nPress any key to continue.............\n");
    getch();
    system("cls");
}

void Title()
{
    printf("\n\n\t\t\t-------------------------------------------------------------------------------");
    printf("\n\t\t\t|                              SSA  CLINIC CENTER                             |");
    printf("\n\t\t\t-------------------------------------------------------------------------------");
}

void MainMenu()
{
    system("cls");
    int choice;
    do
    {
        system("cls");
        int choose;
        Title();
        printf("\n\n\n\n\n\t\t\t\t\t1. Add Surgical Speciality.\n");
        printf("\n\t\t\t\t\t2. Display Surgical Speciality.\n");
        printf("\n\t\t\t\t\t3. Online Admission Form.\n");
        printf("\n\t\t\t\t\t4. Display Online Admission form.\n");
        printf("\n\t\t\t\t\t5. Add Medicine.\n");
        printf("\n\t\t\t\t\t6. Display Medicines.\n");
        printf("\n\t\t\t\t\t7. My Health Record.\n");
        printf("\n\t\t\t\t\t8. Add Equipment.\n");
        printf("\n\t\t\t\t\t9. Calculate Equipment cost.\n");
        printf("\n\t\t\t\t\t10. Contact Us.\n");
        printf("\n\t\t\t\t\t11. Hospital News.\n");
        printf("\n\t\t\t\t\t12. Exit.\n");
        printf("\n\t\t\t\t\tEnter Your choice Number(1 to 12): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Add_Specialty();
            break;
        case 2:
            Display_Surgical();
            break;
        case 3:
            On_Add_fo();
            break;
        case 4:
            Display_On_Add_fo();
            break;
        case 5:
            Add_medi();
            break;
        case 6:
            Dis_Add_medi();
            break;
        case 7:
            My_Heal_R();
            break;
        case 8:
            Add_Equip();
            break;
        case 9:
            cal_Equip_cost();
            break;
        case 10:
            cont_us();
            break;
        case 11:
            Hos_news();
            break;
        case 12:
            ex_it();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 12);
}

void ex_it()
{
    system("cls");
    Title();
    printf("\n\n\n\n\n\n\t\t\t\t\tTHANK YOU FOR VISITING!\n");
    getch();
}

void Add_Specialty()
{
    system("cls");
    printf("\n\t\t\t---------------------------------------------------------------");
    printf("\n\t\t\t|                          Add Specialty                      |");
    printf("\n\t\t\t---------------------------------------------------------------");
    struct Speciality s;
    printf("\n\n\n\t\t\t\tEnter Your Specialty ID: ");
    scanf("%d", &s.doc_id);
    printf("\n\t\t\t\tEnter Your Specialty name: ");
    scanf("%s", s.name);
    total[count++] = s;
    printf("\n\t\t\t\tSpecialty added successfully!\n");
    getch();
}

void Display_Surgical()
{
    system("cls");
    Title();
    if (count == 0)
    {
        printf("\n\t\t\t\tNo specialties found.\n");
    }
    else
    {
        printf("\n\t\t\t\tID\t\tSpecialties Name");
        printf("\n\n\t\t\t\t-------------------------------");
        for (int i = 0; i < count; i++)
        {
            printf("\n\t\t\t\t%d\t\t%s", total[i].doc_id, total[i].name);
        }
    }
    getch();
}

void On_Add_fo()
{

}

void Display_On_Add_fo()
{

}

void Add_medi()
{

}

void Dis_Add_medi()
{

}

void My_Heal_R()
{

}

void Add_Equip()
{

}

void cal_Equip_cost()
{

}

void cont_us()
{

}

void Hos_news()
{

}

int main()
{
    WelcomeScreen();
    Title();
    MainMenu();
    return 0;
}
