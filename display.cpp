#include "display.h"


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

    this->formats.clear();
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
        Format temp_format = obj.formats[i];
        temp_format.x += obj.x;
        temp_format.y += obj.y;
        this->formats.push_back(temp_format);
    }
    this->draw(obj.x, obj.y, obj.s);
}
