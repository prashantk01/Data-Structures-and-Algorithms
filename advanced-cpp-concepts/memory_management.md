
### ```Memory and Storage classes```


Storage classes are something that define scope, lifetime and linkage of the variables.
Scope: where this variable can be used? Local or global
Lifetime: when this variable was created and to be destroyed?
Linkage: Whether this variable can be used in other files? (Internal/External)
	
    1. Const variable: once value defined, modification is not allowed after initialization. const int x = 10; 
	2. Volatile variable: value may change in run time (by thread, hardware etc.) so compiler won’t cache this variable in register. Prevents compiler optimization, force compiler to read/write from memory. volatile int x=10; (Also data type will not change).
	3. Static variable : Limits access. Prevents data access from other files (for global) or extends lifetime (for local). Has same behavior as global variable if dealing with single file. Uses keyword static, provides static lifetime (entire program duration).
		a. Static variable (local): Scope is function, lifetime is entire program means when invoked next time value is not lost, linkage is none.
		b. Static variable (global): scope is file, lifetime is entire program, linkage is internal limited to this file only. prevents access in other files using extern keyword as well.
		c. Static class variable: scope is class, lifetime is entire program. This belongs to class shared by all the objects.
	4. Auto & register: deprecated in old C++ versions.
	5. Extern: used for cross file access. Scope is global, lifetime is program, linkage is external.


### ```Stack vs Heap vs TLS```

Stack: - Very fast - Size limited (1-8 MB) - Grows downward - Automatic memory management - Function calls and local variables - Each thread has its own stack

Heap: - Slower than stack - Large in size (GBs) - Grows upward - Manual memory management (new/malloc, delete/free) - Shared among all threads (needs synchronization)

TLS (Thread-Local Storage): - Each thread gets its own separate copy of variables - Keyword: thread_local - Prevents race conditions ON THE TLS VARIABLE ITSELF - Does NOT prevent race conditions on shared variables - Use when you need per-thread state without locking


### ```Physical Memory (Hardware)```

	1. Registers (CPU) - Fastest, smallest
	2. Cache (L1, L2, L3) - Very fast, small
	3. RAM (Main Memory) - Fast, large
	4. Disk/SSD (Storage) - Slow, very large
RAM Memory sections: 

Stack (local variable, function call - function parameters, return addresses)<br>
Heap (dynamic allocation)<br>
.data (globally initialized data - Globally AND statically initialized data)<br>
.rodata (read only data - const global, string literals)<br>
.text (code, main)<br>
.bss (Uninitialized global/static data, zero-initialized)<br>
TLS - thread local storage<br>

### ```TLB and Paging```

TLB(Translation lookaside buffer) is cache memory associated to CPU memory which stores recently used page table entries.<br>
Page Table: The page table, stored in RAM, maps virtual page numbers to physical frame numbers.<br>
Frames: RAM is fragmented in frames fix size blocks called frames. 

Virtual Logical Address = Offset + Virtual Page Number. <br>

Process:<br>

    1. CPU generates virtual logical address for any process execution by user or OS.
	2. CPU checks if virtual page number exist in TLB? 
		a. If required virtual page number exist in TLB cache, it returns the frame number and physical memory address.  This is TLB hit case, very fast memory access.
		b. If it does not exit, it is TLB miss.
	3. For TLB Miss case, CPU starts page table walk search in RAM, extract frame number and then updates this entry in TLB. It is slower as it searching across RAM.

Huge-page?<br>
Larger page sizes (2 MB or 1 GB instead of 4 KB) which takes less pages to cover virtual memory mapping, Now one TLB covers more memory, increase TLB hit rate and better performance.

Page faults?<br>
If the PTE(page table entry) indicates the page is not currently in RAM, the CPU triggers a page fault exception. A page fault is an exception raised by the CPU when a process accesses a virtual page that is not currently mapped to a physical frame in RAM, requiring the OS to handle the fault by loading the page or terminating the process. Page replacement algorithms (LRU, Clock, FIFO) — how the OS decides which page to evict during a page fault.

### ``Explain the C++ memory model?``
The C++ memory model defines how memory operations are ordered and made visible across multiple threads. It introduces concepts like atomic operations, happens-before relationships, memory ordering, and synchronization primitives to ensure correct behaviour in concurrent programs and to prevent data races.








