# scfg
A lightweight tool to compile macro scripts into game-compatible `.cfg` files. Simple, fast, and efficient.

# scfg 函数

- `DEFINEPATH <exec-path>`：`exec` 的路径
- `SRC 指令`：直接调用游戏内指令
- `SLEEP 时长 BEGIN/STRICT` ：睡眠脚本，单位为秒。最后一个参数表示从上一个计时“起点”开始计时，或从当前时间开始计时。这有助于减少计时误差。
- `SETBEGIN`：设置计时起点
- `SETANG <游戏内getpos命令的输出>`：重置并设置视角在目标角度
- `ANG <游戏内getpos命令的输出>`：不重置视角，使用以最后的视角指令为基准的相对角度，设置视角
- `MOVEANG <游戏内getpos命令的输出>`：不重置视角，使用以最后的视角指令为基准的相对角度，平滑移动视角。
- `PLAY 文件路径`：播放音效
- `BEEP`：播放 beep 音效
- `CVAR 变量名 值`：更改 cvar 的值
- `LOCKMOUSE `：锁定鼠标
- `UNLOCKMOUSE `：释放鼠标
- `END `：脚本结束

# 编译命令

默认扩展名为 `.cs2script`

Usage: `scfg <input file> <exec path>`

Example: `scfg a.cs2script path/to/executable`