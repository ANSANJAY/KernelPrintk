What is a console?
======================

For Linux, a console is a device to which you can write text data and read text data.

By default, the console is the (text-mode) screen and keyboard. One can switch to that console by pressing Ctrl+Alt+Fn, where n is 1 to 6. 

When one boots his PC, the kernel prints a lot of messages, like "initializing this...", "initializing that...". These all get printed via printk that sends the message to the console driver.

So why don't the kernel messages appear when in graphics mode?
=============================================================

In Linux, graphics mode is implemented not inside the kernel (and thus it cannot print messages in graphics mode), but as a usermode process called X, or sometimes X server

Every program that wants to, say, display a window, sends a message via IPC to the X server and says it how it (the X server) should draw the window. 

Of course, this message passing is implemented in a shared library, so from the application writer point of view, it's just a call to a function that displays the window

xterm is one of the many graphical applications (Konsole and gnome-terminal are the other two well-known programs) that emulates a terminal. 

xterm passes all keystrokes to the shell it runs and the resultant text is drawn graphically using the selected font (by using some functions in a shared library that send messages to the X server and tell it to draw the characters)

Kernel messages are not output from the shell, so xterm does not receive them, and therefore does not print (err.. draw) them.

Switch to CTRL+ALT+F4 or any other.

To Return to GUI: CTRL+ALT+F2 
