📊 CPU Scheduling Algorithms (Non-Preemptive)


🚀 Overview
This project implements Non-Preemptive CPU Scheduling Algorithms using C. It helps in understanding how different scheduling strategies work in an Operating System by calculating key metrics such as Waiting Time, Turnaround Time, and Completion Time.
CPU scheduling is a fundamental OS concept that decides which process gets CPU time. Non-preemptive scheduling ensures that once a process starts execution, it runs till completion without interruption. 
Studocu

🧠 Algorithms Implemented
The project includes the following non-preemptive scheduling algorithms:

🔹 First Come First Serve (FCFS)
🔹 Shortest Job First (SJF – Non-Preemptive)
🔹 Priority Scheduling (Non-Preemptive)

These algorithms are widely used for process management and performance optimization in operating systems.

⚙️ Features
📥 User input for processes (PID, Arrival Time, Burst Time, Priority)

📊 Calculates:

Completion Time (CT)
Turnaround Time (TAT)
Waiting Time (WT)

📈 Displays scheduling results in tabular format
🧮 Easy-to-understand logic for academic learning


🏗️ Project Structure

SchedulingAlgorithmNonPreemptive/
│── fcfs.c
│── sjf.c
│── priority.c
│── README.md


🛠️ How to Run


1️⃣ Clone the Repository
Bash

git clone https://github.com/satishkumarpeddi/SchedulingAlgorithmNonPreemptive.git
cd SchedulingAlgorithmNonPreemptive


2️⃣ Compile the Program
Bash

gcc fcfs.c -o fcfs
gcc sjf.c -o sjf
gcc priority.c -o priority


3️⃣ Run the Program
Bash

./fcfs
./sjf
./priority
📌 Sample Input

Enter number of processes: 3

PID   AT   BT   Priority
P1    0    5    2
P2    1    3    1
P3    2    8    3
📌 Sample Output

PID   AT   BT   CT   TAT   WT
P1    0    5    5    5     0
P2    1    3    8    7     4
P3    2    8    16   14    6

Average Waiting Time = 3.33
Average Turnaround Time = 8.66


📖 Key Concepts


Waiting Time (WT) = Turnaround Time – Burst Time
Turnaround Time (TAT) = Completion Time – Arrival Time
Non-preemptive scheduling does not interrupt running processes, making it simple but sometimes inefficient for shorter jobs. 
Scribd

🎯 Use Cases


Operating System Lab programs
Academic projects
Interview preparation

Understanding scheduling concepts visually

🤝 Contributing
Contributions are welcome!


Feel free to:

Fork the repository
Create a new branch
Submit a pull request

📜 License
This project is open-source and available under the MIT License.

👨‍💻 Author
Satish Kumar Peddi

GitHub: https://github.com/satishkumarpeddi
