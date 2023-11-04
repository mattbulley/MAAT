#include "mtpch.h"
#include "ContentBrowserPanel.h"

#include <imgui/imgui.h>

#include <filesystem>

namespace MAAT {

	// Once we have projects, change this
	extern const std::filesystem::path g_AssetPath = "assets";

	ContentBrowserPanel::ContentBrowserPanel()
		: m_CurrentDirectory(g_AssetPath)
	{
		m_DirectoryIcon = Texture2D::Create("Resources/Icons/ContentBrowser/DirectoryIcon3.png");
		m_FileIcon = Texture2D::Create("Resources/Icons/ContentBrowser/FileIcon2.png");
		m_DiscIcon1 = Texture2D::Create("Resources/Icons/ContentBrowser/DiscIcon1.png");
		m_DiscIcon2 = Texture2D::Create("Resources/Icons/ContentBrowser/DiscIcon2.png");
		m_DiscIcon3 = Texture2D::Create("Resources/Icons/ContentBrowser/DiscIcon3.png");
		m_FontIcon = Texture2D::Create("Resources/Icons/ContentBrowser/FontIcon.png");
		m_SceneIcon = Texture2D::Create("Resources/Icons/ContentBrowser/SceneIcon.png");
	}

	void ContentBrowserPanel::OnImGuiRender()
	{
		ImGui::Begin("Content Browser");

		if (m_CurrentDirectory != std::filesystem::path(g_AssetPath))
		{
			if (ImGui::Button("<-"))
			{
				m_CurrentDirectory = m_CurrentDirectory.parent_path();
			}
		}

		static float padding = 16.0f;
		static float thumbnailSize = 100.0f;
		float cellSize = thumbnailSize + padding;

		float panelWidth = ImGui::GetContentRegionAvail().x;
		int columnCount = (int)(panelWidth / cellSize);
		if (columnCount < 1)
			columnCount = 1;

		ImGui::Columns(columnCount, 0, false);

		int i = 0;

		for (auto& directoryEntry : std::filesystem::directory_iterator(m_CurrentDirectory))
		{
			const auto& path = directoryEntry.path();
			auto relativePath = std::filesystem::relative(path, g_AssetPath);
			std::string filenameString = relativePath.filename().string();

			ImGui::PushID(filenameString.c_str());
			Ref<Texture2D> icon = 0;

			std::string fileExtension = path.string().substr(path.string().find_last_of(".") + 1);

			if (fileExtension == "png" || fileExtension == "PNG")
				icon = m_DiscIcon1;
			else if (fileExtension == "glsl")
				icon = m_DiscIcon3;
			else if (fileExtension == "spv")
				icon = m_DiscIcon2;
			else if (fileExtension == "ttf")
				icon = m_FontIcon;
			else if (fileExtension == "maat")
				icon = m_SceneIcon;
			else
				icon = directoryEntry.is_directory() ? m_DirectoryIcon : m_FileIcon;

			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
			ImGui::ImageButton((ImTextureID)icon->GetRendererID(), { thumbnailSize, thumbnailSize }, { 0, 1 }, { 1, 0 });

			if (ImGui::BeginDragDropSource())
			{
				const wchar_t* itemPath = relativePath.c_str();
				ImGui::SetDragDropPayload("CONTENT_BROWSER_ITEM", itemPath, (wcslen(itemPath) + 1) * sizeof(wchar_t), ImGuiCond_Once);
				ImGui::EndDragDropSource();
			}

			ImGui::PopStyleColor();
			if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
			{
				if (directoryEntry.is_directory())
					m_CurrentDirectory /= path.filename();
			}
			ImGui::Button(filenameString.c_str());

			ImGui::NextColumn();
			
			ImGui::PopID();
		}

		ImGui::Columns(1);

		//ImGui::SliderFloat("Thumbnail Size", &thumbnailSize, 16, 512);
		//ImGui::SliderFloat("Padding", &padding, 0, 32);

		// TODO: status bar
		ImGui::End();
	}
}