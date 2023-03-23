#include "screen.h"


Screen::Screen(int width, int height)
{
    this->width = width;
    this->height = height;
    this->buffer.resize(height);
    for (int i = 0; i < height; i++)
    {
        this->buffer[i].resize(width, ' ');
    }
    this->current = this->buffer;
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

void Screen::clean(){
    cout << "\x1B[2J\x1B[H";
}

void Screen::insert_format(vector<string> &temp){
    temp = this->buffer;

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
}

void Screen::refresh()
{
    // cout << "\x1B[2J\x1B[H";
    vector<string> temp;
    this->insert_format(temp);

    // this->current = temp;

    // update line by line
    for (int i = 0; i < this->height; i++)
    {
        printf("\033[%d;1H", i + 1);
        printf("%s", temp[i].c_str());
    }
    cout << endl;
    
    printf("\033[?25l");
}


void Screen::draw(int x, int y, const string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        this->buffer[y][x + i] = s[i];
    }
}

void Screen::draw(int x, int y, const vector<string> &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        this -> draw(x, y + i, s[i]);
    }
}

void Screen::draw(Object* obj)
{
    // obj->script2format();
    // set format_map to -1 for the area that will be covered by obj
    for (int i = 0; i < obj->s.size(); i++)
    {
        for (int j = 0; j < obj->s[i].length(); j++)
        {
            this->format_map[obj->y + i][obj->x + j] = -1;
        }
    }

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

void Screen::draw(vector<Object>* objs)
{
    for (int i = 0; i < objs->size(); i++)
    {
        this->draw(&objs[i]);
    }
}

void Screen::draw_map(Map* map)
{
    this->buffer = map->s;
    
}


// only update the changed line of the screen
// TODO
void Screen::update()
{
    for (int i = 0; i < this->height; i++)
    {
        if (this->buffer[i] != this->current[i])
        {
            printf("\033[%d;0H", i);
            printf("%s", this->buffer[i].c_str());
        }
    }
    this->current = this->buffer;
    
}

