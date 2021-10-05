#pragma once

#include<array>
#include<stdexcept>
#include<string>
#include<vector>

#include "VectorN.h"

template<typename TField, size_t TRows, size_t TColumns>
class MatrixN
{
public:
	MatrixN(std::vector<std::vector<TField>> mat)
	{
		if (mat.size() != TRows)
		{
			std::string message = "RowCount must be " + std::to_string(TRows) +
				"But was: " + std::to_string(mat.size());
			throw std::invalid_argument(message);
		}

		for (size_t i = 0; i < TRows; i++)
		{
			if (mat[i].size() != TColumns)
			{
				std::string message = "Error on Rowindex: " + std::to_string(i) +
					"ColumnCount must be " + std::to_string(TColumns) +
					"But was: " + std::to_string(mat[i].size());

				throw std::invalid_argument(message);
			}
		}

		for (size_t i = 0; i < TRows; i++)
			for (size_t j = 0; j < TColumns; j++)
				matrix[i][j] = mat[i][j];
	}

	VectorN<TField, TColumns> operator*(VectorN<TField, TColumns> other) const
	{
		std::array<TField, TColumns> dotProducts;

		for (size_t i = 0; i < TRows; i++)
		{
			TField dotProduct{};

			for (size_t j = 0; j < TColumns; j++)
				dotProduct += matrix[i][j] * other[j];

			dotProducts[i] = dotProduct;
		}

		return VectorN<TField, TColumns>(dotProducts);
	}

	template<int TOtherColumns>
	MatrixN<TField, TRows, TOtherColumns> operator*(MatrixN<TField, TColumns, TOtherColumns> other)
	{
		std::vector<std::vector<TField>> temp;

		for (size_t i = 0; i < TRows; i++)
		{
			temp.push_back(std::vector<TField>());

			for (size_t j = 0; j < TOtherColumns; j++)
			{
				TField dotProduct{};

				for (size_t k = 0; k < TColumns; k++)
					dotProduct += matrix[i][k] * other.matrix[k][j];

				temp[i].push_back(dotProduct);
			}
		}

		return MatrixN<TField, TRows, TOtherColumns>(temp);
	}

private:
	TField matrix[TRows][TColumns];
};

