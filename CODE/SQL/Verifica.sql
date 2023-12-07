DROP DATABASE IF EXISTS universita;
CREATE DATABASE verifica;

\c verifica

DROP TABLE IF EXISTS studenti;
CREATE TABLE studenti(
    id   serial NOT NULL,
    nome        varchar(25) NOT NULL,
    voto     int NOT NULL,
    
    PRIMARY KEY (id)
);

INSERT INTO studenti VALUES(DEFAULT,'Piero',7);
INSERT INTO studenti VALUES(DEFAULT,'ALberto',6);
INSERT INTO studenti VALUES(DEFAULT,'Frencesco',9);
INSERT INTO studenti VALUES(DEFAULT,'Carminio',8);
INSERT INTO studenti VALUES(DEFAULT,'Eusebio',6);
INSERT INTO studenti VALUES(DEFAULT,'Eugenio',7);
INSERT INTO studenti VALUES(DEFAULT,'Livio',9);
INSERT INTO studenti VALUES(DEFAULT,'Angiolino',8);

SELECT MAX(voto), nome FROM studenti GROUP BY nome;
SELECT id, nome FROM studenti WHERE voto IN (
    SELECT MAX(voto) FROM studenti
);