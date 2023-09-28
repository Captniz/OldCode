CREATE DATABASE alterazioni;

CREATE TABLE studenti (
  cod int,
  nome varchar(50),
  cognome varchar(50),
  email varchar(50),
  telefono varchar(50),
  indirizzo varchar(50)
);

INSERT INTO studenti VALUES(
    '101', 
    'Piero', 
    'Pierini', 
    'ppierini@fermimn.edu.it', 
    '3924722478', 
    'Via roncoleva 14'
);

INSERT INTO studenti VALUES(
    '102', 
    'Giacomo', 
    'Matteotti', 
    'gamat@fermimn.edu.it', 
    '3929722478', 
    'Via lonchi 24'
);

INSERT INTO studenti VALUES(
    '103', 
    'Matteo', 
    'Messina', 
    'mmessina@fermimn.edu.it', 
    '0924720198', 
    'Via arbusti 4'
);

ALTER TABLE studenti ADD eta integer;

ALTER TABLE studenti ALTER cod TYPE char(3);