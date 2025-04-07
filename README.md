<div align="center">
  <h1>42_so_long</h1>
</div>
Project developed during the Common Core @ 42 Porto

<div align="center">
  <h2>So_long</h2>
</div>
And thanks for all the fish!

<div align="center">
  <h3>Summary</h3>
</div>
This project is a small 2D game.
Its purpose is to have you work with textures, sprites,
and other basic gameplay elements.

<div align="center">
  <h2>🛠️ Usage</h2>
</div>

<div align="center">
  <h3>Requirements</h3>
</div>

The project is written in C language and needs the **`gcc` compiler** and some standard **C libraries** to run.

<div align="center">
  <h3>Instructions</h3>
</div>

<div align="center">
  <p>**1. Compiling the project**<p>
</div>

### Step 1 / Clone the repository:

```bash
$ git clone git@github.com:TiagoMartins14/so_long.git
```

### Step 2 / Install Minilibx and its dependencies:
Minilibx download:
```bash
$ cd so_long/
$ make download
```
Minilibx dependencies:
```bash
$ sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

### Step 3 / Compile the program:  

```bash
$ make
```

### Step 4 / Run the program:
The map folder has some pre-configured maps for you to test the game environment.  
You're able to create a map of your own and the program will tell you if the map is valid or not.  

<details>
<summary>Click here for map creation tutorial.</summary>
  
Map Rules:  
It has to be a **rectangular closed map** (walls around) and there needs to be a valid way to collect the diamonds and to the exit.
It has to have at least one collectible.
The map file extension has to be **'.ber'**.  
The map is composed by 5 elements:  
```
- '1' for walls;
- '0' for available floor;
- 'P' for Player starting position;
- 'E' for exit;
- 'C' for collectible;
```

Map example:
```
11111111111111111
10P001C0001C000C1
11110111101110111
10000000000000001
111101110111C1101
1C000100C0011C001
1111010C0C0111101
1C1101C0E0C111101
10C1010C0C011C1C1
10100100C00110111
101111110111C0001
101C1000010C11101
10101011110111101
10000000000000001
11111111111111111
```
</details>

To run the program, you need to select a map from the existing ones or the one that you've created. For that, you need to put its filename. The map needs to be inside the **maps** folder  
  
```bash
$ ./so_long map_1.ber
```

To exit the game, just press 'ESC' on your keyboard or click the 'X' in the game window. **HAVE FUN!**
