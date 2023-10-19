#pragma once

namespace MAAT
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define MAAT_KEY_SPACE           ::MAAT::Key::Space
#define MAAT_KEY_APOSTROPHE      ::MAAT::Key::Apostrophe    /* ' */
#define MAAT_KEY_COMMA           ::MAAT::Key::Comma         /* , */
#define MAAT_KEY_MINUS           ::MAAT::Key::Minus         /* - */
#define MAAT_KEY_PERIOD          ::MAAT::Key::Period        /* . */
#define MAAT_KEY_SLASH           ::MAAT::Key::Slash         /* / */
#define MAAT_KEY_0               ::MAAT::Key::D0
#define MAAT_KEY_1               ::MAAT::Key::D1
#define MAAT_KEY_2               ::MAAT::Key::D2
#define MAAT_KEY_3               ::MAAT::Key::D3
#define MAAT_KEY_4               ::MAAT::Key::D4
#define MAAT_KEY_5               ::MAAT::Key::D5
#define MAAT_KEY_6               ::MAAT::Key::D6
#define MAAT_KEY_7               ::MAAT::Key::D7
#define MAAT_KEY_8               ::MAAT::Key::D8
#define MAAT_KEY_9               ::MAAT::Key::D9
#define MAAT_KEY_SEMICOLON       ::MAAT::Key::Semicolon     /* ; */
#define MAAT_KEY_EQUAL           ::MAAT::Key::Equal         /* = */
#define MAAT_KEY_A               ::MAAT::Key::A
#define MAAT_KEY_B               ::MAAT::Key::B
#define MAAT_KEY_C               ::MAAT::Key::C
#define MAAT_KEY_D               ::MAAT::Key::D
#define MAAT_KEY_E               ::MAAT::Key::E
#define MAAT_KEY_F               ::MAAT::Key::F
#define MAAT_KEY_G               ::MAAT::Key::G
#define MAAT_KEY_H               ::MAAT::Key::H
#define MAAT_KEY_I               ::MAAT::Key::I
#define MAAT_KEY_J               ::MAAT::Key::J
#define MAAT_KEY_K               ::MAAT::Key::K
#define MAAT_KEY_L               ::MAAT::Key::L
#define MAAT_KEY_M               ::MAAT::Key::M
#define MAAT_KEY_N               ::MAAT::Key::N
#define MAAT_KEY_O               ::MAAT::Key::O
#define MAAT_KEY_P               ::MAAT::Key::P
#define MAAT_KEY_Q               ::MAAT::Key::Q
#define MAAT_KEY_R               ::MAAT::Key::R
#define MAAT_KEY_S               ::MAAT::Key::S
#define MAAT_KEY_T               ::MAAT::Key::T
#define MAAT_KEY_U               ::MAAT::Key::U
#define MAAT_KEY_V               ::MAAT::Key::V
#define MAAT_KEY_W               ::MAAT::Key::W
#define MAAT_KEY_X               ::MAAT::Key::X
#define MAAT_KEY_Y               ::MAAT::Key::Y
#define MAAT_KEY_Z               ::MAAT::Key::Z
#define MAAT_KEY_LEFT_BRACKET    ::MAAT::Key::LeftBracket   /* [ */
#define MAAT_KEY_BACKSLASH       ::MAAT::Key::Backslash     /* \ */
#define MAAT_KEY_RIGHT_BRACKET   ::MAAT::Key::RightBracket  /* ] */
#define MAAT_KEY_GRAVE_ACCENT    ::MAAT::Key::GraveAccent   /* ` */
#define MAAT_KEY_WORLD_1         ::MAAT::Key::World1        /* non-US #1 */
#define MAAT_KEY_WORLD_2         ::MAAT::Key::World2        /* non-US #2 */

/* Function keys */
#define MAAT_KEY_ESCAPE          ::MAAT::Key::Escape
#define MAAT_KEY_ENTER           ::MAAT::Key::Enter
#define MAAT_KEY_TAB             ::MAAT::Key::Tab
#define MAAT_KEY_BACKSPACE       ::MAAT::Key::Backspace
#define MAAT_KEY_INSERT          ::MAAT::Key::Insert
#define MAAT_KEY_DELETE          ::MAAT::Key::Delete
#define MAAT_KEY_RIGHT           ::MAAT::Key::Right
#define MAAT_KEY_LEFT            ::MAAT::Key::Left
#define MAAT_KEY_DOWN            ::MAAT::Key::Down
#define MAAT_KEY_UP              ::MAAT::Key::Up
#define MAAT_KEY_PAGE_UP         ::MAAT::Key::PageUp
#define MAAT_KEY_PAGE_DOWN       ::MAAT::Key::PageDown
#define MAAT_KEY_HOME            ::MAAT::Key::Home
#define MAAT_KEY_END             ::MAAT::Key::End
#define MAAT_KEY_CAPS_LOCK       ::MAAT::Key::CapsLock
#define MAAT_KEY_SCROLL_LOCK     ::MAAT::Key::ScrollLock
#define MAAT_KEY_NUM_LOCK        ::MAAT::Key::NumLock
#define MAAT_KEY_PRINT_SCREEN    ::MAAT::Key::PrintScreen
#define MAAT_KEY_PAUSE           ::MAAT::Key::Pause
#define MAAT_KEY_F1              ::MAAT::Key::F1
#define MAAT_KEY_F2              ::MAAT::Key::F2
#define MAAT_KEY_F3              ::MAAT::Key::F3
#define MAAT_KEY_F4              ::MAAT::Key::F4
#define MAAT_KEY_F5              ::MAAT::Key::F5
#define MAAT_KEY_F6              ::MAAT::Key::F6
#define MAAT_KEY_F7              ::MAAT::Key::F7
#define MAAT_KEY_F8              ::MAAT::Key::F8
#define MAAT_KEY_F9              ::MAAT::Key::F9
#define MAAT_KEY_F10             ::MAAT::Key::F10
#define MAAT_KEY_F11             ::MAAT::Key::F11
#define MAAT_KEY_F12             ::MAAT::Key::F12
#define MAAT_KEY_F13             ::MAAT::Key::F13
#define MAAT_KEY_F14             ::MAAT::Key::F14
#define MAAT_KEY_F15             ::MAAT::Key::F15
#define MAAT_KEY_F16             ::MAAT::Key::F16
#define MAAT_KEY_F17             ::MAAT::Key::F17
#define MAAT_KEY_F18             ::MAAT::Key::F18
#define MAAT_KEY_F19             ::MAAT::Key::F19
#define MAAT_KEY_F20             ::MAAT::Key::F20
#define MAAT_KEY_F21             ::MAAT::Key::F21
#define MAAT_KEY_F22             ::MAAT::Key::F22
#define MAAT_KEY_F23             ::MAAT::Key::F23
#define MAAT_KEY_F24             ::MAAT::Key::F24
#define MAAT_KEY_F25             ::MAAT::Key::F25

/* Keypad */
#define MAAT_KEY_KP_0            ::MAAT::Key::KP0
#define MAAT_KEY_KP_1            ::MAAT::Key::KP1
#define MAAT_KEY_KP_2            ::MAAT::Key::KP2
#define MAAT_KEY_KP_3            ::MAAT::Key::KP3
#define MAAT_KEY_KP_4            ::MAAT::Key::KP4
#define MAAT_KEY_KP_5            ::MAAT::Key::KP5
#define MAAT_KEY_KP_6            ::MAAT::Key::KP6
#define MAAT_KEY_KP_7            ::MAAT::Key::KP7
#define MAAT_KEY_KP_8            ::MAAT::Key::KP8
#define MAAT_KEY_KP_9            ::MAAT::Key::KP9
#define MAAT_KEY_KP_DECIMAL      ::MAAT::Key::KPDecimal
#define MAAT_KEY_KP_DIVIDE       ::MAAT::Key::KPDivide
#define MAAT_KEY_KP_MULTIPLY     ::MAAT::Key::KPMultiply
#define MAAT_KEY_KP_SUBTRACT     ::MAAT::Key::KPSubtract
#define MAAT_KEY_KP_ADD          ::MAAT::Key::KPAdd
#define MAAT_KEY_KP_ENTER        ::MAAT::Key::KPEnter
#define MAAT_KEY_KP_EQUAL        ::MAAT::Key::KPEqual

#define MAAT_KEY_LEFT_SHIFT      ::MAAT::Key::LeftShift
#define MAAT_KEY_LEFT_CONTROL    ::MAAT::Key::LeftControl
#define MAAT_KEY_LEFT_ALT        ::MAAT::Key::LeftAlt
#define MAAT_KEY_LEFT_SUPER      ::MAAT::Key::LeftSuper
#define MAAT_KEY_RIGHT_SHIFT     ::MAAT::Key::RightShift
#define MAAT_KEY_RIGHT_CONTROL   ::MAAT::Key::RightControl
#define MAAT_KEY_RIGHT_ALT       ::MAAT::Key::RightAlt
#define MAAT_KEY_RIGHT_SUPER     ::MAAT::Key::RightSuper
#define MAAT_KEY_MENU            ::MAAT::Key::Menu
