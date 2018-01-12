#include "Camera.h"

sf::View Camera::getView()
{
	return view;
}

void Camera::cameraZoom(sf::Event event)
{
	if (event.type == sf::Event::MouseWheelMoved)
	{
		if (event.mouseWheel.delta < 0)
			view.zoom(1.1f);
		else if (event.mouseWheel.delta > 0)
			view.zoom(0.95f);
	}
}

void Camera::followPlayerSmooth(sf::Vector2f entityPos, float deltaTime)
{
	camera.x += (entityPos.x - view.getCenter().x) * deltaTime * (float)10;      //smooth camera follow
	camera.y += (entityPos.y-200 - view.getCenter().y) * deltaTime * (float)1;      //smooth camera follow
	view.setCenter(camera);
}
