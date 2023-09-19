printk is used in kernel programming to log messages and is very useful while debugging the kernel programs. 

But the kernel log being though big, is restricted and unnecessary logging at times can lead to loosing relevant messages . 

Thus kernel provides a function, printk_ratelimit , to restrict the logging using which we can set a limit on the number of prints that we want our program to do. 

The limit on the number of prints is set in the file /proc/sys/kernel/printk_ratelimit_burst 

$ cat /proc/sys/kernel/printk_ratelimit_burst 
10

The printk_ratelimit function will allow 10 prints before it starts blocking the further prints. 

The printk_ratelimit, returns 1 as long as the number of prints do not exceed the limit. Once the limit is reached it starts returning 0. 

Thus the function can be used as a condition for an "if" statement to decide whether to print a message or not. 

The printk will be enabled again after a time interval in seconds mentioned in the file /proc/sys/kernel/printk_ratelimit 

$ cat /proc/sys/kernel/printk_ratelimit
5

Which means, printk will be disabled for 5 seconds after 10 messages by the code which uses the printk_ratelimit function. 

In the example module we put 20 prints in the init function using a for loop. 

Before each print, printk_ratelimit is called to decide whether to print or not. 

When the module gets inserted, we will notice that only the first 10 prints are printed and the rest gets suppressed. 


