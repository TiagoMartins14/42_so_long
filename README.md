# so_long

<div align="center">
  <h1>Description</h1>
</div>
This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.

<div align="center">
  <h1>How to play</h1>
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

## Disclaimer:
This project's source code adheres to the standards of 42 School and its norms and rigorous coding practices:
```
- We refrain from using 'for,' 'do while,' 'switch,' 'case,' or 'goto' constructs.
- Each function has no more than 25 lines of code. 
- There's a maximum of 5 functions per file.
- Assignments and declarations are kept on separate lines unless the variable is declared as static.
- We ensure that no single function has more than 5 variables, promoting code simplicity and readability.
```
