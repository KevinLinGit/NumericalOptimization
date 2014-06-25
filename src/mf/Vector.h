#ifndef NO_MF_VECTOR_H
#define NO_MF_VECTOR_H
#include <vector>
#include <assert.h>
namespace no { namespace mf {
class Vector
{
public:
    typedef std::vector<double>::const_iterator const_iterator;
    typedef std::vector<double>::iterator iterator;
public:
    Vector(const std::size_t& n);
    Vector(const Vector& other);
    ~Vector();

public:
    const double& get(const std::size_t& i) const;
    double& get(const std::size_t& i);

    void set(const std::size_t& i, const double& val);

    const_iterator begin() const
    {
        return v_->begin();
    }

    const_iterator end() const
    {
        return v_->end();
    }
    
    iterator begin()
    {
        return v_->begin();
    }
    
    iterator end()
    {
        return v_->end();
    }

    const std::size_t dimension() const
    {
        return n_;
    }

    void assign(const double& val)
    {
        v_->assign(n_, val);
    }

    void swap(Vector& other)
    {
        assert(n_ == other.n_);
        v_->swap(*(other.v_));
    }
private:
    const std::size_t n_;
    std::vector<double>* v_;
};
} }
#endif
