#include "../Headers/Audio.h"

Audio::Audio() {
	// TODO Auto-generated constructor stub

}

Audio::~Audio() {
	// TODO Auto-generated destructor stub
}
bool Audio::loadMusic()
{
	music.openFromFile("Sounds/music.ogg");
	music.setLoop(true);
	return true;
}
void Audio::playMusic()
{
	music.play();
}

