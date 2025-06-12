 [简体中文](#) | [English](README.md) 
 
 # 🎯 项目简介

 这是一个轻量级的编译器，用于将 Lua 编译为 CS2 的 CFG 格式。  
 lcfg 使用标准的 Lua 语法。

 ---

 # 🚀 功能特性

 * 支持将自定义 Lua 脚本编译为 CFG 文件  
 * 内置多种 lcfg 函数，扩展 Lua 的功能  
 * 提供平滑的视角控制和动作指令  
 * 支持自定义 exec 路径配置  

 ---

 # 📚 支持的 lcfg 函数

 基于 Lua 语法，你可以使用以下由 lcfg 定义的函数：

 * `<basecmd>(number)`：执行基本动作，如移动或攻击，等价于 CFG 中的 `basecmd x 0 0`  
 * `jump()`：跳跃动作  
 * `sleep(ticks)`：延迟执行，单位为 ticks  
 * `jumpbug()`：执行 jumpbug 技巧  
 * `setAngle(yaw, pitch)`：设置视角角度  
 * `angle(yaw, pitch)`：设置角度，但不恢复 yaw 和 pitch  
 * `moveAngle(yaw, pitch, time)`：平滑过渡角度  
 * `src(cmd_string)`：直接写入 CFG 命令字符串  
 * `setExecPath(path)`：设置 exec 文件输出路径  
 * `lockMouse()` / `unlockMouse()`：锁定或解锁鼠标输入  
 * `wasdCancel()`：按下移动键时取消当前动作  

 ---

 ## 📄 Lua 示例

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

 # 🛠️ 编译和构建

 1. 克隆仓库：  
    ```bash
    git clone https://github.com/tomh500/lcfg
    ```
 2. 进入项目目录：  
    ```bash
    cd lcfg
    ```
 3. 构建项目：
    - **Windows**：  
      ```bash
      .\build.bat
      ```
    - **Linux**：  
      1. 安装 Lua 5.4 开发包：  
         ```bash
         sudo apt install liblua5.4-dev
         ```
      2. 赋予构建脚本执行权限：  
         ```bash
         chmod +x build.sh
         ```
      3. 执行构建：  
         ```bash
         ./build.sh
         ```

 4. 将生成的 `lcfg` 拷贝到 SmartActive 目录  
 5. 使用以下命令编译 Lua 脚本：
    ```bash
    lcfg <your_script.lua>
    ```
    或生成 Bunnyhop 配置文件：
    ```bash
    lcfg -buildbhop
    ```

 ---

 # 📦 使用说明

 1. 将 `lcfg` 和 `lua54.dll` 放在脚本同目录，或添加到系统环境变量中  
 2. （Linux 用户）赋予 `lcfg` 执行权限：  
    ```bash
    chmod +x lcfg
    ```
 3. 执行编译命令：  
    ```bash
    lcfg <your_script.lua>
    ```
    或生成 SmartActive Bunnyhop 文件：  
    ```bash
    lcfg -buildbhop
    ```
 4. 运行后将获得包含若干 `_init_.cfg` 文件的文件夹。将该文件夹与 <a href="https://github.com/tomh500/MoClient">DearMoments</a> 配合使用。在 CS2 控制台运行：

    ```cfg
    exec <path_to/_init_.cfg>
    sf_start
    ```

 ---

 ## 📜 许可协议

 采用 [GPL v3.0](https://www.gnu.org/licenses/gpl-3.0.html) 许可
