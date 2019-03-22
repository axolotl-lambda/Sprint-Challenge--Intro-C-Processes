**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

While there are more several additional states, the three we went over in class are running, asleep, and zombie. Running means that the process is currently active, using the CPU, and so forth. Sleeping means the process is still alive but it's not doing anything at the moment. This is the case when it's waiting for something to happen, typically via a system call such as a pipe. Zombie means that the process has finished but it needs to stay around to deliver its return code to its parent process.

**2. What is a zombie process?**

A zombie process is a process that has terminated but that still needs to hand off its return code to its parent process.

**3. How does a zombie process get created? How does one get destroyed?**

A zombie process gets created when a child process dies. All processes become zombie processes when they did, even if for just a moment. Once the parent process reads the return code the zombie process will be destroyed.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Working in a compiled language means that our code will be compiled to machine code rather than bytecode. The machine code can be run directly by the CPU while bytecode needs be run through an interpreter. This extra step takes time. Thus, working in a compiled language will typically produce code that is faster than an interpreted language.
