# Bread & Roti POS System (From Daily Routine to C++ Code)

A practical C++ solution developed to automate the daily routine of auditing quantities, calculating net profits, and tracking supplier budgets at a local bakery retail shop. This project replaces error-prone manual ledger calculations with three interconnected CLI programs operating over a unified flat-file database.

## 📁 System Architecture & Modules

The system is partitioned into 3 specialized programs that share data through `Reports.txt`:

1. **MyProject.cpp (The Core POS):** Takes daily inventory inputs (such as Bread, Roti, and other items from `Data.txt`), calculates the bakery owner's budget, processes remaining stocks, computes net profits, and saves a timestamped record to the data layer.
2. **ShowReportsMyProject.cpp (Reporting Dashboard):** Reads historical data logs from `Reports.txt` and renders previous days' sales records into a clean, structured tabular grid format.
3. **PlainReports.cpp (Market Trend Analyzer):** Evaluates business metrics by calculating the daily variance (increase/decrease) in core items like Bread and Roti quantities compared to the preceding day, helping track market fluctuations.

## 🛠️ Tech Stack & Skills Applied
* **Language:** C++
* **Concepts Used:** File Handling (`fstream`), Vectors & Iterators, Structs, Date/Time Manipulation (`ctime`), Data Splitting (`SplitString`), and Modular Programming.
* **Current Phase:** Currently refactoring the entire codebase using Object-Oriented Programming (OOP) paradigms to enhance scalability and performance.
