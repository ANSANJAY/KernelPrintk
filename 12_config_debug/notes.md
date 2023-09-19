Using pr_debug() globally will cause a tremendous amount of logging so it is not very practical. To make the debug level more manageable, dynamic debugging was introduced.

We can activate it with CONFIG_DYNAMIC_DEBUG

Dynamic debug is designed to allow you to dynamically enable/disable kernel code to obtain additional kernel information

Currently, if CONFIG_DYNAMIC_DEBUG is set, then all pr_debug()/dev_dbg() and print_hex_dump_debug()/print_hex_dump_bytes() calls can be dynamically enabled per-callsite.

Dynamic debug does not operate over debugging messages written using other than those two functions.

Controlling dynamic debug Behaviour
===================================

The behaviour of pr_debug()/dev_dbg() are controlled via writing to a control file in the ‘debugfs’ filesystem. 

Thus, you must first mount the debugfs filesystem, in order to make use of this feature.

$mount -t debugfs none /sys/kernel/debug
$cd /sys/kernel/debug/dynamic_debug/

The behaviour of pr_debug()/dev_dbg() are controlled via writing to a control file in the ‘debugfs’ filesystem. 

Subsequently, we refer to the control file as: <debugfs>/dynamic_debug/control

For example, if you want to enable printing from source file svcsock.c, line 1603 you simply do

echo 'file svcsock.c line 1603 +p' > <debugfs>/dynamic_debug/control

Viewing Dynamic Debug Behaviour
===============================

cat <debugfs>/dynamic_debug/control

Syntax
==========

 echo “<matches> <ops><flags>” > <debugfs>/dynamic_debug/control


matches:  – ‘file’ string , ‘func’ string ,‘line’ line-range , ‘module’ string (seen in lsmod) , supports wildcard (* ?)

ops: 
- remove the given flags
+ add the given flags
= set to the given flags

flags:
p print the log message
f include the function name
l include the line number
m include the module name
t include the thread ID
_ no flags are set

Examples
============

// enable all the messages in file svcsock.c
echo -n 'file svcsock.c +p' >  <debugfs>/dynamic_debug/control

// enable all the messages in the NFS server module
echo -n 'module nfsd +p' >   <debugfs>/dynamic_debug/control

// enable all 12 messages in the function svc_process()
echo -n 'func svc_process +p' > <debugfs>/dynamic_debug/control

// disable all 12 messages in the function svc_process()
echo -n 'func svc_process -p' > <debugfs>/dynamic_debug/control

// enable all messages
echo -n '+p' > <debugfs>/dynamic_debug/control

// enable messages in files of which the paths include string "usb"
echo -n '*usb* +p' > <debugfs>/dynamic_debug/control

echo “file drivers/usb/core/* +p” > <debugfs>/dynamic_debug/control

Enable debug messages during boot process
===========================================

This allows debugging of core code or built-in modules during the boot process.

bootargs
– dyndbg=“QUERY” <-- for kernel
– module.dyndbg=“QUERY” < -- for module

Eg. dyndbg="file ec.c +p"

Enable dynamic debug for multiple files at boot
=================================================

dyndbg='file drivers/<filename1> +p; file drivers/<filename2> +p; file drivers/<filename3> +p'

Case Study
===============

$ echo 'file drivers/usb/core/* =p' > /sys/kernel/debug/dynamic_debug/control

Plug a USB device into the USB host port.

$ dmesg


$ echo -n 'module e1000 +p' > control

$ ifconfig <interface> up/down



