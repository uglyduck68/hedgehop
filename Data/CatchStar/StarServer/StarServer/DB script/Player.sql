use star;

drop table players;

create table players (
	id							varchar(20) not null primary key,	# user ID that is created by server
	login_name			varchar(20),											# login ID that is create when user create account in server
	room_id				int,														# current game root #
	table_id				int,														# current game table #
	connected			int,														# 1 is connected, 0 is not connected
	money					int,														# total money that user have
	lconn_time			datetime												# last login time
);
	
show tables;