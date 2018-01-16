# Bunner

A generic 2D platformer that I'm working on as a project.

Controls:
- A - Left
- D - right
- Space - jump
- LShift - sprint

Features:
- very basic AABB Collision
- basic 2D platformer movements with a simple Lerp acceleration and deceleration
- supports 3 layers of drawing. Background, Main(aka player layer), Foreground. Background and Foreground are used for decorations
- player animation 
- The map only draws what you see(in the default view, not when you zoom in or out)
- sprinting


Upcoming features:
- bullet/projectile class
- ambient sound and player movement sound


Possible features:
- z depth drawing instead of painter algorithm drawing
- particle effects