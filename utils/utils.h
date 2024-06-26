//
//  utils.h
//  Neural Network API
//
//  Created by 泽瑾瑜 on 5/15/24.
//
// This file serves as a centralized hub, providing access to various utility
// functions and modules essential for building and training deep learning models.
// By including this header file, developers gain access to a comprehensive set
// of utilities, ranging from memory management and tensor operations to training
// and evaluation functions, as well as computational operations such as
// convolution, pooling, and activation functions.
//
// Key functionalities included:
//
// 1. Memory management utilities for allocating and deallocating multi-dimensional
//    arrays and tensors.
// 2. Tensor utilities for copying, manipulating, and freeing tensors.
// 3. Training and evaluation utilities, including loss computation, gradient
//    computation, prediction generation, and accuracy calculation.
// 4. Random number generation utilities for introducing randomness in various
//    aspects of deep learning models.
// 5. String utility functions for common string operations.
// 6. Computational utilities for performing convolution, pooling, fully connected
//    layers, dropout, flatten, and activation operations.
//
// By consolidating access to these essential utilities in a single header file,
// this module streamlines the development process, promoting code reusability
// and maintainability. Developers can focus on the core logic of their deep
// learning models while leveraging the power and consistency of these utilities.
//

#ifndef utils_h
#define utils_h

#include "dimension.h"
#include "memory.h"
#include "tools.h"

#include "compute/optim_algorithm.h"
#include "compute/loss_function.h"
#include "compute/metric_algorithm.h"
#include "compute/convolution.h"
#include "compute/activation.h"
#include "compute/dropout.h"
#include "compute/pooling.h"
#include "compute/fully_connected.h"
#include "compute/flatten.h"

#endif /* utils_h */
