create database Comuni;

create table Com (
  COMUNE varchar(50),
  PROVINCIA char(2),
  REGIONE char(3),
  PREFISSO char(5)
  CAP varchar(5),
  COD_COMUNE char(4),
  COD_ISTAT char(6)
);

insert into Com values (
    'ABANO TERME', 
    'PD', 
    'VEN', 
    '35031', 
    '049', 
    'A001', 
    '028001'
);

insert into Com values (
    'ABBADIA CERRETO', 
    'LO', 
    'LOM', 
    '20070', 
    '0371', 
    'A003', 
    '098001'
);

select * from Com;
