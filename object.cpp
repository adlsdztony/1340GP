#include "object.h"

Object::Object(int x, int y, vector<string> s)
{
    this->x = x;
    this->y = y;
    this->s = s;
    this->script2format();
    this->priority = 0;
}

Object::Object(int x, int y, vector<string> s, Format format)
{
    this->x = x;
    this->y = y;
    this->s = s;
    this->script2format();
    this->priority = 0;
    this->formats.push_back(format);
}

// take a string get format and remove it from string
vector<Format> check_format(string &s, int i, int j){
    int start = 0;
    int end = 0;
    vector<Format> fs; 
    while (true)
    {
        start = s.find("<format", start);
        if (start == -1)
        {
            break;
        }
        end = s.find("</format>", start);
        if (end == -1)
        {
            break;
        }
        string format = s.substr(start, end - start + 9);
        s.erase(start, end - start + 9);
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
        s.insert(start, txt);

        
        if (mod_map.find(mod) != mod_map.end())
        {
            mod = mod_map.at(mod);
        }
        else
        {
            mod = "";
        }

        if (front_map.find(front) != front_map.end())
        {
            front = front_map.at(front);
        }
        else
        {
            front = "";
        }

        if (back_map.find(back) != back_map.end())
        {
            back = back_map.at(back);
        }
        else
        {
            back = "";
        }

        format = mod + front + back;

        
        fs.push_back(Format(start + j, i, txt.length(), format));

        // add format to formats
        
    }
    return fs;
}

void Object::script2format()
{
    // find <format mod={} front={} back={} > and </format> in s and remove them and add to formats
    for (int i = 0; i < this->s.size(); i++)
    {
        vector<Format> fs = check_format(this->s[i], i, 0);
        for (int j = 0; j < fs.size(); j++)
        {
            this->formats.push_back(fs[j]);
        }
    }
}
