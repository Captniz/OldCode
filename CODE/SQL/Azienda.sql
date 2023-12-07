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

SELECT a_nome, colore, peso AS pesetto FROM articoli WHERE a_cod='AZX100';
SELECT * FROM articoli WHERE colore='Rosso';
SELECT a_nome, a_nome AS nomino, a_nome FROM articoli WHERE colore='Rosso';
SELECT forniture.a_cod , fornitori.f_cod, forniture.quantita, fornitori.nome FROM fornitori, forniture WHERE fornitori.f_cod = forniture.f_cod;
SELECT a_cod , f_cod, quantita FROM forniture;
SELECT fornitori.nome FROM fornitori, forniture WHERE forniture.quantita > 2500 AND fornitori.f_cod = forniture.f_cod;
SELECT DISTINCT articoli.a_nome FROM articoli, fornitori, forniture WHERE forniture.f_cod = '1' AND forniture.a_cod = articoli.a_cod;
SELECT * FROM articoli WHERE articoli.a_cod IN (SELECT forniture.a_cod FROM forniture WHERE forniture.f_cod = '1')
--Articoli venduti a firenze (nome,colore)
SELECT a_nome, colore FROM articoli WHERE citta='Firenza';
--Quante sono le forniture di firenze
SELECT COUNT(a_cod) AS numero FROM forniture WHERE a_cod IN (SELECT a_cod FROM articoli WHERE citta='Firenza');
--Citta con articoli di colore rosso
SELECT DISTINCT citta FROM articoli WHERE colore='Rosso';
--Cont le right di articoli
SELECT COUNT(a_cod) AS numeroTuple FROM articoli;
--Elenco di fornitori con almeno un articolo
SELECT DISTINCT * FROM fornitori;
--Media delle forniture con codice 1
SELECT AVG(quantita) AS mediaForn FROM forniture;
--Nome e peso dell oggetto di peso massimo di colore rosso
SELECT a_nome, MAX(peso) FROM articoli WHERE colore='Rosso' GROUP BY a_nome;
SELECT a_cod, SUM(quantita) FROM forniture GROUP BY a_cod;
-- ???? cosa fa HAVING
SELECT a_cod FROM forniture GROUP BY a_cod HAVING COUNT(*) > 1;
--- ???? Come trovo solo quello col massimo di un dato 



--VERIFICA:
SELECT fornitori.nome,articoli.a_nome,forniture.quantita FROM fornitori,forniture,articoli WHERE forniture.a_cod = articoli.a_cod AND fornitori.f_cod = forniture.f_cod AND forniture.f_cod = '1';

SELECT fornitori.f_cod, fornitori.nome, fornitori.citta, forniture.quantita FROM fornitori, forniture WHERE forniture.f_cod = fornitori.f_cod AND forniture.quantita IN (SELECT MAX(quantita) FROM forniture);

SELECT forniture.f_cod, fornitori.nome, fornitori.citta, COUNT(forniture.*) FROM fornitori, forniture GROUP BY forniture.f_cod ORDER BY COUNT(forniture.*) DESC LIMIT 1;
