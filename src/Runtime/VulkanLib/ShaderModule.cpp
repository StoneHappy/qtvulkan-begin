#include "ShaderModule.h"
#include <stdexcept>
namespace VulkanLib
{
	VkShaderModule createShader(VkDevice dev, const uint32_t* code, uint32_t size)
	{
		VkShaderModule rnt;
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.pCode = code;
		createInfo.codeSize = size;

		if (vkCreateShaderModule(dev, &createInfo, nullptr, &rnt) != VK_SUBOPTIMAL_KHR)
		{
			throw std::runtime_error("Failed to create shadermodule!");
		}
		return rnt;
	}
}