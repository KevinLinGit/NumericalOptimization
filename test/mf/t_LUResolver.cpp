#include <unistd.h>
#include <mf/LUResolver.h>
#include <iostream>
#include <mf/Matrix.h>
#include <mf/Vector.h>

using namespace no::mf;

int main(int argc, char** argv)
{
    const std::size_t nrows = 2;
    const std::size_t ncols = 2;
    Matrix* A = new Matrix(nrows, ncols);
    A->viewRow(0).set(0, 4);
    A->viewRow(0).set(1, 3);
    A->viewRow(1).set(0, 6);
    A->viewRow(1).set(0, 3);
    Matrix* L = new Matrix(nrows, ncols);
    Matrix* U = new Matrix(nrows, ncols);

    LUResolver* resolver = new LUResolver();
    resolver->resolve(A, L, U);
    std::cout<<"L:\n";
    for (std::size_t row = 0; row < nrows; ++row)
    {
        const Vector& vec = L->viewRow(row);
        for (std::size_t col = 0; col < ncols; ++col)
        {
            std::cout<<vec.get(col)<<"\t";
        }
        std::cout<<"\n";
    }
    
    std::cout<<"U:\n";
    for (std::size_t row = 0; row < nrows; ++row)
    {
        const Vector& vec = U->viewRow(row);
        for (std::size_t col = 0; col < ncols; ++col)
        {
            std::cout<<vec.get(col)<<"\t";
        }
        std::cout<<"\n";
    }
}
