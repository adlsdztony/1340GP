#include "object.h"

Object::Object(int x, int y, vector<string> s)
{
    this->x = x;
    this->y = y;
    this->s = s;
    this->priority = 0;
}

Object::Object(int x, int y, vector<string> s, Format format)
{
    this->x = x;
    this->y = y;
    this->s = s;
    this->priority = 0;
    this->formats.push_back(format);
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
