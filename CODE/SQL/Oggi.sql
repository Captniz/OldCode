DROP DATABASE IF EXISTS oggi;
CREATE DATABASE oggi;

\c oggi

DROP TABLE IF EXISTS studenti;
CREATE TABLE studenti (nome varchar(30) PRIMARY KEY,voto int NOT NULL,reddito int NOT NULL);

INSERT INTO studenti VALUES('Pippo',5,2000);
INSERT INTO studenti VALUES('Paolo',6,1500);
INSERT INTO studenti VALUES('Marco',7,1600);
INSERT INTO studenti VALUES('Gianni',8,1300);
INSERT INTO studenti VALUES('Renzo',9,1200);
INSERT INTO studenti VALUES('Toni',10,1000);

SELECT MAX(voto) FROM studenti;
SELECT SUM(reddito) FROM studenti WHERE voto IN (SELECT voto FROM studenti WHERE voto >= 8);