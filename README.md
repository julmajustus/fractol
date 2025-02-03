# fract’ol - Computer Graphics Fractals.

Draws beatiful fractals utilizing MLX42 library.  
Handles Julia, Mandelbrot and Multibrot sets.  
Written in C.

---
### Install

```
git clone https://github.com/julmajustus/fractol.git

make bonus
```
---

### Usage

```
Correct input for fractol is:
  ./fractol mandelbrot
  ./fractol julia x.x x.x
    (x.x values should be between -2.0 and 2.0)

Controls:
  General:
    ESC      - Exit program
    WASD     - Move the view inside window
    Mouse    - Scroll to zoom in/out
    R        - Reset colorset to black/white
    Space    - Randomize colorset

  Julia set controls:
    UP/DOWN  - Increase/decrease constants
    LEFT/RIGHT - Finer increase/decrease constants
```
---

![julia set](demos/julia.png)
![mandelbrot](demos/mandelbrot.png)
![multibrot](demos/multibrot.png)
