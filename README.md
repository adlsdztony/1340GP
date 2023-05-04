[![Logo](https://see.fontimg.com/api/renderfont4/x3ARK/eyJyIjoiZnMiLCJoIjo5OCwidyI6MTUwMCwiZnMiOjY1LCJmZ2MiOiIjMDAwMDAwIiwiYmdjIjoiI0ZGRkZGRiIsInQiOjF9/SG9ua29ubW9uIEdP/there-brat.png)](https://www.fontspace.com/category/art-deco)
# Menu
1. [For Player](#for-player) 
	1. [Team members](#Team-members-)
	2. [How to play](#how-to-play-)
	3. [Features implemented](#features-implemented-)
	4. [Discription](#description-)
	5. [Non-standard libraries](#non-standard-libraries-%EF%B8%8F)
2. [For Developer](#for-developer)
	1. [class Keyboard](#class-keyboard)
	2. [class Format](#class-format)
	3. [class Object](#class-object)
	4. [class Window: public Object](#class-window-public-object)
	5. [class Notice: public Window](#class-notice-public-window)
	6. [class Screen](#class-screen)
	7. [class Map](#class-map)
		1. [To add interactive object to the map](#to-add-interactive-object-to-the-map)
	8. [Create format with \<format\>](#create-format-with-format)
# For Player
## Team members 🧑‍💻
[Chen Binghao](https://github.com/PeterPan246)&ensp;&ensp;(3036098003)

[Chen Borun](https://github.com/cbr-ine)&ensp;&ensp;&ensp;&ensp;(3036052190)

[Chen Tianyu](https://github.com/Uynaity)&ensp;&ensp;&ensp; (3036094605)

[Luo Siqi](https://github.com/rossskkki)&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; (3035979470)

[Zhou Zilong](https://github.com/adlsdztony)&ensp;&ensp;&ensp;&ensp;(3035962427)

## How to play 🤗
**Remember to zoom in the terminal window to get a better experience.**
```bash
make
```
```bash
./game
```
That‘s ALL! 
- Press *Enter/Space* to start.
- Press *Up/Down/Left/Right* (or *w/s/a/d* ) to move or change the selection.
- Press *E* to interact.
- Press *Enter* to select.
- Press *Esc* **Twice** to exit.


## Features implemented 🚀
- **Generation of random game sets or events**

    - Our AI combat system uses a random probability to trigger the appropriate skill (see [fight_system.cpp](fight_system.cpp))
⁣⁣⁣⁣
- **Data structures for storing game status**

    - We define a class to store the game status (see *class State* in [game.h](game.h))
⁣⁣⁣⁣
- **Dynamic memory management**

    - We dynamically manage the memory for pop-up interactions (see *int show_notice* in [notice.cpp](notice.cpp))
⁣⁣⁣⁣
- **File input/output**

    - We write individual game progress to the game_state.txt file so that players can quit the game at any time without losing data (see *State::store()* and *State::load()* in [game.cpp](game.cpp))
⁣⁣⁣⁣
- **Program codes in multiple files**

    - Easy to manage and modify different functions of the game
⁣⁣⁣⁣
- **Proper indentation and naming styles**

    - We can quickly locate the function that needs to be modified
⁣⁣⁣⁣
- **In-code documentation**

    - We won't lose our way with a lot of code


## Description 😎
💎Welcome to our text-based Pokemon game written in C++! We're excited to bring the classic Pokemon experience to life in a unique and engaging way. In this game, you will embark on an adventure to catch, train, and battle your way to become the ultimate Pokemon Master. Don't forget to try to collect all the Pokemon!

🎢At the start of your journey, you'll get your starting Pokemon and set out into the world. You'll explore various locations such as grassland, river, and hill, where you'll encounter wild Pokemon along the way.

👾When you come across a wild Pokemon, you'll have the option to battle it. Battles are turn-based and consist of four main options: attack, defend, use an item, or flee. You'll choose your options and watch as your Pokemon battles against the wild Pokemon.

🕹️As you progress through the game, you'll collect new Pokemon, each with their own unique abilities and attributes.

🏆Your ultimate goal is to become the Pokemon Champion by defeating the Elite Four trainers. Only the most skilled and dedicated players will be able to rise to the top and claim the title of Pokemon Master.

😜Our game is fun and challenging and will keep you engaged for hours on end. With its simple yet addictive gameplay and nostalgic feel, we're sure it will appeal to fans of the original Pokemon games. So go ahead and enjoy it!


## Non-standard libraries 🗂️
Not used, standard libraries only.


# For Developer
## class Keyboard

```c++
// create keyboard
Keyboard kb;

// listen for keyboard input with blocking
int key = kb.scanKeyboard();

// listen for keyboard input without blocking
kb.listen();

// get the last key pressed, if no key is pressed, return 0
int key = kb.read();

// block until some keys are pressed
vector<int> keys = {KEY_ENTER, KEY_ESC};
int key = kb.wait_for(keys);
```
Some keys are defined in [keyboard.h](keyboard.h).

## class Format
format can be FRONT_RED etc. or BACK_RED etc. which are defined in [format.h](format.h).
```c++
int x;
int y;
int length;
string format;

// create format
Format format(x, y, length, format);
```
Notice: the x and y are relative to the object, not the screen.
## class Object
If you want to create an object, you need to create a vector of string, and pass it to the constructor.

You can use \<format\> to format the string, see [here](#create-format-with-format).
```c++
// create vector of string with format
vector<string> vector_of_string = {
    "<format front=red >Hello<format>",
    "World"
};

// create object
Object obj(x, y, vector_of_string);
```
Or you can pass a [Format](#class-format) to the constructor.
```c++
// create vector of string
vector<string> vector_of_string = {
    "Hello"
    "World"
};

// create format
Format format(0, 0, 5, FRONT_RED);

// create object with format
Object obj(x, y, vector_of_string, format);
```
Both of them will create an object with the same result.

## class Window: public Object
```c++
int x;
int y;
int width;
int height;
string title;
vector<string> content;

// create window
Window window(x, y, width, height, title, content);
```
The output will be like this:
```
+----------------+
|     title      |
|                |
|content[0]      |
|content[1]      |
|                |
+----------------+
```
You can set space between the title and the content by setting the space variable.
```c++
int space = 2;
// create window
Window window(x, y, width, height, title, content, space);
```
The output will be like this:
```
+----------------+
|     title      |
|                |
|                |
|content[0]      |
|content[1]      |
+----------------+
```
## class Notice: public Window
```c++
vector<string> selection = {
    "Hello"
    "World"
};
// create notice
Notice notice(x, y, width, height, title, selection);
```
You can create a window with a selection.
```c++
// pass the current keyboard and screen to the notice
int i = notice.select(&keyboard, &screen);

// the return will be the index of the selection
string output = selection[i];
cout << output << endl;
```
The output will be like this:
```
+----------------+
|     title      |
|                |
|hello           |
|world           |
|                |
+----------------+
```
If user select the first line, the output will be "hello".
```c++
// you can also use int show_notice to show the notice with pre-defined width and height
int choice = show_notice(title, selections, Keyboard *kb, Screen *screen)
```

## class Screen
```c++
int width;
int height;

// create screen
Screen screen(width, height);
```
```c++
// clear the screen
screen.clear();

// add object to the screen
screen.draw(&obj); // notice that obj is a pointer

// refresh(display) the screen
screen.refresh();
```

## class Map
```c++
// map cab be created with a vector of string (map) and a vector of string (valid_map)
vector<string> map = {
    "                      ",
    "                      ",
    "                      ",
    "                      ",
    "###    ##### #########",
    "####               ###",
    };

vector<string> valid_map = {
    "1111111111111111111111",
    "1111111111111111111111",
    "1111111111111111111111",
    "1111111111111111111111",
    "0001111000001000000000",
    "0000111111111111111000",
    };

Map map(map, valid_map);
```

```c++
// map can be created with a vector of string
vector<string> map = {
    "                      ",
    "                      ",
    "                      ",
    "                      ",
    "###    ##### #########",
    "####               ###",
    };
// empty space represents a valid position, and store into valid_map

// create map
Map map(map);
```
This will create a map with the same result as the first one.
### To add interactive object to the map
```c++
// create object
Object obj(x, y, vector_of_string);
char name = 'a';
map.add_interact_object(&obj, name);
```
The name will be used to identify the object and add function to the object.


## Create format with \<format\>
To format the string, you need to start with 
```
<format mod=MOD front=FRONT_COLOR back=BACK_COLOR >
       ^       ^                 ^               ^
^These spaces must be included
``` 
and end with
```
</format>
```
The mod, front_color and back_color are defined in [format.h](format.h).
```c++
/// Hello world! with red Hello
<format front=red >Hello</format> world!
```
Notice: there have to be a space between the format and the string.