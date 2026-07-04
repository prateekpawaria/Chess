# ♟️ Console Chess Game in C

A classic two-player **chess game** built using the C programming language, playable entirely in the terminal. This project is a great showcase of logic handling, board rendering, and player interaction in a CLI-based environment.

## 🎯 Features

- Full implementation of chess rules (including castling, pawn promotion, and en passant if added)
- Text-based 8x8 chessboard in the console
- Turn-based play between two human players
- Basic input validation and move legality checking
- Minimal external dependencies

## 🚀 Getting Started

### 🔧 Compilation

Use `gcc` to compile the chess game:

```bash
gcc -o chess chess.c
```

### ▶️ Run

```bash
./chess
```

*(If you're on Windows and using the PowerShell script you included, run it like this:)*

```powershell
./chess.ps1
```

> Make sure the `.c` source files and the script are in the same directory.

## 🕹️ Gameplay

- The board is displayed in the terminal.
- Players are prompted to enter their moves using standard algebraic notation (e.g., `e2 e4`).
- The game alternates between White and Black turns.
- The game ends when checkmate, stalemate, or draw conditions are met.

## 📁 File Structure

- `chess.c` – Main logic and game loop
- `chess.h` – Header file (if used)
- `chess.ps1` – PowerShell script to compile or run the game on Windows

## 🧠 Future Enhancements

- Add AI opponent (Minimax or basic heuristics)
- Save/load game functionality
- Timed moves (chess clock)
- Move history and undo feature
