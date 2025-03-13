# Embedded Linux Device Drivers

## Linux Architecture

Linux is primarily divided into **User Space** and **Kernel Space**. These two components interact through a **System Call Interface**, which is a predefined and mature interface to the Linux Kernel for Userspace applications. The diagram below provides a basic understanding:

### Kernel Space

- Kernel space is where the kernel (the core of the operating system) executes and provides its services.

![Kernel Space](https://camo.githubusercontent.com/60dad2d1fbf1a720824b4d3ec4c4cb169b88f66345a26f37094fe1b793a9c786/68747470733a2f2f656d626574726f6e6963782e636f6d2f77702d636f6e74656e742f75706c6f6164732f323031372f30382f6b65726e656c2d73706163652d76732d757365722d73706163652e706e67)

### User Space

- User Space is where user applications are executed.

---

## Linux Kernel Modules

- Kernel modules are pieces of code that can be loaded and unloaded into the kernel on demand. They extend the functionality of the kernel without requiring a system reboot.

- Custom code can be added to Linux kernels via two methods:
  1. **In-tree Kernel Module**: Add the code to the kernel source tree and recompile the kernel.
  2. **Out-of-tree Kernel Module**: Load code at runtime without recompiling the kernel. This process is called loading the module, referring to the code you want to add. These are called **Loadable Kernel Modules (LKM)**.

- LKMs can perform a variety of tasks, but generally fall into three main categories:
  - Device drivers
  - Filesystem drivers
  - System calls

---

## LInux Device Drivers

- A device driver is designed for a specific piece of hardware. The kernel uses it to communicate with that hardware without having to know its internal details.

---

## File System Drivers

- A filesystem driver interprets the contents of a filesystem (typically the contents of a disk drive) as files and directories.
- There are many ways to store files and directories (e.g., on disk drives, network servers). Each way needs its own filesystem driver.
- Examples: **ext2**, **MS-DOS** filesystem, **NFS**, etc.

---

## System Calls

- Userspace programs use **system calls** to get services from the kernel (e.g., reading a file, creating a new process, shutting down the system).
- Most system calls are integral to the system and are built into the base kernel (no LKM option).

---

## Advantages of LKM

1. **No need to keep rebuilding the kernel** whenever you add a new device or upgrade an old device. This saves time and helps keep the base kernel error-free.
2. **Flexibility**: LKMs can be loaded/unloaded with a single command, saving memory by only loading them when needed.

---

## Differences Between Kernel Modules and User Programs

1. **Address Spaces**: A module runs in kernel space; an application runs in userspace. Kernel space and user space have their own memory address spaces.
2. **Execution Privileges**: Kernel modules have greater privilege than user programs.
3. **Execution Model**: User programs typically run sequentially, while a kernel module registers itself to serve future requests.
4. **Header Files**: Kernel modules require a different set of header files than user programs.

---

## Difference Between Kernel Drivers and Kernel Modules

- A **kernel module** is compiled code inserted into the kernel at runtime (e.g., with `insmod` or `modprobe`).
- A **driver** is code that runs in the kernel to talk to hardware. It “drives” the hardware. Almost every hardware component in your computer has an associated driver.

---

## Device Driver

- A device driver is a particular form of software designed to enable interaction with hardware devices.
- Without the required device driver, the corresponding hardware fails to work.
- A device driver usually communicates with the hardware via the communications subsystem or computer bus.
- Device drivers are operating system-specific and hardware-dependent.
- It acts as a translator between the hardware device and the programs or operating systems that use it.

### Types
1. **Character Driver**
2. **Block Driver**
3. **Network Driver**

> In Linux, everything is a file, meaning Linux treats all hardware devices as files.

---

### Character Device

- A char file is a hardware file that reads/writes data in a character-by-character fashion.
- Classic examples include keyboards, mice, and serial printers.

### Block Device

- A block file is a hardware file that reads/writes data in blocks rather than character by character.
- Useful for bulk read/write operations.
- Examples: HDD, USB drives, and CD-ROMs.

### Network Device

- A network device, from Linux’s perspective, is an entity that sends and receives data packets.
- Examples: Ethernet, Wi-Fi, Bluetooth.

---

## First Linux Device Driver

### Module Information

The following pieces of information are typically found in **linux/module.h** as macros:

- **License**
- **Author**
- **Module Description**
- **Module Version**

#### License

- GPL (GNU General Public License) is an open-source license meant for software.
  ```c
  MODULE_LICENSE("GPL");
  MODULE_LICENSE("GPL v2");
# Author
Using this macro, you can specify who wrote the Linux device driver or module:

```c
MODULE_AUTHOR("VINAY KUAMR RATHOR ");
Module Description
This macro allows you to give a description of the module or Linux device driver:


MODULE_DESCRIPTION("A sample driver");
