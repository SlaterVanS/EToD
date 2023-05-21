#pragma once

#include "ETOD.h"
#include "ETOD/Renderer/Texture.h"

#include <filesystem>

namespace ETOD {
	
	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();

		void OnImGuiRender();
	private:
		std::filesystem::path m_BaseDirectory;
		std::filesystem::path m_CurrentDirectory;

		Ref<Texture2D> m_DirectoryIcon;
		Ref<Texture2D> m_FileIcon;
		std::unordered_map<std::string, Ref<Texture2D>> m_TextureIcons;

		ImGuiLayer languageCheck;
	};

}