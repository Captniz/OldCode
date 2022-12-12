/*221203_ztl_cognome_nome.html
==============================
Gestione Targhe ZTL Mantova

Si realizzi un pagina web utilizzando HTML+CSS+JS
per la gestione delle autorizzazione
alla circolazione delle automobili nelle ZTL della città di Mantova

NAVBAR (visualizzata in alto contenete le seguente opzioni)
 Nuova  
 Autorizza  
 Revoca
 Controlla  
 Stampa  
 chiudi  

premendo una delle opzioni della NAVBAR verrà visualizzato il menu corrispondente


Caratteristiche Menu

  ----------------
  Nuova Targa
  ----------------
  (permette di inserire i dati di un nuovo utente e della sua targa)

  CAMPI INPUT *
  -----------
  Nome
  Cognome
  Luogo di nascita
  Data di nascita
  Indirizzo Residenza
  Città Residenza
  Targa
  Pulsante "INSERISCI" che effettua un nuovo inserimento  

  i dati dovranno essere memorizzati nel sistema in 2 oggetti
  un array di oggetti targa dove targa = {userid,targa,ztl}; // dove ztl è vale "Y" o "N"
  un array di oggetti user dove user ={userid,nome,cognome,natoa,natoil,addr,city)

  assicurando che
 
  userid sia un numero progressivo e che non ci siano 2 user con lo stesso userid
  non ci siano due targhe uguali
 

  ----------------
  Autorizza Targa
  ----------------
  CAMPI INPUT *
  -----------
  Nome
  Cognome
  Targa
  Pulsante "CERCA" una targa per nome o cognome o targa
 
  visualizzi un elenco di targhe che rispondano ai criteri di ricerca con un bottone "AUTORIZZA" in linea per autorizzare la targa

  ----------------
  Revoca Targa
  ----------------
  CAMPI INPUT *
  -----------
  Nome
  Cognome
  Targa
  Pulsante "CERCA" una targa per nome o cognome o targa
 
  visualizzi un elenco di targhe che rispondano ai criteri di ricerca con un bottone "CANCELLARE" in linea per cancellare     l'autorizzazione  la targa

  ----------------
  Modifica Targa
  ----------------
  CAMPI INPUT *
  -----------
  Nome
  Cognome
  Targa
  Pulsante "CERCA" una targa per nome o cognome o targa
 
  visualizzi un elenco di targhe che rispondano ai criteri di ricerca con un bottone "modifica" in linea  che apre una nuova FORM

 
  CAMPI INPUT modifica *
  --------------------
  Nome
  Cognome
  Luogo di nascita
  Data di nascita
  Indirizzo Residenza
  Città Residenza
  Targa
  Pulsante "MODIFICA" che effettua la modifica dei dati

  NB
  i campi saranno tutti valorizzati all'apertura della sotto form e modificabili
  prima di modificare nelle strutture interne accertarsi che :non ci siano due utenti con lo stesso id, due targe uguali

  ----------------
  Stampa Targhe
  ----------------
  stampa l'elenco di tutte le targhe usando il formato tabella HTML

 
* NOTA CAMPI INPUT

  chk data entry

  Nome: non deve contenere numeri dimensione massima 20 caratteri
  Cognome: non deve contenere numeri dimensione massima 20 caratteri
  Luogo di nascita: non deve contenere numeri  dimensione massima 20 caratteri
  Data di nascita: sia informato dd/mm/yy
  Indirizzo Residenza non deve contenere numeri:  dimensione massima 40 caratteri
  Città Residenza non deve contenere numeri:  dimensione massima 20 caratteri
  Targa: contenga almeno 1 numero && contenga almenu un carattere e sia lunga non meno di 7 caratteri */
  
var activeId = "nuova";

function Show(id) {
  document.getElementById(activeId).style.display = "none";
  activeId = id;
  document.getElementById(activeId).style.display = "block";
}

function Nuova() {
  var nome = document.forms.nuovaF.getElementById("nome").value;
  var cnome = document.forms.nuovaF.getElementById("cognome").value;
  var indirizzo = document.forms.nuovaF.getElementById("indirizzo").value; 
  var citta = document.forms.nuovaF.getElementById("citta").value;
  var data 
}
