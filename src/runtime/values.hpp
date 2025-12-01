// Header File for the Runtime Values

#ifndef VALUES_HPP
#define VALUES_HPP

#include <string>

namespace fling {
	namespace runtime {

		// Enum with Runtime Values
		enum class ValueType {
			Null,
			Number,
		};

		// A Value Struct for the Runtime
		struct RuntimeVal {
			ValueType type;

			int numberValue = 0;
			std::string stringValue;
		};

		// a Null struct for the Runtime
		struct NullVal : RuntimeVal {
			std::string value = "null";

			NullVal() : RuntimeVal(fling::runtime::ValueType::Null) {}
		};

		// a number struct for the Runtime
		struct NumberVal : RuntimeVal {
			int value;
			NumberVal(int v) : RuntimeVal(fling::runtime::ValueType::Number), value(v) {}
		};
	} // namespace runtime
} // namespace fling

#endif // VALUES_HPP
