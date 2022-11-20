#include "Renderer.h"
#include <glm/glm.hpp>
#include <array>
#include <cstddef>
namespace b_hello_triangle
{
	struct Vertex
	{
		glm::vec2 pos;
		glm::vec3 color;

		static VkVertexInputBindingDescription getBindingDescription();
		static std::array<VkVertexInputAttributeDescription, 2> getAttributeDescriptions();
	};

	Renderer::Renderer(QVulkanWindow* w)
		: m_window(w)
	{
	}

	void Renderer::initResources()
	{
		qDebug("initResources");
		VkDevice dev = m_window->device();
		m_devFuncs = m_window->vulkanInstance()->deviceFunctions(dev);

		VkBufferCreateInfo bufferInfo;
		bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;


	}

	void Renderer::initSwapChainResources()
	{

		

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
	VkVertexInputBindingDescription Vertex::getBindingDescription()
	{
		VkVertexInputBindingDescription bindingDescription{};
		bindingDescription.binding = 0;
		bindingDescription.stride = sizeof(Vertex);
		bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
	}
	std::array<VkVertexInputAttributeDescription, 2> Vertex::getAttributeDescriptions()
	{
		std::array<VkVertexInputAttributeDescription, 2> attributeDescriptions{};
		attributeDescriptions[0].binding = 0;
		attributeDescriptions[0].location = 0;
		attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
		attributeDescriptions[0].offset = offsetof(Vertex, pos);

		attributeDescriptions[1].binding = 0;
		attributeDescriptions[1].location = 1;
		attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[1].offset = offsetof(Vertex, color);
	}
}
