#ifndef NO_MF_MATRIX_H
#define NO_MF_MATRIX_H
#include <vector>

namespace no { namespace mf {
class Vector;

class Matrix
{
public:
    Matrix(const std::size_t& row, const std::size_t& col);
    ~Matrix();

public:
    const Vector& viewRow(const std::size_t& row) const
    {
        return (*data_)[row];
    }
    
    Vector& viewRow(const std::size_t& row)
    {
        return (*data_)[row];
    }

    const std::size_t numRows() const
    {
        return nrow_;
    }

    const std::size_t numCols() const
    {
        return ncol_;
    }
private:
    const std::size_t nrow_;
    const std::size_t ncol_;
    std::vector<Vector>* data_;
};
} }
#endif
