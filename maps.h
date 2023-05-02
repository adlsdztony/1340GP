#pragma once

#include <string>
#include <vector>
#include "map.h"
#include "format.h"



void init_chuntian_path(Map &map);
void init_chuntian_town(Map &map);
void init_Fairy_society_center(Map &map);
void init_grassland(Map &map);
void init_hill(Map &map);
void init_home(Map &map);
void init_market(Map &map);
void init_qiushui_town(Map &map);
void init_riverside(Map &map);

// TODO add interaction to maps



const vector<string> chuntian_path = {
    "<format front=blue >####################################################################</format>",
    "<format front=blue >#</format>     <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>        <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>      <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>    <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>          <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>        <format front=blue >#</format>",
    "<format front=blue >#</format>         <format front=green >^^^^^                               ^^^^^</format>                <format front=blue >#</format>",
    "<format front=blue >#</format>   <format front=cyan >*~~*~~*~~*~~*~~*     *~~*~~*~~*~~*~~*       *~~*~~*~~*~~*~~* </format>  <format front=blue >#</format>",
    "<format front=blue >####################################################################</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >====</format>                                                            <format front=blue >====</format>",
    "                                                                    ",
    "                                                                    ",
    "<format front=blue >====</format>                                         CCCCCCC            <format front=blue >====</format>",
    "<format front=blue >#</format>                                           O  ASH  O              <format front=blue >#</format>",
    "<format front=blue >#</format>                                            OOOOOOO               <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >####################################################################</format>",
    "<format front=blue >#</format>       <format front=cyan >*~~*~~*~~*~~*~~*     *~~*~~*~~*~~*~~*     *~~*~~*~~*~~*~~*</format> <format front=blue >#</format>",
    "<format front=blue >#</format>           <format front=green >^^^^^     ^^^^^         ^^^^^       ^^^^^     ^^^^^</format>    <format front=blue >#</format>",
    "<format front=blue >#</format>     <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>        <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>      <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>    <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>          <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>        <format front=blue >#</format>",
    "<format front=blue >####################################################################</format>",
};

const vector<string> chuntian_path_vaild = {
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "00001111111111111111111111111111111111111111111111111111111111110000",
    "L111111111111111111111111111111111111111111111111111111111111111111R",
    "L11111111111111111111111111111111111111111111ZZZZZZZ111111111111111R",
    "00001111111111111111111111111111111111111111100000001111111111110000",
    "01111111111111111111111111111111111111111111000000000111111111111110",
    "01111111111111111111111111111111111111111111100000001111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000000000000000",
};

const map<char, string> chuntian_path_interact = {
    {'L', "chuntian_town 66 9"},
    {'Z', "chat ash"},
    {'R', "riverside 1 13"}
};

// const Map chuntian_path_map(chuntian_path, chuntian_path_vaild, chuntian_path_interact);


const vector<string> chuntian_town = {
    "<format front=blue >####################################################################</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>       <format front=green >^^^^</format>                 <format front=white >########</format>             <format front=white >########</format>         <format front=blue >#</format>",
    "<format front=blue >#</format>         <format front=green >^^^^</format>               <format front=white >#      #</format>             <format front=white >#      #</format>         <format front=blue >#</format>",
    "<format front=blue >#</format>                            <format front=white >########</format>             <format front=white >#Market#</format>    <format front=green >^^^^</format> <format front=blue >#</format>",
    "<format front=blue >#</format>         <format front=white >########</format>                                <format front=white >#      #</format>         <format front=blue >#</format>",
    "<format front=blue >#</format>         <format front=white ># Home #</format>           <format front=green >^^^^</format>                 <format front=white >###--###</format>         <format front=blue >#</format>",
    "<format front=blue >#</format>         <format front=white >###--###</format>                                                 <format front=blue >#</format>",
    "<format front=blue >====</format>                   <format front=white >#########################</format>     <format front=green >^^^^</format>       <format front=blue >====</format>",
    "                       <format front=white >#                       #</format>                    ",
    "                       <format front=white >#      Fairy            #</format>                    ",
    "<format front=blue >====</format>                   <format front=white >#        Society        #</format>                <format front=blue >====</format>",
    "<format front=blue >#</format>                      <format front=white >#           Center      #</format>                   <format front=blue >#</format>",
    "<format front=blue >#</format>        <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>         <format front=white >#                       #</format>                   <format front=blue >#</format>",
    "<format front=blue >#</format>                      <format front=white >#########------##########</format>                   <format front=blue >#</format>",
    "<format front=blue >#</format>      <format front=white >########</format>                                    <format front=white >########</format>        <format front=blue >#</format>",
    "<format front=blue >#</format>      <format front=white >#      #</format>            <format front=green >^^^^</format>                    <format front=white >#      #</format>        <format front=blue >#</format>",
    "<format front=blue >#</format>      <format front=white >########</format>                         <format front=green >^^^^</format>       <format front=white >########</format>        <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >####################################################################</format>",
};

const vector<string> chuntian_town_vaild = {
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111000000001111111111111000000001111111110",
    "011111111111aa111111111111111000000001111111111111000000001111111110",
    "01111111111111111111111111111000000001111111111111000000001111111110",
    "01111111110000000011111111111111111111111111111111000000001111111110",
    "01111111110000000011111111111111111111111111111111000000001111111110",
    "01111111110000000011111111111111111111111111111111111MM1111111111110",
    "0000111111111HH11111111000000000000000000000000011111111111111110000",
    "L111111111111111111111100000000000000000000000001111111111111111111R",
    "L111111111111111111111100000000000000000000000001111111111111111111R",
    "00001111111111111111111000000000000000000000000011111111111111110000",
    "01111111111111111111111000000000000000000000000011111111111111111110",
    "01111111111111111111111000000000000000000000000011111111111111111110",
    "01111111111111111111111000000000000000000000000011111111111111111110",
    "01111110000000011111111111111111FFFFFF111111111111100000000111111110",
    "01111110000000011111111111111111111111111111111111100000000111111110",
    "01111110000000011111111111111111111111111bb1111111100000000111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "00000000000000000000000000000000000000000000000000000000000000000000",
};

const map<char, string> chuntian_town_interact = {
    {'M', "market 35 18"},
    {'F', "Fairy_society_center 33 18"},
    {'H', "home 33 18"},
    {'L', "grassland 66 9"},
    {'R', "chuntian_path 1 10"},
    {'a', "fight Ninetales"},  
    {'b', "fight Rapidash"}
};

// const Map chuntian_town_map(chuntian_town, chuntian_town_vaild, chuntian_town_interact);

const vector<string> Fairy_society_center = {
    "<format front=blue >####################################################################</format>",
    "<format front=blue >#</format>                        <format front=white >\\                    /</format>                    <format front=blue >#</format>",
    "<format front=blue >#</format>                         <format front=white >\\  Recovery center /</format>                     <format front=blue >#</format>",
    "<format front=blue >#</format>                          <format front=white >\\_______  _______/</format>                      <format front=blue >#</format>",
    "<format front=blue >#</format>                                              <format front=white >OOOOOOOOOO</format>          <format front=blue >#</format>",
    "<format front=blue >#</format>                                             <format front=white >C          O</format>         <format front=blue >#</format>",
    "<format front=blue >#</format>                                             <format front=white >C  DOCTOR  O</format>         <format front=blue >#</format>",
    "<format front=blue >#</format>                                             <format front=white >C          O</format>         <format front=blue >#</format>",
    "<format front=blue >#</format>                                              <format front=white >OOOOOOOOOO</format>          <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                        <format front=blue >|</format>             <format front=blue >|</format>                           <format front=blue >#</format>",
    "<format front=blue >#</format>                        <format front=blue >|</format>             <format front=blue >|</format>                           <format front=blue >#</format>",
    "<format front=blue >#########################|             |############################</format>",
};

const vector<string> Fairy_society_center_vaild = {
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "01111111111111111111111110000000000000000000000111111111111111111110",
    "01111111111111111111111111000000000000000000001111111111111111111110",
    "01111111111111111111111111100000000000000000011111111111111111111110",
    "01111111111111111111111111111111111RR1111111110000000000111111111110",
    "01111111111111111111111111111111111111111111O00000000000011111111110",
    "01111111111111111111111111111111111111111111O00000000000011111111110",
    "01111111111111111111111111111111111111111111O00000000000011111111110",
    "01111111111111111111111111111111111111111111110000000000111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111110111111111111101111111111111111111111111110",
    "01111111111111111111111110111111111111101111111111111111111111111110",
    "00000000000000000000000000DDDDDDDDDDDDD00000000000000000000000000000",
};

const map<char, string> Fairy_society_center_interact = {
    {'O', "chat doctor"},
    {'R', "chat recovery_center"},
    {'D', "chuntian_town 35 15"}
};

// const Map Fairy_society_center_map(Fairy_society_center, Fairy_society_center_vaild, Fairy_society_center_interact);



const vector<string> grassland = {
    "<format front=blue >####################################################################</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>       <format front=green >^^^^^^^^</format>                                                   <format front=blue >#</format>",
    "<format front=blue >#</format>                                <format front=green >^^^^^^^^</format>                          <format front=blue >#</format>",
    "<format front=blue >#</format>                                      <format front=green >^^^^^^^^</format>                    <format front=blue >#</format>",
    "<format front=blue >#</format>                    <format front=green >^^^^^^^^</format>                <format front=green >^^^^^^^^</format>              <format front=blue >#</format>",
    "<format front=blue >#</format>  OOOOOOOOO                       <format front=green >^^^^^^^^</format>                        <format front=blue >#</format>",
    "<format front=blue >#</format> O         C                                                      <format front=blue >#</format>",
    "<format front=blue >#</format> O  PETER  C                                                   <format front=blue >====</format>",
    "<format front=blue >#</format> O         C                               <format front=green >^^^^^^^^</format>                 ",
    "<format front=blue >#</format>  OOOOOOOOO                                                         ",
    "<format front=blue >#</format>                    <format front=green >^^^^^^^^</format>                                   <format front=blue >====</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                          CCCCCCCC                                <format front=blue >#</format>",
    "<format front=blue >#</format>                         O        O                               <format front=blue >#</format>",
    "<format front=blue >#</format>   <format front=green >^^^^^^^^</format>              O DANIEL O              <format front=green >^^^^^^^^</format>         <format front=blue >#</format>",
    "<format front=blue >#</format>                         O        O            <format front=green >^^^^^^^^</format>           <format front=blue >#</format>",
    "<format front=blue >#</format>         <format front=green >^^^^^^^^</format>         OOOOOOOO                <format front=green >^^^^^^^^</format>        <format front=blue >#</format>",
    "<format front=blue >#</format>                                            <format front=green >^^^^^^^^</format>              <format front=blue >#</format>",
    "<format front=blue >####################################################################</format>",
};

const vector<string> grassland_vaild = {
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01100000000011111111111111111111111111cc1111111111111111111111111110",
    "0100000000000B111111111111111111111111111111111111111111111111111110",
    "0100000000000B111111111111111111111111111111111111111111111111110000",
    "0100000000000B11111111111111111111111111111111mm1111111111111111111R",
    "0110000000001111111111111111111111111111111111111111111111111111111R",
    "01111111111111111111111111111111111111111111111111111111111111110000",
    "011111111111111111111111111CCCCCCCC111111111111111111111111111111110",
    "01111111111111111111111111100000000111111111111111111111111111111110",
    "01111111111111111111111111000000000011111111111111111111111111111110",
    "01111111dd1111111111111111000000000011111111111111111111111111111110",
    "01111111111111111111111111000000000011111111111111111111111111111110",
    "01111111111111111111111111100000000111111111111111111111111111111110",
    "0111111111111111111111111111111111111111111111nn11111111111111111110",
    "00000000000000000000000000000000000000000000000000000000000000000000",
};

const map<char, string> grassland_interact = {
    {'B', "chat Peter"},
    {'C', "chat Daniel"},
    {'R', "chuntian_town 1 10"},
    {'c', "fight Weepinbell"},
    {'d', "fight Grovyle"},
    {'m', "fight Venusaur"},
    {'n', "fight Sceptile"}
};

// const Map grassland_map(grassland, grassland_vaild, grassland_interact);

const vector<string> hill = {
    "<format front=blue >########################|                  |########################</format>",
    "<format front=blue >#</format>                       <format front=blue >|                  |</format>                       <format front=blue >#</format>",
    "<format front=blue >#</format>                       <format front=blue >|                  |</format>                       <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>          <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>                                                   <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                    <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>         <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>               <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>                                              <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                             CCCCCCCCCCC          <format front=blue >#</format>",
    "<format front=blue >#</format>                                <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>       O           O         <format front=blue >#</format>",
    "<format front=blue >#</format>                                           O             O        <format front=blue >#</format>",
    "<format front=blue >#</format>                                          O  T  O  N  Y   O       <format front=blue >#</format>",
    "<format front=blue >#</format>     <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>                                O               O       <format front=blue >#</format>",
    "<format front=blue >#</format>                                           O             O        <format front=blue >#</format>",
    "<format front=blue >#</format>                                            OOOOOOOOOOOOO          <format front=blue >#</format>",
    "<format front=blue >#</format>                              <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>                               <format front=blue >#</format>",
    "<format front=blue >####################################################################</format>",
};

const vector<string> hill_vaild = {
    "0000000000000000000000000UUUUUUUUUUUUUUUUUU0000000000000000000000000",
    "01111111111111111111111101111111111111111110111111111111111111111110",
    "01111111111111111111111101111111111111111110111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "011111111111ee111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "0111111111111111111111111111111111111111111111DDDDDDDDDDD11111111110",
    "01111111111111111111111111111111111111111111110000000000011111111110",
    "01111111111111111111111111111111111111111111100000000000001111111110",
    "01111111111111111111111111111111111111111111000000000000000111111110",
    "01111111111111111111111111111111111111111110000000000000000011111110",
    "01111111111111111111111111111111111111111110000000000000000011111110",
    "01111111111111111111111111111111111111111111000000000000000111111110",
    "01111111111111111111111111111111111111111111100000000000001111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "00000000000000000000000000000000000000000000000000000000000000000000",
};

const map<char, string> hill_interact = {
    {'U', "riverside 34 19"},
    {'D', "chat Tony"},
    {'e', "fight Sentret"}
};

// const Map hill_map(hill, hill_vaild, hill_interact);



const vector<string> home = {
    "<format front=blue >####################################################################</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>       OOOOOOOOO                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>      O         C                                                 <format front=blue >#</format>",
    "<format front=blue >#</format>      O   MOM   C                                                 <format front=blue >#</format>",
    "<format front=blue >#</format>      O         C                                                 <format front=blue >#</format>",
    "<format front=blue >#</format>       OOOOOOOOO                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                        <format front=blue >|             |</format>                           <format front=blue >#</format>",
    "<format front=blue >#</format>                        <format front=blue >|             |</format>                           <format front=blue >#</format>",
    "<format front=blue >#########################|             |############################</format>",
};

const vector<string> home_vaild = {
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111000000000111111111111111111111111111111111111111111111111110",
    "011111100000000000M1111111111111111111111111111111111111111111111110",
    "011111100000000000M1111111111111111111111111111111111111111111111110",
    "011111100000000000M1111111111111111111111111111111111111111111111110",
    "01111111000000000111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111110111111111111101111111111111111111111111110",
    "01111111111111111111111110111111111111101111111111111111111111111110",
    "00000000000000000000000000DDDDDDDDDDDDD00000000000000000000000000000",
};

const map<char, string> home_interact = {
    {'M', "chat mom"},
    {'D', "chuntian_town 14 8"}
};               

// const Map home_map(home, home_vaild, home_interact);

const vector<string> market = {
    "<format front=blue >####################################################################</format>",
    "<format front=blue >#</format>                    |                        |                    <format front=blue >#</format>",
    "<format front=blue >#</format>                    |        Purchase        |                    <format front=blue >#</format>",
    "<format front=blue >#</format>                    |         Center         |                    <format front=blue >#</format>",
    "<format front=blue >#</format>                    |                        |                    <format front=blue >#</format>",
    "<format front=blue >#</format>                    |__________$$$$__________|                    <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                        <format front=blue >|                |</format>                        <format front=blue >#</format>",
    "<format front=blue >#</format>                        <format front=blue >|                |</format>                        <format front=blue >#</format>",
    "<format front=blue >#########################|                |#########################</format>",
};

const vector<string> market_vaild = {
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "01111111111111111111100000000000000000000000000111111111111111111110",
    "01111111111111111111100000000000000000000000000111111111111111111110",
    "01111111111111111111100000000000000000000000000111111111111111111110",
    "01111111111111111111100000000000000000000000000111111111111111111110",
    "01111111111111111111100000000000000000000000000111111111111111111110",
    "01111111111111111111111111111111BBBB11111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111110111111111111111101111111111111111111111110",
    "01111111111111111111111110111111111111111101111111111111111111111110",
    "00000000000000000000000000DDDDDDDDDDDDDDDD00000000000000000000000000",
};

const map<char, string> market_interact = {
    {'B', "chat supermarket"},
    {'D', "chuntian_town 54 7"}
};

// const Map market_map(market, market_vaild, market_interact);



const vector<string> qiushui_town = {
    "<format front=blue >####################################################################</format>",
    "<format front=blue >#</format>                     <format front=cyan >~~~</format>          <format front=green >^^^^</format>              <format front=cyan >~~~</format>           <format front=blue >#</format>",
    "<format front=blue >#</format>        ########                                 ########         <format front=blue >#</format>",
    "<format front=blue >#</format>        #      #              <format front=cyan >~~~</format>                #      #         <format front=blue >#</format>",
    "<format front=blue >#</format>        ########             <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>               #Market#         <format front=blue >#</format>",
    "<format front=blue >#</format>                                                 #      #         <format front=blue >#</format>",
    "<format front=blue >#</format>       <format front=green >^^^^</format>                                      ###--###   <format front=green >^^^^</format>  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                 <format front=green >^^^^</format>             <format front=blue >#</format>",
    "<format front=blue >====</format>                   #########################                   <format front=blue >#</format>",
    "                       #                       #                   <format front=blue >#</format>",
    "                       #      Fairy            #                   <format front=blue >#</format>",
    "<format front=blue >====</format>                   #        Society        #    ########       <format front=blue >#</format>",
    "<format front=blue >#</format>       <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>          #           Center      #    #      #       <format front=blue >#</format>",
    "<format front=blue >#</format>           <format front=green >^^^^</format>       #                       #    ########  <format front=cyan >~~~</format>  <format front=blue >#</format>",
    "<format front=blue >#</format>                      #########------##########                   <format front=blue >#</format>",
    "<format front=blue >#</format>      ########       <format front=cyan >~~~</format>                           <format front=green >^^^^</format>           <format front=blue >#</format>",
    "<format front=blue >#</format>      #      #         <format front=green >^^^^</format>               <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>                   <format front=blue >#</format>",
    "<format front=blue >#</format>      ########                           <format front=cyan >~~~~~~~~</format> <format front=green >^^</format><format front=red >*</format><format front=green >^^</format>           <format front=blue >#</format>",
    "<format front=blue >#</format>                         <format front=cyan >~~~~~~~~</format>    <format front=cyan >~~~</format> <format front=cyan >~~~~~~~~</format>                 <format front=blue >#</format>",
    "<format front=blue >####################################################################</format>",
};

const vector<string> qiushui_town_vaild = {
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111100000000111111111111111111111111111111111000000001111111110",
    "01111111100000000111111111111111111111111111111111000000001111111110",
    "01111111100000000111111111111111111111111111111111000000001111111110",
    "01111111111111111111111111111111111111111111111111000000001111111110",
    "01111111111111111111111111111111111111111111111111000000001111ii1110",
    "01111111111111111111111111111111111111111111111111111MM1111111111110",
    "00001111111111111111111000000000000000000000000011111111111111111110",
    "L1111111111111111111111000000000000000000000000011111111111111111110",
    "L1111111111111111111111000000000000000000000000011111111111111111110",
    "00001111111111111111111000000000000000000000000011110000000011111110",
    "01111111111gg1111111111000000000000000000000000011110000000011111110",
    "01111111111111111111111000000000000000000000000011110000000011pp1110",
    "01111111111111111111111000000000000000000000000011111111111111111110",
    "01111110000000011111111111111111FFFFFF111111111111111111111111111110",
    "01111110000000011111111111111111111111111111111111111111111111111110",
    "0111111000000001111111111111111111111111111hh11111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "00000000000000000000000000000000000000000000000000000000000000000000",
};

const map<char, string> qiushui_town_interact = {
    {'L', "riverside 66 13"},
    {'F', "Fairy_society_center1 33 18"},
    {'M', "market1 35 18"},
    {'g', "fight Arcanine"},
    {'h', "fight Gyarados"},
    {'i', "fight Furret"},
    {'p', "fight Vaporeon"}
};

// const Map qiushui_town_map(qiushui_town, qiushui_town_vaild, qiushui_town_interact);

const vector<string> riverside = {
    "<format front=blue >####################################################################</format>",
    "<format front=blue >#</format><format front=cyan >~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ </format><format front=blue >#</format>",
    "<format front=blue >#</format><format front=cyan > ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~</format><format front=blue >#</format>",
    "<format front=blue >#</format><format front=cyan >~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ </format><format front=blue >#</format>",
    "<format front=blue >#</format><format front=cyan > ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~</format><format front=blue >#</format>",
    "<format front=blue >#</format><format front=cyan >~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ </format><format front=blue >#</format>",
    "<format front=blue >#</format>                         <format front=green >^^^^</format>                                     <format front=blue >#</format>",
    "<format front=blue >#</format>                                                     <format front=green >^^^^</format>         <format front=blue >#</format>",
    "<format front=blue >#</format>              <format front=green >^^^^</format>                                                <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                  <format front=green >^^^^</format>            <format front=blue >#</format>",
    "<format front=blue >====</format>                                                            <format front=blue >====</format>",
    "                                                   <format front=green >^^^^</format>             ",
    "                                                                    ",
    "<format front=blue >====</format>                                                            <format front=blue >====</format>",
    "<format front=blue >#</format>                                              CCCCCC              <format front=blue >#</format>",
    "<format front=blue >#</format>          <format front=green >^^^^</format>                               O SIKI O             <format front=blue >#</format>",
    "<format front=blue >#</format>                       <format front=blue >|                  |</format>   OOOOOO              <format front=blue >#</format>",
    "<format front=blue >#</format>                       <format front=blue >|                  |</format>                       <format front=blue >#</format>",
    "<format front=blue >########################|                  |########################</format>",
};

const vector<string> riverside_vaild = {
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "0111111111111111111111111111111kk11111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111jj1111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "011111111111111111111111111111111111111111111111111ll111111111111110",
    "00001111111111111111111111111111111111111111111111111111111111110000",
    "L111111111111111111111111111111111111111111111111111111111111111111R",
    "L111111111111111111111111111111111111111111111111111111111111111111R",
    "00001111111111111111111111111111111111111111111AAAAAA111111111110000",
    "01111111111111111111111111111111111111111111111000000111111111111110",
    "01111111111111111111111111111111111111111111110000000011111111111110",
    "01111111111111111111111101111111111111111110111000000111111111111110",
    "01111111111111111111111101111111111111111110111111111111111111111110",
    "0000000000000000000000000DDDDDDDDDDDDDDDDDD0000000000000000000000000",
};

const map<char, string> riverside_interact = {
    {'L', "chuntian_path 66 10"},
    {'R', "qiushui_town 1 10"},
    {'A', "chat Siki"},
    {'D', "hill 34 1" },
    {'j', "fight Blastoise"},
    {'k', "fight Wartortle"},
    {'l', "fight Charmeleon"}
};

// const Map riverside_map(riverside, riverside_vaild, riverside_interact);
const vector<string> Fairy_society_center1 = {
    "<format front=blue >####################################################################</format>",
    "<format front=blue >#</format>                      <format front=white >\\                    /</format>                      <format front=blue >#</format>",
    "<format front=blue >#</format>                       <format front=white >\\  Recovery center /</format>                       <format front=blue >#</format>",
    "<format front=blue >#</format>                        <format front=white >\\_______  _______/</format>                        <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                        <format front=blue >|</format>             <format front=blue >|</format>                           <format front=blue >#</format>",
    "<format front=blue >#</format>                        <format front=blue >|</format>             <format front=blue >|</format>                           <format front=blue >#</format>",
    "<format front=blue >#########################|             |############################</format>",
};

const vector<string> Fairy_society_center1_vaild = {
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "01111111111111111111111000000000000000000000011111111111111111111110",
    "01111111111111111111111100000000000000000000111111111111111111111110",
    "01111111111111111111111110000000000000000001111111111111111111111110",
    "011111111111111111111111111111111RR111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111110111111111111101111111111111111111111111110",
    "01111111111111111111111110111111111111101111111111111111111111111110",
    "00000000000000000000000000DDDDDDDDDDDDD00000000000000000000000000000",
};

const map<char, string> Fairy_society_center1_interact = {
    {'R', "chat recovery_center"},
    {'D', "qiushui_town 35 15"}
};

// const Map Fairy_society_center_map(Fairy_society_center1, Fairy_society_center1_vaild, Fairy_society_center1_interact);

const vector<string> market1 = {
    "<format front=blue >####################################################################</format>",
    "<format front=blue >#</format>                    |                        |                    <format front=blue >#</format>",
    "<format front=blue >#</format>                    |        Purchase        |                    <format front=blue >#</format>",
    "<format front=blue >#</format>                    |         Center         |                    <format front=blue >#</format>",
    "<format front=blue >#</format>                    |                        |                    <format front=blue >#</format>",
    "<format front=blue >#</format>                    |__________$$$$__________|                    <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                                                                  <format front=blue >#</format>",
    "<format front=blue >#</format>                        <format front=blue >|                |</format>                        <format front=blue >#</format>",
    "<format front=blue >#</format>                        <format front=blue >|                |</format>                        <format front=blue >#</format>",
    "<format front=blue >#########################|                |#########################</format>",
};

const vector<string> market1_vaild = {
    "00000000000000000000000000000000000000000000000000000000000000000000",
    "01111111111111111111100000000000000000000000000111111111111111111110",
    "01111111111111111111100000000000000000000000000111111111111111111110",
    "01111111111111111111100000000000000000000000000111111111111111111110",
    "01111111111111111111100000000000000000000000000111111111111111111110",
    "01111111111111111111100000000000000000000000000111111111111111111110",
    "01111111111111111111111111111111BBBB11111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111111111111111111111111111111111111111111111110",
    "01111111111111111111111110111111111111111101111111111111111111111110",
    "01111111111111111111111110111111111111111101111111111111111111111110",
    "00000000000000000000000000DDDDDDDDDDDDDDDD00000000000000000000000000",
};

const map<char, string> market1_interact = {
    {'B', "chat supermarket"},
    {'D', "qiushui_town 53 7"}
};

// const Map market1_map(market1, market1_vaild, market1_interact);

void init_maps(map<string, Map> &maps);
// const map<string, Map> maps_map = {
//     {"chuntian_path", chuntian_path_map},
//     {"chuntian_town", chuntian_town_map},
//     {"Fairy_society_center", Fairy_society_center_map},
//     {"grassland", grassland_map},
//     {"hill", hill_map},
//     {"home", home_map},
//     {"market", market_map},
//     {"qiushui_town", qiushui_town_map},
//     {"riverside", riverside_map},
//     {"market1", market1_map},
//     {"Fairy_society_center1", Fairy_society_center1_map}
// };