#include <SFML/Audio.hpp>
using namespace sf;

class Audio {
public:
	Audio();
	virtual ~Audio();
private:
	Music music;
	Sound sound;
};
