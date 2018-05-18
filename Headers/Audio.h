#include <SFML/Audio.hpp>
#include <string>

#ifndef HEADERS_AUDIO_H_
#define HEADERS_AUDIO_H_
using namespace sf;
using namespace std;

class Audio {
public:
	Audio();
	virtual ~Audio();
	bool loadMusic();
	bool loadSound();
	void playMusic();
	void stopMusic();
	void playSound();

private:
	Music music;
	Sound sound;
};
#endif  /*HEADERS_AUDIO_H_*/
