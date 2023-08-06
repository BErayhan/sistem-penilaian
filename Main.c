#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include "dosen.h"
//#include "mahasiswa.h"
//#include "inputMatkul.h"

void dosen (void);
void mahasiswa (void);
void TU (void);

struct matkul{
  char nama[50];
  float tugas;
  float uts;
  float kuis;
  float uas;
}Matkul, copy_matkul;

FILE *info , *info2;

int cek_matkul(char id[50])
{
  FILE *matkul;
  int i=0;
  
  matkul=fopen("info_matkul.txt","r");
  while(!feof(matkul))
    {
      if(fread(&copy_matkul,sizeof(struct matkul),1,matkul)==1)
            if(strcmp(copy_matkul.nama, id)==0)
        {
            i=1;
            break;
        }
    }
    fclose(matkul);
    return i;
}

void InputMatkul(void){
  info=fopen("info_matkul.txt","a");

  int ulang;

  do { 
    system("cls");
    printf("\n\n\t\t\t Input Matkul");
    printf("\n\t\t\t -----------------");
    printf("\n\n\t\t Silakan masukkan detail berikut : ");
    
    printf("\n\n\t Nama Mata Kuliah : ");fflush(stdin);
    scanf("%255[^\n]s", &Matkul.nama); 
    
    if(cek_matkul(Matkul.nama)==0){
      printf("\n\t Persentase Tugas/PR : ");
      fflush(stdin); scanf("%255[^\n]", &Matkul.tugas); 
    
      printf("\n\t Persentase Kuis : ");
      fflush(stdin); scanf("%255[^\n]", &Matkul.kuis); 
    
      printf("\n\t Persentase UTS : ");
      fflush(stdin); scanf("%d", &Matkul.uts); 

      printf("\n\t Persentase UAS : ");
      fflush(stdin);scanf("%255[^\n]", &Matkul.uts); 
      
      fwrite(&Matkul,sizeof(struct matkul),1,info);   
      printf("\n\n\t >>> Mata Kuliah berhasil ditambahkan.");
      printf("\n\n\t Apakah Anda ingin menambahkan mata kuliah yang lain? [1] Ya          [0] Tidak : ");
      scanf("%d",&ulang);
    }
      
    else{
      printf("\n\n\t >>> Mata kuliah sudah terdaftar.");
      printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
      getch();
    }
 }while(ulang==1);   
    fclose(info); 
    return;
}

void dosen(void) {
  int pilihan1;
  char password[20] = "dosen" ;
  
	//label :
  system("cls");
  printf("\n\nSilakan masukkan password : ");
  
  char str[20];
  char ch;
	int i=0;
  
  while( ((ch=getch())!='\r') && i<20 ){
    putch('*');
    str[i++]=ch;
  }
  
  str[i]='\0';
  
  if(strcmp(str,password)==0){
    printf("\n\n\n>>> Proses autentikasi berhasil. ");
    printf("\n\nTekan tombol apa saja untuk melanjutkan...");
    getch();
  }
  else{
    printf("\n\n\n>>> Password yang Anda masukkan salah.");
    printf("\n\nTekan tombol apa saja untuk melanjutkan...");
    getch();
    return;
  }
   
  do {
	  system("cls");
    
  	printf("\n\nMenu Dosen :\n");
  	printf("\n[1] Input Mata Kuliah dan Presentase Penilaiannya");
  	printf("\n[2] Input Nilai Mahasiswa");
		printf("\n[3] Hasil Rekapitulasi Nilai");
 		printf("\n[4] Panduan");
    printf("\n[5] Kembali ke Menu Awal");
 		printf("\n[6] Keluar Program");
    
 		printf("\n\nSilakan masukkan pilihan Anda (1-6) : ");
    scanf("%d",&pilihan1); fflush(stdin);

    switch(pilihan1){
        case 1: InputMatkul();
					      break;
        case 2: inputNilai();
					      break;
        case 3: rekapNilai();
					      break;
        case 4: panduan();
					      break;
        case 5: main();
                break;
        case 6: keluar();
                break;
        default: printf("\n\n>>> Pilihan Anda tidak sesuai.");
                 getch();
    }
  }while(1);
  
  getch();
  
}

int main (){
  int user;
  
  printf("------------------ SISTEM PENILAIAN MAHASISWA ------------------\n\n");

  
  printf("\nPilihan user:\n");
  puts("1. Dosen");
  puts("2. Mahasiswa");
  puts("3. TU");

  do{
    printf("Masuk sebagai apa? (ketik 1/2/3)\n");
    scanf("%d", &user);
    if(user == 1 || user == 2 || user == 3)break;
    printf("Maaf, input tidak valid. Mohon diulangi.\n\n");
  }while(1);
  
  
  /*if (user==1){
    dosen();
  }else if (user==2){
     mahasiswa();
  }
  else if (user==3){
    TU();
  }*/
  
  return 0;
}



