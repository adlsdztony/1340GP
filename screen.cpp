#include "screen.h"


vector<string> letter_a = {
    "█████╗  ",
    "██╔══██╗",
    "███████║",
    "██╔══██║",
    "██║  ██║",
    "╚═╝  ╚═╝"};

vector<string> letter_b = {
    "██████╗ ",
    "██╔══██╗",
    "██████╔╝",
    "██╔══██╗",
    "██████╔╝",
    "╚═════╝ "};

vector<string> letter_c = {
    "███████╗",
    "██╔════╝",
    "██║     ",
    "██║     ",
    "╚██████╗",
    " ╚═════╝"};

vector<string> letter_d = {
    "██████╗ ",
    "██╔══██╗",
    "██║  ██║",
    "██║  ██║",
    "██████╔╝",
    "╚═════╝ "};

vector<string> letter_e = {
    "███████╗",
    "██╔════╝",
    "█████╗  ",
    "██╔══╝  ",
    "███████╗",
    "╚══════╝"};

vector<string> letter_f = {
    "███████╗",
    "██╔════╝",
    "█████╗  ",
    "██╔══╝  ",
    "██║     ",
    "╚═╝     "};

vector<string> letter_g = {
    "███████╗ ",
    "██╔════╝ ",
    "██║  ███╗",
    "██║   ██║",
    "╚██████╔╝",
    " ╚═════╝ "};

vector<string> letter_h = {
    "██╗  ██╗",
    "██║  ██║",
    "███████║",
    "██╔══██║",
    "██║  ██║",
    "╚═╝  ╚═╝"};

vector<string> letter_i = {
    " ██╗ ",
    " ██║ ",
    " ██║ ",
    " ██║ ",
    " ██║ ",
    " ╚═╝ "};

vector<string> letter_j = {
    "     ██╗",
    "     ██║",
    "     ██║",
    "██   ██║",
    "╚█████╔╝",
    " ╚════╝ "};

vector<string> letter_k = {
    "██╗  ██╗",
    "██║ ██╔╝",
    "█████╔╝ ",
    "██╔═██╗ ",
    "██║  ██╗",
    "╚═╝  ╚═╝"};

vector<string> letter_l = {
    "██╗     "
    "██║     "
    "██║     "
    "██║     "
    "███████╗"
    "╚══════╝"};

vector<string> letter_m = {
    "███╗   ███╗",
    "████╗ ████║",
    "██╔████╔██║",
    "██║╚██╔╝██║",
    "██║ ╚═╝ ██║",
    "╚═╝     ╚═╝"};

vector<string> letter_n = {
    "███╗   ██╗",
    "████╗  ██║",
    "██╔██╗ ██║",
    "██║╚██╗██║",
    "██║ ╚████║",
    "╚═╝  ╚═══╝"};

vector<string> letter_o = {
    "█████╗  ",
    "██╔══██╗",
    "██║  ██║",
    "██║  ██║",
    "╚█████╔╝",
    " ╚════╝ "};
vector<string> letter_p = {
    "██████╗ ",
    "██╔══██╗",
    "██████╔╝",
    "██╔═══╝ ",
    "██║     ",
    "╚═╝     "};

vector<string> letter_q = {
    "██████╗  ",
    "██╔══██╗ ",
    "██║  ██║ ",
    "██║▄▄ ██║",
    "╚██████╔╝",
    " ╚══▀▀═╝ "};

vector<string> letter_r = {
    "██████╗ ",
    "██╔══██╗",
    "██████╔╝",
    "██╔══██╗",
    "██║  ██║",
    "╚═╝  ╚═╝"};


vector<string> letter_s = {
    "███████╗",
    "██╔════╝",
    "███████╗",
    "╚════██║",
    "███████║",
    "╚══════╝"};

vector<string> letter_t = {
    "███████╗ ",
    "╚══██╔══╝",
    "   ██║   ",
    "   ██║   ",
    "   ██║   ",
    "   ╚═╝   "};

    vector<string> letter_u = {
    "██╗  ██╗",
    "██║  ██║",
    "██║  ██║",
    "██║  ██║",
    "╚█████╔╝",
    " ╚════╝ "};

vector<string> letter_v = {
    "██╗   ██╗",
    "██║   ██║",
    "██║   ██║",
    "╚██╗ ██╔╝",
    " ╚████╔╝ ",
    "  ╚═══╝  "};

vector<string> letter_w = {
    "██╗    ██╗",
    "██║    ██║",
    "██║ █╗ ██║",
    "██║███╗██║",
    "╚███╔███╔╝",
    " ╚══╝╚══╝ "};

vector<string> letter_x = {
    "██╗  ██╗",
    "╚██╗██╔╝",
    " ╚███╔╝ ",
    " ██╔██╗ ",
    "██╔╝ ██╗",
    "╚═╝  ╚═╝"};

vector<string> letter_y = {
    "██╗   ██╗",
    "╚██╗ ██╔╝",
    " ╚████╔╝ ",
    "  ╚██╔╝  ",
    "   ██║   ",
    "   ╚═╝   "};

vector<string> letter_z = {
    "███████╗",
    "╚══███╔╝",
    "  ███╔╝ ",
    " ███╔╝  ",
    "███████╗",
    "╚══════╝"};


map<char, vector<string>> letters = {
    {'a', letter_a}, {'b', letter_b}, {'c', letter_c}, {'d', letter_d},
    {'e', letter_e}, {'f', letter_f}, {'g', letter_g}, {'h', letter_h},
    {'i', letter_i}, {'j', letter_j}, {'k', letter_k}, {'l', letter_l},
    {'m', letter_m}, {'n', letter_n}, {'o', letter_o}, {'p', letter_p},
    {'q', letter_q}, {'r', letter_r}, {'s', letter_s}, {'t', letter_t},
    {'u', letter_u}, {'v', letter_v}, {'w', letter_w}, {'x', letter_x},
    {'y', letter_y}, {'z', letter_z}};

// int main() {
//   string input;
//   cin >> input;
//   for (int i = 0; i < 6; i++) {
//     for (char c : input) {
//       cout << letters[c][i] << " ";
//     }
//     cout << endl;
//   }
//   return 0;
// }


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
                while (j > 0)
                {
                    if (this->format_map[i][j - 1] != format_index)
                    {
                        break;
                    }
                    j--;
                }
                // insert RESET to temp_j + 1 in temp[i]
                temp[i].insert(temp_j + 1 , RESET);
                // insert format to j + 1 in temp[i]
                temp[i].insert(j, this->formats[format_index].format);
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

void Screen::draw(int x, int y, char c)
{
    this->buffer[y][x] = c;
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

void Screen::draw(vector<Object*> objs)
{
    
    for (int i = 0; i < objs.size(); i++)
    {

        this->draw(objs[i]);
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

