# Windows Developer Environment Setup & Troubleshooting

### **The Problem**
Newly compiled `.exe` files (e.g., `guwo.exe`) are blocked by Windows with errors such as:
* *"Program failed to run: An Application Control policy has blocked this file"*
* *"Blocked by your organization's Device Guard policy"*

### **The Root Cause**
**Smart App Control (SAC)** or **WDAC** is active. These security layers block any "untrusted" or "unknown" executables that do not have a valid digital signature. This automatically includes almost all code written and compiled locally by developers.

### **The Permanent Solution**
1.  Open **Windows Security**.
2.  Go to **App & browser control**.
3.  Select **Smart App Control settings**.
4.  Set Smart App Control to **Off**.
    * *Note: This is usually a one-way toggle. Disabling it is often required for local C++ development on Windows 11.*

### **Supporting Configuration**
* **Antivirus Exclusions:** Add your development parent folder (e.g., `C:\Users\Santhosh\CPP Games`) to **Virus & threat protection > Manage settings > Exclusions**. This prevents the antivirus from locking files during the compilation process.
* **Static Linking Flags:** Use the following flags during compilation to ensure the executable is self-contained:
    ```bash
    g++ -static -static-libgcc -static-libstdc++ main.cpp -o main.exe
    ```
* **VS Code Code Runner Fix:** In `settings.json`, update the `executorMap` for C++ to automate the fix:
    ```json
    "code-runner.executorMap": {
        "cpp": "cd $dir && g++ -static $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
    }
    ```

### **Alternative for High-Security Systems**
If Windows policies still block execution, move development to a non-Windows kernel:
1.  **WSL (Windows Subsystem for Linux):** Run an Ubuntu terminal inside Windows.
2.  **Virtual Machine:** Use VMware Workstation Player to run a dedicated Linux development environment.