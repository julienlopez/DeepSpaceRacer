#pragma once

#include <array>

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
    std::enable_if_t<NbRows == 1 || NbColumns == 1, const T&> operator()(const Index index) const
    {
        return m_values[index];
    }

    template <class U>
    friend bool operator==(const Matrix<T, NbRows, NbColumns>& m1, const Matrix<U, NbRows, NbColumns>& m2) noexcept
    {
        return std::equal(begin(m1.m_values), end(m1.m_values), begin(m2.m_values));
    }

private:
    Storage_t m_values;
};

} // namespace LinearAlgebra
