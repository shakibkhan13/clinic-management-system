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

void addPatient()
{
    if(numberOfPatient>=MAX_PATIENTS)
    {
        printf("\nMaximum number of patient is reached!\n");
        return;
    }
    struct Patient newPatient;
    printf("\n\nEnter the name of patient : ");
    fgets(newPatient.name,sizeof(newPatient.name),stdin);
    newPatient.name[strcspn(newPatient.name,"\n")]='\0';
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
   fgets(newPatient.attendingDoctor,sizeof(newPatient.attendingDoctor),stdin);
   newPatient.attendingDoctor[strcspn(newPatient.attendingDoctor,"\n")]='\0';
    printf("Enter the disease name : ");
    scanf("%s",&newPatient.disease);
    patients[numberOfPatient]=newPatient;
    numberOfPatient++;
    printf("\nNew patient add successfully.\n");
}
//Function for delete patient
void deletePatient()
{
    if(numberOfPatient == 0)
    {
        printf("\nThere is no patient for delete.\n");
        return;
    }
    char deletePatient[40];
    printf("\n\nEnter the name of  Patient to delete : ");
    fgets(deletePatient,sizeof(deletePatient),stdin);
    deletePatient[strcspn(deletePatient,"\n")]='\0';
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
        printf("\nInformation of patient is deleted successfully.\n");
    }
    else
    {
        printf("\npatient is not found.\n");
    }
}
//Function for update patient information
void updatePatient()
{
    if(numberOfPatient == 0)
    {
        printf("\nThere is no patient to update his/her information.\n");
        return;
    }
    char updateToName[40];
    printf("\n\nEnter the name of patient to update : ");
    fgets(updateToName,sizeof(updateToName),stdin);
    updateToName[strcspn(updateToName,"\n")]='\0';
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
            fgets(patients[i].attendingDoctor,sizeof(patients[i].attendingDoctor),stdin);
            patients[i].attendingDoctor[strcspn(patients[i].attendingDoctor,"\n")]='\0';
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
    if(numberOfPatient == 0)
    {
        printf("\nThere is no patient to read information.\n");
        return;
    }
    char nameToRead[40];
    printf("\nEnter the name of patient to read info : ");
    fgets(nameToRead,sizeof(nameToRead),stdin);
    nameToRead[strcspn(nameToRead,"\n")]='\0';
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
void createAdmissionForm();
void deleteAdmissionForm();
void updateAdmissionForm();
void readAdmissionForm();
void demoAdmissionForm();
void printAdmissionForm();
//function to create online form
void createAdmissionForm()
{
    if(numberOfForm>=MAX_PATIENTS)
    {
        printf("Error !Maximum number of online Admission form is reached.\n");
        return;
    }
    struct admissionForm newpatient;
    printf("Enter the patient name : ");
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
    if(numberOfForm == 0)
    {
        printf("Sorry! There is no Admission Form to delete.\n");
        return;
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
    if(numberOfForm==0)
    {
        printf("\nSorry ! No Admission Form to Update.\n");
        return;
    }
    int found =0;
    char updatePatient[40];
    printf("\n\nEnter the patient name to update his/her Admission form : ");
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
    if(numberOfForm==0)
    {
        printf("sorry !There is no Admission form of any patient.\n ");
        return;
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
    if(numberOfForm==0)
    {
        printf("sorry !There is no Admission form to print.\n ");
        return;
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
    if(numberOfPayment==0)
    {
        printf("\nSorry! No one had not payed yet.\n");
        return;
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
     if(numberOfPayment==0)
    {
        printf("\nSorry! No one had not payed yet.\n");
        return;
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
    printf("\n\nPatient name : Amina\n");
    printf("Total Amount : 1000 TK\n");
    printf("Account Number:A/C1200987\n");
    printf("Deposit Amount :500 TK\n");
    printf("Due Amount : 500 TK\n");
    printf("Date of Payment : 12/08/2023\n");
    printf("Payment Time : 12:30 PM\n\n");
}
//structure for contact us
struct contact
{
    char hospitalName[40];
    char address[50];
    char postalAddress[50];
    char phoneNumber[20];
    char fax[30];
    char email[50];
};
struct contact contacts[1];
int numberOfContact=0;
//function for create contact
void createContact()
{
    if(numberOfContact>=1)
    {
        printf("\nSorrry !Maximum number of contact is reached.\n");
        return;
    }
    else{
    struct contact newContact;
    printf("\nEnter Hospital name : ");
    getchar();
    fgets(newContact.hospitalName,sizeof(newContact.hospitalName),stdin);
    newContact.hospitalName[strcspn(newContact.hospitalName,"\n")]='\0';
    printf("Enter Address : ");
    fgets(newContact.address,sizeof(newContact.address),stdin);
    newContact.address[strcspn(newContact.address,"\n")]='\0';
    printf("Enter postal Address : ");
    fgets(newContact.postalAddress,sizeof(newContact.postalAddress),stdin);
    newContact.postalAddress[strcspn(newContact.postalAddress,"\n")]='\0';
    printf("Enter phone number : ");
    scanf("%s",&newContact.phoneNumber);
    printf("Enter fax number:");
    scanf("%s",&newContact.fax);
    printf("Enter Email address :");
    scanf("%s",&newContact.email);
    contacts[numberOfContact]=newContact;
    numberOfContact++;
    printf("\nContact information is created successfully.\n");
    }
}
//function for delete contact
void deleteContact()
{
    int found=0;
    if(numberOfContact==0)
    {
        printf("\nSorry ! There is no contact information is available for delete.\n");
        return;
    }
    int index;
    printf("Enter index number to delete contact information (%d) : ",numberOfContact-1);
    scanf("%d",&index);
    if(index>=0 && index<numberOfContact)
    {
        for(int i=index;i<numberOfContact-1;i++)
        {
            contacts[i]=contacts[i+1];
        }
        numberOfContact--;
        found=1;
    }
    if(found==1)
    {
            printf("\nContact information is delete successfully.\n");

    }
    else
    {
        printf("\nNot found such contact information.\n");
    }
}
//function for read contact
void readContact()
{
    if(numberOfContact==0)
    {
        printf("\nThere is no contact to read.\n");
        return;
    }
    for(int i=0;i<numberOfContact;i++)
    {
        printf("\n\nSTREET ADDRESS\n\n");
        printf("%s\n",contacts[i].hospitalName);
        printf("Address :%s\n",contacts[i].address);
        printf("\nPOSTAL ADDRESS\n\n");
        printf("postal address : %s\n",contacts[i].postalAddress);
        printf("Phone Number :%s\n",contacts[i].phoneNumber);
        printf("Fax :%s\n",contacts[i].fax);
        printf("Email : %s\n",contacts[i].email);

    }
}
//function of demo contact
void demoContact()
{
    printf("\n\nSTREET ADDRESS\n\n");
    printf("Sydney and Sydney Eye Hospital.\n");
    printf("Address : 8 Macquaries st sydney,NSW 2000\n");
    printf("\n\nPOSTAL ADDRESS\n\n");
    printf("Postal address : GPO Box 1614\nSydney,NSW 2001\n");
    printf("Phone number :(02)93782 711\n");
    printf("Fax:(02)99382 7111\n");
    printf("Email:ssehehospitalservice@health.nsw.gov.au\n");
}
//structure for about us
struct aboutUs
{
    char hospitalName[50];
    char history[500];
    char community[500];
    char achievement[500];
};
struct aboutUs abouts[1];
int numberOfAboutUs=0;
//function of create adout us
void createAboutUs()
{
    if(numberOfAboutUs>=1)
    {
        printf("\nSorry!Maximum number of About us reached.\n");

    }
    else{
        struct aboutUs newAbout;
        printf("\nEnter hospital name : ");
        getchar();
        fgets(newAbout.hospitalName,sizeof(newAbout.hospitalName),stdin);
        newAbout.hospitalName[strcspn(newAbout.hospitalName,"\n")]='\0' ;
        printf("\nEnter information about hospital history : \n");
        fgets(newAbout.history,sizeof(newAbout.history),stdin);
        newAbout.history[strcspn(newAbout.history,"\n")]='\0' ;
        printf("\nEnter information about hospital community :\n");
        fgets(newAbout.community,sizeof(newAbout.community),stdin);
        newAbout.community[strcspn(newAbout.community,"\n")]='\0' ;
        printf("\nEnter information about hospital achievement :\n");
        fgets(newAbout.achievement,sizeof(newAbout.achievement),stdin);
        newAbout.achievement[strcspn(newAbout.achievement,"\n")]='\0' ;
        abouts[numberOfAboutUs]=newAbout;
        numberOfAboutUs++;
        printf("\nCreate about us successfully.\n");
    }
}
//function of delete about us
void deleteAboutUs()
{
    if(numberOfAboutUs==0)
    {
        printf("\n There is no information to delete.\n");
        return;
    }
    int index;
    int found=0;
    printf("Enter index %d ot delete information about us:",numberOfAboutUs-1);
    scanf("%d",&index);
    if(index>=0 && index<numberOfAboutUs)
    {
        for(int i=index;i<numberOfAboutUs-1;i++)
        {
            abouts[i]=abouts[i+1];
        }
        numberOfAboutUs--;
        found=1;
    }
    if(found==1)
    {
        printf("\nInformation delete about us successfully.\n");
    }
    else{
        printf("\nNot found such information.Invalid choice.\n");
    }
}
//function to read about us
void aboutUs()
{
    if(numberOfAboutUs==0)
    {
        printf("\nThere is no information About Us to read.\n");
        return;
    }
    for(int i=0;i<numberOfAboutUs;i++){
    printf("\n\n\t\t%s\n\n",abouts[i].hospitalName);
    printf("OUR HISTORY :\n%s\n\n",abouts[i].history);
    printf("OUR COMMUNITY :\n%s\n\n",abouts[i].community);
    printf("OUR ACHIEVEMENT :\n%s\n\n",abouts[i].achievement);
    }
}
//function for demo about us
void demoAboutUs()
{
    printf("\n\n\t\t Sydney and Sydney Eye Hospital\n");
    printf("\nOUR HISTORY :\n\n");
    printf("Sydney and Sydney eye Hospital is steeped in history,\n");
    printf("with a legacy of nursing and medical first to it .......\n");
    printf("\nOUR COMMUNITY :\n\n");
    printf("Annually there are more than 37000 attendances to\nto the hospital emergency department ....");
    printf("\n\nOUR ACHIEVEMENT :\n\n");
    printf("1.Surgery recovery plan success\n2.Saving of SESLHD\n3.Cost Efficient rostering....\n");
}
#define MAX_NEWS 100
struct news
{
    char title[50];
    char detail[300];
};
struct news newsroom[MAX_NEWS];
int numberOfNews=0;
void createNews()
{
    if(numberOfNews>=MAX_NEWS)
    {
        printf("\nSorry !News room is reached its maximum limit.\n");
        return;
    }
    struct news newNews;
    printf("\nEnter the title : ");
    getchar();
    fgets(newNews.title,sizeof(newNews.title),stdin);
    newNews.title[strcspn(newNews.title,"\n")]='\0';
    printf("\nDetails : \n");
    fgets(newNews.detail,sizeof(newNews.detail),stdin);
    newNews.detail[strcspn(newNews.detail,"\n")]='\0';
    newsroom[numberOfNews]=newNews;
    numberOfNews++;
    printf("\nNewsroom is created successfully.\n");

}
void deleteNews()
{
    if(numberOfNews==0)
    {
        printf("\nThere is no News to delete.\n");
        return;
    }
    char deleteTitle[50];
    int found=0;
    printf("Enter the title to delete news : ");
    getchar();
    fgets(deleteTitle,sizeof(deleteTitle),stdin);
    deleteTitle[strcspn(deleteTitle,"\n")]='\0';
    for(int i=0;i<numberOfNews;i++)
    {
        if(strcmp(deleteTitle,newsroom[i].title)==0)
        {
            for(int j=i;j<numberOfNews-1;j++)
            {
                newsroom[j]=newsroom[j+1];
            }
            numberOfNews--;
            found=1;
            break;
        }
    }
    if(found==1)
    {
        printf("News is deleted successfully.\n");
    }
    else
    {
        printf("Not found.\n");
    }
}
void newsRoom()
{
    if(numberOfNews==0)
    {
        printf("\nThere is no News to read.\n");
        return;
    }
    printf("\n\n\t\tWELCOME TO NEWSROOM\n\n");
    for(int i=0;i<numberOfNews;i++)
    {
        printf("%d.News Title :%s\n",i+1,newsroom[i].title);
        printf("DETAILS : \n%s\n",newsroom[i].detail);

    }
}
void demoNewsRoom()
{
    printf("\n\n\t\tWELCOME TO NEWS ROOM\n\n");
    printf("Dengue Fever News : \n");
    printf("Details:\nFor dengue patients Emergency Department are open 24/7.\n");
    printf("the symptoms of severa dengue are\n1.belly pain...\n");
}

int main()
{
    dashBoard();
    head=NULL;
    int choice1,choice2,choice3,choice4,choice5,choice6,choice7,choice8;
    do{
        printf("\n\n\nThe survice we provided are :\n");
        printf("\n1.Patient Information.\n");
        printf("2.Appointment.\n");
        printf("3.Online Admission Form.\n");
        printf("4.Make a Payment.\n");
        printf("5.Contact Us.\n");
        printf("6.About Us.\n");
        printf("7.News Room.\n");
        printf("9.Exit.\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice1);
        switch(choice1){
        case 1:

            do{
            printf("\n1.Add patient information.\n");
            printf("2.Delete patient information.\n");
            printf("3.Update patient information.\n");
            printf("4.Read patient information.\n");
            printf("5.Print patient information.\n");
            printf("6.Go to main manu.\n");
            printf("Enter your choice : ");
            scanf("%d",&choice2);
        switch(choice2){
        case 1:
            addPatient();
            break;
        case 2:
            deletePatient();
            break;
        case 3:
            updatePatient();
            break;
        case 4:
            readPatient();
            break;
        case 5:
            printPatient();
            break;
        case 6:
            break;
        default:
            printf("\nInvalid choice for patient operation.\n");
            break;
        }

    }while(choice2 != 6);
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
                    do
                    {
                        printf("\n1.Contact Us.\n");
                        printf("2.Create contact Information.\n");
                        printf("3.delete contact Information.\n");
                        printf("4.demo contact us.\n");
                        printf("5.go to main menu.\n\n");
                        printf("Enter your choice : ");
                        scanf("%d",&choice6);
                        switch(choice6)
                        {
                        case 1:
                            readContact();
                            break;
                        case 2:
                            createContact();
                            break;
                        case 3:
                            deleteContact();
                            break;
                        case 4:
                            demoContact();
                            break;
                        case 5:
                            break;
                        default:
                            printf("\nInvalid choice .\n");

                        }
                    }while(choice6 != 5);
                    break;
            case 6:
                do
                {
                    printf("\n1.About US.\n");
                    printf("2.create About us.\n");
                    printf("3.delete About Us.\n");
                    printf("4.demo About Us.\n");
                    printf("5.go to main menu.\n\n");
                    printf("Enter your choice : ");
                    scanf("%d",&choice7);
                    switch(choice7)
                    {
                        case 1:
                            aboutUs();
                            break;
                        case 2:
                            createAboutUs();
                            break;
                        case 3:
                            deleteAboutUs();
                            break;
                        case 4:
                            demoAboutUs();
                            break;
                        case 5:
                            break;
                        default:
                            printf("\nInvalid choice.\n");
                    }
                            }while(choice7 != 5);
                            break;
            case 7:
                do
                {
                   printf("\n1.News room.\n");
                    printf("2.create News.\n");
                   printf("3.delete News.\n");
                   printf("4.demo News room.\n");
                   printf("5.go to main menu.\n\n");
                   printf("Enter your choice : ");
                   scanf("%d",&choice8);
                   switch(choice8)
                   {
                   case 1:
                    newsRoom();
                    break;
                   case 2:
                    createNews();
                    break;
                   case 3:
                    deleteNews();
                    break;
                   case 4:
                    demoNewsRoom();
                    break;
                   case 5:
                    break;
                   default:
                    printf("\nInvalid choice.\n");
                   }
                   }while(choice8 != 5);
                 break;
case 9:
    return 0;
default:
    printf("\nInvalid choicde.\n");
    break;
        }
    }while(1);
    return 0;
}
