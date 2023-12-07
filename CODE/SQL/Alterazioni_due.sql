DROP DATABASE IF EXISTS alterazioni_due;
CREATE DATABASE alterazioni_due;

\c alterazioni_due

DROP TABLE IF EXISTS studenti;
CREATE TABLE studenti(
    matricola   char(6) NOT NULL,
    nome        varchar(25) NOT NULL,
    cognome     varchar(25) NOT NULL,
    
    UNIQUE(nome,cognome),
    PRIMARY KEY (matricola)
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

ALTER TABLE studenti ADD voti integer;

\d studenti

ALTER TABLE studenti DROP voti;

\d studenti

ALTER TABLE studenti ADD voti integer;

UPDATE studenti SET voti=9 WHERE matricola='SIMTAR';

UPDATE studenti SET voti=10 WHERE matricola='ZENTOS';

UPDATE studenti SET voti=8 WHERE matricola='MATBIN';

UPDATE studenti SET voti=7 WHERE matricola='DAVMIL';

SELECT cognome FROM studenti WHERE voti>7;

SELECT count(*) AS contavoti FROM studenti WHERE voti>7;

ALTER TABLE studenti ALTER nome TYPE varchar(30);

DROP TABLE IF EXISTS corsi;
CREATE TABLE corsi(
    id_corso        serial NOT NULL,
    nome            varchar(25) NOT NULL,

    UNIQUE(nome),
    PRIMARY KEY (id_corso)
);

INSERT INTO corsi VALUES(
    DEFAULT,
    'Infor1'
);

INSERT INTO corsi VALUES(
    DEFAULT,
    'Ita2'
);

ALTER TABLE studenti ADD corso int REFERENCES corsi(id_corso);

UPDATE studenti SET corso=1 WHERE matricola='ZENTOS';

UPDATE studenti SET corso=1 WHERE matricola='MATBIN';

UPDATE studenti SET corso=2 WHERE matricola='DAVMIL';

UPDATE studenti SET corso=2 WHERE matricola='SIMTAR';

SELECT * FROM studenti;