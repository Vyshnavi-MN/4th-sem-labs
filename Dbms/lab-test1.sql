Queries:

1.
CREATE TABLE student( snum INT, sname VARCHAR(10), major VARCHAR(2), lvl VARCHAR(2), age INT, primary key(snum))
CREATE TABLE faculty( fid INT,fname VARCHAR(20), deptid INT, PRIMARY KEY(fid))
CREATE TABLE class( cname VARCHAR(20), metts_at TIMESTAMP, room VARCHAR(10), fid INT, PRIMARY KEY(cname), FOREIGN KEY(fid) REFERENCES faculty(fid))
CREATE TABLE enrolled( snum INT, cname VARCHAR(20), PRIMARY KEY(snum,cname), FOREIGN KEY(snum) REFERENCES student(snum))

                                                                                                                  
2.                                                                                                                 2.
INSERT INTO STUDENT VALUES(&snum, '&sname', '&major', '&lvl', &age);
INSERT INTO STUDENT VALUES(1, 'John', 'CS', 'Sr', 19)
INSERT INTO STUDENT VALUES(2, 'Smith', 'CS', 'Jr', 20)
INSERT INTO STUDENT VALUES(3, 'Jake', 'CV', 'Sr', 20)
INSERT INTO STUDENT VALUES(4, 'Tim', 'CS', 'Jr', 20)
INSERT INTO STUDENT VALUES(5, 'Rahul', 'CS', 'Jr', 20)
INSERT INTO STUDENT VALUES(6, 'Ritu', 'CS', 'Sr', 21)

SELECT * FROM `student`

INSERT INTO FACULTY VALUES(11, 'Harish', 1000)
INSERT INTO FACULTY VALUES(12, 'MV', 1000)
INSERT INTO FACULTY VALUES(13 , 'Mira', 1001)
INSERT INTO FACULTY VALUES(14, 'Shiva', 1002)
INSERT INTO FACULTY VALUES(15, 'Nupur', 1000)

SELECT * FROM `faculty`

insert into class values('class10', '12/11/15 10:15:16', 'R128', 14)
insert into class values('class2', '12/11/15 10:15:20', 'R2', 12)
insert into class values('class3', '12/11/15 10:15:25', 'R3', 12)
insert into class values('class4', '12/11/15 20:15:20', 'R4', 14)
insert into class values('class5', '12/11/15 20:15:20', 'R3', 15)
insert into class values('class6', '12/11/15 13:20:20', 'R2', 14
insert into class values('class6', '12/11/15 13:20:20', 'R2', 14)
insert into class values('class7', '12/11/15 10:10:10', 'R3', 14)

SELECT * FROM `class`

insert into enrolled values(1, 'class1')
insert into enrolled values(2, 'class2')
insert into enrolled values(3, 'class3')
insert into enrolled values(4, 'class4')
insert into enrolled values(5, 'class5')

SELECT * FROM `enrolled`

insert into enrolled values(5, 'class5')
insert into enrolled values(4, 'class5')
insert into enrolled values(3, 'class5')
insert into enrolled values(2, 'class5')
insert into enrolled values(1, 'class5')
Expand Requery Edit Explain Profiling Bookmark Database : vyshnavi Queried time : 15:27:4
SELECT * FROM `enrolled`

                         
                         

        3.SELECT DISTINCT S.sname FROM Student S WHERE S.snum IN 
          (SELECT E1.snum FROM Enrolled E1, Enrolled E2, Class C1, Class C2 WHERE 
           E1.snum = E2.snum AND E1.cname <> E2.cname AND E1.cname = C1.cname AND E2.cname = C2.cname AND C1.metts_at = C2.metts_at) 
                         
                         
        4.SELECT DISTINCT F.fname FROM Faculty F WHERE NOT EXISTS 
           ((SELECT C.room FROM Class C ) EXCEPT (SELECT C1.room FROM Class C1 WHERE C1.fid = F.fid )) 
                                                  
                                                  
        5.SELECT S.age, S.lvl FROM Student S GROUP BY S.age, S.lvl HAVING S.lvl IN 
            (SELECT S1.lvl FROM Student S1 WHERE S1.age = S.age GROUP BY S1.lvl, S1.age 
            HAVING COUNT(*) >= ALL (SELECT COUNT(*) FROM Student S2 WHERE s1.age = S2.age GROUP BY S2.lvl, S2.age)) 
                                    
  
