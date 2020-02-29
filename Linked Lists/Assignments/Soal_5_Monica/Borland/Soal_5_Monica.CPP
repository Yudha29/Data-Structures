#include <iostream.h> //standar library untuk input/output
#include <stdio.h> 
#include <stdlib.h> //standar library untuk gunakan system() dll
#include <string> //standar library untuk gunakan strcpy, strlen, agak mager nyebutinnya
#include <conio.h> //yang pasti getch()

struct Simpul {
	char dat[10];
	struct Simpul *next;
};

/*
 * temp: untuk menyimpan data yang di input
 * head: mengacu ke elemen pertama dalam linked list
 * ptr: digunakan untuk traverse/menjelajahi tiap element linked list
*/
struct Simpul *temp,*head=NULL,*ptr=NULL;

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
					 * pada circular linked list next pointer dari element paling akhir mengacu ke element pertama
					 * namun kamu hanya punya satu element, maka next dari element yang kamu punya akan mengacu ke dirinya sendiri
            		*/
            		head->next = head;
            		
            		/*
					 * buat ptr menyimpan alamat dari elemen pertama
					 * karena ketika kamu mau memasukan data selanjutnya
					 * kamu akan memerlukan ptr untuk mencatat dimana data yang paling akhir
					*/
            		ptr=head;
            	} else {
            		/*
					 * jika sudah ada element pertama dan kamu ingin menambahkan element baru
					 * maka gunakan ptr yang pada saat ini mengacu ke elemen terakhir dalam linked list
					*/
               		ptr->next=temp;
            		ptr=ptr->next;
            		
            		/*
					 * sekarang elemen yang baru telah di tambahkan sebagai element terakhir
					 * namun tugas belum selesai karena dalam circular linked list
					 * next pada element terakhir akan mengacu ke head/elemen pertama
					 * karena itu kita perlu set next elemen terakhir ke elemen pertama
					*/
					ptr->next = head;
               	}
      		}
   		}
	} while(strlen(masukan)>0);

	cout<<"\nJumlah data "<<(a-2);

	cout<<endl<<endl;
	cout<<"Hasil Entry Data:"<<endl;
	
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
		 * namun syarat pada perulangan nya harus di ubah
		 * karena pada circular linked list tidak ada data yang null
		 * data terakhir akan mengacu kembali ke head
		 * jika menggunakan syarat ptr != null maka akan menjadi looping forever
		*/
   		do {
   			//print seluruh datanya
   			cout<<"["<<ptr->dat<<"]--> alamat Ptr ["<<ptr<<"] --> Next Ptr ["<<ptr->next<<"]"<<endl;
   			ptr=ptr->next;
   			
   			/*
			 * ubah menjadi ptr != head jika menggunakan while do maka tidak bisa
			 * karena pada saat awal akan melakukan print ptr == head
			 * namun dengan do while tidak ada masalah karena ia akan melakukan perulangan 1x sebelum cek kondisi
			 * pada perulangan yang pertama itu data head akan di print
			 * dan melakukan perubahan ptr yang sebelumnya mengacu ke head menjadi mengacu ke data setelah head
			*/
  		} while(ptr!=head); //kondisi ini diubah
	}

	do {
		/*
		 * karena kamu akan mencari suatu element yang berisi data yang dicari
		 * maka kamu harus mencari mencocokan data yang kamu cari dengan tiap data yang ada di linked list
		 * maka posisi ptr harus diubah menjadi head/elemen pertama
		 * karena kamu harus mulai mencari dari data yang pertama ke terakhir
		*/
		ptr=head;
		cout<<"\nData yang anda cari: ";gets(cari);
		//lakakan pencarian dengan while selama data tidak ketemu maka geser posisi ptr ke simpul selanjutnya
		while(ptr != NULL && (strcmp(cari,ptr->dat)!=0)) {
			//tiap data tidak di temukan geser ptr ke posisi selanjutnya
   			ptr=ptr->next;
   			
   			/*
   			 * karena pada circular linked list elemen terakhir akan mengacu kembali ke head
   			 * setelah menggeser ptr ke posisi selanjutnya dan selanjutnya
   			 * hingga sampai di posisi element terakhir lalu kamu menggesernya lagi kamu akan kembali ke head
   			 * itu akan menciptakan looping forever
   			 * untuk itu kamu harus mengecek apakah ptr itu kembali lagi ke head
   			 * jka ia maka break dan keluar dari perulangan
   			 * menandakan bahwa data tidak ditemukan
   			*/
   			if (ptr == head) break;
   		};
   		
   		//cek lagi apakah data benar benar ditemukan
		if((ptr!=NULL) && (strcmp(cari,ptr->dat)==0)) {
			//jika iya maka print data yang ditemukan
			cout <<"\nData "<<cari<<" ada pada alamat "<<ptr << " #yey ketemu" << endl;
		} else {
			cout << "\nData yang anda cari tidak ditemukan. #hiks hiks" << endl;
		}
	} while(strlen(cari)>0);

	getch();
}