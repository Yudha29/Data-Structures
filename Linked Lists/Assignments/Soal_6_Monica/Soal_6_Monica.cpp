#include <iostream> //standar library untuk input/output
#include <stdio.h> 
#include <stdlib.h> //standar library untuk gunakan system() dll
#include <string.h> //standar library untuk gunakan strcpy, strlen, agak mager nyebutinnya
#include <conio.h> //yang pasti getch()

using namespace std;

struct Simpul {
	char dat[10];
	struct Simpul *next;
	struct Simpul * prev;
};

/*
 * temp: untuk menyimpan data yang di input
 * head: mengacu ke elemen pertama dalam linked list
 * ptr: digunakan untuk traverse/menjelajahi tiap element linked list
 * tail: mengacu ke elemen terakhir dalma linked list
*/
struct Simpul *temp,*head=NULL,*ptr=NULL, *tail = NULL;

main()
{
	char masukan[10], cari[10];	
	int a;

	//perulangan do while ini tidak memiliki dampak apapun pada program sehingga tidak diperlukan
	do {
		cout<<"\nEntry Serial Data";
		cout<<endl<<endl;
		
		/*
		 * for disini looping forever karen kondisi ga akan pernah salah
		 * yang digunakan pada for ini hanya variable a nya untuk memberikan urutan seperti data ke a
		*/
		for (a=1;strlen(masukan)>0;a++) {
			//meminta masukan data dari user
			cout<<"Data ke "<<a<<":";gets(masukan);
   			if(strlen(masukan)>0)
   			{
   				//for disini juga tidak di diperlukan
         		for(int i=strlen(masukan);i<10;i++)
            		masukan;

				//mengalokasikan memori untuk menampung data yang akan di input
         		temp=(struct Simpul *)malloc(sizeof(struct Simpul));

				//mengcopy data yang user masukan ke dalam simpul->data/node->data
            	strcpy(temp->dat,masukan);

				//jika belum ada data yang dimasukan ke linked list
				//maka masukan sebagai head/data pertama
            	if (head==NULL) {
            		//menjadikan data yang di input sebagi head/data pertama
            		head=temp;
            		
            		/*
					 * saat ini kamu hanya punya element pertama
					 * pada double linked list kamu punay prev dan next
					 * prev mengacu ke element sebelumnya
					 * next ke element selanjutnya
					 * namun kamu hanya punya satu element, maka prev dari element saat ini adalah NULL karena tidak ada elemen lain sebelum elemen pertama
					 * dan nextnya juga null karena kamu hanya punya satu elemen
            		*/
            		head->next = NULL;
            		head->prev = NULL;
            		
            		/*
					 * dan buat tail = head karena saat ini kamu hanya punya satu elemen sehingga keduanya mengacu ke satu element itu
					 * kamu akan memerlukan tail untuk mencatat dimana data yang paling akhir
					*/
            		tail=head;
            	} else {
            		/*
					 * jika sudah ada element pertama dan kamu ingin menambahkan element baru
					 * maka gunakan tail yang mengacu ke elemen terakhir dalam linked list
					 * lalu setelah tail->next = temp maka tail bukan lagi elemen terakhir namun ke dua terakhir
					 * lalu set prev dari element yang kamu buat ke tail
					 * dan ubah tail menjadi data paling terakhir dengan tail = tail->next
					*/
               		tail->next=temp;
               		temp->prev = tail;
               		temp->next = NULL;
            		tail=tail->next;
               	}
      		}
   		}
	} while(strlen(masukan)>0);

	cout<<"\nJumlah data "<<(a-2);

	cout<<endl<<endl;
	cout<<"List data cetak maju:"<<endl;
	
	/*
	 * sebelum print harus cek dulu apakah linked listnya memiliki elemen atau tidak
	 * jika linked listnya tidak punya head maka berarti itu kosong
	*/
	if(head!=NULL) {
		/*
		 * karena kamu akan print element dari elemen pertama ke terakhir
		 * maka posisi ptr harus diubah menjadi head/elemen pertama
		*/
		ptr=head;
		
		/*
		 * lakukan perulangan untuk print satu persatu datanya
		 * untuk print dari pertama ke terakhir
		*/
   		do {
   			//print seluruh datanya
   			cout<<"["<<ptr->dat<<"]--> alamat Ptr ["<<ptr<<"] --> Prev Ptr ["<<ptr->prev<<"] --> Next Ptr ["<<ptr->next<<"]"<<endl;
   			ptr=ptr->next;
   			
   			/*
			 * kondisi untuk cek apakah ptr != NULL
			*/
  		} while(ptr!=NULL);
  		
  		cout<<endl<<endl;
		cout<<"List data cetak mundur:"<<endl;
		
		/*
		 * karena kamu akan print element dari elemen terakhir ke pertama
		 * maka posisi ptr harus diubah menjadi tail/elemen terakhir
		*/
		
		ptr = tail;
  		/*
		 * lakukan perulangan untuk print satu persatu datanya
		 * untuk print dari terakhir ke pertama
		*/
  		do {
   			//print seluruh datanya
   			cout<<"["<<ptr->dat<<"]--> alamat Ptr ["<<ptr<<"] --> Prev Ptr ["<<ptr->prev<<"] --> Next Ptr ["<<ptr->next<<"]"<<endl;
   			//karena kamu akan print dari bawah ke atas kamu akan menggeser nilai dari ptr ke nilai sebelumnya
   			ptr=ptr->prev;

  		} while(ptr!=NULL);
	}

	getch();
}
