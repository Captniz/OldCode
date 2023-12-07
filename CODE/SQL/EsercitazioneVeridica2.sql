DROP DATABASE IF EXISTS prova2;
CREATE DATABASE prova2;

\c prova2


DROP TABLE IF EXISTS t1;
CREATE TABLE t1 (
    num     smallint    NOT NULL,
    nome    char        NOT NULL,
    
    PRIMARY KEY (num)
);

DROP TABLE IF EXISTS t2;
CREATE TABLE t2 (
    num     smallint    NOT NULL,
    val     varchar(20) NOT NULL,
    
    PRIMARY KEY (num)
);


INSERT INTO t1 VALUES (1, 'a');
INSERT INTO t1 VALUES (2, 'b');
INSERT INTO t1 VALUES (3, 'c');

INSERT INTO t2 VALUES (1, 'xxx');
INSERT INTO t2 VALUES (3, 'yyy');
INSERT INTO t2 VALUES (5, 'zzz');

ALTER TABLE t1 DROP CONSTRAINT t1_pkey;
ALTER TABLE t2 DROP CONSTRAINT t2_pkey;

SELECT * FROM t1 CROSS JOIN t2 LIMIT 5;
SELECT * FROM t1 INNER JOIN t2 ON t1.num = t2.num;
SELECT * FROM t1 LEFT JOIN t2 ON t1.num = t2.num;
SELECT * FROM t1 RIGHT JOIN t2 ON t1.num = t2.num;
SELECT * FROM t1 FULL JOIN t2 ON t1.num = t2.num;
SELECT * FROM t1 LEFT JOIN t2 ON t1.num = t2.num AND t2.val = 'xxx';