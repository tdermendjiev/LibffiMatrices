//
//  FFICall.cpp
//  LibffiTest
//
//  Created by Teodor Dermendzhiev on 16/02/2018.
//  Copyright © 2018 Teodor Dermendzhiev. All rights reserved.
//

#include "FFICall.hpp"

#include <iostream>
#include <stdio.h>
#import <ffi/ffi.h>
#include <simd/simd.h>

typedef struct SimpleStruct {
    int32_t x1;
    struct {
        int16_t x2;
        int32_t x3;
    } y1[2];
} SimpleStruct;

SimpleStruct getSimpleStruct() {
    SimpleStruct simpleStruct = { .x1 = 0, .y1 = { { .x2 = 20, .x3 = 30 }, { .x2 = 50, .x3 = 60 } } };
    
    return simpleStruct;
}

simd_float2 getMatrix4x3() {
    matrix_float4x2 result;
    simd_float2 sfloat = simd_make_float2(3.1415, 2.3456);
//    for (int i = 0; i < 4; i++) {
//        result.columns[i] = sfloat;
//    }
    return sfloat;
}

void callFFI() {
    ffi_cif cif;
    void* buffer = malloc(128);
    
    ffi_type* ffiType = new ffi_type({ .size = 8,
        .alignment = 4,
        .type = FFI_TYPE_STRUCT });
    
//    ffi_type* ffiTypeVector = new ffi_type({ .size = 8,
//        .alignment = 4,
//        .type = FFI_TYPE_STRUCT });
    
    ffi_type* ffiTypeEl = new ffi_type({ .size = 4,
        .alignment = 4,
        .type = FFI_TYPE_FLOAT });
    
    ffiType->elements = new ffi_type*[3];
//    ffiTypeVector->elements = new ffi_type*[5];
    
    for (size_t i = 0; i < 2; i++) {
        ffiType->elements[i] = ffiTypeEl;
//        ffiTypeVector->elements[i] = ffiTypeEl;
    }
    
    ffiType->elements[2] = nullptr;
//    ffiTypeVector->elements[2] = nullptr;
    
    if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, 0,
                     ffiType, 0) == FFI_OK)
    {
        ffi_call(&cif, FFI_FN(getMatrix4x3), buffer, 0);
        
        printf("End");
    }
    
}
