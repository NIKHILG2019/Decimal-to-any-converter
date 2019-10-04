#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define STACKSIZE 100
int c;
int x;
int fflag=0;
int stack[STACKSIZE];
int queue[STACKSIZE];
float convert_Decimal_ToanyBase(int,float);
float hex_to_decimal();
float convert_anyBase_To_Decimal(int);
int delete_element();
void printhex(float);
void print(float);
void push();
void insert(int);
float hex_to_decimal();
int pop();
int top=-1;
int front=-1;
int rear=-1;
void push(int x)
{
    if(top==STACKSIZE-1)
    {
        printf("\n STACK OVERFLOW \n");
        exit(1);
    }
    else
    {
        stack[++top]=x;
    }
    
}
int pop()
{
    if(top==-1)
    {
        printf("\r STACK UNDERFLOW : \r ");
        exit(1);
    }
    else
    {
        return(stack[top--]);
    }
    
}
void printhex(float f)
{
    int i,n;
    while(top!=-1)
    {
        n=pop();
        char a;
        if(n>=10)
        n=n+55;
        a=n;
        if(n>=55)
        printf("%c",a);
        else
        printf("%d",n);
    }
    if(f!=0)
    {
    printf(".");
    for(i=0;i<6;i++)
    {
        n=delete_element();
        if(n>=10)
        n=n+55;
        char a;
        a=n;
        if(n>55)   
         printf("%c",a);
         else
        printf("%d",n);
    }
    }
    front=rear=-1;
    top=-1;
    getch();
    
}
void print(float f)
{
    int i;
    while(top!=-1)
    {
        printf("%d",pop());
    }
    printf(".");
    if(f!=0)
    {
    for(i=0;i<6;i++)
    {
        printf("%d",delete_element());

    }
    }
    front=rear=-1;
    top=-1;
}
float convert_Decimal_ToanyBase(int radix,float fraction )
{
    float multi,f;
    int integer,rem,i,integer1;
    integer=fraction;
    fraction=fraction-integer;
    while(integer>=radix)
    {
        rem=integer%radix;
        integer=integer/radix;
        push(rem);
    }
    push(integer);
    f=fraction;
    if(fraction!=0.0)
    {
        for(i=0;i<6;i++)
        {
            multi=fraction*radix;
            integer1=multi;
            fraction=multi-integer1;
            insert(integer1);

        }
    }
    if(radix==16)
    printhex(f);
    else
    print(f); 
}
void insert(int integer)
{
    if(rear==STACKSIZE-1)
    {
        printf("\n Queue OVERFLOW \n");
        exit(1);
    }
    else
    {
        if(front==-1 && rear==-1)
        {
            front=rear=0;
            queue[front]=integer;
        }
        else
        {
            queue[++rear]=integer;
        }
        
    }
    
}
int delete_element()
{
    if(rear==-1 && front==-1)
    {
        printf("\n Queue UNDERFLOW \n");
        exit(1);
    }
    else if(rear==front)
    {
        front--;
        return(queue[rear--]);
    }
    else
    {
        return(queue[front++]);
    }
}
float convert_anyBase_To_Decimal(int radix)
{
    int i,k,j,len,p=1,flag=0,count,n,sum=0;
    double sum1,sum2;
    char s1[50],s[50],s2[50];
    printf("Enter the string : ");
    gets(s);
    for(k=0;s[k]!='\0';k++)
    {
        if(s[k]=='.')
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
    for(i=0;s[i]!='.';i++)
    {
        s1[i]=s[i];
    }
    s1[i]='\0';
    for(i=++i,j=0;s[i]!='\0';i++,j++)
    {
        s2[j]=s[i];
    }
    s2[j]='\0';
    }
    else
    {
        strcpy(s1,s);
    }
    i=0;
    while(s1[i]!='\0')
    {
        if(s1[i]>='0'&& s1[i]<='7')
        {
            n=s1[i]-48;
            push(n);
            i++;
        }
        else
        {
            printf("\n YOUR INPUT DOES NOT SUPPORTS THE CURRENT NUMBER SYSTEM");
            getch();
            exit(1);

        }
    }
    count=0;
    while(top!=-1)
    {
        n=pow(radix,count)*pop();
        sum=sum+n;
        count++;
    }
    i=0;
    if(flag==1)
    {
    while(s2[i]!='\0')
    {
        if(s2[i]>='0'&& s2[i]<='9')
        {
            n=s2[i]-48;
            insert(n);
            i++;
        }
        else
        {
            printf("\n YOUR INPUT DOES NOT SUPPORTS THE CURRENT NUMBER SYSTEM");
            getch();
            exit(1);

        }
    }

    len=strlen(s2);
    count=0;
    i=-1;
    while(count!=len)
    {
        sum1=sum1+delete_element()*pow(radix,i);
        i--;
        count++;
    }
    }
    sum2=sum+sum1;
    front=rear=-1;
    top=-1;
    if(c!=5&&c!=6&&c!=8&&c!=9&&c!=10&&c!=11)
    {
    printf("%f",sum2);
    return(-1);
    }
    else
    {
        return sum2;
    }
}
float hex_to_decimal()
{
    int i,k,j,len,p=1,flag=0;
    float pf=1,sum2=0,sum=0,sum1=0;
    char s1[50],s[50],s2[50];
    printf("Enter the string : ");
    scanf("%s",s);
    strupr(s);
    for(k=0;s[k]!='\0';k++)
    {
        if(s[k]=='.')
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
    for(i=0;s[i]!='.';i++)
    {
        s1[i]=s[i];
    }
    s1[i]='\0';
    for(i=++i,j=0;s[i]!='\0';i++,j++)
    {
        s2[j]=s[i];
    }
    s2[j]='\0';
    }
    else
    {
        strcpy(s1,s);
    }
    len=strlen(s1);
            for(i=len-1;i>=0;i--)
            {
                if(s1[i]>='0'&& s1[i]<='9')
                {
                    sum1=sum1+(s1[i]-48)*p;
                    p=p*16;
                }
                else if(s1[i]>='A'&&s1[i]<='F')
                {
                    sum1=sum1+(s1[i]-55)*p;
                    p=p*16;
                    
                }
                else
                {
                   printf("\n YOUR INPUT DOES NOT SUPPORTS THE CURRENT NUMBER SYSTEM");
                    getch();
                    exit(1);
                }
            }
            if(flag==1)
            {
            len=strlen(s2);
            pf=pf*pow(16,-1);
            for(i=len-1;i>=0;i--)
            {
                if(s2[i]>='0'&& s2[i]<='9')
                {
                    sum2=sum2+(s2[i]-48)*pf;
                    pf=pf*pow(16,-1);
                }
                else if(s2[i]>='A'&&s2[i]<='F')
                {
                    sum2=sum2+(s2[i]-55)*pf;
                    pf=pf*pow(16,-1);
                    
                }
                else
                {
                   printf("\n YOUR INPUT DOES NOT SUPPORTS THE CURRENT NUMBER SYSTEM");
                    getch();
                    exit(1);
                
                }
            }
        sum=sum1+sum2;
        if(c!=10&&c!=11)
        {
        printf("\n%f",sum);
        return(-1);
        }
        return(sum);
        }
        else
        {   if(c!=10&&c!=11)
            {
            printf("%f",sum1);
            return(-1);
            }
            return(sum1);
        }
}
void main()
{
    float gf,no;
    printf("\n\n");
    printf("\n");
    printf("\t\t\t\t\tPRESS ENTER TO EXECUTE\" CALBIN \"\t");
    do
    {
        getch();
        system("cls");
    printf("\t*****************************CALBIN*****************************\n");
    printf("\n\n");
    printf("\t1>Decimal to binary\t\t");
    printf("\t2>Decimal to octal\n");
    printf("\t3>Decimal to hexadecimal\t");
    printf("\t4>Binary to decimal\n");
    printf("\t5>Binary to octal\t\t");
    printf("\t6>Binary to hexadecimal\n");
    printf("\t7>Octal to decimal\t\t");
    printf("\t8>Octal to binary\n");
    printf("\t9>Octal to hexadecimal\t\t");
    printf("\t10>Hexadeimal to binary\n");
    printf("\t11>Hexadeimal to octal\t\t");
    printf("\t12>Hexadeimal to decimal\n");
    printf("\tENTER ANY OTHEN NUMBER TO EXIT\t\t");
    printf("\n\t");
    printf("PLEASE SELECT YOUR OPERATION : ");
    scanf("%d",&c);
    getchar();
        switch(c)
        {
            case 1 :
                printf("\n Enter the number in decimal : ");
                scanf("%f",&gf);
                no=convert_Decimal_ToanyBase(2,gf);
                break;
            case 2 :
                printf("\n Enter the number in decimal : ");
                scanf("%f",&gf);
                no=convert_Decimal_ToanyBase(8,gf);
                break;
            case 3 :
                printf("\n Enter the number in decimal : ");
                scanf("%f",&gf);
                no=convert_Decimal_ToanyBase(16,gf);
                break;
            case 4 :
                convert_anyBase_To_Decimal(2);
                break;
            case 5 :
                no=convert_anyBase_To_Decimal(2);
                no=convert_Decimal_ToanyBase(8,no);
                break;
            case 6 :
                no=convert_anyBase_To_Decimal(2);
                no=convert_Decimal_ToanyBase(16,no);
                break;
            case 7 :
                convert_anyBase_To_Decimal(8);
                break;
            case 8 :
                no=convert_anyBase_To_Decimal(8);
                no=convert_Decimal_ToanyBase(2,no);
                break;
            case 9 :
                no=convert_anyBase_To_Decimal(8);
                no=convert_Decimal_ToanyBase(16,no);
                break;
            case 10 :
                no=hex_to_decimal();
                no=convert_Decimal_ToanyBase(2,no);
                break;
            case 11 :
                no=hex_to_decimal();
                no=convert_Decimal_ToanyBase(8,no);
                break;
            case 12 :
                hex_to_decimal();
                break;
            default : 
                c=100;
                break;
        }
    }while(c!=100);
    getch();    
}