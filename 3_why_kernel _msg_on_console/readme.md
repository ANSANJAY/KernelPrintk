# **Console and Graphical Mode in Linux**

In the world of Linux, a `console` is a special kind of device that facilitates text-based input-output operations. 
- For Linux, a console is a device to which you can write text data and read text data.
- In simpler terms, it's a place where you can type commands and see text-based outputs.

Initially, when **Linux boots**, it's in `text mode`. 
- The numerous initialization messages you see like "Setting up X..." or "Loading Y..." are displayed on the `console`. 
-These messages are generated using the `printk` function, which relays the message to the console driver.

However, **most users** interact with Linux in a `graphical environment,` like GNOME, KDE, or another GUI. 
- This graphical interface is powered by a `user-mode process` called the `X server`, often just called "X." 
- X is responsible for rendering the GUI, including windows, buttons, and text.

----

Applications communicate with X to render graphics.
-  For example, `xterm`, `Konsole`, and `gnome-terminal` are terminal emulators in the GUI. 
- They translate user keystrokes into commands and display outputs by rendering text in the graphical environment.

## Now, you might wonder: why don't kernel messages pop up in the graphical interface? 
---

The reason is simple: kernel messages aren't outputs of any shell that's running within the GUI.
- Since the terminal emulator (like `xterm`) doesn't receive these kernel messages, they aren't rendered in the GUI.

- In Linux, graphics mode is implemented not inside the kernel (and thus it cannot print messages in graphics mode), but as a `usermode process called X`, or sometimes X server

- Every program that wants to, say, display a window, sends a message via IPC to the X server and says it how  the X server should draw the window. 

- Of course, this message passing is implemented in a shared library, so from the application writer point of view, it's just a call to a function that displays the window

- `xterm` is one of the many graphical applications (Konsole and gnome-terminal are the other two well-known programs) that emulates a terminal. 

- xterm passes all keystrokes to the shell it runs and the resultant text is drawn graphically using the selected font (by using some functions in a shared library that send messages to the X server and tell it to draw the characters)

- Kernel messages are not output from the shell, so xterm does not receive them, and therefore does not print (err.. draw) them.

---
For direct console access, you can switch between different TTYs using `CTRL+ALT+Fn` combinations.

- And to return to the graphical environment, `CTRL+ALT+F2` is commonly used.

---


*Q: How does Linux handle graphics?*

*A: Linux handles graphics through a user-mode process known as the `X server`, which is responsible for rendering the graphical user interface.*

*Q: Why don't kernel messages pop up in the GUI like `gnome-terminal`?*

*A: Kernel messages are `not outputs from the shell that GUI terminal emulators, like gnome-terminal, communicate with`. 
- Hence, these emulators do not receive or render kernel messages in the GUI.

*Q: What's the purpose of terminal emulators like `xterm` in the graphical environment?*

*A: Terminal emulators like `xterm` provide a command-line interface within the graphical environment. They capture user keystrokes, send them to the shell for processing, and then display the output graphically.*

---

**3. Simple Explanation 🌟**

Imagine your Linux OS as a big theater. The console is like the backstage area where all the preparation happens. 
- It's all behind-the-scenes stuff with a lot of technical chatter. 
- When you boot up Linux, you're initially peeking backstage.

---

Then, when you start your graphical environment, it's like the curtain rises, revealing a grand stage (your GUI) with actors, props, and effects. 
- This show is directed by the X server, and applications like `xterm` are actors on this stage.
---


Now, while the show is going on, the backstage chatter (kernel messages) doesn't just come out on the main stage. It remains backstage because it's not part of the show (GUI). 

If you ever want to peek backstage again, you can do so using `CTRL+ALT+Fn` shortcuts, but to return to the main show, use `CTRL+ALT+F2`.



------------------

Why kernel messages don't appear in shell in graphical mode?
=============================================================


What is a console?
======================



By default, the console is the (text-mode) screen and keyboard. One can switch to that console by pressing Ctrl+Alt+Fn, where n is 1 to 6. 

When one boots his PC, the kernel prints a lot of messages, like "initializing this...", "initializing that...". These all get printed via printk that sends the message to the console driver.

So why don't the kernel messages appear when in graphics mode?
=============================================================



Switch to CTRL+ALT+F4 or any other.

To Return to GUI: CTRL+ALT+F2 

