# 🐬 So Long: A Simple 2D Game 🎮

Welcome to **So Long**, my 2D game project designed to help me dive into computer graphics programming and have a little fun along the way! This project was created as part of my journey to learn C programming and explore graphics using MiniLibX.

---

## ✨ About the Game

**So Long** is a 2D top-down game where the player navigates a map, collects items, and escapes through an exit. The game's default theme involves a dolphin escaping Earth after eating some fish, but I’ve made it fully customizable—characters, maps, and settings can be tailored to any theme you'd like!

---

## 🎯 Objectives

This project helps improve:
- **Window management**: Displaying game graphics smoothly.
- **Event handling**: Responding to player inputs like movement.
- **Working with textures and sprites**: Designing game visuals.
- **C programming**: Writing efficient and error-free code.

---

## 🛠️ How It Works

### Features:
- Move your character using `W`, `A`, `S`, and `D` (or arrow keys).
- Collect all items on the map (`C` collectibles).
- Escape through the map exit (`E`) while avoiding obstacles (`1` walls).
- A movement counter updates after each action.

### Map Configuration:
The game uses `.ber` files to define maps. A valid map includes:
- Walls (`1`), free spaces (`0`), collectibles (`C`), exit (`E`), and a starting position (`P`).
- Maps must be surrounded by walls, rectangular, and have at least one exit, one collectible, and one starting position.

### Graphics:
- Uses the **MiniLibX** library for displaying 2D graphics.
- Smooth window transitions and clean exit functionality (via `ESC` or window close).

## 🚀 Bonus Features

If you're exploring further:
- Add enemies! The player loses when touching enemy patrols.
- Sprite animations to make the game more dynamic.
- Display the movement counter on the screen rather than in the terminal.

## 🔧 Setup & Usage

1. **Clone the repository**:
 ```bash
 git clone <repository-url>
 cd so_long
```

2. **Build the game**:
 ```bash
 make
```
3. **Run the game**:
```bash
    ./so_long maps/map.ber
```

4. **Clean up**:
```bash
    make clean
```
##  Requirements

- C compiler (GCC or Clang)
- MinilibX library
- Mandatory part: MAKEFILE .c, .h, .ber maps, textures.

## 📚 Resources

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [BMP Image Format](https://en.wikipedia.org/wiki/BMP_file_format)
- [Game Design Document Template](https://www.gamecareerguide.com/features/1293/game_design_document_template.php)


## Feel free to adjust anything to fit your preferences or specific customizations!
