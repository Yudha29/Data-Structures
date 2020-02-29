#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Simpul
{
char dat[10];
struct Simpul *next;
};

struct Simpul *temp,*head=NULL,*ptr=NULL,*prevptr=NULL;

main()
{

char masukan[10];
int a;
char cari[10];
char sisip[10];

do
{
cout<<"\nEntry Serial Data";
cout<<endl<<endl;

	for (a=1;strlen(masukan)>0;a++)
   {
	cout<<"Data ke "<<a<<":";gets(masukan);
   	if(strlen(masukan)>0)
   	{
         	for(int i=strlen(masukan);i<10;i++)
            masukan;

         	temp=(struct Simpul *)malloc(sizeof(struct Simpul));

            strcpy(temp->dat,masukan);
            temp->next = NULL;

            if (head==NULL)
            {
            head=temp;
            ptr=head;
            }
            	else
               {
               ptr->next=temp;
               ptr=ptr->next;
               }
      }

   }
}while(strlen(masukan)>0);

cout<<"\nJumlah data "<<(a-2);

cout<<endl<<endl;
cout<<"List Data:"<<endl;
if(head!=NULL)
{
	ptr=head;
   do
   {
   cout<<"["<<ptr->dat<<"] --> alamat Ptr ["<<ptr<<"] --> Next Ptr ["<<ptr->next<<"]"<<endl;
   ptr=ptr->next;
   }while(ptr!=NULL);
}

do
{
	ptr=head;
	prevptr = NULL;
	cout<<"\nData yang anda cari: ";gets(cari);
	while((strcmp(cari,ptr->dat)!=0) && (ptr!=NULL))
   	{
   		prevptr = ptr;
   		ptr=ptr->next;
   	};

	if((strcmp(cari,ptr->dat)==0) && (ptr!=NULL))
		{
         if(ptr==head)
         {
         head=ptr->next;
         delete ptr;
         ptr = head;
         }
        else
        {
           prevptr->next=ptr->next;
           
           delete ptr;
           
           ptr = prevptr->next;
        }
            
        
    
        
      }

      else
      {
      cout<<"Data tidak ditemukan";
      }
cout<<endl;
cout<<"List Data:"<<endl;
if(head!=NULL)
{
	ptr=head;
   do
   {
   cout<<"["<<ptr->dat<<"] --> alamat Ptr ["<<ptr<<"] --> Next Ptr ["<<ptr->next<<"]"<<endl;
   ptr=ptr->next;
   }while(ptr!=NULL);
}
}while(strlen(cari)>0);

}
