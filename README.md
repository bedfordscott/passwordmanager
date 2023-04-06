#Password Manager
This is a simple password manager program written in C that encrypts passwords using the SHA-256 algorithm.

#Getting Started
To use the program, clone the repository to your local machine and compile the source code using a C compiler.
bash
git clone [repository url]
cd password-manager
gcc password-manager.c -lcrypto -o password-manager

#Usage
To add a new password, run the program and select option 1. You will be prompted to enter the website, username, and password. The password will be encrypted using SHA-256 and stored in a data file.

To view your passwords, run the program and select option 2. The program will display the website, username, and encrypted password for each entry.

#Features
Secure password storage using SHA-256 encryption
Simple command-line interface
Data persistence using file I/O
Built With
C programming language
OpenSSL library for SHA-256 encryption

#Contributors
Ford Scott

#License
This project is licensed under the MIT License - see the LICENSE file for details.

#Acknowledgments
OpenSSL
SHA-256 algorithm

#Contact
If you have any questions or feedback, please contact me at bedfordhscott@gmail.com
