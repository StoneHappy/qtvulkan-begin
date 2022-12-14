#pragma once
#include <QApplication>
#include "a_hello_vulkan/VulkanWindow.h"
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(lcVk, "qt.vulkan")

namespace qtvulkanbegin
{
	namespace a_hello_vulkan
	{
		int main(int argc, char** argv)
		{
			QApplication app(argc, argv);

			QLoggingCategory::setFilterRules(QStringLiteral("qt.vulkan=true"));

			QVulkanInstance inst;

			inst.setLayers(QByteArrayList()
				<< "VK_LAYER_GOOGLE_threading"
				<< "VK_LAYER_LUNARG_parameter_validation"
				<< "VK_LAYER_LUNARG_object_tracker"
				<< "VK_LAYER_LUNARG_core_validation"
				<< "VK_LAYER_LUNARG_image"
				<< "VK_LAYER_LUNARG_swapchain"
				<< "VK_LAYER_GOOGLE_unique_objects");

			if (!inst.create())
				qFatal("Failed to create Vulkan instance: %d", inst.errorCode());

			VulkanWindow w;

			w.setVulkanInstance(&inst);
			w.resize(1024, 768);
			w.show();

			return app.exec();
		}
	}
}