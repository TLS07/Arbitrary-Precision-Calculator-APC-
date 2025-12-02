# Arbitrary-Precision-Calculator-APC-
A C-based arbitrary-precision arithmetic calculator that supports operations on integers far beyond standard 32/64-bit limits. Implements custom big-number handling using dynamic memory for addition, subtraction, multiplication, and more.

✨ Features

💠Addition – Perform addition on arbitrarily large integers.

💠Subtraction – Subtract one large number from another with full precision.

💠Multiplication – Multiply very large numbers accurately.

💠Division – Compute quotient (and internally remainder) for large-number division.

🧱 Data Structures
Doubly Linked List

Large numbers are stored using a custom doubly linked list:

💠Node – Each node stores a 4-digit chunk for efficiency.

💠List – Expands dynamically to support numbers of any size.

💠Enables flexible insertion, deletion, and traversal required for big-integer arithmetic.
