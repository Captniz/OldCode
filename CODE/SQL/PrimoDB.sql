create database 5CIIN;

create table alunni (
  id integer,
  name varchar(50),
  surname varchar(50),
  email varchar(50),
  telefono varchar(50),
  indirizzo varchar(50)
);

insert into Alunni values (
    '1', 
    'Piero', 
    'Pierini', 
    'ppierini@fermimn.edu.it', 
    '3924722478', 
    'Via roncoleva 14'
);

select * from Alunni;
