As a sample TAP file was taken file SampleFiles\CDRUSNWRUS2700391.

It was loaded to tattelecom test DB using stable version of TAPLoader. Then it's contents were copied to separate sample tables with the following scripts.

create table Tap3_File_Sample as select * from Tap3_File f where f.file_id = 1001110;

create table Tap3_call_Sample as select * from Tap3_Call c where c.file_id = 1001110;

create table Tap3_GprsCall_Sample as select * from Tap3_GprsCall c where c.file_id = 1001110;

create table Tap3_BasicService_Sample as select * from Tap3_BasicService s where s.event_id in ( select c.event_id from Tap3_Call c where c.file_id = 1001110);

create table Tap3_ChargeInfo_Sample as select * from Tap3_ChargeInfo i where i.event_id in ( select s.service_id from Tap3_BasicService s where s.event_id in ( select c.event_id from Tap3_Call c where c.file_id = 1001110));

create table Tap3_ChargeDetail_Sample as
select * from Tap3_ChargeDetail d where d.charge_id in (
 select i.charge_id from Tap3_ChargeInfo i where i.event_id in ( select s.service_id from Tap3_BasicService s where s.event_id in ( select c.event_id from Tap3_Call c where c.file_id = 1001110)));
 
 
 insert into Tap3_ChargeInfo_Sample (select * from Tap3_ChargeInfo i where i.event_id in ( select c.event_id from Tap3_GprsCall c where c.file_id = 1001110));
 
 insert into Tap3_ChargeDetail_Sample (
 select * from Tap3_ChargeDetail d where d.charge_id in (
 	select i.charge_id from Tap3_ChargeInfo i where i.event_id in ( select c.event_id from Tap3_GprsCall c where c.file_id = 1001110)));



