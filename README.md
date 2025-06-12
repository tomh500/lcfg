# 🎯 Project Overview

This is a lightweight compiler that converts Lua scripts into CS2-compatible CFG format.
lcfg uses standard Lua syntax.

Project Fork from -Cap1taL-


---

# 🚀 Features
* Supports compiling custom scripts into CFG files
* Provides built-in lcfg functions to extend Lua's capabilities
* Enables smooth view control and action commands
* Supports customizable exec path configuration

---



# 📚 supported lcfg funcation

Based on the Lua syntax, you can use the following functions defined in lcfg：

* `<basecmd>(number)`：execute actions such as moving or attacking,  Corresponding to `basecmd x 0 0` in cfg。
* `jump()`：run jump
* `sleep()`：Delay execute in ticks
* `jumpbug()`：execute jumpbug
* `setAngle(yaw, pitch)`：set angle
* `angle(yaw, pitch)`：set angle without recovery yaw and pitch
* `moveAngle(yaw, pitch, time)`：set angle but smooth
* `src(cmd)`：write some string in cfg
* `setExecPath(path)`：set exec path
* if you wanna lock mouse when cfg is running ,you can use `lockMouse()` and `unlockMouse()`
* is you wanna cancel actions when any move key has pressed , you can use `wasdCancel()`

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

# 🛠️ Build And Compile Lua


1. Clone the repository using `git clone https://github.com/tomh500/lcfg`. 
2. CD into the local repository folder.
3. Build lcfg project on your device:
    - For Windows: `.\build.bat`
    - For Linux: 
      (1). Make sure installed lua5.4 with `sudo apt install liblua5.4-dev`
      (2). `chmod +x build.sh`
      (3). `./build.sh`
4. Copy the lcfg to SmartActive Folder
5. Run ```lcfg <path_to_your_lua>``` or ```lcfg -buildbhop```

---

# 📦 How to Use

1. Place lcfg and lua54.dll in the same directory as the script, or add them to your system's environment variables
2.  For Linux extra run ```chmod +x lcfg```
3. Run: ```lcfg <path_to_your_lua>``` to Compile lua or Run ```lcfg -buildbhop``` to build SmaMode bunnyhop file
4. You will now get a folder containing several ```_init_.cfg``` files. Use them together with <a href="https://github.com/tomh500/MoClient">DearMoments</a>, and place the folder anywhere you like. To start, run the following cfg command in CS2 Console:

```exec <path to your _init_.cfg>``` then 
```sf_start```

## 📜 License

GPL 3.0

