int rico(int num, int result){

   if(num!=0){
      result = result*10 + num%10;
      return rico((num/10),result);
   }

   return result;
}