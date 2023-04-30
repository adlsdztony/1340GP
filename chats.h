#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;



const map<string, vector<string>> chat_map = {
    {"start", {
        "Welcome to the Pokemon world!",
        "And yes! it's no different from the one you know, enjoy our own text-based version!"
        }
    },
    {"mom1", {
        "Have you eaten yet? I'm going to cook something delicious for you.",
        "Come back home early!", 
        "Don't forget to explore and enjoy the journey. There's so much to see and experience in this world, and the bonds you form with your Pokemon along the way will last a lifetime. I'll be cheering you on every step of the way!"
        }
    },
    {"mom2", {
        "Oh my dear child, You're growing up to be a skilled and responsible trainer. Do you need any extra supplies or money for your journey? Don't forget to take breaks and call me once in a while to let me know how you're doing. Stay safe out there!"
        }
    },
    {"doctor1", {
        "Hello there, young trainer! I am a Pokemon doctor, and I specialize in the health and well-being of all Pokemon. I see that you don't have a Pokemon yet, so I would like to offer you one to start your journey. Choose one from these three Pokemon: grass,fire or water. Take care of your new partner and make sure to come back to me if you need any medical attention for your Pokemon. Good luck on your journey!"
        }
    },
    {"doctor2", {
        "Welcome, trainer! Have you been taking good care of your Pokemon? Remember, a healthy Pokemon is a happy Pokemon. If you need any healing or advice, don't hesitate to ask me.",
        "If you're interested in learning more about Pokemon battles, you should check out Xiao Zhi. He's a skilled Pokemon trainer who hangs out at the along the Chuntian Path. Maybe He can teach you about battle strategies and help you improve your skills. Just head east from here and you'll see him. Good luck!",
        "Welcome back, trainer! I see that your Pokemon are looking a bit tired. If you want to restore their health, you can take them to the Pokemon recovery center. It's a facility that specializes in healing Pokemon, and it's completely free of charge. Your Pokemon will be as good as new in no time!"
        }
    },
    {"xiaozhi1", {
        "Hi there, trainer! Did the doctor ask you to come? My name is Xiao Zhi. I see that you're interested in learning more about Pokemon battles. Well, you've come to the right place! The key to any successful battle is using the right strategies. You need to know your Pokemon's strengths and weaknesses and use them to your advantage. For example, if you're facing a water-type Pokemon, use grass-type move to gain the upper hand. And always make sure to train your Pokemon and keep them in top shape.",
        "If you're looking to catch more Pokemon, you need to have a good capture strategy. The first step is weakening the Pokemon you want to catch, but not too much, or else it might faint. Once the Pokemon is weakened, use a Pokeball to catch it. Different types of Pokeballs work better on different types of Pokemon, so make sure to choose the right one. And don't forget to stock up on plenty of Pokeballs before you head out on your journey! Good luck catching them all!"
        }
    },
    {"xiaozhi2", {
        "Hey there, again! Did you know that there are other Pokemon players out there just like you? You can challenge them to battles and test your skills against theirs. There are also Pokemon tournaments held in different sites, where you can compete against other trainers for prizes and recognition. Keep training your Pokemon and who knows, maybe you'll become the next Pokemon champion!",
        "btw, If you want to beat other Pokemon trainers, you need to have a good battle strategy. First, make sure you have a well-rounded team of Pokemon with a variety of moves and types. Then, study your opponent's Pokemon and try to anticipate their moves. Always be ready to switch out Pokemon if one is at a disadvantage. And most importantly, don't give up! Even if you lose a battle, you can learn from your mistakes and come back stronger. Keep practicing and you'll be a master trainer in no time!",
        "Hey, trainer! How's your journey going? Have you caught any new Pokemon lately? Don't forget to take care of your team and keep them in top shape. Oh, and have you heard about the legendary Pokemon that's rumored to be hiding somewhere in this region? I've been searching for it myself, but no luck so far. Anyway, keep up the good work and don't give up on your dreams of becoming a great Pokemon trainer!",
        "Hi! I see you've been traveling a lot lately. Have you visited any interesting places? Oh, and don't forget to take breaks and rest up your Pokemon. They need some R&R too! Anyway, it's always nice to see fellow trainers out and about. Keep up the good work!"
        }
    },
    {"xiaozhi3", {
        "Congratulations, trainer! You've beaten all the other Pokemon trainers in the region. That's quite an accomplishment! You must have a lot of skill and dedication to have come this far. You truly exemplify what it means to be a great Pokemon trainer. Keep up the good work and never stop striving to be the best."
        }
    },
    {"trainerA", {
        "Ah, you want to challenge me, trainer? I'm always up for a good battle. But be warned, I won't go easy on you just because we're chatting. My Pokemon and I are always ready for a challenge. Are you sure you're ready to face us? If so, let's battle and see who comes out!"
        }
    },
    {"trainerB", {
        "Hey, trainer! I see you've been training your Pokemon hard. I think it's time we put your skills to the test. Let's have a friendly battle and see how you fare against me. Don't worry, it'll be a good learning experience for both of us!"
        }
    },
    {"trainerC", {
        "Hello, young trainer. I've been watching you from afar and I must say, I'm impressed with your progress. You've come a long way since you started your journey. But don't get too confident. There's always room for improvement. Let me give you a challenge and see if you're truly ready for what lies ahead."
        }
    },
    {"trainerD", {
        "Greetings, fellow Pokemon enthusiast! I can see the passion for Pokemon in your eyes. It's always refreshing to meet someone who shares the same love for these creatures as I do. Let's have a friendly battle and see how we match up. And afterward, we can chat more about our favorite Pokemon and strategies. What do you say?"
        }
    },
    {"recovery_center", {
	    "Do you want to have all your Pokemons recovered?"
	    "They are all good now!"
	    }
	},
    {"supermarket", {
	    "What do you wanna buy?"
	    }
	}
};
