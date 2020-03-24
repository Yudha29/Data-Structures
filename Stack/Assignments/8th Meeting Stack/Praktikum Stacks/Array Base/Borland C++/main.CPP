#include <iostream.h>
#include <stdlib.h>

const int maxSize = 20; //max element yang bisa ditampung oleh stack
int stack[maxSize]; //buat array yang akan dijadikan stack
int index = 0; //variable yang digunakan untuk menyimpan index di posisi setelah elemen teratas
int size = 0; //variable yang menyatakan jumlah element pada stack

//isEmpty() digunakan untuk cek apakah stack kosong atau tidak
bool isEmpty() {
	//jika sizenya 0 maka return true berarti benar stack kosong
	if (size == 0)
		return true;

	//jika tidak return false berarti stack tidak kosong
	return false;
}

//isFull() untuk mengecek apakah stack penuh atau tidak
bool isFull() {
	//jika jumlah element stack telah sama dengan jumlah maximum element yang dapat ditampung
	//maka return true berarti benar (stack penuh)
	if (size == maxSize)
		return true;
	
	//jika tidak berarti salah (stack tidak penuh)
	return false;
}

//peek() digunakan untuk mendapat element paling atas pada stack tanpa menghapus
int peek() {
	//karena index menunjuk posisi setelah element teratas maka harus dikurangi satu agar menunjuk elemen terakhir
	return stack[index - 1];
}

//pop() digunakan untuk mengeluarkan dan menghapus data teratas
int pop() {
	//keluarkan element teratas
	int temp = stack[index - 1];
	
	index--; //buat index untuk mengacu ke element sebelumnya
	size--; //kurangi jumlah size dari index
	
	//return data teratas sebelum terjadi penghapusan pada stack
	return temp;
}

//push() digunakan untuk memasukan data sebagai element teratas pada stack
void push(int element) {
	//index mengacu ke sel array setelah element teratas pada stack
	//jadi stack[index] mengacu ke sel array setelah data teratas
	stack[index] = element;
	
	index++;
	size++; //naikan jumlah elemen pada stack
}

//print() digunakan untuk memprint semua data pada stack
//PERHATIAN : fungsi ini menggunakan algoritma rekursif
void print() {
	//pop element teratas dalam linked list
	//size akan berkurang satu tiap kali pop()
	int temp = pop();
	
	//print datanya
	cout << "|\t" << temp << "\t|" << '\n';
	
	//jika sizenya tidak 0 atau stack belum kosong
	if (!isEmpty())
		//jalankan kembali prosedur ini
		print();

	//lalu push kembali data yang dikeluarkan ke dalam stack
	push(temp);
}

//clear digunakan untuk menghapus seluruh isi dari stack
//PERHATIAN : fungsi ini menggunakan algoritma rekursif
void clear() {
	//jika stack tidak kosong
	if (!isEmpty()) {
		//keluarkan ini nya
		pop();
		
		//panggil kembali fungsi ini clear()
		clear();
	}
}

//pushToStack() digunakan untuk meminta inputan untuk menginput isi dari stack
void pushToStack() {
	//print pesan
	cout << "Input Data, Untuk mengakhiri isi 0 \n";

	//buat variable tempData untuk menyimpan data inputan
	//variable i untuk no inputan ke berapa
	int tempData, i = 1;
	do {
		cout << "Input Data ke " << i << " :";
		cin >> tempData;
		
		if (!isFull() && tempData != 0) {
			//jika stack tidak kosong dan tempData tidak sama dengan 0
			//maka masukan data ke stack
			push(tempData);
		} else if (tempData == 0) {
			//jika tempData == 0  berarti keluar dari sesi input
			break;
		} else {
			//jika tidak maka kemungkinan terakhir stacknya penuh
			cout << "Stack penuh\n";
		}

		i++;
	} while (true);
}

//printMenu() digunakan untuk print menu
void printMenu() {
	cout << "Menu\n";
	cout << "1. Tambah data ke stacks\n";
	cout << "2. Keluarkan data dari stacks\n";
	cout << "3. Tampilkan data teratas dari stacks\n";
	cout << "4. Bersihkan stacks\n";
	cout << "5. Check stacks apakah stacks kosong\n";
	cout << "6. Tampilkan isi stack\n";
	cout << "0. Keluar\n";
}

int main() {
	do {
		system("cls");
		//print menu
		printMenu();
	
		//variable untuk menampung data inputan
		int selected;
		
		//print dan masukan inputan
		cout << "Pilihan anda : ";
		cin >> selected;
	
		//cek inputan
		switch (selected)
		{
		case 1:
			//jika pilih 1 maka eksekusi pushToStack untuk memasukan data ke stack
			pushToStack();
			break;
		case 2:
			//jika pilih 2 maka eksekusi pop() untuk mengeluarkan dan hapus data teratas
			cout << "Data yang di pop : " << pop() << "\n";
			break;
		case 3:
			//jika pilih 3 maka eksekusi peek() untuk mendapatkan data teratas pada stack
			cout << "Data pada top stack : " << peek() << "\n";
			break;
		case 4:
			//jika pilih 4 maka hapus seluruh data pada stack
			clear();
			cout << "Stack telah dibersihkan\n";
			break;
		case 5:
			//pilih 5 cek apakah stack kosong
			if (isEmpty())
				cout << "Stack kosong\n";
			else
				cout << "Stack tidak kosong\n";
			break;
		case 6:
			//jika pilih 6 maka cek apakah stack kosong
			cout << "Isi stack : \n";
			if (!isEmpty())
				//jika tidak maka eksekusi fungsi print() untuk print semua isi stack
				print();
			else
				//jika kosong maka kirimkan pesan stack kosong
				cout << "Stack kosong\n";
			break;
		case 0:
			//jika pilih 0 maka keluar dari program
			exit(0);
			break;
		}
		system("pause");
		
	} while (true);

	return 0;
}
