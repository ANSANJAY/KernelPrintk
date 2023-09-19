No Use of Floating Point in Kernel
===================================

When a user-space process uses floating-point instructions, the kernel manages the transition from integer to floating point mode.

Why is floating point mode off?

	many programs don't use floating point or don't use it on any given time slice; and

	saving the FPU registers and other FPU state takes time; therefore

an OS kernel may simply turn the FPU off. Presto, no state to save and restore, and therefore faster context-switching. 

If a program attempts an FPU op, 
	the program will trap into the kernel, 
	the kernel will turn the FPU on, 
	restore any saved state that may already exist, and 
	then return to re-execute the FPU op.

At context switch time, it knows to actually go through the state save logic. (And then it may turn the FPU off again.)

The reason that the kernel doesn't particularly need FPU ops and also needs to run on architectures without an FPU at all. 

 Therefore, it simply avoids the complexity and runtime required to manage its own FPU context by not doing ops for which there are always other software solutions.


