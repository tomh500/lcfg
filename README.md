[English](#) | [简体中文](README_CN.md) 
 
 # 🎯 Project Overview
 lcfg is a lightweight compiler designed to translate Lua scripts into CFG files compatible with CS2.
 It extends standard Lua syntax with custom commands for gameplay automation.


 # 🚀 Features
 - Compile custom Lua scripts into CFG files
 - Includes built-in lcfg functions to extend Lua capabilities
 - Supports smooth angle transitions and action scripting
 - Allows exec path customization


 # 📚 Supported lcfg Functions
 lcfg defines the following functions that can be used in your Lua script:
 - LCFG_VERSION(int): Declares the syntax version (must appear at the top of the script)
 - <basecmd>(number): Executes base actions like movement or attack (maps to `basecmd x 0 0`)
 - jump(): Triggers a jump
 - sleep(ticks): Waits for the given number of ticks
 - jumpbug(): Executes the jumpbug technique
 - setAngle(yaw, pitch): Sets the viewing angle
 - angle(yaw, pitch): Directly sets angle without restoring yaw/pitch
 - moveAngle(yaw, pitch, time): Smoothly transitions angle over time
 - src(cmd_string): Inserts raw CFG command text
 - setExecPath(path): Specifies the output path for the generated CFG
 - lockMouse() / unlockMouse(): Locks or unlocks mouse input
 - wasdCancel(): Cancels current action when movement keys are pressed


 ## 📄 Lua Example
 ```lua
 LCFG_VERSION(1)
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


 # 🛠️ Build & Usage

 1. Clone the repository:
 ```bash
 git clone https:github.com/tomh500/lcfg
 ```

 2. Navigate to the project folder:
 ```bash
 cd lcfg
 ```

 3. Build the project (x64 Native Tools Command Prompt for VS 2022):
 ```bash
 build.bat
 ```

 4. Copy the generated `lcfg.exe` into your SmartActive directory

 5. Compile Lua scripts:
 ```bash
 lcfg <your_script.lua>
 ```

 Or generate Bunnyhop config:
 ```bash
 lcfg -buildbhop
 ```

 6. After running, you’ll get a folder containing `_init_.cfg`.  
 Use it with [DearMoments](https://github.com/tomh500/DearMoments).  
 In CS2 console, run:
 ```cfg
 exec <path_to/_init_.cfg>;sf_start
 ```


 # 📜 License
 Distributed under [GPL v3.0](https:www.gnu.org/licenses/gpl-3.0.html)
