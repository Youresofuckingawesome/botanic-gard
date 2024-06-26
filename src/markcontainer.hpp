#pragma once

#include <mark.hpp>
#include <imgui.h>

#include <vector>

namespace MyGui {
	
	class MarkContainer
	{	
	public:
		MarkContainer() = default;
		
		void Add(ImVec2 pos);
		void Add(Mark& m);
		void Add(Mark& m, ImVec2 pos);
		void Add(std::string label, ImVec2 pos, std::string name, std::string filename, std::vector<MyGui::Info> vec_info);

		bool Any(Mark* mark = nullptr);

		void ForAll(std::function<void(Mark&)> fn);
		
		inline void Clear() { m_marks.clear(); }
		
		inline size_t GetSize() { return m_marks.size(); }

		// ELEMENT DESTROY SORRY FOR A LITTLE BIT AN UNINTUITIVE BULLSHIT BUT IT IS WHAT IT IS
		inline void operator()(int i) { m_marks.erase(m_marks.begin() + i); m_deletes++; }
		inline Mark& operator[](int i) { return m_marks[i]; }

		// INCAPSULATION VIOLATION
		inline std::vector<Mark>& GetVector() { return m_marks; }
		
	private:
		int m_deletes = 0;
		
		std::vector<Mark> m_marks;
    };

}
