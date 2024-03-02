DROP DATABASE IF EXISTS prova;
CREATE DATABASE prova;

\c prova


DROP TABLE IF EXISTS province;
CREATE TABLE province (
    sigla char(2) NOT NULL PRIMARY KEY,
    denominazione varchar(20) NOT NULL,
);

DROP TABLE IF EXISTS alunni;
CREATE TABLE alunni (
    matricola serial NOT NULL PRIMARY KEY,
    nome varchar(25) NOT NULL,
    sigla char(2) REFERENCES province(sigla)
);

INSERT INTO province VALUES(
    'TO',
    'Torino'
);

INSERT INTO province VALUES(
    'MN',
    'Mantova'
);

INSERT INTO province VALUES(
    'BG',
    'Bergamo'
);

INSERT INTO alunni VALUES(
    DEFAULT,
    'Marco',
    'BG'
);

INSERT INTO alunni VALUES(
    DEFAULT
    'Pino',
    'MN'
);

INSERT INTO alunni VALUES(
    DEFAULT,
    'Pluto',
    'TO'
);