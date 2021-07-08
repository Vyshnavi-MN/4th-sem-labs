create user vyshnavi1 identified by vysh123;
grant dba to vyshnavi1;

CREATE TABLE branch
     ( branch_name VARCHAR(30),
       branch_city VARCHAR(30),
       assets real,
       PRIMARY KEY(branch_name)
     );
desc branch

CREATE TABLE bank_account
     ( accno INTEGER,
       branch_name VARCHAR(30),
       balance real,
       PRIMARY KEY(accno),
       FOREIGN KEY(branch_name) REFERENCES branch(branch_name)
     );
desc bank_account

CREATE TABLE bank_customer
    ( customer_name VARCHAR(30),
      customer_street VARCHAR(30),
      customer_city VARCHAR(30),
      PRIMARY KEY(customer_name)
    );
desc bank_customer

CREATE TABLE loan
    ( loan_number INTEGER,
      branch_name VARCHAR(30),
      amount real,
      PRIMARY KEY(loan_number),
      FOREIGN KEY(branch_name) REFERENCES branch(branch_name)
    );
desc loan

CREATE TABLE depositor
    ( customer_name VARCHAR(30),
      accno INTEGER,
      PRIMARY KEY(customer_name, accno),
      FOREIGN KEY(customer_name) REFERENCES bank_customer(customer_name),
      FOREIGN KEY(accno) REFERENCES bank_account(accno)
    );
desc depositor

insert  into branch values('SBI_Chamrajpet','Bangalore',50000);
insert  into branch values('SBI_ResidencyRoad','Bangalore',10000);
insert  into branch values('SBI_ShivajiRoad','Bangalore',20000);
insert  into branch values('SBI_ParlimentRoad','Delhi',10000);
insert  into branch values('SBI_Jantarmantar','Delhi',20000);

select * from branch;


insert into loan values(2,'SBI_Chamrajpet',1000);
insert into loan values(1,'SBI_ResidencyRoad',2000);
insert into loan values(3,'SBI_ShivajiRoad',3000);
insert into loan values(4,'SBI_ParlimentRoad',4000);
insert into loan values(5,'SBI_Jantarmantar',5000);

select * from loan;

insert into bank_account values(11,'SBI_Jantarmantar',2000);
insert into bank_account values(10,'SBI_ResidencyRoad',5000);
insert into bank_account values(9,'SBI_ParlimentRoad',3000);
insert into bank_account values(8,'SBI_ResidencyRoad',4000);
insert into bank_account values(6,'SBI_ShivajiRoad',4000);
insert into bank_account values(5,'SBI_Jantarmantar',8000);
insert into bank_account values(4,'SBI_ParlimentRoad',9000);
insert into bank_account values(3,'SBI_ShivajiRoad',6000);
insert into bank_account values(2,'SBI_ResidencyRoad',5000);
insert into bank_account values(1,'SBI_Chamrajpet',2000);

commit;