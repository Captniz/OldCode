import java.util.*;public class test{public static void main(String args[]){
    int i=0;
    Random rnd =
    new Random();
    Stagista s[] =
    new Stagista[10];
    Uomo u =
    new Uomo("Pietro","Bini","Maschio","Bologna");
    String c[] = {"Bologna","Milano","Roma","Mantova","Firenze"};
    u.stampa();
    s[i]=
    new
    Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(4)+1],rnd.nextInt(40)+10,++i);
    s[i]=
    new
    Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(4)+1],rnd.nextInt(40)+10,++i);
    s[i]=
    new
    Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(4)+1],rnd.nextInt(40)+10,++i);
    s[i]=
    new
    Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(4)+1],rnd.nextInt(40)+10,++i);
    s[i]=
    new
    Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(4)+1],rnd.nextInt(40)+10,++i);
    s[i]=
    new
    Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(4)+1],rnd.nextInt(40)+10,++i);
    s[i]=
    new
    Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(4)+1],rnd.nextInt(40)+10,++i);
    s[i]=
    new
    Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(4)+1],rnd.nextInt(40)+10,++i);
    s[i]=
    new
    Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(4)+1],rnd.nextInt(40)+10,++i);
    s[i]=
    new
    Stagista("Pietro","Bini","Maschio",c[rnd.nextInt(4)+1],rnd.nextInt(40)+10,++i);
    for(i=0;i<10;i++){
    s[i].stampa();
    }
    System.out.println("\nIl Piu giovane:");
    s[getGiovane(s)].stampa();
    System.out.println("\nCitta pref:");
    getCittaPref(s,c);
    }
    static int getGiovane(Stagista s[]){
    int prev=0;
    for(int i=1;i<(s.length-1);i++){
    if(s[prev].annoNascita()>s[i].annoNascita()){
    prev=i;
    }
    }
    return prev;
    }static void getCittaPref(Stagista s[], String c[]){
    int ctr=0;
    int prevctr=0;
    int cit=0;
    for(int i=0;i<c.length;i++){
    for(int j=0;j<s.length;j++){
    if(s[j].getCit()==c[i]){
    ctr++;
    }
    }
    if(ctr>prevctr){
    cit=i;
    prevctr=ctr;
    }
    ctr=0;
    }
    System.out.print(c[cit] + " " + prevctr);
    }
    }
     class Uomo{protected String nome;
    protected String cognome;protected String sesso;protected String codiceF;protected String citta;
    Uomo(){
    this.nome=null;
    this.cognome=null;
    this.sesso=null;
    this.citta=null;
    this.codiceF=null;
    }
    Uomo(String nome, String cognome, String sesso, String citta){
    this.nome=nome;
    this.cognome=cognome;
    this.sesso=sesso;
    this.citta=citta;
    codiceF = "";
    this.setCod(); //←questo e’ giusto, basta togliere il commento
    }
    void setN(String nome){
    this.nome = nome;
    }
    void setC(String cognome){
    this.cognome = cognome;
    }
    void setCod(){
    Random rnd = new Random();
    int ctr=0;
    for (int i = 0; i < nome.length()&&ctr<3; i++) {
    if(nome.charAt(i)!='a' && nome.charAt(i)!='e' && nome.charAt(i)!='i' &&
    nome.charAt(i)!='o' && nome.charAt(i)!='u'){
    codiceF+=nome.charAt(i);
    ctr++;
    }
    }
    for (int i = (nome.length()-1); i >=0&&ctr<3; i--) {
    if(nome.charAt(i)=='a' || nome.charAt(i)=='e' || nome.charAt(i)=='i' ||
    nome.charAt(i)=='o' || nome.charAt(i)=='u'){
    codiceF+=nome.charAt(i);
    ctr++;
    }
    }
    ctr=0;
    for (int i = 0; i < cognome.length()&&ctr<3; i++) {
    if(cognome.charAt(i)!='a' && cognome.charAt(i)!='e' &&
    cognome.charAt(i)!='i' && cognome.charAt(i)!='o' && cognome.charAt(i)!='u'){
    codiceF+=cognome.charAt(i);
    ctr++;
    }
    }
    for (int i= (cognome.length()-1); i >=0&&ctr<3; i--) {
    if(cognome.charAt(i)=='a' || cognome.charAt(i)=='e' ||
    cognome.charAt(i)=='i' || cognome.charAt(i)=='o' || cognome.charAt(i)=='u'){
    codiceF+=cognome.charAt(i);
    ctr++;
    }
    }
    codiceF+=rnd.nextInt(50)+50;
    codiceF+=(char)(rnd.nextInt(12)+65);
    codiceF+=rnd.nextInt(31)+1;
    codiceF+=(char)(rnd.nextInt(26)+65);
    codiceF+=rnd.nextInt(9)+1;
    codiceF+=rnd.nextInt(9)+1;
    codiceF+=rnd.nextInt(9)+1;
    codiceF+=(char)(rnd.nextInt(26)+65);
    }
    void setCod(String codiceF){
    this.codiceF=codiceF;
    }
    void setS(String sesso){
    this.sesso = sesso;
    }
    void setCit(String citta){
    this.citta = citta;
    }
    String getN(){
    return nome;
    }
    String getC(){
    return cognome;
    }
    String getCod(){
    return codiceF;
    }
    String getS(){
    return sesso;
    }
    String getCit(){
    return citta;
    }
    void stampa(){
    System.out.println("Uomo [ nome=" + nome + ", cognome=" + cognome + ", sesso=" +
    sesso+ ", citta=" + citta +", annoNascita=" +
    this.annoNascita()+ " ]");
    }
    int annoNascita(){
    int tmp=0;
    tmp = Integer.parseInt(codiceF.substring(6, 8));
    return tmp;
    }
    }class Stagista
    extends Uomo{
    int numeroPres;
    int numeroId;
    Stagista(String nome, String cognome, String sesso, String citta, int numeroPres,
    int numeroId){
    super( nome, cognome, sesso, citta);
    this.numeroPres = numeroPres;
    this.numeroId = numeroId;
    }
    void setPres(int numeroPres){
    this.numeroPres = numeroPres;
    }
    void setId(int numeroId){
    this.numeroId=numeroId;
    }
    int getPres(){
    return numeroPres;
    }
    int getId(){
    return numeroId;
    }
    //”Uomo” → “Stagista”
    @
    Override
    void stampa(){
    System.out.println("Stagista [ nome=" + nome + ", cognome=" + cognome + ",sesso=" + sesso+ ", citta=" + citta+ ", annoNascita=" + annoNascita()+ ", presenze="
    + numeroPres+ ", identifictivo=" + numeroId+" ]");
    }
    }