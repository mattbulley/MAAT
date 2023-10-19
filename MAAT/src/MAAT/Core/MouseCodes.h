#pragma once

namespace MAAT
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define MAAT_MOUSE_BUTTON_0      ::MAAT::Mouse::Button0
#define MAAT_MOUSE_BUTTON_1      ::MAAT::Mouse::Button1
#define MAAT_MOUSE_BUTTON_2      ::MAAT::Mouse::Button2
#define MAAT_MOUSE_BUTTON_3      ::MAAT::Mouse::Button3
#define MAAT_MOUSE_BUTTON_4      ::MAAT::Mouse::Button4
#define MAAT_MOUSE_BUTTON_5      ::MAAT::Mouse::Button5
#define MAAT_MOUSE_BUTTON_6      ::MAAT::Mouse::Button6
#define MAAT_MOUSE_BUTTON_7      ::MAAT::Mouse::Button7
#define MAAT_MOUSE_BUTTON_LAST   ::MAAT::Mouse::ButtonLast
#define MAAT_MOUSE_BUTTON_LEFT   ::MAAT::Mouse::ButtonLeft
#define MAAT_MOUSE_BUTTON_RIGHT  ::MAAT::Mouse::ButtonRight
#define MAAT_MOUSE_BUTTON_MIDDLE ::MAAT::Mouse::ButtonMiddle
