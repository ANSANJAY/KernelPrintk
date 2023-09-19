**1. Explain the technical concept 📚**

In the Linux kernel, the `printk` function is used to produce log messages. If no log level is specified when using `printk`, the kernel will assign a default log level to that message. This default log level is determined by the value of `default_message_loglevel`.

The file `/proc/sys/kernel/printk` provides a way to control the behavior of kernel logging. When you `cat /proc/sys/kernel/printk`, you get four numbers, which are associated with:

1. `console_loglevel`: This determines the minimum level at which messages will be printed to the console. Messages with a level below this will not be displayed.
2. `default_message_loglevel`: If a `printk` message doesn't have a specified log level, it will be given this default level.
3. `minimum_console_loglevel`: This sets the absolute minimum level for messages to be logged to the console. Even if `console_loglevel` is set lower than this, messages won't be displayed if they're below this minimum level.
4. `maximum_console_loglevel`: Sets the absolute maximum level for messages to be logged to the console. Messages with levels above this won't be displayed, even if `console_loglevel` is higher.

Using the command `$echo 8 > /proc/sys/kernel/printk` will change the `console_loglevel` to 8, which is usually beyond the standard log levels and might effectively mute console messages. 

The `dmesg -n 3` command adjusts the `console_loglevel` directly, without needing to manually echo into `/proc/sys/kernel/printk`. It sets the level to 3 (`KERN_ERR`), which means only emergency, alert, and critical messages will be displayed on the console.

---

**2. Technical Interview Questions about this topic (and answers) 🤓**

*Q: If a developer uses `printk` without specifying a log level, which variable determines the level of that message?*

*A: The level of that message will be determined by `default_message_loglevel`.*

*Q: If you want to ensure only critical and above messages (like emergencies and alerts) are displayed on the console, what command can you use?*

*A: You can use the command `sudo dmesg -n 3` to set the `console_loglevel` to 3, ensuring only messages of level 3 (`KERN_ERR`) and above (emergency and alert) are shown.*

---

**3. Simple Explanation for Easy Recall 🌟**

Imagine you're in a busy newsroom with different kinds of news coming in. The editor (the kernel) decides which news (messages) to show on the main screen (console). 

- Some news is so critical that it's always shown, like breaking news of a major event. That's like high-priority log levels.
- Some news might be general updates, like weather reports. They can be shown, but not always.
- Lastly, there's news that's not worth showing on the main screen, like a minor local event.

Now, the editor uses a set of rules (log levels in `/proc/sys/kernel/printk`) to decide which news to show. If the reporters (developers using `printk`) don't label their news (don't specify log level), the editor uses a default label (uses `default_message_loglevel`).

The command `dmesg -n 3` is like telling the editor to only focus on the most critical news and ignore the rest for the main screen.


----

What happens if we don't specify a log level in the printk

cat /proc/sys/kernel/printk


They are associated with the following variables: – 
console_loglevel: level under which the messages are logged on the console device 
 default_message_loglevel: priority level that is associated by default with messages for which no priority value is specified 
minimum_console_loglevel: minimum level to allow a message to be logged on the console device 
maximum_console_loglevel: maximum level 

$echo 8 > /proc/sys/kernel/printk
Will change the console_loglevel

$sudo dmesg -n 3

----