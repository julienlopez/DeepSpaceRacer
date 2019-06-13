#pragma once

#include <algorithm>
#include <array>

#include <numeric_range.hpp>

namespace LinearAlgebra
{

template <class T, std::size_t NbRows, std::size_t NbColumns> class Matrix
{
public:
    using Storage_t = std::array<T, NbRows * NbColumns>;
    using Index = std::size_t;

    Matrix(Storage_t values) noexcept
        : m_values(std::move(values))
    {
    }

    /**
     * @brief vector element access
     */
    std::enable_if_t<NbRows == 1 || NbColumns == 1, const T&> operator()(const Index index) const noexcept
    {
        return m_values[index];
    }

    // comparisson operators

    template <class U>
    friend bool operator==(const Matrix<T, NbRows, NbColumns>& m1, const Matrix<U, NbRows, NbColumns>& m2) noexcept
    {
        return std::equal(begin(m1.m_values), end(m1.m_values), begin(m2.m_values));
    }

    // arithmetics operators

    template <class U> Matrix& operator+=(const Matrix<U, NbRows, NbColumns>& m2) noexcept
    {
        for(const auto i : range(m_values.size()))
            m_values[i] += m2.m_values[i];
        return *this;
    }

    template <class U> friend auto operator*(const U& scalar, const Matrix& matrix) noexcept
    {
        using ResultType = Matrix<decltype(scalar * matrix.m_values.front()), NbRows, NbColumns>;
        typename ResultType::Storage_t res;
        std::transform(begin(matrix.m_values), end(matrix.m_values), begin(res),
                       [&scalar](const T& value) { return scalar * value; });
        return ResultType{res};
    }

private:
    Storage_t m_values;
};

} // namespace LinearAlgebra
