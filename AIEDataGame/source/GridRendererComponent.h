#pragma once
#include "RendererComponent.h"
#include "GridColliderComponent.h"

//type for the actual 2D grid to render
enum TileType
{
	SKIP = 0,
	RED = 1,
	BLUE = 2,
	PURPLE = 3,
	GREEN = 4,
	YELLOW = 5,
	MARONE = 6,
};

//typedef for 2D array of tile type
typedef TileType** tileMap;

const float uvEpsilon = 0.02f;

/*
* class GridRendererComponent
* child class of BaseComponent
*
* a component that holds a position
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class GridRendererComponent : public BaseComponent
{
public:

	LinkedNode<GridRendererComponent*>* thisNode = nullptr; //position in the renderers array in playState

	TextureResource* atlasRes = nullptr; //the texture that the renderer will use regions of
	AABB singularRegion = AABB(); //the region that encapsulates one of the textures
	AABB renderRegion = AABB(); //the region that one square will be drawn to

	//dimensions of the 2D array
	int sizeY = 0;
	int sizeX = 0;

	tileMap data; //2D array of data

	TextFileResource* textRes; //pointer to the 2D array data from the text file

	/*
	* GridRendererComponent()
	* default constructor
	*/
	GridRendererComponent() {};

	/*
	* ~GridRendererComponent()
	* virtual function
	* default destructor
	*/
	virtual ~GridRendererComponent() {};

	/*
	* initialise
	* overrides BaseComponent's initialise()
	*
	* initialises the component, only gets called if component is attached to a gameobject
	*
	* @returns void
	*/
	void initialise() override;
	
	/*
	* load
	*
	* loads in the array data, setting up the grid
	* renderer for use rendering tiles in a game
	*
	* @returns void
	*/
	void load();

	/*
	* render
	*
	* draws the texture to the screen
	*
	* @param Application2D* appPtr - pointer to the application that will render it
	* @param Vector2 cameraOffset - offset from the origin to draw the texture from in addition to transforms
	* @returns void
	*/
	void render(Application2D* appPtr, Vector2 cameraOffset);

};