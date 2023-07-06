#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_specialties 100
#define max_patients 100
#define max_medicines 100
#define max_equipment 100

typedef struct {
    int id;
    char name[50];
} Specialty;

typedef struct {
    char name[50];
    int age;
    char gender[10];
    char address[100];
    char contactNumber[15];
    char symptoms[200];
    int preAdmissionStatus;
} Patient;

typedef struct {
    int id;
    char name[50];
    float price;
} Medicine;

typedef struct {
    int id;
    char name[50];
    float cost;
} Equipment;

Specialty sp[max_specialties];
int spcount = 0;

Patient p[max_patients];
int pcount = 0;

Medicine m[max_medicines];
int mcount = 0;

Equipment e[max_equipment];
int ecount = 0;

void WelcomeScreen()
{
    printf("\n\n\n\n\n\t\t\t\t#########################################");
    printf("\n\t\t\t\t#\t\tWELCOME TO \t\t#");
    printf("\n\t\t\t\t#   SSA CLINIC CENTER MANAGEMENT SYSTEM #");
    printf("\n\t\t\t\t#########################################");
    printf("\n\n\n\nPress any key to continue.............\n");
    getchar();
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
        printf("\n\n\n\t\t\t\t\t1. Add Surgical Specialty.\n");
        printf("\n\t\t\t\t\t2. Display Surgical Specialty.\n");
        printf("\n\t\t\t\t\t3. Online Admission Form.\n");
        printf("\n\t\t\t\t\t4. Display Online Admission form.\n");
        printf("\n\t\t\t\t\t5. Add Medicine.\n");
        printf("\n\t\t\t\t\t6. Display Medicines.\n");
        printf("\n\t\t\t\t\t7. Patient Health Record.\n");
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
            printf("\n\n\n\t\t\t\tInvalid Input! Please enter a valid choice from 1 to 12.");
            break;
        }
        printf("\n\n\nPress any key to continue.............\n");
        getchar();
        getchar();
    } while (choice != 12);
}

void Add_Specialty()
{
    system("cls");
    Title();
    printf("\n\n\n\n\n\n\n\t\t\t\tEnter Surgical Specialty ID: ");
    scanf("%d", &sp[spcount].id);
    printf("\n\t\t\t\tEnter Surgical Specialty Name: ");
    scanf("%s", sp[spcount].name);
    spcount++;
}

void Display_Surgical()
{
    system("cls");
    Title();
    if (spcount == 0)
    {
        printf("\n\n\t\t\t\tNo Surgical Specialty Added!");
    }
    else
    {
        printf("\n\n\n\t\t\t\tSurgical Specialty List\n");
        printf("\t\t\t\t-----------------------\n");
        printf("\t\t\t\tID\t|\tSpecialty\n");
        printf("\t\t\t\t-----------------------\n");
        for (int i = 0; i < spcount; i++)
        {
            printf("\t\t\t\t%d\t|\t%s\n", sp[i].id, sp[i].name);
        }
    }
}

void On_Add_fo()
{
    system("cls");
    Title();
    printf("\n\n\n\n\n\n\n\n\t\t\t\tPatient Name: ");
    scanf("%s", p[pcount].name);
    printf("\n\t\t\t\tAge: ");
    scanf("%d", &p[pcount].age);
    printf("\n\t\t\t\tGender: ");
    scanf("%s", p[pcount].gender);
    printf("\n\t\t\t\tAddress: ");
    scanf("%s", p[pcount].address);
    printf("\n\t\t\t\tContact Number: ");
    scanf("%s", p[pcount].contactNumber);
    printf("\n\t\t\t\tSymptoms: ");
    scanf("%s", p[pcount].symptoms);
    p[pcount].preAdmissionStatus = 1;
    pcount++;
}

void Display_On_Add_fo()
{
    system("cls");
    Title();
    if (pcount == 0)
    {
        printf("\n\n\t\t\t\tNo Online Admission Form Added!");
    }
    else
    {
        printf("\n\n\n\t\t\t\tOnline Admission Form List\n");
        printf("\t\t\t\t-------------------------\n");
        printf("\t\t\t\tName\t|\tAge\t|\tGender\t|\tAddress\t|\tContact Number\t|\tSymptoms\n");
        printf("\t\t\t\t--------------------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < pcount; i++)
        {
            printf("\t\t\t\t%s\t|\t%d\t|\t%s\t|\t%s\t|\t%s\t|\t%s\n", p[i].name, p[i].age, p[i].gender, p[i].address, p[i].contactNumber, p[i].symptoms);
        }
    }
}

void Add_medi()
{
    system("cls");
    Title();
    printf("\n\n\n\n\n\n\n\n\t\t\t\tEnter Medicine ID: ");
    scanf("%d", &m[mcount].id);
    printf("\n\t\t\t\tEnter Medicine Name: ");
    scanf("%s", m[mcount].name);
    printf("\n\t\t\t\tEnter Medicine Price: ");
    scanf("%f", &m[mcount].price);
    mcount++;
}

void Dis_Add_medi()
{
    system("cls");
    Title();
    if (mcount == 0)
    {
        printf("\n\n\t\t\t\tNo Medicines Added!");
    }
    else
    {
        printf("\n\n\n\t\t\t\tMedicine List\n");
        printf("\t\t\t\t-------------\n");
        printf("\t\t\t\tID\t|\tMedicine Name\t|\tPrice\n");
        printf("\t\t\t\t------------------------------------\n");
        for (int i = 0; i < mcount; i++)
        {
            printf("\t\t\t\t%d\t|\t%s\t|\t%.2f\n", m[i].id, m[i].name, m[i].price);
        }
    }
}

void My_Heal_R()
{
    system("cls");
    Title();
    if (pcount == 0)
    {
        printf("\n\n\t\t\t\tNo Health Records Found!");
    }
    else
    {
        printf("\n\n\n\t\t\t\tHealth Records List\n");
        printf("\t\t\t\t--------------------\n");
        printf("\t\t\t\tName\t|\tAge\t|\tGender\t|\tAddress\t|\tContact Number\t|\tSymptoms\n");
        printf("\t\t\t\t--------------------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < pcount; i++)
        {
            printf("\t\t\t\t%s\t|\t%d\t|\t%s\t|\t%s\t|\t%s\t|\t%s\n", p[i].name, p[i].age, p[i].gender, p[i].address, p[i].contactNumber, p[i].symptoms);
        }
    }
}

void Add_Equip()
{
    system("cls");
    Title();
    printf("\n\n\n\n\n\n\n\n\t\t\t\tEnter Equipment ID: ");
    scanf("%d", &e[ecount].id);
    printf("\n\t\t\t\tEnter Equipment Name: ");
    scanf("%s", e[ecount].name);
    printf("\n\t\t\t\tEnter Equipment Cost: ");
    scanf("%f", &e[ecount].cost);
    ecount++;
}

void cal_Equip_cost()
{
    system("cls");
    Title();
    float totalCost = 0;
    if (ecount == 0)
    {
        printf("\n\n\t\t\t\tNo Equipment Added!");
    }
    else
    {
        for (int i = 0; i < ecount; i++)
        {
            totalCost += e[i].cost;
        }
        printf("\n\n\t\t\t\tTotal Equipment Cost: %.2f", totalCost);
    }
}

void cont_us()
{
    system("cls");
    Title();
    printf("\n\n\t\t\t\t\t\tContact Us\n");
    printf("\t\t\t\t\t\t---------\n");
    printf("\n\t\t\t\t\tSSA Clinic Center\n");
    printf("\n\t\t\t\t\tAddress: pollobi , Mirpur-12 , Dhaka \n");
    printf("\n\t\t\t\t\tContact Number: 01909125813\n");
    printf("\n\t\t\t\t\tEmail: ssaclinicmanagement1@gmail\n");
}

void Hos_news()
{
    system("cls");
    Title();
    printf("\n\n\t\t\t\t\t   Hospital News\n");
    printf("\t\t\t\t\t   ------------\n");
    printf("\n\t\t\t\t\t- New surgical specialty added.\n");
    printf("\n\t\t\t\t\t- Special discounts on medicines.\n");
    printf("\n\t\t\t\t\t- Upgraded equipment for better patient care.\n");
}

void ex_it()
{
    system("cls");
    Title();
    printf("\n\t\t\t\tThank you for watching SSA Clinic Center Management System!\n");
    printf("\n\t\t\t\t\t\tHave a nice day!\n");

}

int main()
{
    WelcomeScreen();
    MainMenu();
    return 0;
}
