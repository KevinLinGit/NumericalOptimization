#include "LUResolver.h"
#include "Matrix.h"
#include "Vector.h"

namespace no { namespace mf {

void LUResolver::resolve(Matrix* A, Matrix* L, Matrix* U)
{
    const std::size_t nrows = A->numRows();
    const std::size_t ncols = A->numRows();
    Matrix* P = new Matrix(nrows, ncols);
    // initialize
    for (std::size_t i = 0; i < nrows; ++i)
    {
        Vector& lvec = L->viewRow(i);
        lvec.assign(0.0);
        Vector& pvec = P->viewRow(i);
        pvec.assign(0.0);
        pvec.set(i, 1.0);
    }

    for (std::size_t i = 0; i < nrows; ++i)
    {
        std::size_t maxK = 0;
        double maxV = 0.0;
        //find the index j ∈ {i, i + 1, . . . , n} such that |A ji | max
        for (std::size_t k = i; k < nrows; ++k)
        {
            const double val = A->viewRow(k).get(i);
            if (val > maxV)
            {
                maxV= val;
                maxK = k;
            }
        }

        if (A->viewRow(i).get(maxK) < 1e-6)
        {
            break;
        }
        if (maxK != i)
        {
            // swap
            A->viewRow(i).swap(A->viewRow(maxK));
        }

        const double aii = A->viewRow(i).get(i);
        L->viewRow(i).set(i, 1.0);
        for (std::size_t k = i + 1; k < nrows; ++k)
        {
            const double aki = A->viewRow(k).get(i);
            double lki = aki / aii;

            L->viewRow(k).set(i, lki);
            for (std::size_t l = i + 1; l < nrows; ++l)
            {
                A->viewRow(k).get(l) -= lki * A->viewRow(i).get(l);
            }
        }
    }
    // U ← upper triangular part of A.
    for (std::size_t i = 0; i < nrows; ++i)
    {
        Vector& uvec = U->viewRow(i);
        uvec.assign(0.0);
        Vector& avec = A->viewRow(i);
        for (std::size_t k = i; k < ncols; ++k)
        {
            uvec.set(k, avec.get(k));
        }
    }
    delete P;
}
} }
