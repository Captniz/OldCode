DROP DATABASE IF EXISTS impresa;
CREATE DATABASE impresa;

\c impresa

DROP TABLE IF EXISTS dipartimento;
CREATE TABLE dipartimento(
    nome varchar(15),
    numero_impiegati int DEFAULT 0, 

    PRIMARY KEY (nome)
);

DROP TABLE IF EXISTS impiegato;
CREATE TABLE impiegato (
    matricola   char(6),
    nome        varchar(25) NOT NULL,
    cognome     varchar(25) NOT NULL,
    dipart      varchar(15) REFERENCES dipartimento(nome),
    ufficio     numeric(3),
    stipendio   numeric(3) DEFAULT 0,
    
    UNIQUE(nome,cognome),
    PRIMARY KEY (matricola)
);

INSERT INTO dipartimento VALUES(
    'Tecnici',
    120
);

INSERT INTO dipartimento VALUES(
    'Elettronici',
    183
);

INSERT INTO impiegato VALUES(
    'PIPBIA',
    'Pippo',
    'Bianchi',
    'Tecnici',
    938,
    500
);

INSERT INTO impiegato VALUES(
    'NICNER',
    'Nicolo',
    'Neri',
    'Tecnici',
    283,
    100
);
