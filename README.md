# 🎯 SCFG - Lua to CS2 CFG Compiler

<div align="center">

**[中文](#中文) | [English](#english) | [Русский](#русский)**

_A lightweight compiler that converts Lua scripts to CS2 CFG format_

</div>

---

## 🌍 Language Support

This project supports three languages: Chinese (中文), English, and Russian (Русский). Use the `--lang` parameter to set your preferred language:

```bash
scfg script.lua --lang zh  # Chinese
scfg script.lua --lang en  # English
scfg script.lua --lang ru  # Russian
```

---

## 中文

### 🎯 项目简介

这是一个轻量级的编译器，用于将 lua 编译为 CS2 的 CFG 格式。

SCFG 使用 Lua 语法。

### 🚀 功能特性

- 支持将自定义脚本编译为 CFG
- 内置多种 SCFG 函数，扩展 Lua 的功能
- 提供平滑的视角控制和动作指令
- 支持自定义 exec 路径设置
- 多语言支持（中文、英文、俄文）

### 📦 使用方法

1. 将 `scfg.exe` 和 `lua54.dll` 放置于脚本同目录，或将其添加到系统环境变量中。
2. 使用以下命令编译您的脚本：

   ```bash
   scfg <your_script_file> [--lang zh|en|ru]
   ```

3. 现在您得到了一个有若干 `cmd_<id>.cfg` 文件的文件夹。将其与 <a href="https://github.com/eLecCap1taL/horizon">Horizon</a> 一起使用，放置在任何地方均可。使用以下 cfg 命令来启动

   ```bash
   exec <路径>/cmd_1.cfg;hzSche_process
   ```

### 📚 支持的 SCFG 函数

在 Lua 语法的基础上，您可以使用以下 SCFG 定义的函数：

- `<basecmd>(数字)`：执行基本动作，如前进、后退、攻击等。对应 CFG 中的 `basecmd x 0 0`。
- `jump()`：执行跳跃动作。
- `sleep()`：以 tick 为单位的延迟。
- `jumpbug()`：执行 Jumpbug 动作。
- `setAngle(yaw, pitch)`：设置视角角度。
- `angle(yaw, pitch)`：在不重置角度的基础上设置视角，避免频繁重置引起的抖动。
- `moveAngle(yaw, pitch, time)`：在指定时间内平滑移动视角到目标角度。
- `src(cmd)`：直接在 CFG 中写入指定的命令内容。
- `setExecPath(path)`：设置生成文件中 exec 的路径。
- 如果您希望锁定鼠标移动，在脚本中使用 `lockMouse()` 和 `unlockMouse()`
- 如果您希望用户按下 WASD 任意一个时立即终止进程，在脚本中使用 `wasdCancel()`。此功能默认关闭

### 📄 示例

```lua
setExecPath("cfg/autoexec.cfg")

lockMouse()
wasdCancel()

jump()
sleep(5)
setAngle(90, 0)
moveAngle(180, 0, 10)
src("echo Hello, SCFG!")

unlockMouse()
```

### 🛠️ 自行编译

1. 确保您的系统已安装 Bash 和 C++ 环境。
2. **Linux 用户**：请先安装 Lua 开发库：

   ```bash
   # Ubuntu/Debian
   sudo apt-get install build-essential liblua5.4-dev

   # CentOS/RHEL
   sudo yum install gcc-c++ lua-devel

   # Arch Linux
   sudo pacman -S base-devel lua
   ```

3. 运行以下命令以编译 SCFG：

   ```bash
   chmod +x build.sh
   ./build.sh
   ```

---

## English

### 🎯 Project Overview

SCFG is a lightweight compiler that converts Lua scripts into CS2 CFG format.

SCFG uses Lua syntax with extended functionality for CS2 scripting.

### 🚀 Features

- Compile custom Lua scripts to CFG format
- Built-in SCFG functions extending Lua capabilities
- Smooth camera control and action commands
- Custom exec path configuration
- Multi-language support (Chinese, English, Russian)

### 📦 Usage

1. Place `scfg.exe` and `lua54.dll` in the same directory as your script, or add them to your system PATH.
2. Compile your script using:

   ```bash
   scfg <your_script_file> [--lang zh|en|ru]
   ```

3. You'll get a folder with several `cmd_<id>.cfg` files. Use these with <a href="https://github.com/eLecCap1taL/horizon">Horizon</a> anywhere. Start with:

   ```bash
   exec <path>/cmd_1.cfg;hzSche_process
   ```

### 📚 Supported SCFG Functions

Based on Lua syntax, you can use these SCFG-defined functions:

- `<basecmd>(number)`: Execute basic actions like forward, backward, attack. Corresponds to `basecmd x 0 0` in CFG.
- `jump()`: Execute jump action.
- `sleep()`: Delay in ticks.
- `jumpbug()`: Execute Jumpbug action.
- `setAngle(yaw, pitch)`: Set camera angles.
- `angle(yaw, pitch)`: Set angles without resetting, avoiding jitter from frequent resets.
- `moveAngle(yaw, pitch, time)`: Smoothly move camera to target angles over specified time.
- `src(cmd)`: Write specified command directly to CFG.
- `setExecPath(path)`: Set exec path in generated files.
- Use `lockMouse()` and `unlockMouse()` to lock mouse movement.
- Use `wasdCancel()` to terminate process when WASD is pressed. This feature is disabled by default.

### 📄 Example

```lua
setExecPath("cfg/autoexec.cfg")

lockMouse()
wasdCancel()

jump()
sleep(5)
setAngle(90, 0)
moveAngle(180, 0, 10)
src("echo Hello, SCFG!")

unlockMouse()
```

### 🛠️ Build from Source

1. Ensure your system has Bash and C++ environment installed.
2. **Linux users**: Please install Lua development libraries first:

   ```bash
   # Ubuntu/Debian
   sudo apt-get install build-essential liblua5.4-dev

   # CentOS/RHEL
   sudo yum install gcc-c++ lua-devel

   # Arch Linux
   sudo pacman -S base-devel lua
   ```

3. Run the following command to compile SCFG:

   ```bash
   chmod +x build.sh
   ./build.sh
   ```

---

## Русский

### 🎯 Обзор проекта

SCFG - это легковесный компилятор, который преобразует Lua скрипты в формат CS2 CFG.

SCFG использует синтаксис Lua с расширенной функциональностью для скриптов CS2.

### 🚀 Возможности

- Компиляция пользовательских Lua скриптов в формат CFG
- Встроенные функции SCFG, расширяющие возможности Lua
- Плавный контроль камеры и команды действий
- Настройка пользовательского пути exec
- Поддержка нескольких языков (китайский, английский, русский)

### 📦 Использование

1. Разместите `scfg.exe` и `lua54.dll` в той же директории, что и ваш скрипт, или добавьте их в системную переменную PATH.
2. Скомпилируйте ваш скрипт с помощью:

   ```bash
   scfg <ваш_файл_скрипта> [--lang zh|en|ru]
   ```

3. Вы получите папку с несколькими файлами `cmd_<id>.cfg`. Используйте их с <a href="https://github.com/eLecCap1taL/horizon">Horizon</a> в любом месте. Запустите с помощью:

   ```bash
   exec <путь>/cmd_1.cfg;hzSche_process
   ```

### 📚 Поддерживаемые функции SCFG

На основе синтаксиса Lua вы можете использовать следующие функции, определенные SCFG:

- `<basecmd>(число)`: Выполнение базовых действий, таких как движение вперед, назад, атака. Соответствует `basecmd x 0 0` в CFG.
- `jump()`: Выполнение прыжка.
- `sleep()`: Задержка в тиках.
- `jumpbug()`: Выполнение Jumpbug действия.
- `setAngle(yaw, pitch)`: Установка углов камеры.
- `angle(yaw, pitch)`: Установка углов без сброса, избегая дрожания от частых сбросов.
- `moveAngle(yaw, pitch, time)`: Плавное перемещение камеры к целевым углам за указанное время.
- `src(cmd)`: Прямая запись указанной команды в CFG.
- `setExecPath(path)`: Установка пути exec в сгенерированных файлах.
- Используйте `lockMouse()` и `unlockMouse()` для блокировки движения мыши.
- Используйте `wasdCancel()` для завершения процесса при нажатии WASD. Эта функция отключена по умолчанию.

### 📄 Пример

```lua
setExecPath("cfg/autoexec.cfg")

lockMouse()
wasdCancel()

jump()
sleep(5)
setAngle(90, 0)
moveAngle(180, 0, 10)
src("echo Hello, SCFG!")

unlockMouse()
```

### 🛠️ Сборка из исходников

1. Убедитесь, что в вашей системе установлены Bash и C++ окружение.
2. **Пользователи Linux**: сначала установите библиотеки разработки Lua:

   ```bash
   # Ubuntu/Debian
   sudo apt-get install build-essential liblua5.4-dev

   # CentOS/RHEL
   sudo yum install gcc-c++ lua-devel

   # Arch Linux
   sudo pacman -S base-devel lua
   ```

3. Выполните следующую команду для компиляции SCFG:

   ```bash
   chmod +x build.sh
   ./build.sh
   ```

---

## 📜 License

**GPL 3.0**

---

## 🤝 Contributing

We welcome contributions! Please feel free to submit issues, feature requests, or pull requests to help improve SCFG for all language communities.

## 📞 Support

For support in your language:

- **中文**: 查看中文文档部分或提交 issue
- **English**: Check the English documentation section or submit an issue
- **Русский**: Смотрите русскую документацию или создайте issue
