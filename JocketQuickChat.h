#pragma once

#include <tgbot/tgbot.h>
#include <map>
#include "bot_reloaded.h"

const std::string Informational[4] = {"I got it!", "Centering...", "Take the shot!", "Defending..."};
const std::string Compliments[4] = { "Nice shot!", "Great pass!", "Thanks!", "What a save!"};
const std::string Reactions[4] = { "OMG!", "Noooo!", "Wow!", "Close one!"};
const std::string Apologies[4] = { "$#@%!", "No Problem.", "Whoops...", "Sorry!" };

void checkQuickChat(TgBot::Message::Ptr message, std::string menu, std::string op);
void sendInformational(TgBot::Message::Ptr message, int op);
void sendCompliments(TgBot::Message::Ptr message, int op);
void sendReactions(TgBot::Message::Ptr message, int op);
void sendApologies(TgBot::Message::Ptr message, int op);