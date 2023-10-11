#pragma once

#include <string>

namespace MAAT {

	class Shader
	{
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentsSrc);
		~Shader();

		void Bind() const;
		void Unbind() const;
	private:
		uint32_t m_RendererID;
	};
}