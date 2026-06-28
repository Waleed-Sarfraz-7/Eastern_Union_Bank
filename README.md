# EUB — Banking Management System

A console-based banking management system built in C++ for my 1st semester project at UET Lahore. Supports multiple user roles with role-specific menus and persistent file-based storage.

---

## Features

**Multi-role access** — four account types with separate menus and permissions:
- **Admin** — full system control, view all accounts, manage reservoir
- **Manager** — add/delete accounts, manage employees and salaries, view feedbacks
- **Employee** — limited banking operations, view accounts and feedbacks
- **Customer** — personal banking, loans, bill payments, currency conversion

**Banking operations**
- Deposit, withdraw, transfer money
- Check balance
- Currency conversion (PKR ↔ USD)

**Loan module**
- Home loan, student loan, debt consolidation loan
- View active loans and pay off debt

**Bill payments**
- Water, electricity, and gas bills

**Additional**
- Feedback submission and review
- Bank reservoir tracking
- Employee salary management
- File-based data persistence (accounts, loans, feedback, reservoir)

---

## Getting Started

**Requirements**
- Windows OS
- C++ compiler (MinGW / MSVC)

**Build & run**
```bash
g++ waleedsarfraz.cpp -o eub.exe
./eub.exe
```

> Note: Uses Windows-specific headers (`windows.h`, `conio.h`). Will not compile on Linux/macOS.

---

## Tech Stack

- C++
- File I/O for data persistence
- Windows Console API for colored output

---

## Author

**Waleed Sarfraz** — 1st Semester, CS, UET Lahore
