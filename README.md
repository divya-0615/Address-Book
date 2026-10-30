# 📒 Address Book Management System in C

## Project Overview

The **Address Book Management System** is a console-based application developed using the C programming language to manage and organize contact information efficiently.

The application allows users to store, retrieve, modify, delete, and display contact details through a simple menu-driven interface. It uses file handling to maintain contact records permanently, ensuring that the information remains available even after the program is closed.

This project demonstrates the practical implementation of fundamental C programming concepts, including structures, pointers, functions, file handling, string manipulation, and data validation.

## Project Objectives

- Develop a simple and efficient contact management system.
- Implement CRUD (Create, Read, Update, Delete) operations.
- Understand and apply structures for managing contact records.
- Implement file handling for permanent data storage.
- Perform contact searching and validation.
- Improve problem-solving and modular programming skills.

## Features

### 1. Add Contact
- Add new contact details to the address book.
- Store information such as name, phone number, email, city, and state.
- Validate user input before storing contact information.

### 2. Search Contact
- Search for existing contacts using their details.
- Supports case-insensitive name searching.
- Display matching contact information.

### 3. Edit Contact
- Modify the information of an existing contact.
- Update contact details whenever required.

### 4. Delete Contact
- Remove unwanted or outdated contact records.
- Maintain updated contact information.

### 5. Display Contacts
- Display all saved contacts.
- Organize and sort contact records based on the selected criteria.

### 6. File Handling
- Store contact information permanently using file operations.
- Retrieve previously saved records when the application starts.
- Maintain contact data even after program termination.

## Technologies & Concepts Used

| Technology / Concept | Application |
|---|---|
| C Programming | Core development language |
| Structures | Organizing contact information |
| Pointers | Efficient memory and data handling |
| Functions | Modular program development |
| File Handling | Permanent data storage |
| String Handling | Processing contact details |
| Data Validation | Ensuring valid user input |
| Sorting | Organizing contact records |

## Project Structure

The project is organized into separate modules to maintain readability and simplify code management.

```text
Address-Book/
│
├── main.c          # Main function and menu handling
├── contact.h       # Structure definitions and declarations
├── contact.c       # Contact management operations
├── file.c          # File handling operations
├── data/           # Contact data storage (if applicable)
│
└── README.md       # Project documentation
```

*Note: Adjust the filenames and folders according to your actual repository structure.*

## ⚙️ How to Run the Project

### Prerequisites

- GCC Compiler
- Any C-compatible IDE or code editor (VS Code, Code::Blocks, etc.)
- Basic knowledge of terminal commands

### Step 1: Clone the Repository

```bash
git clone YOUR_GITHUB_REPOSITORY_URL
```

### Step 2: Navigate to the Project Directory

```bash
cd Address-Book
```

### Step 3: Compile the Program

If your project contains multiple C source files:

```bash
gcc *.c -o address_book
```

### Step 4: Execute the Program

**Linux / macOS:**

```bash
./address_book
```

**Windows:**

```bash
address_book.exe
```

## 💻 Application Workflow

1. Run the application.
2. Select an operation from the main menu.
3. Enter the required contact information.
4. Perform operations such as adding, searching, editing, deleting, or displaying contacts.
5. Save and retrieve contact records through file handling.
6. Exit the application.

## Key Learning Outcomes

Through this project, I gained practical experience in:

- Implementing structures to organize real-world data.
- Understanding pointers and their applications in C.
- Performing file operations such as reading, writing, and updating records.
- Developing modular programs using functions.
- Implementing searching and sorting techniques.
- Applying input validation and string manipulation.
- Building a menu-driven application using C.

## Future Enhancements

- Implement a graphical user interface (GUI).
- Add advanced search options using multiple fields.
- Implement duplicate contact detection.
- Add password-based authentication.
- Improve data security through encryption.
- Integrate database support for better data management.

## Author

**Divya Ambadas Adam**

Electronics and Telecommunication Engineering

---

⭐ If you find this project useful, feel free to star the repository!

**Developed with ❤️ using C Programming.**
