# 🐍 Optimized Snake Game

> Full C implementation with optimized memory management and modular architecture

## 📋 Overview

A complete **Snake game** written in pure C, emphasizing clean **software architecture** and **memory efficiency**. Demonstrates low-level programming skills, modular design, and performance-conscious development.

## 🎮 Features

- Smooth real-time terminal-based gameplay
- Score tracking with progressive difficulty
- Optimized linked-list snake representation
- Zero memory leaks (Valgrind-verified)
- Modular architecture for easy extensibility

## 🏗️ Architecture

```
┌─────────────┐   ┌─────────────┐   ┌─────────────┐
│   Input     │──▶│   Game      │──▶│  Renderer   │
│  Handler    │   │   Logic     │   │  (Terminal)  │
└─────────────┘   └─────────────┘   └─────────────┘
                        │
                  ┌─────▼─────┐
                  │   State   │
                  │  Manager  │
                  └───────────┘
```

**Modules**:
- `input.c` — Keyboard input handling (non-blocking)
- `game.c` — Core game logic (collision, scoring, growth)
- `render.c` — Terminal rendering with ANSI escape codes
- `state.c` — Game state management

## 🚀 Quick Start

```bash
# Clone
git clone https://github.com/Yacinxe/snake-game.git
cd snake-game

# Build
make

# Play
./snake
```

## 📂 Project Structure

```
snake-game/
├── src/
│   ├── main.c       # Entry point
│   ├── game.c       # Game logic
│   ├── game.h
│   ├── input.c      # Input handling
│   ├── input.h
│   ├── render.c     # Terminal rendering
│   ├── render.h
│   ├── state.c      # State management
│   └── state.h
├── Makefile
└── README.md
```

## 🛠️ Technologies

![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)
![Make](https://img.shields.io/badge/Make-064F8C?style=flat-square&logo=cmake&logoColor=white)
![Valgrind](https://img.shields.io/badge/Valgrind-4B275F?style=flat-square)

## 📄 License

MIT License
