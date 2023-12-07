DROP DATABASE IF EXISTS universita;
CREATE DATABASE universita;

\c universita

DROP TABLE IF EXISTS professori;
CREATE TABLE professori(
    id_prof     serial,
    nome        varchar(25) NOT NULL,
    cognome     varchar(25) NOT NULL,

    UNIQUE(nome,cognome),
    PRIMARY KEY (id_prof)
);

DROP TABLE IF EXISTS studenti;
CREATE TABLE studenti(
    matricola   char(6) NOT NULL,
    nome        varchar(25) NOT NULL,
    cognome     varchar(25) NOT NULL,
    
    UNIQUE(nome,cognome),
    PRIMARY KEY (matricola)
);

DROP TABLE IF EXISTS corsi;
CREATE TABLE corsi(
    id_corso        serial NOT NULL,
    nome            varchar(25) NOT NULL,
    id_professore   int REFERENCES professori(id_prof),
    
    UNIQUE(nome),
    PRIMARY KEY (id_corso)
);

DROP TABLE IF EXISTS esami;
CREATE TABLE esami(
    id_corso    int REFERENCES corsi(id_corso) NOT NULL,
    studente    char(6) REFERENCES studenti(matricola) NOT NULL,
    voto        int NOT NULL,
    giorno      date NOT NULL,
    
    PRIMARY KEY (id_corso,studente)
);

INSERT INTO professori VALUES(
    DEFAULT,
    'Pino',
    'Insegno'
);

INSERT INTO professori VALUES(
    DEFAULT,
    'Claudio',
    'Bisio'
);

INSERT INTO studenti VALUES(
    'SIMTAR',
    'Simone',
    'Tardiani'
);

INSERT INTO studenti VALUES(
    'MATBIN',
    'Matteo',
    'Bini'
);

INSERT INTO studenti VALUES(
    'DAVMIL',
    'Davide',
    'Milanese'
);

INSERT INTO studenti VALUES(
    'ZENTOS',
    'Zeno',
    'Tosi'
);

INSERT INTO corsi VALUES(
    DEFAULT,
    'Infor1',
    1
);

INSERT INTO corsi VALUES(
    DEFAULT,
    'Ita2',
    2
);

INSERT INTO esami VALUES(
    1,
    'MATBIN',
    25,
    '2023-10-29'
);

INSERT INTO esami VALUES(
    2,
    'ZENTOS',
    23,
    '2023-10-29'
);