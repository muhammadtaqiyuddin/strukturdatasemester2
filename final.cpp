#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

int i,  jumlahmhs, jumlah, n,temp, nim[100],nimLinkedList;
float ipk;
string nama[100],nama_yang_dicari,namaLinkedList; 

void fungsi(int *jumlah,int *n){ 
	float ipk;
	ipk = (*jumlah) / (*n); 
	cout << ipk << endl; 
}

void input(){ 
	int n, jumlah , nilai[100]; 
    float ipk;
		cout << "Masukkan nama anda = " << endl; 
		cin >> namaLinkedList; 
		cout << "Masukkan nim anda = " << endl; 
		cin >> nimLinkedList; 
		cout << "inputkan banyak mata kuliah anda = " << endl; 
		cin >> n; 
		for (int i = 0; i < n; i++) 
		{
			cout << "Inputkan nilai mata kuliah ke " << i+1 << " = ";
			cin >> nilai[i]; 
			jumlah += nilai[i]; 
		}	
        cout << "========================" << endl;
		cout << "Jumlah nilai : "<< jumlah << endl;
		cout << "IPK : " ;	
		fungsi(&jumlah, &n); 
		cout << "========================" << endl;
       
}
struct Mahasiswa{
  string namaLinkedList;
  int nimLinkedList,jumlah;
  Mahasiswa *next;
};

Mahasiswa *head, *tail, *cur, *newNode, *del, *before;

int countSingleLinkedList(){
  cur = head;
  int jumlah = 0;
  while( cur != NULL ){
    jumlah++;
    cur = cur->next;
  }
  return jumlah;
}

void addFirst(string namaLinkedList, int nimLinkedList){

  newNode = new Mahasiswa();
  newNode->namaLinkedList = namaLinkedList;
  newNode->nimLinkedList = nimLinkedList;
  newNode->next = head;
  head = newNode;

  cout << "Data berhasil di tambahkan"<< endl;
}

void addLast(string namaLinkedList, int nimLinkedList){
	
  newNode = new Mahasiswa();
  newNode->namaLinkedList = namaLinkedList;
  newNode->nimLinkedList = nimLinkedList;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;

  cout << "Data berhasil di tambahkan"<< endl;
}

void removeFirst(){
  del = head;
  head = head->next;
  delete del;

  cout << "Data berhasil di hapus"<< endl;
}

void removeLast(){
  del = tail;
  cur = head;
  while( cur->next != tail ){
    cur = cur->next;
  }
  tail = cur;
  tail->next = NULL;
  delete del;

  cout << "Data berhasil di hapus"<< endl;
}

void changeFirst(string namaLinkedList, int nimLinkedList){
  head->namaLinkedList = namaLinkedList;
  head->nimLinkedList = nimLinkedList;

  cout << "Data berhasil di ubah"<< endl;
}

void changeLast(string namaLinkedList, int nimLinkedList){
  tail->namaLinkedList = namaLinkedList;
  tail->nimLinkedList = nimLinkedList;

  cout << "Data berhasil di ubah"<< endl;
}

void createSingleLinkedList(string namaLinkedList, int nimLinkedList){
  head = new Mahasiswa();
  head->namaLinkedList = namaLinkedList;
  head->nimLinkedList = nimLinkedList;
  head->next = NULL;
  tail = head;

  cout << "Data berhasil di tambahkan"<< endl;
}

void printSingleLinkedList(){
  cout << "Jumlah data ada : " << countSingleLinkedList() << endl;
  cur = head;
  while( cur != NULL ){
    cout << "nama Mahasiswa : " << cur->namaLinkedList << endl;
    cout << "nim Mahasiswa : " << cur->nimLinkedList << endl;
    cur = cur->next;
  }
}

struct tumpukan  
{
  char data[15][100], max[15];  
  int i, j;
} stack;

void push()  
{
  stack.i++;
  cout << "Masukan Data Mahasiswa : ";
  cin >> stack.max;
  strcpy (stack.data[stack.i], stack.max); 
  cout << "Data Mahasiswa Berhasil Ditambahkan";
}

void pop()  
{
  if (stack.i > 0)
  {
    cout << "Data yang terambil : " << stack.data[stack.i] << endl;
    stack.i--; stack.j--;
  }
  else
    cout << "Tidak ada data yang terambil" << endl;
}

void view (int n)  
{
  if (stack.j > 0)  
  {
    for (int e = n; e >= 1; e--)
    {
    cout << stack.data[e] << endl;
    }
  }
  else 
    cout << "tak ada data tersimpan" << endl; 
}

void clear()  
{
  stack.j = 0; stack.i = 0;  
}



void input ( int *jml_mhs){ 
	int n, jumlah , nilai[100], i; 

	for (int i = 0; i < jumlahmhs; i++) 
	{
		jumlah = 0;
		cout << "Inputkan Mahasiswa ke " << i+1 << endl; 
		cout << "Masukkan nama anda = " << endl; 
		cin >> nama[i]; 
		cout << "Masukkan nim anda = " << endl; 
		cin >> nim[i]; 
		cout << "inputkan banyak mata kuliah anda = " << endl; 
		cin >> n; 
		
		for (int i = 0; i < n; i++) 
		{
			cout << "Inputkan nilai mata kuliah ke " << i+1 << " = ";
			cin >> nilai[i]; 
			jumlah += nilai[i]; 
		}	
		cout << "========================" << endl;
        cout << "Jumlah nilai : "<< jumlah << endl;
        cout << "========================" << endl;
        cout << "========================" << endl;
        cout << "IPK : " ;  
        fungsi(&jumlah, &n); 
        cout << "========================" << endl;  
        cout << endl;
	}
}

void insertionSort() {
	int i, j, second;
	string temp2;

	for (i = 0; i < jumlahmhs; i++) {
		temp = *(nim+i);
		temp2 = *(nama+i);
		j = i-1; 

		while (*(nim+j) > temp && j >= 0)
		{
			*(nim+j+1) = *(nim+j);
			*(nama+j+1) = *(nama+j);
			j--;
		}
		second = j+1;
		*(nim+second) = temp;
		*(nama+second) = temp2;
	}
	cout<<"Data Berhasil Diurutkan Menggunakan Insertion Sort"<<endl;
}

void searching(){
	bool ketemu = false;
	int posisi;

	cout<<"Nama Mahasiswa yang Dicari : ";
	cin>>nama_yang_dicari;

	for(int i = 0; i < jumlahmhs; i++) {
		if(*(nama+i) == nama_yang_dicari) {
			ketemu = true;
			posisi = i;
			break;
		}
	}

	if(ketemu) {
		cout<<"Selamat nama yang anda cari :'"<<nama_yang_dicari<<"' ditemukan di posisi "<< posisi <<" indeks array"<<endl;
	} else {
		cout<<"Maaf nama yang anda cari tidak ditemukan"<<endl;
	}
}


int main ()
{
	int pil, n, pilihan;
	do
	{
		cout << "==============================" << endl; 
		cout << "    PROGRAM DATA MAHASISWA    " << endl; 
		cout << "==============================" << endl; 
		cout << "1. Input data mahasiswa,mencari nilai rata rata dan melakukan shorting\n2. View Data\n3. Searching\n4. Stack\n5. Linkedlist\n6. Exit" << endl;
		cout << "Masukkan pilihan : ";
		cin >> pilihan;
		switch (pilihan)
		{
		case 1 :
			cout << "Masukkan jumlah Mahasiswa = " << endl; 
			cin >> jumlahmhs; 
			input(&jumlahmhs);
			insertionSort();		
			for (int i = 0; i < jumlahmhs; i++) 
			{
				cout << "Nama Mahasiswa ke - " << i+1 << " = " << nama[i]<<endl;
				cout << "NIM Mahasiswa ke - " << i+1 << " = " << nim[i] << endl;
			}
			cout << "========================\n" << endl;
			break;
		case 2:	
			cout << "==============================" << endl; 
			cout << "      VIEW DATA MAHASISWA     " << endl; 
			cout << "==============================" << endl; 
			for (int i = 0; i < jumlahmhs; i++) 
			{
				cout << "Nama Mahasiswa ke - " << i+1 << " = " << nama[i]<<endl;
				cout << "NIM Mahasiswa ke - " << i+1 << " = " << nim[i] << endl;
			}
			break;
		case 3:
			cout << "==============================" << endl; 
			cout << "    SEARCH DATA MAHASISWA    " << endl; 
			cout << "==============================" << endl; 
			searching();
			break;
		case 4:
			cout<<"------------------------------------------"<<endl;
			cout<<"-----  PROGRAM STACK DATA MAHASISWA  -----"<<endl;
			cout<<"------------------------------------------"<<endl;
			stack.data[n];
			stack.i = 0;
			stack.j = 0;
			do {
				cout << "1. Push Data\n2. Pop Data\n3. View Data\n4. Clear Data\n5. Exit\nMasukkan pilihan :";
				cin >> pil;
				switch(pil){
				case 1:
				if (stack.j < n)
					{
					stack.j++;  push();
					}
					else
					{
					cout << "tumpukan penuh" << endl;
					getch();
					}
					break;
				case 2:
				pop ();
				break;
				case 3:
				view (stack.i);
				break;
				case 4:
				clear();
				break;
				case 5:cout << "Terimakasih";
				}
				getchar();
				cout << endl;
				cout << endl;
			}while(pil!=5);
			break;
		case 5 :
			do {	
				cout << "==============================" << endl; 
				cout << "    PROGRAM DATA MAHASISWA    " << endl; 
				cout << "==============================" << endl; 
				cout << "1. Tambah mahasiswa\n2. Add first Data mahasiswa\n3. Add Last Data Mahasiswa\n4. Remove First Mahasiswa\n5. Remove Last Mahasiswa\n6. Change first Mahasiswa\n7. Change Last Mahasiswa\n8. View\n9. Exit" << endl;
				cout << "Masukkan pilihan : ";
				cin >> pilihan;
				switch(pilihan){
				case 1:
				input();
				createSingleLinkedList(namaLinkedList,nimLinkedList);
				break;
				case 2:
				input();
				addFirst( namaLinkedList,  nimLinkedList);
				break;
				case 3:
				input();
				addLast( namaLinkedList,  nimLinkedList);
				break;
				case 4:
				removeFirst();
				break;
				case 5:
				removeLast();
				break;
				case 6:
				input();
				changeFirst(namaLinkedList,nimLinkedList);
				break;
				case 7:
				input();
				changeLast(namaLinkedList,nimLinkedList);
				break;
				case 8:
				cout << "==============================" << endl; 
				printSingleLinkedList();
				cout << "==============================" << endl; 
				cout << "\n\n" << endl;
				}
				getchar();
				cout << endl;
				cout << endl;
				}while(pilihan!=9);
		}
	}while(pilihan!=6);
	
}