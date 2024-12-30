[English](/README_en_us.md)

---

# scfg
A lightweight compiler for compiling Horizon cs2script scripts into .cfg files.

# scfg Commands

- `DEFINEPATH <exec path>`: Used at the beginning to specify the path used by the `exec` command, which is also the actual location of your cfg file.
- `TICK(seconds)`: **This is not a command**. It can be used as a parameter for any command to convert the internal time unit from seconds to ticks.

- `SRC <command>`: Directly call an in-game command.
- `SLEEP <seconds>`: Pauses script execution for a specified time, in seconds. Ensures that the time error from the last timing mark is within 1 tick.
- `SLEEPTICK <ticks>`: Will be deprecated, please use `SLEEP TICK(ticks)` instead.
- `SETBEGIN`: Sets a timing mark.
- `CHECKTIME`: Outputs the error from the last timing mark to the global chat.

- `SETANG <getpos output>`: Precisely sets the view angle, absolute positioning.
- `ANG <getpos output>`: Sets the view angle imprecisely, relative to the last view angle command.
- `MOVEANG <duration> <getpos output>`: Sets the view angle imprecisely, smoothly moving from the last view angle to the target angle over the specified duration. You can use `TICK()` to provide the time in ticks.

- `PLAY <resource path>`: Plays a sound effect.
- `BEEP`: Plays a beep sound effect.

- `CVAR <name> <value>`: Changes the value of a cvar.

- `LOCKMOUSE`: Locks the mouse.
- `UNLOCKMOUSE`: Unlocks the mouse.

- `+FORWARD`: Starts moving forward.
- `-FORWARD`: Stops moving forward.
- `+BACK`: Starts moving backward.
- `-BACK`: Stops moving backward.
- `+RIGHT`: Starts moving to the right.
- `-RIGHT`: Stops moving to the right.
- `+LEFT`: Starts moving to the left.
- `-LEFT`: Stops moving to the left.
- `+DUCK`: Ducks.
- `-DUCK`: Stops ducking.
- `+SPRINT`: Starts walking.
- `-SPRINT`: Stops walking.
- `JUMP`: Jumps.
- `JUMPBUG`: Performs a jumpbug.
- `DROP`: Drops the current item.
- `+USE`: Uses an item (e.g., unpacking).
- `-USE`: Stops using the item.
- `+ATTACK`: Starts firing.
- `-ATTACK`: Stops firing.
- `+ATTACK2`: Secondary firing (e.g., aiming down sights, adjusting shooting mode).
- `-ATTACK2`: Stops secondary firing.
- `SLOT1`: Switches to the primary weapon.
- `SLOT2`: Switches to the secondary weapon.
- `SLOT3`: Switches to the melee weapon.
- `SLOT4`: Switches to the throwable item.
- `SLOT5`: Switches to C4.
- `NADE_HE`: Switches to the high explosive grenade.
- `NADE_SMOKE`: Switches to the smoke grenade.
- `NADE_FLASH`: Switches to the flashbang.
- `NADE_DECOY`: Switches to the decoy grenade.
- `NADE_MOLO`: Switches to the molotov cocktail / firebomb.

- `SAY_ALL <text>`: Sends a global message.
- `SAY_TEAM <text>`: Sends a team message.
- `SAY_CONSOLE <text>`: Sends a console message.
  
- `FPS_LOW`: Locks the fps to 64.
- `FPS_RESET`: Resets to the frame rate limit specified in the optPreference.

- `SPEED_LEFT <degrees per second>`: Accelerates the left rotation. This will cancel previous rotation acceleration.
- `SPEED_RIGHT <degrees per second>`: Accelerates the right rotation. This will cancel previous rotation acceleration.
- `SPEED_STOP`: Stops rotation acceleration.

- `END`: Terminates the script.

# How to Use scfg

scfg is a command-line program.

The default file extension is `.cs2script`.

Usage: `scfg.exe <script file>`

Example: `scfg.exe a.cs2script`

# Compile scfg

`g++ scfg.cpp -o scfg -std=c++23 -O2 -static`
