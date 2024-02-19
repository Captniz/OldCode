DROP DATABASE IF EXISTS libreria;
CREATE DATABASE libreria;

\c libreria

DROP TABLE IF EXISTS studenti;
CREATE TABLE studenti (
    classe          int             NOT NULL,
    sezione         char(4)         NOT NULL,
    nome            varchar(25)     NOT NULL,
    cognome         varchar(25)     NOT NULL,

    PRIMARY KEY (nome,cognome)
);

INSERT INTO studenti VALUES (5, 'CIIN', 'Simone', 'Tardiani');
INSERT INTO studenti VALUES (5, 'CIIN', 'Matteo', 'Bini');
INSERT INTO studenti VALUES (5, 'CIIN', 'Simone', 'Casari');

DROP TABLE IF EXISTS libri;
CREATE TABLE libri (
    titolo          varchar(25)     NOT NULL,
    autore          varchar(25)     NOT NULL,
    disponibile     boolean         NOT NULL,

    PRIMARY KEY (titolo,autore)
);

INSERT INTO libri VALUES ('Bibbia', 'Gli apostoli', False);
INSERT INTO libri VALUES ('Topolino 2945', 'Topolino', True);
INSERT INTO libri VALUES ('1984', 'Orwell', True);

DROP TABLE IF EXISTS prestiti;
CREATE TABLE prestiti (
    dataInizio      date            NOT NULL,
    dataFine        date            ,
    s_nome          varchar(25)     NOT NULL,
    s_cognome       varchar(25)     NOT NULL,
    l_titolo        varchar(25)     NOT NULL,
    l_autore        varchar(25)     NOT NULL,

    FOREIGN KEY (s_nome,s_cognome) REFERENCES studenti(nome,cognome),
    FOREIGN KEY (l_titolo,l_autore) REFERENCES libri(titolo,autore),

    PRIMARY KEY (s_nome,l_titolo,dataInizio)
);

INSERT INTO prestiti VALUES ('2024-10-20',NULL,'Simone','Tardiani','Bibbia','Gli apostoli');
INSERT INTO prestiti VALUES ('2024-10-20','2024-10-30','Bini','Matteo','Topolino 2945','Topolino');

