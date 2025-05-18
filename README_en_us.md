> [中文版](/README.md)

---

# 🎯 Project Overview

This is a lightweight compiler that converts scripting languages into CS2's CFG format. 

SCFG utilizes Lua syntax.

---

# 🚀 Features

* Compile custom scripts into CFG format
* Built-in SCFG functions extending Lua capabilities
* Smooth view angle control and action commands
* Support for custom exec path settings

---

# 🛠️ Installation & Compilation

1. Ensure your system has a Bash environment installed.
2. Run the following command to compile SCFG:

   ```bash
   ./build.sh
   ```



---

# 📦 Usage

1. Place `scfg.exe` and `lua54.dll` in the same directory as your script or add them to the system environment variables.
2. Run your script using the following command:

   ```bash
   scfg ./your_script.lua
   ```



---

# 📚 Supported SCFG Functions

In addition to Lua syntax, you can use the following SCFG-defined functions:

* `<basecmd>(number)`: Executes basic actions like forward, back, attack, etc. Corresponds to `basecmd x 0 0` in CFG.
* `jump()`: Performs a jump action.
* `sleep()`: Delays execution in ticks.
* `jumpbug()`: Executes the Jumpbug action.
* `setAngle(yaw, pitch)`: Sets the view angle.
* `angle(yaw, pitch)`: Sets the view angle without resetting, avoiding jitter from frequent resets.
* `moveAngle(yaw, pitch, time)`: Smoothly moves the view angle to the target over the specified time.
* `src(cmd)`: Directly writes the specified command into the CFG.
* `setExecPath(path)`: Sets the exec path in the generated file.

---

## 📄 Example

```lua
setExecPath("cfg/autoexec.cfg")

jump()
sleep(5)
setAngle(90, 0)
moveAngle(180, 0, 10)
src("echo Hello, SCFG!")
```



---

## 📜 License

GPL 3.0