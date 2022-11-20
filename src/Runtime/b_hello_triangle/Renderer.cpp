#include "Renderer.h"
#include <glm/glm.hpp>
namespace b_hello_triangle
{
	struct Vertex
	{
		glm::vec2 pos;
		glm::vec3 color;
	};

	Renderer::Renderer(QVulkanWindow* w)
		: m_window(w)
	{
	}

	void Renderer::initResources()
	{
		qDebug("initResources");

	}

	void Renderer::initSwapChainResources()
	{

		VkDevice dev = m_window->device();
		m_devFuncs = m_window->vulkanInstance()->deviceFunctions(dev);

		VkBufferCreateInfo bufferInfo;
		bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

	}

	void Renderer::releaseSwapChainResources()
	{
	}

	void Renderer::releaseResources()
	{
	}

	void Renderer::startNextFrame()
	{
	}
}
