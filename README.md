 C-Login-System

A simple C++ login and registration system with password recovery functionality.

 Features

* User registration with username and password
* Login verification
* Forgot password option (search by username)

 File

* `log_In.cpp` - Main C++ source code file containing all functionality.

 How to Run

1. Clone the repository:
   `git clone https://github.com/Biruk9/C-Login-System.git`
2. Navigate to the project folder and compile the code using a C++ compiler:
   `g++ log_In.cpp -o login_system`
3. Run the executable:
   `./login_system`

Technologies Used

* C++
* File Handling (for storing user records)

Notes

* Records are saved in `records.txt` automatically when registering new users.
* Make sure `records.txt` is in the same directory as the executable for proper functionality.

