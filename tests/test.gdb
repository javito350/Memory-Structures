set output-radix 0x10
set input-radix 0xa
target extended-remote localhost:50000
file build/main.elf
load
break checkpoint
set pagination off
set logging file tests/log
set logging enable on
break checkpoint
run
call create_list()
call remove_node($1, 772)
call list_length($2)
call list_size($2)
call create_list()
call remove_node($5, 337)
call list_length($6)
call list_size($6)
quit