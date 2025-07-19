 
[English](#) | [简体中文](README_CN.md)

 # 🎯 Project Overview

 This is a lightweight compiler that converts Lua scripts into CS2-compatible CFG format.  
 `lcfg` uses standard Lua syntax.

 > Project forked from **-Cap1taL-**
 

 ---

 # 🚀 Features

 - Compile custom Lua scripts into CFG files  
 - Built-in `lcfg` functions extending Lua's capabilities  
 - Smooth view control and advanced movement commands  
 - Customizable `exec` path for integration  

 ---

 # 📚 Supported lcfg Functions

 Based on Lua syntax, you can use the following functions defined by `lcfg`:

 - `<basecmd>(number)`: Execute basic actions like moving or attacking, equivalent to `basecmd x 0 0` in CFG  
 - `jump()`: Performs a jump  
 - `sleep(ticks)`: Delay execution by ticks  
 - `jumpbug()`: Executes jumpbug technique  
 - `setAngle(yaw, pitch)`: Sets view angles  
 - `angle(yaw, pitch)`: Sets angle without recovering yaw/pitch  
 - `moveAngle(yaw, pitch, time)`: Smooth angle transition  
 - `src(cmd_string)`: Insert raw command string into CFG  
 - `setExecPath(path)`: Define exec output path  
 - `lockMouse()` / `unlockMouse()`: Locks/unlocks mouse input  
 - `wasdCancel()`: Cancels execution if movement keys are pressed  

 ---

 ## 📄 Lua Example

 ```lua
 setExecPath("cfg/autoexec.cfg")

 lockMouse()
 wasdCancel()

 jump()
 sleep(5)
 setAngle(90, 0)
 moveAngle(180, 0, 10)
 src("echo Hello, lcfg!")

 unlockMouse()
 ```

 ---

 # 🛠️ Build and Compile Lua

 1. Clone the repository:  
    ```bash
    git clone https://github.com/tomh500/lcfg
    ```
 2. Enter the project directory:  
    ```bash
    cd lcfg
    ```
 3. Build the project:
    - **Windows**:  
      ```bash
      .\build.bat
      ```

 4. Copy the `lcfg` binary to your SmartActive folder  
 5. Compile Lua scripts:
    ```bash
    lcfg <your_script.lua>
    ```
    Or build bhop file:
    ```bash
    lcfg -buildbhop
    ```

 ---


 ## 📜 License

 Licensed under [GPL v3.0](https://www.gnu.org/licenses/gpl-3.0.en.html)
