#pragma once

#include "MAAT/Renderer/Texture.h"

#include <filesystem>

namespace MAAT {

	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();

		void OnImGuiRender();
	private:
		std::filesystem::path m_CurrentDirectory;

		Ref<Texture2D> m_DirectoryIcon;
		Ref<Texture2D> m_FileIcon;
		Ref<Texture2D> m_DiscIcon1;
		Ref<Texture2D> m_DiscIcon2;
		Ref<Texture2D> m_DiscIcon3;
		Ref<Texture2D> m_FontIcon;
		Ref<Texture2D> m_SceneIcon;
	};
}