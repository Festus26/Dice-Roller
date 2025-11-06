# 🎲 Dice Roller

A simple command-line dice rolling application written in C with ASCII art animations. Perfect for tabletop gaming!

## ✨ Features

- **7 Dice Types**: D4, D6, D8, D10, D12, D20 and D100
- **ASCII Art**: Custom visual representations for each dice
- **Animated Rolling**: Fun rolling animation
- **Cross-Platform**: Works on Windows, macOS, and Linux
- **Two Modes**: Interactive menu or quick command-line mode

## 🚀 Quick Start

### Compile

**Windows:**
```bash
gcc main.c -o dice_roller.exe
```

**macOS/Linux:**
```bash
gcc main.c -o dice_roller
```

### Run

**Interactive Menu:**
```bash
./dice_roller
```

**Quick Roll:**
```bash
./dice_roller d20    # Roll a 20-sided die
./dice_roller d6     # Roll a 6-sided die
./dice_roller d100   # Roll a 100-sided die
```

## 🎮 Supported Dice

| Dice | Sides | Shape |
|------|-------|-------|
| D4   | 4     | Tetrahedron |
| D6   | 6     | Cube |
| D8   | 8     | Octahedron |
| D10  | 10    | Pentagonal trapezohedron |
| D12  | 12    | Dodecahedron |
| D20  | 20    | Icosahedron |
| D100 | 100   | Zocchihedron |

## 🛠️ Technical Details

- Pure C with no external dependencies
- Cross-platform compatible (Windows, macOS, Linux)
- Uses platform-specific sleep and clear screen functions

---