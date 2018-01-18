# Bunner

A generic 2D platformer that I'm working on as a project.

Controls:
- A - left
- D - right
- Space - jump
- LShift - sprint
- LControl - shoot
- Esc - ingame menu

Features:
- very basic AABB Collision
- basic 2D platformer movements with a simple Lerp acceleration and deceleration
- sprinting
- supports 3 layers of drawing. Background, Main(aka player layer), Foreground. Background and Foreground are used for decorations
- player animation 
- player running sound
- the map only draws what you see(in the default view, not when you zoom in or out)
- projectiles
- ingame menu(the game is frozen until you exit the menu)


Upcoming features:
- ambient sound


Possible features:
- z depth drawing instead of painter algorithm drawing
- particle effects