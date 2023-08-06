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
