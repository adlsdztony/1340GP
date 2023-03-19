#include "display.h"
#include "keyboard.h"
#include <algorithm>


// class Screen
// {
// public:
//     int width;
//     int height;
//     vector<string> buffer;

// public:
//     Screen(int width, int height);
//     void clear();
//     void refresh();
//     void draw(int x, int y, char c);
//     void draw(int x, int y, string s);
//     void draw(int x, int y, string s[]);
//     void draw(Object obj);
// };

Format::Format(int x, int y, int length, string format)
{
    this->x = x;
    this->y = y;
    this->length = length;
    this->format = format;
}


Object::Object(int x, int y, vector<string> s)
{
    this->x = x;
    this->y = y;
    this->s = s;
    this->priority = 0;
}


void Object::script2format()
{
    // find <format mod={} front={} back={} > and </format> in s and remove them and add to formats
    for (int i = 0; i < this->s.size(); i++)
    {
        int start = 0;
        int end = 0;
        while (true)
        {
            start = this->s[i].find("<format", start);
            if (start == -1)
            {
                break;
            }
            end = this->s[i].find("</format>", start);
            if (end == -1)
            {
                break;
            }
            string format = this->s[i].substr(start, end - start + 9);
            this->s[i].erase(start, end - start + 9);
            string mod;
            string front;
            string back;
            int mod_start = format.find("mod=") + 4;

            int front_start = format.find("front=") + 6;

            int back_start = format.find("back=") + 5;

            int txt_start = format.find(">") + 1;
            int txt_end = format.find("</format>");

            if (mod_start != -1)
            {
                int mod_end = format.find(" ", mod_start);
                mod = format.substr(mod_start, mod_end - mod_start);
            }
            if (front_start != -1)
            {
                int front_end = format.find(" ", front_start);
                front = format.substr(front_start, front_end - front_start);
            }
            if (back_start != -1)
            {
                int back_end = format.find(" ", back_start);
                back = format.substr(back_start, back_end - back_start);
            }
            string txt = format.substr(txt_start, txt_end - txt_start);
            this->s[i].insert(start, txt);

            // convert mod to format
            if (mod == "bold")
            {
                mod = BOLD;
            }
            else if (mod == "underline")
            {
                mod = UNDERLINE;
            }
            else if (mod == "blink")
            {
                mod = BLINK;
            }
            else if (mod == "reverse")
            {
                mod = REVERSE;
            }
            else if (mod == "concealed")
            {
                mod = CONCEALED;
            }
            else
            {
                mod = "";
            }
            // convert front to format
            if (front == "black")
            {
                front = FRONT_BLACK;
            }
            else if (front == "red")
            {
                front = FRONT_RED;
            }
            else if (front == "green")
            {
                front = FRONT_GREEN;
            }
            else if (front == "yellow")
            {
                front = FRONT_YELLOW;
            }
            else if (front == "blue")
            {
                front = FRONT_BLUE;
            }
            else if (front == "purple")
            {
                front = FRONT_PURPLE;
            }
            else if (front == "cyan")
            {
                front = FRONT_CYAN;
            }
            else if (front == "white")
            {
                front = FRONT_WHITE;
            }
            else
            {
                front = "";
            }
            // convert back to format
            if (back == "black")
            {
                back = BACK_BLACK;
            }
            else if (back == "red")
            {
                back = BACK_RED;
            }
            else if (back == "green")
            {
                back = BACK_GREEN;
            }
            else if (back == "yellow")
            {
                back = BACK_YELLOW;
            }
            else if (back == "blue")
            {
                back = BACK_BLUE;
            }
            else if (back == "purple")
            {
                back = BACK_PURPLE;
            }
            else if (back == "cyan")
            {
                back = BACK_CYAN;
            }
            else if (back == "white")
            {
                back = BACK_WHITE;
            }
            else
            {
                back = "";
            }
            
            // conbine format
            format = mod + front + back;


            // add format to formats
            this->formats.push_back(Format(start, i, txt.length(), format));
        }
    }
}



Screen::Screen(int width, int height)
{
    this->width = width;
    this->height = height;
    this->buffer.resize(height);
    for (int i = 0; i < height; i++)
    {
        this->buffer[i].resize(width*2);
    }
    
}

void Screen::clear()
{
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            this->buffer[i][j] = ' ';
        }
    }
}

void Screen::refresh()
{
    cout << "\x1B[2J\x1B[H";
    // deep copy buffer to temp
    vector<string> temp = this->buffer;
    // sort formats by y and x desc
    sort(this->formats.begin(), this->formats.end(), [](Format a, Format b) {
        if (a.y == b.y)
        {
            return a.x > b.x;
        }
        return a.y > b.y;
    });

    for (int i = 0; i < this->formats.size(); i++)
    {
        int x = this->formats[i].x;
        int y = this->formats[i].y;
        int length = this->formats[i].length;
        string s = this->formats[i].format;
        // insert RESET to x + length in temp[y]
        temp[y].insert(x + length, RESET);
        // insert s to x in temp[y]
        temp[y].insert(x, s);

    }

    for (int i = 0; i < this->height; i++)
    {
        printf("%s", temp[i].c_str());
        cout << endl;
    }
}


void Screen::draw(int x, int y, string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        this->buffer[y][x + i] = s[i];
    }
}

void Screen::draw(int x, int y, vector<string> s)
{
    for (int i = 0; i < s.size(); i++)
    {
        this -> draw(x, y + i, s[i]);
    }
}

void Screen::draw(Object obj)
{
    obj.script2format();
    for (int i = 0; i < obj.formats.size(); i++)
    {
        this->formats.push_back(obj.formats[i]);
    }
    this->draw(obj.x, obj.y, obj.s);
}


int main()
{
    Screen screen(80, 10);
    screen.clear();
    vector<string> s = {
        "<format back=blue >hellosss</format> <format front=red >world</format>",
        "world"
        };

    Object obj(0, 0, s);
    
    
    screen.draw(obj);
    screen.refresh();
    screen.refresh();
    return 0;
}