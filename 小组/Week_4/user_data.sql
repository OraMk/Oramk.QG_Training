DROP database IF EXISTS user_data;
CREATE database user_data;
USE user_data;
DROP TABLE IF EXISTS emp;
CREATE TABLE emp (
  `EMPNO` int NOT NULL,
  `ENAME` varchar(10) DEFAULT NULL,
  `JOB` varchar(9) DEFAULT NULL,
  `MGR` int DEFAULT NULL,
  `HIREDATE` date DEFAULT NULL,
  `SAL` double(7,2) DEFAULT NULL,
  `COMM` double(7,2) DEFAULT NULL,
  `DEPTNO` int DEFAULT NULL,
  PRIMARY KEY (`EMPNO`)
) ;

INSERT INTO emp VALUES ('7369', 'SMITH', 'CLERK', '7902', '1980-12-17', '880.00', null, '20');
INSERT INTO emp VALUES ('7499', 'ALLEN', 'SALESMAN', '7698', '1981-02-20', '1760.00', '300.00', '30');
INSERT INTO emp VALUES ('7521', 'WARD', 'SALESMAN', '7698', '1981-02-22', '1375.00', '500.00', '30');
INSERT INTO emp VALUES ('7566', 'JONES', 'MANAGER', '7839', '1981-04-02', '3272.50', null, '20');
INSERT INTO emp VALUES ('7698', 'BLAKE', 'MANAGER', '7839', '1981-05-01', '3135.00', null, '30');
INSERT INTO emp VALUES ('7782', 'CLARK', 'MANAGER', '7839', '1981-06-09', '2695.00', null, '10');
INSERT INTO emp VALUES ('7788', 'SCOTT', 'ANALYST', '7566', '1987-04-19', '3300.00', null, '20');
INSERT INTO emp VALUES ('7839', 'KING', 'PRESIDENT', null, '1981-11-17', '5500.00', null, '10');
INSERT INTO emp VALUES ('7844', 'TURNER', 'SALESMAN', '7698', '1981-09-08', '1650.00', '0.00', '30');
INSERT INTO emp VALUES ('7876', 'ADAMS', 'CLERK', '7788', '1987-05-23', '1210.00', null, '20');
INSERT INTO emp VALUES ('7900', 'JAMES', 'CLERK', '7698', '1981-12-03', '1045.00', null, '30');
INSERT INTO emp VALUES ('7902', 'FORD', 'ANALYST', '7566', '1981-12-03', '3300.00', null, '20');
INSERT INTO emp VALUES ('7934', 'MILLER', 'CLERK', '7782', '1982-01-23', '1430.00', null, '10');

DROP TABLE IF EXISTS user;
CREATE TABLE user (
  `Username` varchar(225) NOT NULL,
  `Password` varchar(225) DEFAULT NULL,
  PRIMARY KEY (`Username`)
) ;

INSERT INTO user VALUES ('QGStudio', 'QGStudio');
INSERT INTO user VALUES ('张三', '123456');
