[English](/README_en_us.md)

---

# scfg
一个用于把 Horizon cs2script 脚本编译为 .cfg 文件的轻量级编译器。

# scfg 命令

- `DEFINEPATH <exec 路径>`: 在开头使用，用于指定 `exec` 指令使用的路径，也是你 cfg 的实际位置。
- `TICK(秒数)`：**这并不是一个指令**。它可以作为任何指令的参数，用于把内部的时间单位从秒转换为 tick。

- `SRC <命令>`: 直接调用游戏内命令。
- `SLEEP <秒数>`: 暂停脚本运行一段时间，单位为秒。保证距离上个计时标记点的计时误差在 1tick 之内。
- `SLEEPTICK <tick数>`: 即将被弃用，请用 `SLEEP TICK(tick数)` 代替。
- `SETBEGIN`: 设置计时标记点。
- `CHECKTIME`：输出距离上个计时标记点的误差至全局聊天。

- `SETANG <游戏内 getpos 指令的输出>`: 精准设置视角，绝对定位。
- `ANG <游戏内 getpos 指令的输出>`: 非精准设置视角，从上一个视角指令相对定位。
- `MOVEANG <时长> <游戏内 getpos 指令的输出>`: 非精准设置视角，从上一个视角指令相对地平滑移动至目标视角，可以指定耗时. 可以用 `TICK()` 提供以 tick 为单位的时间。

- `PLAY <资源路径>`: 播放音效。
- `BEEP`: 播放音效 beep。

- `CVAR <名字> <值>`: 改变 cvar 的值。

- `LOCKMOUSE`: 锁定鼠标。
- `UNLOCKMOUSE`: 取消锁定鼠标。

- `+FORWARD`：开始向前移动
- `-FORWARD`：停止向前移动
- `+BACK`：开始向后移动
- `-BACK`：停止向后移动
- `+RIGHT`：开始向右移动
- `-RIGHT`：停止向右移动
- `+LEFT`：开始向左移动
- `-LEFT`：停止向左移动
- `+DUCK`：下蹲
- `-DUCK`：取消下蹲
- `+SPRINT`：静步
- `-SPRINT`：取消静步
- `JUMP`：跳跃
- `JUMPBUG`：jumpbug 跳跃
- `DROP`：丢弃当前所持物品
- `+USE`：使用（拆包等）
- `+USE`：停止使用
- `+ATTACK`：开火
- `-ATTACK`：停止开火
- `+ATTACK2`：第二开火（开镜，调整射击模式等）
- `-ATTACK2`：停止第二开火
- `SLOT1`：切换至主武器
- `SLOT2`：切换至副武器
- `SLOT3`：切换至近战武器
- `SLOT4`：切换至投掷物
- `SLOT5`：切换至C4
  
- `FPS_LOW`：锁定 fps 至 64。
- `FPS_RESET`：恢复至 optPreference 中指定的帧率限制。
  
- `SPEED_LEFT <每秒旋转角度>`：向左旋转加速。会取消先前的旋转加速。
- `SPEED_RIGHT <每秒旋转角度>`：向右旋转加速。会取消先前的旋转加速。
- `SPEED_STOP`：停止旋转加速。

- `END`: 脚本终止。

# scfg 使用方法

scfg 是一个命令行程序。

默认文件扩展名为 `.cs2script`.

使用方法: `scfg.exe <脚本文件>`

例子: `scfg.exe a.cs2script`

# 编译 scfg

`g++ scfg.cpp -o scfg -std=c++23 -O2 -static`