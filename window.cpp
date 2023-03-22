#include "window.h"


Window::Window(int x, int y, int width, int length, string title, vector<string> content, int space)
{
    this->x = x;
    this->y = y;
    this->title = title;
    this->content = content;
    this->space = space;
    
    // create a window use +-+ and | to draw a box
    s.push_back(string(1, '+') + string(width - 2, '-') + string(1, '+'));
    
    for (int i = 0; i < length; i++)
    {
        s.push_back(string(1, '|') + string(width - 2, ' ') + string(1, '|'));
    }
    s.push_back(string(1, '+') + string(width - 2, '-') + string(1, '+'));
    
    // add title
    vector<Format> fs = check_format(title, 1);
    int title_start = (width - title.length()) / 2;
    for (int i = 0; i < fs.size(); i++)
    {
        fs[i].x += title_start;
        formats.push_back(fs[i]);
    }
    s[1].replace(title_start, title.length(), title);

    // add content
    for (int i = 0; i < content.size(); i++)
    {
        vector<Format> fs = check_format(content[i], i + 2 + space, 1);
        for (int j = 0; j < fs.size(); j++)
        {
            formats.push_back(fs[j]);
        }
        s[i + 2 + space].replace(1, content[i].length(), content[i]);
    }


}