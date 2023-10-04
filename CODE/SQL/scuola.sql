CREATE TABLE materie (
  id serial NOT NULL PRIMARY KEY,
  sigla char(3) NOT NULL,
  materia varchar(20) NOT NULL
);

INSERT INTO materie VALUES( 
  DEFAULT,
  'MEC', 
  'Meccanica'
);

INSERT INTO materie VALUES( 
    DEFAULT,
    'INF', 
    'Informatica'
);

INSERT INTO materie VALUES( 
  DEFAULT,
  'TEL', 
  'Telecomunicazioni'
);

-------------------------------------------------

CREATE TABLE tipi_aule (
  id serial NOT NULL PRIMARY KEY, 
  tipo varchar(20) NOT NULL,
  materia_id smallint REFERENCES materie(id) -- materie > id
);

INSERT INTO tipi_aule VALUES( 
  DEFAULT,
    'Laboratorio', 
    1
);

INSERT INTO tipi_aule VALUES( 
  DEFAULT,
    'Laboratorio', 
    2
);

INSERT INTO tipi_aule VALUES( 
  DEFAULT,
    'Aula'
);

-------------------------------------------------

CREATE TABLE aule (
  id serial NOT NULL PRIMARY KEY,
  numero_aula smallint NOT NULL,
  tipo_id smallint NOT NULL REFERENCES tipi_aule(id) -- tipi_aule > id
);

INSERT INTO aule VALUES( 
  DEFAULT,
    '460',
    1
);

INSERT INTO aule VALUES( 
  DEFAULT,
    '380',
    2 
);

INSERT INTO aule VALUES( 
  DEFAULT,
    '80',
    3
);

-------------------------------------------------

CREATE TABLE classi (
  id serial NOT NULL PRIMARY KEY,
  sigla varchar(5) NOT NULL,
  sezione char(2) NOT NULL,
  materia_id smallint NOT NULL REFERENCES materie(id), -- materie > id
  numero_alunni smallint NOT NULL
);

INSERT INTO classi VALUES( 
  DEFAULT,
    '5CIIN',
    '5C',
    2,
    22
);

INSERT INTO classi VALUES( 
  DEFAULT,
    '5AMEC',
    '5A',
    1,
    19
);

-------------------------------------------------

CREATE TABLE alunni (
  id serial NOT NULL PRIMARY KEY,
  classe_id smallint NOT NULL REFERENCES classi(id), -- classi > id
  nome varchar(30) NOT NULL,
  cognome varchar(30) NOT NULL,
  eta smallint NOT NULL,
  email varchar(50) 
);

INSERT INTO alunni VALUES( 
  DEFAULT,
    1,
    'Mario',
    'Rossi',
    18
);

INSERT INTO alunni VALUES( 
  DEFAULT,
    1,
    'Ermenegildo',
    'Verdi',
    19
);

INSERT INTO alunni VALUES( 
  DEFAULT,
    2,
    'Luca',
    'Bianchi',
    19
);

INSERT INTO alunni VALUES( 
  DEFAULT,
    2,
    'Giovanni',
    'Neri',
    17
);

-------------------------------------------------

CREATE TABLE docenti (
  id serial NOT NULL PRIMARY KEY,
  materia_id smallint NOT NULL REFERENCES materie(id), -- materie > id
  nome varchar(30) NOT NULL,
  cognome varchar(30) NOT NULL,
  eta smallint NOT NULL,
  email varchar(50)
);

INSERT INTO docenti VALUES( 
  DEFAULT,
    1,
    'Giuseppe',
    'Verdi',
    45
);

INSERT INTO docenti VALUES( 
  DEFAULT,
    2,
    'Marco',
    'Culpo',
    43
);

-------------------------------------------------

CREATE TABLE orario (
    aula_id smallint NOT NULL REFERENCES aule(id), -- aule > id
    classe_id smallint NOT NULL REFERENCES classi(id), -- classi > id
    giorno smallint NOT NULL,
    ora smallint NOT NULL,
    prof_id smallint NOT NULL REFERENCES docenti(id) -- docenti > id
);

INSERT INTO orario VALUES( 
    1,
    1,
    1,
    8,
    1
);

INSERT INTO orario VALUES( 
    2,
    1,
    1,
    9,
    1
);

INSERT INTO orario VALUES( 
    1,
    1,
    1,
    10,
    1
);

INSERT INTO orario VALUES( 
    2,
    1,
    1,
    11,
    1
);

INSERT INTO orario VALUES( 
    2,
    1,
    1,
    12,
    1
);

INSERT INTO orario VALUES( 
    2,
    1,
    1,
    13,
    1
);