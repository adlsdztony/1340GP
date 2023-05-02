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
    {"mom", {
        "Have you eaten yet? I'm going to cook something delicious for you.",
        "Come back home early!", 
        "Don't forget to explore and enjoy the journey. There's so much to see and experience in this world,",
	"and the bonds you form with your Pokemon along the way will last a lifetime. I'll be cheering you on every step of the way!"
        }
    },
    {"doctor", {
	"Hello there, young trainer! I am a Pokemon doctor, and I specialize in the health and well-being of all Pokemon. I see that you don't have a Pokemon yet, so I would like to offer you one to start your journey.",
	"Choose one from these three Pokemon: grass,fire or water. Take care of your new partner and make sure to come back to me if you need any medical attention for your Pokemon. Good luck on your journey!",	    
        "If you're interested in learning more about Pokemon battles, you should check out Ash. He's a skilled Pokemon trainer who hangs out at the along the Chuntian Path.", 
	"Maybe He can teach you about battle strategies and help you improve your skills. Just head east from here and you'll see him. Good luck!"
        }
    },
    {"ash", {
	"Hi there, trainer! Did the doctor ask you to come? My name is Ash. I see that you're interested in learning more about Pokemon battles. Well, you've come to the right place!",
	"The key to any successful battle is using the right strategies. You need to know your Pokemon's strengths and weaknesses and use them to your advantage.",
	"For example, if you're facing a water-type Pokemon, use grass-type move to gain the upper hand. And always make sure to train your Pokemon and keep them in top shape.",
	"If you're looking to catch more Pokemon, you need to have a good capture strategy. The first step is weakening the Pokemon you want to catch, but not too much, or else it might faint",
	"Once the Pokemon is weakened, use a Pokeball to catch it. Different types of Pokeballs work better on different types of Pokemon,", 
	"so make sure to choose the right one. And don't forget to stock up on plenty of Pokeballs before you head out on your journey! Good luck catching them all!",
        "Did you know that there are other Pokemon players out there just like you? You can challenge them to battles and test your skills against theirs. There are also Pokemon tournaments held in different sites,",
	"where you can compete against other trainers for prizes and recognition. Keep training your Pokemon and who knows, maybe you'll become the next Pokemon champion!"
        }
    },
    {"Siki", {
        "Ah, you want to challenge me, trainer? I'm always up for a good battle. But be warned, I won't go easy on you just because we're chatting. My Pokemon and I are always ready for a challenge. Are you sure you're ready to face us? If so, let's battle and see who comes out!"
        }
    },
    {"Peter", {
        "Hey, trainer! I see you've been training your Pokemon hard. I think it's time we put your skills to the test. Let's have a friendly battle and see how you fare against me. Don't worry, it'll be a good learning experience for both of us!"
        }
    },
    {"Daniel", {
        "Hello, young trainer. I've been watching you from afar and I must say, I'm impressed with your progress. You've come a long way since you started your journey. But don't get too confident. There's always room for improvement. Let me give you a challenge and see if you're truly ready for what lies ahead."
        }
    },
    {"Tony", {
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
