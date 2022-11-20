#pragma once

#include <QVulkanWindowRenderer>


namespace b_hello_triangle
{
	class Renderer : public QVulkanWindowRenderer
	{
	public:
		Renderer(QVulkanWindow* w);

		void initResources() override;
		void initSwapChainResources() override;
		void releaseSwapChainResources() override;
		void releaseResources() override;

		void startNextFrame() override;

	private:
		QVulkanWindow* m_window;
		QVulkanDeviceFunctions* m_devFuncs;
	};
}
