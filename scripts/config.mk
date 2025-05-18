export output=$(abspath output)
export bin=$(output)/bin
export obj=$(output)/obj
export src=$(abspath src)
export firmware=$(abspath firmware)

export CXX=g++
export LD=g++
export CXXFLAGS=-Wall -Wextra -O2 -std=c++23