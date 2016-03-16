#include "JocketQuickChat.h"

std::map<int, int> whoUsed;

void checkQuickChat(TgBot::Message::Ptr message, std::string menu, std::string opcao)
{
	// Converting input to int.
	int op = (opcao != "") ? stoi(opcao) : 0;

	// Checking when the message came.
	/*std::time_t t = std::time(0);
	whoUsed[message->from->id] = t;								// TO-DO: anti-flood
	int count = 0;*/

	if (menu == "1")
		sendInformational(message, op);

	else if (menu == "2")
		sendCompliments(message, op);

	else if (menu == "3")
		sendReactions(message, op);

	else if (menu == "4")
		sendApologies(message, op);
}

void sendInformational(TgBot::Message::Ptr message, int op)
{
	if (op >= 1 && op <= 4)
		getBot().getApi().sendMessage(message->chat->id, Informational[op - 1]);
	else if(op == 0)
		getBot().getApi().sendMessage(message->chat->id, "1. I got it!\n2. Centering...\n3. Take the shot!\n4. Defending...");
}

void sendCompliments(TgBot::Message::Ptr message, int op)
{
	if (op >= 1 && op <= 4)
		getBot().getApi().sendMessage(message->chat->id, Compliments[op - 1]);
	else if (op == 0)
		getBot().getApi().sendMessage(message->chat->id, "1. Nice shot!\n2. Great pass!\n3. Thanks!\n4. What a save!");
}

void sendReactions(TgBot::Message::Ptr message, int op)
{
	if (op >= 1 && op <= 4)
		getBot().getApi().sendMessage(message->chat->id, Reactions[op - 1]);
	else if (op == 0)
		getBot().getApi().sendMessage(message->chat->id, "1. OMG!\n2. Noooo!\n3. Wow!\n4. Close one!");
}

void sendApologies(TgBot::Message::Ptr message, int op)
{
	if (op >= 1 && op <= 4)
		getBot().getApi().sendMessage(message->chat->id, Apologies[op - 1]);
	else if (op == 0)
		getBot().getApi().sendMessage(message->chat->id, "1. $#@%!\n2. No Problem.!\n3. Whoops...\n4. Sorry!");
}