# For developers
## <font color=Blue>class</font> Keyboard

```c++
// create keyboard
Keyboard kb;

// listen for keyboard input without blocking
kb.listen();

// get the last key pressed
int key = kb.read();

// block until some keys are pressed
vector<int> keys = {KEY_ENTER, KEY_ESC};
int key = kb.wait_for(keys);
```

## <font color=Blue>class</font> Format
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
## <font color=Blue>class</font> Object
If you want to create an object, you need to create a vector of string, and pass it to the constructor.

You can use \<format\> to format the string, see [here](#Create-format-with-\<format\>).
```c++
// create vector of string with format
vector<string> vector_of_string = {
    "<format front=red >Hello<format>",
    "World"
};

// create object
Object obj(x, y, vector_of_string);
```
Or you can pass a format to the constructor.
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

## <font color=Blue>class</font> Window: public Object
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
the output will be like this:
```
+----------------+
|     title      |
|                |
|content[0]      |
|content[1]      |
|                |
+----------------+
```
you can set space between the title and the content by setting the space variable.
```c++
int space = 2;
// create window
Window window(x, y, width, height, title, content, space);
```
the output will be like this:
```
+----------------+
|     title      |
|                |
|                |
|content[0]      |
|content[1]      |
+----------------+
```
## Create format with \<format\>