# scfg
A lightweight tool to compile counter-strike 2 macro scripts into game-compatible cfg files. Simple, fast, and efficient.

# scfg Functions

- `DEFINEPATH <exec-path>`: The path to the `exec` file.
- `SRC <command>`: Directly execute a game command.
- `SLEEP <duration>`: Sleep the script for a specified duration in seconds. The last parameter specifies whether the timing starts from the previous timing "start point". This helps reduce timing errors.
- `SLEEPTICK <duration>`: Sleep the script for a specified duration in ticks. The last parameter specifies whether the timing starts from the previous timing "start point". This helps reduce timing errors.
- `SETBEGIN`: Set the timing start point.
- `CHECKTIME`：Output current timing errors.
- `SETANG <output of the game’s getpos command>`: Reset and set the view angle to the target angle.
- `ANG <output of the game’s getpos command>`: Do not reset the view angle, set it relative to the last view command's angle.
- `MOVEANG <output of the game’s getpos command>`: Do not reset the view angle, smoothly move the view angle relative to the last view command’s angle.
- `PLAY <resource path>`: Play a sound effect.
- `BEEP`: Play a beep sound effect.
- `CVAR <name> <value>`: Change the value of a cvar.
- `LOCKMOUSE`: Lock the mouse.
- `UNLOCKMOUSE`: Unlock the mouse.
- `END`: End the script.

# Compile Command

The default file extension is `.cs2script`.

Usage: `scfg.exe <input file>`

Example: `scfg.exe a.cs2script`