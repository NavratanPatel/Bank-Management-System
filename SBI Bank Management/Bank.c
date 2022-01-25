///////////////////////////////////////////////////////////////STARTING///////////////////////////////////////////////////////////////////////////////
////////////////////////Header Files/////////////////////////
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
/////////////////////////Macro Names/////////////////////////
#define SPACE 32    //space
#define BKSP 8     //back space
#define ENTER 13

//////////////////////////////////////Function Declarration///////////////////////////
void d_s(void);
void d_b(void);
void d_i(void);
void Loading(void);
void Soft_D(void);

void bank_p(void);
void bank_pl(void);
void bank_ps(void);
/////////////SIGNUP Functions Declaration
void signup_p1(void);
void signup_p2(void);
void signup_p3(void);
void signup_p4(void);
void Bybank(void);

void PAcc_no(void);
void PDc_no(void);
void P_Ifsc(void);
int dobonly(void);
void Panonly(char *,int);
void Up4only(char*,int);
void input_Uid(void);
void input_Upw(void);
void input_State(void);
void input_Em(void);
void input_Mno(void);
int input_Dob(void);
void input_Adno(void);
void input_Pno(void);

///////////////////////Task Fuctions
void file_w(void);
int integeronly(void);
void charonly(char*);
void char_Donly(char*,int);
void clr(int,int);
void delay(int);
void box1(int,int,int,int);
void box(int,int,int,int);
///////////////////////Saving Acc Functions
void USSA(void);
void AccPro(void);
void AcDc(void);
void AcBe(void);

void AcTcw(void);
void Ac_bc(void);
void Ac(void);

void Ad(void);
void Ac_bw(void);

void AcMud(void);
void AccCls(void);
void del(void);

void s(void);
//////////////////////Modification Function
void MN(void);
void MD(void);
void ME(void);
void MMn(void);
void MUn(void);
void MUp(void);
void MP(void);
//////////////////////Globle Variable Declaration/////////////////////////////////////////////
FILE *fp=NULL;
long int position;
int i,count,j,n;
int no,f=0,tn;
SYSTEMTIME t;
////////////////Globle Data Type Declaration//////////////////////////////////////////////////

//////////////////////Date
typedef struct
{
    int d;
    int m;
    int y;
}Date;

/////////////////////Statements
typedef  struct
{
    Date sd;
    int ai;
    float A;
    float Ds;
    float Cs;
}Stm;
//////////////////////////////////

/////////////Account User Info
typedef struct
{
    /////////////USER INFO Provided BY BANK////////////////
    char Acn[11],Dbt_n[16],Ifsc[11]; //Acc No,Debit No,IFSC Code
    int Evdm,Evdy,cvvn;          // Validity Date Month & Year,Cvv No
    //////////////////////////////

    float T_Amt;                                            ///Amount
    int Age,Ds,Ms,Ap;                                       ///Age,Debit Status ,Marriage Status & Ask Pan Card
    Date Dob,Dot;                                           ///Date Of Birth & Date Of Submition
    char Ahn[25],Fn[25],Mn[25],G[6];                        /// Account Holder ,Father,Mother Name & Gender
    char Cst[20],R[20],Em[30],Mno[11],S[25],Dst[25],Vtc[25];
    ///caste,religion,E-mail,mobile No,State,District & Village/Town/city

    char Adrs[50],Adno[17];                                 ///Address & Aadhar Num
    char Uid[13],Upw[20],Up[5];                             /// User ID & Password,User Pin
    char Bb[25],Na[25],Edu[50],Pro[30];                     ///Bank Branch , Nationlity,Education & Profession
    char Pno[15],Pin[6];                                    ///Pan NO ,Area PIN Code
    ////////////////
    Stm st[7];                       ///statements
    int reset;

}Acc_User;

//////////variables
Acc_User Au,AC[25];
int recsize=sizeof(Acc_User);
char C_un[13],C_pw[20];  ///globle Login Variables
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////*************///MAIN PROGRAMME OF BANK///************/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    system("cls");
    system("color b9");
    gotoxy(25,3);
    printf("\t   WEL-COME TO BANK OF");
    box1(1,90,2,27);
    d_s();
    d_b();
    d_i();
    Soft_D();
    Loading();
    //////////////
    bank_p();


    gotoxy(2,28);
    getch();
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////************Main Programme END**************////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////@@@**********///BANK PANNEL///**********@@@////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void bank_p()
{
    while(1)
    {
    int ch;
    system("cls");
    system("color b9");
    printf("\n\n\n\t\t\t\tSTATE BANK OF INDIA");
    printf("\n\n\t1.Login");
    printf("\n\t2.Register");
    printf("\n\t3.Exit");
    printf("\n\tEnter Your Choice : ");
    box1(1,90,2,27);
    gotoxy(29,7);
    box(29,45,7,9);
    gotoxy(31,8);
    ch=integeronly();
     switch(ch)
     {
      case 1:
          bank_pl();
          break;
      case 2:
          bank_ps();
          break;
      case 3:
          gotoxy(2,28);
          exit(0);
      default :
            {
             printf("\n\n\tInvalid Response");
             printf("\n\tPlease Try Again.....");
             box1(1,90,2,27);
             gotoxy(3,28);
             getch();
            }

      }
     }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////****Bank Pannel END****////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////*******///BANK SIGN-UP PANNEL///********/////P.No. 167-/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void bank_ps()
{
    signup_p1();
    signup_p2();
    signup_p3();
    signup_p4();
    bank_p();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////****BANK SIGNUP PANNEL E-N-D****///////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////@@@*****///BANK LOGIN PANNEL///****@@@//////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void bank_pl()
{
    //////////////Variable//////////////////////////
    FILE *fp;
    int a,no_u,no_p;
    //////////////////////////////////
    system("cls");
    system("color b9");
    printf("\n\n\n\t\t\t\t-: SBI BANK LOGIN PANNEL :-");
    printf("\n\n\tUsername*           : ");
    box1(1,90,2,28);
    gotoxy(30,4);
    box(30,60,4,6);
    gotoxy(31,5);
    fflush(stdin);
    gets(C_un);
    printf("\n\n\tPassword*           : ");
    box1(1,90,2,28);
    gotoxy(30,7);
    box(30,60,7,9);
    gotoxy(31,8);

   //////////////////////////////////////////////////////////////////////////////
   i=0;
    do
    {
        a=getch();
        if(a==BKSP&&i>0)
        {
                i--;
                printf("\b");
                printf(" ");
                printf("\b");
        }

        if(a!=SPACE&&a!=ENTER&&a!=BKSP)
        {
            printf("%c",'*');
            C_pw[i]=a;
            i++;
        }
        if(a==ENTER&&i>0)
        {
            C_pw[i]='\0';
            break;
        }

    }while(1);
   //////////////////////////////////////////////////////////////////

   /////////////////////////FILE OPENING///////////////////////////
   fp=fopen("Acuser.dat","rb");

   if(fp==NULL)
   {
       printf("\n\n\tFile Cannot Opened");
       box1(1,90,2,28);
       getch();
       bank_p();
   }

   no=0;
   while(fread(&Au,sizeof(Au),1,fp)==1)
   {
      AC[no]=Au;
      no++;
   }
   tn=no;
   fclose(fp);
  ///////////////////////Matching For Security//////////////////////////////////////
   for(i=0;i<no;i++)
   {
       if(strcmp(C_un,AC[i].Uid)==0)
       {
         f=i;
         no_u=1;
         break;
       }
       else
           no_u=0;

   }

   for(i=0;i<no;i++)
   {
       if(strcmp(C_pw,AC[i].Upw)==0)
       {
           no_p=1;
           break;
       }
       else
           no_p=0;
   }

 ////////////////////////////////////////Message To Acc User ////////////////////////////////////////////
 if(no_u==1&&no_p==1)
      {
       printf("\n\n\n\tLogin Successfully........\n");
       box1(1,90,2,28);
       getch();
       USSA();

      }
    else if(no_p==0&&no_u==1)
        {
         printf("\n\n\tERROR : Invalid Password ");
         printf("\n\tPlease Try Again To Login........\n");
         box1(1,90,2,28);
         getch();
         bank_p();
       }
    else if(no_u==0&&no_p==1)
       {
         printf("\n\n\tERROR : Invalid User ID ");
         printf("\n\tPlease Try Again To Login........\n");
         box1(1,90,2,28);
         getch();
         bank_p();
       }
    else if(no_u==0&&no_p==0)
        {
         printf("\n\n\tERROR : Invalid User ID & Password ");
         printf("\n\tPlease Try Again To Login........\n");
         box1(1,90,2,28);
         getch();
         bank_p();
       }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////****BANK LOGIN PANNEL END****///////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////****TASK FUNCTIONS****///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////***GOTOXY()***///////////////////////////////////////////////////////////////////////////
void gotoxy(int x,int y)
{
    COORD t;
    t.X=x;
    t.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),t);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void clr(int count,int k)
{
    for(i=count;i>k&&count>k;i--)
     {
        printf("\b");
        printf(" ");
        printf("\b");
        count--;
     }

}
///////////////////////////////////////INPUT CHARACTER ONLY ////////////////////////////////////////////////////////////////////////
void charonly(char *charp)
{
 int a;
 i=0;
do
{
    a=getch();
    if(a>=65&&a<=90||a>=97&&a<=122||(a==SPACE&&i>0))
    {
     i++;
     printf("%c",a);
     *charp=a;
     charp++;
    }
    if(a==ENTER&&i>0)
    {
      *charp='\0';
      break;
    }

    if(a==BKSP&&i>0)
    {
        printf("\b");
        printf(" ");
        printf("\b");
        i--;
        charp--;
    }
 }while(1);
}


///////////////////////////////////////////////////CHARACTER ONLY END ////////////////////////////////////////////////////////////////

///////////////////////////////////////INPUT INTEGER ONLY ////////////////////////////////////////////////////////////////////////
int integeronly()
{
 int a,num=0;
 n=0;
do
{
    a=getch();
    if(a>=48&&a<=57)
    {
     printf("%c",a);
     num=num*10+(a-48);
     n++;
    }
    if(a==ENTER&&n>0)
        break;
    if(a==BKSP&&n>0)
    {
        printf("\b");
        printf(" ");
        printf("\b");
        num=num/10;
        n--;
    }
}while(1);
return(num);
}


///////////////////////////////////////////////////INTEGER ONLY END ////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////INPUT PAN NO ONLY //////////////////////////////////////////////////////////////
void Panonly(char *charp, int l)
{
 int a;
 i=0;
 do
 {
    a=getch();
    if(a>=48&&a<=57||a>=65&&a<=90)
    {
     i++;
     printf("%c",a);
     *charp=a;
     charp++;
    }
    if(a==ENTER&&i>=l)
    {
      *charp='\0';
      break;
    }

    if(a==BKSP&&i>0)
    {
        printf("\b");
        printf(" ");
        printf("\b");
        i--;
        charp--;
    }
 }while(1);

}
/////////////////////////////////////////////////Pan NO Only/////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////INPUT DOB INTEGER ONLY//////////////////////////////////////////////////////////////////////
int dobonly()
{
 int a,num=0;
 n=0;
do
{
    a=getch();
    if(a>=48&&a<=57)
    {
     printf("%c",a);
     num=num*10+(a-48);
     n++;
    }

    if(a==47&&n>0){
        printf("%c",a);
       return(num);
    }
    if(a==ENTER&&n>0)
       break;
    if(a==BKSP&&n>0)
    {
        printf("\b");
        printf(" ");
        printf("\b");
        num=num/10;
        n--;
    }
}while(1);
return(num);
}
////////////////////////////////////////////END D0B INTEGER ONLY////////////////////////////////////////////////////////////////////

///////////////////////////////////////INPUT CHAR IN DIGITS ONLY ////////////////////////////////////////////////////////////////////////
void char_Donly(char *charp,int l)
{
 int a;
 i=0;
do
{
    a=getch();
    if(a>=48&&a<=57)
    {
     i++;
     printf("%c",a);
     *charp=a;
     charp++;
    }
    if(a==ENTER&&i>=l)
    {
      *charp='\0';
      break;
    }

    if(a==BKSP&&i>0)
    {
        printf("\b");
        printf(" ");
        printf("\b");
        i--;
        charp--;
    }
 }while(1);

}


///////////////////////////////////////////////////CHAR IN DIGITS ONLY END /////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////*** DELAY()***///////////////////////////////////////////////////////////////////////////////
void delay(int a)
{
    int add=1;
    int time;
    int i;
    time=a*1000000;
    for(i=0;i<time;i++)
    {
        add*=i;
        add++;
        add++;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////Software Developed BY...//////////////////////////////////////////////////////////////////
void Soft_D()
{
   gotoxy(65,16);
   printf("~ DEVELOPED BY:");
   gotoxy(65,17);
   printf("  NAVRATAN PATEL");
}

///////////////////////////////////////////////////////////Loading............./////////////////////////////////////////////////////////////
void Loading()
{
    gotoxy(34,20);
    printf("LOADING ");
    j=0;
    for(i=0;i<=8;i++)
    {
        printf("%c",175);
        //box1(2,160,2,41);
        delay(80);
        if(i==6)
        {
          for(;i>1;i--){
                if(j==1)
                break;
          printf("\b");
          printf(" ");
          printf("\b");
          delay(50);
          count=1;
          }
        }
        else if(count==1&&i==5)
           {
              j=1;
              break;
           }
    }
    gotoxy(2,28);
}
/////////////////////////////////////////////////////////***CHARACTER (S)BI***///////////////////////////////////////////////////////////////////////
void d_s(void)
{
    int i=0,j=1;
    gotoxy(37,4);
    for(i=1;i<=4;i++)
    {
      printf("%c",220);
    }

    for(i=1;i<=3;i++)
    {

      gotoxy(37,4+j);
      printf("%c",221);
      j++;
    }

    gotoxy(37,8);
    for(i=1;i<=4;i++)
    {
      printf("%c",223);
    }

    j=1;

    for(i=1;i<=4;i++)
    {

      gotoxy(40,7+j);
      printf("%c",221);
      j++;
    }
    gotoxy(37,11);
    for(i=1;i<4;i++)
    {
      printf("%c",220);
    }

}


//////////////////////////////////////////////////////////*** CHARACTER S(B)I***////////////////////////////////////////////////////////////////////
void d_b(void)
{
    int i=0,j=1;
    gotoxy(44,4);
    for(i=1;i<=4;i++)
    {
      printf("%c",220);
    }

    for(i=1;i<=3;i++)
    {

      gotoxy(44,4+j);
      printf("%c",221);
      j++;
    }

     gotoxy(44,8);
    for(i=1;i<=4;i++)
    {
      printf("%c",223);
    }

    j=1;
    for(i=1;i<=3;i++)
    {

      gotoxy(47,4+j);
      printf("%c",222);
      j++;
    }

    j=1;
    for(i=1;i<=4;i++)
    {
      gotoxy(44,7+j);
      printf("%c",221);
      j++;
    }
     gotoxy(44,11);
    for(i=1;i<=4;i++)
    {
      printf("%c",223);

    }
    j=1;
    for(i=1;i<4;i++)
    {
      gotoxy(47,7+j);
      printf("%c",222);
      j++;
    }


}
///////////////////////////////////////////////***CHARACTER SB(I)***///////////////////////////////////////////////////////////////////////////////
void d_i(void)
{
    int i=0,j=0;

    for(i=1;i<=4;i++)
    {
        gotoxy(50+j,4);
        printf("%c",220);
        j++;
    }
    j=1;
    for(i=1;i<8;i++)
    {
      gotoxy(51,4+j);
      printf("%c",222);
      j++;
    }

    j=1;
    for(i=1;i<=4;i++)
    {
        gotoxy(49+j,11);
        printf("%c",223);
        j++;
    }
}

//////////////////////////////////////////***Double BOX Design***///////////////////////////////////////////////////////////////////////////////
void box1(int left,int right,int top,int bottom)
{
int i;


//_setcursortype(0);
gotoxy(left,top);
printf("%c",201);
for(i=0;i<right-left;i++)
{
 printf("%c",205);
}
printf("%c",187);


for(i=1;i<bottom-top;i++)
{
gotoxy(right+1,top+i);
printf("%c",186);

}
for(i=1;i<bottom-top;i++)
    {
gotoxy(left,top+i);
printf("%c",186);
}
gotoxy(left,bottom);
printf("%c",200);
for(i=0;i<=right-left;i++)
{
 printf("%c",205);
}
gotoxy(right+1,bottom);
printf("%c",188);

}

/////////////////////////////////////////////***SINGLE LINE BOX DESIGN***/////////////////////////////////////////////////////////////
void box(int left,int right,int top,int bottom)
{
int i;


//_setcursortype(0);
gotoxy(left,top);
printf("%c",218);
for(i=0;i<right-left;i++)
{
 printf("%c",196);
}
printf("%c",191);


for(i=1;i<bottom-top;i++)
{
gotoxy(right+1,top+i);
printf("%c",179);
}
for(i=1;i<bottom-top;i++)
{
gotoxy(left,top+i);
printf("%c",179);
}
gotoxy(left,bottom);
printf("%c",192);
for(i=0;i<right-left;i++)
{
 printf("%c",196);
}
gotoxy(right+1,bottom);
printf("%c",217);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////****TASK FUNCTIONS END***//////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////************************SIGN-UP FUNCTIONS***********************///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////INPUT USER ID/////////////////////////////////////////////////////////////////////////////////////
void input_Uid()
{
    //////USER ID Variables
    int uA=0,ua=0,un=0,uc=0;

    printf("\n\t[(6-12 char) A-Z | a-z |0-9 ]");
    printf("\n\n\tCreate Username     : ");
    box1(1,90,2,28);
    gotoxy(30,5);
    box(30,55,5,7);
    gotoxy(31,6);
    fflush(stdin);
    gets(Au.Uid);
    ///////////////////////////////////////////////////
    n=0;
    n=strlen(Au.Uid);

    if(n>=6&&n<=12)
    {
        for(i=0;Au.Uid[i];i++)
        {
           if(Au.Uid[i]>='A'&&Au.Uid[i]<='Z')
               uA++;
           else if(Au.Uid[i]>='a'&&Au.Uid[i]<='z')
               ua++;
           else if(Au.Uid[i]>=48&&Au.Uid[i]<=57)
                un++;
        }
        if(uA>0&&ua>0&&un>0)
            uc=uA+ua+un;

        if(uc==n)
           ;
        else
        {
          printf("\n\n\tInvalid : User ID ");
          printf("\n\tPlease Follow Above Rules To Create Again.....");
          box1(1,90,2,28);
          getch();
          bank_p();
        }
    }
    else
    {
        printf("\n\n\tInvalid User ID: Enter Minimum 6 & Max. 12 Characters");
        printf("\n\tTry Again To Sign-Up.......\n");
        box1(1,90,2,28);
        getch();
        bank_p();
    }


}
/////////////////////////////////////////////////////////////END USER ID CODE////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////INPUT USER PASSWORD ////////////////////////////////////////////////////////////////////////////////
void input_Upw()
{
    ///////USER Password Variables
    int pp;
    char cp[20],acp[20];
    int pwA=0,pwa=0,pwn=0,pws=0,pwc=0;

    printf("\n\t[(8-16 char) A-Z | a-z | 0-9 With special Symbol]");
    printf("\n\n\tCreate Password     : ");
    box1(1,90,2,28);
    gotoxy(30,9);
    box(30,55,9,11);
    gotoxy(31,10);
   /////////////////////////////////////

    i=0;
    do
    {
        pp=getch();
        if(pp==BKSP&&i>0)
        {
                i--;
                printf("\b");
                printf(" ");
                printf("\b");
        }

        if(pp!=SPACE&&pp!=ENTER&&pp!=BKSP)
        {
            printf("%c",'*');
            cp[i]=pp;
            i++;
        }
        if(pp==ENTER&&i>0)
        {
            cp[i]='\0';
            break;
        }

    }while(1);

  ///////////////////////////////////////
    printf("\n\n\n\tConfirm Password    : ");
    box1(1,90,2,28);
    gotoxy(30,12);
    box(30,55,12,14);
    gotoxy(31,13);


    i=0;
    do
    {
        pp=getch();
        if(pp==BKSP&&i>0)
        {
                i--;
                printf("\b");
                printf(" ");
                printf("\b");
        }

        if(pp!=SPACE&&pp!=ENTER&&pp!=BKSP)
        {
            printf("%c",'*');
            acp[i]=pp;
            i++;
        }
        if(pp==ENTER&&i>0)
        {
            acp[i]='\0';
            break;
        }

    }while(1);
////////////////////////////////////

//////////////////////////Password Security////////////////////
    n=0;
    if(strcmp(cp,acp)==0)
    {

     strcpy(Au.Upw,acp);
     n=strlen(Au.Upw);
      if(n>=8&&n<=16)
        {
          for(i=0;i<n;i++)
           {

            if(Au.Upw[i]>='A'&&Au.Upw[i]<='Z')
                pwA++;
            else if(Au.Upw[i]>='a'&&Au.Upw[i]<='z')
                pwa++;
            else if(Au.Upw[i]>=48&&Au.Upw[i]<=57)
                pwn++;
            else if(Au.Upw[i]>=0&&Au.Upw[i]<=47)
                pws++;
            else if(Au.Upw[i]>=58&&Au.Upw[i]<=64)
                pws++;
            else if(Au.Upw[i]>=91&&Au.Upw[i]<=96)
                pws++;
            else if(Au.Upw[i]>=123&&Au.Upw[i]<=127)
                pws++;
           }
           if(pwa>0&&pwn>0&&pwA>0&&pws>0)
            pwc=(pwa+pwA+pwn+pws);

           if(pwc==n)
            {
              ;
            }
            else
            {
             printf("\n\n\tInvalid : Password");
             printf("\n\tPlease Follow Above Rule To Try Again.......\n");
             box1(1,90,2,28);
             getch();
             bank_p();
            }
          }
        else
         {
           printf("\n\n\tInvalid : Enter Minimum 8 & Max. 16 character");
           printf("\n\tTry Again To Sign-Up.....");
           box1(1,90,2,28);
           getch();
           bank_p();
         }

    }
    else
    {
        printf("\n\n\tInvalid : Confirm Password don't Match");
        printf("\n\tTry Again To Sign-Up.....");
        box1(1,90,2,28);
        getch();
        bank_p();
    }

}

////////////////////////////////////////USER PASSWORD CODE END//////////////////////////////////////////////////////////////////

///////////////////////////////////////INPUT 4 DIGITS User PIN ONLY ////////////////////////////////////////////////////////////////////////
void Up4only(char *charp,int l)
{
 int a;
 i=0;
do
{
    a=getch();
    if(a>=48&&a<=57)
    {
     i++;
     printf("%c",'*');
     *charp=a;
     charp++;
    }
    if(a==ENTER&&i>=l)
    {
      *charp='\0';
      break;
    }

    if(a==BKSP&&i>0)
    {
        printf("\b");
        printf(" ");
        printf("\b");
        i--;
        charp--;
    }
 }while(1);

}
///////////////////////////////////////////////////END 4 DIGIT PIN///////////////////////////////////////////////////////////////

///////////////////////////////////////////FILE WRITING/////////////////////////////////////////////////////////////////////////////
void file_w()
{
         fp=fopen("Acuser.dat","ab");
         if(fp==NULL)
         {

             printf("\n\n\tFile Cannot Opened");
             box1(1,90,2,28);
             getch();
             bank_p();
         }
         fwrite(&Au,sizeof(Au),1,fp);
         fclose(fp);

         printf("\n\n\tYour Account Opened Successfully.......");
         box1(1,90,2,28);
         getch();

}
//////////////////////////////////////////////////////////***FILE WRITTING END***/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////***INPUT STATE****//////////////////////////////////////////////////////////////////////
void input_State()
{
    ////////variables///////////
    char *Nts[]={"ANDHRA PRADESH","ARUNACHAL PRADESH","ASSAM","BIHAR",
                  "CHHATTISGARH","GOA","GUJARAT","HARYANA","HIMACHAL PRADESH",
                  "JAMMU AND KASHMIR","JHARKHAND","KARNATAKA","KERALA","MADHYA PRADESH",
                  "MAHARASHTRA","MANIPUR","MEGHALAYA","MIZORAM","NAGALAND","ODISHA","PUNJAB",
                  "RAJASTHAN","SIKKIM","TAMIL NADU","TELANGANA","TRIPURA","UTTAR PRADESH","UTTARAKHAND","WEST BENGAL"
                 };

    char *Nsn[]={ "ANDHRAPRADESH","ARUNACHALPRADESH","HIMACHALPRADESH",
                 "JAMMU KASHMIR","JAMMUKASHMIR","MADHYAPRADESH","TAMILNADU",
                 "UTTARPRADESH","WESTBENGAL"
                 };
    ////////////////////////////
    printf("\n\n\n\tState               : ");
    box1(1,90,2,28);
    gotoxy(30,10);
    box(30,55,10,12);
    gotoxy(31,11);
    charonly(&Au.S);
    /////////////////////////
     strupr(Au.S);
     count=0;
     n=0;
    for(i=0;i<29;i++)
    {
     if(strcmp(Au.S,Nts[i])==0)
     {
         count++;
         break;

     }
     if(i<9)
    {
      if(strcmp(Au.S,Nsn[i])==0)
      {
        n++;
        break;
      }
      else
      {
        n=0;
        count=0;
      }
     }

    }

   if(n==1&&count==0||n==0&&count==1)
    {
        ;
    }
    else if(n==0&&count==0)
    {
        printf("\n\n\tInvalid : It Isn't A State In INDIA");
        printf("\n\tPlease Try Again.....");
        box1(1,90,2,28);
        getch();
        bank_p();
    }


}
////////////////////////////////////////////**Input State END**/////////////////////////////////////////////////////////////


////////////////////////////////////////////***INPUT E-MAIL ID***///////////////////////////////////////////////////////////
void input_Em(void)
{
    //////E-Mail ID Variables
    int l,ea=0,en=0,et=0;
    char ch_em[11]="@gmail.com";
    char n_em[20],alno[20];

    ////////////////////////////////////
    printf("\n\n\tE-Mail ID           : ");
    box1(1,90,2,28);
    gotoxy(30,4);
    box(30,60,4,6);
    gotoxy(31,5);
    fflush(stdin);
    gets(Au.Em);
    //////////////////////////////
    count=0;
    l=0;
    for(i=0;Au.Em[i];i++)
    {

         if(Au.Em[i]==ch_em[l])
            {
              n_em[l]=Au.Em[i];
              l++;
            }
        else if(l>0)
            {
            n_em[l]=Au.Em[i];
            l++;
            }


        if(l==0)
        {
            alno[i]=Au.Em[i];
            if(Au.Em[i]>='A'&&Au.Em[i]<='Z'||Au.Em[i]>='a'&&Au.Em[i]<='z')
               ea++;
           else if(Au.Em[i]>=48&&Au.Em[i]<=57)
                en++;
        }
        else if(l==1)
        {
         alno[i]='\0';
        }

    }
    n_em[l]='\0';


        if(ea>0&&en>0)
            et=ea+en;

        if(strlen(alno)==et)
            ;
        else
            {
             printf("\n\tPlease Enter Your Alphanumerical Name");
             printf("\n\tTry Again.....\n");
              box1(1,90,2,28);
             getch();
             bank_p();
            }

    if(strcmp(n_em,ch_em)==0&&strlen(Au.Em)>=12&&l==10)
        ;
    else
        {
        printf("\n\tYou Have Entered Invalid E-Mail ID......");
        printf("\n\tTry Again.....\n");
         box1(1,90,2,28);
        getch();
        bank_p();
        }

}
//////////////////////////////////////////////////***Input E-Mail END***/////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////***INPUT MOBILE NO***/////////////////////////////////////////////////////////////////////////////////
void input_Mno()
{
    /////////////variables////////

    printf("\n\n\tMobile Number       : ");
    box1(1,90,2,28);
    gotoxy(30,7);
    box(30,55,7,9);
    gotoxy(31,8);
    char_Donly(&Au.Mno,10);
    //////////////////////////////
     if(strlen(Au.Mno)==10)
        {
            if(Au.Mno[0]==48)
            {
             printf("\n\n\tInvalid Mobile Number");
             printf("\n\tTry Again To Sign Up.....");
             box1(1,90,2,28);
             getch();
             bank_p();
            }

        }
    else
    {
     printf("\n\n\tInvalid Mobile Number");
     printf("\n\tTry Again To Sign Up.....");
     box1(1,90,2,28);
     getch();
     bank_p();
    }
}
//////////////////////////////////////////////////////Input Mobile No END////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////****INPUT DATE OF BIRTH******/////////////////////////////////////////////////////////////////////////
int input_Dob()
{
    ///////Date Of Birth Variables
    int da;
    int m[13]={31,28,31,30,31,30,31,31,30,31,30,31};
    int t_m;    //total months
    int t_y;  //total Years
    int t_d;// total days
    //////////////////////////////////
    printf("\n\n\n\tDate Of Birth[d/m/y]: ");
    box1(1,90,2,28);
    gotoxy(30,16);
    box(30,55,16,18);
    gotoxy(31,17);
    fflush(stdin);
    Au.Dob.d=dobonly();
    Au.Dob.m=dobonly();
    Au.Dob.y=dobonly();

    /////////////AGE Calculation ////////
    if(Au.Dob.d>0&&Au.Dob.d<=31&&Au.Dob.m>0&&Au.Dob.m<=12&&Au.Dob.y>=1936)
        ;
    else{
        printf("\n\n\tInvaild Date\n\tPlease Try Again.......");
        box1(1,90,2,28);
        getch();
        bank_p();
        }

    GetSystemTime(&t);
    count=0;
     if(t.wDay<Au.Dob.d)
        {
         t_d=(m[t.wMonth]+t.wDay)-Au.Dob.d;
          count++;
        }
     else
         t_d=(t.wDay-Au.Dob.d);

     if(count==1)
      {
         t_m=t.wMonth-1;

          if(t_m<Au.Dob.m){
           t_m=(t_m+12)-Au.Dob.m;
            count=0;
            count++;
            }
            else
             t_m=t_m-Au.Dob.m;

      }
      else
     {
         if(t.wMonth<Au.Dob.m){
           t_m=(t.wMonth+12)-Au.Dob.m;
            count=0;
            count++;
          }
            else
             t_m=t.wMonth-Au.Dob.m;
     }

     if(count==1)
       {
           t_y=t.wYear-1;
           t_y=t_y-Au.Dob.y;

       }
       else
       {
           t_y=t.wYear-Au.Dob.y;
       }
       ////AGE Calculation End/////////

  /////////////////////////////////////////
     if(t_y>=18)
        ;
    else
    {
     printf("\n\n\tYou Are Not 18 Year Old");
     printf("\n\tTry Again To Sign-Up.....");
     box1(1,90,2,28);
     getch();
     bank_p();
    }
   return(t_y);
}
////////////////////////////////////////////////////////////DATE OF BIRTH END///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////***INPUT AADHAR NO***////////////////////////////////////////////////////////////////////////
void input_Adno()
{
    printf("\n\n\tAadhar Card No      : ");
    box1(1,90,2,28);
    gotoxy(30,25);
    box(30,55,25,27);
    gotoxy(31,26);
    char_Donly(&Au.Adno,12);
    ////////////////////////////////////////////
     if(Au.Adno[0]==48)
     {
        gotoxy(57,26);
        printf("\tInvalid : Aadhar No");
        gotoxy(57,27);
        printf("\tTry Again To Sign Up.....");
        box1(1,90,2,28);
        getch();
        bank_p();
     }

    if(strlen(Au.Adno)==12)
    {
      ;
    }
    else
    {
      gotoxy(57,26);
      printf("\tInvalid:12 Digits Allowed");
      gotoxy(57,27);
      printf("\tTry Again To Sign Up.....");
      box1(1,90,2,28);
      getch();
      bank_p();
    }
}
/////////////////////////////////////////////////////////////////////Aadhar No End///////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////***INPUT PAN NO***///////////////////////////////////////////////////////////////////////////////
void input_Pno()
{
    ////variables
    int cpd=0,cpA=0;
    printf("\n\n\n\tPan Number          : ");
    box1(1,90,2,28);
    gotoxy(30,19);
    box(30,55,19,21);
    gotoxy(31,20);
    Panonly(&Au.Pno,10);
   /////////////////////////////////////////
    if(Au.Pno[0]==48)
    {
        printf("\n\n\tInvalid : Pan No");
        printf("\tTry Again To Sign Up.....");
        box1(1,90,2,28);
        getch();
        bank_p();
    }

    if(strlen(Au.Pno)==10)
        ;
    else
     {
        printf("\n\n\tInvalid : 10 Digits Allowed");
        printf("\tTry Again To Sign Up.....");
        box1(1,90,2,28);
        getch();
        bank_p();
     }

}
//////////////////////////////////////////////////////////////PAN NO END//////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////***SIGN_UP PAGE 1***/////////////////////////////////////////////////////////////////
void signup_p1()
{
    //////variables
    int t_y;
    //////Gender Variables
    char Mg[5]="MALE",Fg[7]="FEMALE";

    system("cls");
    system("color b9");
    printf("\n\n\n\t\t\t\t-: SBI BANK SIGN-UP PANNEL :-");
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\tAccount Holder Name : ");
    box1(1,90,2,28);
    gotoxy(30,4);
    box(30,55,4,6);
    gotoxy(31,5);
    charonly(&Au.Ahn);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tFather/Husband Name : ");
    box1(1,90,2,28);
    gotoxy(30,7);
    box(30,55,7,9);
    gotoxy(31,8);
    charonly(&Au.Fn);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tMother Name         : ");
    box1(1,90,2,28);
    gotoxy(30,10);
    box(30,55,10,12);
    gotoxy(31,11);
    charonly(&Au.Mn);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tGender [Male/Female]: ");
    box1(1,90,2,28);
    gotoxy(30,13);
    box(30,55,13,15);
    gotoxy(31,14);
    charonly(&Au.G);
    /////////////////////////////////////////////////////////
    if(strlen(Au.G)>=4&strlen(Au.G)<=6)
        ;
    else
    {
        printf("\n\n\tInvaild Gender\n\tPlease Try Again.......");
        box1(1,90,2,28);
        getch();
        bank_p();
    }

    strupr(Au.G);
    if(strcmp(Au.G,Mg)==0||strcmp(Au.G,Fg)==0)
      ;
    else
    {
        printf("\n\n\tInvaild Gender\n\tPlease Try Again.......");
        box1(1,90,2,28);
        getch();
        bank_p();
    }

    ////////////////////////////////////////////////
    t_y=input_Dob();
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tAge                 : ");
    box1(1,90,2,28);
    gotoxy(30,19);
    box(30,55,19,21);
    gotoxy(31,20);

    Au.Age=integeronly();
    //////////////////////////////////////////
    if(Au.Age==t_y)
    {
       ;
    }
    else if(t_y!=Au.Age)
       {
        printf("\n\n\tInvalid : Age Don't Match To Date Of Birth");
        printf("\n\tTry Again To Sign-Up.....");
        box1(1,90,2,28);
        getch();
        bank_p();
       }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tCaste               : ");
    box1(1,90,2,28);
    gotoxy(30,22);
    box(30,55,22,24);
    gotoxy(31,23);
    charonly(&Au.Cst);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("\n\n\n\tReligion            : ");
    box1(1,90,2,28);
    gotoxy(30,25);
    box(30,55,25,27);
    gotoxy(31,26);
    charonly(&Au.R);

}
///////////////////////////////////////////SIGN UP PAGE 1 END////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////***SIGN_UP PAGE 2***/////////////////////////////////////////////////////////////////
void signup_p2()
{
    system("cls");
    system("color b9");
    printf("\n\n\n\t\t\t\t-: SBI BANK SIGN-UP PANNEL :-");
    /////////////////////////////////////////////////////////////
    input_Em();
    ////////////////////////////////////////////////////////////
    input_Mno();
    ///////////////////////////////////////////////////////////////
    input_State();

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tDistrict            : ");
     box1(1,90,2,28);
    gotoxy(30,13);
    box(30,55,13,15);
    gotoxy(31,14);
    charonly(&Au.Dst);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tVillage/Town/City   : ");
    box1(1,90,2,28);
    gotoxy(30,16);
    box(30,55,16,18);
    gotoxy(31,17);
    charonly(&Au.Vtc);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tPIN Code            : ");
    box1(1,90,2,28);
    gotoxy(30,19);
    box(30,55,19,21);
    gotoxy(31,20);
    char_Donly(&Au.Pin,6);
    ////////////////////////////////
    if(strlen(Au.Pin)==6)
        ;
    else
    {
      printf("\n\n\tInvalid PIN Code : 6 Digits Allowed Here");
      printf("\n\tTry Again To Sign Up.....");
      box1(1,90,2,28);
      getch();
      bank_p();
    }

   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tAddress             : ");
    box1(1,90,2,28);
    gotoxy(30,22);
    box(30,78,22,24);
    gotoxy(31,23);
    fflush(stdin);
    gets(Au.Adrs);
    ///////////////////////////////////////////////
    if(Au.Adrs[0]==BKSP||strlen(Au.Adrs)==0)
     {
      printf("\n\n\tInvalid Address : First Space Not Allowed Here");
      printf("\n\tTry Again To Sign Up.....");
      box1(1,90,2,28);
      getch();
      bank_p();
     }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    input_Adno();

}
///////////////////////////////////////////SIGN UP PAGE 2 END////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////***SIGN_UP PAGE 3***/////////////////////////////////////////////////////////////////
void signup_p3()
{
    //variables
    char ind[][10]={"INDIA","INDIAN"};

    system("cls");
    system("color b9");
    printf("\n\n\n\t\t\t\t-: SBI BANK SIGN-UP PANNEL :-");
    ///////////////////////
    input_Uid();
    ///////////////////////
    input_Upw();
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tBank Branch         : ");
    box1(1,90,2,28);
    gotoxy(30,15);
    box(30,55,15,17);
    gotoxy(31,16);
    charonly(&Au.Bb);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tDate Of Submition   : ");
    box1(1,90,2,28);
    gotoxy(30,18);
    box(30,55,18,20);
    gotoxy(31,19);

    Au.Dot.d=dobonly();
    Au.Dot.m=dobonly();
    Au.Dot.y=dobonly();

    GetSystemTime(&t);
    ///////////////////////////////////////////////////////////
    if((t.wDay==Au.Dot.d||t.wDay==Au.Dot.d-1)&&t.wMonth==Au.Dot.m&&t.wYear==Au.Dot.y)
    {
        ;
    }
    else
    {
      printf("\n\n\tInvalid : Date Of Today");
      printf("\n\tTry Again To Sign Up.....");
      box1(1,90,2,28);
      getch();
      bank_p();
    }
    ///////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tNationlity          : ");
    box1(1,90,2,28);
    gotoxy(30,21);
    box(30,55,21,23);
    gotoxy(31,22);
    charonly(&Au.Na);
    strupr(Au.Na);
    //////////////////////////////////////////////////////////////
    count=0;
    for(i=0;i<2;i++)
    {
      if(strcmp(Au.Na,ind[i])==0)
      {
        count=1;
        break;
      }
      else
        {
         count=0;
        }
    }
    if(count==1)
        ;
    else
        {
         printf("\n\n\tInvalid : Nationlity");
         printf("\n\tTry Again To Sign Up.....");
         box1(1,90,2,28);
         getch();
         bank_p();
        }
    ///////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tEducation           : ");
    box1(1,90,2,28);
    gotoxy(30,24);
    box(30,78,24,26);
    gotoxy(31,25);
    fflush(stdin);
    gets(Au.Edu);

    if(Au.Edu[0]==BKSP||strlen(Au.Edu)==0)
     {
      gotoxy(5,27);
      printf("\tInvalid:Space Not Allowed & Try Again To Sign Up.....");
      box1(1,90,2,28);
      getch();
      bank_p();
     }

}
///////////////////////////////////////////SIGN UP PAGE 3 END////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////SIGN_UP PAGE 4/////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////SIGN UP PAGE 4 END//////////////////////////////////////////////////////////////////////////////////////
void signup_p4()
{
    int Ss;
    long unsigned int Amt;
    system("cls");
    system("color b9");
    printf("\n\n\n\t\t\t\t-: SBI BANK SIGN-UP PANNEL :-");
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\tProfession          : ");
    box1(1,90,2,28);
    gotoxy(30,4);
    box(30,55,4,6);
    gotoxy(31,5);
    charonly(&Au.Pro);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tMarriage Status [Yes/No : 1/0] : ");
    box1(1,90,2,28);
    gotoxy(40,7);
    box(40,55,7,9);
    gotoxy(41,8);
    Au.Ms=integeronly();

    if(Au.Ms==1||Au.Ms==0)
     ;
   else
    {
      printf("\n\n\tInvalid Response : Follow Yes=1 & No=0");
      printf("\n\tTry Again To Sign Up.....");
      box1(1,90,2,28);
      getch();
      bank_p();
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tFisrt Deposit Amount [Min 1000]: ");
    box1(1,90,2,28);
    gotoxy(40,10);
    box(40,55,10,12);
    gotoxy(41,11);
    Amt=integeronly();
    Au.reset=1;
    //////////////////////
    if(Amt>=1000)
     Au.T_Amt=Amt;
   else
    {
      printf("\n\n\tInvalid Amount : Minimun First Deposit 1000 Rs.");
      printf("\n\tTry Again To Sign Up.....");
      box1(1,90,2,28);
      getch();
      bank_p();
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\tDo You Want Debit Card [Yes/No : 1/0] : ");
    box1(1,90,2,28);
    gotoxy(48,13);
    box(48,55,13,15);
    gotoxy(49,14);
    Au.Ds=integeronly();
    ////////////////////////////////////////////////////////////////////////
    if(Au.Ds==1||Au.Ds==0)
     ;
    else
    {
      printf("\n\n\tInvalid Response : Follow Yes=1 & No=0");
      printf("\n\tTry Again To Sign Up.....");
      box1(1,90,2,28);
      getch();
      bank_p();
    }

    if(Au.Ds==1)
    {
        ;
    }
    else if(Au.Ds==0)
    {
        Au.Ap=0;
        printf("\n\n\tDo You Agree To Open [SAVING ACCOUNT] If The Information Provided");
        printf("\n\tBy You Follows The TERMS & CONDITIONS Of STATE BANK OF INDIA.");
        printf("\n\n\n\t  SUBMIT");
        box1(1,90,2,28);
        gotoxy(7,19);
        box1(7,16,19,21);
        //////////////////////
        gotoxy(50,20);
        printf("[YES/NO : 1/0]");
        gotoxy(65,19);
        box1(65,75,19,21);
        gotoxy(67,20);
        Ss=integeronly();
      //////////////////////////////////
         if(Ss==1)
         {
            Bybank();
            file_w();
         }
         else if(Ss==0)
         {
            printf("\n\n\tYour SBI ACCOUNT Not OPENED Successfully................");
            printf("\n\n\tPlease Follow TERMS & CONDITION And Try Again To SIGNUP.");
            box1(1,90,2,28);
            getch();
         }

     }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     if(Au.Ds==1)
     {
         printf("\n\n\n\tDo You Have Pan Card [Yes/No : 1/0]   : ");
         box1(1,90,2,28);
         gotoxy(47,16);
         box(48,55,16,18);
         gotoxy(49,17);
         Au.Ap=integeronly();
        ///////////////////////////////////////////////////////////
         if(Au.Ap==1||Au.Ap==0)
          ;
         else
         {
          printf("\n\n\tInvalid Response : Follow Yes=1 & No=0");
          printf("\n\tTry Again To Sign Up.....");
          box1(1,90,2,28);
          getch();
          bank_p();
         }

      if(Au.Ap==1)
      {
        ////////////////////////////////////////
              input_Pno();
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         j=0;
         printf("\n\n\n\tGenerate New Pin    : ");
         box1(1,90,2,28);
         gotoxy(30,22);
         box(30,55,22,24);
         gotoxy(31,23);

         if(j==1)
         {
            labelP1:
            printf("\n\n\n\tGenerate New Pin    : ");
            box1(1,90,2,28);
            gotoxy(30,22);
            box(30,55,22,24);
            gotoxy(54,23);
            count=54;
            clr(54,31);
          }
         Up4only(&Au.Up,4);
         //////////////////////////////////////
         if(strlen(Au.Up)==4)
            ;
         else
         {
            printf("\n\n\tInvalid PIN : ONLY 4 DIGITS Allowed Here");
            printf("\n\tTry Again To Sign-Up.....");
            box1(1,90,2,28);
            getch();
            gotoxy(2,20);
             j=1;
            goto labelP1;
         }
        //////////////////////////////////////////NEXT PAGE///////////////////////////////////////////////////////////////////////////
         system("cls");
         system("color b9");
         printf("\n\n\n\t\t\t\t-: SBI BANK SIGN-UP PANNEL :-");
        //////////////////////////////////////////////////////
         printf("\n\n\tDo You Agree To Open [SAVING ACCOUNT] If The Information Provided");
         printf("\n\tBy You Follows The TERMS & CONDITIONS Of STATE BANK OF INDIA.");
         printf("\n\n\n\t  SUBMIT");
         box1(1,90,2,28);
         gotoxy(7,8);
         box1(7,16,8,10);
         //////////////////////
         gotoxy(50,9);
         printf("[YES/NO : 1/0]");
         gotoxy(65,8);
         box1(65,75,8,10);
         gotoxy(67,9);
         Ss=integeronly();
         ///////////////////////////FILE WRITTING//
         if(Ss==1)
         {
           Bybank();
           file_w();
         }
         else if(Ss==0)
         {
            printf("\n\n\tYour SBI ACCOUNT Not OPENED Successfully................");
            printf("\n\n\tPlease Follow TERMS & CONDITION And Try Again To SIGNUP.");
            box1(1,90,2,28);
            getch();
         }


       }

        else if(Au.Ap==0)
         {
            Au.Ds=0;
            printf("\n\n\tFor DEBIT CARD You Must Have PAN CARD....");
            printf("\n\n\tDo You Agree To Open [SAVING ACCOUNT] If The Information Provided");
            printf("\n\tBy You Follows The TERMS & CONDITIONS Of STATE BANK OF INDIA.");
            printf("\n\n\n\t  SUBMIT");
            box1(1,90,2,28);
            gotoxy(7,24);
            box1(7,16,24,26);
            ////////////////////
            gotoxy(50,25);
            printf("[YES/NO : 1/0]");
            gotoxy(65,24);
            box1(65,75,24,26);
            gotoxy(67,25);
            Ss=integeronly();
            /////////////////////////////FILE WRITTING///////////////////////////////////////////
            if(Ss==1)
            {
              Bybank();
             fp=fopen("Acuser.dat","ab");
             if(fp==NULL)
              {
                gotoxy(18,26);
                printf("\tFile Cannot Opened");
                box1(1,90,2,28);
                getch();
                bank_p();
              }
             fwrite(&Au,sizeof(Au),1,fp);
             fclose(fp);
             gotoxy(18,26);
             printf("\n\tYour Account Opened Successfully.......");
             box1(1,90,2,28);
             getch();
            }
            else if(Ss==0)
            {
              printf("\n\n\tACCOUNT Not OPENED Successfully...  Follow TERMS & CONDITION & Try Again To SIGNUP");
              box1(1,90,2,28);
              getch();
            }

        //////////////////
         }
       ////////////////////
      }

}
/////////////////////////////////////////ACC INFO PROVIDED BY BANK //////////////////////////////////////////////////////////////////////////////
void Bybank()
{
    GetSystemTime(&t);
    /////////////////////////////////////////
    Au.Evdm=t.wMonth;
    Au.Evdy=t.wYear+5;
    /////////////////////////////////////////////////////////////////////////////////////////////
    PAcc_no();
    /////////////////////////////////////////////////////////////////////////////////////////////////
    PDc_no();
    ////////////////////////////////////////////////////////////////////////////////////////////////
    Au.cvvn=rand()%1000;

    if(Au.cvvn<100)
      Au.cvvn=Au.cvvn+100;
    /////////////////////////////////////////////////////////////////////////////////////////////////
    P_Ifsc();

}
/////////////////////////////////////////END INFO BY BANK//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////Providing Account No///////////////////////////////////////////////////////
void PAcc_no()
{
    Au.Acn[0]='6';
    Au.Acn[1]='1';
    Au.Acn[2]='3';
    count=0;

    srand(time(NULL));
    for(i=3;i<11;i++)
    {
        count=rand()%10;
        count==1?Au.Acn[i]='1':i;
        count==2?Au.Acn[i]='2':i;
        count==3?Au.Acn[i]='3':i;
        count==4?Au.Acn[i]='4':i;
        count==5?Au.Acn[i]='5':i;

        count==6?Au.Acn[i]='6':i;
        count==7?Au.Acn[i]='7':i;
        count==8?Au.Acn[i]='8':i;
        count==9?Au.Acn[i]='9':i;
        count==0?Au.Acn[i]='0':i;

    }

    if(i==11)
    {
      Au.Acn[i]='\0';
    }
}
/////////////////////////////////////////////////// Pro. Acc No End///////////////////////////////////////////////////////////


//////////////////////////////////////////////////Providing Debit Card No///////////////////////////////////////////////////////
void PDc_no()
{
    Au.Dbt_n[0]='4';
    Au.Dbt_n[1]='6';
    Au.Dbt_n[2]='8';
    count=0;

    srand(time(NULL));
    for(i=3;i<16;i++)
    {
        count=rand()%10;
        count==1?Au.Dbt_n[i]='1':i;
        count==2?Au.Dbt_n[i]='2':i;
        count==3?Au.Dbt_n[i]='3':i;
        count==4?Au.Dbt_n[i]='4':i;
        count==5?Au.Dbt_n[i]='5':i;

        count==6?Au.Dbt_n[i]='6':i;
        count==7?Au.Dbt_n[i]='7':i;
        count==8?Au.Dbt_n[i]='8':i;
        count==9?Au.Dbt_n[i]='9':i;
        count==0?Au.Dbt_n[i]='0':i;

    }


    if(i==16)
    {
     Au.Dbt_n[i]='\0';

    }
}
///////////////////////////////////////////////////Pro. Debit Card No END///////////////////////////////////////////////////////

////////////////////////////////////////////////Providing IFSC CODE////////////////////////////////////////////////////////////
void P_Ifsc()
{
    Au.Ifsc[0]='S';
    Au.Ifsc[1]='B';
    Au.Ifsc[2]='I';
    Au.Ifsc[3]='N';
    Au.Ifsc[4]='0';
    ///////////////////////
    n=0;
    for(i=5;i<11;i++)
    {
        Au.Ifsc[i]=Au.Pin[n];
        n++;
    }
    if(i==11)
    {
     Au.Ifsc[i]='\0';
    }
}
/////////////////////////////////////////////////END Pro. IFSC Code///////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////USER SAVING SBI ACCOUNT//////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void USSA()
{

    while(1)
    {
    int ch;
    system("cls");
    system("color e0");
    printf("\n\n\n\t\t\t\t   %c SBI Saving ACCOUNT %c",254,254);
    printf("\n\n\t\t%c Online SBI Mbanking :\n",177);
    printf("\n\t\t1.Account Profile");
    printf("\n\t\t2.Debit Card");
    printf("\n\t\t3.Balance Enquiry");
    printf("\n\t\t4.Transction");
    printf("\n\t\t5.Modify Details");
    printf("\n\t\t6.Account Closure");
    printf("\n\t\t7.Exit");
    printf("\n\t\t8.%c BACK %c",174,174);
    printf("\n\t\tEnter Your Choice : ");
    box1(1,90,2,28);
    gotoxy(39,14);
    box(39,50,14,16);
    gotoxy(40,15);
    ch=integeronly();
     switch(ch)
     {
      case 1:
          AccPro();
          break;
      case 2:
          AcDc();
          break;
      case 3:
            AcBe();
            break;
      case 4:
            AcTcw();
            break;
      case 5:
            AcMud();
            break;
      case 6:
             AccCls();
             break;
      case 7:
          gotoxy(2,28);
          exit(0);
      case 8:
           bank_p();
           break;
      default :
            {
             printf("\n\n\t\tInvalid Response");
             printf("\n\t\tPlease Try Again.....");
             box1(1,90,2,28);
             gotoxy(3,28);
             getch();
            }
       }

    }
}


/////////////////////////////////////////ACCOUNT PROFILE////////////////////////////////////////////////////////////////////////
void AccPro()
{
    char Mg[5]="MALE",Fg[7]="FEMALE";
    system("cls");
    system("color e0");
    printf("\n\n\n\t\t\t\t   %c Account Profile %c",174,175);
    ///////////////////////////////////////////////////////////////////////
   ///////////////////////Matching For Security/////////////////////////////
   for(i=0;i<no;i++)
   {
       if(strcmp(C_un,AC[i].Uid)==0&&strcmp(C_pw,AC[i].Upw)==0)
       {
         f=i;
         break;
       }

   }
   ///////////////////////////////////////////////////////////////////////
   ///////////////////////////////////////////////////////////////////////
    printf("\n\n\n\t\t\t\t      SBI Passbook ");

    gotoxy(8,6);
    printf("\n\n\t  Account No        : ");
    for(i=0;i<11;i++)
    {
        printf("%c",AC[f].Acn[i]);
    }
    //////////////////////////////////////////////////////////////////////
    printf("\n\t  Ac Holder Name    : ");
    if(strcmp(AC[f].G,Mg)==0)
    printf("Mr. %s",AC[f].Ahn);
    else
    {
        count=0;
        for(i=0;i<6;i++)
        {
            if(AC[f].G[i]==Fg[i])
                count++;
        }
        if(count==6)
          printf("Mrs. %s",AC[f].Ahn);
    }

    /////////////////////////////
    if(AC[f].Ms==0&&strcmp(AC[f].G,"MALE")==0)
        printf("  S/O %s",AC[f].Fn);
    else if(AC[f].Ms==1&&strcmp(AC[f].G,"MALE")==0)
        printf("  S/O %s",AC[f].Fn);
    else if(AC[f].Ms==0)
    {
      count=0;
        for(i=0;i<6;i++)
        {
            if(AC[f].G[i]==Fg[i])
                count++;
        }
        if(count==6&&AC[f].Ms==0)
           printf("  D/O %s",AC[f].Fn);
    }
     else if(AC[f].Ms==1)
     {
        count=0;
        for(i=0;i<6;i++)
        {
            if(AC[f].G[i]==Fg[i])
                count++;
        }
        if(count==6&&AC[f].Ms==1)
           printf("  W/O %s",AC[f].Fn);
     }

    /////////////////////////////////////////////////////////////////////////
    printf("\n\t  Village/Town      : ");
    printf("%s",AC[f].Vtc);
    /////////////////////////////////////////////////////////////////////////
    printf("\n\t  DISTT             : ");
    printf("%s",AC[f].Dst);
    //////////////////////////////////////////////////////////////////////////
    printf("\n\t  PIN Code          : ");
    for(i=0;i<6;i++)
    {
     printf("%c",AC[f].Pin[i]);
    }
    //////////////////////////////////////////////////////////////////////////
    printf("\n\t  Address           : ");
    printf("%s",AC[f].Adrs);
    ///////////////////////////////////////////////////////////////////////////
    printf("\n\t  Phone             : ");
    printf("%s",AC[f].Mno);
    ///////////////////////////////////////////////////////////////////////////
    printf("\n\t  Email             : ");
    printf("%s",AC[f].Em);
    ////////////////////////////////////////////////////////////////////////////
    printf("\n\t  Date Of Issue     : ");
    printf("%d/%d/%d",AC[f].Dot.d,AC[f].Dot.m,AC[f].Dot.y);
    ///////////////////////////////////////////////////////////////////////////
    printf("\n\t  IFSC              : ");
    printf("%s",AC[f].Ifsc);
    ////////////////////////////////////////////////////////////////////////////
    printf("\n\n\n\t for more information & help please call at toll free no : 1800 425 3800");
    ////////////////////////////////////////////////////////////////////////////
    box1(1,90,2,28);
    box(8,81,5,21);
    getch();

}
//////////////////////////////////////////////END AccPro//////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////ACCOUNT Debit Card////////////////////////////////////////////////////////////
void AcDc()
{
    system("cls");
    system("color e0");
    printf("\n\n\n\t\t\t\t   %c Account Debit Card %c",174,175);
    ///////////////////////////////////////////////////////////////////////
   ///////////////////////Matching For Security/////////////////////////////
   for(i=0;i<no;i++)
   {
       if(strcmp(C_un,AC[i].Uid)==0&&strcmp(C_pw,AC[i].Upw)==0)
       {
         f=i;
         break;
       }

   }
   ///////////////////////////////////////////////////////////////////////
   ///////////////////////////////////////////////////////////////////////
    if(AC[f].Ds==1)
    {

     printf("\n\n\n   :DEBIT CARD Status:");
     printf("\n        Actived");
     gotoxy(34,6);
     printf("STATE BANK OF INDIA");
     gotoxy(28,9);
     printf(" %c%c%c ",177,177,177);
     gotoxy(53,14);
     printf("%c VISA CARD",251);
     gotoxy(27,14);
     printf("%s",AC[f].Ahn);

     gotoxy(30,12);
     for(i=0;i<16;i++)
     {
        if(i==4||i==8||i==12)
            printf("    ");
        printf("%c",AC[f].Dbt_n[i]);
     }
     ////////////////////////////////////////
     gotoxy(34,9);
     printf("  VALID FROM");
     printf("\t  VALID THRU");
     gotoxy(34,10);
     printf("  %d/%d",AC[f].Dot.m,AC[f].Dot.y);
     printf("\t  %d/%d",AC[f].Evdm,AC[f].Evdy);
     //////////////////////////////////////////////////////////////////////////////////////////////////////

     gotoxy(26,19);
     for(i=0;i<=38;i++)
     {
       printf("%c",219);
     }
     gotoxy(26,20);
     for(i=0;i<=38;i++)
     {
        printf("%c",219);
     }

     gotoxy(26,21);
     for(i=0;i<=28;i++)
     {
       printf("%c",176);
     }
     printf(" %d",AC[f].cvvn);
     /////////////////////////////////
     gotoxy(26,22);
     printf("Keep PIN confidentail");
     gotoxy(26,23);
     printf("card is governed by terms & condition");
     gotoxy(26,24);
     printf("of sbi debit card agreement");
     gotoxy(50,25);
     printf("SBI AUTHORISED");
     /////////////////////////////////////
     box(27,32,8,10);
     box(25,64,5,15);
     box(25,64,17,26);
     box1(1,90,2,28);
     getch();
     USSA();
    }
    else
    {
        printf("\n\n\t\tDEBIT CARD Status : Deactived");
        printf("\n\n\tYou Have Not Been Given A DEBIT CARD From The SBI BANK. ");
        printf("\n\tPlease Contact The Bank Once Again & Update Your Details For Activation.");
        box1(1,90,2,28);
        getch();

    }

}

//////////////////////////////////////////////////END Debit Card///////////////////////////////////////////////////////////////


/////////////////////////////////////////////ACCOUNT BALANCE ENQUIRY/////////////////////////////////////////////////////////////
void AcBe()
{
    char P[5];
    ///////////////////////////////////////////////////////////////////////
   ///////////////////////Matching For Security/////////////////////////////
   for(i=0;i<no;i++)
   {
       if(strcmp(C_un,AC[i].Uid)==0&&strcmp(C_pw,AC[i].Upw)==0)
       {
         f=i;
         break;
       }

   }
   ///////////////////////////////////////////////////////////////////////
   ///////////////////////////////////////////////////////////////////////

    if(AC[f].Ds==1)
    {
        system("cls");
        system("color e0");
        gotoxy(30,14);
        printf("Enter Your 4 Digit PIN No");
        gotoxy(35,15);
        Up4only(&P,4);
    }

    if(strcmp(P,AC[f].Up)==0||AC[f].Ds==0)
    {
     system("cls");
     system("color e0");
     GetSystemTime(&t);
     printf("\n\n\n\t\t\t\t  %c Account Balance Enquiry %c",174,175);
     gotoxy(38,5);
     printf("VIEW BALANCE");
     gotoxy(38,15);
     printf("STATEMENTS");
     gotoxy(15,16);
     printf("%c Last 7 Times Transction",167);
     ////////////////////////////////////////////////////////
     gotoxy(42,7);
     printf("SBI");
     printf("\n\t\tBranch  : %s",AC[f].Bb);
     printf("\t\t\tDate : %d/%d/%d",t.wDay,t.wMonth,t.wYear);
     printf("\n\t\t\t\t     Availabe Balance");
     printf("\n\t\t\t\t     %f INR",AC[f].T_Amt);
     printf("\n\t\tA/C No  : ");
     for(i=0;i<11;i++)
     {
        if(i>6)
         printf("%c",AC[f].Acn[i]);
        else
            printf("%c",'X');
     }
     printf("\t\t\tSaving Account");
     if(AC[f].Ds==1)
      {
        printf("\n\t\tDebit Card No : ");
        for(i=0;i<16;i++)
         {
           if(i>11)
           printf("%c",AC[f].Dbt_n[i]);
          else
            printf("%c",'X');
          }
     printf("\tMob No:");
     for(i=0;i<10;i++)
     {
        if(i>7)
            printf("%c",AC[f].Mno[i]);
        else
            printf("%c",'X');
     }
     }
     else
     {
        printf("\n\t\tMob No  : ");
      for(i=0;i<10;i++)
      {
         if(i>7)
            printf("%c",AC[f].Mno[i]);
         else
            printf("%c",'X');
      }
     }
     /////////////////////////////////////////
     gotoxy(15,18);
     printf("%s\t\t%s\t\t%s","Date","Credit/Debit","Availabe Balance");
     s();
     ////////////////////////////////////////
     box1(1,90,2,28);
     box(12,75,6,14);
     box(12,75,17,26);
     getch();
     USSA();
    }
    else
    {
      system("cls");
      system("color e0");
      gotoxy(28,15);
      printf("ERROR : Invalid PIN No");
      getch();
    }
}

//////////////////////////////////////////////////END Acc Balance Eaq,///////////////////////////////////////////////////////////////

//////////////////////////////////////////////ACCOUNT Details MODIFICATION//////////////////////////////////////////////////////
void AcMud()
{
    while(1)
    {
     int ch;
     system("cls");
     system("color e0");
     printf("\n\n\n\t\t\t\t   %c Modification Of Account %c",174,175);
     printf("\n\n\t\t1.A/c Holder Name");
     printf("\n\t\t2.Debit Status");
     printf("\n\t\t3.Username");
     printf("\n\t\t4.User Password");
     printf("\n\t\t5.PIN No");
     printf("\n\t\t6.Mobile No");
     printf("\n\t\t7.Email ID");
     printf("\n\t\t8.%c BACK %c",174,174);
     printf("\n\t\tEnter Your Choice : ");
     box1(1,90,2,28);
     gotoxy(35,12);
     box(35,50,12,14);
     gotoxy(36,13);
     ch=integeronly();
      switch(ch)
      {
       case 1:
           MN();
           break;
       case 2:
           MD();
           break;
       case 3:
            MUn();
            break;
       case 4:
            MUp();
            break;
       case 5:
            MP();
            break;
       case 6:
             MMn();
             break;
       case 7:
            ME();
            break;
       case 8:
           USSA();
           break;
       default :
            {
             printf("\n\n\t\tInvalid Response");
             printf("\n\t\tPlease Try Again.....");
             box1(1,90,2,28);
             gotoxy(3,28);
             getch();
            }
       }
    }

}
//////////////////////////////////////////////////END Acc Modify/////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////ACCOUNT CLOSURE////////////////////////////////////////////////////////////
void AccCls()
{
    system("cls");
    system("color e0");
    printf("\n\n\n\t\t\t\t   %c Account Closure %c",174,175);
    box1(1,90,2,28);
    del();
    getch();
}

//////////////////////////////////////////////////END Acc Closure///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////END USSA Function/////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////Modify A/c Name///////////////////////////////////////////////////////////////
void MN()
{
    FILE *fp;
    char An[12],On[25];
    int d=0,cn;
    system("cls");
    system("color e0");

    printf("\n\n\n\t\t\t\t   %c Change A/c Name %c",174,175);
    ////////////////////////////
    ///////////////////////Matching For Security/////////////////////////////
   for(i=0;i<no;i++)
   {
       if(strcmp(C_un,AC[i].Uid)==0&&strcmp(C_pw,AC[i].Upw)==0)
       {
         f=i;
         break;
       }

   }
   ///////////////////////////////////////////////////////////////////////
    printf("\n\n\t\tEnter A/c No      : ");
    box1(1,90,2,28);
    gotoxy(36,4);
    box(36,55,4,6);
    gotoxy(37,5);
    char_Donly(&An,11);
    /////////////////////////////////////////////////////////////////
   cn=0;
    for(i=0;i<11;i++)
    {
        if(An[i]==AC[f].Acn[i])
        cn++;
    }
   ///////////////////////////////////////////////////////////////////////
    printf("\n\n\n\t\tEnter A/c Old Name: ");
    box1(1,90,2,28);
    gotoxy(36,7);
    box(36,55,7,9);
    gotoxy(37,8);
    charonly(&On);
    /////////////////////////////////
    fp=fopen("Acuser.dat","rb+");
    if(fp==NULL)
    {
        printf("\n\n\t\tFile cannot open");
        box1(1,90,2,28);
        getch();
        AcMud();
    }


    fseek(fp,0,SEEK_SET);
    while(fread(&Au,recsize,1,fp)>0)
    {
        n=0;
         for(i=0;i<11;i++)
             {
                if(An[i]==Au.Acn[i])
                    n++;
             }

        if(n==11&&cn==11)
        {
           d=1;
           if(strcmp(Au.Ahn,On)==0)
                {
                   d=1;
                   printf("\n\n\n\t\tEnter New Name    : ");
                   box1(1,90,2,28);
                   gotoxy(36,10);
                   box(36,55,10,12);
                   gotoxy(37,11);
                   charonly(&Au.Ahn);
                   ////////////////////////////////////////////////
                   fseek(fp,-recsize,SEEK_CUR);
                   fwrite(&Au,recsize,1,fp);
                   break;

                }
                else
                    d=0;
        }
        else
          d=0;

    }

    fclose(fp);
    if(d==0){
        printf("\n\n\t\tInvalid Detail : Such User Not Found In BANK");
        box1(1,90,2,28);
        getch();
        AcMud();
    }
    else{
        printf("\n\n\n\t\tYour A/c Name Changed Successfully.....");
        box1(1,90,2,28);
        getch();
        AcMud();
    }

}
///////////////////////////////////////////////////////END//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////Modify Debit Status///////////////////////////////////////////////////////////
void MD(void)
{
    FILE *fp;
    int d=0,Ss,cn;
    int cpd=0,cpA=0;
    char An[11],N[25];
    system("cls");
    system("color e0");

    printf("\n\n\n\t\t\t\t   %c Change Debit Card Status %c",174,175);
    ////////////////////////////
     ///////////////////////Matching For Security/////////////////////////////
   for(i=0;i<no;i++)
   {
       if(strcmp(C_un,AC[i].Uid)==0&&strcmp(C_pw,AC[i].Upw)==0)
       {
         f=i;
         break;
       }

   }
   /////////////////////////////////////////////////////////
    printf("\n\n\t\tEnter A/c No      : ");
    box1(1,90,2,28);
    gotoxy(36,4);
    box(36,55,4,6);
    gotoxy(37,5);
    char_Donly(&An,11);
    /////////////////////////////////////////////////////////////////
   cn=0;
    for(i=0;i<11;i++)
    {
        if(An[i]==AC[f].Acn[i])
        cn++;
    }
   ///////////////////////////////////////////////////////////////////////
    printf("\n\n\n\t\tEnter A/c Name    : ");
    box1(1,90,2,28);
    gotoxy(36,7);
    box(36,55,7,9);
    gotoxy(37,8);
    charonly(&N);
    /////////////////////////////////
    fp=fopen("Acuser.dat","rb+");
    if(fp==NULL)
    {
        printf("\n\n\t\tFile cannot open");
        box1(1,90,2,28);
        getch();
        AcMud();
    }


    fseek(fp,0,SEEK_SET);
    while(fread(&Au,recsize,1,fp)>0)
    {
        n=0;
         for(i=0;i<11;i++)
             {
                if(An[i]==Au.Acn[i])
                    n++;
             }

        if(n==11&&cn==11)
        {

           if(strcmp(Au.Ahn,N)==0)
                {

                   if(Au.Ds==0)
                   {
                    printf("\n\n\n\t\tActivate Your Debit Card[Yes/No : 1/0] : ");
                    box1(1,90,2,28);
                    gotoxy(56,10);
                    box(56,65,10,12);
                    gotoxy(57,11);
                    Ss=integeronly();
                  ////////////////////////////////////////////////
                     if(Ss==1||Ss==0)
                       ;
                      else
                        {
                          printf("\n\n\t\tInvalid Response : Follow Yes=1 & No=0");
                          printf("\n\t\tTry Again To Modify.....");
                          box1(1,90,2,28);
                          getch();
                          fclose(fp);
                          AcMud();
                         }
                    ////////////////////////
                    if(Ss==1)
                        {
                            printf("\n\n\n\t\tPan Number       : ");
                            box1(1,90,2,28);
                            gotoxy(36,13);
                            box(36,55,13,15);
                            gotoxy(37,14);
                            Panonly(&Au.Pno,10);
                            /////////////////////////////////
                            if(Au.Pno[0]==48)
                             {
                               printf("\n\n\t\tInvalid : Pan No");
                               printf("\n\t\tTry Again To Sign Up.....");
                               box1(1,90,2,28);
                               getch();
                               fclose(fp);
                               AcMud();
                              }

                             if(strlen(Au.Pno)==10)
                               {
                                    if(Au.Pno[0]==48)
                                    {
                                     printf("\n\n\t\tInvalid : Pan No");
                                     printf("\n\t\tTry Again To Sign Up.....");
                                     box1(1,90,2,28);
                                     getch();
                                     fclose(fp);
                                     AcMud();
                                    }
                                    ////////////////////////////////////////////////////////
                                    Au.Ds=1;
                                    printf("\n\n\n\t\tGenerate New PIN No: ");
                                    box1(1,90,2,28);
                                    gotoxy(38,16);
                                    box(38,55,16,18);
                                    gotoxy(39,17);
                                    Up4only(&Au.Up,4);

                                    if(strlen(Au.Up)==4)
                                     {
                                       d=1;
                                       fseek(fp,-recsize,SEEK_CUR);
                                       fwrite(&Au,recsize,1,fp);
                                        break;
                                     }
                                   else
                                    {
                                      printf("\n\n\t\tInvalid PIN : ONLY 4 DIGITS Allowed Here");
                                      printf("\n\t\tTry Again To Modify.....");
                                      box1(1,90,2,28);
                                      getch();
                                      fclose(fp);
                                      AcMud();
                                     }

                                }
                            else
                              {
                                 printf("\n\n\t\tInvalid : 10 Digits Allowed");
                                 printf("\n\t\tTry Again To Modify.....");
                                 box1(1,90,2,28);
                                 getch();
                                 fclose(fp);
                                 AcMud();
                               }

                        }

                    else if(Ss==0){
                            printf("\n\n\n\t\tNothing Has Been Changed In Your Debit Card Status");
                            box1(1,90,2,28);
                            getch();
                            fclose(fp);
                            AcMud();
                    }

                    ////////////////////////////////////////////////
                   }
                   else if(Au.Ds==1)
                    {
                      printf("\n\n\n\t\tDeactivate Your Debit Card[Yes/No : 1/0] : ");
                      box1(1,90,2,28);
                      gotoxy(58,10);
                      box(58,65,10,12);
                      gotoxy(59,11);
                      Ss=integeronly();
                     ////////////////////////////////////////////////////////
                       if(Ss==1||Ss==0)
                         ;
                       else
                         {
                           printf("\n\n\t\tInvalid Response : Follow Yes=1 & No=0");
                           printf("\n\t\tTry Again To Modify.....");
                           box1(1,90,2,28);
                           getch();
                           fclose(fp);
                           AcMud();
                          }
                     /////////////////////////////////////////////////////////

                      if(Ss==1)
                      {
                         d=1;
                         Au.Ds=0;
                         fseek(fp,-recsize,SEEK_CUR);
                         fwrite(&Au,recsize,1,fp);
                         break;
                      }
                      else if(Ss==0)
                      {
                           printf("\n\n\n\t\tNothing Has Been Changed In Your Debit Card Status");
                           box1(1,90,2,28);
                           fclose(fp);
                           getch();
                           AcMud();
                      }
                    //////////////////
                    }

                }
                else
                    d=0;
        }
        else
          d=0;

    }

    fclose(fp);
    if(d==0){
        printf("\n\n\t\tInvalid Detail : Such User Not Found In BANK");
        box1(1,90,2,28);
        getch();
        AcMud();
    }
    else if(d==1&&Ss==1)
        {
        printf("\n\n\n\t\tYour Debit Card Status Updated Successfully.....");
        box1(1,90,2,28);
        getch();
        AcMud();
       }

}
////////////////////////////////////////////////////////END/////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////Modify Username///////////////////////////////////////////////////////////////
void MUn(void)
{
    FILE *fp;
    char An[11],N[25],U[13],M[10];
    int uA=0,ua=0,un=0,uc=0;
    int d=0,Ss,cn;
    system("cls");
    system("color e0");

    printf("\n\n\n\t\t\t\t   %c Change Username %c",174,175);
    ////////////////////////////
     ///////////////////////Matching For Security/////////////////////////////
   for(i=0;i<no;i++)
   {
       if(strcmp(C_un,AC[i].Uid)==0&&strcmp(C_pw,AC[i].Upw)==0)
       {
         f=i;
         break;
       }

   }
   /////////////////////////////////////////////////////////
    printf("\n\n\t\tEnter A/c No      : ");
    box1(1,90,2,28);
    gotoxy(36,4);
    box(36,55,4,6);
    gotoxy(37,5);
    char_Donly(&An,11);
    /////////////////////////////////////////////////////////////////
   cn=0;
    for(i=0;i<11;i++)
    {
        if(An[i]==AC[f].Acn[i])
        cn++;
    }
   ///////////////////////////////////////////////////////////////////////
    printf("\n\n\n\t\tEnter A/c Name    : ");
    box1(1,90,2,28);
    gotoxy(36,7);
    box(36,55,7,9);
    gotoxy(37,8);
    charonly(&N);

    printf("\n\n\n\t\tDo You remember Old Username[1/0]: ");
    box1(1,90,2,28);
    gotoxy(50,10);
    box(50,55,10,12);
    gotoxy(51,11);
    Ss=integeronly();
    ///////////////////////////////////////////////////////////////
    if(Ss==1||Ss==0)
     ;
   else
    {
      printf("\n\n\t\tInvalid Response : Follow Yes=1 & No=0");
      printf("\n\t\tTry Again To Modify.....");
      box1(1,90,2,28);
      getch();
      AcMud();
    }
    ///////////////////////////////////////////////////////////////
    if(Ss==1)
    {
    printf("\n\n\n\t\tEnter Old Username: ");
    box1(1,90,2,28);
    gotoxy(36,13);
    box(36,55,13,15);
    gotoxy(37,14);
    fflush(stdin);
    gets(U);
    }
    else
    {
     printf("\n\n\n\t\tEnter Mobile No   : ");
     box1(1,90,2,28);
     gotoxy(36,13);
     box(36,55,13,15);
     gotoxy(37,14);
     char_Donly(&M,10);

    }
    /////////////////////////////////
    fp=fopen("Acuser.dat","rb+");
    if(fp==NULL)
    {
        printf("\n\n\t\tFile cannot open");
        box1(1,90,2,28);
        getch();
        AcMud();
    }


    fseek(fp,0,SEEK_SET);
    while(fread(&Au,recsize,1,fp)>0)
    {
        n=0;
         for(i=0;i<11;i++)
             {
                if(An[i]==Au.Acn[i])
                    n++;
             }

        if(n==11&&cn==11)
        {

           if(strcmp(Au.Ahn,N)==0)
                {
                   if(Ss==1)
                   {
                     if(strcmp(Au.Uid,U)==0)
                     {
                        printf("\n\n\t\t[(6-12 char) A-Z | a-z |0-9 ]");
                        printf("\n\n\t\tCreate New Username: ");
                        box1(1,90,2,28);
                        gotoxy(37,18);
                        box(37,55,18,20);
                        gotoxy(38,19);
                        fflush(stdin);
                        gets(Au.Uid);
                        ///////////////////////////////////////////////////
                        n=0;
                        n=strlen(Au.Uid);

                    if(n>=6&&n<=12)
                       {
                        for(i=0;Au.Uid[i];i++)
                        {
                         if(Au.Uid[i]>='A'&&Au.Uid[i]<='Z')
                           uA++;
                         else if(Au.Uid[i]>='a'&&Au.Uid[i]<='z')
                           ua++;
                         else if(Au.Uid[i]>=48&&Au.Uid[i]<=57)
                           un++;
                         }
                        if(uA>0&&ua>0&&un>0)
                         uc=uA+ua+un;

                         if(uc==n)
                            {
                                d=1;
                                ////////////////////////////////////////////////
                                fseek(fp,-recsize,SEEK_CUR);
                                 fwrite(&Au,recsize,1,fp);
                                 break;

                            }
                          else
                           {
                              printf("\n\n\t\tInvalid : User ID ");
                              printf("\n\t\tPlease Follow Above Rules To Modify Again.....");
                              box1(1,90,2,28);
                              getch();
                              fclose(fp);
                              AcMud();
                            }
                      }
                     else
                        {
                            printf("\n\n\t\tInvalid User ID: Enter Minimum 6 & Max. 12 Characters");
                            printf("\n\t\tTry Again To Modify.......\n");
                            box1(1,90,2,28);
                            getch();
                            fclose(fp);
                            AcMud();
                         }



                     }
                     else
                        d=0;
                   }
                   else if(Ss==0)
                   {
                     if(strcmp(Au.Mno,M)==0)
                     {
                        printf("\n\n\t\t[(6-12 char) A-Z | a-z |0-9 ]");
                        printf("\n\n\t\tCreate New Username: ");
                        box1(1,90,2,28);
                        gotoxy(37,17);
                        box(37,55,17,19);
                        gotoxy(38,18);
                        fflush(stdin);
                        gets(Au.Uid);
                        ///////////////////////////////////////////////////
                        n=0;
                        n=strlen(Au.Uid);

                    if(n>=6&&n<=12)
                       {
                        for(i=0;Au.Uid[i];i++)
                        {
                         if(Au.Uid[i]>='A'&&Au.Uid[i]<='Z')
                           uA++;
                         else if(Au.Uid[i]>='a'&&Au.Uid[i]<='z')
                           ua++;
                         else if(Au.Uid[i]>=48&&Au.Uid[i]<=57)
                           un++;
                         }
                        if(uA>0&&ua>0&&un>0)
                         uc=uA+ua+un;

                         if(uc==n)
                            {
                                d=1;
                                ////////////////////////////////////////////////
                                fseek(fp,-recsize,SEEK_CUR);
                                 fwrite(&Au,recsize,1,fp);
                                 break;

                            }
                          else
                           {
                              printf("\n\n\t\tInvalid : User ID ");
                              printf("\n\t\tPlease Follow Above Rules To Modify Again.....");
                              box1(1,90,2,28);
                              getch();
                              fclose(fp);
                              AcMud();
                            }
                      }
                     else
                        {
                            printf("\n\n\t\tInvalid User ID: Enter Minimum 6 & Max. 12 Characters");
                            printf("\n\t\tTry Again To Modify.......\n");
                            box1(1,90,2,28);
                            getch();
                            fclose(fp);
                            AcMud();
                         }


                     }
                     else
                        d=0;
                   }

                }
                else
                    d=0;
        }
        else
          d=0;

    }

    fclose(fp);
    if(d==0){
        printf("\n\n\t\tInvalid Detail : Such User Not Found In BANK");
        box1(1,90,2,28);
        getch();
        AcMud();
    }
    else{
        printf("\n\n\n\t\tYour A/c Username Changed Successfully.....");
        box1(1,90,2,28);
        getch();
        AcMud();
    }

}
////////////////////////////////////////////////////////END/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////Modify User Password///////////////////////////////////////////////////////////
void MUp(void)
{
    FILE *fp;
    char An[11],N[25],Op[17],M[10],Np[17],Cp[17];
    int pwA=0,pwa=0,pwn=0,pws=0,pwc=0;
    int d=0,Ss,pp,cn;
    system("cls");
    system("color e0");
    printf("\n\n\n\t\t\t\t   %c Change User password %c",174,175);
    //////////////////////////////////////////
     ///////////////////////Matching For Security/////////////////////////////
   for(i=0;i<no;i++)
   {
       if(strcmp(C_un,AC[i].Uid)==0&&strcmp(C_pw,AC[i].Upw)==0)
       {
         f=i;
         break;
       }

   }
   /////////////////////////////////////////////////////////
    printf("\n\n\t\tEnter A/c No      : ");
    box1(1,90,2,28);
    gotoxy(36,4);
    box(36,55,4,6);
    gotoxy(37,5);
    char_Donly(&An,11);
    /////////////////////////////////////////////////////////////////
   cn=0;
    for(i=0;i<11;i++)
    {
        if(An[i]==AC[f].Acn[i])
        cn++;
    }
   ///////////////////////////////////////////////////////////////////////
    printf("\n\n\n\t\tEnter A/c Name    : ");
    box1(1,90,2,28);
    gotoxy(36,7);
    box(36,55,7,9);
    gotoxy(37,8);
    charonly(&N);
    //////////////////////////////////////
    printf("\n\n\n\t\tDo You remember Old Password[1/0]: ");
    box1(1,90,2,28);
    gotoxy(50,10);
    box(50,55,10,12);
    gotoxy(51,11);
    Ss=integeronly();


    if(Ss==1||Ss==0)
     ;
   else
    {
      printf("\n\n\t\tInvalid Response : Follow Yes=1 & No=0");
      printf("\n\t\tTry Again To Modify.....");
      box1(1,90,2,28);
      getch();
      AcMud();
    }
    //////////////////////////////////////////////////////////////
    fp=fopen("Acuser.dat","rb+");
    if(fp==NULL)
    {
        printf("\n\n\t\tFile cannot open");
        box1(1,90,2,28);
        getch();
        AcMud();
    }
    //////////////////////////////////////////////////////////

    fseek(fp,0,SEEK_SET);
    while(fread(&Au,recsize,1,fp)>0)
    {
        n=0;
         for(i=0;i<11;i++)
             {
                if(An[i]==Au.Acn[i])
                    n++;
             }

        if(n==11&&cn==1)
        {
            d=1;
            if(strcmp(Au.Ahn,N)==0)
                {

                    if(Ss==1)
                    {
                       printf("\n\n\n\t\tEnter Old Password: ");
                       box1(1,90,2,28);
                       gotoxy(36,13);
                       box(36,55,13,15);
                       gotoxy(37,14);
                      //////////////////////
                      i=0;
                     do
                     {
                       pp=getch();
                      if(pp==BKSP&&i>0)
                       {
                        i--;
                        printf("\b");
                        printf(" ");
                        printf("\b");
                       }

                       if(pp!=SPACE&&pp!=ENTER&&pp!=BKSP)
                         {
                          printf("%c",'*');
                          Op[i]=pp;
                          i++;
                          }
                         if(pp==ENTER&&i>0)
                          {
                            Op[i]='\0';
                            break;
                           }

                        }while(1);



                      if(strcmp(Au.Upw,Op)==0)
                      {
                             /////////////////////////////////////////////
                              printf("\n\n\t\t[(8-16 char) A-Z | a-z | 0-9 With special Symbol]");
                              printf("\n\n\t\tNew Password      : ");
                              box1(1,90,2,28);
                              gotoxy(36,17);
                              box(36,55,17,19);
                              gotoxy(37,18);
                             //////////////////////////
                                i=0;
                                do
                                {
                                    pp=getch();
                                   if(pp==BKSP&&i>0)
                                       {
                                          i--;
                                          printf("\b");
                                          printf(" ");
                                          printf("\b");
                                        }

                                     if(pp!=SPACE&&pp!=ENTER&&pp!=BKSP)
                                        {
                                          printf("%c",'*');
                                          Np[i]=pp;
                                          i++;
                                         }
                                      if(pp==ENTER&&i>0)
                                         {
                                           Np[i]='\0';
                                           break;
                                         }

                                    }while(1);
                                //////////////////////////////////////////////
                                  printf("\n\n\n\t\tConfirm Password  : ");
                                  box1(1,90,2,28);
                                  gotoxy(36,20);
                                  box(36,55,20,22);
                                  gotoxy(37,21);
                                 //////////////////////////
                                     i=0;
                                     do
                                       {
                                          pp=getch();
                                          if(pp==BKSP&&i>0)
                                             {
                                                i--;
                                                printf("\b");
                                                printf(" ");
                                                printf("\b");
                                              }

                                            if(pp!=SPACE&&pp!=ENTER&&pp!=BKSP)
                                               {
                                                 printf("%c",'*');
                                                 Cp[i]=pp;
                                                  i++;
                                                }
                                             if(pp==ENTER&&i>0)
                                                {
                                                   Cp[i]='\0';
                                                   break;
                                                 }

                                         }while(1);

                                         if(strcmp(Np,Cp)==0)
                                         {
                                             n=0;
                                             n=strlen(Cp);
                                             if(n>=8&&n<=16)
                                             {
                                                 for(i=0;i<n;i++)
                                               {

                                                if(Au.Upw[i]>='A'&&Au.Upw[i]<='Z')
                                                     pwA++;
                                                 else if(Au.Upw[i]>='a'&&Au.Upw[i]<='z')
                                                     pwa++;
                                                 else if(Au.Upw[i]>=48&&Au.Upw[i]<=57)
                                                     pwn++;
                                                 else if(Au.Upw[i]>=0&&Au.Upw[i]<=47)
                                                    pws++;
                                                 else if(Au.Upw[i]>=58&&Au.Upw[i]<=64)
                                                    pws++;
                                                 else if(Au.Upw[i]>=91&&Au.Upw[i]<=96)
                                                    pws++;
                                                 else if(Au.Upw[i]>=123&&Au.Upw[i]<=127)
                                                    pws++;
                                                }
                                              if(pwa>0&&pwn>0&&pwA>0&&pws>0)
                                               pwc=(pwa+pwA+pwn+pws);

                                               if(pwc==n)
                                                 {
                                                   d=1;
                                                   strcpy(Au.Upw,Cp);
                                                   //////////////////////
                                                   fseek(fp,-recsize,1);
                                                   fwrite(&Au,recsize,1,fp);
                                                   fclose(fp);
                                                   break;
                                                 }
                                               else
                                                {
                                                 printf("\n\n\t\tInvalid : Password");
                                                 printf("\n\t\tPlease Follow Above Rule To Try Again.......\n");
                                                 box1(1,90,2,28);
                                                 getch();
                                                 fclose(fp);
                                                 AcMud();

                                                  }
                                             }
                                             else
                                             {
                                                printf("\n\n\t\tInvalid : Enter Minimum 8 & Max. 16 character");
                                                printf("\n\t\tTry Again To Modify.....");
                                                box1(1,90,2,28);
                                                getch();
                                                fclose(fp);
                                                AcMud();
                                                }

                                         }
                                         else
                                         {
                                             printf("\n\n\t\tInvalid : Confirm Password don't Match");
                                             box1(1,90,2,28);
                                             getch();
                                             fclose(fp);
                                             AcMud();
                                         }

                      }
                      else
                      {
                          printf("\n\n\t\tInvalid : Old Password ");
                          box1(1,90,2,28);
                          getch();
                          fclose(fp);
                          AcMud();
                      }
                    }
                    else if(Ss==0)
                    {
                        printf("\n\n\n\t\tEnter Mobile No   : ");
                        box1(1,90,2,28);
                        gotoxy(36,13);
                        box(36,55,13,15);
                        gotoxy(37,14);
                        char_Donly(&M,10);

                        if(strcmp(Au.Mno,M)==0)
                         {
                             /////////////////////////////////////////////
                              printf("\n\n\t\t[(8-16 char) A-Z | a-z | 0-9 With special Symbol]");
                              printf("\n\n\t\tNew Password      : ");
                              box1(1,90,2,28);
                              gotoxy(36,17);
                              box(36,55,17,19);
                              gotoxy(37,18);
                             //////////////////////////
                                i=0;
                                do
                                {
                                    pp=getch();
                                   if(pp==BKSP&&i>0)
                                       {
                                          i--;
                                          printf("\b");
                                          printf(" ");
                                          printf("\b");
                                        }

                                     if(pp!=SPACE&&pp!=ENTER&&pp!=BKSP)
                                        {
                                          printf("%c",'*');
                                          Np[i]=pp;
                                          i++;
                                         }
                                      if(pp==ENTER&&i>0)
                                         {
                                           Np[i]='\0';
                                           break;
                                         }

                                    }while(1);
                                //////////////////////////////////////////////
                                  printf("\n\n\n\t\tConfirm Password  : ");
                                  box1(1,90,2,28);
                                  gotoxy(36,20);
                                  box(36,55,20,22);
                                  gotoxy(37,21);
                                 //////////////////////////
                                     i=0;
                                     do
                                       {
                                          pp=getch();
                                          if(pp==BKSP&&i>0)
                                             {
                                                i--;
                                                printf("\b");
                                                printf(" ");
                                                printf("\b");
                                              }

                                            if(pp!=SPACE&&pp!=ENTER&&pp!=BKSP)
                                               {
                                                 printf("%c",'*');
                                                 Cp[i]=pp;
                                                  i++;
                                                }
                                             if(pp==ENTER&&i>0)
                                                {
                                                   Cp[i]='\0';
                                                   break;
                                                 }

                                         }while(1);

                                         if(strcmp(Np,Cp)==0)
                                         {
                                             n=0;
                                             n=strlen(Cp);
                                             if(n>=8&&n<=16)
                                             {
                                                 for(i=0;i<n;i++)
                                               {

                                                if(Au.Upw[i]>='A'&&Au.Upw[i]<='Z')
                                                     pwA++;
                                                 else if(Au.Upw[i]>='a'&&Au.Upw[i]<='z')
                                                     pwa++;
                                                 else if(Au.Upw[i]>=48&&Au.Upw[i]<=57)
                                                     pwn++;
                                                 else if(Au.Upw[i]>=0&&Au.Upw[i]<=47)
                                                    pws++;
                                                 else if(Au.Upw[i]>=58&&Au.Upw[i]<=64)
                                                    pws++;
                                                 else if(Au.Upw[i]>=91&&Au.Upw[i]<=96)
                                                    pws++;
                                                 else if(Au.Upw[i]>=123&&Au.Upw[i]<=127)
                                                    pws++;
                                                }
                                              if(pwa>0&&pwn>0&&pwA>0&&pws>0)
                                               pwc=(pwa+pwA+pwn+pws);

                                               if(pwc==n)
                                                 {
                                                   d=1;
                                                   strcpy(Au.Upw,Cp);
                                                   //////////////////////
                                                   fseek(fp,-recsize,1);
                                                   fwrite(&Au,recsize,1,fp);
                                                   break;
                                                 }
                                               else
                                                {
                                                 printf("\n\n\t\tInvalid : Password");
                                                 printf("\n\t\tPlease Follow Above Rule To Try Again.......\n");
                                                 box1(1,90,2,28);
                                                 getch();
                                                 fclose(fp);
                                                 AcMud();

                                                  }
                                             }
                                             else
                                             {
                                                printf("\n\n\t\tInvalid : Enter Minimum 8 & Max. 16 character");
                                                printf("\n\t\tTry Again To Modify.....");
                                                box1(1,90,2,28);
                                                getch();
                                                fclose(fp);
                                                AcMud();
                                                }

                                         }
                                         else
                                         {
                                             printf("\n\n\t\tInvalid : Confirm Password don't Match");
                                             box1(1,90,2,28);
                                             getch();
                                             fclose(fp);
                                             AcMud();
                                         }
                         }
                         else
                         {
                            printf("\n\n\t\tInvalid : Mobile No");
                            box1(1,90,2,28);
                            getch();
                            fclose(fp);
                            AcMud();
                         }
                    }

                }
                else
                 d=0;
        }
        else
         d=0;

    }

    fclose(fp);
    if(d==0){
        printf("\n\n\t\tInvalid Detail : Such User Not Found In BANK");
        box1(1,90,2,28);
        getch();
        AcMud();
    }
    else{
        printf("\n\n\n\t\tYour A/c Password Changed Successfully.....");
        box1(1,90,2,28);
        getch();
        AcMud();
    }


}
////////////////////////////////////////////////////////END/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////Modify User PIN NO/////////////////////////////////////////////////////////////
void MP(void)
{
    FILE *fp;
    char An[11],N[25],M[10],OP[5],Up[17];
    int Ss,d=0,pp,cn;
    system("cls");
    system("color e0");
    printf("\n\n\n\t\t\t\t   %c Change Debit Card PIN No %c",174,175);
    //////////////////////////////////////////
     ///////////////////////Matching For Security/////////////////////////////
   for(i=0;i<no;i++)
   {
       if(strcmp(C_un,AC[i].Uid)==0&&strcmp(C_pw,AC[i].Upw)==0)
       {
         f=i;
         break;
       }

   }
   /////////////////////////////////////////////////////////
    printf("\n\n\t\tEnter A/c No      : ");
    box1(1,90,2,28);
    gotoxy(36,4);
    box(36,55,4,6);
    gotoxy(37,5);
    char_Donly(&An,11);
    /////////////////////////////////////////////////////////////////
   cn=0;
    for(i=0;i<11;i++)
    {
        if(An[i]==AC[f].Acn[i])
        cn++;
    }
   ///////////////////////////////////////////////////////////////////////
    printf("\n\n\n\t\tEnter A/c Name    : ");
    box1(1,90,2,28);
    gotoxy(36,7);
    box(36,55,7,9);
    gotoxy(37,8);
    charonly(&N);
    //////////////////////////////////////
    printf("\n\n\n\t\tDo You remember Old PIN NO [1/0] : ");
    box1(1,90,2,28);
    gotoxy(50,10);
    box(50,55,10,12);
    gotoxy(51,11);
    Ss=integeronly();
    ///////////////////////////////////////////////////////////
    if(Ss==1||Ss==0)
     ;
   else
    {
      printf("\n\n\t\tInvalid Response : Follow Yes=1 & No=0");
      printf("\n\t\tTry Again To Modify.....");
      box1(1,90,2,28);
      getch();
      AcMud();
    }
    //////////////////////////////////////////////////////////////
    fp=fopen("Acuser.dat","rb+");
    if(fp==NULL)
    {
        printf("\n\n\t\tFile cannot open");
        box1(1,90,2,28);
        getch();
        AcMud();
    }
    //////////////////////////////////////////////////////////

    fseek(fp,0,SEEK_SET);
    while(fread(&Au,recsize,1,fp)>0)
    {
        n=0;
         for(i=0;i<11;i++)
             {
                if(An[i]==Au.Acn[i])
                    n++;
             }

        if(n==11&&cn==11)
        {
            if(strcmp(Au.Ahn,N)==0)
            {
                if(Ss==1)
                {
                    printf("\n\n\n\t\tEnter Old PIN No  : ");
                    box1(1,90,2,28);
                    gotoxy(36,13);
                    box(36,55,13,15);
                    gotoxy(37,14);
                    Up4only(&OP,4);
                    //////////////////////////////////////////////
                    if(strcmp(Au.Up,OP)==0)
                    {
                           printf("\n\n\n\t\tGenerate New PIN No: ");
                           box1(1,90,2,28);
                           gotoxy(38,16);
                           box(38,55,16,18);
                           gotoxy(39,17);
                           Up4only(&Au.Up,4);

                           if(strlen(Au.Up)==4)
                             {
                                 d=1;
                                 fseek(fp,-recsize,SEEK_CUR);
                                 fwrite(&Au,recsize,1,fp);
                                 fclose(fp);
                                 break;
                             }
                           else
                             {
                                  printf("\n\n\t\tInvalid PIN : ONLY 4 DIGITS Allowed Here");
                                  printf("\n\t\tTry Again To Modify.....");
                                  box1(1,90,2,28);
                                  getch();
                                  fclose(fp);
                                  AcMud();
                             }
                    }
                    else
                    {
                        printf("\n\n\t\tInvalid : Old PIN No");
                        box1(1,90,2,28);
                        getch();
                        fclose(fp);
                        AcMud();
                    }


                }
                else if(Ss==0)
                {
                    printf("\n\n\n\t\tEnter Mobile No   : ");
                    box1(1,90,2,28);
                    gotoxy(36,13);
                    box(36,55,13,15);
                    gotoxy(37,14);
                    char_Donly(&M,10);
                    //////////////////////////////////////////////
                    if(strcmp(Au.Mno,M)==0)
                    {
                        printf("\n\n\n\t\tEnter A/c Password: ");
                        box1(1,90,2,28);
                        gotoxy(36,16);
                        box(36,55,16,18);
                        gotoxy(37,17);
                        /////////////////////////
                          i=0;
                          do
                          {
                            pp=getch();
                             if(pp==BKSP&&i>0)
                               {
                                 i--;
                                 printf("\b");
                                 printf(" ");
                                 printf("\b");
                                }

                              if(pp!=SPACE&&pp!=ENTER&&pp!=BKSP)
                                {
                                  printf("%c",'*');
                                  Up[i]=pp;
                                  i++;
                                }
                              if(pp==ENTER&&i>0)
                                {
                                   Up[i]='\0';
                                    break;
                                }

                           }while(1);

                           ///////////////////////////////////
                           if(strcmp(Au.Upw,Up)==0)
                           {
                              printf("\n\n\n\t\tGenerate New PIN No: ");
                              box1(1,90,2,28);
                              gotoxy(38,19);
                              box(38,55,19,21);
                              gotoxy(39,20);
                              Up4only(&Au.Up,4);

                             if(strlen(Au.Up)==4)
                               {
                                 d=1;
                                 fseek(fp,-recsize,SEEK_CUR);
                                 fwrite(&Au,recsize,1,fp);
                                 break;
                               }
                             else
                               {
                                  printf("\n\n\t\tInvalid PIN : ONLY 4 DIGITS Allowed Here");
                                  printf("\n\t\tTry Again To Modify.....");
                                  box1(1,90,2,28);
                                  getch();
                                  fclose(fp);
                                  AcMud();
                               }
                           }
                           else
                           {
                               printf("\n\n\t\tInvalid : Your A/c Password");
                               box1(1,90,2,28);
                               getch();
                               fclose(fp);
                               AcMud();
                           }

                    }
                    else
                    {
                        printf("\n\n\t\tInvalid : Mobile No");
                        box1(1,90,2,28);
                        getch();
                        fclose(fp);
                        AcMud();
                    }
                }
            }
            else
                d=0;
        }
        else
          d=0;
    }

    ////////////////////////////
    fclose(fp);
    if(d==0){
        printf("\n\n\t\tInvalid Detail : Such User Not Found In BANK");
        box1(1,90,2,28);
        getch();
        AcMud();
    }
    else{
        printf("\n\n\n\t\tYour A/c Debit Card PIN NO Changed Successfully.....");
        box1(1,90,2,28);
        getch();
        AcMud();
    }



}
////////////////////////////////////////////////////////END/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////Modify Mobile NO///////////////////////////////////////////////////////////////
void MMn(void)
{
    FILE *fp;
    char An[11],N[25],OM[10];
    int d=0,cn;
    system("cls");
    system("color e0");
    printf("\n\n\n\t\t\t\t   %c Change Mobile No %c",174,175);
    //////////////////////////////////////////
     ///////////////////////Matching For Security/////////////////////////////
   for(i=0;i<no;i++)
   {
       if(strcmp(C_un,AC[i].Uid)==0&&strcmp(C_pw,AC[i].Upw)==0)
       {
         f=i;
         break;
       }

   }
   /////////////////////////////////////////////////////////
    printf("\n\n\t\tEnter A/c No      : ");
    box1(1,90,2,28);
    gotoxy(36,4);
    box(36,55,4,6);
    gotoxy(37,5);
    char_Donly(&An,11);
    /////////////////////////////////////////////////////////////////
   cn=0;
    for(i=0;i<11;i++)
    {
        if(An[i]==AC[f].Acn[i])
        cn++;
    }
   ///////////////////////////////////////////////////////////////////////
    printf("\n\n\n\t\tEnter A/c Name    : ");
    box1(1,90,2,28);
    gotoxy(36,7);
    box(36,55,7,9);
    gotoxy(37,8);
    charonly(&N);

    /////////////////////////////////////////////////
    fp=fopen("Acuser.dat","rb+");
    if(fp==NULL)
    {
        printf("\n\n\t\tFile cannot open");
        box1(1,90,2,28);
        getch();
        AcMud();
    }
    //////////////////////////////////////////////////////////
    fseek(fp,0,SEEK_SET);
    while(fread(&Au,recsize,1,fp)>0)
    {
         n=0;
         for(i=0;i<11;i++)
             {
                if(An[i]==Au.Acn[i])
                    n++;
             }

        if(n==11&&cn==11)
        {
            if(strcmp(Au.Ahn,N)==0)
            {
                /////////////////////////////////////////////
                 printf("\n\n\n\t\tEnter Old Mobile No: ");
                 box1(1,90,2,28);
                 gotoxy(37,10);
                 box(37,55,10,12);
                 gotoxy(38,11);
                 char_Donly(&OM,10);
                if(strcmp(Au.Mno,OM)==0)
                {
                    printf("\n\n\n\t\tNew Mobile No     : ");
                    box1(1,90,2,28);
                    gotoxy(37,13);
                    box(37,55,13,15);
                    gotoxy(38,14);
                    char_Donly(&Au.Mno,10);
                    if(strlen(Au.Mno)==10&&Au.Mno[0]!=48)
                    {
                    ////////////////////////
                    d=1;
                    fseek(fp,-recsize,SEEK_CUR);
                    fwrite(&Au,recsize,1,fp);
                    break;
                    }
                    else
                    {
                       printf("\n\n\t\tInvalid : Mobile No");
                       box1(1,90,2,28);
                       getch();
                       fclose(fp);
                       AcMud();
                    }
                }
                else
                {
                    printf("\n\n\t\tInvalid : Old Mobile No");
                    box1(1,90,2,28);
                    getch();
                    fclose(fp);
                    AcMud();
                }
            }
            else
              d=0;
        }
        else
          d=0;

    }
    /////////////////////////////////
    fclose(fp);

    if(d==0){
        printf("\n\n\t\tInvalid Detail : Such User Not Found In BANK");
        box1(1,90,2,28);
        getch();
        AcMud();
    }
    else{
        printf("\n\n\n\t\tYour A/c Mobile No Changed Successfully.....");
        box1(1,90,2,28);
        getch();
        AcMud();
    }

}
////////////////////////////////////////////////////////END/////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////Modify E-Mail ID/////////////////////////////////////////////////////////////
void ME(void)
{
    FILE *fp;
    char An[11],N[25],OE[30];
    //////E-Mail ID Variables
    int cn,l,ea=0,en=0,et=0,d=0;
    char ch_em[11]="@gmail.com";
    char n_em[20],alno[20];

    system("cls");
    system("color e0");
    printf("\n\n\n\t\t\t\t   %c Change E-Mail ID %c",174,175);
    //////////////////////////////////////////
     ///////////////////////Matching For Security/////////////////////////////
   for(i=0;i<no;i++)
   {
       if(strcmp(C_un,AC[i].Uid)==0&&strcmp(C_pw,AC[i].Upw)==0)
       {
         f=i;
         break;
       }

   }
   /////////////////////////////////////////////////////////
    printf("\n\n\t\tEnter A/c No      : ");
    box1(1,90,2,28);
    gotoxy(36,4);
    box(36,55,4,6);
    gotoxy(37,5);
    char_Donly(&An,11);
    /////////////////////////////////////////////////////////////////
   cn=0;
    for(i=0;i<11;i++)
    {
        if(An[i]==AC[f].Acn[i])
        cn++;
    }
   ///////////////////////////////////////////////////////////////////////
    printf("\n\n\n\t\tEnter A/c Name    : ");
    box1(1,90,2,28);
    gotoxy(36,7);
    box(36,55,7,9);
    gotoxy(37,8);
    charonly(&N);

    /////////////////////////////////////////////////
    fp=fopen("Acuser.dat","rb+");
    if(fp==NULL)
    {
        printf("\n\n\t\tFile cannot open");
        box1(1,90,2,28);
        getch();
        AcMud();
    }
    //////////////////////////////////////////////////////////
    fseek(fp,0,SEEK_SET);
    while(fread(&Au,recsize,1,fp)>0)
    {
         n=0;
         for(i=0;i<11;i++)
             {
                if(An[i]==Au.Acn[i])
                    n++;
             }

        if(n==11&&cn==11)
        {
            if(strcmp(Au.Ahn,N)==0)
            {
                /////////////////////////////////////////////
                 printf("\n\n\n\t\tEnter Old E-Mail  : ");
                 box1(1,90,2,28);
                 gotoxy(37,10);
                 box(37,55,10,12);
                 gotoxy(38,11);
                 fflush(stdin);
                 gets(OE);
              if(strcmp(Au.Em,OE)==0)
               {
                    printf("\n\n\t\tNew E-Mail ID     : ");
                    box1(1,90,2,28);
                    gotoxy(37,13);
                    box(37,60,13,15);
                    gotoxy(38,14);
                    fflush(stdin);
                    gets(Au.Em);

                    //////////////////////////////
                  count=0;
                  l=0;
                for(i=0;Au.Em[i];i++)
                {

                   if(Au.Em[i]==ch_em[l])
                    {
                      n_em[l]=Au.Em[i];
                      l++;
                    }
                   else if(l>0)
                    {
                      n_em[l]=Au.Em[i];
                      l++;
                    }


                   if(l==0)
                    {
                      alno[i]=Au.Em[i];
                   if(Au.Em[i]>='A'&&Au.Em[i]<='Z'||Au.Em[i]>='a'&&Au.Em[i]<='z')
                       ea++;
                   else if(Au.Em[i]>=48&&Au.Em[i]<=57)
                       en++;
                   }
                   else if(l==1)
                    {
                      alno[i]='\0';
                    }

                 }
                        n_em[l]='\0';


                         if(ea>0&&en>0)
                            et=ea+en;

                          if(strlen(alno)==et)
                             {
                                 if(strcmp(n_em,ch_em)==0&&strlen(Au.Em)>=12&&l==10)
                                  {
                                    d=1;
                                    fseek(fp,-recsize,SEEK_CUR);
                                    fwrite(&Au,recsize,1,fp);
                                    break;
                                  }
                                else
                                 {
                                   printf("\n\n\t\tYou Have Entered Invalid E-Mail ID......");
                                   printf("\n\t\tTry Again.....\n");
                                   box1(1,90,2,28);
                                   getch();
                                   fclose(fp);
                                   AcMud();
                                 }

                             }
                          else
                            {
                                printf("\n\n\t\tPlease Enter Your Alphanumerical Name");
                                printf("\n\t\tTry Again.....\n");
                                box1(1,90,2,28);
                                getch();
                                fclose(fp);
                                AcMud();
                            }

                }
                else
                {
                    printf("\n\n\t\tInvalid : Old E-Mail ID");
                    box1(1,90,2,28);
                    getch();
                    fclose(fp);
                    AcMud();
                }
            }
            else
              d=0;
        }
        else
          d=0;

    }
    /////////////////////////////////
    fclose(fp);

    if(d==0){
        printf("\n\n\t\tInvalid Detail : Such User Not Found In BANK");
        box1(1,90,2,28);
        getch();
        AcMud();
    }
    else{
        printf("\n\n\n\t\tYour A/c E-Mail ID Changed Successfully.....");
        box1(1,90,2,28);
        getch();
        AcMud();
    }

}
////////////////////////////////////////////////////////END/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////Acc Transction/////////////////////////////////////////////////////////////////

void AcTcw(void)
{
    int ch;
    ///////////////////////////////////////////////////////////////////////
   ///////////////////////Matching For Security/////////////////////////////
   for(i=0;i<no;i++)
   {
       if(strcmp(C_un,AC[i].Uid)==0&&strcmp(C_pw,AC[i].Upw)==0)
       {
         f=i;
         break;
       }

   }
   ///////////////////////////////////////////////////////////////////////
   ///////////////////////////////////////////////////////////////////////
    while(1)
    {
        system("cls");
        system("color e0");
        printf("\n\n\n\t\t\t\t   %c A/c Online Transction %c",174,175);
        printf("\n\n\t\t1.Credit");
        printf("\n\t\t2.Debit");
        printf("\n\t\t3.%c BACK %c",174,174);
        printf("\n\t\tEnter Your Choice : ");
        box1(1,90,2,28);
        gotoxy(35,7);
        box(35,50,7,9);
        gotoxy(36,8);
        ch=integeronly();
        switch(ch)
        {
         case 1:
           Ac_bc();
           break;
         case 2:
           Ac_bw();
           break;
         case 3:
            USSA();
            break;
         default :
             printf("\n\t\tInvalid Choice.");
             printf("\n\t\tPlease Try Again......");
             box1(1,90,2,28);
             getch();
             AcTcw();
       }
    }
}
//////////////////////////////////////////////////Transction END/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////Credit Amount To Ac/////////////////////////////////////////////////////////////////
void Ac_bc()
{
    system("cls");
    system("color e0");
    Ac();
    getch();
}
///////////////////////////////////////////////////END////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Ac()
{
    FILE *fp;
    char An[11],N[25],Fc[12];
    int d=0;
    float add;
    GetSystemTime(&t);
    ///////////////////////////////////////////////
    printf("\n\n\n\n\t\tEnter A/c No      : ");
    box1(1,90,2,28);
    gotoxy(36,3);
    box(36,55,3,5);
    gotoxy(37,4);
    char_Donly(&An,11);
    printf("\n\n\n\t\tA/c Holder's Name : ");
    box1(1,90,2,28);
    gotoxy(36,6);
    box(36,55,6,8);
    gotoxy(37,7);
    charonly(&N);
    //////////////////////////////////////////////
    printf("\n\n\n\t\tIFSC Code         : ");
    box1(1,90,2,28);
    gotoxy(36,9);
    box(36,55,9,11);
    gotoxy(37,10);
    Panonly(&Fc,11);
    ////////////////////////////////////////////////
    fp=fopen("Acuser.dat","rb+");
    if(fp==NULL)
    {
        printf("\n\t\tFile cannot open");
        box1(1,90,2,28);
        getch();
        AcTcw();
    }


    fseek(fp,0,SEEK_SET);
    while(fread(&Au,recsize,1,fp)>0)
    {
        n=0;
         for(i=0;i<11;i++)
             {
                if(An[i]==Au.Acn[i])
                    n++;
             }

        if(n==11)
        {
           d=1;
           if(strcmp(Au.Ahn,N)==0)
                {
                   if(strcmp(AC[f].Ahn,N)==0){
                     if(strcmp(Au.Ifsc,Fc)==0)
                      {
                        printf("\n\n\n\t\tAdd Amount        : ");
                        box1(1,90,2,28);
                        gotoxy(36,12);
                        box(36,55,12,14);
                        gotoxy(37,13);
                        add=(float)integeronly();
                        ////////////////////////////////////////////

                       if(add>=100.0)
                        {
                           d=1;
                           Au.T_Amt=Au.T_Amt+add;
                           ////////////////////////////////////
                          if(Au.reset>=1&&Au.reset<=7)
                          {
                               Au.st[Au.reset-1].sd.d=t.wDay;
                               Au.st[Au.reset-1].sd.m=t.wMonth;
                               Au.st[Au.reset-1].sd.y=t.wYear;
                               ///////////////////////////////
                                Au.st[Au.reset-1].A=Au.T_Amt;
                                Au.st[Au.reset-1].Cs=add;
                                Au.st[Au.reset-1].ai=1;
                          }
                           if(Au.reset<=7)
                             Au.reset++;
                           else if(Au.reset>7)
                           {
                             Au.reset=1;
                             Au.st[Au.reset-1].sd.d=t.wDay;
                               Au.st[Au.reset-1].sd.m=t.wMonth;
                               Au.st[Au.reset-1].sd.y=t.wYear;
                               ///////////////////////////////
                                Au.st[Au.reset-1].A=Au.T_Amt;
                                Au.st[Au.reset-1].Cs=add;
                                Au.st[Au.reset-1].ai=1;
                                Au.reset++;
                           }

                           /////////////////////////////////////
                           fseek(fp,-recsize,SEEK_CUR);
                           fwrite(&Au,recsize,1,fp);
                           break;
                        }
                       else
                        {
                         printf("\n\n\n\t\tPlease Add Minimum Amount 100 Rs Only");
                         box1(1,90,2,28);
                         getch();
                          fclose(fp);
                          AcTcw();
                        }
                     }
                      else
                        d=0;
                   }
                   else
                   {
                       printf("\n\n\t\tInvalid : Your A/c Details");
                        box1(1,90,2,28);
                       getch();
                       fclose(fp);
                       AcTcw();
                   }

                }
                else
                    d=0;
        }
        else
          d=0;

    }
    fclose(fp);

    if(d==0){
        printf("\n\n\t\tInvalid Detail : Such User Not Found In BANK");
        box1(1,90,2,28);
        getch();
        AcTcw();
    }
    else{
        printf("\n\n\n\t\tA/c XX%c%c%c%c Credited With Rs. %f Successfully.....",Au.Acn[7],Au.Acn[8],Au.Acn[9],Au.Acn[10],add);
        box1(1,90,2,28);
        getch();
        AcTcw();
    }

}
////////////////////////////////////////////////////////////////END////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////Debit Amount To Ac///////////////////////////////////////////////////////////////////////////////////////
void Ac_bw()
{
    system("cls");
    system("color e0");
    Ad();
    getch();
}
//////////////////////////////////////////////////////END//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Ad()
{
    FILE *fp;
    char An[11],N[25],Fc[12];
    int d=0;
    float add;
    ///////////////////////////////////////////////
    printf("\n\n\n\n\t\tEnter A/c No      : ");
    box1(1,90,2,28);
    gotoxy(36,3);
    box(36,55,3,5);
    gotoxy(37,4);
    char_Donly(&An,11);
    printf("\n\n\n\t\tA/c Holder's Name : ");
    box1(1,90,2,28);
    gotoxy(36,6);
    box(36,55,6,8);
    gotoxy(37,7);
    charonly(&N);
    //////////////////////////////////////////////
    printf("\n\n\n\t\tIFSC Code         : ");
    box1(1,90,2,28);
    gotoxy(36,9);
    box(36,55,9,11);
    gotoxy(37,10);
    Panonly(&Fc,11);
    ////////////////////////////////////////////////

    fp=fopen("Acuser.dat","rb+");
    if(fp==NULL)
    {
        printf("\n\t\tFile cannot open");
        box1(1,90,2,28);
        getch();
        AcTcw();
    }


    fseek(fp,0,SEEK_SET);
    while(fread(&Au,recsize,1,fp)>0)
    {
        n=0;
         for(i=0;i<11;i++)
             {
                if(An[i]==Au.Acn[i])
                    n++;
             }

        if(n==11)
        {
           d=1;
           if(strcmp(Au.Ahn,N)==0)
                {
                    if(strcmp(AC[f].Ahn,N)==0){
                     if(strcmp(Au.Ifsc,Fc)==0)
                      {
                        printf("\n\n\n\t\tWithdrawal Amount : ");
                        box1(1,90,2,28);
                        gotoxy(36,12);
                        box(36,55,12,14);
                        gotoxy(37,13);
                        add=(float)integeronly();
                        ////////////////////////////////////////////


                         if(add>=100.0)
                           {
                             if((Au.T_Amt-add)>0.0)
                             {
                               f=1;
                               Au.T_Amt=Au.T_Amt-add;
                               //////////////////////////////////////////
                                if(Au.reset>=1&&Au.reset<=7)
                                 {
                                  Au.st[Au.reset-1].sd.d=t.wDay;
                                  Au.st[Au.reset-1].sd.m=t.wMonth;
                                  Au.st[Au.reset-1].sd.y=t.wYear;
                                  ///////////////////////////////
                                  Au.st[Au.reset-1].A=Au.T_Amt;
                                  Au.st[Au.reset-1].Ds=add;
                                  Au.st[Au.reset-1].ai=-1;
                                }
                                if(Au.reset<=7)
                                   Au.reset++;
                                else if(Au.reset>7)
                                {
                                 Au.reset=1;
                                 Au.st[Au.reset-1].sd.d=t.wDay;
                                  Au.st[Au.reset-1].sd.m=t.wMonth;
                                  Au.st[Au.reset-1].sd.y=t.wYear;
                                  ///////////////////////////////
                                  Au.st[Au.reset-1].A=Au.T_Amt;
                                  Au.st[Au.reset-1].Ds=add;
                                  Au.st[Au.reset-1].ai=-1;
                                  Au.reset++;
                                }

                               ///////////////////////////////////////////
                               fseek(fp,-recsize,SEEK_CUR);
                               fwrite(&Au,recsize,1,fp);
                               break;
                              }
                             else
                             {
                               printf("\n\n\n\t\tYour Money Has Not Been Debited");
                               printf("\n\t\tYour Account Has Insufficient Funds.");
                               box1(1,90,2,28);
                               getch();
                               AcTcw();
                             }

                           }
                         else
                         {
                           printf("\n\n\n\t\tPlease withdrawal Minimum Amount 100 Rs Only");
                           box1(1,90,2,28);
                           getch();
                           AcTcw();
                         }
                      }
                      else
                         d=0;
                    }
                    else
                    {
                        printf("\n\n\t\tInvalid : Your A/c Details");
                        box1(1,90,2,28);
                       getch();
                       fclose(fp);
                       AcTcw();
                    }
                }
                else
                    d=0;
        }
        else
          d=0;

    }
    fclose(fp);

    if(d==0){
        printf("\n\n\t\tInvalid Detail : Such User Not Found In BANK");
        box1(1,90,2,28);
        getch();
        AcTcw();
    }
    else{
         printf("\n\n\n\t\tA/c XX%c%c%c%c Debited With Rs. %f Successfully.....",Au.Acn[7],Au.Acn[8],Au.Acn[9],Au.Acn[10],add);
         box1(1,90,2,28);
         getch();
         AcTcw();
    }

}
////////////////////////////////////////////////////////////////END////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////END  END END //////////////////////////////////////////////////////////////////////////
void del()
{
    FILE *ft,*fp;
    char An[11],N[25],Up[17],R[50];
    int d=0,pp,k=0,t=0,cn=0;
    gotoxy(6,5);
    ///////////////////////Matching For Security/////////////////////////////
   for(i=0;i<no;i++)
   {
       if(strcmp(C_un,AC[i].Uid)==0&&strcmp(C_pw,AC[i].Upw)==0)
       {
         f=i;
         break;
       }

   }
   ///////////////////////////////////////////////////////////////////////

    printf("Total SBI Account User : %d",tn);
    gotoxy(6,6);
    printf("\n\t\tEnter A/c No    : ");
    box1(1,90,2,28);
    box(35,55,6,8);
    gotoxy(36,7);
    char_Donly(&An,11);
    ////////////////////////////////
    printf("\n\n\n\t\tA/c Holder's Name : ");
    box1(1,90,2,28);
    gotoxy(36,9);
    box(36,55,9,11);
    gotoxy(37,10);
    charonly(&N);
    //////////////////////////////////////////////
    printf("\n\n\n\t\tA/c Password      : ");
    box1(1,90,2,28);
    gotoxy(36,12);
    box(36,55,12,14);
    gotoxy(37,13);


    i=0;
    do
    {
        pp=getch();
      if(pp==BKSP&&i>0)
        {
           i--;
           printf("\b");
           printf(" ");
           printf("\b");
        }

      if(pp!=SPACE&&pp!=ENTER&&pp!=BKSP)
        {
           printf("%c",'*');
           Up[i]=pp;
           i++;
        }
       if(pp==ENTER&&i>0)
        {
          Up[i]='\0';
          break;
        }

    }while(1);

    //////////////////////////////////////////////////////////
    printf("\n\n\n\t\tReason            : ");
    box1(1,90,2,28);
    gotoxy(36,15);
    box(36,62,15,17);
    gotoxy(37,16);
    charonly(&R);
    /////////////////////////////////////////////////////////
     cn=0;
         for(i=0;i<11;i++)
             {
                if(An[i]==AC[f].Acn[i])
                    cn++;
             }

    //////////////////////////////////////////////////////////
    fp=fopen("Acuser.dat","rb");
    ft=fopen("Temp.dat","ab");
    ////////////////////////////////////////

    fseek(fp,0,SEEK_SET);
    while(fread(&Au,recsize,1,fp)>0)
    {
        n=0;
         for(i=0;i<11;i++)
             {
                if(An[i]==Au.Acn[i])
                    n++;
             }

        if(n==11&&cn==11)
        {
           if(strcmp(Au.Ahn,N)==0)
           {
               if(strcmp(Au.Upw,Up)==0)
               {
                   k=1;
                   d=1;
                   t=1;
               }
               else
               {
                   printf("\n\n\t\tInvalid : Password");
                   box1(1,90,2,28);
                   fclose(fp);
                   fclose(ft);
                   getch();
                   remove("Temp.dat");
                   USSA();
               }
           }
           else
               d=0;
        }
        else
            d=0;

        if(k!=1)
            fwrite(&Au,recsize,1,ft);
        else
           k=0;

    }
    fclose(fp);
    fclose(ft);
    //////////////////////////////////
    if(t==1){
    remove("Acuser.dat");
    rename("Temp.dat","Acuser.dat");
    }
    else if(t==0&&d==0)
    {
      remove("Temp.dat");
    }
    //////////////////////////////////////
    if(t==0){
        printf("\n\n\t\tSuch Account User Not Found In BANK");
        box1(1,90,2,28);
        getch();
        USSA();
    }
    else if(t==1){
        tn--;
        printf("\n\n\n\t\t\tAccount Permanently Deleted Successfully.....");
        box1(1,90,2,28);
        getch();
        USSA();
     }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void s()
{
   for(i=0;i<=(AC[f].reset-2);i++)
   {
       gotoxy(15,19+i);
       if(AC[f].st[i].ai==1)
       printf("%d/%d/%d\t+%-5f\t\t%-5f",AC[f].st[i].sd.d,AC[f].st[i].sd.m,AC[f].st[i].sd.y,AC[f].st[i].Cs,AC[f].st[i].A);
       else if(AC[f].st[i].ai==-1)
       printf("%d/%d/%d\t-%-5f\t\t%-5f",AC[f].st[i].sd.d,AC[f].st[i].sd.m,AC[f].st[i].sd.y,AC[f].st[i].Ds,AC[f].st[i].A);
   }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////END Bank Programme///////////////////////////////////////////////////////////
