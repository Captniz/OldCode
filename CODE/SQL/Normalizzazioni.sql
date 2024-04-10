DROP DATABASE IF EXISTS norm;
CREATE DATABASE norm;

\c norm

DROP TABLE IF EXISTS zone;
CREATE TABLE zone (
    cod char(1) NOT NULL PRIMARY KEY,
    zona varchar(25) NOT NULL
);

DROP TABLE IF EXISTS tipi;
CREATE TABLE tipi (
    cod char(1) NOT NULL PRIMARY KEY,
    tipo varchar(25) NOT NULL
);

DROP TABLE IF EXISTS carte;
CREATE TABLE carte (
    cod char(1) NOT NULL PRIMARY KEY,
    carta varchar(25) NOT NULL
);

DROP TABLE IF EXISTS gestioni;
CREATE TABLE gestioni (
    codRistorante int NOT NULL PRIMARY KEY,
    nome varchar(25) NOT NULL,
    indirizzo varchar(25) NOT NULL,
    codTipo char(1) NOT NULL,
    codZona varchar(25) NOT NULL
);

DROP TABLE IF EXISTS ristoranti;
CREATE TABLE ristoranti (
    cod int NOT NULL PRIMARY KEY,
    codCarta char(1) NOT NULL
);

-- ####################################

DROP DATABASE IF EXISTS norm1;
CREATE DATABASE norm1;

\c nrom1

DROP TABLE IF EXISTS corsi;
CREATE TABLE corsi (
    codMateria int NOT NULL,
    codStudi char(3) NOT NULL,
    semestre char(1) NOT NULL,
    codProf char(3) NOT NULL

    PRIMARY KEY (codMateria, codStudi, semestre)
);

DROP TABLE IF EXISTS prof;
CREATE TABLE prof (
    codProf char(3) NOT NULL PRIMARY KEY,
    nomeProf varchar(25) NOT NULL,
    cognomeProf varchar(25) NOT NULL,
    dipartiemento varchar(25) NOT NULL
);

DROP TABLE IF EXISTS materia;
CREATE TABLE materia (
    codMateria int NOT NULL PRIMARY KEY,
    materia varchar(25) NOT NULL
);
