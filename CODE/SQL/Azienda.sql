DROP DATABASE IF EXISTS azienda;
CREATE DATABASE azienda;

\c azienda

DROP TABLE IF EXISTS fornitori;
CREATE TABLE fornitori (
    f_cod   char(5)     PRIMARY KEY,
    nome    varchar(25) NOT NULL,
    citta   varchar(25) NOT NULL
);

DROP TABLE IF EXISTS articoli;
CREATE TABLE articoli (
    a_cod   char(6)     PRIMARY KEY,
    a_nome  varchar(20) NOT NULL,
    colore  varchar(10),
    peso    int         NOT NULL,
    citta   varchar(25) NOT NULL
);

DROP TABLE IF EXISTS forniture;
CREATE TABLE forniture (
    f_cod   char(5)     REFERENCES fornitori(f_cod),
    a_cod   char(6)     REFERENCES articoli(a_cod),
    quantita int        NOT NULL
);

INSERT INTO fornitori VALUES('1','Pippo','Firenze');
INSERT INTO fornitori VALUES('2','Paolo','Firenze');
INSERT INTO fornitori VALUES('3','Marco','Roma');
INSERT INTO fornitori VALUES('4','Gianni','Roma');
INSERT INTO fornitori VALUES('5','Renzo','Venezia');
INSERT INTO fornitori VALUES('6','Toni','Venezia');

INSERT INTO articoli VALUES('AZX100','Gomma','Rosso',100,'Firenze');
INSERT INTO articoli VALUES('AZX200','Lapis','Giallo',200,'Roma');
INSERT INTO articoli VALUES('AZX300','Penna','Verde',300,'Firenze');
INSERT INTO articoli VALUES('AZX400','Biro','Rosso',400,'Padova');
INSERT INTO articoli VALUES('AZX500','Pennarello','Rosso',500,'Firenze');
INSERT INTO articoli VALUES('AZX600','Matita','Nero',200,'Napoli');

INSERT INTO forniture VALUES('1','AZX200',1000);
INSERT INTO forniture VALUES('1','AZX100',1500);
INSERT INTO forniture VALUES('1','AZX400',1000);
INSERT INTO forniture VALUES('2','AZX300',3000);
INSERT INTO forniture VALUES('2','AZX400',1000);
INSERT INTO forniture VALUES('3','AZX600',5000);
INSERT INTO forniture VALUES('4','AZX500',1600);
INSERT INTO forniture VALUES('5','AZX100',4000);
INSERT INTO forniture VALUES('6','AZX100',3000);
INSERT INTO forniture VALUES('6','AZX200',1000);
INSERT INTO forniture VALUES('6','AZX300',2500);
INSERT INTO forniture VALUES('6','AZX400',2000);


--VERIFICA:
SELECT * FROM articoli WHERE a_cod IN (SELECT a_cod FROM forniture WHERE f_cod = '1');

SELECT COUNT(*) FROM forniture WHERE a_cod IN (SELECT a_cod FROM articoli WHERE citta = 'Firenze');

SELECT * FROM articoli LEFT JOIN forniture ON articoli.a_cod = forniture.a_cod OFFSET 9; 

SELECT DISTINCT fornitori.nome FROM fornitori JOIN forniture ON fornitori.f_cod = forniture.f_cod ORDER BY fornitori.nome DESC;

-------

SELECT forniture.f_cod, SUM(forniture.quantita) FROM forniture GROUP BY forniture.f_cod HAVING SUM(forniture.quantita) > 3000;

SELECT fornitori.nome,fornitori.f_cod,articoli.a_nome,articoli.a_cod, forniture.quantita FROM fornitori,forniture,articoli WHERE fornitori.f_cod AND articoli.a_cod IN (SELECT a_cod, f_cod FROM forniture WHERE quantita > 3000);

SELECT fornitori.nome,articoli.a_nome,forniture.quantita FROM fornitori,forniture,articoli WHERE forniture.a_cod = articoli.a_cod AND fornitori.f_cod = forniture.f_cod AND forniture.f_cod = '1';

SELECT fornitori.f_cod, fornitori.nome, fornitori.citta, forniture.quantita FROM fornitori, forniture WHERE forniture.f_cod = fornitori.f_cod AND forniture.quantita = MAX(forniture.quantita);

SELECT fornitori.f_cod, fornitori.nome, fornitori.citta, forniture.quantita FROM fornitori, forniture WHERE forniture.f_cod = fornitori.f_cod AND forniture.quantita IN (SELECT MAX(quantita) FROM forniture);

ciao;

SELECT fornitori.f_cod, fornitori.nome, fornitori.citta, COUNT(articoli.*) FROM fornitori, articoli GROUP BY fornitori.f_cod ORDER BY COUNT(articoli.*) DESC LIMIT 1;

SELECT forniture.f_cod, fornitori.nome, fornitori.citta, COUNT(forniture.*) FROM fornitori, forniture GROUP BY forniture.f_cod ORDER BY COUNT(forniture.*) DESC LIMIT 1;
