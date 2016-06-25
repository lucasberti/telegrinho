#include "SendAudio.h"
#include "bot_reloaded.h"
#include <time.h>
#include <cstdlib> 

void checkForAudio(TgBot::Message::Ptr message)
{
	
	// Miss Nordestina
	if (message->text == "oi")
	{
		getBot().getApi().sendVoice(message->chat->id, MISS_NORDESTINA_FILE_ID);
	}

	else if (message->text == "!nordestina" || message->text == "/nordestina")
	{
		std::srand(time(0));
		int r = rand() % 19;
		getBot().getApi().sendVoice(message->chat->id, MISS_NORDESTINA_CHAT[r]);
	}

	else if (message->text == "!dolar" || message->text == "/dolar")
	{
		getBot().getApi().sendVoice(message->chat->id, MISS_NORDESTINA_DOLAR);
	}

	else if (message->text == "churos" || message->text == "Churos" || message->text == "CHUROS")
	{
		getBot().getApi().sendVoice(message->chat->id, MISS_NORDESTINA_FILE_ID);
	}

	else if (message->text == "xischupano")
	{
		getBot().getApi().sendVoice(message->chat->id, XIS_CHUPANO_FILE_ID);
	}

	else if (message->text == "trevah")
	{
		getBot().getApi().sendVoice(message->chat->id, TREVAH_FILE_ID);
	}

	else if (message->text == "retchagemeno")
	{
		getBot().getApi().sendVoice(message->chat->id, RETCHA_GEMENDO_FILE_ID);
	}
	
	else if (message->text == "meu deus")
	{
 		getBot().getApi().sendVoice(message->chat->id, HASTAD_MEU_DEUS);
	}
}
