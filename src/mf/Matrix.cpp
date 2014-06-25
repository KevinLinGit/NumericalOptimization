#include "Matrix.h"
#include "Vector.h"
namespace no { namespace mf {
Matrix::Matrix(const std::size_t& row, const std::size_t& col)
    : nrow_(row)
    , ncol_(col)
    , data_(NULL)
{
    Vector vec(ncol_);
    data_ = new std::vector<Vector>(nrow_, vec);
}

Matrix::~Matrix()
{
    if (NULL != data_)
    {
        delete data_;
        data_ = NULL;
    }
}
} }
