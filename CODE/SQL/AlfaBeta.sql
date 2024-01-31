DROP DATABASE IF EXISTS alfa;
CREATE DATABASE alfa;

\c alfa

DROP TABLE IF EXISTS alunni;
CREATE TABLE alunni (
    id serial NOT NULL PRIMARY KEY,
    nome varchar(25) NOT NULL,
    cognome varchar(25) NOT NULL
);

DROP TABLE IF EXISTS prof;
CREATE TABLE prof (
    id serial NOT NULL PRIMARY KEY,
    nome varchar(25) NOT NULL,
    cognome varchar(25) NOT NULL
);

DROP DATABASE IF EXISTS beta;
CREATE DATABASE beta;

\c beta

DROP TABLE IF EXISTS materie;
CREATE TABLE materie (
    id serial NOT NULL PRIMARY KEY,
    nome varchar(25) NOT NULL
);

\c alfa

INSERT INTO alunni VALUES(
    DEFAULT,
    'Marco',
    'B'
);