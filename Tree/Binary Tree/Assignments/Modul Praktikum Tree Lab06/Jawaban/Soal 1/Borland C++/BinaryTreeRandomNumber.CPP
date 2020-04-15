#include <iostream> //import library io stream untuk standard input/output
#include <stdlib.h> //import libary untuk menggunakan fungsi system() dan rand()
#include <conio.h>
#include <String>

//definisikan struct yang digunakan sebagai elemen dari binary tree
struct Node {
	int data; //definisikan member data untuk menyimpan data elemen
	Node* left; //definiskan variable untuk menampung data left
	Node* right; //definiskan variable untuk menampung data right
};

//definisikan fungsi untuk membuat elemen baru
Node* newNodee(int data);
//definsikan fungsi untuk menambahkan elemen ke dalam tree
Node* insert(Node* node, int data);
//buat variable untuk menampung posisi terakhir dimana data disimpan
string position = "ROOT";
//buat variable untuk menampung parent data yang baru dimasukan
int parent;

int main() {
	//definisikan root dari tree sebagai null berarti belum ada root
	Node* root = NULL;
	//baut variable untuk melakukan iterasi untuk menyimpan 10 data ke dalam tree
	int i = 1;

	//lakukan perulangan do while
	//kenapa do while karena gw suka aja
	do {
		//definisikan variable dat untuk menampung angka random dari 1 - 99
		int data = rand() % 100;
			
		//lakukan fungsi rekursif untuk menambahkan data ke dalam tree
		//parameternya adalah node/elemen pada tree pada pemanggilan awal yang dimasukan adalah root dari tree
		//data adalah data inputan yang ingin dijadikan sebagai elemen dari tree
		root = insert(root, data);

		//jika elemen dimasukan pada posisi root
		if (position == "ROOT") {
			//maka print bahwa elemen dimasukan ke dalam posisi root
			cout << data << ": ditempatkan sebagai ROOT\n";
		}
		else {
			//jika elemen yang dimasukan tidak di posisi root print posisinya dan juga parent dari element yang dimasukan
			cout << data << ": ditempatkan sebagai " << position << " " << parent << "\n";
		}

		i++;
		//selama i lebih kecil atau sama dengan 10
	} while (i <= 10);

   getch();
	return 0;
}

//fungsi untuk membuat node/elemen tree
Node* newNodee(int data)
{
	//alokasi kan memori dinamis
	Node* temp = (Node*)malloc(sizeof(Node));
	//masukan data
	temp->data = data;
	//set left dan right menjadi null
	temp->left = temp->right = NULL;
	//return node/elemen yang terbuat
	return temp;
}

Node* insert(Node* node, int data)
{
	//jika node yang dimasukan adalah null
	if (node == NULL) {
		//maka buat elemen/node dengan fungsi newNodee dan return node yang terbuat
		return newNodee(data);
	}

	//cek apakah data yang dimasukan lebih kecil atau sama dari data pada elemen/node saat ini
	if (data <= node->data) {
		//jika iya maka posisikan data ke left elemen
		position = "LEFT";
		//simpan isi data parent
		parent = node->data;
		//lalu panggil kembali fungsi insert dan arahkan ke elemen sebelah kiri/ node->left
		//eksekusi akan kembali ke bagian awal fungsi insert kembali
		node->left = insert(node->left, data);
	}
	else {
		//jika iya maka posisikan data ke right elemen
		position = "RIGHT";
		//simpan isi data parent
		parent = node->data;
		//lalu panggil kembali fungsi insert dan arahkan ke elemen sebelah kanan/ node->right
		//eksekusi akan kembali ke bagian awal fungsi insert kembali
		node->right = insert(node->right, data);
	}

	//setelah data baru dimasukan ke dalam tree return tiap elemen di atasnya untuk menjaga struktur tree
	return node;
}
