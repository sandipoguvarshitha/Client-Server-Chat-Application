# Client-Server-Chat-Application-using-TCP-Sockets-and-System-V-Message-Queues

A powerful **Client-Server Chat Application** developed in **C Programming** using:

* TCP Socket Programming
* System V Message Queues
* Linux System Programming
* Inter Process Communication (IPC)

This project demonstrates real-time communication between multiple clients through a centralized server process using Linux IPC mechanisms.

The application allows multiple clients to:

* Connect to a centralized server
* Send messages in real time
* Receive messages concurrently
* Communicate using TCP sockets
* Exchange messages through System V Message Queues

---

# ✨ Features

## 🖥️ Centralized Server Communication

* Dedicated server handles all client communication
* Receives messages from clients
* Forwards messages to destination clients

---

## 👥 Multi-Client Support

* Multiple clients can connect simultaneously
* Supports client-to-client communication

---

## 📨 Real-Time Messaging

* Instant message delivery
* Concurrent send and receive operations

---

## ⚡ Concurrent Communication

Uses `fork()` for simultaneous:

* Sending messages
* Receiving messages

---

## 🔒 System V IPC Mechanism

Implements:

* `msgget()`
* `msgsnd()`
* `msgrcv()`

for message queue communication.

---

## 🌐 TCP Socket Programming

Uses:

* `socket()`
* `bind()`
* `listen()`
* `accept()`
* `connect()`
* `read()`
* `write()`

for network communication.

---

# 🛠️ Technologies Used

* C Programming
* Linux System Programming
* TCP/IP Socket Programming
* System V Message Queues
* Inter Process Communication (IPC)
* Process Management using `fork()`

---

# 📂 Project Structure

```text
.
├── server.c
├── client.c
├── header.h
└── README.md
```

---

# 📌 Working Principle

1. Server creates a TCP socket
2. Server waits for client connections
3. Multiple clients connect to server
4. Clients send messages to server
5. Server stores messages using message queue
6. Server forwards messages to destination clients
7. Clients receive messages in real time

---

# 🔥 Key Concepts Demonstrated

✔️ TCP Socket Programming

✔️ Client-Server Architecture

✔️ Inter Process Communication (IPC)

✔️ System V Message Queues

✔️ Concurrent Processing using `fork()`

✔️ Linux System Calls

✔️ Real-Time Communication

✔️ Process Synchronization

---

# ⚙️ Setup & Installation Guide

## 📥 Clone the Repository

```bash
git clone https://github.com/sandipogu/Client-Server-Chat-Application.git

cd Client-Server-Chat-Application
```

---

# 🛠️ Requirements

## Linux Environment Required

This project is designed for:

* Ubuntu
* Debian
* Kali Linux
* Fedora
* Arch Linux

---

# Required Compiler

## Install GCC Compiler

### Ubuntu / Debian

```bash
sudo apt update
sudo apt install build-essential
```

### Fedora

```bash
sudo dnf install gcc
```

### Arch Linux

```bash
sudo pacman -S gcc
```

---

# 📄 Header File

The `header.h` file includes all required libraries:

```c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
```

---

# ▶️ Compile the Programs

## Compile Server

```bash
gcc server.c -o server
```

## Compile Client

```bash
gcc client.c -o client
```

---

# ▶️ Run the Application

## Step 1: Start the Server

```bash
./server 2000 127.0.0.1
```

### Output

```text
waiting for client request
```

---

## Step 2: Start Client 1

Open another terminal:

```bash
./client 2000 127.0.0.1
```

---

## Step 3: Start Client 2

Open another terminal:

```bash
./client 2000 127.0.0.1
```

---

# 💬 Example Communication

## Client 1

```text
enter the message to send
Hello
```

---

## Client 2 Receives

```text
message:Hello
```

---

# 🧩 Message Structure

```c
struct msgbuf
{
    long mtype;
    char mtext[100];
};
```

---

# 📚 Important System Calls Used

| Function  | Purpose                     |
| --------- | --------------------------- |
| socket()  | Create socket               |
| bind()    | Bind IP and port            |
| listen()  | Listen for connections      |
| accept()  | Accept client connection    |
| connect() | Connect client to server    |
| read()    | Receive data                |
| write()   | Send data                   |
| fork()    | Create concurrent processes |
| msgget()  | Create/access message queue |
| msgsnd()  | Send message to queue       |
| msgrcv()  | Receive message from queue  |

---

# 🚀 Future Enhancements

* Multi-user group chat
* Username support
* Broadcast messaging
* Message encryption
* Chat history storage
* GUI-based chat interface
* Client authentication
* Online user status
* File sharing support

---

# ⚠️ Important Notes

* Works only on Linux/Unix systems
* Server must start before clients
* Multiple clients can connect simultaneously
* Message queue persists until removed manually
* Uses TCP protocol for reliable communication

---

# 🧹 Remove Existing Message Queue

Check message queues:

```bash
ipcs -q
```

Remove queue manually:

```bash
ipcrm -q <queue_id>
```

---

# 👨‍💻 Learning Outcomes

This project helps understand:

* TCP Socket Programming
* Linux IPC Mechanisms
* System V Message Queues
* Concurrent Programming
* Process Creation using `fork()`
* Real-Time Communication Systems
* Client-Server Application Development

---

# ⭐ Support

If you found this project useful:

⭐ Star the repository

🍴 Fork the project

🛠️ Contribute improvements

---

# 👨‍💻 Author

Developed using C Programming, Linux Socket Programming, and System V Message Queues.
