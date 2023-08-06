int cek_matkul(char id[50])
{
  FILE *matkul;
  int i=0;
  
  matkul=fopen("info_matkul.txt","r");
  while(!feof(matkul))
    {
      if(fread(&copy_matkul,sizeof(matkul),1,matkul)==1)
    {
			if(strcmp(copy_matkul.nama, id)==0)
        {
            i=1;
            break;
        }
    }
    fclose(matkul);
    return i;
}


void InputMatkul(void) {
  info=fopen("info_matkul.txt","a");

  int ulang;

  do { 
    system("cls");
    printf("\n\n\t\t\t Input Matkul");
    printf("\n\t\t\t -----------------");
    printf("\n\n\t\t Silakan masukkan detail berikut : ");
    
    printf("\n\n\t Nama Mata Kuliah : ");
    scanf("%255[^\n]s",Matkul.nama); fflush(stdin);
    
    if(cek_matkul(Matkul.nama)==0){
      printf("\n\t Persentase Tugas/PR : ");
      scanf("%255[^\n]", &Matkul.tugas); fflush(stdin);
    
      printf("\n\t Persentase Kuis : ");
      scanf("%255[^\n]", &Matkul.kuis); fflush(stdin);
    
      printf("\n\t Persentase UTS : ");
      scanf("%d", &Matkul.UTS); fflush(stdin);

      printf("\n\t Persentase UAS : ");
      scanf("%255[^\n]", &Matkul.UAS); fflush(stdin);
      
      fwrite(&Matkul,sizeof(struct info_matkul),1,info);   
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
