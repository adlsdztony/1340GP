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
    // init format_map with -1
    this->format_map.resize(height);
    for (int i = 0; i < height; i++)
    {
        this->format_map[i].resize(width);
        for (int j = 0; j < width; j++)
        {
            this->format_map[i][j] = -1;
        }
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
    // init format_map with -1
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            this->format_map[i][j] = -1;
        }
    }
}

void Screen::refresh()
{
    cout << "\x1B[2J\x1B[H";
    // deep copy buffer to temp
    vector<string> temp = this->buffer;
    // sort formats by y and x desc
    // sort(this->formats.begin(), this->formats.end(), [](Format a, Format b) {
    //     if (a.y == b.y)
    //     {
    //         return a.x > b.x;
    //     }
    //     return a.y > b.y;
    // });

    // print format_map
    // for (int i = 0; i < this->height; i++)
    // {
    //     for (int j = 0; j < this->width; j++)
    //     {
    //         cout << this->format_map[i][j] << " ";
    //     }
    //     cout << endl;
    // }  

    // for (int i = 0; i < this->formats.size(); i++)
    // {
    //     int x = this->formats[i].x;
    //     int y = this->formats[i].y;
    //     int length = this->formats[i].length;
    //     string s = this->formats[i].format;
    //     // insert RESET to x + length in temp[y]
    //     temp[y].insert(x + length, RESET);
    //     // insert s to x in temp[y]
    //     temp[y].insert(x, s);

    // }

    // draw formats according to format_map consider overlap
    // for (int i = 0; i < this->height; i++)
    // {
    //     for (int j = 0; j < this->width; j++)
    //     {
    //         int format_index = this->format_map[i][j];
    //         int temp_j = j;
    //         if (format_index != -1)
    //         {
    //             // get how long the format is
    //             while (this->format_map[i][j] == format_index && j < this->width)
    //             {
    //                 j++;
    //             }
    //             // insert RESET to j in temp[i]
    //             temp[i].insert(j, RESET);
    //             // insert format to j - length in temp[i]
    //             temp[i].insert(temp_j, this->formats[format_index].format);
    //         }
    //     }
    // }

    // draw formats according to format_map consider overlap from right to left
    for (int i = 0; i < this->height; i++)
    {
        for (int j = this->width - 1; j >= 0; j--)
        {
            int format_index = this->format_map[i][j];
            int temp_j = j;
            if (format_index != -1)
            {
                // get how long the format is
                while (this->format_map[i][j] == format_index && j >= 0)
                {
                    j--;
                }
                // insert RESET to temp_j + 1 in temp[i]
                temp[i].insert(temp_j + 1, RESET);
                // insert format to j + 1 in temp[i]
                temp[i].insert(j+1, this->formats[format_index].format);
            }
        }
    }

    for (int i = 0; i < this->height; i++)
    {
        printf("%s", temp[i].c_str());
        cout << endl;
    }

    printf("\033[?25l");
}


void Screen::draw(int x, int y, string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        this->buffer[y][x + i] = s[i];
    }
}

void Screen::draw(int x, int y, vector<string> &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        this -> draw(x, y + i, s[i]);
    }
}

void Screen::draw(Object* obj)
{
    obj->script2format();
    for (int i = 0; i < obj->formats.size(); i++)
    {
        Format temp_format = obj->formats[i];
        temp_format.x += obj->x;
        temp_format.y += obj->y;
        this->formats.push_back(temp_format);
        // update format_map
        for (int j = 0; j < temp_format.length; j++)
        {
            this->format_map[temp_format.y][temp_format.x + j] = this->formats.size() - 1;
        }
    }
    this->draw(obj->x, obj->y, obj->s);
}
