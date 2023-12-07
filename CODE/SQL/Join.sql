DROP DATABASE IF EXISTS jointest;
CREATE DATABASE jointest;

\c jointest


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
INSERT INTO t2 VALUES (2, 'yyy');
INSERT INTO t2 VALUES (3, 'zzz');

--???   Ripassa cosa fa CROSS JOIN 

SELECT * FROM t1 CROSS JOIN t2;
SELECT * FROM t1 CROSS JOIN t2 LIMIT 2;
SELECT * FROM t1 CROSS JOIN t2 OFFSET 6;
SELECT * FROM t1 INNER JOIN t2 ON t1.num = t2.num;
SELECT * FROM t1 INNER JOIN t2 USING (num); 

--***   USING() Elimina num ridondante
--???   Ripassa cosa fa NATURAL

SELECT * FROM t1 NATURAL INNER JOIN t2;
SELECT * FROM t1 LEFT JOIN t2 ON t1.num = t2.num;
SELECT * FROM t1 LEFT JOIN t2 USING(num);
SELECT * FROM t1 RIGHT JOIN t2 ON t1.num = t2.num;

---***  FULL JOIN unione di RIGHT e LEFT join

SELECT * FROM t1 FULL JOIN t2 ON t1.num = t2.num;