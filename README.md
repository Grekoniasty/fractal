# fract-ol

A 42 School project that renders interactive fractal visualizations using MiniLibX. Supports the Mandelbrot and Julia sets with real-time exploration via keyboard and mouse.

---

## How it works

Each pixel on screen is mapped to a complex number. For every point, the fractal formula is iterated up to a maximum depth — if the value escapes to infinity before the limit, the pixel is colored based on how quickly it escaped. If it never escapes, it belongs to the set and is drawn black.

**Mandelbrot** — the starting point is always `z = 0`, and the constant `c` varies per pixel: `z = z² + c`

**Julia** — the constant `c` is fixed (passed as arguments) and `z` starts at the pixel's complex value: `z = z² + c`. Different values of `c` produce wildly different shapes.

---

## Controls

| Input | Action |
|---|---|
| `scroll up` | Zoom in |
| `scroll down` | Zoom out |
| `arrow keys` | Move around the fractal |
| `numpad +` | Increase iteration depth (+5) |
| `numpad -` | Decrease iteration depth (-5) |
| `c` | Change color scheme |
| `ESC` | Exit |

---

## Usage

```bash
make
./fractol mandelbrot
./fractol julia <real> <imaginary>
```

**Examples:**
```bash
./fractol julia -0.7 0.27
./fractol julia 0.355 0.355
```

---

## Bonus

- Mouse-controlled Julia parameter shifting — hovering over the Mandelbrot set updates the Julia constant in real time, showing the corresponding Julia set live
- Smooth coloring based on escape velocity for gradient rendering instead of hard color bands
