#include "bot_reloaded.h"

// Exiting nicely.
void sigintHandler(int param)
{
	std::cout << std::endl << "Leaving..." << std::endl;
	exit(1);
}

int main()
{
	signal(SIGINT, sigintHandler);

	// New instance
	TgBot::Bot bot = getBot();

	// Listener to all messages
	bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message)
	{
		// Get current POSIX
		std::time_t t = std::time(0);

		// Prevents cross-interaction and old messages.
		if (message->from->id != 82017295 && t - message->date < 10) 
		{
			/* ///// I could call onAnyMessage from each file, but it is easier to manage from here. ///// */

			// Global checks
			checkForAudio(message);
			checkForEstique(message);

			if (message->text == "vc esta ai")
				getBot().getApi().sendMessage(message->chat->id, "TO AQUI PORA");


		}
		else
			std::cout << "Too old!" << std::endl;

		printf("%s\n", message->text.c_str());

	});

	try
	{
		TgBot::TgLongPoll longPoll(bot);
		while (true)
		{
			printf("Long poll\n");
			longPoll.start();
		}
	}
	catch (TgBot::TgException& e)
	{
		printf("DEU POBREMA EM... %s\n", e.what());
	}
	return 0;
}
