#pragma once

#include <vulkan/vulkan.h>

namespace VulkanLib
{
	VkShaderModule createShader(VkDevice dev, const uint32_t* code, uint32_t size);
}
