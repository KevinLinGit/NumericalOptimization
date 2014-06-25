#include "Vector.h"

namespace no { namespace mf {
Vector::Vector(const std::size_t& n)
    : n_(n)
    , v_(NULL)
{
    v_ = new std::vector<double>(n_);
}

Vector::Vector(const Vector& other)
    : n_(other.n_)
    , v_(NULL)
{
    v_ = new std::vector<double>(*(other.v_));
}

Vector::~Vector()
{
    if (NULL != v_)
    {
        delete v_;
        v_ = NULL;
    }
}

const double& Vector::get(const std::size_t& i) const
{
    return (*v_)[i];
}

double& Vector::get(const std::size_t& i)
{
    return (*v_)[i];
}

void Vector::set(const std::size_t& i, const double& val)
{
    (*v_)[i] = val;
}
} }
