#include <SFML/Graphics.hpp>
using namespace sf;

class Background : public Drawable,Transformable{
public:
	Background(int = 0);
	virtual ~Background();
	virtual void draw(RenderTarget &target, RenderStates states)const;
private:
	Sprite sprite;
	Texture texture;
};

