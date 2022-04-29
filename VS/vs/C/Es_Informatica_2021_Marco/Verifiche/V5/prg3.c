float inserisci(struct studente v[DIM]){

   int i,j,media;
   i=0;
   j=0;
   media=0;

   printf("Nome %d",i+1);
   gets(v[i].Nome);
   printf("Cognome %d",i+1);
   gets(v[i].Cognome);
   printf("Voto %d",i+1);
   scanf("%d",v[i].Voto);
   i++;

   while(i<DIM && v[i-1].Voto!=0){
      printf("Nome %d",i+1);
      gets(v[i].Nome);
      printf("Cognome %d",i+1);
      gets(v[i].Cognome);
      printf("Voto %d",i+1);
      scanf("%d",&v[i].Voto);
      i++;
   }

   if(v[i-1].Voto==0){
      i--;
   }

   for(j=0;j<i;j++){
      media=media+v[j].Voto;
   }

   return (media/i);
}