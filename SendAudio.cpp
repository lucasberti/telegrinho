#include "SendAudio.h"
#include "bot_reloaded.h"
#include <time.h>
#include <cstdlib> 

void checkForAudio(TgBot::Message::Ptr message)
{
	
	// Miss Nordestina
	if (message->text == "oi")
	{
		getBot().getApi().sendAudio(message->chat->id, MISS_NORDESTINA_FILE_ID);
	}

	if (message->text == "!nordestina" || message->text == "/nordestina")
	{
		std::srand(time(0));
		int r = rand() % 19;
		getBot().getApi().sendAudio(message->chat->id, MISS_NORDESTINA_CHAT[r]);
	}

	if (message->text == "!dolar" || message->text == "/dolar")
	{
		getBot().getApi().sendAudio(message->chat->id, MISS_NORDESTINA_DOLAR);
	}

	if (message->text == "churos" || message->text == "Churos" || message->text == "CHUROS")
	{
		getBot().getApi().sendAudio(message->chat->id, MISS_NORDESTINA_FILE_ID);
	}

	if (message->text == "xischupano")
	{
		getBot().getApi().sendAudio(message->chat->id, XIS_CHUPANO_FILE_ID);
	}

	if (message->text == "trevah")
	{
		getBot().getApi().sendAudio(message->chat->id, TREVAH_FILE_ID);
	}

	if (message->text == "retchagemeno")
	{
		getBot().getApi().sendAudio(message->chat->id, RETCHA_GEMENDO_FILE_ID);
	}
}
