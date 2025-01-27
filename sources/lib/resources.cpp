#include "resources.hpp"
#include "windef.hpp"
#include <iostream>

ResourceManger::ResourceManger()
{
	if (!m_Font.openFromFile(FONT_PATH))
	{
		std::cerr << "Failed to Open the Font" << std::endl;
	}
}
