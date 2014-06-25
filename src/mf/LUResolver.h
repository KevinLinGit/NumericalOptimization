#ifndef NO_MF_LU_RESOLVER_H
#define NO_MF_LU_RESOLVER_H
namespace no { namespace mf {
class Matrix;
class LUResolver
{
public:
    void resolve(Matrix* A, Matrix* L, Matrix* U);
};
} }
#endif
