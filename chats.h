#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;



const map<string, vector<string>> chat_map = {
    {"start", {
        "Welcome to the game!",
        "You are a student in the school of magic."
        }
    },
    {"mom", {
        "You are a student in the school of magic.",
        "You are a student in the school of magic.You are a student in the school of magic.You are a student in the school of magic.You are a student in the school of magic."
        }
    },
    {"tue", {
        "You are a student in the school of magic."
        }
    },
    {"wed", {
        "You are a student in the school of magic."
        }
    },
    {"thu", {
        "You are a student in the school of magic."
        }
    },
    {"fri", {
        "You are a student in the school of magic."
        }
    },
    {"sat", {
        "You are a student in the school of magic."
        }
    },
    {"sun", {
        "You are a student in the school of magic."
        }
    },
    {"end", {
        "You are a student in the school of magic."
        }
    },
    {"default", {
        "You are a student in the school of magic."
        }
    }
};