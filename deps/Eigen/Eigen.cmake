orcaslicer_add_cmake_project(
    Eigen
    URL https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz
    URL_HASH SHA256=8586084f71f9bde545ee7fa6d00288b264a2b7ac3607b974e54d13e7162c1c72
    CMAKE_ARGS
        -DCMAKE_POSITION_INDEPENDENT_CODE=ON
        -DBUILD_TESTING=OFF
)
