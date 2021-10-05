#pragma once

#include <array>
#include <stdexcept>
#include <string>

template<typename TField, std::size_t TComponents>
class VectorN
{
public:
	size_t size() const { return TComponents; };

	VectorN(std::array<TField, TComponents> components)
		: components(components)
	{
	}

	VectorN<TField, TComponents> operator+(const VectorN<TField, TComponents>& other) const {
		std::array<TField, TComponents> addedComponents;

		for (size_t i = 0; i < TComponents; i++)
			addedComponents[i] = components[i] + other.components[i];

		return VectorN<TField, TComponents>(addedComponents);
	};

	TField operator*(const VectorN<TField, TComponents>& other) const
	{
		TField dotProduct{};

		for (size_t i = 0; i < TComponents; i++)
			dotProduct += components[i] * other.components[i];

		return dotProduct;
	}

	friend VectorN<TField, TComponents> operator*(const TField& value, VectorN<TField, TComponents>& target) {
		std::array<TField, TComponents> multipliedComponents;

		for (size_t i = 0; i < TComponents; i++)
			multipliedComponents[i] = target[i] * value;

		return VectorN<TField, TComponents>(multipliedComponents);
	};

	friend std::ostream& operator<<(std::ostream& stream, VectorN<TField, TComponents> vector) {
		stream << "v = (";

		for (std::size_t i = 0; i < vector.size(); ++i)
		{
			if (i == vector.size() - 1)
				stream << vector[i] << ")";
			else
				stream << vector[i] << ", ";
		}

		return stream;
	}

	TField& operator[](int i) 
	{
		if (i < 0)
			throw std::invalid_argument("index must be largert than -1");

		if (i > size() - 1)
		{
			std::string message = "index must be smaller than " + std::to_string(size() - 1);
			throw std::invalid_argument(message);
		}

		return components[i];
	}

private:
	std::array<TField, TComponents> components;
};

