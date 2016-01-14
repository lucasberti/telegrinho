#include "Estiques.h"

bool estiquesStarted = false;

int estiquesStep = 0;
int idWhoStarted = 0;
int idWhere = 0;

std::string estiqueID = "";
std::string estiqueTrigger = "";

bool loaded = false;

void checkForEstique(TgBot::Message::Ptr message)
{
	if (!loaded)
		fileToMap("rs.txt", kv_Estiques); loaded = true;

	// Looping through the map, checking if the message matches any trigger
	for (auto it = kv_Estiques.cbegin(); it != kv_Estiques.cend(); it++)
	{
		//std::cout << it->first << " E O SEGUNDO " << it->second << std::endl;

		if (message->text == it->first)
			getBot().getApi().sendSticker(message->chat->id, it->second.c_str());
	}

	// Sends every sticker in the database (rs.txt).
	if (message->text == "estiques")
	{
		std::string list = "";

		for (auto it = kv_Estiques.cbegin(); it != kv_Estiques.cend(); it++)
			list += it->first + "\n";

		getBot().getApi().sendMessage(message->chat->id, list);
	}

	if (message->text == "novo estique" && !estiquesStarted && estiquesStep == 0)
	{
		estiquesStarted = true;
		estiquesStep = 1;
		idWhoStarted = message->from->id;
		idWhere = message->chat->id;

		getBot().getApi().sendMessage(message->chat->id, "ok esto esperadon qual o estiquers em");
	}

	else if (message->text == "cancela" && message->from->id == idWhoStarted && message->chat->id == idWhere && estiquesStep > 0)
	{
		estiquesStarted = false;
		estiquesStep = 0;
		idWhoStarted = 0;
		idWhere = 0;

		getBot().getApi().sendMessage(message->chat->id, "pora eu achava q ia fase 1 estique bem amssinha pro xet assimmas pelo visot fui decepsioanado?");
	}

	else if (message->from->id == idWhoStarted && message->chat->id == idWhere && estiquesStep == 1)
	{
		if (message->sticker)
		{
			estiqueID = message->sticker->fileId;
			getBot().getApi().sendMessage(message->chat->id, "KKK VEI Q ESTIEKES MASAAAAAAA KUAL O MODMCANDO????");
			estiquesStep = 2;
		}
		else if (message->document && message->document->mimeType == "video/mp4")
		{
			estiqueID = message->document->fileId;
			getBot().getApi().sendMessage(message->chat->id, "KKK VEI Q GUIF MASAAAAAAA KUAL O MODMCANDO????");
			estiquesStep = 2;
		}
		else
		{
			getBot().getApi().sendMessage(message->chat->id, "ow vei q pora e essa iso nem e sticke vai se fode!!! camselei a criasao cusao");
			estiquesStep = 0;
			estiquesStarted = false;
			idWhoStarted = 0;
		}
	}

	else if (message->from->id == idWhoStarted && message->chat->id == idWhere && estiquesStep == 2)
	{
		estiqueTrigger = message->text;
		idWhoStarted = 0;
		idWhere = 0;
		estiquesStep = 0;
		estiquesStarted = false;

		// Kinda ugly, but prevents most common exploits.
		if (boost::starts_with(message->text, "!") ||
			boost::starts_with(message->text, "/") ||
			boost::starts_with(message->text, "@") ||
			boost::starts_with(message->text, "BQ") ||
			message->text.find('|') != std::string::npos ||
			message->text == "novo estique" ||
			message->text == "estiques" ||
			message->text == "stats" ||
			message->text == "")
			getBot().getApi().sendMessage(message->chat->id, "pora assim nao da ne vc axa q so buro?/");
		else
		{
			getBot().getApi().sendMessage(message->chat->id, "kkkk q comado loco lol \"" + estiqueTrigger + "\" kkkkkkkkk aiai");
			kv_Estiques[estiqueTrigger] = estiqueID;
			mapToFile("rs.txt", kv_Estiques);
			printf("Estique com comando %s criado usando fileID %s", estiqueTrigger.c_str(), estiqueID.c_str());
			estiqueTrigger = "";
		}
	}
}
