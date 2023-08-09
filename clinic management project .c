#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define MAX_PATIENTS 100
struct Patient
{
    char name[40];
    int age;
    char gender[20];
    char phoneNumber[20];
    char admiteDate[20];
    char dischargeDate[20];
    char attendingDoctor[40];
    char disease[40];
};
struct Patient patients[MAX_PATIENTS];
int numberOfPatient=0;
void addPatient();
void readPatient();
void updatePatient();
void deletePatient();
void printPatient();
void dashBoard();
//Function for addPatient
void addPatient()
{
    system("cls");
    if(numberOfPatient>=MAX_PATIENTS)
    {
        printf("\nMaximum number of patient is reached!\n");
        return;
    }
    struct Patient newPatient;
    printf("/nEnter the name of patient : ");
    scanf("%s",&newPatient.name);
    printf("Enter the age of patient : ");
    scanf("%d",&newPatient.age);
    printf("Enter the gender of patient : ");
    scanf("%s",&newPatient.gender);
    printf("Enter the phone number : ");
    scanf("%s",&newPatient.phoneNumber);
    printf("Enter the admition Date : ");
    scanf("%s",&newPatient.admiteDate);
    printf("Enter the discharge Date : ");
    scanf("%s",&newPatient.dischargeDate);
    printf("Enter the attending doctor name : ");
    scanf("%s",&newPatient.attendingDoctor);
    printf("Enter the disease name : ");
    scanf("%s",&newPatient.disease);
    patients[numberOfPatient]=newPatient;
    numberOfPatient++;
    printf("New patient add successfully.\n");
}
//Function for delete patient
void deletePatient()
{
    system("cls");
    if(numberOfPatient == 0)
    {
        printf("\nThere is no patient for delete.\n");
        return;
    }
    char deletePatient[40];
    printf("\nEnter the name of  Patient to delete : ");
    scanf("%s",&deletePatient);
    int found = 0;
    for(int i=0;i<numberOfPatient;i++)
    {
        if(strcmp(deletePatient,patients[i].name) == 0)
        {
            for(int j=i;j<numberOfPatient-1;j++)
            {
                patients[j]=patients[j+1];
            }
            numberOfPatient--;
            found = 1;
            break;
        }
    }
    if(found == 1)
    {
        printf("Information of patient is deleted successfully.\n");
    }
    else
    {
        printf("patient is not found.\n");
    }
}
//Function for update patient information
void updatePatient()
{
    system("cls");
    if(numberOfPatient == 0)
    {
        printf("\nThere is no patient to update his/her information.\n");
        return;
    }
    char updateToName[40];
    printf("\nEnter the name of patient to update : ");
    scanf("%s",&updateToName);
    int found = 0;
    for(int i=0;i<numberOfPatient;i++)
    {
        if(strcmp(updateToName,patients[i].name) == 0)
        {
            printf("\nEnter the new age of patient : ");
            scanf("%d",&patients[i].age);
            printf("Enter the new gender of patient : ");
            scanf("%s",&patients[i].gender);
            printf("Enter the new phone number : ");
            scanf("%s",&patients[i].phoneNumber);
            printf("Enter the new admition Date : ");
            scanf("%s",&patients[i].admiteDate);
            printf("Enter the new discharge Date : ");
            scanf("%s",&patients[i].dischargeDate);
            printf("Enter the new attending doctor name : ");
            scanf("%s",&patients[i].attendingDoctor);
            printf("Enter the new disease name : ");
            scanf("%s",&patients[i].disease);
            found = 1;
            break;
        }
    }
    if(found == 1)
    {
        printf("\npatient information is updated successfully.\n");
    }
    else
    {
        printf("\nPatient is not found.\n");
    }
}
//Function of read patient information
void readPatient()
{
    system("cls");
    if(numberOfPatient == 0)
    {
        printf("\nThere is no patient to read information.\n");
        return;
    }
    char nameToRead[40];
    printf("\nEnter the name of patient to read info : ");
    scanf("%s",&nameToRead);
    int found = 0;
    for(int i=0;i<numberOfPatient;i++)
    {
        if(strcmp(nameToRead,patients[i].name) == 0)
        {
            printf("Age : %d\n",patients[i].age);
            printf("Gender : %s\n",patients[i].gender);
            printf("Admition Date: %s\n",patients[i].admiteDate);
            printf("Discharge Date : %s\n",patients[i].dischargeDate);
            printf("phone number : %s\n",patients[i].phoneNumber);
            printf("Attending Doctor : %s\n",patients[i].attendingDoctor);
            printf("Disease : %s\n",patients[i].disease);
            found = 1;
            break;
        }
    }
    if(found == 1)
    {
        printf("\nRead the patient information successfully.\n");
    }
    else
    {
        printf("\n patient is not found.\n ");
    }
}
//function to print all patient
void printPatient()
{
    system("cls");
     if(numberOfPatient == 0)
    {
        printf("\nThere is no patient to print information.\n");
        return;
    }
    printf("\nList of patient:\n");
    for(int i=0;i<numberOfPatient;i++)
    {
        printf("\n%d.Name : %s\n",i+1,patients[i].name);
        printf(" Age : %d\n",patients[i].age);
        printf(" phone number : %s\n",patients[i].phoneNumber);
        printf(" Admition Date : %s\n",patients[i].admiteDate);
        printf(" Discharge Date : %s\n",patients[i].dischargeDate);
        printf(" Gender : %s\n",patients[i].gender);
        printf(" Attending Doctor : %s\n",patients[i].attendingDoctor);
        printf(" Disease : %s\n",patients[i].disease);


        }
    }
//DashBoard of the program
void dashBoard()
{
    char key;
    printf("\n\n\t\t\t*////*WELCOME TO DOCTORS & PATIENTS FRIENDLY HOSPITAL MANAGEMENT APP*///*");
    printf("\n\n\n\nI will be honoured and happy to make your hospital journey easy and warm.\n\n");
    printf("For this please any key to start the journey......\n");
    scanf("%c",&key);
    if (key>=0)
    {
        return;
    }
}
struct appointment
{
    int serial;
    char name[40];
    char NID[20];
    char phoneNumber[12];
    char symptoms[60];
    struct appointment *next;
};
typedef struct appointment patient;
int token=20;
patient *head;
//function for take appointment
void patientAppointment(patient *pointer)
{
    system("cls");
    int serial;
    char key;
    if(token == 0)
    {
        printf("\n\nSorry!Today's all appointments are full.\n\n");
        printf("Try to book an appointment for tomorrow early morning at 8 AM.\n");
    }
    else
    {
        if(pointer == NULL)
        {
            head=(patient*)malloc(sizeof(patient));
            pointer=head;
            pointer->next=NULL;
            patient_Information:
                printf("\n\nEnter patient name : ");
                getchar();
                gets(pointer->name);
                printf("Enter the NID/Birth Certificate no : ");
                scanf("%s",&pointer->NID);
                printf("Enter patient symptoms : ");
                getchar();
                gets(pointer->symptoms);
           mobile_no:
            printf("Enter your 11 digits phone number : ");
            gets(pointer->phoneNumber);
            int length = strlen(pointer->phoneNumber);

            if(length != 11)
            {
               printf("\nInvalid Mobile Number. Please, give valid mobile number.\n");
               goto mobile_no;
            }
           int i;
           for(i = 0; pointer -> phoneNumber[i]!=NULL; i++)
           {
            if(pointer->phoneNumber[i]<'0' || pointer->phoneNumber[i]>'9')
            {
                 printf("\nInvalid Mobile Number. Please, give valid mobile number.\n");
                 goto mobile_no;
            }
           }
        token--;
        serial = 20 - token;
        pointer->serial = serial;
        printf("\n Your Appointment with Doctor is Booked Successfully for Today.\n");
        printf("Your serial no : %d.\n", pointer->serial);
        printf("\nPress any key to continue : ");
        scanf("%c", &key);
        if(key >= 0)
        return;
        }
        while(pointer->next != NULL)
        {
            pointer = pointer->next;
        }
        pointer->next = (patient*)malloc(sizeof(patient));
        pointer = pointer->next;
        pointer->next = NULL;
        goto patient_Information;
    }
}
//function for doctor appointment list
void displayAppointment(patient *pointer)
{
    system("cls");
    if(pointer == NULL)
    {
        printf("\n\nNo appointment is booked for today yet!!\n");
        printf("If you want to book an appointment please,proceed.....\n");
    }
    else
    {
        printf("\n\n\t\t\tPatient List : \n");
        printf("\t\t\t----------------");
        while(pointer != NULL)
        {
            printf("\nSerial no : %d\n",pointer->serial);
            printf("Patient name : %s\n",pointer->name);
            printf("NID no : %s\n",pointer->NID);
            printf("phone number : %s\n",pointer->phoneNumber);
            printf("Symptoms : %s\n",pointer->symptoms);
            pointer=pointer->next;
        }
    }
}
//structure for online Admission Form
struct admissionForm
{
     char name[40];
    char gender[20];
    char dateOfBirth[20];
    char phoneNumber[12];
    char guardianName[40];
    char guardianNumber[12];
    int admissionFee;
    char signature[40];
};
struct admissionForm pForm[MAX_PATIENTS];
int numberOfForm = 0;

void createAdmissionForm()
{
    system("cls");
    if(numberOfForm>=MAX_PATIENTS)
    {
        printf("Error !Maximum number of online Admission form is reached.\n");
    }
    struct admissionForm newpatient;
    printf("Enter the patient name : ");
    getchar();
    gets(newpatient.name);
    printf("Enter Gender : ");
    scanf("%s",&newpatient.gender);
    printf("Enter Date Of Birth : ");
    scanf("%s",&newpatient.dateOfBirth);
    printf("Enter phone number : ");
    scanf("%s",&newpatient.phoneNumber);
    printf("Enter Guardian name : ");
    scanf("%s",&newpatient.guardianName);
    printf("Enter Guardian phone number : ");
    scanf("%s",&newpatient.guardianNumber);
    printf("Enter admission fee : ");
    scanf("%d",&newpatient.admissionFee);
    printf("Signature : ");
    scanf("%s",&newpatient.signature);
    pForm[numberOfForm]=newpatient;
    numberOfForm++;
    printf("\nOnline Admission Form is filled successfully.\n");
    }
//function for delete online admission form
void deleteAdmissionForm()
{
    system("cls");
    if(numberOfForm == 0)
    {
        printf("Sorry! There is no Admission Form to delete.\n");
    }
    int found = 0;
    char deletePatient[40];
    printf("Enter the patient name for delete Admission Form : ");
    scanf("%s",&deletePatient);
    for(int i=0;i<numberOfForm;i++)
    {
        if(strcmp(deletePatient,pForm[i].name)==0)
        {
            for(int j=i;j<numberOfForm-1;j++)
            {
                pForm[j]=pForm[j+1];
            }
            numberOfForm--;
            found = 1;
            break;
        }
    }
    if(found == 1)
    {
        printf("\n Admission form is delete successfully.\n");
    }
    else
    {
        printf("\nPatient Admission form is not found.\n");
    }

}
//function to update Admission forn
void updateAdmissionForm()
{
    system("cls");
    if(numberOfForm==0)
    {
        printf("\nSorry ! No Admission Form to Update.\n");
    }
    int found =0;
    char updatePatient[40];
    printf("Enter the patient name to update his/her Admission form : ");
    scanf("%s",&updatePatient);
    for(int i=0;i<numberOfForm;i++)
    {
        if(strcmp(updatePatient,pForm[i].name)==0)
        {
            printf("Enter new Gender : ");
    scanf("%s",&pForm[i].gender);
    printf("Enter new Date Of Birth : ");
    scanf("%s",&pForm[i].dateOfBirth);
    printf("Enter new phone number : ");
    scanf("%s",&pForm[i].phoneNumber);
    printf("Enter new Guardian name : ");
    scanf("%s",&pForm[i].guardianName);
    printf("Enter Guardian new phone number : ");
    scanf("%s",&pForm[i].guardianNumber);
    printf("Enter admission fee : ");
    scanf("%d",&pForm[i].admissionFee);
    printf("Signature : ");
    scanf("%s",&pForm[i].signature);
found = 1;
break;
        }
    }
    if(found == 1)
    {
        printf("\nAdmission Form is update successfully.\n");
    }
    else{
        printf("\npatient is not found.\n");
    }
}
//function to read admission form
void readAdmissionForm()
{
    system("cls");
    if(numberOfForm==0)
    {
        printf("sorry !There is no Admission form of any patient.\n ");
    }
    int found = 0;
    char readPatient[40];
    printf("Enter patient name to read his/her Adnission form : ");
    scanf("%s",&readPatient);
    for(int i=0;i<numberOfForm;i++)
    {
        if(strcmp(readPatient,pForm[i].name)==0)
        {
            printf("\n\t\t\tADMISSION FORM\n");
            printf("patient name : %s\n",pForm[i].name);
            printf("Gender : %s\n",pForm[i].gender);
            printf("Date Of Birth : %s\n",pForm[i].dateOfBirth);
            printf("Phone Number : %s\n",pForm[i].phoneNumber);
            printf("Guardian name : %s\n",pForm[i].guardianName);
            printf("Guardian phone number : %s\n",pForm[i].guardianNumber);
            printf("Admission Fee : %d TK\n",pForm[i].admissionFee);
            printf("Signature : %s\n",pForm[i].signature);
            found=1;
            break;
        }
    }
    if(found == 1)
    {
        printf("\nAdmission form is read successfully.\n");
    }
    else
    {
        printf("\nSorry ! Admission form is not found.\n");
    }
}
//function to print all admission form
void printAdmissionForm()
{
    system("cls");
    if(numberOfForm==0)
    {
        printf("sorry !There is no Admission form to print.\n ");
    }
    else{
    printf("\n\t\t\tADMISSION FORM\n");
    for(int i=0;i<numberOfForm;i++)
    {
            printf("%d.patient name : %s\n",i+1,pForm[i].name);
            printf("Gender : %s\n",pForm[i].gender);
            printf("Date Of Birth : %s\n",pForm[i].dateOfBirth);
            printf("Phone Number : %s\n",pForm[i].phoneNumber);
            printf("Guardian name : %s\n",pForm[i].guardianName);
            printf("Guardian phone number : %s\n",pForm[i].guardianNumber);
            printf("Admission Fee : %d TK\n",pForm[i].admissionFee);
            printf("Signature : %s\n",pForm[i].signature);

        }
    }
}
//function for demo of admission form
void demoAdmissionForm()
{
    system("cls");
    printf("\n\t\t\tADMISSION FORM\n\n");
    printf("Patient name : Akbar\n");
    printf("Gender : Male\n");
    printf("Date Of Birth : 26/03/2000\n");
    printf("Phone number : 0172********45\n");
    printf("Guardian name : Jalaluddin\n");
    printf("Guardian phone number : 018*********56\n");
    printf("Admission Fee : 150 TK\n");
    printf("Signature : akbar\n");
}
//srtucture for payment
struct payment
{
    char name[40];
    char bankNo[20];
    char PIN[5];
    char date[20];
    char time[10];
    int totalAmount;
int depositeAmount;
int dueAmount;
};
struct payment payments[MAX_PATIENTS];
int numberOfPayment = 0;
//function for payment
void payment()
{
    system("cls");
    struct payment newpayment;
    int choice;
    if(numberOfPayment>=MAX_PATIENTS)
    {
        printf("\nSorry ! Maximum number of payment is reached!\n");
    }
    printf("\nEnter Patient name : ");
    scanf("%s",&newpayment.name);
     printf("Enter total amount : ");
    scanf("%d",&newpayment.totalAmount);
    printf("\nPayment opsition\n");
    printf("1.In person payment.\n");
    printf("2.payment through Bank.\n");
    printf("3.payment through Bkash.\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
    case 1:
        {
            printf("Enter deposite amount : ");
            scanf("%d",&newpayment.depositeAmount);
        }
        break;
    case 2:
        {
            printf("Enter the Account NO :  ");
            scanf("%s",&newpayment.bankNo);
            printf("Enter 4 Digit PIN NO :");
            scanf("%s",&newpayment.PIN);
             printf("Enter deposite amount : ");
            scanf("%d",&newpayment.depositeAmount);
        }
        break;
    case 3:
        {
            printf("Enter the Bkash NO :  ");
            scanf("%s",&newpayment.bankNo);
            printf("Enter 4 Digit PIN NO :");
            scanf("%s",&newpayment.PIN);
             printf("Enter deposite amount : ");
            scanf("%d",&newpayment.depositeAmount);

        }
    default:
        printf("\n\nInvalid choice.\n");
        break;
    }
    printf("Enter payment date :");
    scanf("%s",&newpayment.date);
    printf("Enter payment time : ");
    scanf("%s",&newpayment.time);
    payments[numberOfPayment]=newpayment;
    numberOfPayment++;
    printf("\nPayment is successful.\n");

}
//calculate function
int calculateDue(int total,int deposite)
{
    return total-deposite;
}
//function for money recript
void takeReceipt()
{
    system("cls");
    if(numberOfPayment==0)
    {
        printf("\nSorry! No one had not payed yet.\n");
    }
    else
    {
    int found=0;
    char patientName[40];
    printf("\nEnter the patient name for money receipt : ");
    scanf("%s",&patientName);
    for(int i=0;i<numberOfPayment;i++)
    {
        if(strcmp(patientName,payments[i].name)==0)
        {
            printf("\n\t\t\tMONEY RECEIPT\n");
            printf("Patient Name : %s\n",payments[i].name);
            printf("Total Amount : %d\n",payments[i].totalAmount);
            printf("Deposit Amount : %d\n",payments[i].depositeAmount);
            payments[i].dueAmount=calculateDue(payments[i].totalAmount,payments[i].depositeAmount);
            printf("Due Amount : %d\n",payments[i].dueAmount);
            if(payments[i].bankNo[0] == '\0')
                {
                printf("Payment method is inperson\n");

                }
                else
                {
                    printf("Account No : %s\n",payments[i].bankNo);
                }
                printf("Payment Date : %s\n",payments[i].date);
                printf("Payment time : %s\n\n",payments[i].time);
                found = 1;
                break;
                    }
    }
    if(found = 1)
    {
        printf("\nTake money Receipt.\n");
    }
    else
    {
        printf("\nNot found !!\n");
    }
}
}
//print all payment
void showPayment()
{
    system("cls");
     if(numberOfPayment==0)
    {
        printf("\nSorry! No one had not payed yet.\n");
    }
    else{
    printf("\n\t\t\tPAYMENT LIST:\n");
    for(int i=0;i<numberOfPayment;i++)
    {
            printf("%d.Patient Name : %s\n",i+1,payments[i].name);
            printf("Total Amount : %d\n",payments[i].totalAmount);
            printf("Deposit Amount : %d\n",payments[i].depositeAmount);
            payments[i].dueAmount=calculateDue(payments[i].totalAmount,payments[i].depositeAmount);
            printf("Due Amount : %d\n",payments[i].dueAmount);
            if(payments[i].bankNo[0] == '\0')
                {
                printf("Payment method is inperson\n");

                }
                else
                {
                    printf("Account No : %s\n",payments[i].bankNo);
                }
                printf("Payment Date : %s\n",payments[i].date);
                printf("Payment time : %s\n\n",payments[i].time);
                    }
    }
}
//function for demopayment
void demoPayment()
{
    system("cls");
    printf("\n\nPatient name : Amina\n");
    printf("Total Amount : 1000 TK\n");
    printf("Account Number:A/C1200987\n");
    printf("Deposit Amount :500 TK\n");
    printf("Due Amount : 500 TK\n");
    printf("Date of Payment : 12/08/2023\n");
    printf("Payment Time : 12:30 PM\n\n");
}
void cont_us()
{
    system("cls");
    printf("\nContact Us:\n");
    printf("Address: Kawlar Bazar,Airport, Dhaka \n");
    printf("Contact Number: 01XXXXXXXXXX\n");
    printf("Email: ssaclinicmanagement1@gmail.com\n");
}
void About_us(){
    //system("cls"); // Clear the screen
    printf("ABOUT US\n");
    printf("\nWelcome to our Clinic Management System!\n");
    printf("Our clinic aims to provide high-quality healthcare services to patients.\n");
    printf("We are dedicated to ensuring the well-being of our patients and delivering\n");
    printf("compassionate care with the utmost professionalism.\n\n");
    printf("For any inquiries or assistance, please contact:\n");
    printf("Email: clinic@example.com\n");
    printf("Phone: 123-456-7890\n\n");
    printf("Press any key to return to the main menu...");
    getchar(); // Wait for user input
}
void newsRoom() {
   // system("cls"); // Clear the screen
    printf("\n\n\t\t\t*////*NEWS ROOM*///*\n");
    printf("\nWelcome to the News Room!\n");
    printf("Stay updated with the latest news and announcements from our clinic.\n");
    printf("1. COVID-19 Vaccination Drive: Join us for our upcoming COVID-19 vaccination drive!\n");
    printf("   Date: August 15, 2023\n");
    printf("   Time: 9:00 AM - 5:00 PM\n\n");
    printf("2. New Specialist Doctor: We are excited to welcome Dr. Smith, a specialist in\n");
    printf("   cardiology, to our clinic's team.\n\n");
    printf("Press any key to return to the main menu...");
    getchar();
}

int main()
{
    dashBoard();
    head=NULL;
    int choice1,choice2,choice3,choice4,choice5,choice6;
    do{
            printf("\n\n\nThe survice we provided are :\n");
        printf("\n1.Patient Information.\n");
        printf("2.Appointment.\n");
        printf("3.Online Admission Form.\n");
        printf("4.Make a Payment.\n");
        printf("5.About Us.\n");
        printf("6.Contact Us.\n");
        printf("7.News Room.\n");
        printf("9.Exit.\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice1);
        system("cls");
        switch(choice1){
        case 1:

            do{
                    printf("\n11.Add patient information.\n");
            printf("12.Delete patient information.\n");
            printf("13.Update patient information.\n");
            printf("14.Read patient information.\n");
            printf("15.Print patient information.\n");
            printf("16.Go to main manu.\n");
            printf("Enter your choice : ");
            scanf("%d",&choice2);
        switch(choice2){
        case 11:
            addPatient();
            break;
        case 12:
            deletePatient();
            break;
        case 13:
            updatePatient();
            break;
        case 14:
            readPatient();
            break;
        case 15:
            printPatient();
            break;
        case 16:
            break;
        default:
            printf("\nInvalid choice for patient operation.\n");
            break;
        }

    }while(choice2 != 16);
            break;
        case 2:
            do
            {
                printf("\n1.Take Appointment.\n");
                printf("2.Show patient list.\n");
                printf("3.Go to main menu.\n");
                printf("Enter your choice : ");
                scanf("%d",&choice3);
                switch(choice3)
                {
                case 1:
                    patientAppointment(head);
                    break;
                case 2:
                    displayAppointment(head);
                    break;
                case 3:
                    break;
                default:
                    printf("Invalid choice!\n");
                }
            }while(choice3 != 3);
            break;
    case 3:
        do
        {
                        printf("\n1.Create Admission Form.\n");
                        printf("2.Delete Admission Form.\n");
                        printf("3.Update Admission Form.\n");
                        printf("4.Read Admission Form.\n");
                        printf("5.print Admission Form.\n");
                        printf("6.Demo Admission Form.\n");
                        printf("7.Go to main menu.\n");
                        printf("\n Enter your choice : ");
                        scanf("%d",&choice4);
                        switch(choice4)
                        {
                        case 1:
                            createAdmissionForm();
                            break;
                        case 2:
                            deleteAdmissionForm();
                            break;
                        case 3:
                            updateAdmissionForm();
                            break;
                        case 4:
                            readAdmissionForm();
                            break;
                        case 5:
                            printAdmissionForm();
                            break;
                        case 6:
                            demoAdmissionForm();
                            break;
                        case 7:
                            break;
                        default:
                            printf("Invalid choice .\n");
                            break;
                        }
        }while(choice4 != 7);
        break;
        case 4:
            do
            {
                printf("\n\n1.Make a payment.\n");
                printf("2.Take money receipt.\n");
                printf("3.Show all payment.\n");
                printf("4.Demo of a payment.\n");
                printf("5.go to main menu.\n\n");
                printf("Enter your choice : ");
                scanf("%d",&choice5);
                switch(choice5)
                {
                case 1:
                    payment();
                    break;
               case 2:
                    takeReceipt();
                    break;
                case 3:
                    showPayment();
                    break;
                case 4:
                    demoPayment();
                    break;
                case 5:
                    break;
                default:
                    printf("\nInvalid choice.\n");
                }
            }while(choice5 != 5);
            break;
               case 5:
                     About_us();
                    break;
               case 6:
                     cont_us();
                     break;
               case 7:
                    newsRoom();
                    break  ;
case 9:
    return 0;
default:
    printf("\nInvalid choicde.\n");
    break;
        }
    }while(1);
    return 0;
}
