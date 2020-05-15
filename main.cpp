#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include "Eigen/Dense"
#include <fstream>

using namespace Eigen;

int main()
{
    std::vector<double> january = {51.2, 51.2, 39.5, 45.1, 29.9, 24.8, 32, 35.6, 54.6, 67.2, 42.4, 29, 22.9, 23.8, 27.9, 19.4, 31.3, 33.3, 52.9, 21.5, 33.4, 29.2, 25.5, 14.2, 8.5, 12.2, 47.1, 27.8, 31.3, 20.5, 22.6, 31.9, 20.6, 32.7, 35.2, 21.5, 23.7, 32.2, 42.1, 40.5, 8.2, 31.1, 26.9, 28.4, 36.8, 38.1, 32.3, 28.1, 28.4, 45.4, 14.2, 40.5, 38.3, 44.8, 43.6, 52.1, 28, 16.8, 40.5, 37.5, 25.4, 34.5, 19.4, 26.6};
    std::vector<double> june  =   {81.6, 91.2, 81.4, 75.2, 73, 72.7, 75.8, 78.7, 81, 82.3, 78, 74.5, 71.9, 75.1, 75, 75.1, 80.7, 76.9, 81.9, 68, 76.6, 73.3, 73.3, 63.8, 65.6, 71.9, 81.7, 78.8, 78.6, 69.3, 77.2, 69.3, 69.7, 75.1, 78.7, 72, 70.1, 76.6, 78.5, 77.5, 70.8, 75.6, 71.4, 73.6, 81.5, 67.1, 76.8, 71.9, 72.1, 81.2, 73.3, 79.6, 79.6, 84.8, 82.3, 83.3, 76.7, 69.8, 78.3, 77.9, 69.7, 75, 69.9, 69.1};

    Eigen::Matrix<double,64,2> mat;
    for (int i = 0; i < 64; ++i) {
        mat(i,0)=january.at(i);
        mat(i,1)=june.at(i);
    }
    std::cout<<mat<<std::endl;

    std::cout<<"Standardize the dataset"<<std::endl;
    MatrixXd centered = mat.rowwise() - mat.colwise().mean();
    std::cout<<centered<<std::endl;

    std::cout<<"Co-variance matrix"<<std::endl;
    MatrixXd cov = (centered.adjoint() * centered) / double(mat.rows() - 1);
    std::cout<<cov<<std::endl;

    SelfAdjointEigenSolver<MatrixXd> es(cov);

    std::cout<<"Eigenvalues"<<std::endl;
    std::cout<<es.eigenvalues()<<std::endl;

    std::cout << "The matrix of eigenvectors" << std::endl;
    std::cout << es.eigenvectors() << std::endl;

    return 0;

}