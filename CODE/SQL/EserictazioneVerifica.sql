DROP DATABASE IF EXISTS jointest;
CREATE DATABASE jointest;

\c jointest

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

INSERT INTO fornitori VALUES('00001','Piero','Firenze');
INSERT INTO fornitori VALUES('00002','Giacomo','Firenze');
INSERT INTO fornitori VALUES('00003','Antonio','Roma');
INSERT INTO fornitori VALUES('00004','Andrea','Roma');
INSERT INTO fornitori VALUES('00005','Marco','Venezia');
INSERT INTO fornitori VALUES('00006','Gianluca','Venezia');

INSERT INTO articoli VALUES('AZX100','Gomma','Rosso',100,'Firenze');
INSERT INTO articoli VALUES('AZX200','Lapis','Giallo',200,'Roma');
INSERT INTO articoli VALUES('AZX300','Penna','Verde',300,'Firenze');
INSERT INTO articoli VALUES('AZX400','Biro','Rosso',400,'Padova');
INSERT INTO articoli VALUES('AZX500','Pennarello','Rosso',500,'Firenze');
INSERT INTO articoli VALUES('AZX600','Matita','Nero',200,'Napoli');

INSERT INTO forniture VALUES('00001','AZX200',1000);
INSERT INTO forniture VALUES('00001','AZX100',1500);
INSERT INTO forniture VALUES('00001','AZX400',1000);
INSERT INTO forniture VALUES('00002','AZX300',3000);
INSERT INTO forniture VALUES('00002','AZX400',1000);
INSERT INTO forniture VALUES('00003','AZX600',5000);
INSERT INTO forniture VALUES('00004','AZX500',1600);
INSERT INTO forniture VALUES('00005','AZX100',4000);
INSERT INTO forniture VALUES('00006','AZX100',3000);
INSERT INTO forniture VALUES('00006','AZX200',1000);
INSERT INTO forniture VALUES('00006','AZX300',2500);
INSERT INTO forniture VALUES('00006','AZX400',2000);

-- Visualizzare gli articoli provenienti da città in cui è presente un fornitore qualsiasi
SELECT DISTINCT articoli.a_cod, articoli.a_nome FROM articoli INNER JOIN fornitori ON articoli.citta = fornitori.citta;

-- a_cod  |   f_nome
-- --------+------------
--  AZX500 | Pennarello
--  AZX100 | Gomma
--  AZX300 | Penna
--  AZX200 | Lapis

-- a_cod  |   a_nome
-- --------+------------
--  AZX500 | Pennarello
--  AZX100 | Gomma
--  AZX300 | Penna
--  AZX200 | Lapis
-- (4 rows)

SELECT DISTINCT articoli.a_cod, articoli.a_nome FROM articoli RIGHT OUTER JOIN fornitori ON articoli.citta = fornitori.citta;


--!!! Per estrarre le parti di data si usa:
--!!! EXTRACT(MONTH FROM data)
--!!! EXTRACT(YEAR FROM data)