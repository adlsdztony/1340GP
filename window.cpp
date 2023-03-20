#include "window.h"

#include <iostream>


Window::Window(int x, int y, int width, int length, string title, vector<string> content)
{
    this->x = x;
    this->y = y;
    this->title = title;
    this->content = content;
    
    // create a window use - and | to draw a box
    s.push_back(string(width, '-'));
    for (int i = 0; i < length; i++)
    {
        s.push_back(string(1, '|') + string(width - 2, ' ') + string(1, '|'));
    }
    s.push_back(string(width, '-'));
    
    // add title
    vector<Format> fs = check_format(title, 1);
    int title_start = (width - title.length()) / 2;
    cout << title.length() << endl;
    for (int i = 0; i < fs.size(); i++)
    {
        fs[i].x += title_start;
        formats.push_back(fs[i]);
    }
    s[1].replace(title_start, title.length(), title);

    // add content
    for (int i = 0; i < content.size(); i++)
    {
        vector<Format> fs = check_format(content[i], i + 3, 1);
        for (int j = 0; j < fs.size(); j++)
        {
            formats.push_back(fs[j]);
        }
        s[i + 3].replace(1, content[i].length(), content[i]);
    }


}

