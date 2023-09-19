cat /proc/sys/kernel/printk


They are associated with the following variables: – 
console_loglevel: level under which the messages are logged on the console device 
 default_message_loglevel: priority level that is associated by default with messages for which no priority value is specified 
minimum_console_loglevel: minimum level to allow a message to be logged on the console device 
maximum_console_loglevel: maximum level 

$echo 8 > /proc/sys/kernel/printk
Will change the console_loglevel

$sudo dmesg -n 3
