**1. Explaining the Technical Concept 📘**

**Dynamic Debugging in Linux Kernel**

In the Linux kernel, logging plays an indispensable role, helping developers troubleshoot and understand the internal workings. However, a naive approach using `pr_debug()` can be overwhelming due to the sheer volume of logs. Enter **Dynamic Debugging**.

Dynamic debugging is controlled by the kernel configuration option `CONFIG_DYNAMIC_DEBUG`. When activated:
- Calls to `pr_debug()/dev_dbg()` and `print_hex_dump_debug()/print_hex_dump_bytes()` can be toggled on/off on a per-call site basis.
- The system ignores debug messages not using these specific calls.

To use this feature, the debugfs filesystem must be mounted:
```bash
$ mount -t debugfs none /sys/kernel/debug
```

Control over which debug statements are active is managed by a control file in the `debugfs` filesystem, commonly referenced as `<debugfs>/dynamic_debug/control`.

**Syntax** for controlling which logs get printed:
```bash
echo “<matches> <ops><flags>” > <debugfs>/dynamic_debug/control
```

Various flags control the inclusion of data like function name, line number, module name, etc.

**2. Interview Questions and Answers 💼**

- **Q1**: How can you activate dynamic debugging in the Linux kernel?
  - **A1**: By setting the kernel configuration option `CONFIG_DYNAMIC_DEBUG`.

- **Q2**: What is the primary purpose of dynamic debugging?
  - **A2**: Dynamic debugging allows developers to dynamically enable/disable kernel debug logging for specific call sites, making debugging more manageable and less noisy.

- **Q3**: Which filesystem needs to be mounted to use the dynamic debug feature?
  - **A3**: The `debugfs` filesystem needs to be mounted.

- **Q4**: How do you enable debugging messages for a specific source file and line using dynamic debugging?
  - **A4**: By writing to the control file in debugfs. Example: `echo 'file svcsock.c line 1603 +p' > <debugfs>/dynamic_debug/control`.

- **Q5**: What would the following command achieve?
  ```bash
  echo -n 'module nfsd +p' > <debugfs>/dynamic_debug/control
  ```
  - **A5**: It would enable all debug messages in the NFS server module.

**3. Simple Explanation for Quick Recollection 🌟**

Imagine you're in a room full of talkative people, and it's super noisy. It's tough to focus on just one person's speech. This is how the kernel feels when all debug logs are on. 

Now, what if you could mute everyone and only give a microphone 🎤 to the person you want to hear from? Dynamic Debugging is like that microphone. Instead of listening to everyone (every module, every function), you only "listen" to the specific parts you're interested in. It's a way to silence 🤫 the noise and focus on what matters.

Remember: Just like deciding who gets the microphone, you choose which part of the kernel code you want to debug. It's all about filtering out the noise and hearing the right things! 🎧👂


----------

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



