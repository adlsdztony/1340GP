# For developers
## <font color=Blue>class</font> Keyboard

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

## Create format with \<format\>
To format the string, you need to start with 
```
<format mod=MOD front=FRONT_COLOR back=BACK_COLOR >
       ^       ^                 ^               ^
These spaces must be included
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
