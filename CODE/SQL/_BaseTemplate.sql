DROP DATABASE IF EXISTS xxx;
CREATE DATABASE xxx;

\c test

DROP TABLE IF EXISTS yyy;
CREATE TABLE yyy (
    id serial NOT NULL PRIMARY KEY,
    nome varchar(25) NOT NULL,
    cognome varchar(25) NOT NULL
);

DROP TABLE IF EXISTS zzz;
CREATE TABLE zzz (
    id_studente int NOT NULL REFERENCES studente(id),
    materia varchar(25) NOT NULL,
    giorno char(8) NOT NULL,
    voto int NOT NULL
);

INSERT INTO studente VALUES(
    DEFAULT,
    'a',
    'b'
);
